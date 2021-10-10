// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Code based on https://www.codeproject.com/Articles/9887/CStaticTreeCtrl-A-CStatic-derived-custom-Tree-cont
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#pragma once
#ifndef CustomTreeCtrl_Header
#define CustomTreeCtrl_Header

#include "WP_APPDefines.h"

#include "MultiviewPrecompile.h"
//#include "CustomTreeControl.h"
//#include "StaticTreeCtrl.h"
#include "ContextMenu.h"
#include "DLG_TreeNodeText.h"
//#include "CustomTreeNode.h"
//#include "OtherFunctions/MFCMacros.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/// <summary>
/// Edited derivable version of CustomTreeControl's CStaticTreeCtrl class <para />(base code from https://www.codeproject.com/Articles/9887/CStaticTreeCtrl-A-CStatic-derived-custom-Tree-cont)
/// <para />NodeCtrl refers to NodeTree holding this class
/// <para />TreeNode refers to derived class's name (for keeping inherited functionality)
/// Implements the <see cref="CStatic" />
/// </summary>
/// <seealso cref="CStatic" />
template <typename TreeNode>
class CustomTreeCtrl : public CStatic
{
    // Construction
public:
    /// <summary>
    /// Initializes a new instance of the <see cref="CustomTreeCtrl"/> class.
    /// </summary>
    CustomTreeCtrl()
    {
#ifdef BlazesGUICode_UseDictionaryBasedNodes
#else
        m_pTopNode = new TreeNode();	// The tree top
#endif

        m_iIndent = 16;				// Indentation for tree branches
        m_iPadding = 4;				// Padding between tree and the control border

        m_bShowLines = TRUE;				// Show lines by default
        m_bScrollBarMessage = FALSE;			// Only relevant when calculating the scrollbar

        m_iDocHeight = 0;				// A polite yet meaningless default

        m_crDefaultTextColor = RGB(58, 58, 58);	// Some default
        m_crConnectingLines = RGB(128, 128, 128);	// Some default

        m_bAudioOn = FALSE;			// The context menu audio

                                    // Safeguards
        SetTextFont(8, FALSE, FALSE, "Arial Unicode MS");
        m_pSelected = NULL;
    }

    /// <summary>
    /// Finalizes an instance of the <see cref="CustomTreeCtrl"/> class.
    /// </summary>
    virtual ~CustomTreeCtrl()
    {
        DeleteNode(m_pTopNode);	// Delete all children if there are any
        delete m_pTopNode;			// Delete top node
        m_pTopNode = NULL;

        m_Font.DeleteObject();

        if (m_bmpBackground.GetSafeHandle() != NULL)
            m_bmpBackground.DeleteObject();
    }
    // Attributes
protected:
    LOGFONT			m_lgFont;
    CFont			m_Font;
    COLORREF		m_crDefaultTextColor;
    COLORREF		m_crConnectingLines;

    BOOL			m_bShowLines;

    CBitmap			m_bmpBackground;

    int				m_iDocHeight;
    BOOL			m_bScrollBarMessage;

    int				m_iLineHeight;
    int				m_iIndent;
    int				m_iPadding;

    //Saving TreeNode* inside base class of CustomTreeNode* as fix for C2664 error
    CustomTreeNode*		m_pTopNode;
    CustomTreeNode*		m_pSelected;

    BOOL			m_bAudioOn;

    // Operations
public:
    /// <summary>
    /// Sets the text font.
    /// </summary>
    /// <param name="nHeight">Height of the n.</param>
    /// <param name="bBold">The b bold.</param>
    /// <param name="bItalic">The b italic.</param>
    /// <param name="csFaceName">Name of the cs face.</param>
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
        CDC		*pDC = GetDC();
        int		iSaved = pDC->SaveDC();
        CFont*	pOldFont = pDC->SelectObject(&m_Font);

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
    /// <param name="crText">The cr text.</param>
    virtual void SetDefaultTextColor(COLORREF crText)
    {
        m_crDefaultTextColor = crText;
    }

