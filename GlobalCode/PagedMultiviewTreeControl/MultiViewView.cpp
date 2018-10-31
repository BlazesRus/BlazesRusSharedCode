// MultiViewView.cpp : implementation of the MultiViewView class
//

#include "MultiviewPrecompile.h"
#include "MultiViewApp.h"

#include "MultiViewDoc.h"
#include "MultiViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MultiViewView

IMPLEMENT_DYNCREATE(MultiViewView, CView)

BEGIN_MESSAGE_MAP(MultiViewView, CView)
	//{{AFX_MSG_MAP(MultiViewView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MultiViewView construction/destruction

MultiViewView::MultiViewView()
{
	// TODO: add construction code here

}

MultiViewView::~MultiViewView()
{
}


/////////////////////////////////////////////////////////////////////////////
// MultiViewView drawing

void MultiViewView::OnDraw(CDC* pDC)
{
	MultiViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(400,300,"First view");
	pDC->TextOut(400,320,pDoc->m_str);
}

/////////////////////////////////////////////////////////////////////////////
// MultiViewView diagnostics

#ifdef _DEBUG
void MultiViewView::AssertValid() const
{
	CView::AssertValid();
}

void MultiViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMultiViewDoc* MultiViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiViewDoc)));
	return (CMultiViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// MultiViewView message handlers
