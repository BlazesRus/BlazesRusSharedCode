
// MFCView.cpp : implementation of the MFCView class
//

#include "MFCpch.h"
#include "MFCFramework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApp.h"
#endif

#include "MFCDoc.h"
#include "MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// MFCView

IMPLEMENT_DYNCREATE(MFCView, CView)

BEGIN_MESSAGE_MAP(MFCView, CView)
#ifndef BlazesMFCApp_DisablePrinterFeatures
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
#endif
END_MESSAGE_MAP()

// MFCView construction/destruction

MFCView::MFCView() noexcept
{
	// TODO: add construction code here
}

MFCView::~MFCView()
{
}

BOOL MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// MFCView drawing

void MFCView::OnDraw(CDC* /*pDC*/)
{
	MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

#ifndef BlazesMFCApp_DisablePrinterFeatures
// MFCView printing
BOOL MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}
#endif

// MFCView diagnostics

#ifdef _DEBUG
void MFCView::AssertValid() const
{
	CView::AssertValid();
}

void MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

MFCDoc* MFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(MFCDoc)));
	return (MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// MFCView message handlers
