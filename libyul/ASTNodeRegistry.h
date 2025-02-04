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

#pragma once

#include <map>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace solidity::yul
{

class ASTNodeRegistry
{
public:
	/// unsafe to use from a different registry instance, it is up to the user to safeguard against this
	using NodeId = size_t;

	static constexpr auto ghostPlaceholder = "GHOST[@]";

	ASTNodeRegistry();
	ASTNodeRegistry(std::vector<std::string> const& _labels, std::vector<size_t> const& _nameToLabelMapping);

	std::string_view operator()(NodeId _id) const;

	static bool constexpr empty(NodeId const _id) { return _id == emptyId(); }
	static NodeId constexpr emptyId() { return 0; }
	static NodeId constexpr ghostId() { return 1; }

	std::vector<std::string> const& labels() const { return m_labels; }
	NodeId maximumId() const { return m_nameToLabelMapping.size() - 1; }

	size_t nameToLabelIndex(NodeId _name) const;
	/// this is a potentially expensive operation
	std::optional<NodeId> findNameForLabel(std::string_view _label) const;
private:
	std::string_view lookupGhost(NodeId _name) const;

	std::vector<std::string> m_labels;
	std::vector<size_t> m_nameToLabelMapping;
	mutable std::map<NodeId, std::string> m_ghostLabelCache;
};

class ASTNodeRegistryBuilder
{
public:
	ASTNodeRegistryBuilder();
	explicit ASTNodeRegistryBuilder(ASTNodeRegistry const& _existingRegistry);
	ASTNodeRegistry::NodeId define(std::string_view _label);
	ASTNodeRegistry build() const;
private:
	class LabelToNameMapping
	{
	public:
		LabelToNameMapping();
		std::tuple<ASTNodeRegistry::NodeId, bool> tryInsert(std::string_view _label, ASTNodeRegistry::NodeId _name);

		auto const& data() const { return m_mapping; }
	private:
		std::map<std::string, size_t, std::less<>> m_mapping;
	};

	LabelToNameMapping m_mapping;
	size_t m_nextNameId = 0;
};

}
