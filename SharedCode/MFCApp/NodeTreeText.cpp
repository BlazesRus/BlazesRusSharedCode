// NodeTreeText.cpp : implementation file
//

#include "MFCpch.h"
#include "NodeTreeText.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// NodeTreeText dialog


NodeTreeText::NodeTreeText(CWnd* pParent /*=NULL*/)
	: CDialog(NodeTreeText::IDD, pParent)
{
	//{{AFX_DATA_INIT(NodeTreeText)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void NodeTreeText::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(NodeTreeText)
	DDX_Control(pDX, IDC_EF_TEXT, m_EF_Text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(NodeTreeText, CDialog)
	//{{AFX_MSG_MAP(NodeTreeText)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// NodeTreeText message handlers

BOOL NodeTreeText::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	m_EF_Text.SetWindowText( m_csItemText );
	m_EF_Text.SetFocus();

	return FALSE;	// return TRUE unless you set the focus to a control
					// EXCEPTION: OCX Property Pages should return FALSE
}

void NodeTreeText::OnOK() 
{
	m_EF_Text.GetWindowText( m_csItemText );

	CDialog::OnOK();
}