    /// <summary>
    /// Sets the text settings.
    /// </summary>
    /// <param name="nHeight">Height of the n.</param>
    /// <param name="bBold">The b bold.</param>
    /// <param name="bItalic">The b italic.</param>
    /// <param name="csFaceName">Name of the cs face.</param>
    /// <param name="crText">The cr text.</param>
    virtual void SetTextSettings(LONG nHeight, BOOL bBold, BOOL bItalic, const CString& csFaceName, COLORREF crText)
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
        CDC		*pDC = GetDC();
        int		iSaved = pDC->SaveDC();
        CFont*	pOldFont = pDC->SelectObject(&m_Font);

        // Calculate the height of this font with a character likely to be 'big'
        // and don't forget to add a little padding
        m_iLineHeight = pDC->GetTextExtent("X").cy + 4;

        pDC->SelectObject(pOldFont);
        pDC->RestoreDC(iSaved);
        ReleaseDC(pDC);
        m_crDefaultTextColor = crText;
    }

    /// <summary>
    /// Inserts the sibling.
    /// </summary>
    /// <param name="pInsertAfter">The p insert after.</param>
    /// <param name="csLabel">The cs label.</param>
    /// <param name="crText">The cr text.</param>
    /// <param name="bUseDefaultTextColor">Color of the b use default text.</param>
    /// <param name="bInvalidate">The b invalidate.</param>
    /// <returns>CustomTreeNode *.</returns>
    CustomTreeNode* InsertSibling(CustomTreeNode* pInsertAfter, const CString& csLabel,
        COLORREF crText = 0, BOOL bUseDefaultTextColor = TRUE,
        BOOL bInvalidate = FALSE)
    {
        ASSERT(pInsertAfter != NULL);	// Make sure the node exists

        CustomTreeNode* pNewNode = new TreeNode();

        pNewNode->DisplayName = csLabel;					// New node's label

        if (bUseDefaultTextColor)
            pNewNode->bUseDefaultTextColor = TRUE;		// Use the default text color
        else
            pNewNode->textColor = crText;					// New node's text color

        pNewNode->pParent = pInsertAfter->pParent;	// Has the same parent

                                                    // Insert the new node between pInsertAfter and its next sibling
        pNewNode->pSibling = pInsertAfter->pSibling;
        pInsertAfter->pSibling = pNewNode;

        // Repaint the control if so desired
        if (bInvalidate)
            Invalidate();

        return pNewNode;
    }
    /// <summary>
    /// Inserts the child.
    /// </summary>
    /// <param name="pParent">The p parent.</param>
    /// <param name="csLabel">The cs label.</param>
    /// <param name="crText">The cr text.</param>
    /// <param name="bUseDefaultTextColor">Color of the b use default text.</param>
    /// <param name="bInvalidate">The b invalidate.</param>
    /// <returns>CustomTreeNode *.</returns>
    CustomTreeNode* InsertChild(CustomTreeNode* pParent, const CString& csLabel,
        COLORREF crText = 0, BOOL bUseDefaultTextColor = TRUE,
        BOOL bInvalidate = FALSE)
    {
        ASSERT(pParent != NULL);	// Make sure the node exists

        if (pParent == m_pTopNode)	// Check for top node
            pParent = m_pTopNode;

        CustomTreeNode* pNewNode = new TreeNode();

        // Basic node information
        pNewNode->DisplayName = csLabel;	// New node's label

        if (bUseDefaultTextColor)
            pNewNode->bUseDefaultTextColor = TRUE;		// Use the default text color
        else
            pNewNode->textColor = crText;					// New node's text color

        pNewNode->pParent = pParent;	// New node's parent

                                        // Insert the new node as pParent's first child
        pNewNode->pSibling = pParent->pChild;
        pParent->pChild = pNewNode;

        // Repaint the control if so desired
        if (bInvalidate)
            Invalidate();

        return pNewNode;
    }
    /// <summary>
    /// Adds to root.
    /// </summary>
    /// <param name="csLabel">The cs label.</param>
    /// <param name="crText">The cr text.</param>
    /// <param name="bUseDefaultTextColor">Color of the b use default text.</param>
    /// <param name="bInvalidate">The b invalidate.</param>
    /// <returns>CustomTreeNode *.</returns>
    CustomTreeNode* AddToRoot(const CString& csLabel, COLORREF crText = 0, BOOL bUseDefaultTextColor = TRUE, BOOL bInvalidate = FALSE)
    {
        return InsertChild(m_pTopNode, csLabel, crText, bUseDefaultTextColor, bInvalidate);
    }

    /// <summary>
    /// Deletes the node.
    /// </summary>
    /// <param name="pNode">The p node.</param>
    /// <param name="bInvalidate">The b invalidate.</param>
    void DeleteNode(CustomTreeNode* pNode, BOOL bInvalidate = FALSE)
    {
        ASSERT(pNode != NULL);	// Make sure the node exists

                                // Don't delete the top node
        if (pNode == m_pTopNode)
            DeleteNode(m_pTopNode, bInvalidate);

        // Delete children
        if (pNode->pChild != NULL)
            DeleteNodeRecursive(pNode->pChild);

        // If this node is not the top node, fix pointers in sibling list
        if (pNode != m_pTopNode)
        {
            CustomTreeNode* pRunner = pNode->pParent;

            // If first child, set the parent pointer to the next sibling
            // Otherwise, find sibling before and set its sibling pointer to the node's sibling
            if (pRunner->pChild == pNode)
                pRunner->pChild = pNode->pSibling;
            else
            {
                pRunner = pRunner->pChild;

                // Loop until the next node is the one being deleted
                while (pRunner->pSibling != pNode)
                    pRunner = pRunner->pSibling;

                pRunner->pSibling = pNode->pSibling;
            }

            delete pNode;

            pNode = NULL;
        }

        // Repaint the control if so desired
        if (bInvalidate)
            Invalidate();
    }

    /// <summary>
    /// Toggle node between open and closed
    /// </summary>
    /// <param name="pNode">The p node.</param>
    /// <param name="bInvalidate">The b invalidate.</param>
    void ToggleNode(CustomTreeNode* pNode, BOOL bInvalidate = FALSE)
    {
        ASSERT(pNode != NULL);

        pNode->bOpen = !(pNode->bOpen);

        if (bInvalidate)
            Invalidate();
    }
    void SetNodeColor(CustomTreeNode* pNode, COLORREF crText, BOOL bInvalidate = FALSE)
    {
        ASSERT(pNode != NULL);

        pNode->bUseDefaultTextColor = FALSE;
        pNode->textColor = crText;

        if (bInvalidate)
            Invalidate();
    }

    void SetBackgroundBitmap(BOOL bInvalidate = FALSE)
    {
        CFileDialog fd(TRUE, NULL, NULL, OFN_EXPLORER | OFN_FILEMUSTEXIST, _T("Bitmap Files (*.bmp)|*.bmp||"), this);

        // If the user clicked 'OK'
        if (fd.DoModal() == IDOK)
        {
            // If there is a bitmap already loaded, delete it
            if (m_bmpBackground.GetSafeHandle() != NULL)
                m_bmpBackground.DeleteObject();

            // Load the bitmap from the file selected
            HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, fd.GetPathName(), IMAGE_BITMAP,
                0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);

            // Attach it to the CBitmap object
            m_bmpBackground.Attach(hBitmap);

            // Repaint if so desired
            if (bInvalidate)
                Invalidate();
        }
    }

