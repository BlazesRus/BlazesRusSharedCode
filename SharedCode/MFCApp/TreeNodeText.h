#if !defined(AFX_DLG_TREENODETEXT_H__D497F021_8720_4B55_A529_B4FC74E3D770__INCLUDED_)
#define AFX_DLG_TREENODETEXT_H__D497F021_8720_4B55_A529_B4FC74E3D770__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLG_TreeNodeText.h : header file
//

#include "AppResources.h"
/////////////////////////////////////////////////////////////////////////////
// TreeNodeText dialog

class TreeNodeText : public CDialog
{
// Construction
public:
	TreeNodeText(CWnd* pParent = NULL);   // standard constructor

	CString		m_csItemText;

// Dialog Data
	//{{AFX_DATA(TreeNodeText)
    enum { IDD = IDD_NODETEXT };
	CEdit	m_EF_Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TreeNodeText)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TreeNodeText)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_TREENODETEXT_H__D497F021_8720_4B55_A529_B4FC74E3D770__INCLUDED_)
