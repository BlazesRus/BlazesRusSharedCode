// CustomTreeView.cpp : implementation file
//

#include "MultiviewPrecompile.h"
#include "MultiViewApp.h"
#include "CustomTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CustomTreeView

IMPLEMENT_DYNCREATE(CustomTreeView, CView)

BEGIN_MESSAGE_MAP(CustomTreeView, CView)
	//{{AFX_MSG_MAP(CustomTreeView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CustomTreeView drawing

void CustomTreeView::OnDraw(CDC* pDC)
{
	MultiViewDoc* pDoc = GetDocument();
	pDC->TextOut(400,300,"Other view");
	pDC->TextOut(400,320,pDoc->m_str);
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CustomTreeView diagnostics

#ifdef _DEBUG
void CustomTreeView::AssertValid() const
{
	CView::AssertValid();
}

void CustomTreeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CustomTreeView message handlers

MultiViewDoc* CustomTreeView::GetDocument()
{
	return (MultiViewDoc*)m_pDocument;
}
