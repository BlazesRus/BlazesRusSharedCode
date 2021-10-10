// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Code based on https://www.codeproject.com/Articles/9887/CStaticTreeCtrl-A-CStatic-derived-custom-Tree-cont
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#pragma once
#if !defined(CustomTreeViewWAudio_IncludeGuard)
#define CustomTreeViewWAudio_IncludeGuard

#include "CustomTreeView.h"
#include "AudioSupportedContextMenu.h"

/// <summary>
/// Edited derivable version of CustomTreeControl's CViewTreeCtrl class converted into a view
/// <para/>(base code from https://www.codeproject.com/Articles/9887/CViewTreeCtrl-A-CView-derived-custom-Tree-cont)
/// <para/>NodeType/TreeNode refers to derived node's class name (for keeping inherited functionality)
/// </summary>
template <typename TreeNode, typename DocViewType>
class CustomTreeViewWAudio : public CustomTreeView<TreeNode, DocViewType, AudioSupportedContextMenu>
{
    CRuntime_Arg02Base03_Reused01(CustomTreeViewWAudio, TreeNode, DocViewType, CustomTreeView, AudioSupportedContextMenu)
public:
    typedef TreeNode NodeType;


    /// <summary>
    /// Adds new blank node to root.
    /// </summary>
    /// <returns>unsigned _int64</returns>
    virtual unsigned _int64 AddNodeToRoot()
    {
        unsigned _int64 IndexPos = NodeBank.Add(XMLTagViewNode());
        RootLvlNodes.Add(IndexPos);
        NodeType& pNewNode = NodeBank[IndexPos];
        pNewNode.bUseDefaultTextColor = TRUE;
        pNewNode.csLabel = "_";
        return IndexPos;
    }

    virtual void DeleteNode(unsigned __int64 pNode, BOOL bInvalidate = FALSE)
    {/*virtual void DeleteNode(NodeType* pNode, BOOL bInvalidate = FALSE)*/
        DeleteNodeRecursive(pNode);

        // Repaint the control if so desired
        if (bInvalidate)
            Invalidate();
    }

    /*virtual void DeleteNode(NodeType* targetNode, BOOL bInvalidate = FALSE)
    {
        DeleteNodeRecursive(pNode);

        // Repaint the control if so desired
        if (bInvalidate)
            Invalidate();
    }*/

    void ToggleNode(NodeType* pNode, BOOL bInvalidate = FALSE)
    {
        ASSERT(pNode != NULL);

        pNode->bOpen = !(pNode->bOpen);

        if (bInvalidate)
            Invalidate();
    }

    /// <summary>
    /// Recursively delete node and all child nodes from nodeID
    /// </summary>
    /// <param name="pNode">The p node.</param>
    void DeleteNodeRecursive(unsigned __int64 nodeID)
    {
        size_t RootIndex = RootLvlNodes.GetElementIndex(nodeID);
        if (RootIndex != -1) { RootLvlNodes.Remove(RootIndex); }
        UXIntList NodesToDelete;
        unsigned __int64 childID;
        NodesToDelete.Add(nodeID);
        //Delete all child nodes connected(can't delete from within node deconstruction since node has no knowledge of TreeView)
        NodeType* targetNode = this->NodeBank[nodeID];
        size_t childSize = targetNode->ChildNodes.size();
        for(size_t Index= 0; Index< childSize;++Index)
        {
            childID = targetNode->ChildNodes.at(Index);
            NodesToDelete.Add(childID);
            AddAllChildrenToList(NodesToDelete, childID);
        }

        for (size_t Index = 0; Index < NodesToDelete; ++Index)
        {
            NodeBank.Remove(NodesToDelete(Index));
        }
    }

