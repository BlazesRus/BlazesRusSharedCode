#if !defined(AFX_OTHERVIEW_H__34535BED_8D5C_453E_9DAE_F8A9413ABF6E__INCLUDED_)
#define AFX_OTHERVIEW_H__34535BED_8D5C_453E_9DAE_F8A9413ABF6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif

#include "MultiviewPrecompile.h"
#include "MultiViewDoc.h"
//#include <string>

/////////////////////////////////////////////////////////////////////////////
// OtherView view

class OtherView : public CView
{
//private:
//	static std::string ClassString() { return "OtherView"; }
protected:
    DECLARE_DYNCREATE(OtherView)

// Attributes
// Operations
public:
    OtherView();           // protected constructor used by dynamic creation
    virtual ~OtherView();
    //CStaticTreeCtrl	m_ST_Tree;
    //TreeCtrlPage MainTree;
    //TreePage MainTree;

public:
    MultiViewDoc* GetDocument();

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(OtherView)
    protected:
    virtual void OnDraw(CDC* pDC);      // overridden to draw this view
    //}}AFX_VIRTUAL

// Implementation
protected:
#ifdef _DEBUG

    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

    // Generated message map functions
protected:
    //{{AFX_MSG(OtherView)
        // NOTE - the ClassWizard will add and remove member functions here.
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OTHERVIEW_H__34535BED_8D5C_453E_9DAE_F8A9413ABF6E__INCLUDED_)
