// DFBody2DView.cpp : implementation of the DFBody2DView class
//
#include "MFCpch.h"
#include "DFBody2DView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// DFBody2DView
IMPLEMENT_DYNCREATE(DFBody2DView, MFCView)

BEGIN_MESSAGE_MAP(DFBody2DView, MFCView)
#ifndef BlazesMFCApp_DisablePrinter
    // Standard printing commands
    ON_COMMAND(ID_FILE_PRINT, &MFCView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_DIRECT, &MFCView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, &MFCView::OnFilePrintPreview)
#endif
END_MESSAGE_MAP()

// DFBody2DView construction/destruction

DFBody2DView::DFBody2DView() noexcept
{
    m_iIndent = 16;				// Indentation for tree branches
    m_iPadding = 4;				// Padding between tree and the control border

    m_bShowLines = TRUE;				// Show lines by default
    m_bScrollBarMessage = FALSE;			// Only relevant when calculating the scrollbar

    m_iDocHeight = 0;				// A polite yet meaningless default

    m_DefaultTextColor = RGB(58, 58, 58);

    //// Safeguards
    //SetTextFont(8, FALSE, FALSE, "Arial Unicode MS");
    //TextMenu.CreatePopupMenu();
    //contextMenuPopUp.AppendMenuItem(MF_DISABLED, WM_APP, cs, pDC);
    //contextMenuPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), pDC);
}

BOOL DFBody2DView::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs
    return MFCView::PreCreateWindow(cs);
}