    /// <summary>
    /// Adds all children to list.
    /// </summary>
    /// <param name="nodeList">The node list.</param>
    /// <param name="nodeID">The node identifier.</param>
    void AddAllChildrenToList(UXIntList& nodeList, unsigned __int64 nodeID)
    {
        NodeType* targetNode = this->NodeBank[nodeID];
        size_t childSize = targetNode->ChildNodes.size();
        for (size_t Index = 0; Index < childSize; ++Index)
        {
            AddAllChildrenToList(NodesToDelete, targetNode->ChildNodes.at(Index));
        }
    }

protected:
    int DrawNodesRecursive(CDC* pDC, NodeType* pNode, int x, int y, CRect rFrame)
    {
        int		iDocHeight = 0;		// Total document height
        CRect	rNode;

        // The node's location and dimensions on screen
        rNode.left = x;
        rNode.top = y;
        rNode.right = rFrame.right - m_iPadding;
        rNode.bottom = y + m_iLineHeight;

        pNode->rNode.CopyRect(rNode);		// Record the rectangle

        //Text Color
        COLORREF cr = (pNode->bUseDefaultTextColor) ? m_crDefaultTextColor : pNode->textColor;
        COLORREF crOldText = pDC->SetTextColor(cr);

        // MULTILINE TEXT - begins
        CString	cs = pNode->csLabel;
        int		iPos = 0;

        // Draw text until there is nothing left to draw
        while (cs.GetLength() > 0)
        {
            // Height of a line of text
            rNode.bottom = rNode.top + m_iLineHeight;

            // Find out how much text fits in one line
            iPos = HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, cs);

            // Draw only if the node is visible
            if (rNode.bottom > 0 && rNode.top < rFrame.bottom)
                pDC->DrawText(cs.Left(iPos + 1), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);

            // Eliminate the text that has been already drawn
            cs = cs.Mid(iPos + 1);

            // The node grows every time another line of text is drawn
            pNode->rNode.UnionRect(pNode->rNode, rNode);

            // Move down the drawing rectangle for the next line of text
            rNode.top = rNode.bottom;
        }
        // MULTILINE TEXT - ends

        pDC->SetTextColor(crOldText);

/*		// If there are no child or siblings, then this branch is done
        if (pNode->pChild == NULL && pNode->pSibling == NULL)
            return pNode->rNode.Height();

        // If the node is open AND it has children, then draw those
        if (pNode->bOpen && pNode->pChild != NULL)
            iDocHeight = DrawNodesRecursive(pDC, (NodeType*)pNode->pChild, x + m_iIndent, y + pNode->rNode.Height(), rFrame);

        // If the node has siblings, then draw those
        if (pNode->pSibling != NULL)
            iDocHeight += DrawNodesRecursive(pDC, (NodeType*)pNode->pSibling, x, y + pNode->rNode.Height() + iDocHeight, rFrame);
*/
        size_t childNum = pNode->ChildNodes.size();
        unsigned __int64 childID;
        NodeType* targetNode = nullptr;
        if(pNode->bOpen&&childNum>0)
        {
            for(size_t Index=0;Index<childNum;++Index)
            {
                childID = pNode->ChildNodes.at(Index);
                targetNode = this->NodeBank[childID];
                iDocHeight = DrawNodesRecursive(pDC, targetNode, x + m_iIndent, y + pNode->rNode.Height(), rFrame);
            }
        }

