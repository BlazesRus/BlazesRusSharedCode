#pragma once
#if !defined(AFX_STATICTREECTRL_H__A9777424_A55F_4A55_BE9D_5308028DB601__INCLUDED_)
#define AFX_STATICTREECTRL_H__A9777424_A55F_4A55_BE9D_5308028DB601__INCLUDED_

// StaticTreeCtrl.h : header file
//
/////////////////////////////////////////////////////////////////////////////

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
#define STRCPY(x,y)				strcpy_s(x,y)
#endif

#include "MultiviewPrecompile.h"
//#include "CustomTreeControl.h"
#include "ContextMenu.h"
#include "DLG_TreeNodeText.h"
#include "CustomTreeNode.h"
#include "CustomTreeCtrl.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#undef THIS_FILE
//static char THIS_FILE[] = __FILE__;
//#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeNode class
class CStaticTreeCtrl;
class CTreeNode;
class CTreeNode : public CustomTreeNode<CStaticTreeCtrl
#ifdef BlazesGUICode_UseDictionaryBasedNodes
>
#else
,CTreeNode>
#endif
{
public:
	CTreeNode(): CustomTreeNode<CStaticTreeCtrl
#ifdef BlazesGUICode_UseDictionaryBasedNodes
	>
#else
	, CTreeNode>
#endif
	(){}
};

/////////////////////////////////////////////////////////////////////////////
// CStaticTreeCtrl window

class CStaticTreeCtrl;
class CStaticTreeCtrl : public CustomTreeCtrl<CTreeNode>
{
public:
	//virtual ~CStaticTreeCtrl()
	//{
	//	DeleteNode(m_pTopNode);	// Delete all children if there are any
	//	delete m_pTopNode;			// Delete top node
	//	m_pTopNode = NULL;

	//	m_Font.DeleteObject();

	//	if (m_bmpBackground.GetSafeHandle() != NULL)
	//		m_bmpBackground.DeleteObject();
	//}
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICTREECTRL_H__A9777424_A55F_4A55_BE9D_5308028DB601__INCLUDED_)
