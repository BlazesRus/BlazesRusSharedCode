// XMLView.cpp : implementation of the XMLView class
//
#include "MFCpch.h"
#include "XMLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// XMLView
IMPLEMENT_DYNCREATE(XMLView, MFCView)

BEGIN_MESSAGE_MAP(XMLView, MFCView)
#ifndef BlazesMFCApp_DisablePrinterFeatures
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &MFCView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &MFCView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &MFCView::OnFilePrintPreview)
#endif
END_MESSAGE_MAP()

// XMLView construction/destruction

XMLView::XMLView() noexcept
{
	m_iIndent = 16;				// Indentation for tree branches
	m_iPadding = 4;				// Padding between tree and the control border

	m_bShowLines = TRUE;				// Show lines by default
	m_bScrollBarMessage = FALSE;			// Only relevant when calculating the scrollbar

	m_iDocHeight = 0;				// A polite yet meaningless default

	m_crDefaultTextColor = RGB(58, 58, 58);

	//// Safeguards
	//SetTextFont(8, FALSE, FALSE, "Arial Unicode MS");
	//TextMenu.CreatePopupMenu();
	//contextMenuPopUp.AppendMenuItem(MF_DISABLED, WM_APP, cs, pDC);
	//contextMenuPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), pDC);
}

XMLView::~XMLView()
{
}

BOOL XMLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return MFCView::PreCreateWindow(cs);
}

bool XMLView::LoadDataFromFile(std::string FilePath)
{

}

void XMLView::SaveDataToFile(std::string FilePath)
{
	if (FilePath.back() == '/' || FilePath.back() == '\\') { FilePath += "TextFile.xml"; }
	size_t StringLength;
	char StringChar;
	std::string LineString;
	std::fstream LoadedFileStream;
	//Fix for non-existing file
	CreateFileIfDoesntExist(FilePath);
	LoadedFileStream.open(FilePath.c_str(), std::fstream::out | std::fstream::trunc);
	if (LoadedFileStream.is_open())
	{
		if (LoadedFileStream.good())
		{//Saving to file now

		}
		else
		{
			if (LoadedFileStream.bad()) { std::cout << "Failed Read/Write operation Error!\n"; }
			else if (LoadedFileStream.fail()) { std::cout << "Failed format based Error!\n"; }
			else if (LoadedFileStream.bad()) { std::cout << "Failed Read/Write operation Error!\n"; }
			else if (LoadedFileStream.eof()) {/*Send debug message of reaching end of file?*/ }
		}
		LoadedFileStream.close();
	}
	else
	{
		std::cout << "Failed to open " << FilePath << ".\n";
	}
}

// XMLView drawing

void XMLView::OnDraw(CDC* /*pDC*/)
{
	MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

#ifndef BlazesMFCApp_DisablePrinterFeatures
// XMLView printing
BOOL XMLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void XMLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void XMLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}
#endif

// XMLView diagnostics

#ifdef _DEBUG
void XMLView::AssertValid() const
{
	MFCView::AssertValid();
}

void XMLView::Dump(CDumpContext& dc) const
{
	MFCView::Dump(dc);
}

MFCDoc* XMLView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(MFCDoc)));
	return (MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// XMLView message handlers