        return iDocHeight + pNode->rNode.Height();
    }
    int HowMuchTextFits(CDC* pDC, int iAvailableWidth, CString csText)
    {
        int iValidSoFar = csText.GetLength() - 1;					// Assume the entire text fits

                                                                    // If the text's pixel width is larger than what's available
        if (pDC->GetTextExtent(csText).cx > iAvailableWidth)
        {
            int iNextBlank = 0;	// Position of the next blank in text
            int iPixelWidth = 0;	// Text's pixel width

                                    // Loop until we can fit no more of the text
            while (iPixelWidth < iAvailableWidth)
            {
                iValidSoFar = iNextBlank;							// Record the char position so far
                iNextBlank = csText.Find(' ', iNextBlank + 1);	// Advance one word at a time

                                                                // Have reached the end of the string?
                if (iNextBlank == -1)
                    iNextBlank = csText.GetLength();

                // Calculate the new width
                iPixelWidth = pDC->GetTextExtent(csText.Left(iNextBlank)).cx;
            }
        }

        return iValidSoFar;
    }

    void DrawLinesRecursive(CDC* pDC, NodeType* pNode)
    {
        // Draw lines from children if the node is open before drawing lines from this node
        //if (pNode->bOpen && pNode->pChild != NULL)
        //	DrawLinesRecursive(pDC, (NodeType*)pNode->pChild);
        size_t childNum = pNode->ChildNodes.size();
        unsigned __int64 ID;
        NodeType* targetNode = nullptr;
        if (childNum > 0)
        {
            for (size_t Index = 0; Index < childNum; ++Index)
            {
                ID = pNode->ChildNodes.at(Index);
                targetNode = this->NodeBank[childID];
                DrawLinesRecursive(pDC, targetNode);
            }
        }

        // Where is the elbow joint of this connecting line?
        int iJointX = pNode->rNode.left - m_iIndent - 6;
        int iJointY = pNode->rNode.top + (m_iLineHeight / 2);

        // If the parent is not the top node, throw a connecting line to it
        ID = pNode->ParentIndex;
        if (ID!= 18446744073709551615)//pNode->pParent != m_pTopNode)
        {
            targetNode = this->NodeBank[ID];
            // How far up from the joint is the parent?
            int iDispY = iJointY - targetNode->rNode.top - (m_iLineHeight / 2);

            // Use 1 pixel wide rectangles to draw lines
            pDC->FillSolidRect(iJointX, iJointY, m_iIndent, 1, m_crConnectingLines);	// Horizontal line
            pDC->FillSolidRect(iJointX, iJointY, 1, -iDispY, m_crConnectingLines);		// Vertical line
        }

        // Put a solid dot to mark a node
        pDC->FillSolidRect(iJointX + m_iIndent - 2, iJointY - 2, 5, 5, m_crConnectingLines);

        // Hollow out the dot if the node has no children
        if (childNum==0)//pNode->pChild == NULL)
            pDC->FillSolidRect(iJointX + m_iIndent - 1, iJointY - 1, 3, 3, RGB(255, 255, 255));

        //// Draw the next sibling if there are any
        //if (pNode->pSibling != NULL)
        //	DrawLinesRecursive(pDC, (NodeType*)pNode->pSibling);
    }

    void ResetScrollBar()
    {
        // Flag to avoid a call from OnSize while resetting the scrollbar
        m_bScrollBarMessage = TRUE;

        CRect rFrame;

        GetClientRect(rFrame);

        // Need for scrollbars?
        if (rFrame.Height() > m_iDocHeight + 8)
        {
            ShowScrollBar(SB_VERT, FALSE);	// Hide it
            SetScrollPos(SB_VERT, 0);
        }
        else
        {
            SCROLLINFO	si;
            si.cbSize = sizeof(SCROLLINFO);
            si.fMask = SIF_PAGE | SIF_RANGE;
            si.nPage = rFrame.Height();
            si.nMax = m_iDocHeight + 8;
            si.nMin = 0;

            SetScrollInfo(SB_VERT, &si);
            EnableScrollBarCtrl(SB_VERT, TRUE);
        }

        m_bScrollBarMessage = FALSE;
    }

    NodeType* FindNodeByPoint(const CPoint& point, NodeType* pNode)
    {
        NodeType* pFound = nullptr;

        // Found it?
        if (pNode->rNode.PtInRect(point))
            pFound = pNode;

        //// If this node isn't it then check the node's children if it is open and there are any
        //if (pFound == NULL && pNode->bOpen && pNode->pChild != NULL)
        //	pFound = FindNodeByPoint(point, (NodeType*)pNode->pChild);
        //// If didn't find it among the node's children, then check the next sibling
        //if (pFound == NULL && pNode->pSibling != NULL)
        //	pFound = FindNodeByPoint(point, (NodeType*)pNode->pSibling);
        size_t tempSize = pNode->ChildNodes.size();
        if (pFound == nullptr && pNode->bOpen && tempSize>0)
        {
            unsigned __int64 ID;
            for (size_t Index = 0; Index < tempSize && pFound == nullptr; ++Index)
            {
                ID = pNode->ChildNodes.at(Index);
                pFound = FindNodeByPoint(point, NodeBank[ID]);
            }
        }

        return pFound;
    }

    NodeType* FindNodeByRootPoint(const CPoint& point)
    {
        size_t tempSize = RootLvlNodes.size();
        unsigned __int64 ID;
        if(tempSize==0)
        {
            return nullptr;
        }
        else
        {
            NodeType* pFound = nullptr;

            // Found it?
            if (pNode->rNode.PtInRect(point))
                pFound = pNode;
            for (size_t Index = 0; Index < tempSize && pFound == nullptr; ++Index)//if(m_pTopNode->pChild != NULL)
            {
                ID = RootLvlNodes[Index];
                pFound = FindNodeByPoint(point, NodeBank[ID]);
            }
        }

        return pFound;
    }

    /*NodeType* FindNodeByID(const CPoint& point, unsigned __int64 NodeId)
    {
        NodeType* pFound = nullptr;

    }*/

    BOOL NodeTextDlg(CString& csText)
    {
        BOOL				bRet = FALSE;
        CDLG_TreeNodeText	tntDlg;

        tntDlg.m_csItemText = csText;

        if (tntDlg.DoModal() == IDOK)
        {
            csText = tntDlg.m_csItemText;
            bRet = TRUE;
        }

        return bRet;
    }

    // Message handlers
    void OnCM_InsertChild()
    {
        CString csText("");

        if (NodeTextDlg(csText) == TRUE)
        {
            if (m_pSelected == NULL)
                InsertChild(m_pTopNode, csText);
            else
            {
                InsertChild(m_pSelected, csText);
                m_pSelected = NULL;
            }

            Invalidate();
        }
    }
    void OnCM_InsertSibling()
    {
        CString csText("");

        if (NodeTextDlg(csText) == TRUE)
        {
            InsertSibling(m_pSelected, csText);
            m_pSelected = NULL;
            Invalidate();
        }
    }
    void OnCM_DeleteNode()
    {
        DeleteNode(m_pSelected, TRUE);

        m_pSelected = NULL;
    }
    void OnCM_ModifyNodeText()
    {
        if (NodeTextDlg(m_pSelected->csLabel) == TRUE)
        {
            m_pSelected = NULL;
            Invalidate();
        }
    }
    void OnCM_ChangeNodeColor()
    {
        COLORREF cr = (m_pSelected->bUseDefaultTextColor) ? m_crDefaultTextColor : m_pSelected->textColor;

        CColorDialog ccd(cr, CC_FULLOPEN | CC_ANYCOLOR);

        if (ccd.DoModal() == IDOK)
            SetNodeColor(m_pSelected, ccd.GetColor(), TRUE);

        m_pSelected = NULL;
    }
    void OnCM_ToggleConnectingLines()
    {
        m_bShowLines = !m_bShowLines;

        Invalidate();
    }
    void OnCM_SetConnectingLinesColor()
    {
        CColorDialog ccd(m_crConnectingLines, CC_FULLOPEN | CC_ANYCOLOR);

        if (ccd.DoModal() == IDOK)
        {
            m_crConnectingLines = ccd.GetColor();
            Invalidate();
        }
    }
    void OnCM_SetFont()
    {
        CFontDialog cfd(&m_lgFont, CF_SCREENFONTS | CF_INITTOLOGFONTSTRUCT);

        if (cfd.DoModal() == IDOK)
        {
            SetTextFont(cfd.GetSize() / 10, cfd.IsBold(), cfd.IsItalic(), cfd.GetFaceName());
            Invalidate();
        }
    }
    void OnCM_SetDefaultColor()
    {
        CColorDialog ccd(m_crDefaultTextColor, CC_FULLOPEN | CC_ANYCOLOR);

        if (ccd.DoModal() == IDOK)
        {
            m_crDefaultTextColor = ccd.GetColor();
            Invalidate();
        }
    }
    void OnCM_SetBackgroundBitmap()
    {
        SetBackgroundBitmap(TRUE);
    }
