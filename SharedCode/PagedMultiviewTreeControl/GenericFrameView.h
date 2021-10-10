// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#ifndef GenericFrameView_IncludeGuard
#define GenericFrameView_IncludeGuard

#include "MultiviewPrecompile.h"
#include <string>

/// <summary>
/// Class named GenericFrameView.
/// Implements the <see cref="CView" />
/// </summary>
/// <seealso cref="CView" />
template <typename DocViewType>
class GenericFrameView : public CView
{
    CRuntime_Arg01V2(GenericFrameView, DocViewType, CView)
public:
#ifdef UNICODE
    LPCWSTR ViewName;
#else
    LPCSTR ViewName;
#endif
protected: // create from serialization only
/// <summary>
/// Initializes a new instance of the <see cref="GenericFrameView"/> class.
/// </summary>
    GenericFrameView()
    {
        // TODO: add construction code here
        ViewName = "";
    }
    /// <summary>
    /// Initializes a new instance of the <see cref="GenericFrameView"/> class.
    /// </summary>
    /// <param name="viewName">Name of the view.</param>
    GenericFrameView(
#ifdef UNICODE
        LPCWSTR viewName
#else
        LPCSTR viewName
#endif
    )
    {
        // TODO: add construction code here
        ViewName = viewName;
    }
    //DECLARE_DYNCREATE(GenericFrameView)

// Attributes
public:
    /// <summary>
    /// Gets the document.
    /// </summary>
    /// <returns>DocViewType*</returns>
    DocViewType* GetDocument()
    {
#ifndef _DEBUG
        return (DocViewType*)m_pDocument;
#else
        ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocViewType)));
        return (CDocViewType*)m_pDocument;
#endif
    }

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(GenericFrameView)
    public:
        /// <summary>
        /// Called when [draw].
        /// </summary>
        /// <param name="pDC">The p dc.</param>
        virtual void OnDraw(CDC* pDC)
        {
            DocViewType* pDoc = GetDocument();
            ASSERT_VALID(pDoc);
            // TODO: add draw code for native data here
            pDC->TextOut(400, 300, ViewName);
            pDC->TextOut(400, 320, pDoc->m_str);
        }  // overridden to draw this view
    protected:
    //}}AFX_VIRTUAL

// Implementation
public:
    /// <summary>
    /// Finalizes an instance of the <see cref="GenericFrameView"/> class.
    /// </summary>
    virtual ~GenericFrameView()
    {
    }
#ifdef _DEBUG
    /// <summary>
    /// Asserts the valid.
    /// </summary>
    virtual void AssertValid() const
    {
        CView::AssertValid();
}
    /// <summary>
    /// Dumps the specified dc.
    /// </summary>
    /// <param name="dc">The dc.</param>
    virtual void Dump(CDumpContext& dc) const
    {
        CView::Dump(dc);
    }
#endif

// Generated message map functions
    //{{AFX_MSG(GenericFrameView)
        // NOTE - the ClassWizard will add and remove member functions here.
        //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    BEGIN_AltMESSAGE_MAP()
        // Standard printing commands
        //ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
        //ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
        //ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
    END_AltMESSAGE_MAP(CView)
};

CRuntimeImplimentation_Arg01(GenericFrameView, DocViewType, CView)

#endif
