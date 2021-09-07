
// MFCFrame.h : interface of the MFCFrame class
//

#pragma once
#include "OutputWnd.h"

class MFCFrame : public CFrameWnd
{
    
protected: // create from serialization only
    MFCFrame() noexcept;
    DECLARE_DYNCREATE(MFCFrame)

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
    CStatusBar        m_wndStatusBar;
    OutputWnd        m_wndOutput;

// Generated message map functions
protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnApplicationLook(UINT id);
    afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
    afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
    DECLARE_MESSAGE_MAP()

    BOOL CreateDockingWindows();
    void SetDockingWindowIcons(BOOL bHiColorIcons);
};