protected:
    void DeleteNodeRecursive(CustomTreeNode* pNode)
    {
        if (pNode->pSibling != NULL)
            DeleteNodeRecursive(pNode->pSibling);

        if (pNode->pChild != NULL)
            DeleteNodeRecursive(pNode->pChild);

        delete pNode;

        pNode = NULL;
    }		// Recursive delete

    int DrawNodesRecursive(CDC* pDC, CustomTreeNode* pNode, int x, int y, CRect rFrame)
    {
        int		iDocHeight = 0;		// Total document height
        CRect	rNode;

        // The node's location and dimensions on screen
        rNode.left = x;
        rNode.top = y;
        rNode.right = rFrame.right - m_iPadding;
        rNode.bottom = y + m_iLineHeight;

        pNode->rNode.CopyRect(rNode);		// Record the rectangle

        COLORREF cr = (pNode->bUseDefaultTextColor) ? m_crDefaultTextColor : pNode->textColor;
        COLORREF crOldText = pDC->SetTextColor(cr);

        // MULTILINE TEXT - begins
        CString	cs = pNode->DisplayName;
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

        // If there are no child or siblings, then this branch is done
        if (pNode->pChild == NULL && pNode->pSibling == NULL)
            return pNode->rNode.Height();

        // If the node is open AND it has children, then draw those
        if (pNode->bOpen && pNode->pChild != NULL)
            iDocHeight = DrawNodesRecursive(pDC, pNode->pChild, x + m_iIndent, y + pNode->rNode.Height(), rFrame);

        // If the node has siblings, then draw those
        if (pNode->pSibling != NULL)
            iDocHeight += DrawNodesRecursive(pDC, pNode->pSibling, x, y + pNode->rNode.Height() + iDocHeight, rFrame);

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
                iValidSoFar = iNextBlank;							// Record the char pos so far
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

    void DrawLinesRecursive(CDC* pDC, CustomTreeNode* pNode)
    {
        // Draw lines from children if the node is open before drawing lines from this node
        if (pNode->bOpen && pNode->pChild != NULL)
            DrawLinesRecursive(pDC, pNode->pChild);

        // Where is the elbow joint of this connecting line?
        int iJointX = pNode->rNode.left - m_iIndent - 6;
        int iJointY = pNode->rNode.top + (m_iLineHeight / 2);

        // If the parent is not the top node, throw a connecting line to it
        if (pNode->pParent != m_pTopNode)
        {
            // How far up from the joint is the parent?
            int iDispY = iJointY - pNode->pParent->rNode.top - (m_iLineHeight / 2);

            // Use 1 pixel wide rectangles to draw lines
            pDC->FillSolidRect(iJointX, iJointY, m_iIndent, 1, m_crConnectingLines);	// Horizontal line
            pDC->FillSolidRect(iJointX, iJointY, 1, -iDispY, m_crConnectingLines);		// Vertical line
        }

        // Put a solid dot to mark a node
        pDC->FillSolidRect(iJointX + m_iIndent - 2, iJointY - 2, 5, 5, m_crConnectingLines);

        // Hollow out the dot if the node has no children
        if (pNode->pChild == NULL)
            pDC->FillSolidRect(iJointX + m_iIndent - 1, iJointY - 1, 3, 3, RGB(255, 255, 255));

        // Draw the next sibling if there are any
        if (pNode->pSibling != NULL)
            DrawLinesRecursive(pDC, pNode->pSibling);
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

    CustomTreeNode* FindNodeByPoint(const CPoint& point, CustomTreeNode* pNode)
    {
        CustomTreeNode* pFound = NULL;

        // Found it?
        if (pNode->rNode.PtInRect(point))
            pFound = pNode;

        // If this node isn't it then check the node's children if it is open and there are any
        if (pFound == NULL && pNode->bOpen && pNode->pChild != NULL)
            pFound = FindNodeByPoint(point, pNode->pChild);

        // If didn't find it among the node's children, then check the next sibling
        if (pFound == NULL && pNode->pSibling != NULL)
            pFound = FindNodeByPoint(point, pNode->pSibling);

        return pFound;
    }
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
        if (NodeTextDlg(m_pSelected->DisplayName) == TRUE)
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
    void OnCM_ToggleMenuSound()
    {
        m_bAudioOn = !m_bAudioOn;
    }

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CustomTreeCtrl)
protected:
    virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
    {
        if (message == WM_NCHITTEST || message == WM_NCLBUTTONDOWN || message == WM_NCLBUTTONDBLCLK)
            return ::DefWindowProc(m_hWnd, message, wParam, lParam);

        return CStatic::WindowProc(message, wParam, lParam);
    }
    //}}AFX_VIRTUAL


    // Generated message map functions
protected:
    //{{AFX_MSG(CustomTreeCtrl)
    afx_msg void OnPaint()
    {
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

        if (m_pTopNode->pChild != NULL)
        {
            iLastNodePos = DrawNodesRecursive(pDCMem, m_pTopNode->pChild,
                rFrame.left + m_iIndent,
                m_iPadding - GetScrollPos(SB_VERT),
                rFrame);

            if (m_bShowLines)
                DrawLinesRecursive(pDCMem, m_pTopNode->pChild);
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

        CStatic::OnSize(nType, cx, cy);
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
        CustomTreeNode* pClickedOn = NULL;		// Assume no node was clicked on

        if (m_pTopNode->pChild != NULL)		// If the tree is populated, search it
            pClickedOn = FindNodeByPoint(point, m_pTopNode->pChild);

        if (pClickedOn != NULL)			// If a node was clicked on
            ToggleNode(pClickedOn, TRUE);
        else
            CStatic::OnLButtonUp(nFlags, point);
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

        return CStatic::OnMouseWheel(nFlags, zDelta, pt);
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
        if (m_pTopNode->pChild == NULL)
            m_pSelected = NULL;		// Empty tree
        else
            m_pSelected = FindNodeByPoint(cp, m_pTopNode->pChild);

        CContextMenu ccmPopUp;

        ccmPopUp.CreatePopupMenu();

        // Customize the menu appearance and behavior
        ccmPopUp
#ifdef EnableCustomTreeSounds
            .ToggleSound(m_bAudioOn)
#endif
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
            CString	csDots = (m_pSelected->DisplayName.GetLength() > 45) ? _T("...") : _T("");
            CString cs = m_pSelected->DisplayName.Left(45) + csDots;
#ifdef EnableCustomTreeSounds
            ccmPopUp.AppendMenuItem(MF_DISABLED, WM_APP, cs, _T(""), pDC);
            ccmPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), _T(""), pDC);
#else
            ccmPopUp.AppendMenuItem(MF_DISABLED, WM_APP, cs, pDC);
            ccmPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), pDC);
