// CustomTreeControlDlg.cpp : implementation file
//

#include "MultiviewPrecompile.h"
//#include "CustomTreeControl.h"
#include "CustomTreeControlDlg.h"
#include "StaticTreeCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomTreeControlDlg dialog

CCustomTreeControlDlg::CCustomTreeControlDlg(CWnd* pParent /*=NULL*/)
	: CResizableDialog(CCustomTreeControlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCustomTreeControlDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCustomTreeControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CResizableDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustomTreeControlDlg)
	DDX_Control(pDX, IDC_ST_TREE, m_ST_Tree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCustomTreeControlDlg, CResizableDialog)
	//{{AFX_MSG_MAP(CCustomTreeControlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomTreeControlDlg message handlers

BOOL CCustomTreeControlDlg::OnInitDialog()
{
	CResizableDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if(pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if(!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Resizable dialog
	ShowSizeGrip( TRUE );

	AddAnchor( IDC_ST_TREE, TOP_LEFT, BOTTOM_RIGHT );

	// Tree initialization
	m_ST_Tree.SetTextSettings( 8, FALSE, FALSE, "Arial Unicode MS" , RGB(0,64,128) );

	// Tree data
	CTreeNode* author;
	CTreeNode* quotes;
	CTreeNode* works;

	// Third author
	author	= m_ST_Tree.AddToRoot(_T("Voltaire") );

	quotes	= m_ST_Tree.InsertChild( author, _T("Personal Quotes:") );
	m_ST_Tree.InsertChild( author, _T("Real name François-Marie Arouet.") );
	works	= m_ST_Tree.InsertChild( author, _T("Popular works:") );
	m_ST_Tree.InsertChild( author, _T("Born, November 21, 1694. Died, May 30, 1778.") );

	m_ST_Tree.InsertChild( works, _T("Zadig(1747).") );
	m_ST_Tree.InsertChild( works, _T("Candide(1759).") );

	m_ST_Tree.InsertChild( quotes, _T("I have never made but one prayer to God, a very short one: 'O Lord, make my enemies ridiculous.' And God granted it.") );
	m_ST_Tree.InsertChild( quotes, _T("Appreciation is a wonderful thing: It makes what is excellent in others belong to us as well.") );
	m_ST_Tree.InsertChild( quotes, _T("A witty saying proves nothing.") );
	m_ST_Tree.InsertChild( quotes, _T("...the safest course is to do nothing against one's conscience. With this secret, we can enjoy life and have no fear from death.") );

	// Second author
	author	= m_ST_Tree.AddToRoot(_T("Isaac Asimov") );

	quotes	= m_ST_Tree.InsertChild( author, _T("Personal Quotes:") );
	m_ST_Tree.InsertChild( author, _T("Wrote or edited over 500 volumes and an estimated 90,000 letters.") );
	works	= m_ST_Tree.InsertChild( author, _T("Popular works:") );
	m_ST_Tree.InsertChild( author, _T("Born, January 2, 1920. Died, April 6, 1992.") );

	m_ST_Tree.InsertChild( works, _T("I, Robot (1950).") );
	m_ST_Tree.InsertChild( works, _T("Foundation(1951).") );
	m_ST_Tree.InsertChild( works, _T("The Bicentennial Man(1976).") );

	m_ST_Tree.InsertChild( quotes, _T("Part of the inhumanity of the computer is that, once it is competently programmed and working smoothly, it is completely honest.") );
	m_ST_Tree.InsertChild( quotes, _T("Life is pleasant. Death is peaceful. It's the transition that's troublesome.") );
	m_ST_Tree.InsertChild( quotes, _T("The most exciting phrase to hear in science, the one that heralds new discoveries, is not 'Eureka!' (I found it!) but 'That's funny ...'") );

	// First author
	author	= m_ST_Tree.AddToRoot(_T("Hermann Hesse") );

	quotes	= m_ST_Tree.InsertChild( author, _T("Personal Quotes:") );
	m_ST_Tree.InsertChild( author, _T("Won the 1946 Nobel Prize in literature.") );
	works	= m_ST_Tree.InsertChild( author, _T("Popular works:") );
	m_ST_Tree.InsertChild( author, _T("Born, July 2, 1877. Died, August 9, 1962") );

	m_ST_Tree.InsertChild( works, _T("Siddhartha(1922).") );
	m_ST_Tree.InsertChild( works, _T("Der Steppenwolf(1927).") );
	m_ST_Tree.InsertChild( works, _T("The Glass Bead Game(1943).") );

	m_ST_Tree.InsertChild( quotes, _T("The best weapons against the infamies of life are courage, wilfulness and patience. Courage strenthens, wilfulness is fun and patience provides tranquility.") );
	m_ST_Tree.InsertChild( quotes, _T("When dealing with the insane, the best method is to pretend to be sane.") );
	m_ST_Tree.InsertChild( quotes, _T("I have always believed, and I still believe, that whatever good or bad fortune may come our way we can always give it meaning and transform it into something of value.") );
	m_ST_Tree.InsertChild( quotes, _T("Eternity is a mere moment, just long enough for a joke.") );
	m_ST_Tree.InsertChild( quotes, _T("Opinions mean nothing; they may be beautiful or ugly, clever or foolish, anyone can embrace or reject them.") );

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCustomTreeControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CResizableDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCustomTreeControlDlg::OnPaint()
{
	if(IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CResizableDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCustomTreeControlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
