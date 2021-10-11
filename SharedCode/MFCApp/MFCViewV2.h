#pragma once

#include "MFCDoc.h"
#include "../OtherFunctions/MFCMacrosV3.h"
#include <string>

class MFCViewV2 : public CView
{
protected:
	MFCViewV2() noexcept;
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
	virtual ~MFCViewV2();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	MFC_RuntimeExtPart01(MFCViewV2, CView)
	//Any message map messages here
#ifndef BlazesMFCApp_DisablePrinter
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
#endif
	MFC_RuntimeExtPart02(MFCViewV2)
};

MFC_RuntimeImplimentation(MFCViewV2)
#ifndef _DEBUG  // debug version in MFCViewV2.cpp
inline MFCDoc* MFCViewV2::GetDocument() const
   { return reinterpret_cast<MFCDoc*>(m_pDocument); }
#endif

