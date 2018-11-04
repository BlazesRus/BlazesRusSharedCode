// CustomTreeControlDlg.h : header file
//

#if !defined(AFX_CUSTOMTREECONTROLDLG_H__B6655738_67F7_4BD2_A663_45943F988A2A__INCLUDED_)
#define AFX_CUSTOMTREECONTROLDLG_H__B6655738_67F7_4BD2_A663_45943F988A2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Resource.h"
#include "ResizableDialog.h"
#include "StaticTreeCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CCustomTreeControlDlg dialog

class CCustomTreeControlDlg : public CResizableDialog
{
// Construction
public:
	CCustomTreeControlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCustomTreeControlDlg)
	enum { IDD = IDD_CUSTOMTREECONTROL_DIALOG };
	CStaticTreeCtrl	m_ST_Tree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomTreeControlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCustomTreeControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMTREECONTROLDLG_H__B6655738_67F7_4BD2_A663_45943F988A2A__INCLUDED_)