#endif
        }

        UINT nFlag = (m_pSelected != NULL) ? MF_ENABLED : MF_GRAYED;

#ifdef EnableCustomTreeSounds
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
#else
        // Node related items
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_INSERTCHILD, _T("Insert Child"), pDC);
        ccmPopUp.AppendMenuItem(nFlag, CM_INSERTSIBLING, _T("Insert Sibling"), pDC);
        ccmPopUp.AppendMenuItem(nFlag, CM_DELETENODE, _T("Delete Node"), pDC);
        ccmPopUp.AppendMenuItem(nFlag, CM_MODIFYNODETEXT, _T("Modify Node Text"), pDC);
        ccmPopUp.AppendMenuItem(nFlag, CM_CHANGENODECOLOR, _T("Change Node Color"), pDC);

        ccmPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), pDC);

        // Connecting lines related items
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_TOGGLECONNECTINGLINES, _T("Toggle Connecting Lines"), pDC);
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_SETCONNECTINGLINESCOLOR, _T("Set Connecting Lines Color"), pDC);

        ccmPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), pDC);

        // Tree appearance items
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_SETFONT, _T("Set Font"), pDC);
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_SETDEFAULTCOLOR, _T("Set Default Text Color"), pDC);
        ccmPopUp.AppendMenuItem(MF_ENABLED, CM_SETBACKGROUNDBITMAP, _T("Set Background Bitmap"), pDC);
