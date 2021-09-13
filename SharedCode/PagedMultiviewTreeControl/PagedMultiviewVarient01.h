// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#if !defined(PagedMultiviewVarient01_IncludeGuard)
#define PagedMultiviewVarient01_IncludeGuard

#include "MultiviewPrecompile.h"

#ifndef __AFXWIN_H__
#error "include 'MultiviewPrecompile.h' before including this file for PCH"
#endif
#include "OtherFunctions/MFCMacros.h"

#if !defined(ID_APP_ABOUT)
    #define ID_APP_ABOUT 0xE140
#endif
#if !defined(IDR_MAINFRAME)
    #define IDR_MAINFRAME 128
#endif
#if !defined(ID_VIEW_OTHERVIEW)
#define ID_VIEW_OTHERVIEW 30772
#endif
#if !defined(ID_VIEW_SWITCHVIEW)
#define ID_VIEW_SWITCHVIEW 30773
#endif
#if !defined(ID_VIEW_FIRSTVIEW)
#define ID_VIEW_FIRSTVIEW 30771
#endif

#include "MultiViewDoc.h"
//#include "MFView.h"

#include "AboutDlg.h"

#include <VariableLists/VariableList.h>
/// <summary>
/// Multi-view features based on https://www.codeproject.com/Articles/7686/Using-Multiview
/// Implements the <see cref="CWinAppEx" />
/// Defaults to PagedView for initial view
/// </summary>
/// <seealso cref="CWinAppEx" />
template <typename PagedViewType, typename Frame01, typename ViewType02, typename ViewType03>
class PagedMultiviewVarient01 : public CWinAppEx
{
    /// <summary>
    /// The main non-paged view
    /// </summary>
    CView* View02;
    /// <summary>
    /// The List holding one or more Alternative Views
    /// </summary>
    VariableList<PagedViewType*> AltView;
    /// <summary>
    /// The non-paged view #2
    /// </summary>
    CView* View03;
public:
    static signed int const LoadCurrentAltView = 1000000000;
    /// <summary>
    /// The using alt view if ViewNum==0;  
    /// </summary>
    int ViewNum;

    /// <summary>
    /// Return Main view as non-CView pointer
    /// </summary>
    /// <returns>ViewType02*</returns>
    ViewType02* GetView02()
    {
        if (View02 == nullptr)
        {
            return nullptr;
        }
        else
        {
            return dynamic_cast<ViewType02*>(View02);
        }
    }
    /// <summary>
    /// Switches to alt view.
    /// </summary>
    /// <param name="Num">The number.</param>
    void SwitchToAltView(unsigned int Num = LoadCurrentAltView)
    {
        if (ViewNum!=0)
        {
            UINT temp = ::GetWindowLong(AltView[CurrentAltView]->m_hWnd, GWL_ID);
            ::SetWindowLong(AltView[CurrentAltView]->m_hWnd, GWL_ID, ::GetWindowLong(View02->m_hWnd, GWL_ID));
            ::SetWindowLong(View02->m_hWnd, GWL_ID, temp);

            View02->ShowWindow(SW_HIDE);
        }
        if(Num== LoadCurrentAltView)//Use Current loaded AltView
        {
            AltView[CurrentAltView]->ShowWindow(SW_SHOW);
        }
        else
        {
            AltView[CurrentAltView]->ShowWindow(SW_HIDE);
            CurrentAltView = Num;
            AltView[CurrentAltView]->ShowWindow(SW_SHOW);
        }
        ((Frame01*)m_pMainWnd)->SetActiveView(AltView[CurrentAltView]);
        ((Frame01*)m_pMainWnd)->RecalcLayout();
        AltView[CurrentAltView]->Invalidate();
        ViewNum = 0;
    }

    /// <summary>
    /// Initializes a new instance of the <see cref="PagedMultiviewVarient01" /> class.
    /// </summary>
    /// ///////////////////////////////////////////////////////////////////////////
    /// PagedMultiviewVarient01 construction
    PagedMultiviewVarient01()
    {
        UsingAltView = false;
        // TODO: add construction code here,
        // Place all significant initialization in InitInstance
    }

