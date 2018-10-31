#if !defined(MultiviewApp_IncludeGuard)
#define MultiviewApp_IncludeGuard

#include "MultiviewPrecompile.h"

#ifndef __AFXWIN_H__
#error "include 'MultiviewPrecompile.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include <GlobalCode_IniData/IniDataV2.h>
//#include <GlobalCode_IniData/IndexedPDictionary.h>
//#include "BvhFrame.h"

#define DECLARE_ALTERNATIVEMESSAGE_MAP() \
protected: \
	static const AFX_MSGMAP* PASCAL GetThisMessageMap(); \
	virtual const AFX_MSGMAP* GetMessageMap() const;

template <typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>//: MainFrame, OtherView, CView, CFrameWnd
class BasicMultiviewTemplate : public CWinAppEx
{
	CView* m_pFirstView;
	CView* m_pOtherView;
public:
	CMultiViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiViewApp)
	public:
	virtual BOOL InitInstance();
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