public:
    CustomTreeViewWAudio()
    {
        m_iIndent = 16;				// Indentation for tree branches
        m_iPadding = 4;				// Padding between tree and the control border

        m_bShowLines = TRUE;				// Show lines by default
        m_bScrollBarMessage = FALSE;			// Only relevant when calculating the scrollbar

        m_iDocHeight = 0;				// A polite yet meaningless default

        m_crDefaultTextColor = RGB(58, 58, 58);	// Some default
        m_crConnectingLines = RGB(128, 128, 128);	// Some default

        // Safeguards
        SetTextFont(8, FALSE, FALSE, "Arial Unicode MS");
        m_pSelected = nullptr;
        ViewName = "TreeView";
    }
    virtual ~CustomTreeViewWAudio()
    {
        //DeleteNode(m_pTopNode);	// Delete all children if there are any
        //delete m_pTopNode;			// Delete top node
        //m_pTopNode = NULL;
        NodeBank.clear();
        RootLvlNodes.clear();

        m_Font.DeleteObject();

        if (m_bmpBackground.GetSafeHandle() != NULL)
            m_bmpBackground.DeleteObject();
    }
    /// <summary>
    /// Loads the data from file.
    /// </summary>
    /// <param name="FilePath">The file path.</param>
    /// <returns>bool</returns>
    virtual bool LoadDataFromFile(std::string FilePath)
    {//Only load tags without argument fields etc for basic non-derived version
        char LineChar;
        bool InsideXMLComment = false;
        bool InsideTag = false;
        std::string ScanBuffer = "";
        //std::string ContentBuffer = "";
        StringVectorList TagDepth;
        std::string CurrentTag = "";
        unsigned _int64 CurrentTagIndex = EmptyNode;
        std::string NextTag = "";
        IniDataV2 AdditionTagOptions;
        //         signed int CommandStage = 0;
        //         //------------------------------------------------------------------------------------

         //0=NormalTag; 1:SelfContainedTag; 2:TagIsClosing; 3:XMLVersionTag
        int TagType = 0;
        //bool ArgHasNoValue = false;
        bool PotentialComment = false;
        bool InsideParenthesis = false;
        //bool TagNameHasArg02 = false;
        //std::string TagNameArg02 = "";
        size_t SizeBuffer;

        ifstream inFile;
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
                SizeBuffer = ScanBuffer.size();
                if (SizeBuffer == 0)
                {
                    if (LineChar == '-')
                    {
                        ScanBuffer = "-";
                    }
                }
                else if (SizeBuffer == 1)
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
            else if (InsideTag)
            {
                if (LineChar == '>')
                {
                    unsigned _int64 IndexPos;
                    InsideTag = false;
                    //Add NextTag into tree
                    if (TagType == 1)
                    {
                        IndexPos = AddNode(NextTag, 1, CurrentTagIndex);
                    }
                    else if (TagType == 2)
                    {
                        if (NextTag == CurrentTag)//Normal Exiting of Previous Tag
                        {
                            TagDepth.Remove(TagDepth.size() - 1);//Remove last tag from depth
                        }
                        else//Rare exiting of non-previous tag
                        {
                            //Write code for this later(not as important)
                        }
                        //Add TagContent Buffer into Node
                    }
                    else
                    {
                        IndexPos = AddNode(NextTag, 0, CurrentTagIndex);
                        CurrentTag = NextTag;
                        CurrentTagIndex = IndexPos;
                        TagDepth.Add(CurrentTag);
                    }
                    //Clear Buffers after adding Tag to tree
                    NextTag = ""; ScanBuffer = ""; TagType = 0;
                }
                else if (NextTag.empty())
                {
                    if (ScanBuffer.empty())
                    {
                        if (LineChar == '/')//Detected Closing Tag
                        {
                            TagType = 2;
                        }
                        else if (LineChar == '?'&&TagType == 0)
                        {
                            TagType = 3;
                        }
                        else if (LineChar == ' ' || LineChar == '\t' || LineChar == '\n')
                        {
                            if (!ScanBuffer.empty())//End Tag on whitespace if buffer not empty
                            {
                                NextTag = ScanBuffer;
                                ScanBuffer = "";
                            }
                        }
                        else if (LineChar == '!')
                        {
                            PotentialComment = true;
                        }
                        else
                        {
                            ScanBuffer += LineChar;
                        }
                    }
                    else
                    {
                        if (LineChar == '?'&&TagType == 0)
                        {
                            TagType = 3;
                        }
                        else if (LineChar == ' ' || LineChar == '\t' || LineChar == '\n')
                        {
                            if (!ScanBuffer.empty())//End Tag on whitespace if buffer not empty
                            {
                                NextTag = ScanBuffer;
                                ScanBuffer = "";
                            }
                        }
                        else
                        {
                            ScanBuffer += LineChar;
                        }
                    }
                }
                else
                {
                    if (LineChar == '/')//Detected Self-Contained Tag
                    {
                        TagType = 1;
                    }
                    else//Get Tag arguments etc here
                    {
                    }
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
                    if (!CurrentTag.empty())//Get TagContent here
                    {
                        //		CurrentNode->TagContent += LineChar;
                    }
                }
            }
        }
        return true;
    }
