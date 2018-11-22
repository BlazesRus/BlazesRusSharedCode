// MainFrm.h : interface of the MainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(MainFrame__INCLUDED)
#define MainFrame__INCLUDED

#include "MultiviewPrecompile.h"
//#include <string>

class MainFrame : public CFrameWnd
{
//private:
//	static std::string ClassString() { return "MainFrame"; }
protected: // create from serialization only
	MainFrame();
	DECLARE_DYNCREATE(MainFrame)

	// Attributes
public:

	// Operations
public:

	// Overrides
		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(MainFrame)
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~MainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

	// Generated message map functions
protected:
	//{{AFX_MSG(MainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class MainFrameView : public CView{};
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
