// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Tree Code based on https://www.codeproject.com/Articles/9887/CStaticTreeCtrl-A-CStatic-derived-custom-Tree-cont
// ***********************************************************************
#pragma once
#ifndef TextView_Header
#define TextView_Header

#include <string>
#include <typeinfo>
#include <iostream>
#include <fstream>

#include "MFCView.h"

#include "ContextMenu.h"
#include "TreeNodeText.h"
#include "..\Databases\UIntDic.h"
#include "..\VariableLists\StringVectorList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/// <summary>
/// View for displaying text in a file
/// </summary>
/// <seealso cref="MFCView" />
class TextView : public MFCView
{//Gutted out and reworked varient of TreeView file from BhvEditor tool that was working on)
public:
	//Name of File(if blank then not saved/loaded yet into view)
	std::string FileName="";
	StringVectorList 
private:
    DECLARE_DYNCREATE(TextView)
    void CreateFileIfDoesntExist()
    {
		if(FileName=="")
		{
			std::cout << "Filename not set yet!" << std::endl;
		}
		else
		{
			bool FileExists = false;
			//Based on https://www.quora.com/What-is-the-best-way-to-check-whether-a-particular-file-exists-or-not-in-C++
			struct stat buffer;
			FileExists = (stat(FileName.c_str(), &buffer) == 0);
			//Based on http://stackoverflow.com/questions/17818099/how-to-check-if-a-file-exists-before-creating-a-new-file
			if(!FileExists)
			{
				std::ofstream file(FileName);
				if(!file)
				{
					std::cout << "File could not be created" << std::endl;
					return;
				}
			}
		}
    }
public:// Construction
    /// <summary>
    /// Initializes a new instance of: the <see cref="TextView"/> class.
    /// </summary>
    TextView()
    {
        m_iIndent = 16;				// Indentation for tree branches
        m_iPadding = 4;				// Padding between tree and the control border

        m_bShowLines = TRUE;				// Show lines by default
        m_bScrollBarMessage = FALSE;			// Only relevant when calculating the scrollbar

        m_iDocHeight = 0;				// A polite yet meaningless default

        m_crDefaultTextColor = RGB(58, 58, 58);

        // Safeguards
        SetTextFont(8, FALSE, FALSE, "Arial Unicode MS");
		TextMenu.CreatePopupMenu();
		contextMenuPopUp.AppendMenuItem(MF_DISABLED, WM_APP, cs, pDC);
        contextMenuPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), pDC);
    }

    /// <summary>
    /// Finalizes an instance of the <see cref="TextView"/> class.
    /// </summary>
    virtual ~TextView()
    {
        Reset();
        m_Font.DeleteObject();
    }

    //MultiViewDoc* GetDocument() {return (MultiViewDoc*)m_pDocument; }

    // Attributes
protected:
    LOGFONT			m_lgFont;
    CFont			m_Font;
    COLORREF		m_crDefaultTextColor;
    COLORREF		m_TagContentColor = RGB(40, 40, 160);
    COLORREF		m_crConnectingLines;
    const COLORREF	m_ArgColor = RGB(202, 201, 201);//(Lighter Shade of Sonic Silver) https://www.schemecolor.com/sample?getcolor=7a7978

    BOOL			m_bShowLines;

    int				m_iDocHeight;
    BOOL			m_bScrollBarMessage;

    int				m_iLineHeight;
    int				m_iIndent;
    int				m_iPadding;
	ContextMenu TextMenu(&m_Font);

