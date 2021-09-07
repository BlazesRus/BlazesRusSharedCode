
#pragma once

/////////////////////////////////////////////////////////////////////////////
// OutputList window

class OutputList : public CListBox
{
// Construction
public:
    OutputList() noexcept;

// Implementation
public:
    virtual ~OutputList();

protected:
    afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
    afx_msg void OnEditCopy();
    afx_msg void OnEditClear();
    afx_msg void OnViewOutput();

    DECLARE_MESSAGE_MAP()
};

class OutputWnd : public CDockablePane
{
// Construction
public:
    OutputWnd() noexcept;

    void UpdateFonts();

// Attributes
protected:
    CMFCTabCtrl	m_wndTabs;

    OutputList m_wndOutputBuild;
    OutputList m_wndOutputDebug;
    OutputList m_wndOutputFind;

protected:
    void FillBuildWindow();
    void FillDebugWindow();
    void FillFindWindow();

    void AdjustHorzScroll(CListBox& wndListBox);

// Implementation
public:
    virtual ~OutputWnd();

protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSize(UINT nType, int cx, int cy);

    DECLARE_MESSAGE_MAP()
};

