
// MFCFrame.cpp : implementation of the MFCFrame class
//

#include "MFCpch.h"
#include "MFCFramework.h"
#include "MFCApp.h"

#include "MFCFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// MFCFrame
#ifdef BlazesMFCApp_UseSDI
IMPLEMENT_DYNCREATE(MFCFrame, CFrameWnd)
#else
IMPLEMENT_DYNAMIC(MFCFrame, CMDIFrameWndEx)
#endif

#ifdef BlazesMFCApp_UseSDI
BEGIN_MESSAGE_MAP(MFCFrame, CFrameWnd)
#else
BEGIN_MESSAGE_MAP(MFCFrame, CMDIFrameWndEx)
#endif
    ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
    ID_SEPARATOR,           // status line indicator
    ID_INDICATOR_CAPS,
    ID_INDICATOR_NUM,
    ID_INDICATOR_SCRL,
};

// MFCFrame construction/destruction

MFCFrame::MFCFrame() noexcept
{
    // TODO: add member initialization code here
}

MFCFrame::~MFCFrame()
{
}

int MFCFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
#ifdef BlazesMFCApp_UseSDI
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
#else
    if (CMDIFrameWndEx::OnCreate(lpCreateStruct) == -1)
#endif
        return -1;

#ifndef BlazesMFCApp_UseSDI
    CMDITabInfo mdiTabParams;
    mdiTabParams.m_style = CMFCTabCtrl::STYLE_3D_ONENOTE; // other styles available...
    mdiTabParams.m_bActiveTabCloseButton = TRUE;      // set to FALSE to place close button at right of tab area
    mdiTabParams.m_bTabIcons = FALSE;    // set to TRUE to enable document icons on MDI tabs
    mdiTabParams.m_bAutoColor = TRUE;    // set to FALSE to disable auto-coloring of MDI tabs
    mdiTabParams.m_bDocumentMenu = TRUE; // enable the document menu at the right edge of the tab area
    EnableMDITabbedGroups(TRUE, mdiTabParams);
#endif

    if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT | TBSTYLE_TRANSPARENT) ||
        !m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
    {
        TRACE0("Failed to create toolbar\n");
        return -1;      // fail to create
    }
    if (!m_wndDlgBar.Create(this, IDR_MAINFRAME, CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
    {
        TRACE0("Failed to create dialog bar\n");
        return -1;		// fail to create
    }

    if (!m_wndReBar.Create(this) || !m_wndReBar.AddBar(&m_wndToolBar) || !m_wndReBar.AddBar(&m_wndDlgBar))
    {
        TRACE0("Failed to create rebar\n");
        return -1;      // fail to create
    }

    if (!m_wndStatusBar.Create(this))
    {
        TRACE0("Failed to create status bar\n");
        return -1;      // fail to create
    }
    m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

#ifndef BlazesMFCApp_DisableTooltips
    m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
#endif

#ifndef BlazesMFCApp_UseSDI
    // Switch the order of document name and application name on the window title bar. This
    // improves the usability of the taskbar because the document name is visible with the thumbnail.
    ModifyStyle(0, FWS_PREFIXTITLE);
#endif

    return 0;
}

BOOL MFCFrame::PreCreateWindow(CREATESTRUCT& cs)
{
#ifdef BlazesMFCApp_UseSDI
    if( !CFrameWnd::PreCreateWindow(cs) )
#else
    if( !CMDIFrameWndEx::PreCreateWindow(cs) )
#endif
        return FALSE;
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs

    return TRUE;
}

#ifdef BlazesMFCApp_EnableOutputWindow
BOOL MFCFrame::CreateOutputWindows()
{
    BOOL bNameValid;
    // Create output window
    CString strOutputWnd;
    bNameValid = strOutputWnd.LoadString(IDS_OUTPUT_WND);
    ASSERT(bNameValid);
    if (!m_wndOutput.Create(strOutputWnd, this, CRect(0, 0, 100, 100), TRUE, ID_VIEW_OUTPUTWND, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
    {
        TRACE0("Failed to create Output window\n");
        return FALSE; // failed to create
    }

    HICON hOutputBarIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(IDI_OUTPUT_WND_HC), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
    m_wndOutput.SetIcon(hOutputBarIcon, FALSE);
    return TRUE;
}
#endif

// MFCFrame diagnostics

#ifdef _DEBUG
void MFCFrame::AssertValid() const
{
#ifdef BlazesMFCApp_UseSDI
    CFrameWnd::AssertValid();
#else
    CMDIFrameWndEx::AssertValid();
#endif
}

void MFCFrame::Dump(CDumpContext& dc) const
{
#ifdef BlazesMFCApp_UseSDI
    CFrameWnd::Dump(dc);
#else
    CMDIFrameWndEx::Dump(dc);
#endif
}
#endif //_DEBUG


// MFCFrame message handlers