public:
    DocViewType* GetDocument()
    {
        return (DocViewType*)m_pDocument;
    }

    // Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CustomTreeViewWAudio)
protected:
    virtual void OnDraw(CDC* pDC)
    {
        DocViewType* pDoc = GetDocument();
        pDC->TextOut(400, 300, ViewName);
        pDC->TextOut(400, 320, pDoc->m_str);

        CPaintDC dc(this); // Device context for painting
    // Double-buffering
        CDC*		pDCMem = new CDC;
        CBitmap*	pOldBitmap = NULL;
        CBitmap		bmpCanvas;
        CRect		rFrame;

        GetClientRect(rFrame);

        pDCMem->CreateCompatibleDC(&dc);

        bmpCanvas.CreateCompatibleBitmap(&dc, rFrame.Width(), rFrame.Height());

        pOldBitmap = pDCMem->SelectObject(&bmpCanvas);

        // START DRAW -------------------------------------------------

        // If there is a bitmap loaded, use it
        // Otherwise, paint the background white
        if (m_bmpBackground.GetSafeHandle() != NULL)
        {
            CDC*	pDCTemp = new CDC;;
            BITMAP	bmp;

            pDCTemp->CreateCompatibleDC(&dc);

            m_bmpBackground.GetBitmap(&bmp);

            // Select the bitmap into the temp device context
            CBitmap* pOldBitmap = (CBitmap*)pDCTemp->SelectObject(&m_bmpBackground);

            // Stretch the bitmap to fill the entire control area
            pDCMem->StretchBlt(0, 0, rFrame.Width(), rFrame.Height(), pDCTemp, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

            pDCTemp->SelectObject(pOldBitmap);

            delete pDCTemp;
        }
        else
            pDCMem->FillSolidRect(rFrame, RGB(255, 255, 255));

        UINT	nMode = pDCMem->SetBkMode(TRANSPARENT);
        CFont*	pOldFont = pDCMem->SelectObject(&m_Font);

        int iLastNodePos = 0;

        size_t tempSize = RootLvlNodes.size();
        unsigned __int64 ID;

/*
            iLastNodePos = DrawNodesRecursive(pDCMem, (NodeType*)m_pTopNode->pChild,
                rFrame.left + m_iIndent,
                m_iPadding - GetScrollPos(SB_VERT),
                rFrame);

            if (m_bShowLines)
                DrawLinesRecursive(pDCMem, (NodeType*)m_pTopNode->pChild);
*/
        for (size_t Index = 0; Index < tempSize; ++Index)//if(m_pTopNode->pChild != NULL)
        {
            ID = RootLvlNodes[Index];
            iLastNodePos = DrawNodesRecursive(pDCMem, NodeBank[ID], rFrame.left + m_iIndent, m_iPadding - GetScrollPos(SB_VERT), rFrame);

            if (m_bShowLines)
                DrawLinesRecursive(pDCMem, NodeBank[ID]);
        }

        pDCMem->SelectObject(pOldFont);
        pDCMem->SetBkMode(nMode);

        pDCMem->Draw3dRect(rFrame, RGB(0, 0, 0), RGB(0, 0, 0));	// Border

                                                                // END DRAW   -------------------------------------------------

        dc.BitBlt(0, 0, rFrame.Width(), rFrame.Height(), pDCMem, 0, 0, SRCCOPY);

        pDCMem->SelectObject(pOldBitmap);

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
    afx_msg void OnSize(UINT nType, int cx, int cy)
    {
        // Setting the scroll sends its own size message. Prevent it thus avoiding an ugly loop.
        // Other than that, resizing the control means that the tree height may change (word-wrap).
        if (!m_bScrollBarMessage)
            ResetScrollBar();

        CView::OnSize(nType, cx, cy);
    }
    afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
    {
        int iScrollBarPos = GetScrollPos(SB_VERT);

        CRect rFrame;

        GetClientRect(rFrame);

        switch (nSBCode)
        {
        case SB_LINEUP:
            iScrollBarPos = max(iScrollBarPos - m_iLineHeight, 0);
            break;

        case SB_LINEDOWN:
            iScrollBarPos = min(iScrollBarPos + m_iLineHeight, GetScrollLimit(SB_VERT));
            break;

        case SB_PAGEUP:
            iScrollBarPos = max(iScrollBarPos - rFrame.Height(), 0);
            break;

        case SB_PAGEDOWN:
            iScrollBarPos = min(iScrollBarPos + rFrame.Height(), GetScrollLimit(SB_VERT));
            break;

        case SB_THUMBTRACK:
        case SB_THUMBPOSITION:
        {
            SCROLLINFO si;

            ZeroMemory(&si, sizeof(SCROLLINFO));

            si.cbSize = sizeof(SCROLLINFO);
            si.fMask = SIF_TRACKPOS;

            if (GetScrollInfo(SB_VERT, &si, SIF_TRACKPOS))
                iScrollBarPos = si.nTrackPos;
            else
                iScrollBarPos = (UINT)nPos;
            break;
        }
        }

        SetScrollPos(SB_VERT, iScrollBarPos);

        Invalidate();

        CWnd::OnVScroll(nSBCode, nPos, pScrollBar);
    }
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point)
    {
        NodeType* pClickedOn = nullptr;		// Assume no node was clicked on

        //if (m_pTopNode->pChild != NULL)		// If the tree is populated, search it
        //	pClickedOn = FindNodeByPoint(point, (NodeType*)m_pTopNode->pChild);
        pClickedOn = FindNodeByRootPoint(point);

        if (pClickedOn != NULL)			// If a node was clicked on
            ToggleNode(pClickedOn, TRUE);
        else
            CView::OnLButtonUp(nFlags, point);
    }
    afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
    {
        // zDelta greater than 0, means rotating away from the user, that is, scrolling up
        OnVScroll((zDelta > 0) ? SB_LINEUP : SB_LINEDOWN, 0, NULL);

        return CView::OnMouseWheel(nFlags, zDelta, pt);
    }

protected:
    /// <summary>
    /// Applies the menu generation.
    /// </summary>
    /// <param name="ccmPopUp">The CCM pop up.</param>
    /// <param name="nFlag">The n flag.</param>
    /// <param name="pDC">The p dc.</param>
    virtual void ApplyMenuGen(ContextMenuType* ccmPopUp, UINT nFlag, CDC* pDC)
    {
        // Node related items
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_INSERTCHILD, _T("Insert Child"), _T("insertChild.wav"), pDC);
        ccmPopUp.AppendMenuItem(nFlag, CM_INSERTSIBLING, _T("Insert Sibling"), _T("insertSibling.wav"), pDC);
        ccmPopUp.AppendMenuItem(nFlag, CM_DELETENODE, _T("Delete Node"), _T("deleteNode.wav"), pDC);
        ccmPopUp.AppendMenuItem(nFlag, CM_MODIFYNODETEXT, _T("Modify Node Text"), _T("modifyNodeText.wav"), pDC);
        ccmPopUp.AppendMenuItem(nFlag, CM_CHANGENODECOLOR, _T("Change Node Color"), _T("changeNodeColor.wav"), pDC);

        ccmPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), _T(""), pDC);

        // Connecting lines related items
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_TOGGLECONNECTINGLINES, _T("Toggle Connecting Lines"), _T("toggleConnectingLines.wav"), pDC);
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_SETCONNECTINGLINESCOLOR, _T("Set Connecting Lines Color"), _T("setConnectingLinesColor.wav"), pDC);

        ccmPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), _T(""), pDC);

        // Tree appearance items
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_SETFONT, _T("Set Font"), _T("setFont.wav"), pDC);
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_SETDEFAULTCOLOR, _T("Set Default Text Color"), _T("setDefaultColor.wav"), pDC);
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_SETBACKGROUNDBITMAP, _T("Set Background Bitmap"), _T("setBackgroundBitmap.wav"), pDC);

        ccmPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), _T(""), pDC);

        // Context menu sound toggle item
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_TOGGLEMENUSOUND, _T("Toggle Menu Sound"), _T("toggleMenuSound.wav"), pDC);
    }

    /// <summary>
    /// Called when [context menu].
    /// </summary>
    /// <param name="pWnd">The p WND.</param>
    /// <param name="point">The point.</param>
    afx_msg void OnContextMenu(CWnd* pWnd, CPoint point)
    {
        CPoint cp(point);

        // WM_CONTEXTMENU passes absolute coordinates, we need them local
        ScreenToClient(&cp);

        // Find the node that has been clicked on
        m_pSelected = FindNodeByRootPoint(cp);

        ContextMenuType ccmPopUp;

        ccmPopUp.CreatePopupMenu();

        // Customize the menu appearance and behavior
        ccmPopUp.ToggleSound(m_bAudioOn)
        .SetTextFont(&m_Font)
        .SetColors(RGB(70, 36, 36), RGB(253, 249, 249), RGB(172, 96, 96), RGB(244, 234, 234), RGB(182, 109, 109));

        // Get a device context so that it'll be possible for the context menu
        // to calculate the size of the menu item's text
        CDC		*pDC = GetDC();
        int		iSaved = pDC->SaveDC();
        CFont*	pOldFont = pDC->SelectObject(&m_Font);

        // ADDING MENU ITEMS - Start

        // If a node has been clicked on, use the first 45 chars of its text as the
        // first menu item (always disabled)
        if (m_pSelected != NULL)
        {
            CString	csDots = (m_pSelected->csLabel.GetLength() > 45) ? _T("...") : _T("");
            CString cs = m_pSelected->csLabel.Left(45) + csDots;
            ccmPopUp.AppendMenuItem(MF_DISABLED, WM_APP, cs, _T(""), pDC);
            ccmPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), _T(""), pDC);
        }

        UINT nFlag = (m_pSelected != NULL) ? MF_ENABLED : MF_GRAYED;

        ApplyMenuGen(&ccmPopUp, nFlag, pDC);
        // ADDING MENU ITEMS - End

        // Display the context menu
        ccmPopUp.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

        // Clean up
        pDC->SelectObject(pOldFont);
        pDC->RestoreDC(iSaved);
        ReleaseDC(pDC);
    }
    //}}AFX_VIRTUAL

