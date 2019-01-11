// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest BlazesGlobalCode Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#pragma once
#if !defined(NonGUINodeTree_IncludeGuard)
#define NonGUINodeTree_IncludeGuard

#include "GlobalCode_IniData/IndexedDictionary.h"

/// <summary>
/// Class named NonGUINode.
/// </summary>
class NonGUINode
{

};

/// <summary>
/// Class named NonGUINodeTree.
/// </summary>
template <typename TreeNode = NonGUINode> class NonGUINodeTree
{public:
	static const unsigned _int64 EmptyNode = 18446744073709551615;
	NodeDictionary<TreeNode> NodeBank;
	NonGUINodeTree()
	{
	}
	~NonGUINodeTree()
	{

	}
};

#endif