//-------File Loading Operations-------------------------------------------------------

    /// <summary>
    /// Loads the data from file.
    /// </summary>
    /// <param name="FilePath">The file path.</param>
    /// <returns>bool</returns>
    bool LoadDataFromFile(std::string FilePath);

    /// <summary>
    /// Saves the loaded data to file. (if / or \ is last character, will instead create/replace BhvFile.xml)
    /// </summary>
    /// <param name="FilePath">The file path. or file name </param>
    void SaveDataToFile(std::string FilePath)
    {
        if (FilePath.back() == '/' || FilePath.back() == '\\'){ FilePath += "BhvFile.xml"; }
        size_t StringLength;
        char StringChar;
        std::string LineString;
        std::fstream LoadedFileStream;
        //Fix for non-existing file
        CreateFileIfDoesntExist(FilePath);
        LoadedFileStream.open(FilePath.c_str(), std::fstream::out | std::fstream::trunc);
        if(LoadedFileStream.is_open())
        {
            if(LoadedFileStream.good())
            {//Saving to file now
			    for(ContentList::iterator ArgElement = ContentList.begin(), EndElement = ContentList.end(); ArgElement != EndElement; ++ArgElement)
                {
					LoadedFileStream << ArgElement << "\n";
				}
            }
            else
            {
                if(LoadedFileStream.bad()) { std::cout << "Failed Read/Write operation Error!\n"; }
                else if(LoadedFileStream.fail()) { std::cout << "Failed format based Error!\n"; }
                else if(LoadedFileStream.bad()) { std::cout << "Failed Read/Write operation Error!\n"; }
                else if(LoadedFileStream.eof()) {/*Send debug message of reaching end of file?*/ }
            }
            LoadedFileStream.close();
        }
        else
        {
            std::cout << "Failed to open " << FilePath << ".\n";
        }
    }
//--------------------------------------------------------------------------------------

    /// <summary>
    /// Resets the storage of this instance.
    /// </summary>
    void Reset()
    {
        ContentList.clear();
    }

    // Operations
public:
    /// <summary>
    /// Sets the text font.
    /// </summary>
    /// <param name="nHeight">Height of the n.</param>
    /// <param name="bBold">If true, is set as bold.</param>
    /// <param name="bItalic">If true, is set as italic.</param>
    /// <param name="csFaceName">Name of the font applied</param>
    virtual void SetTextFont(LONG nHeight, BOOL bBold, BOOL bItalic, const CString& csFaceName)
    {
        m_lgFont.lfHeight = -MulDiv(nHeight, GetDeviceCaps(GetDC()->m_hDC, LOGPIXELSY), 72);
        m_lgFont.lfWidth = 0;
        m_lgFont.lfEscapement = 0;
        m_lgFont.lfOrientation = 0;
        m_lgFont.lfWeight = (bBold) ? FW_BOLD : FW_DONTCARE;
        m_lgFont.lfItalic = (BYTE)((bItalic) ? TRUE : FALSE);
        m_lgFont.lfUnderline = FALSE;
        m_lgFont.lfStrikeOut = FALSE;
        m_lgFont.lfCharSet = DEFAULT_CHARSET;
        m_lgFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
        m_lgFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
        m_lgFont.lfQuality = DEFAULT_QUALITY;
        m_lgFont.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;

        STRCPY(m_lgFont.lfFaceName, csFaceName);

        if (m_Font.GetSafeHandle() != NULL)
            m_Font.DeleteObject();

        m_Font.CreateFontIndirect(&m_lgFont);

        // Calculate node height for this font
        CDC* pDC = GetDC();
        int		iSaved = pDC->SaveDC();
        CFont* pOldFont = pDC->SelectObject(&m_Font);

        // Calculate the height of this font with a character likely to be 'big'
        // and don't forget to add a little padding
        m_iLineHeight = pDC->GetTextExtent("X").cy + 4;

        pDC->SelectObject(pOldFont);
        pDC->RestoreDC(iSaved);
        ReleaseDC(pDC);
    }
    /// <summary>
    /// Sets the default color of the text.
    /// </summary>
    /// <param name="crText">The text color to set to.</param>
    virtual void SetDefaultTextColor(COLORREF textColor)
    {
        m_crDefaultTextColor = textColor;
    }

    /// <summary>
    /// Sets the text settings.
    /// </summary>
    /// <param name="nHeight">Height of the n.</param>
    /// <param name="bBold">If true, is set as bold.</param>
    /// <param name="bItalic">If true, is set as italic.</param>
    /// <param name="csFaceName">Name of the font face.</param>
    /// <param name="textColor">The color of the text</param>
    virtual void SetTextSettings(LONG nHeight, BOOL bBold, BOOL bItalic, const CString& csFaceName, COLORREF textColor)
    {
        m_lgFont.lfHeight = -MulDiv(nHeight, GetDeviceCaps(GetDC()->m_hDC, LOGPIXELSY), 72);
        m_lgFont.lfWidth = 0;
        m_lgFont.lfEscapement = 0;
        m_lgFont.lfOrientation = 0;
        m_lgFont.lfWeight = (bBold) ? FW_BOLD : FW_DONTCARE;
        m_lgFont.lfItalic = (BYTE)((bItalic) ? TRUE : FALSE);
        m_lgFont.lfUnderline = FALSE;
        m_lgFont.lfStrikeOut = FALSE;
        m_lgFont.lfCharSet = DEFAULT_CHARSET;
        m_lgFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
        m_lgFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
        m_lgFont.lfQuality = DEFAULT_QUALITY;
        m_lgFont.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;

        STRCPY(m_lgFont.lfFaceName, csFaceName);

        if (m_Font.GetSafeHandle() != NULL)
            m_Font.DeleteObject();

        m_Font.CreateFontIndirect(&m_lgFont);

        // Calculate node height for this font
        CDC* pDC = GetDC();
        int		iSaved = pDC->SaveDC();
        CFont* pOldFont = pDC->SelectObject(&m_Font);

        // Calculate the height of this font with a character likely to be 'big'
        // and don't forget to add a little padding
        m_iLineHeight = pDC->GetTextExtent("X").cy + 4;

        pDC->SelectObject(pOldFont);
        pDC->RestoreDC(iSaved);
        ReleaseDC(pDC);
        m_crDefaultTextColor = textColor;
    }