// Implementation
protected:
#ifdef _DEBUG

    virtual void AssertValid() const
    {
        CView::AssertValid();
    }
    virtual void Dump(CDumpContext& dc) const
    {
        CView::Dump(dc);
    }
#endif
protected:
    /// <summary>
    /// Gets this message map.
    /// </summary>
    /// <returns>const AFX_MSGMAP *.</returns>
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()
    {
        __pragma(warning(push))
            __pragma(warning(disable: 4640))
            static const AFX_MSGMAP_ENTRY _messageEntries[] =
        {
            ON_WM_PAINT()
            ON_WM_SIZE()
            ON_WM_VSCROLL()
            ON_WM_LBUTTONUP()
            ON_WM_MOUSEWHEEL()
            ON_WM_CONTEXTMENU()
            ON_COMMAND(CM_INSERTCHILD, &OnCM_InsertChild)
            ON_COMMAND(CM_INSERTSIBLING, &OnCM_InsertSibling)
            ON_COMMAND(CM_DELETENODE, &OnCM_DeleteNode)
            ON_COMMAND(CM_MODIFYNODETEXT, &OnCM_ModifyNodeText)
            ON_COMMAND(CM_CHANGENODECOLOR, &OnCM_ChangeNodeColor)
            ON_COMMAND(CM_TOGGLECONNECTINGLINES, &OnCM_ToggleConnectingLines)
            ON_COMMAND(CM_SETCONNECTINGLINESCOLOR, &OnCM_SetConnectingLinesColor)
            ON_COMMAND(CM_SETFONT, &OnCM_SetFont)
            ON_COMMAND(CM_SETDEFAULTCOLOR, &OnCM_SetDefaultColor)
            ON_COMMAND(CM_SETBACKGROUNDBITMAP, &OnCM_SetBackgroundBitmap)
            {
 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0
}
        };
        __pragma(warning(pop))
            /// <summary>
            /// The message map
            /// </summary>
            static const AFX_MSGMAP messageMap =
        { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };
        return &messageMap;
    }
public:
    virtual const AFX_MSGMAP* GetMessageMap() const
    {
        return GetThisMessageMap();
    }
};

CRuntimeImplimentation_Arg02(CustomTreeViewWAudio, TreeNode, DocViewType)

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
