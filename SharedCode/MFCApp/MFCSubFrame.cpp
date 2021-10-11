
// MFCSubFrame.cpp : implementation of the MFCSubFrame class
//

#include "MFCpch.h"
#include "MFCFramework.h"
#include "MFCApp.h"

#include "MFCSubFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// MFCSubFrame

IMPLEMENT_DYNCREATE(MFCSubFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(MFCSubFrame, CMDIChildWndEx)
END_MESSAGE_MAP()

// MFCSubFrame construction/destruction

MFCSubFrame::MFCSubFrame() noexcept
{
    // TODO: add member initialization code here
}

MFCSubFrame::~MFCSubFrame()
{
}


BOOL MFCSubFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs
    if( !CMDIChildWndEx::PreCreateWindow(cs) )
        return FALSE;

    cs.style = WS_CHILD | WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU
        | FWS_ADDTOTITLE | WS_THICKFRAME;

    return TRUE;
}

// MFCSubFrame diagnostics

#ifdef _DEBUG
void MFCSubFrame::AssertValid() const
{
    CMDIChildWndEx::AssertValid();
}

void MFCSubFrame::Dump(CDumpContext& dc) const
{
    CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// MFCSubFrame message handlers
