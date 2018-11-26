#pragma once
#ifndef CustomTreeNode_Header
#define CustomTreeNode_Header

#include "WP_APPDefines.h"

#include "MultiviewPrecompile.h"
//#include "CustomTreeControl.h"
//#include "StaticTreeCtrl.h"
#include "ContextMenu.h"
#include "DLG_TreeNodeText.h"
#ifdef BlazesGUICode_UseDictionaryBasedNodes
#include "GlobalCode_IniData/IndexedDictionary.h"
#endif
#include "GlobalCode_IniData/CustomOrderedDictionary.h"

/// <summary>
/// Edited derivable version of CustomTreeControl's Node class <para/>(base code from https://www.codeproject.com/Articles/9887/CStaticTreeCtrl-A-CStatic-derived-custom-Tree-cont)
/// <para/>NodeCtrl refers to NodeTree holding this class
/// <para/>TreeNode refers to derived class's name (for keeping inherited functionality)
/// </summary>
class CustomTreeNode
{
protected:
	typedef CustomTreeNode NodeType;
public:
	//This refers to index inside list of button contexts dictionary unless -1 in which case it uses default menu context list
	int NBMenuType;
	CustomTreeNode()
	{
		csLabel.Empty();
		rNode.SetRectEmpty();

		bUseDefaultTextColor = TRUE;

		bOpen = TRUE;
#ifdef BlazesGUICode_UseDictionaryBasedNodes

#else
		pParent = NULL;
		pSibling = NULL;
		pChild = NULL;
#endif
#if defined(CustomTree_EnableLocalTypedefs)
		TreeType = TreeTypeDef;
		NodeType = TreePageNode;
#endif
		NBMenuType = -1;//Use default node context menu options
	}
	CustomTreeNode(int MenuType)
	{
		csLabel.Empty();
		rNode.SetRectEmpty();

		bUseDefaultTextColor = TRUE;

		bOpen = TRUE;
#ifdef BlazesGUICode_UseDictionaryBasedNodes

#else
		pParent = NULL;
		pSibling = NULL;
		pChild = NULL;
#endif
#if defined(CustomTree_EnableLocalTypedefs)
		TreeType = TreeTypeDef;
		NodeType = TreePageNode;
#endif
		NBMenuType = MenuType;//Use non-default node context menu defined inside a (List<CustomOrderedDictionary<string, ButtonContextData>>)? or defined in override function in CustomTreeView
	}

	virtual ~CustomTreeNode()
	{
		csLabel.Empty();
	}

	CString		csLabel;
	CRect		rNode;

	COLORREF	crText;
	BOOL		bUseDefaultTextColor;

	BOOL    bOpen;
#ifdef BlazesGUICode_UseDictionaryBasedNodes
	List<std::string> ChildNodes;
#else
	NodeType* pParent;
	NodeType* pSibling;
	NodeType* pChild;
#endif
	//int NodeCat;//Keeping NodeAction Dictionary inside TreeView(to reuse the NodeActions without making new dictionaries for each node)

	template <typename ConvertedType>
	explicit operator ConvertedType*()
	{
		if (self == nullptr)
		{
			return nullptr;
		}
		else
		{
			return dynamic_cast<ConvertedType*>(self);
		}
	}
};
#endif
