/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/
// SPDX-License-Identifier: GPL-3.0

#include <libyul/optimiser/NodeIdDispenser.h>

#include <libyul/optimiser/NameCollector.h>
#include <libyul/optimiser/OptimizerUtilities.h>

#include <fmt/compile.h>

using namespace solidity::yul;

namespace
{
bool isInvalidLabel(
	std::string_view const _label,
	std::set<std::string, std::less<>> const& _reservedLabels,
	Dialect const& _dialect
)
{
	return isRestrictedIdentifier(_dialect, _label) || _reservedLabels.contains(_label);
}
}

NodeIdDispenser::NodeIdDispenser(ASTNodeRegistry const& _labelRegistry, std::set<std::string> const& _reservedLabels):
	m_registry(_labelRegistry),
	m_reservedLabels(_reservedLabels.begin(), _reservedLabels.end()),
	m_offset(_labelRegistry.maximumId() + 1)
{}

NodeIdDispenser::NodeId NodeIdDispenser::newId(NodeId const parent)
{
	m_mapping.push_back(resolveBaseName(parent));
	return m_mapping.size() - 1 + m_offset;
}

NodeIdDispenser::NodeId NodeIdDispenser::newGhost()
{
	return newId(ASTNodeRegistry::ghostId());
}

NodeIdDispenser::NodeId NodeIdDispenser::resolveBaseName(NodeId _name) const
{
	if (_name >= m_offset)
		_name = m_mapping[_name - m_offset];
	yulAssert(_name < m_offset, "We have at most one level of indirection, this violates this assumption");
	return _name;
}

ASTNodeRegistry NodeIdDispenser::generateNewLabels(Block const& _root, Dialect const& _dialect) const
{
	std::set<NodeId> usedIds = NameCollector(_root).names();
	// add ghosts to used names as they're not referenced in the regular ast
	for (size_t i = 0; i < m_mapping.size(); ++i)
		if (m_mapping[i] == ASTNodeRegistry::ghostId())
			usedIds.insert(i + m_offset);

	if (usedIds.empty())
		return {};

	auto const& originalLabels = m_registry.get().labels();

	std::vector<uint8_t> reusedLabels (originalLabels.size());
	// this means that everything that is derived from empty / ghost needs to be generated
	reusedLabels[0] = true;
	reusedLabels[1] = true;

	std::vector<std::string> labels{"", ASTNodeRegistry::ghostPlaceholder};
	labels.reserve(originalLabels.size()+2);
	// this is fine as used names is guaranteed to be not empty
	std::vector<size_t> idToLabelMap(*std::prev(usedIds.end()) + 1, 0);
	idToLabelMap[0] = 0;
	idToLabelMap[1] = 1;

	std::set<std::string, std::less<>> alreadyDefinedNames = m_reservedLabels + std::set{"", ASTNodeRegistry::ghostPlaceholder};

	std::vector<NodeId> toGenerate;
	// filter out straightforward case: we just use whatever label was already there and put it into alreadyDefinedNames
	// otherwise it goes into the toGenerate collection
	for (auto const& name: usedIds)
	{
		auto const baseName = resolveBaseName(name);
		auto const baseLabelIndex = m_registry.get().nameToLabelIndex(baseName);
		auto const& baseLabel = originalLabels[baseLabelIndex];
		// if we haven't already reused the label, check that either the name didn't change, then we can just
		// take over the old label, otherwise check that it is a valid label and then reuse
		if (!reusedLabels[baseLabelIndex] && (baseName == name || !isInvalidLabel(baseLabel, m_reservedLabels, _dialect)))
		{
			labels.push_back(baseLabel);
			idToLabelMap[name] = labels.size() - 1;
			alreadyDefinedNames.insert(baseLabel);
			reusedLabels[baseLabelIndex] = true;
		}
		else
			toGenerate.push_back(name);
	}

	for (auto const& name: toGenerate)
	{
		auto const baseName = resolveBaseName(name);

		// ghost variables get special treatment
		if (baseName == ASTNodeRegistry::ghostId())
		{
			idToLabelMap[name] = ASTNodeRegistry::ghostId();
			continue;
		}

		auto const baseLabelIndex = m_registry.get().nameToLabelIndex(baseName);
		auto const& baseLabel = originalLabels[baseLabelIndex];

		std::string generatedLabel = baseLabel;
		size_t suffix = 1;
		do
		{
			generatedLabel = format(FMT_COMPILE("{}_{}"), baseLabel, suffix++);
		} while (isInvalidLabel(generatedLabel, alreadyDefinedNames, _dialect));

		labels.push_back(generatedLabel);
		idToLabelMap[name] = labels.size() - 1;
		alreadyDefinedNames.insert(generatedLabel);
	}

	return ASTNodeRegistry{labels, idToLabelMap};
}
