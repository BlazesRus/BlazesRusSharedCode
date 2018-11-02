#if !defined(HalfPagedMultiview_IncludeGuard)
#define HalfPagedMultiview_IncludeGuard

#include "MultiviewPrecompile.h"

#ifndef __AFXWIN_H__
#error "include 'MultiviewPrecompile.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include <GlobalCode_IniData/IniDataV2.h>
#include "MultiViewDoc.h"
#include "MultiViewView.h"
#include "AboutDlg.h"
//#include <GlobalCode_IniData/IndexedPDictionary.h>
//#include "BvhFrame.h"

/// <summary>
/// Multiview features based on https://www.codeproject.com/Articles/7686/Using-Multiview
/// </summary>
template <typename ViewType01=CView, typename ViewType02=CView, typename WindowType=CView, typename FrameWindowType=CFrameWnd>//: MainFrame, OtherView, CView, CFrameWnd
class HalfPagedMultiview : public CWinAppEx
{
	ViewType01* MainView;
  VariableList<ViewType02*> AltView;
public:
	/////////////////////////////////////////////////////////////////////////////
	// HalfPagedMultiview construction
	HalfPagedMultiview()
	{
		// TODO: add construction code here,
		// Place all significant initialization in InitInstance
	}

  ~virtual HalfPagedMultiview()
  {

  }

  //Edit this virtual function inside Derived Class with method void InitialyzationCode() defined
  virtual void InitialyzationCode
  {

  }
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

			ViewType01* pActiveView = ((FrameWindowType*)m_pMainWnd)->GetActiveView();
			MainView = pActiveView;
			AltView.Add((WindowType*) new ViewType02);

			CDocument* pDoc = ((FrameWindowType*)m_pMainWnd)->GetActiveDocument();

			CCreateContext context;
			context.m_pCurrentDoc = pDoc;

			UINT m_ID = AFX_IDW_PANE_FIRST + 1;
			CRect rect;

      AltView[CurrentAltView]->Create(NULL, NULL, WS_CHILD, rect, m_pMainWnd, m_ID, &context);

      InitialyzationCode();
			// The one and only window has been initialized, so show and update it.
			m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
			m_pMainWnd->UpdateWindow();

			return TRUE;
		}
	  virtual int ExitInstance()
    {

    }
  //}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMultiViewApp)
/// <summary>
/// App command to run the dialog
/// </summary>
	afx_msg void OnAppAbout()
	{
		AboutDlg aboutDlg;
		aboutDlg.DoModal();
	}
	afx_msg void OnViewOtherview()
	{
		// TODO: Add your command handler code here
		UINT temp = ::GetWindowLong(AltView[CurrentAltView]->m_hWnd, GWL_ID);
		::SetWindowLong(AltView[CurrentAltView]->m_hWnd, GWL_ID, ::GetWindowLong(MainView->m_hWnd, GWL_ID));
		::SetWindowLong(MainView->m_hWnd, GWL_ID, temp);

		MainView->ShowWindow(SW_HIDE);
    AltView[CurrentAltView]->ShowWindow(SW_SHOW);
		//AltView->ShowWindow(SW_SHOW);

		((FrameWindowType*)m_pMainWnd)->SetActiveView(AltView[CurrentAltView]);
		((FrameWindowType*)m_pMainWnd)->RecalcLayout();
		AltView->Invalidate();

	}
	afx_msg void OnViewFirstview()
	{
		// TODO: Add your command handler code here

		UINT temp = ::GetWindowWord(AltView[CurrentAltView]->m_hWnd, GWL_ID);
		::SetWindowWord(AltView[CurrentAltView]->m_hWnd, GWL_ID, ::GetWindowWord(MainView->m_hWnd, GWL_ID));
		::SetWindowWord(MainView->m_hWnd, GWL_ID, temp);

		AltView[CurrentAltView]->ShowWindow(SW_HIDE);
		MainView->ShowWindow(SW_SHOW);

		((FrameWindowType*)m_pMainWnd)->SetActiveView(MainView);
		((FrameWindowType*)m_pMainWnd)->RecalcLayout();
		MainView->Invalidate();
	}
	//}}AFX_MSG

	//DECLARE_ALTERNATIVEMESSAGE_MAP()
protected:
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()
	{
		//typedef HalfPagedMultiview< ViewType01, ViewType02, WindowType, FrameWindowType > ThisClass;
		//typedef CWinAppEx TheBaseClass;
		__pragma(warning(push))
		__pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */
		static const AFX_MSGMAP_ENTRY _messageEntries[] =
		{
			ON_COMMAND(ID_APP_ABOUT, &OnAppAbout)
			ON_COMMAND(ID_VIEW_OTHERVIEW, &OnViewOtherview)
			ON_COMMAND(ID_VIEW_FIRSTVIEW, &OnViewFirstview)
			{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
		};
		__pragma(warning(pop))
			static const AFX_MSGMAP messageMap =
		{ &CWinAppEx::GetThisMessageMap, &_messageEntries[0] };
		return &messageMap;
	}

public:
	virtual const AFX_MSGMAP* GetMessageMap() const
	{
		return GetThisMessageMap();
	}
  unsigned int CurrentAltView = 0;
  //IniDataV2 IniSettings;
  //bool m_IsLocked;
  //BOOL  m_bHiColorIcons;
  //CMultiDocTemplate * m_pDocTemplate;
};

//extern MultiviewApp<ViewType01, ViewType02 theApp;
#endif