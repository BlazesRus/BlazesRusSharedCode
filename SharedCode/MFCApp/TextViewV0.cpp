#include "StdBhvTree.h"
#include "TreeView.h"
#include "VariableLists/StringVectorList.h"
#include "TagDepthTree.h"

IMPLEMENT_DYNCREATE(TreeView, CView)


/// <summary>
/// Loads the data from file.
/// </summary>
/// <param name="FilePath">The file path.</param>
/// <returns>bool</returns>
inline bool TreeView::LoadDataFromFile(std::string FilePath)
{
    Reset();
    char LineChar;
    bool InsideXMLComment = false;
    //If false, then inside tagcontent types instead of tags
    bool InsideTag = false;
    std::string ScanBuffer = "";

    //First name inside tag becomes CurrentTag
    std::string CurrentTag = "";
    std::string CurrentNodeName = "";
    unsigned int CurrentNodeIndex = 0;
    //0=NormalTag; 1:SelfContainedTag; 2:TagIsClosing; 3:XMLVersionTag
    int TagType = 0;

    bool ScanningArgData = false;
    std::string ArgElement;
    ArgStringList LastArg;
    ArgList ArgBuffer;

    bool PotentialComment = false;
    bool InsideParenthesis = false;
    bool InsideClassNodeSection = false;
    //0 = Not Scanning TagContent Yet: 1 = Potential SingleLine TagContent: 2 Multi-line target content
    short TagContentStage = 0;

    //Current state of code loading for certain sections of code
    size_t Stage = 0;

    //Index of hkobject class node
    unsigned int CurrentClassNodeIndex = 0;
    //Index of last entered node
    unsigned int CurrentNodeIndex = 0;
    TagDepthTree TagDepth;
    std::string HkClassType = "";

    //std::string CurrentNodeName = "";


    unsigned ClassNodeIndex = 0;
    //class parameter of hkobject

    //BhvTreeViewNode* TargetNode = nullptr;
    const std::string hkobject = "hkobject";
    const std::string Signature = "Signature";

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
            Stage = ScanBuffer.size();
            if (Stage == 0)
            {
                if (LineChar == '-')
                {
                    ScanBuffer = "-";
                }
            }
            else if (Stage == 1)
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
            if (Stage == 0)
            {
                if (LineChar == '=')
                {
                    Stage = 1;
                    //CurrentArgName = ScanBuffer;//Don't need to store in separate variable since ScanBuffer not going to be changed until exit scanning argument data
                    ArgElement = "";
                }
                else if (LineChar != ' ' && LineChar != '\t' && LineChar != '\n')//Skip Whitespace
                {
                    ScanBuffer += LineChar;
                }
            }
            else if (Stage == 1)
            {
                if (LineChar == '\"')
                {
                    Stage = 2;
                }
            }
            else if (Stage == 2)
            {
                if (LineChar == '\"') { Stage = 3; }
            }
            else if (Stage == 3)
            {
                if (LineChar == ',')
                {
                    LastArg.Add(ArgElement);
                }
                else if (LineChar == '\"')
                {
                    ArgBuffer.Add(ScanBuffer, LastArg);
                    ScanningArgData = false;
                }
                else
                {
                    ArgElement += LineChar;
                }
            }
        }
        else
        {
            if (InsideTag)
            {
                if (ScanBuffer == "/" && LineChar == '>')
                {
                    switch (TagType)
                    {
                    default://TagIsClosing(TagType==2)
                            //Decrease TagDepth
                        TagDepth.RemoveLastTagMatch(CurrentTag);
                        break;
                    case 1://SelfContainedTag
                        NodeBank.Add(CurrentTag, ArgBuffer, CurrentNodeIndex);
                        break;
                    case 3://XMLVersionTag(Same as SelfContained Tag except for ? in front and such)
                        break;
                    }
                    CurrentTag = "";//Reset it to clear buffer so next tag has fresh storage
                    InsideTag = false; TagContentStage = 0;
                }
                else if (LineChar == '>')
                {
                    //(TagType==0)
                    CurrentNodeIndex = NodeBank.Add(CurrentTag, ArgBuffer, CurrentNodeIndex);//Index of Last Entered Node is it's parent
                    if (InsideClassNodeSection && CurrentClassNodeIndex == 0 && CurrentTag == hkobject && ArgBuffer.HasKey(Signature))
                    {
                        CurrentClassNodeIndex = CurrentNodeIndex;
                        CurrentNodeName = ArgBuffer["Name"][0];
                        NodeLinks.Add(CurrentNodeName, CurrentClassNodeIndex);
                    }
                    //Increase TagDepth
                    CurrentNodeName = CurrentTag;
                    CurrentTag = "";//Reset it to clear buffer so next tag has fresh storage
                    InsideTag = false; TagContentStage = 0;

                }
                else if (CurrentTag.empty())
                {
                    if (!ScanBuffer.empty())
                    {
                        if (LineChar == '!')//Detecting potential Commented Out Parts
                        {
                            PotentialComment = true;
                        }
                        else if (LineChar == ' ' || LineChar == '/t')
                        {
                            CurrentTag = ScanBuffer;
                        }
                        else
                        {
                            ScanBuffer += LineChar;
                        }
                    }
                    else if (LineChar != ' ' && LineChar != '	' && LineChar != '\n')
                    {
                        ScanBuffer += LineChar;
                        if (LineChar != '\\')
                        {
                            ScanningArgData = true; Stage = 0;
                        }
                    }
                }
                else if (TagContentStage > 0)
                {

                }
                else
                {
                    if (LineChar == '<')
                    {
                        InsideTag = true;
                    }
                    else if (LineChar != ' ' && LineChar != '	' && LineChar != '\n')
                    {
                        ScanBuffer = LineChar;
                        TagContentStage = 1;
                    }
                }
            }
        }
    }
    return true;
}

