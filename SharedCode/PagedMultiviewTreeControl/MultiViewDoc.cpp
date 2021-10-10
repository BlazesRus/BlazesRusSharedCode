// MultiViewDoc.cpp : implementation of the CMultiViewDoc class
//

#include "MultiviewPrecompile.h"
#include "MultiViewApp.h"

#include "MultiViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDoc

IMPLEMENT_DYNCREATE(MultiViewDoc, CDocument)

BEGIN_MESSAGE_MAP(MultiViewDoc, CDocument)
    //{{AFX_MSG_MAP(CMultiViewDoc)
        // NOTE - the ClassWizard will add and remove mapping macros here.
        //    DO NOT EDIT what you see in these blocks of generated code!
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDoc construction/destruction

MultiViewDoc::MultiViewDoc()
{
    // TODO: add one-time construction code here
    //m_str="Hello from document";
}

MultiViewDoc::~MultiViewDoc()
{
}

BOOL MultiViewDoc::OnNewDocument()
{
    if (!CDocument::OnNewDocument())
        return FALSE;

    // TODO: add reinitialization code here
    // (SDI documents will reuse this document)

    return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMultiViewDoc serialization

void MultiViewDoc::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        // TODO: add storing code here
    }
    else
    {
        // TODO: add loading code here
    }
}

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDoc diagnostics

#ifdef _DEBUG
void CMultiViewDoc::AssertValid() const
{
    CDocument::AssertValid();
}

void CMultiViewDoc::Dump(CDumpContext& dc) const
{
    CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDoc commands
