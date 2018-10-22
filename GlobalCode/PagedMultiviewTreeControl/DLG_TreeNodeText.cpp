// DLG_TreeNodeText.cpp : implementation file
//

#include "MultiviewPrecompile.h"
#include "customtreecontrol.h"
#include "DLG_TreeNodeText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLG_TreeNodeText dialog


CDLG_TreeNodeText::CDLG_TreeNodeText(CWnd* pParent /*=NULL*/)
	: CDialog(CDLG_TreeNodeText::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLG_TreeNodeText)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLG_TreeNodeText::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLG_TreeNodeText)
	DDX_Control(pDX, IDC_EF_TEXT, m_EF_Text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLG_TreeNodeText, CDialog)
	//{{AFX_MSG_MAP(CDLG_TreeNodeText)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLG_TreeNodeText message handlers

BOOL CDLG_TreeNodeText::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	m_EF_Text.SetWindowText( m_csItemText );
	m_EF_Text.SetFocus();

	return FALSE;	// return TRUE unless you set the focus to a control
					// EXCEPTION: OCX Property Pages should return FALSE
}

void CDLG_TreeNodeText::OnOK() 
{
	m_EF_Text.GetWindowText( m_csItemText );

	CDialog::OnOK();
}

