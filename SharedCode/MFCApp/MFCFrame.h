
// MFCFrame.h : interface of the MFCFrame class
//

#pragma once
#ifdef BlazesMFCApp_EnableOutputWindow
#include "OutputWnd.h"
#endif

class MFCFrame
#ifdef BlazesMFCApp_UseSDI
: public CFrameWnd
#else
: public CMDIFrameWndEx
#endif
{
#ifdef BlazesMFCApp_UseSDI
protected: // create from serialization only
    MFCFrame() noexcept;
    DECLARE_DYNCREATE(MFCFrame)
#else
    DECLARE_DYNAMIC(MFCFrame)
public:
    MFCFrame() noexcept;
#endif

// Attributes
public:

// Operations
public:

// Overrides
public:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
    virtual ~MFCFrame();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
    CToolBar          m_wndToolBar;
    CReBar            m_wndReBar;
    CDialogBar        m_wndDlgBar;
    CStatusBar        m_wndStatusBar;
#ifdef BlazesMFCApp_EnableOutputWindow
    OutputWnd        m_wndOutput;
#endif

// Generated message map functions
protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    DECLARE_MESSAGE_MAP()
#ifdef BlazesMFCApp_EnableOutputWindow
    BOOL CreateOutputWindows();
#endif
};


