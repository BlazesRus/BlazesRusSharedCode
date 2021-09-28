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
#ifndef BlazesMFCApp_DisablePrinter
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

BOOL XMLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return MFCView::PreCreateWindow(cs);
}

bool XMLView::LoadDataFromFile(std::string FilePath)
{
	Reset();
	//char LineChar;
	//bool InsideXMLComment = false;
	////If false, then inside tagcontent types instead of tags
	//bool InsideTag = false;
	//std::string ScanBuffer = "";

	////First name inside tag becomes CurrentTag
	//std::string CurrentTag = "";
	//std::string CurrentNodeName = "";
	//unsigned int CurrentNodeIndex = 0;
	////0=NormalTag; 1:SelfContainedTag; 2:TagIsClosing; 3:XMLVersionTag
	//int TagType = 0;

	//bool ScanningArgData = false;
	//std::string ArgElement;
	////ArgStringList LastArg;
	////ArgList ArgBuffer;

	//bool PotentialComment = false;
	//bool InsideParenthesis = false;
	////0 = Not Scanning TagContent Yet: 1 = Potential SingleLine TagContent: 2 Multi-line target content
	//short TagContentStage = 0;

	////Current state of code loading for certain sections of code
	//size_t Stage = 0;

	//std::ifstream inFile;
	//inFile.open(FilePath);
	//if (!inFile)
	//{
	//	return false;
	//}
	//while (inFile >> LineChar)
	//{
	//	if (PotentialComment)
	//	{
	//		ScanBuffer += LineChar;
	//		if (ScanBuffer == "--")
	//		{
	//			InsideXMLComment = true;
	//			PotentialComment = false;
	//			ScanBuffer = "";
	//		}
	//		else if (ScanBuffer.size() >= 2)//Detecting non-normal format TagName?
	//		{
	//			PotentialComment = false;
	//			ScanBuffer = "!" + ScanBuffer;
	//		}
	//	}
	//	else if (InsideXMLComment)//Ignoring all xml inside xml formatted comment
	//	{
	//		Stage = ScanBuffer.size();
	//		if (Stage == 0)
	//		{
	//			if (LineChar == '-')
	//			{
	//				ScanBuffer = "-";
	//			}
	//		}
	//		else if (Stage == 1)
	//		{
	//			if (LineChar == '-')
	//			{
	//				ScanBuffer = "--";
	//			}
	//			else
	//			{
	//				ScanBuffer = "";
	//			}
	//		}
	//		else
	//		{
	//			if (LineChar == '>')
	//			{
	//				InsideXMLComment = false;
	//			}
	//			ScanBuffer = "";
	//		}
	//	}
	//	else if (ScanningArgData)
	//	{
	//		if (Stage == 0)
	//		{
	//			if (LineChar == '=')
	//			{
	//				Stage = 1;
	//				//CurrentArgName = ScanBuffer;//Don't need to store in separate variable since ScanBuffer not going to be changed until exit scanning argument data
	//				ArgElement = "";
	//			}
	//			else if (LineChar != ' ' && LineChar != '\t' && LineChar != '\n')//Skip Whitespace
	//			{
	//				ScanBuffer += LineChar;
	//			}
	//		}
	//		else if (Stage == 1)
	//		{
	//			if (LineChar == '\"')
	//			{
	//				Stage = 2;
	//			}
	//		}
	//		else if (Stage == 2)
	//		{
	//			if (LineChar == '\"') { Stage = 3; }
	//		}
	//		else if (Stage == 3)
	//		{
	//			if (LineChar == ',')
	//			{
	//				LastArg.Add(ArgElement);
	//			}
	//			else if (LineChar == '\"')
	//			{
	//				ArgBuffer.Add(ScanBuffer, LastArg);
	//				ScanningArgData = false;
	//			}
	//			else
	//			{
	//				ArgElement += LineChar;
	//			}
	//		}
	//	}
	//	else
	//	{
	//		if (InsideTag)
	//		{
	//			if (ScanBuffer == "/" && LineChar == '>')
	//			{
	//				//switch (TagType)
	//				//{
	//				//default://TagIsClosing(TagType==2)
	//				//		//Decrease TagDepth
	//				//	TagDepth.RemoveLastTagMatch(CurrentTag);
	//				//	break;
	//				//case 1://SelfContainedTag
	//				//	NodeBank.Add(CurrentTag, ArgBuffer, CurrentNodeIndex);
	//				//	break;
	//				//case 3://XMLVersionTag(Same as SelfContained Tag except for ? in front and such)
	//				//	break;
	//				//}
	//				//CurrentTag = "";//Reset it to clear buffer so next tag has fresh storage
	//				//InsideTag = false; TagContentStage = 0;
	//			}
	//			else if (LineChar == '>')
	//			{
	//				////(TagType==0)
	//				//CurrentNodeIndex = NodeBank.Add(CurrentTag, ArgBuffer, CurrentNodeIndex);//Index of Last Entered Node is it's parent
	//				//if (InsideClassNodeSection && CurrentClassNodeIndex == 0 && CurrentTag == hkobject && ArgBuffer.HasKey(Signature))
	//				//{
	//				//	CurrentClassNodeIndex = CurrentNodeIndex;
	//				//	CurrentNodeName = ArgBuffer["Name"][0];
	//				//	NodeLinks.Add(CurrentNodeName, CurrentClassNodeIndex);
	//				//}
	//				////Increase TagDepth
	//				//CurrentNodeName = CurrentTag;
	//				//CurrentTag = "";//Reset it to clear buffer so next tag has fresh storage
	//				//InsideTag = false; TagContentStage = 0;

	//			}
	//			else if (CurrentTag.empty())
	//			{
	//				if (!ScanBuffer.empty())
	//				{
	//					if (LineChar == '!')//Detecting potential Commented Out Parts
	//					{
	//						PotentialComment = true;
	//					}
	//					else if (LineChar == ' ' || LineChar == '/t')
	//					{
	//						CurrentTag = ScanBuffer;
	//					}
	//					else
	//					{
	//						ScanBuffer += LineChar;
	//					}
	//				}
	//				else if (LineChar != ' ' && LineChar != '	' && LineChar != '\n')
	//				{
	//					ScanBuffer += LineChar;
	//					if (LineChar != '\\')
	//					{
	//						ScanningArgData = true; Stage = 0;
	//					}
	//				}
	//			}
	//			else if (TagContentStage > 0)
	//			{

	//			}
	//			else
	//			{
	//				if (LineChar == '<')
	//				{
	//					InsideTag = true;
	//				}
	//				else if (LineChar != ' ' && LineChar != '	' && LineChar != '\n')
	//				{
	//					ScanBuffer = LineChar;
	//					TagContentStage = 1;
	//				}
	//			}
	//		}
	//	}
	//}
	return true;
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

#ifndef BlazesMFCApp_DisablePrinter
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
