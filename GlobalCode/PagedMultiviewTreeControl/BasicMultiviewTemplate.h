#if !defined(MultiviewApp_IncludeGuard)
#define MultiviewApp_IncludeGuard

#include "MultiviewPrecompile.h"

#ifndef __AFXWIN_H__
#error "include 'MultiviewPrecompile.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include <GlobalCode_IniData/IniDataV2.h>
#include "MultiViewDoc.h"
#include "MultiViewView.h"
//#include <GlobalCode_IniData/IndexedPDictionary.h>
//#include "BvhFrame.h"

#if !defined(DECLARE_ALTERNATIVEMESSAGE_MAP)
#define DECLARE_ALTERNATIVEMESSAGE_MAP() \
protected: \
	static const AFX_MSGMAP* PASCAL GetThisMessageMap(); \
	virtual const AFX_MSGMAP* GetMessageMap() const;
#endif

template <typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>//: MainFrame, OtherView, CView, CFrameWnd
class BasicMultiviewTemplate : public CWinAppEx
{
	CView* m_pFirstView;
	CView* m_pOtherView;
public:
	BasicMultiviewTemplate();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiViewApp)
	public:
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
				RUNTIME_CLASS(ViewType01),       // main SDI frame window
				RUNTIME_CLASS(MultiViewView));
			AddDocTemplate(pDocTemplate);

			// Parse command line for standard shell commands, DDE, file open
			CCommandLineInfo cmdInfo;
			ParseCommandLine(cmdInfo);

			// Dispatch commands specified on the command line
			if (!ProcessShellCommand(cmdInfo))
				return FALSE;

			CView* pActiveView = ((CFrameWnd*)m_pMainWnd)->GetActiveView();
			m_pFirstView = pActiveView;
			m_pOtherView = (CView*) new ViewType02;

			CDocument* pDoc = ((CFrameWnd*)m_pMainWnd)->GetActiveDocument();

			CCreateContext context;
			context.m_pCurrentDoc = pDoc;

			UINT m_ID = AFX_IDW_PANE_FIRST + 1;
			CRect rect;

			m_pOtherView->Create(NULL, NULL, WS_CHILD, rect, m_pMainWnd, m_ID, &context);

			// The one and only window has been initialized, so show and update it.
			m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
			m_pMainWnd->UpdateWindow();

			return TRUE;
		}
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMultiViewApp)
	afx_msg void OnAppAbout();
	afx_msg void OnViewOtherview();
	afx_msg void OnViewFirstview();
	//}}AFX_MSG
	DECLARE_ALTERNATIVEMESSAGE_MAP()
//public:
//    bool m_IsLocked;
//    int CurrentAltView = 0;
//    IniDataV2 IniSettings;
////Multiview features added based on https://www.codeproject.com/Articles/7686/Using-Multiview
//    WindowType* MainView;
//    IndexedPDictionary<ViewType02> AltView;
//    BasicMultiviewTemplate();
//    virtual ~BasicMultiviewTemplate();
//
//    CMultiDocTemplate * m_pDocTemplate;
//    virtual BOOL InitInstance();
//    virtual int ExitInstance();
//
//    // Implementation
//    BOOL  m_bHiColorIcons;
//
//    //virtual void PreLoadState();
//    //virtual void LoadCustomState();
//    //virtual void SaveCustomState();
//
//    afx_msg void OnAppAbout();
//    //afx_msg void OnFileNewFrame();
//    //afx_msg void OnFileNew();
//    //Multiview based functions
//    afx_msg void OnViewOtherview();
//    afx_msg void OnViewFirstview();
};

//extern MultiviewApp<ViewType01, ViewType02 theApp;
#endif