bool DFBody2DView::LoadDataFromFile(std::string FilePath)
{
    Reset();
    char LineChar;
    bool InsideXMLComment = false;
    bool InsideTag = false;
    std::string ScanBuffer = "";

    std::string PreviousTag = "";
    std::string NextTag = "";

    //unsigned _int64 LastParentTagIndex;
    unsigned _int64 PreviousTagIndex;
    unsigned _int64 NextTagIndex;

    ArgList tagArgData;

     //0=NormalTag; 1:SelfContainedTag; 2:TagIsClosing; 3:XMLVersionTag
    int8_t TagType = 0;
    bool ArgHasNoValue = false;
    bool PotentialComment = false;
    bool InsideParenthesis = false;
    bool ScanningArgData = false;
    bool TagNameHasArg02 = false;
    std::string TagNameArg02 = "";
    int8_t stage = 0;

    std::ifstream inFile;
    inFile.open(FilePath);
    if (!inFile)
    {
        return false;
    }
    while (inFile >> LineChar)
    {
        if (PotentialComment)
        {
            ScanBuffer += LineChar;
            if (ScanBuffer == "--")
            {
                InsideXMLComment = true;
                PotentialComment = false;
                ScanBuffer = "";
            }
            else if (ScanBuffer.size() >= 2)//Detecting non-normal format TagName?
            {
                PotentialComment = false;
                ScanBuffer = "!" + ScanBuffer;
            }
        }
        else if (InsideXMLComment)//Ignoring all xml inside xml formatted comment
        {
            stage = ScanBuffer.size();
            if (stage == 0)
            {
                if (LineChar == '-')
                {
                    ScanBuffer = "-";
                }
            }
            else if (stage == 1)
            {
                if (LineChar == '-')
                {
                    ScanBuffer = "--";
                }
                else
                {
                    ScanBuffer = "";
                }
            }
            else
            {
                if (LineChar == '>')
                {
                    InsideXMLComment = false;
                }
                ScanBuffer = "";
            }
        }
        else if (ScanningArgData)
        {
            if (stage == 0)
            {
                if (LineChar != '=')
                {
                    stage = 1; TagNameArg02 = "";
                }
                else if (LineChar != ' ' && LineChar != '\t' && LineChar != '\n')//Skip Whitespace
                {
                    ScanBuffer += LineChar;
                }
            }
            else
            {
                if (LineChar == '\"')
                {
                    if (InsideParenthesis && !TagNameArg02.empty())//End argument inside parenthesis with second parenthesis instead of space
                    {
                        tagArgData.Add(ScanBuffer, TagNameArg02);
                    }
                    InsideParenthesis = !InsideParenthesis;
                }
                else
                {
                    if (InsideParenthesis)
                    {
                        TagNameArg02 += LineChar;
                    }
                }
            }
        }
        else if (InsideTag)
        {
            if (LineChar == '>')
            {
                unsigned _int64 IndexPos;
                InsideTag = false;
                ////Add NextTag into tree
                //if (TagType == 1)
                //{
                //	//IndexPos = AddNode(NextTag, 1, CurrentTagIndex);
                //	//NodeBank[IndexPos].AdditionTagOptions
                //}
                //else if (TagType == 2)
                //{
                //	if (NextTag == PreviousTag)//Normal Exiting of Previous Tag
                //	{
                //		//TagDepth.Remove(TagDepth.size() - 1);//Remove last tag from depth
                //	}
                //	else//Rare exiting of non-previous tag
                //	{
                //		//Write code for this later(not as important)
                //	}
                //	//Add TagContent Buffer into Node
                //}
                //else
                //{
                //	IndexPos = AddNode(NextTag, 0, CurrentTagIndex);
                //	PreviousTag = NextTag;
                //	CurrentTagIndex = IndexPos;
                //	//TagDepth.Add(PreviousTag);
                //}
                ////Clear Buffers after adding Tag to tree
                //NextTag = ""; ScanBuffer = ""; TagType = 0;
            }
            else if (NextTag.empty())
            {
                if (ScanBuffer.empty())
                {
                    //if (LineChar == '/')//Detected Closing Tag
                    //{
                    //    TagType = 2;
                    //}
                    //else if (LineChar == '?' && TagType == 0)
                    //{
                    //    TagType = 3;
                    //}
                    //else if (LineChar == ' ' || LineChar == '\t' || LineChar == '\n')
                    //{
                    //    if (!ScanBuffer.empty())//End Tag on whitespace if buffer not empty
                    //    {
                    //        NextTag = ScanBuffer;
                    //        ScanBuffer = "";
                    //    }
                    //}
                    //else if (LineChar == '!')
                    //{
                    //    PotentialComment = true;
                    //}
                    //else
                    //{
                    //    ScanBuffer += LineChar;
                    //}
                }
                else
                {
                    //if (LineChar == '?' && TagType == 0)
                    //{
                    //    TagType = 3;
                    //}
                    //else if (LineChar == ' ' || LineChar == '\t' || LineChar == '\n')
                    //{
                    //    if (!ScanBuffer.empty())//End Tag on whitespace if buffer not empty
                    //    {
                    //        NextTag = ScanBuffer;
                    //        ScanBuffer = "";
                    //    }
                    //}
                    //else
                    //{
                    //    ScanBuffer += LineChar;
                    //}
                }
            }
            else
            {
                //if (LineChar == '/')//Detected Self-Contained Tag
                //{
                //    TagType = 1;
                //}
                //else if (LineChar != '?' && LineChar != ' ' && LineChar != '\t' && LineChar != '\n')//Get Tag arguments etc here
                //{
                //    ScanningArgData = true; stage = 0; ScanBuffer = LineChar;
                //}
            }
        }
        else
        {
            if (LineChar == '<')
            {
                InsideTag = true;
            }
            else
            {
                if (!PreviousTag.empty())//Get TagContent here
                {
                    //TagDepth.LastNode().TagContent += LineChar;
                }
            }
        }
    }
    return true;
}

void DFBody2DView::SaveDataToFile(std::string FilePath)
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

// DFBody2DView drawing

void DFBody2DView::OnDraw(CDC* /*pDC*/)
{
    MFCDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // TODO: add draw code for native data here
}

#ifndef BlazesMFCApp_DisablePrinter
// DFBody2DView printing
BOOL DFBody2DView::OnPreparePrinting(CPrintInfo* pInfo)
{
    // default preparation
    return DoPreparePrinting(pInfo);
}

void DFBody2DView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add extra initialization before printing
}

void DFBody2DView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: add cleanup after printing
}
#endif

// DFBody2DView diagnostics

#ifdef _DEBUG
void DFBody2DView::AssertValid() const
{
    MFCView::AssertValid();
}

void DFBody2DView::Dump(CDumpContext& dc) const
{
    MFCView::Dump(dc);
}

MFCDoc* DFBody2DView::GetDocument() const // non-debug version is inline
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(MFCDoc)));
    return (MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// DFBody2DView message handlers
