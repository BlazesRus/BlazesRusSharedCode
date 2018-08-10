#pragma once
#ifndef CustomTreeNode_Header
#define CustomTreeNode_Header

#define		CM_INSERTCHILD				WM_APP + 10000
#define		CM_INSERTSIBLING			WM_APP + 10001
#define		CM_DELETENODE				WM_APP + 10002
#define		CM_MODIFYNODETEXT			WM_APP + 10003
#define		CM_CHANGENODECOLOR			WM_APP + 10004
#define		CM_TOGGLECONNECTINGLINES	WM_APP + 10010
#define		CM_SETCONNECTINGLINESCOLOR	WM_APP + 10011
#define		CM_SETFONT					WM_APP + 10020
#define		CM_SETDEFAULTCOLOR			WM_APP + 10021
#define		CM_SETBACKGROUNDBITMAP		WM_APP + 10022
#define		CM_TOGGLEMENUSOUND			WM_APP + 10030

#if defined( _UNICODE )
#define STRCPY(x,y)				wcscpy(x,y)
#else
#define STRCPY(x,y)				strcpy(x,y)
#endif

#include "stdafx.h"
#include "CustomTreeControl.h"
#include "StaticTreeCtrl.h"
#include "ContextMenu.h"
#include "DLG_TreeNodeText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//#ifdef BlazesGlobalCode_GUIDisableNodesWithinNode//If enabled places nodes inside Dictionary inside of vectors of nodes within each node
//
//#else
//#include <vector>
//#endif

/// <summary>
/// Edited derivable version of CustomTreeControl's Node class <para/>(base code from https://www.codeproject.com/Articles/9887/CStaticTreeCtrl-A-CStatic-derived-custom-Tree-cont)
/// <para/>NodeCtrl refers to NodeTree holding this class
/// <para/>TreeNode refers to derived class's name (for keeping inherited functionality)
/// </summary>
template <typename NodeCtrl
#ifdef BlazesGUICode_UseDictionaryBasedNodes
>
#else
, typename TreeNode>
#endif
class CustomTreeNode
{
public:
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
	NodeCtrl* TreeTarget;
#else
	TreeNode*	pParent;
	TreeNode*	pSibling;
	TreeNode*	pChild;
#endif
};
#endif