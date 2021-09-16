#pragma once

#include "MFCpch.h"
#ifndef __AFXWIN_H__
    #error "include 'MFCpch.h' before including this file for PCH"
#endif

#include "MFCRes.h"       // main symbols
#include "OtherFunctions/MFCMacros.h"
#include "AboutDlg.hpp"

#include "MFCFramework.h"
#include "afxwinappex.h"
//#include "afxdialogex.h"
#include "MFCApp.h"
#include "MFCFrame.h"

#include "MFCDoc.h"
#include "MFCView.h"


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
    MFCApp() noexcept
    {
        // TODO: add construction code here,
        // Place all significant initialization in InitInstance
        //m_bHiColorIcons = TRUE;

        // TODO: replace application ID string below with unique ID string; recommended
        // format for string is CompanyName.ProductName.SubProduct.VersionInformation
        SetAppID(_T("MFCApp.AppID.NoVersion"));
    }

// Overrides
public:
    virtual BOOL InitInstance();

// Implementation
    //UINT  m_nAppLook;//Removed since only going to use one app look type
    //BOOL  m_bHiColorIcons;//Not sure if needed?

    afx_msg void OnAppAbout()
    {
        AboutDlg aboutDlg;
        aboutDlg.DoModal();
    }
protected://DECLARE_MESSAGE_MAP()
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()
    {
        __pragma(warning(push))
        __pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */
        static const AFX_MSGMAP_ENTRY _messageEntries[] =
        {
            //	//{{AFX_MSG_MAP(CAboutDlg)
            ON_COMMAND(ID_APP_ABOUT, &MFCApp<ViewType>::OnAppAbout)
            // Standard file based document commands
            ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
            ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
            //	//}}AFX_MSG_MAP
            {	0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
        };
        __pragma(warning(pop))
            static const AFX_MSGMAP messageMap =
        { &CDialog::GetThisMessageMap, &_messageEntries[0] };
        return &messageMap;
    }

public:
    virtual const AFX_MSGMAP* GetMessageMap() const
    {
        return GetThisMessageMap();
    }
};

//template <typename ViewType>
//extern MFCApp<ViewType> theApp;

template <typename ViewType>
BOOL MFCApp<ViewType>::InitInstance()
{
    // InitCommonControlsEx() is required on Windows XP if an application
    // manifest specifies use of ComCtl32.dll version 6 or later to enable
    // visual styles.  Otherwise, any window creation will fail.
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    // Set this to include all the common control classes you want to use
    // in your application.
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);
    
    CWinApp::InitInstance();
    
    EnableTaskbarInteraction(FALSE);
    
    // AfxInitRichEdit2() is required to use RichEdit control
    // AfxInitRichEdit2();
    
    // Standard initialization
    // If you are not using these features and wish to reduce the size
    // of your final executable, you should remove from the following
    // the specific initialization routines you do not need
#ifdef MFCApp_UseRegistryStorage
    // Change the registry key under which our settings are stored
    SetRegistryKey(_T("MFCApp"));// TODO: You should modify this string to be something appropriate(such as the name of your company or organization)
    LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)
#else//Portable non-registry storage variant(localOnly Profile settings including last file storage)(Default Setting when MFCApp_UseRegistryStorage is not defined as preprocessor)
    //Place localOnly Profile settings here instead
#endif
    
    // Register the application's document templates.  Document templates
    //  serve as the connection between documents, frame windows and views
    CSingleDocTemplate* pDocTemplate;
    pDocTemplate = new CSingleDocTemplate(
        IDR_MAINFRAME,
        RUNTIME_CLASS(MFCDoc),
        RUNTIME_CLASS(MFCFrame),       // main SDI frame window
        RUNTIME_CLASS(ViewType));//Replace MFCView with custom view derived from MFCView/CView
    if (!pDocTemplate)
        return FALSE;
    AddDocTemplate(pDocTemplate);
    
    // Parse command line for standard shell commands, DDE, file open
    CCommandLineInfo cmdInfo;
    ParseCommandLine(cmdInfo);
    
    // Dispatch commands specified on the command line.  Will return FALSE if
    // app was launched with /RegServer, /Register, /Unregserver or /Unregister.
    if (!ProcessShellCommand(cmdInfo))
        return FALSE;
    
    // The one and only window has been initialized, so show and update it
    m_pMainWnd->ShowWindow(SW_SHOW);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}

//inline AFX_COMDAT const CRuntimeClass MFCApp::classMFCApp = { "MFCApp", sizeof(MFCApp), 0xFFFF, NULL,&MFCApp::_GetBaseClass, NULL, NULL };