#endif

        // ADDING MENU ITEMS - End

        // Display the context menu
        ccmPopUp.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);

        // Clean up
        pDC->SelectObject(pOldFont);
        pDC->RestoreDC(iSaved);
        ReleaseDC(pDC);
    }
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


BEGIN_TEMPLATE_MESSAGE_MAP(CustomTreeCtrl, TreeNode, CStatic)
    ON_WM_PAINT()
    ON_WM_SIZE()
    ON_WM_VSCROLL()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEWHEEL()
    ON_WM_CONTEXTMENU()
    ON_COMMAND(CM_INSERTCHILD, OnCM_InsertChild)
    ON_COMMAND(CM_INSERTSIBLING, OnCM_InsertSibling)
    ON_COMMAND(CM_DELETENODE, OnCM_DeleteNode)
    ON_COMMAND(CM_MODIFYNODETEXT, OnCM_ModifyNodeText)
    ON_COMMAND(CM_CHANGENODECOLOR, OnCM_ChangeNodeColor)
    ON_COMMAND(CM_TOGGLECONNECTINGLINES, OnCM_ToggleConnectingLines)
    ON_COMMAND(CM_SETCONNECTINGLINESCOLOR, OnCM_SetConnectingLinesColor)
    ON_COMMAND(CM_SETFONT, OnCM_SetFont)
    ON_COMMAND(CM_SETDEFAULTCOLOR, OnCM_SetDefaultColor)
    ON_COMMAND(CM_SETBACKGROUNDBITMAP, OnCM_SetBackgroundBitmap)
    ON_COMMAND(CM_TOGGLEMENUSOUND, OnCM_ToggleMenuSound)
END_MESSAGE_MAP()
#endif