protected:

//    /// <summary>
//    /// Draws click-able TagContentNode(Returns X+iPos)
//    /// </summary>
//    /// <param name="pDC">The document pointer.</param>
//    /// <param name="DataContent">Content of the data.</param>
//    /// <param name="x">X position of node</param>
//    /// <param name="y">Y position of node</param>
//    /// <param name="rFrame">Frame Coordinates</param>
//    /// <param name="iDocHeight">Total document height</param>
//    /// <returns>int</returns>
//    int DrawDataContentInfo(CDC* pDC, TagContent& DataContent, int x, int y, CRect rFrame, int& iDocHeight)
//    {
//        CRect	rNode;
//
//        // The node's location and dimensions on screen
//        rNode.left = x;
//        rNode.top = y;
//        rNode.right = rFrame.right - m_iPadding;
//        rNode.bottom = y + m_iLineHeight;
//
//        COLORREF crOldText = pDC->SetTextColor(m_TagContentColor);
//
//        int		iPos;
//
//        // Height of a line of text
//        rNode.bottom = rNode.top + m_iLineHeight;
//
//        //------------------Draw primary NodeButton-------------------------------------------------
//        // Find out how much text fits in one line
//        iPos = HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, DataContent.Content);
//        // Draw only if the node is visible
//        if (rNode.bottom > 0 && rNode.top < rFrame.bottom)
//        {
//            pDC->DrawText(DataContent.Content.Left(iPos + 1), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);
//            DataContent.CoordData.CopyRect(rNode);
//        }
//        else
//        {
//            return x;
//        }
//        return x+iPos;
//    }
//
//    /// <summary>
//    /// Recursively draws the nodes.
//    /// </summary>
//    /// <param name="pDC">The document pointer.</param>
//    /// <param name="pNode">The pointer of target node</param>
//    /// <param name="x">X position of node</param>
//    /// <param name="y">Y position of node</param>
//    /// <param name="rFrame">Frame Coordinates</param>
//    /// <param name="iDocHeight">Total document height</param>
//    /// <returns>int</returns>
//    int RecursivelyDrawNodes(CDC* pDC, DataNode* pNode, int x, int y, CRect rFrame, int iDocHeight = 0)
//    {
//        CRect	rNode;
//
//        // The node's location and dimensions on screen
//        rNode.left = x;
//        rNode.top = y;
//        rNode.right = rFrame.right - m_iPadding;
//        rNode.bottom = y + m_iLineHeight;
//
//        COLORREF crOldText = pDC->SetTextColor(m_crDefaultTextColor);
//        CString nodeTextcs;
//
//        // MULTILINE TEXT - begins
//        std::string nodeText = pNode->TagName.c_str();
//        std::string TempText;
//        int iPos = HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, nodeText.c_str());
//        int ArgSize;
//
//        // Height of a line of text(All parts of Node at same height--limiting to single line nodes for now unless need to expand)
//        rNode.bottom = rNode.top + m_iLineHeight;
//
//        //-------------------------------------------------------------------------------------------------------
//
//        size_t NumberArgs;
//        for(ArgList::iterator ArgElement = pNode->ArgData.begin(), EndElement = pNode->ArgData.end(); ArgElement != EndElement; ++ArgElement)
//        {
//            NumberArgs = ArgElement.value.size();
//            if (NumberArgs == 0)//Non-Value Element
//            {
//                TempText = " " + ArgElement.key;
//                ArgElement.value.ArgStart = iPos;
//                iPos += HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, TempText.c_str());
//                ArgElement.value[0].ArgPos = iPos;
//                nodeText += TempText;
//            }
//            else if (NumberArgs>1)//Multiple Linked Argument Elements
//            {
//                TempText = " " + ArgElement.key + "=\"";
//                ArgElement.value.ArgStart = iPos;
//                iPos += HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, TempText.c_str());
//                nodeText += TempText;
//                for (ArgStringList::iterator Arg = ArgElement.value.begin(), FirstArg = Arg, LastArg = ArgElement.value.end(); Arg != LastArg; ++Arg)
//                {
//                    TempText = Arg != FirstArg? Arg->Value: ", "+ Arg->Value;
//                    //Add Starting position data into ArgStringList
//                    Arg->ArgPos = iPos;
//                    iPos += HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, TempText.c_str());
//                }
//                TempText += "\"";
//                ++iPos;
//            }
//            else//Single Argument Link
//            {
//                TempText = " " + ArgElement.key+"=\""+ArgElement.value[0] + "\"";
//                ArgElement.value.ArgStart = iPos;
//                iPos += HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, TempText.c_str());
//                ArgElement.value[0].ArgPos = iPos;
//            }
//        }
//        //Draw only if the node is visible
//        if (rNode.bottom > 0 && rNode.top < rFrame.bottom)
//        {
//            nodeTextcs = nodeText.c_str();
//            pDC->DrawText(nodeTextcs.Left(iPos + 1), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);
//            rNode.left += iPos;
//            pNode->CoordData.CopyRect(rNode);		// Record the rectangle
//        }
//        //Create TagContent as SpecialConnected nodes
//        pDC->SetTextColor(crOldText);
//        size_t ContentSize = pNode->NodeContent.size();
//        if(ContentSize=1)
//        {
//            DrawDataContentInfo(pDC, pNode->NodeContent[0], x + iPos, y, rFrame, iDocHeight);//Single-Line format TagContent
//        }
//        else if(ContentSize>1)
//        {//Determine how to display by things like node-type, TagName etc
//            int XPos = x + iPos;
//            
//            if(pNode->NodeType==50)//QuadVector format hkparam variable such as(axisOfRotation)
//            {
//                DrawTagContentInfo(pDC, "(", XPos, y, rFrame, iDocHeight); ++XPos;
//                XPos = DrawDataContentInfo(pDC, pNode->NodeContent[0], XPos, y, rFrame, iDocHeight);
//                XPos = DrawDataContentInfo(pDC, pNode->NodeContent[1], x + iPos, y, rFrame, iDocHeight);
//                XPos = DrawDataContentInfo(pDC, pNode->NodeContent[2], x + iPos, y, rFrame, iDocHeight);
//                XPos = DrawDataContentInfo(pDC, pNode->NodeContent[3], x + iPos, y, rFrame, iDocHeight);
//                DrawTagContentInfo(pDC, ")", XPos, y, rFrame, iDocHeight);
//            }
//            else if(pNode->NodeType == 51)//Multi-line QuadVector format
//            {
//                int XPosStart = XPos;
//                int RowPosition = 0;
//                DrawTagContentInfo(pDC, "(", XPos, y, rFrame, iDocHeight); ++XPos;
//                for (TagContentVector::iterator targetNodeIndex = pNode->NodeContent.begin(), EndIndex = pNode->NodeContent.end(); targetNodeIndex != EndIndex; ++targetNodeIndex)
//                {
//                    if (RowPosition == 4)
//                    {
//                        DrawTagContentInfo(pDC, ")", XPos, y, rFrame, iDocHeight);
//                        XPos = XPosStart; y = y + pNode->CoordData.Height();
//                        iDocHeight += pNode->CoordData.Height();
//                        RowPosition = 0;
//                        DrawTagContentInfo(pDC, "(", XPos, y, rFrame, iDocHeight);
//                    }
//                    XPos = DrawDataContentInfo(pDC, *targetNodeIndex, XPos, y, rFrame, iDocHeight);
//                    ++RowPosition;
//                }
//            }
//            else
//            {
//                int XPosStart = XPos;
//                int RowPosition = 0;
//                for (TagContentVector::iterator targetNodeIndex = pNode->NodeContent.begin(), EndIndex = pNode->NodeContent.end(); targetNodeIndex != EndIndex; ++targetNodeIndex)
//                {
//                    if(RowPosition==16)//Allow 16 Elements per line
//                    {
//                        XPos = XPosStart; y = y + pNode->CoordData.Height();
//                        iDocHeight += pNode->CoordData.Height();
//                        RowPosition = 0;
//                    }
//                    XPos = DrawDataContentInfo(pDC, *targetNodeIndex, XPos, y, rFrame, iDocHeight);
//                    ++RowPosition;
//                }
//            }
//        }
//        if (pNode->ChildNodes.empty())
//        {
//            return pNode->CoordData.Height();
//        }
//        else if (pNode->bOpen)// If the node is open AND it has children, then draw those
//        {
//            DataNode* targetNode = nullptr;
//            for (UIntVector::iterator targetNodeIndex = pNode->ChildNodes.begin(), EndIndex = pNode->ChildNodes.end(); targetNodeIndex != EndIndex; ++targetNodeIndex)
//            {
//                targetNode = &this->NodeBank[*targetNodeIndex];
//                iDocHeight = RecursivelyDrawNodes(pDC, targetNode, x + m_iIndent, y + targetNode->CoordData.Height(), rFrame);
//            }
//        }
//
//        return iDocHeight + pNode->CoordData.Height();
//    }

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
                iValidSoFar = iNextBlank;							// Record the character position so far
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

    BOOL NodeTextDlg(std::string& csText)
    {
        BOOL				bRet = FALSE;
        TreeNodeText	tntDlg;

        tntDlg.m_csItemText = csText.c_str();

        if (tntDlg.DoModal() == IDOK)
        {
            csText = tntDlg.m_csItemText;
            bRet = TRUE;
        }

        return bRet;
    }

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(TextView)
protected:
    virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
    {
        if (message == WM_NCHITTEST || message == WM_NCLBUTTONDOWN || message == WM_NCLBUTTONDBLCLK)
            return ::DefWindowProc(m_hWnd, message, wParam, lParam);

        return MFCView::WindowProc(message, wParam, lParam);
    }
    //}}AFX_VIRTUAL

    // Generated message map functions
