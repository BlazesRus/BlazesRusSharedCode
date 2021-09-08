// DLG_TreeNodeText.cpp : implementation file
//

#include "StdBhvTree.h"
//#include "TreeControl.h"
#include "TreeNodeText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TreeNodeText dialog


TreeNodeText::TreeNodeText(CWnd* pParent /*=NULL*/)
	: CDialog(TreeNodeText::IDD, pParent)
{
	//{{AFX_DATA_INIT(TreeNodeText)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void TreeNodeText::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TreeNodeText)
	DDX_Control(pDX, IDC_EF_TEXT, m_EF_Text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TreeNodeText, CDialog)
	//{{AFX_MSG_MAP(TreeNodeText)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TreeNodeText message handlers

BOOL TreeNodeText::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	m_EF_Text.SetWindowText( m_csItemText );
	m_EF_Text.SetFocus();

	return FALSE;	// return TRUE unless you set the focus to a control
					// EXCEPTION: OCX Property Pages should return FALSE
}

void TreeNodeText::OnOK() 
{
	m_EF_Text.GetWindowText( m_csItemText );

	CDialog::OnOK();
}

