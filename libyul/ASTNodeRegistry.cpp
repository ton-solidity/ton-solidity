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

#include <libyul/ASTNodeRegistry.h>

#include <libyul/Exceptions.h>

#include <fmt/format.h>

#include <range/v3/algorithm/max.hpp>
#include <range/v3/view/map.hpp>

using namespace solidity::yul;

ASTNodeRegistry::ASTNodeRegistry(): m_labels{"", ghostPlaceholder}, m_nameToLabelMapping{0, 1} {}

ASTNodeRegistry::ASTNodeRegistry(std::vector<std::string> const& _labels, std::vector<size_t> const& _nameToLabelMapping)
{
	yulAssert(_labels.size() >= 2);
	yulAssert(_labels[0].empty());
	yulAssert(_labels[1] == ghostPlaceholder);
	yulAssert(_nameToLabelMapping.size() >= 2);
	yulAssert(_nameToLabelMapping[0] == 0);
	yulAssert(_nameToLabelMapping[1] == 1);
	std::vector<uint8_t> labelVisited (_labels.size(), false);
	for (auto const& name: _nameToLabelMapping)
	{
		yulAssert(name < _labels.size());
		// it is possible to have multiple references to empty / ghost
		yulAssert(
			name < 2 || !labelVisited[name],
			fmt::format("YulName {} (label \"{}\") is not unique.", name, _labels[name])
		);
		labelVisited[name] = true;
	}
	m_labels = _labels;
	m_nameToLabelMapping = _nameToLabelMapping;
}

size_t ASTNodeRegistry::nameToLabelIndex(NodeId const _name) const
{
	yulAssert(_name < m_nameToLabelMapping.size());
	return m_nameToLabelMapping[_name];
}

std::string_view ASTNodeRegistry::operator()(NodeId const _name) const
{
	auto const labelIndex = nameToLabelIndex(_name);
	if (labelIndex == ghostId())
		return lookupGhost(_name);
	return m_labels[nameToLabelIndex(_name)];
}

std::optional<ASTNodeRegistry::NodeId> ASTNodeRegistry::findNameForLabel(std::string_view const _label) const {
	if (_label.empty())
		return emptyId();
	if (_label == ghostPlaceholder)
		return NodeId{1};
	for (NodeId name = 2; name <= maximumId(); ++name)
		if ((*this)(name) == _label)
			return name;
	return std::nullopt;
}

std::string_view ASTNodeRegistry::lookupGhost(NodeId const _name) const
{
	yulAssert(nameToLabelIndex(_name) == ghostId());
	auto const [it, _] = m_ghostLabelCache.try_emplace(_name, fmt::format("GHOST[{}]", _name));
	return it->second;
}

ASTNodeRegistryBuilder::LabelToNameMapping::LabelToNameMapping():
	m_mapping{{"", 0}, {ASTNodeRegistry::ghostPlaceholder, 1}}
{}

std::tuple<ASTNodeRegistry::NodeId, bool> ASTNodeRegistryBuilder::LabelToNameMapping::tryInsert(
	std::string_view const _label,
	ASTNodeRegistry::NodeId const _name
)
{
	yulAssert(_label != ASTNodeRegistry::ghostPlaceholder);
	auto const [it, emplaced] = m_mapping.try_emplace(std::string{_label}, _name);
	return std::make_tuple(it->second, emplaced);
}

ASTNodeRegistryBuilder::ASTNodeRegistryBuilder():
	m_nextNameId(2)
{}

ASTNodeRegistryBuilder::ASTNodeRegistryBuilder(ASTNodeRegistry const& _existingRegistry)
{
	for (size_t i = 2; i <= _existingRegistry.maximumId(); ++i)
	{
		auto const existingLabel = _existingRegistry(i);
		if (!existingLabel.empty())
		{
			auto const [_, inserted] = m_mapping.tryInsert(_existingRegistry(i), i);
			yulAssert(inserted);
		}
	}
	m_nextNameId = _existingRegistry.maximumId() + 1;
}

ASTNodeRegistry::NodeId ASTNodeRegistryBuilder::define(std::string_view const _label)
{
	auto const [nameId, inserted] = m_mapping.tryInsert(_label, m_nextNameId);
	if (inserted)
		m_nextNameId++;
	return nameId;
}

ASTNodeRegistry ASTNodeRegistryBuilder::build() const
{
	auto const& mapping = m_mapping.data();
	yulAssert(mapping.contains(""));
	yulAssert(mapping.at("") == 0);
	yulAssert(mapping.contains(ASTNodeRegistry::ghostPlaceholder));
	yulAssert(mapping.find(ASTNodeRegistry::ghostPlaceholder)->second == 1);

	std::vector<std::string> labels{"", ASTNodeRegistry::ghostPlaceholder};
	labels.reserve(mapping.size());
	std::vector<size_t> nameToLabelMapping(ranges::max(mapping | ranges::views::values) + 1, 0);
	yulAssert(nameToLabelMapping.size() >= 2, "Mapping at least contains empty and ghost entry");
	nameToLabelMapping[1] = 1;
	for (auto const& [label, name]: mapping)
	{
		// skip empty and ghost
		if (name < 2)
			continue;

		labels.emplace_back(label);
		nameToLabelMapping[name] = labels.size() - 1;
	}
	return ASTNodeRegistry{labels, nameToLabelMapping};
}