void TreeView::OnDraw(CDC* pDC)
{
    MultiViewDoc* pDoc = GetDocument();
   ASSERT_VALID(pDoc);
   if (!pDoc)
      return;
    CPaintDC dc(this); // Device context for painting

                       // Double-buffering
    CDC*		pDCMem = new CDC;
    CRect		rFrame;

    GetClientRect(rFrame);

    pDCMem->CreateCompatibleDC(&dc);

    // START DRAW -------------------------------------------------
    pDCMem->FillSolidRect(rFrame, RGB(255, 255, 255));

    UINT	nMode = pDCMem->SetBkMode(TRANSPARENT);
    CFont*	pOldFont = pDCMem->SelectObject(&m_Font);

    int iLastNodePos = 0;
    
    iLastNodePos = DrawNodesFromRoot(pDCMem,  rFrame.left + m_iIndent, m_iPadding - GetScrollPos(SB_VERT), rFrame);
    if (m_bShowLines)
        DrawLinesFromRoot(pDCMem);

    pDCMem->SelectObject(pOldFont);
    pDCMem->SetBkMode(nMode);

    pDCMem->Draw3dRect(rFrame, RGB(0, 0, 0), RGB(0, 0, 0));	// Border

                                                            // END DRAW   -------------------------------------------------

    dc.BitBlt(0, 0, rFrame.Width(), rFrame.Height(), pDCMem, 0, 0, SRCCOPY);

    delete pDCMem;

    // Has the total document height changed?
    if (iLastNodePos != m_iDocHeight)
    {
        BOOL bInvalidate = ((m_iDocHeight < rFrame.Height()) != (iLastNodePos < rFrame.Height()));

        m_iDocHeight = iLastNodePos;

        ResetScrollBar();

        // If the scrollbar has just been hidden/shown, repaint
        if (bInvalidate)
            Invalidate();
    }
}


#ifdef _DEBUG
void TreeView::AssertValid() const
{
    CView::AssertValid();
}

void TreeView::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}
#endif //_DEBUG