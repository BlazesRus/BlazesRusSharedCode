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

#if !defined(STRCPY)
#if defined( _UNICODE )
#define STRCPY(x,y)				wcscpy(x,y)
#else
#define STRCPY(x,y)				strcpy(x,y)
#endif
#endif

#include "MultiviewPrecompile.h"
//#include "CustomTreeControl.h"
//#include "StaticTreeCtrl.h"
#include "ContextMenu.h"
#include "DLG_TreeNodeText.h"
#ifdef BlazesGUICode_UseDictionaryBasedNodes
#include "GlobalCode_IniData/IndexedDictionary.h"
#endif
#include "GlobalCode_ExperimentalCode/ConvertableP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/// <summary>
/// Edited derivable version of CustomTreeControl's Node class <para/>(base code from https://www.codeproject.com/Articles/9887/CStaticTreeCtrl-A-CStatic-derived-custom-Tree-cont)
/// <para/>NodeCtrl refers to NodeTree holding this class
/// <para/>TreeNode refers to derived class's name (for keeping inherited functionality)
/// </summary>
class CustomTreeNode
{
protected:
	//typedef NodeType = CustomTreeNode;
public:
#if !defined(CustomTree_EnableLocalTypedefs)
	/// <summary>
	/// Sends the information about TreeType and current derived NodeType(Called on TreePage initialization)
	/// </summary>
	/// <param name="">The .</param>
	//static void SendTypeDefInfo(typename TreeTypeDef)
	//{
	//	//TreeType = TreeTypeDef;
	//	//NodeType = TreePageNode;
	//	#define StaticTypeDefName(CustomTreeNode, NodeType) TreeTypeDef
	//}
#endif
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
#if defined(CustomTree_EnableLocalTypedefs)
		TreeType = TreeTypeDef;
		NodeType = TreePageNode;
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
	//TreeType* TreeTarget;
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
