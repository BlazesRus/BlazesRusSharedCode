// OtherView.cpp : implementation file
//

#include "MultiviewPrecompile.h"
#include "MultiViewApp.h"
#include "OtherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// OtherView

IMPLEMENT_DYNCREATE(OtherView, CView)

OtherView::OtherView()
{
}

OtherView::~OtherView()
{
}


BEGIN_MESSAGE_MAP(OtherView, CView)
    //{{AFX_MSG_MAP(OtherView)
        // NOTE - the ClassWizard will add and remove mapping macros here.
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// OtherView drawing

void OtherView::OnDraw(CDC* pDC)
{
    MultiViewDoc* pDoc = GetDocument();
    pDC->TextOut(400,300,"Other view");
    pDC->TextOut(400,320,pDoc->m_str);
    // TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// OtherView diagnostics

#ifdef _DEBUG
void OtherView::AssertValid() const
{
    CView::AssertValid();
}

void OtherView::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// OtherView message handlers

MultiViewDoc* OtherView::GetDocument()
{
    return (MultiViewDoc*)m_pDocument;
}
