
// MFCSubFrame.h : interface of the MFCSubFrame class
//

#pragma once

class MFCSubFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(MFCSubFrame)
public:
	MFCSubFrame() noexcept;

// Attributes
protected:
	CSplitterWndEx m_wndSplitter;
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~MFCSubFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};
