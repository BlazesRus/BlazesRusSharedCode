// MultiView.cpp : Defines the class behaviors for the application.
//

#include "MultiviewPrecompile.h"
#include "MultiviewAppTemplate.h"

#include "MultiViewDoc.h"
#include "MultiViewView.h"
//#include "MainFrm.h"
//#include "OtherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define BEGIN_MULTITEMPLATE_MESSAGE_MAP(theClass, type_name, typename02, typename03, typename04, baseClass)			\
	PTM_WARNING_DISABLE														\
	template < typename type_name, typename typename02, typename typename03, typename typename04 >											\
	const AFX_MSGMAP* theClass< type_name, typename02, typename03, typename04>::GetMessageMap() const			\
	{ return GetThisMessageMap(); }										\
	template < typename type_name, typename typename02, typename typename03, typename typename04 >											\
	const AFX_MSGMAP* PASCAL theClass< type_name, typename02, typename03, typename04 >::GetThisMessageMap()		\
	{																		\
		typedef theClass< type_name, typename02, typename03, typename04 > ThisClass;							\
		typedef baseClass TheBaseClass;										\
		__pragma(warning(push))												\
		__pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */ \
		static const AFX_MSGMAP_ENTRY _messageEntries[] =					\
		{
#define END_MULTITEMPLATE_MAP() \
			{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
		}; \
	__pragma(warning(pop))	\
	static const AFX_MSGMAP messageMap = \
	{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] }; \
	return &messageMap; \
	}								  \
	PTM_WARNING_RESTORE

/////////////////////////////////////////////////////////////////////////////
// MultiviewAppTemplate

//BEGIN_MESSAGE_MAP(MultiviewAppTemplate, CWinAppEx)
BEGIN_MULTITEMPLATE_MESSAGE_MAP(MultiviewAppTemplate, ViewType01, ViewType02, WindowType, FrameWindowType, CWinAppEx)
        //{{AFX_MSG_MAP(MultiviewAppTemplate)
        //ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
        ON_COMMAND(ID_VIEW_OTHERVIEW, OnViewOtherview)
        ON_COMMAND(ID_VIEW_FIRSTVIEW, OnViewFirstview)
        //}}AFX_MSG_MAP
        // Standard file based document commands
        //ON_COMMAND(ID_FILE_NEW, CWinAppEx::OnFileNew)
        //ON_COMMAND(ID_FILE_OPEN, CWinAppEx::OnFileOpen)
        // Standard print setup command
        //ON_COMMAND(ID_FILE_PRINT_SETUP, CWinAppEx::OnFilePrintSetup)
END_MULTITEMPLATE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MultiviewAppTemplate construction

template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
MultiviewAppTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::MultiviewAppTemplate()
{
    // TODO: add construction code here,
    // Place all significant initialization in InitInstance
}

template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
MultiviewAppTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::~MultiviewAppTemplate()
{
}

template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
inline BOOL MultiviewAppTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::InitInstance()
{
    AfxEnableControlContainer();

    //LoadStdProfileSettings();  // Load standard INI file options (including MRU)

    // Register the application's document templates.  Document templates
    //  serve as the connection between documents, frame windows and views.

    CSingleDocTemplate* pDocTemplate;
    pDocTemplate = new CSingleDocTemplate(
        IDR_MAINFRAME,
        RUNTIME_CLASS(CMultiViewDoc),
        RUNTIME_CLASS(ViewType01),       // main SDI frame window
        RUNTIME_CLASS(MultiViewView));
    AddDocTemplate(pDocTemplate);

    // Parse command line for standard shell commands, DDE, file open
    CCommandLineInfo cmdInfo;
    ParseCommandLine(cmdInfo);

    // Dispatch commands specified on the command line
    if (!ProcessShellCommand(cmdInfo))
        return FALSE;

    CView* pActiveView = ((FrameWindowType*)m_pMainWnd)->GetActiveView();
    MainView = pActiveView;

    CDocument* pDoc = ((FrameWindowType*)m_pMainWnd)->GetActiveDocument();

    CCreateContext context;
    context.m_pCurrentDoc = pDoc;

    UINT m_ID = AFX_IDW_PANE_FIRST + 1;
    CRect rect;

	CurrentAltView = AltView.Add(0, (WindowType*) new ViewType02);//AltView = (CView*) new ViewType02;
    AltView[CurrentAltView] = Create(NULL, NULL, WS_CHILD, rect, m_pMainWnd, m_ID, &context);

    // The one and only window has been initialized, so show and update it.
    m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only MultiviewAppTemplate object

//MultiviewAppTemplate theApp;

/////////////////////////////////////////////////////////////////////////////
// MultiviewAppTemplate initialization


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
    CAboutDlg();

// Dialog Data
    //{{AFX_DATA(CAboutDlg)
    enum { IDD = IDD_ABOUTBOX };
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CAboutDlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    //{{AFX_MSG(CAboutDlg)
        // No message handlers
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
    //{{AFX_DATA_INIT(CAboutDlg)
    //}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CAboutDlg)
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
    //{{AFX_MSG_MAP(CAboutDlg)
        // No message handlers
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
void MultiviewAppTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::OnAppAbout()
{
    CAboutDlg aboutDlg;
    aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// MultiviewAppTemplate message handlers
template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
void MultiviewAppTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::OnViewOtherview()
{
    // TODO: Add your command handler code here
    UINT temp = ::GetWindowLong(AltView->m_hWnd, GWL_ID);
    ::SetWindowLong(AltView[CurrentAltView]->m_hWnd, GWL_ID, ::GetWindowLong(MainView->m_hWnd, GWL_ID));
    ::SetWindowLong(MainView->m_hWnd, GWL_ID, temp);

    MainView->ShowWindow(SW_HIDE);
    AltView[CurrentAltView]->ShowWindow(SW_SHOW);

    ((FrameWindowType*)m_pMainWnd)->SetActiveView(AltView[CurrentAltView]);
    ((FrameWindowType*)m_pMainWnd)->RecalcLayout();
    AltView->Invalidate();

}

template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
void MultiviewAppTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::OnViewFirstview()
{
 	// TODO: Add your command handler code here

    UINT temp = ::GetWindowWord(AltView->m_hWnd, GWL_ID);
    ::SetWindowWord(AltView[CurrentAltView]->m_hWnd, GWL_ID, ::GetWindowWord(MainView->m_hWnd, GWL_ID));
    ::SetWindowWord(MainView->m_hWnd, GWL_ID, temp);

 	AltView[CurrentAltView]->ShowWindow(SW_HIDE);
 	MainView->ShowWindow(SW_SHOW);

 	((FrameWindowType*)m_pMainWnd)->SetActiveView(MainView);
 	((FrameWindowType*)m_pMainWnd)->RecalcLayout();
    MainView->Invalidate();
}




