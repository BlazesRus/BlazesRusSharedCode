
// MFCApp.cpp : Defines the class behaviors for the application.
//

#include "MFCpch.h"
#include "MFCFramework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCAppWithoutTemplate.h"
#include "MFCFrame.h"

#include "MFCDoc.h"
#include "MFCView.h"

#include "AboutDlg.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// MFCApp

BEGIN_MESSAGE_MAP(MFCApp, CWinApp)
    ON_COMMAND(ID_APP_ABOUT, &MFCApp::OnAppAbout)
    // Standard file based document commands
    ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
    ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// MFCApp construction

MFCApp::MFCApp() noexcept
{
    m_bHiColorIcons = TRUE;


    // TODO: replace application ID string below with unique ID string; recommended
    // format for string is CompanyName.ProductName.SubProduct.VersionInformation
    SetAppID(_T("MFCApp.AppID.NoVersion"));

    // TODO: add construction code here,
    // Place all significant initialization in InitInstance
}

// The one and only MFCApp object

MFCApp theApp;

// MFCApp initialization

BOOL MFCApp::InitInstance()
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
#else//Portable non-registry storage variant(localOnly Profile settings including last file storage)
    //Place localOnly Profile settings here instead
#endif

    // Register the application's document templates.  Document templates
    //  serve as the connection between documents, frame windows and views
    CSingleDocTemplate* pDocTemplate;
    pDocTemplate = new CSingleDocTemplate(
        IDR_MAINFRAME,
        RUNTIME_CLASS(MFCDoc),
        RUNTIME_CLASS(MFCFrame),       // main SDI frame window
        RUNTIME_CLASS(MFCView));//Replace MFCView with custom view derived from MFCView/CView
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

// MFCApp message handlers


// App command to run the dialog
void MFCApp::OnAppAbout()
{
    AboutDlg aboutDlg;
    aboutDlg.DoModal();
}

// MFCApp message handlers



