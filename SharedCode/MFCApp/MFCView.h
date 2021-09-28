
// MFCView.h : interface of the MFCView class
//

#pragma once

#include "MFCDoc.h"

class MFCView : public CView
{
protected: // create from serialization only
	MFCView() noexcept;
	DECLARE_DYNCREATE(MFCView)

// Attributes
public:
	MFCDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
#ifndef BlazesMFCApp_DisablePrinter
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
#endif

// Implementation
public:
	virtual ~MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCView.cpp
inline MFCDoc* MFCView::GetDocument() const
   { return reinterpret_cast<MFCDoc*>(m_pDocument); }
#endif

