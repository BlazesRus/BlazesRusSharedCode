// MultiViewView.h : interface of the MultiViewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTIVIEWVIEW_H__8776E6CB_7F2B_44B1_92CB_E6292C257F80__INCLUDED_)
#define AFX_MULTIVIEWVIEW_H__8776E6CB_7F2B_44B1_92CB_E6292C257F80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class MultiViewView : public CView
{
protected: // create from serialization only
	MultiViewView();
	DECLARE_DYNCREATE(MultiViewView)

// Attributes
public:
	CMultiViewDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MultiViewView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~MultiViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(MultiViewView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MultiViewView.cpp
inline CMultiViewDoc* MultiViewView::GetDocument()
   { return (CMultiViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIVIEWVIEW_H__8776E6CB_7F2B_44B1_92CB_E6292C257F80__INCLUDED_)