    //~virtual PagedMultiviewVarient01()
    //{
    //}


/// <summary>
/// Edit this virtual function inside Derived Class with method void InitializationCode() defined to run edit code thats run just before displays main view on InitInstance()
/// </summary>
    virtual void InitializationCode()
    {
    }
    // Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CMultiViewApp)
public:
    /// <summary>
    /// Initializes the instance.
    /// </summary>
    /// <returns>BOOL.</returns>
    virtual BOOL InitInstance()
    {
        AfxEnableControlContainer();

        //LoadStdProfileSettings();  // Load standard INI file options (including MRU)

        // Register the application's document templates.  Document templates
        //  serve as the connection between documents, frame windows and views.

        CSingleDocTemplate* pDocTemplate;
        pDocTemplate = new CSingleDocTemplate(
            IDR_MAINFRAME,
            RUNTIME_CLASS(MultiViewDoc),
            RUNTIME_CLASS(Frame01),       // main SDI frame window
            RUNTIME_CLASS(ViewType02));
        AddDocTemplate(pDocTemplate);

        // Parse command line for standard shell commands, DDE, file open
        CCommandLineInfo cmdInfo;
        ParseCommandLine(cmdInfo);

        // Dispatch commands specified on the command line
        if (!ProcessShellCommand(cmdInfo))
        {
            return FALSE;//Fails to create empty document here
        }

        //CView* pActiveView = ((Frame01*)m_pMainWnd)->GetActiveView();
        //View02 = static_cast<ViewType02*>(pActiveView);
        CView* pActiveView = ((CFrameWnd*)m_pMainWnd)->GetActiveView();
        View02 = pActiveView;
        AltView.Add((PagedViewType*) new PagedViewType);

        CDocument* pDoc = ((Frame01*)m_pMainWnd)->GetActiveDocument();

        CCreateContext context;
        context.m_pCurrentDoc = pDoc;

        UINT m_ID = AFX_IDW_PANE_FIRST + 1;
        CRect rect;

        AltView[CurrentAltView]->Create(NULL, NULL, WS_CHILD, rect, m_pMainWnd, m_ID, &context);

        InitializationCode();
        // The one and only window has been initialized, so show and update it.
        m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
        m_pMainWnd->UpdateWindow();

        return TRUE;
    }
    //virtual int ExitInstance()
    //{
    //	return TRUE;
    //}
    //}}AFX_VIRTUAL


/// <summary>
/// Application command to run the dialog
/// </summary>
/// Implementation
/// {{AFX_MSG(CMultiViewApp)
    afx_msg void OnAppAbout()
    {
        AboutDlg aboutDlg;
        aboutDlg.DoModal();
    }
    afx_msg void OnPagedView()
    {
        SwitchToAltView();
    }
    afx_msg void OnNonPagedView01()
    {
        // TODO: Add your command handler code here

        UINT temp = ::GetWindowWord(AltView[CurrentAltView]->m_hWnd, GWL_ID);
        ::SetWindowWord(AltView[CurrentAltView]->m_hWnd, GWL_ID, ::GetWindowWord(View02->m_hWnd, GWL_ID));
        ::SetWindowWord(View02->m_hWnd, GWL_ID, temp);

        AltView[CurrentAltView]->ShowWindow(SW_HIDE);
        View02->ShowWindow(SW_SHOW);

        ((Frame01*)m_pMainWnd)->SetActiveView(View02);
        ((Frame01*)m_pMainWnd)->RecalcLayout();
        View02->Invalidate();
        ViewNum = 1;
    }

    afx_msg void OnViewSwitchView(int ViewNumber=0)
    {
        // TODO: Add your command handler code here
        if(ViewNumber==0)
        {
            SwitchToAltView();
        }
        else
        {
            UINT temp = ::GetWindowWord(AltView[CurrentAltView]->m_hWnd, GWL_ID);
            ::SetWindowWord(AltView[CurrentAltView]->m_hWnd, GWL_ID, ::GetWindowWord(View02->m_hWnd, GWL_ID));
            ::SetWindowWord(View02->m_hWnd, GWL_ID, temp);

            AltView[CurrentAltView]->ShowWindow(SW_HIDE);
            View02->ShowWindow(SW_SHOW);

            if(ViewNumber==2)
            {
                ((Frame01*)m_pMainWnd)->SetActiveView(View03);
            }
            else
            {
                ((Frame01*)m_pMainWnd)->SetActiveView(View02);
            }
            ((Frame01*)m_pMainWnd)->RecalcLayout();
            View02->Invalidate();
            ViewNum = ViewNumber;
        }
    }

    //}}AFX_MSG

    BEGIN_AltMESSAGE_MAP()
        ON_COMMAND(ID_APP_ABOUT, &OnAppAbout)
        ON_COMMAND(ID_VIEW_OTHERVIEW, &OnPagedView)
        ON_COMMAND(ID_VIEW_FIRSTVIEW, &OnNonPagedView01)
        ON_COMMAND(ID_VIEW_SWITCHVIEW, &OnViewSwitchView)
    END_AltMESSAGE_MAP(CWinAppEx)
    /// <summary>
    /// The current alt view
    /// </summary>
    unsigned int CurrentAltView = 0;
    //IniDataV2 IniSettings;
    //bool m_IsLocked;
    //BOOL  m_bHiColorIcons;
    //CMultiDocTemplate * m_pDocTemplate;
};

//extern MultiviewApp<ViewType02, PagedViewType theApp;
#endif