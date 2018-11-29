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
//protected:
//	typedef CustomTreeNode NodeType;
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
		pParent_Key = 18446744073709551615;//Maxed value = NULL
		pSibling_Key = 18446744073709551615;
		pChild_Key = 18446744073709551615;
#else
		pParent = NULL;
		pSibling = NULL;
		pChild = NULL;
#endif
		NBMenuType = -1;//Use default node context menu options
		crText = RGB(240,240,240);//Default to a off-white grey
	}
	CustomTreeNode(int MenuType)
	{
		csLabel.Empty();
		rNode.SetRectEmpty();

		bUseDefaultTextColor = TRUE;

		bOpen = TRUE;
#ifdef BlazesGUICode_UseDictionaryBasedNodes
		pParent_Key = 18446744073709551615;
		pSibling_Key = 18446744073709551615;
		pChild_Key = 18446744073709551615;
#else
		pParent = NULL;
		pSibling = NULL;
		pChild = NULL;
#endif
		NBMenuType = MenuType;//Use non-default node context menu defined inside a (List<CustomOrderedDictionary<string, ButtonContextData>>)? or defined in override function in CustomTreeView
		crText = RGB(240, 240, 240);
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
	CustomTreeNode* pParent;
	CustomTreeNode* pSibling;
	CustomTreeNode* pChild;
#endif

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
