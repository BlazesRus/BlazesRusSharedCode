#include "MFCpch.h"
#include "MFCFramework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApp.h"
#endif

#include "MFCDoc.h"
#include "MFCViewV2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// MFCViewV2 construction/destruction

MFCViewV2::MFCViewV2() noexcept
{
    // TODO: add construction code here
}

MFCViewV2::~MFCViewV2()
{
}

BOOL MFCViewV2::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs

    return CView::PreCreateWindow(cs);
}

// MFCViewV2 drawing

void MFCViewV2::OnDraw(CDC* /*pDC*/)
{
    MFCDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // TODO: add draw code for native data here
}

#ifndef BlazesMFCApp_DisablePrinter
// MFCViewV2 printing
BOOL MFCViewV2::OnPreparePrinting(CPrintInfo* pInfo)
{
    // default preparation
    return DoPreparePrinting(pInfo);
}

void MFCViewV2::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add extra initialization before printing
}

void MFCViewV2::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add cleanup after printing
}
#endif

// MFCViewV2 diagnostics

#ifdef _DEBUG
void MFCViewV2::AssertValid() const
{
    CView::AssertValid();
}

void MFCViewV2::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

MFCDoc* MFCViewV2::GetDocument() const // non-debug version is inline
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(MFCDoc)));
    return (MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// MFCViewV2 message handlers