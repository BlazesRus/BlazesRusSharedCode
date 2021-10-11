#pragma once

#include "MFCpch.h"

#include "AboutDlg.hpp"

#ifndef __AFXWIN_H__
    #error "include 'MFCpch.h' before including this file for PCH"
#endif

#include "MFCRes.h"       // main symbols

#include "afxwinappex.h"
#include "afxdialogex.h"

#include "MFCFramework.h"
#include "MFCFrame.h"
#include "MFCDoc.h"

#ifndef BlazesMFCApp_UseSDI
#include "MFCSubFrame.h"
#endif

#include "../OtherFunctions/MFCMacrosV3.h"
#ifdef BlazesMFCApp_UseAppAsDualView
#include "../OtherFunctions/MFCTwoArgMacros.h"
#else
#include "../OtherFunctions/MFCOneArgMacros.h"
#endif

#include "AppSettings.h"

/// <summary>
/// MFC based template for generating applications with Single ViewType or 2 View Types if BlazesMFCApp_UseAppAsDualView enabled
/// </summary>
#ifdef BlazesMFCApp_UseAppAsDualView
template <typename ViewType, typename SecondaryViewType>
#else
template <typename ViewType>
#endif
class MFCApp : public CWinAppEx
{
public:
    MFCApp() noexcept
    {
        // TODO: replace application ID string below with unique ID string; recommended
        // format for string is CompanyName.ProductName.SubProduct.VersionInformation
        SetAppID(_T("MFCApp.AppID.NoVersion"));
    }

// Overrides
public:
    /// <summary>
    /// MFCApp initialization Code
    /// </summary>
    virtual BOOL InitInstance()
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

        CWinAppEx::InitInstance();

#ifdef BlazesMFCApp_UseSDI
        EnableTaskbarInteraction(FALSE);
#else
        EnableTaskbarInteraction();
#endif

    // AfxInitRichEdit2();//is required to use RichEdit control

    // Standard initialization
    // If you are not using these features and wish to reduce the size
    // of your final executable, you should remove from the following
    // the specific initialization routines you do not need
#ifdef BlazesMFCApp_UseRegistryStorage
    // Change the registry key under which our settings are stored
        SetRegistryKey(_T("MFCApp"));// TODO: You should modify this string to be something appropriate(such as the name of your company or organization)
        LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)
#else//Portable non-registry storage variant(localOnly Profile settings including last file storage)
        AppSettings AppRegistry;
        AppRegistry.Load();
#endif

    // Register the application's document templates.  Document templates
    //  serve as the connection between documents, frame windows and views
#ifdef BlazesMFCApp_UseSDI//Single
    // Register the application's document templates.  Document templates
    //  serve as the connection between documents, frame windows and views
        CSingleDocTemplate* pDocTemplate;
        pDocTemplate = new CSingleDocTemplate(
            IDR_MAINFRAME,
            RUNTIME_CLASS(MFCDoc),
            RUNTIME_CLASS(MFCFrame),       // main SDI frame window
            RUNTIME_CLASS(ViewType));//Replace MFCView with custom view derived from MFCView/CView
#else
        CMultiDocTemplate* pDocTemplate;
        pDocTemplate = new CMultiDocTemplate(IDR_MFCAppTYPE,
            RUNTIME_CLASS(MFCDoc),
            RUNTIME_CLASS(MFCSubFrame), // custom MDI child frame
            RUNTIME_CLASS(ViewType));
#endif
        if (!pDocTemplate)
            return FALSE;
        AddDocTemplate(pDocTemplate);

#ifndef BlazesMFCApp_UseSDI
        // create main MDI Frame window
        MFCFrame* pMainFrame = new MFCFrame;
        if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
        {
            delete pMainFrame;
            return FALSE;
        }
        m_pMainWnd = pMainFrame;
#endif

        // Parse command line for standard shell commands, DDE, file open
        CCommandLineInfo cmdInfo;
        ParseCommandLine(cmdInfo);

        // Dispatch commands specified on the command line.  Will return FALSE if
        // app was launched with /RegServer, /Register, /Unregserver or /Unregister.
        if (!ProcessShellCommand(cmdInfo))
            return FALSE;

#ifdef BlazesMFCApp_UseSDI
        // The one and only window has been initialized, so show and update it
        m_pMainWnd->ShowWindow(SW_SHOW);
        m_pMainWnd->UpdateWindow();
#else
        // The main window has been initialized, so show and update it
        pMainFrame->ShowWindow(m_nCmdShow);
        pMainFrame->UpdateWindow();
#endif
        return TRUE;
    }

    virtual int ExitInstance()
    {
        //TODO: handle additional resources you may have added
        return CWinAppEx::ExitInstance();
    }

// Implementation
    /// <summary>
    /// App command to run the (About Application) dialog
    /// </summary>
    afx_msg void OnAppAbout()
    {
        AboutDlg aboutDlg;
        aboutDlg.DoModal();
    }

#ifdef BlazesMFCApp_UseAppAsDualView
    MFC_RuntimeExtPart01With02Args(MFCApp, ViewType, SecondaryViewType, CWinAppEx)
#else
    MFC_RuntimeExtPart01With01Args(MFCApp, ViewType, CWinAppEx)
#endif
    ON_COMMAND(ID_APP_ABOUT, &MFCApp::OnAppAbout)
    // Standard file based document commands
    ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
    ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
#ifndef BlazesMFCApp_DisablePrinter
    // Standard print setup command
    ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
#endif
    MFC_RuntimeExtPart02(MFCApp, ViewType)
    MFC_RuntimeExtClassName(MFCApp)
};

#ifdef BlazesMFCApp_UseAppAsDualView
MFC_RuntimeImplimentationWith02Args(MFCApp, ViewType, SecondaryViewType)
MFC_RuntimeClassImplimentationWith02Args(MFCApp, ViewType, SecondaryViewType)
#else
MFC_RuntimeImplimentationWith01Args(MFCApp, ViewType)
MFC_RuntimeClassImplimentationWith01Args(MFCApp, ViewType)
#endif