// MultiView.cpp : Defines the class behaviors for the application.
//

#include "MultiviewPrecompile.h"
#include "BasicMultiviewTemplate.h"

#include "MultiViewDoc.h"
#include "MultiViewView.h"
//#include "MainFrm.h"
//#include "OtherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////Based on AFX BEGIN_TEMPLATE_MESSAGE_MAP
//#if !defined(BEGIN_MULTITEMPLATE_MESSAGE_MAP)
//#define BEGIN_MULTITEMPLATE_MESSAGE_MAP(theClass, type_name, typename02, typename03, typename04, baseClass)			\
//	PTM_WARNING_DISABLE														\
//	template < typename type_name, typename typename02, typename typename03, typename typename04 >											\
//	const AFX_MSGMAP* theClass< type_name, typename02, typename03, typename04>::GetMessageMap() const			\
//	{ return GetThisMessageMap(); }										\
//	template < typename type_name, typename typename02, typename typename03, typename typename04 >											\
//	const AFX_MSGMAP* PASCAL theClass< type_name, typename02, typename03, typename04 >::GetThisMessageMap()		\
//	{																		\
//		typedef theClass< type_name, typename02, typename03, typename04 > ThisClass;							\
//		typedef baseClass TheBaseClass;										\
//		__pragma(warning(push))												\
//		__pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */ \
//		static const AFX_MSGMAP_ENTRY _messageEntries[] =					\
//		{
//#define END_MULTITEMPLATE_MAP() \
//			{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
//		}; \
//	__pragma(warning(pop))	\
//	static const AFX_MSGMAP messageMap = \
//	{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] }; \
//	return &messageMap; \
//	}								  \
//	PTM_WARNING_RESTORE
//#endif

/////////////////////////////////////////////////////////////////////////////
// BasicMultiviewTemplate

////BEGIN_MULTITEMPLATE_MESSAGE_MAP(BasicMultiviewTemplate, ViewType01, ViewType02, WindowType, FrameWindowType, CWinAppEx)
//PTM_WARNING_DISABLE
//template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
//const AFX_MSGMAP* BasicMultiviewTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::GetMessageMap() const
//{ return GetThisMessageMap(); }
//\
//template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
//const AFX_MSGMAP* PASCAL BasicMultiviewTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::GetThisMessageMap()
//{
//typedef BasicMultiviewTemplate< ViewType01, ViewType02, WindowType, FrameWindowType > ThisClass;
//typedef CWinAppEx TheBaseClass;
//__pragma(warning(push))
//__pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */
//static const AFX_MSGMAP_ENTRY _messageEntries[] =
//{
//	//{{AFX_MSG_MAP(BasicMultiviewTemplate)

////END_MULTITEMPLATE_MAP()
//	{
//		0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0
//	}
//};
//__pragma(warning(pop))
//static const AFX_MSGMAP messageMap =
//		{ &CWinAppEx::GetThisMessageMap, &_messageEntries[0] };
//			return &messageMap;
//}
//PTM_WARNING_RESTORE

/////////////////////////////////////////////////////////////////////////////
// BasicMultiviewTemplate construction
template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
BasicMultiviewTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::BasicMultiviewTemplate()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only BasicMultiviewTemplate object
//template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
//BasicMultiviewTemplate<ViewType01, ViewType02, WindowType, FrameWindowType> theApp;

/////////////////////////////////////////////////////////////////////////////
// BasicMultiviewTemplate initialization

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
void BasicMultiviewTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// BasicMultiviewTemplate message handlers

template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
void BasicMultiviewTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::OnViewOtherview()
{
	// TODO: Add your command handler code here
	UINT temp = ::GetWindowLong(m_pOtherView->m_hWnd, GWL_ID);
    ::SetWindowLong(m_pOtherView->m_hWnd, GWL_ID, ::GetWindowLong(m_pFirstView->m_hWnd, GWL_ID));
    ::SetWindowLong(m_pFirstView->m_hWnd, GWL_ID, temp);

	m_pFirstView->ShowWindow(SW_HIDE);
	m_pOtherView->ShowWindow(SW_SHOW);

	((CFrameWnd*)m_pMainWnd)->SetActiveView(m_pOtherView);
	((CFrameWnd*) m_pMainWnd)->RecalcLayout();
    m_pOtherView->Invalidate();

}

template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
void BasicMultiviewTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::OnViewFirstview()
{
 	// TODO: Add your command handler code here

    UINT temp = ::GetWindowWord(m_pOtherView->m_hWnd, GWL_ID);
    ::SetWindowWord(m_pOtherView->m_hWnd, GWL_ID, ::GetWindowWord(m_pFirstView->m_hWnd, GWL_ID));
    ::SetWindowWord(m_pFirstView->m_hWnd, GWL_ID, temp);

 	m_pOtherView->ShowWindow(SW_HIDE);
 	m_pFirstView->ShowWindow(SW_SHOW);

 	((CFrameWnd*)m_pMainWnd)->SetActiveView(m_pFirstView);
 	((CFrameWnd*)m_pMainWnd)->RecalcLayout();
    m_pFirstView->Invalidate();
}



