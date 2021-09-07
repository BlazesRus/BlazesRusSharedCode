
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

IMPLEMENT_DYNCREATE(MFCFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(MFCFrame, CFrameWnd)
    ON_WM_CREATE()
    ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WINDOWS_7, ID_VIEW_APPLOOK_WINDOWS_7, &MFCFrame::OnApplicationLook)
    ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WINDOWS_7, ID_VIEW_APPLOOK_WINDOWS_7, &MFCFrame::OnUpdateApplicationLook)
    ON_WM_SETTINGCHANGE()
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
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
        !m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
    {
        TRACE0("Failed to create toolbar\n");
        return -1;      // fail to create
    }

    if (!m_wndStatusBar.Create(this))
    {
        TRACE0("Failed to create status bar\n");
        return -1;      // fail to create
    }
    m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

    // Define MFCApp_DisableDockableToolbar in preprocessor settings if you don't want the toolbar to be dockable
#ifndef MFCApp_DisableDockableToolbar
    m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
    EnableDocking(CBRS_ALIGN_ANY);
    DockControlBar(&m_wndToolBar);
#endif

    return 0;
}

BOOL MFCFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    if( !CFrameWnd::PreCreateWindow(cs) )
        return FALSE;
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs

    return TRUE;
}

BOOL MFCFrame::CreateDockingWindows()
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

    SetDockingWindowIcons(theApp.m_bHiColorIcons);
    return TRUE;
}

void MFCFrame::SetDockingWindowIcons(BOOL bHiColorIcons)
{
    HICON hOutputBarIcon = (HICON) ::LoadImage(::AfxGetResourceHandle(), MAKEINTRESOURCE(bHiColorIcons ? IDI_OUTPUT_WND_HC : IDI_OUTPUT_WND), IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), 0);
    m_wndOutput.SetIcon(hOutputBarIcon, FALSE);

}

// MFCFrame diagnostics

#ifdef _DEBUG
void MFCFrame::AssertValid() const
{
    CFrameWnd::AssertValid();
}

void MFCFrame::Dump(CDumpContext& dc) const
{
    CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// MFCFrame message handlers

void MFCFrame::OnApplicationLook(UINT id)
{
    CWaitCursor wait;

    theApp.m_nAppLook = id;

	//Only Supporting ID_VIEW_APPLOOK_WINDOWS_7 or greater app look visuals
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
    CDockingManager::SetDockingMode(DT_SMART);

    m_wndOutput.UpdateFonts();
    RedrawWindow(nullptr, nullptr, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

}

void MFCFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
    pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}


void MFCFrame::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
    CFrameWnd::OnSettingChange(uFlags, lpszSection);
    m_wndOutput.UpdateFonts();
}
