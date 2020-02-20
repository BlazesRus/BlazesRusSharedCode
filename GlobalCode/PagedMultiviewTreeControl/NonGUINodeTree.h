// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest BlazesGlobalCode Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#pragma once
#if !defined(NonGUINodeTree_IncludeGuard)
#define NonGUINodeTree_IncludeGuard

#include "IniData/IndexedDictionary.h"
#include "VariableLists/VariableTypeLists.h"
#include "NonGUINode.h"

/// <summary>
/// Class named NonGUINodeTree.
/// </summary>
template <typename TreeNode = NonGUINode> class NonGUINodeTree
{public:
	static const unsigned _int64 EmptyNode = 18446744073709551615;
	NodeDictionary<TreeNode> NodeBank;
	/// <summary>
	/// List of indexes for Root level nodes inside NodeBank
	/// </summary>
	UXIntList RootLvlNodes;
public:
/*
	/// <summary>
	/// Adds a node with specified name.
	/// </summary>
	/// <param name="name">The name.</param>
	void Add(std::string name)
	{
		//int Index = this->AddData();
		//this->at(Index).DisplayName = name;
	}
	NonGUINodeTree<TreeNode>& LastNode()
	{
		return this->at(size() - 1);
	}
*/

	/// <summary>
	/// Initializes a new instance of the <see cref="NonGUINodeTree"/> class.
	/// </summary>
	NonGUINodeTree()
	{
	}
	/// <summary>
	/// Finalizes an instance of the <see cref="NonGUINodeTree"/> class.
	/// </summary>
	~NonGUINodeTree()
	{

	}
};

#endif