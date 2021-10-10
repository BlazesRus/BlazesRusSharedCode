// MultiViewDoc.h : interface of the CMultiViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTIVIEWDOC_H__19549D9C_AEE5_4576_8EB4_C96F0CAC6A29__INCLUDED_)
#define AFX_MULTIVIEWDOC_H__19549D9C_AEE5_4576_8EB4_C96F0CAC6A29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include <string>

class MultiViewDoc : public CDocument
{
//private:
//	static std::string ClassString() { return "MultiViewDoc"; }
protected: // create from serialization only
    MultiViewDoc();
    DECLARE_DYNCREATE(MultiViewDoc)
    CString m_str;
// Attributes
public:

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CMultiViewDoc)
    public:
    virtual BOOL OnNewDocument();
    virtual void Serialize(CArchive& ar);
    //}}AFX_VIRTUAL

// Implementation
public:
    virtual ~MultiViewDoc();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
    //{{AFX_MSG(CMultiViewDoc)
        // NOTE - the ClassWizard will add and remove member functions here.
        //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIVIEWDOC_H__19549D9C_AEE5_4576_8EB4_C96F0CAC6A29__INCLUDED_)