protected:
    //{{AFX_MSG(TextView)
protected:
    virtual void OnDraw(CDC* pDC);
    afx_msg void OnSize(UINT nType, int cx, int cy)
    {
        // Setting the scroll sends its own size message. Prevent it thus avoiding an ugly loop.
        // Other than that, resizing the control means that the tree height may change (word-wrap).
        if (!m_bScrollBarMessage)
            ResetScrollBar();

        MFCView::OnSize(nType, cx, cy);
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
		//MFCView::OnLButtonUp(nFlags, point);
    }

    /// <summary>
    /// Called when [mouse wheel].
    /// </summary>
    /// <param name="nFlags">The n flags.</param>
    /// <param name="zDelta">The z delta.</param>
    /// <param name="pt">The pt.</param>
    /// <returns>BOOL.</returns>
    afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
    {
        // zDelta greater than 0, means rotating away from the user, that is, scrolling up
        OnVScroll((zDelta > 0) ? SB_LINEUP : SB_LINEDOWN, 0, NULL);

        return MFCView::OnMouseWheel(nFlags, zDelta, pt);
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
		
		// Get a device context so that it'll be possible for the context menu
		// to calculate the size of the menu item's text
		CDC* pDC = GetDC();
		int		iSaved = pDC->SaveDC();
		CFont* pOldFont = pDC->SelectObject(&m_Font);

		// Display the context menu
		TextMenu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

		// Clean up
		pDC->SelectObject(pOldFont);
		pDC->RestoreDC(iSaved);
		ReleaseDC(pDC);
    }

    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(TextView, MFCView)
    ON_WM_PAINT()
    ON_WM_SIZE()
    ON_WM_VSCROLL()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEWHEEL()
    ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()
#endif
