#pragma once

#ifndef __AFXWIN_H__
    #error "include 'MFCpch.h' before including this file for PCH"
#endif

#include "MFCRes.h"       // main symbols
#include "OtherFunctions/MFCMacros.h"

// MFCApp:
// See MFCApp.cpp for the implementation of this class
//
/// <summary>
/// MFC based template for generating applications with a single view (Include MFCAppProcesser.h to generate Application with default generic view type)
/// </summary>
template <typename ViewType>
class MFCApp : public CWinApp
{
public:
    MFCApp() noexcept;

// Overrides
public:
    virtual BOOL InitInstance();

// Implementation
    //UINT  m_nAppLook;//Removed since only going to use one app look type
    //BOOL  m_bHiColorIcons;//Not sure if needed?

    afx_msg void OnAppAbout();
    DECLARE_MESSAGE_MAP()
//protected:
//	/// <summary>
//	/// Gets this message map.
//	/// </summary>
//	/// <returns>const AFX_MSGMAP *.</returns>
//	static const AFX_MSGMAP* PASCAL GetThisMessageMap()
//	{
//		__pragma(warning(push))
//		__pragma(warning(disable: 4640))
//		static const AFX_MSGMAP_ENTRY _messageEntries[] =
//		{
//			//ON_WM_PAINT()
//			//ON_WM_SIZE()
//			//ON_WM_VSCROLL()
//			//ON_WM_LBUTTONUP()
//			//ON_WM_MOUSEWHEEL()
//			//ON_WM_CONTEXTMENU()
//			//ON_COMMAND(CM_INSERTCHILD, &OnCM_InsertChild)
//			//ON_COMMAND(CM_INSERTSIBLING, &OnCM_InsertSibling)
//			//ON_COMMAND(CM_DELETENODE, &OnCM_DeleteNode)
//			//ON_COMMAND(CM_MODIFYNODETEXT, &OnCM_ModifyNodeText)
//			//ON_COMMAND(CM_CHANGENODECOLOR, &OnCM_ChangeNodeColor)
//			//ON_COMMAND(CM_TOGGLECONNECTINGLINES, &OnCM_ToggleConnectingLines)
//			//ON_COMMAND(CM_SETCONNECTINGLINESCOLOR, &OnCM_SetConnectingLinesColor)
//			//ON_COMMAND(CM_SETFONT, &OnCM_SetFont)
//			//ON_COMMAND(CM_SETDEFAULTCOLOR, &OnCM_SetDefaultColor)
//			//ON_COMMAND(CM_SETBACKGROUNDBITMAP, &OnCM_SetBackgroundBitmap)
//			{
// 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0
//			}
//		};
//		__pragma(warning(pop))
//		/// <summary>
//		/// The message map
//		/// </summary>
//		static const AFX_MSGMAP messageMap =
//		{ &CWinApp::GetThisMessageMap, &_messageEntries[0] };
//		return &messageMap;
//	}
//public:
//	virtual const AFX_MSGMAP* GetMessageMap() const
//	{
//		return GetThisMessageMap();
//	}
};

//inline AFX_COMDAT const CRuntimeClass MFCApp::classMFCApp = { "MFCApp", sizeof(MFCApp), 0xFFFF, NULL,&MFCApp::_GetBaseClass, NULL, NULL };
