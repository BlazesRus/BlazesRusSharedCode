// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Tree Code based on https://www.codeproject.com/Articles/9887/CStaticTreeCtrl-A-CStatic-derived-custom-Tree-cont
// ***********************************************************************
#pragma once
#ifndef TreeView_Header
#define TreeView_Header

//#include "WP_APPDefines.h"
//
//#include "MultiviewPrecompile.h"
////#include "ContextMenu.h"
//#include "DLG_TreeNodeText.h"
//#include <string>
//#include <typeinfo>
//#include "VariableLists/VariableTypeLists.h"
//#include "MultiViewDoc.h"
//#include "DataNode.h"
//#include "DataDictionary.h"
//#include "UIntVector.h"
//#include "ArgList.h"
//#include "VariableTypeLists.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/// <summary>
/// Edited derivable version of CustomTreeControl's CViewTreeCtrl class converted into a view
/// <para/>(base code from https://www.codeproject.com/Articles/9887/CViewTreeCtrl-A-CView-derived-custom-Tree-cont)
// <para/>This version is mix of dictionary and created Node pointer based approach
/// </summary>
/// <seealso cref="CView" />
class TreeView : public CView
{
	DECLARE_DYNCREATE(TreeView)
	// Construction
public:
	/// <summary>
	/// Class named DataNode. (Node links to other nodes in node bank)
	/// Held within NodeDictionary with int key
	/// </summary>
	class DataNode : BasicDataNode
	{
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="DataNode"/> class. (All Data Nodes must have display names)
		/// </summary>
		/// <param name="name">The NodeName.</param>
		DataNode(std::string name){}
		
		/// <summary>
		/// Finalizes an instance of the <see cref="DataNode"/> class.
		/// </summary>
		~DataNode(){}
	};

	/// <summary>
	/// Class named DataDictionary.
	/// Implements the <see cref="std::unordered_map{std::string, DataNode}" />
	/// </summary>
	/// <seealso cref="std::unordered_map{std::string, DataNode}" />
	class DataDictionary : public BasicDataDictionary<DataNode>{};
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="TreeView"/> class.
	/// </summary>
	TreeView()
	{
		//m_pTopNode = new DataNode("No File Loaded");	// The tree top
		TargetNodeRegion = 0;

		m_iIndent = 16;				// Indentation for tree branches
		m_iPadding = 4;				// Padding between tree and the control border

		m_bShowLines = TRUE;				// Show lines by default
		m_bScrollBarMessage = FALSE;			// Only relevant when calculating the scrollbar

		m_iDocHeight = 0;				// A polite yet meaningless default

		m_crDefaultTextColor = RGB(58, 58, 58);	// Some default
		m_crConnectingLines = RGB(128, 128, 128);	// Some default

		// Safeguards
		SetTextFont(8, FALSE, FALSE, "Arial Unicode MS");

		//PrimaryTarget = "";
		//SecondaryTarget = "";
		
		//Test Code
		
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="TreeView"/> class.
	/// </summary>
	virtual ~TreeView()
	{
		RootNodes.clear();
		NodeBank.clear();
		NodeLinks.clear();

		m_Font.DeleteObject();
	}

	MultiViewDoc* GetDocument();

	// Attributes
protected:
	LOGFONT			m_lgFont;
	CFont			m_Font;
	COLORREF		m_crDefaultTextColor;
	COLORREF		m_crConnectingLines;

	BOOL			m_bShowLines;

	int				m_iDocHeight;
	BOOL			m_bScrollBarMessage;

	int				m_iLineHeight;
	int				m_iIndent;
	int				m_iPadding;
	
	DataDictionary NodeBank;
	UIntVector RootNodes;
	CustomOrderedDictionary<std::string, unsigned int> NodeLinks;
	
	//If not zero, limits coordinate search region only within this node and all subnodes from it
	unsigned int TargetNodeRegion;
public:
	/// <summary>
	/// Loads the data from file.
	/// </summary>
	/// <param name="FilePath">The file path.</param>
	/// <returns>bool</returns>
	bool LoadDataFromFile(std::string FilePath)
	{	return true; }

	/// <summary>
	/// Saves the loaded data to file.
	/// </summary>
	/// <param name="FilePath">The file path.</param>
	/// <returns>bool</returns>
	bool SaveDataToFile(std::string FilePath)
	{	return true; }

	/// <summary>
	/// Resets this instance.
	/// </summary>
	void Reset()
	{
		RootNodes.clear();
		NodeBank.clear();
		NodeLinks.clear();
	}

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
	/// Toggle node between open and closed
	/// </summary>
	/// <param name="pNode">The p node.</param>
	/// <param name="bInvalidate">The b invalidate.</param>
	void ToggleNode(DataNode* pNode, BOOL bInvalidate = FALSE)
	{
		ToggleNode(pNode, bInvalidate);
	}

protected:
	void DeleteNode(DataNode* pNode, unsigned int nodeIndex)
	{
		UIntVector TargetNodes;
		TargetNodes.push_back(Key);
		unsigned int pIndex = pNode->ParentIndex;
		for(UIntVector::iterator targetNodeIndex = pNode->ChildNodes.begin(), EndIndex = pNode->ChildNodes.end(); targetNodeIndex != EndIndex; ++targetNodeIndex)
		{
			targetNode = this->NodeBank[*targetNodeIndex];
			AddAllSubNodes(targetNode, TargetNodes);
		}
		if(pNode->ParentIndex==0)
		{
			bool NodeFound = false;
			RootNodes.DeleteFirstMatch(nodeIndex)
		}
		for(UIntVector::iterator targetNodeIndex = TargetNodes.begin(), EndIndex = TargetNodes.end(); targetNodeIndex != EndIndex; ++targetNodeIndex)
		{
			NodeBank.remove(*targetNodeIndex);
		}
		if (bInvalidate)
			Invalidate();
	}
	void AddAllSubNodes(DataNode* pNode, &UIntVector)
	{
		DataNode* targetNode;
		for(UIntVector::iterator targetNodeIndex = pNode->ChildNodes.begin(), EndIndex = pNode->ChildNodes.end(); targetNodeIndex != EndIndex; ++targetNodeIndex)
		{
			targetNode = this->NodeBank[targetNodeIndex];
			AddAllSubNodes(targetNode, TargetNodes);
		}
	}

	int DrawNodesRecursive(CDC* pDC, DataNode* pNode, int x, int y, CRect rFrame)
	{
		int		iDocHeight = 0;		// Total document height
		CRect	rNode;
		CRect	TotalNodeArea;

		// The node's location and dimensions on screen
		rNode.left = x;
		rNode.top = y;
		rNode.right = rFrame.right - m_iPadding;
		rNode.bottom = y + m_iLineHeight;

		//pNode->rNode.CopyRect(rNode);		// Record the rectangle

		COLORREF crOldText = pDC->SetTextColor(m_crDefaultTextColor);

		// MULTILINE TEXT - begins
		CString	cs = pNode->TagName;
		int		iPos;
		int ArgSize;

		// Height of a line of text(All parts of Node at same height--limiting to single line nodes for now unless need to expand)
		rNode.bottom = rNode.top + m_iLineHeight;
		
		//------------------Draw primary NodeButton-------------------------------------------------
		// Find out how much text fits in one line
		iPos = HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, cs);
		// Draw only if the node is visible
		if (rNode.bottom > 0 && rNode.top < rFrame.bottom)
		{
			//Construct TagButton
			pDC->DrawText(cs.Left(iPos + 1), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);//Temporary Code(Switch to button derivative later)
			rNode.left += iPos;
		}
		//-------------------------------------------------------------------------------------------------------
		size_t NumberArgs, Index, LastElem;
		for( auto const& [key, val] : pNode->ArgData )//Draw rest of Nodes based on Args
		{
			NumberArgs = val.size();
			if(NumberArgs==0)//Non-Value Element
			{
				cs = " "+key;
				iPos = HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, cs);
				pDC->DrawText(cs.Left(iPos + 1), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);
				rNode.left += iPos;
			}
			else if(NumberArgs>1)//Multiple Linked Arg Buttons
			{
				cs = " "+key+"=\"";
				iPos = HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, cs);
				pDC->DrawText(cs.Left(iPos + 1), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);
				rNode.left += iPos;
				for(vector<std::string>::iterator Arg = val.begin(), FirstArg = Arg, LastArg = val.end(); Arg != LastArg; ++Arg) 
				{
					if(Arg!=FirstArg)
					{
						cs = ", ";
						pDC->DrawText(cs.Left(3), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);
						rNode.left += 2;
					}
					cs = *Arg;
					iPos = HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, cs);
					pDC->DrawText(cs.Left(iPos + 1), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);//Temporary Code
					rNode.left += iPos;
				}
				cs = "\""
				pDC->DrawText(cs.Left(2), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);
				rNode.left += 1;
			}
			else//Single Arg Link
			{
				cs = " "+key[0];
				iPos = HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, cs);
				pDC->DrawText(cs.Left(iPos + 1), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);//Temporary Code
				rNode.left += iPos;
			}
		}
		if(!pNode.TagContent.empty())
		{
			cs = ">";
			pDC->DrawText(cs.Left(2), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);
			rNode.left += 1;
			for(vector<std::string>::iterator Arg = TagContent.begin(), FirstArg = Arg, LastArg = TagContent.end(); Arg != LastArg; ++Arg) 
			{//Create TagContent NodeButton(s)
				if(Arg!=FirstArg)
				{
					cs = ", ";
					pDC->DrawText(cs.Left(3), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);
					rNode.left += 2;
				}
				cs = *Arg;
				iPos = HowMuchTextFits(pDC, rFrame.right - m_iPadding - rNode.left, cs);
				pDC->DrawText(cs.Left(iPos + 1), rNode, DT_LEFT | DT_SINGLELINE | DT_VCENTER);//Temporary Code
				rNode.left += iPos;
			}
		}
		pDC->SetTextColor(crOldText);
		if(pNode.ChildNodes.empty())
		{
			return pNode->rNode.Height();
		}
		else if(pNode->bOpen)// If the node is open AND it has children, then draw those
		{
			DataNode* targetNode = nullptr;
			for(UIntVector::iterator targetNodeIndex = ChildNodes.begin(), EndIndex = ChildNodes.end(); targetNodeIndex != EndIndex; ++targetNodeIndex)
			{
				targetNode = this->NodeBank[targetNodeIndex];
				iDocHeight = DrawNodesRecursive(pDC, targetNode, x + m_iIndent, y + targetNode->rNode.Height(), rFrame);
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
	
	void DrawLinesRecursive(CDC* pDC, DataNode* pNode)
	{
		DataNode* targetNode = nullptr;
		if(pNode->bOpen)
		{
			for(UIntVector::iterator targetNodeIndex = ChildNodes.begin(), EndIndex = ChildNodes.end(); targetNodeIndex != EndIndex; ++targetNodeIndex)
			{
				targetNode = this->NodeBank[*targetNodeIndex];
				DrawLinesRecursive(pDC, targetNode);
			}
		}

		// Where is the elbow joint of this connecting line?
		int iJointX = pNode->nDisp.TagButton.left - m_iIndent - 6;
		int iJointY = pNode->nDisp.TagButton.top + (m_iLineHeight / 2);
		unsigned int TargetIndex = pNode->ParentIndex;

		// If the parent is not the root, throw a connecting line to it
		if (TargetIndex!=0)
		{
			targetNode = this->NodeBank[TargetIndex];
			// How far up from the joint is the parent?
			int iDispY = iJointY - targetNode->rNode.top - (m_iLineHeight / 2);

			// Use 1 pixel wide rectangles to draw lines
			pDC->FillSolidRect(iJointX, iJointY, m_iIndent, 1, m_crConnectingLines);	// Horizontal line
			pDC->FillSolidRect(iJointX, iJointY, 1, -iDispY, m_crConnectingLines);		// Vertical line
		}

		// Put a solid dot to mark a node
		pDC->FillSolidRect(iJointX + m_iIndent - 2, iJointY - 2, 5, 5, m_crConnectingLines);

		// Hollow out the dot if the node has no children
		if (pNode->ChildNodes.size()==0)
			pDC->FillSolidRect(iJointX + m_iIndent - 1, iJointY - 1, 3, 3, RGB(255, 255, 255));

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

	void AddNode(std::string TagName, unsigned int parentIndex=0, ArgList args)
	{
	
	}
	// Message handlers

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TreeView)
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
	//{{AFX_MSG(TreeView)
	protected:
	virtual void OnDraw(CDC* pDC);
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
	
/*
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point)
	{
		RecursiveNodeSearchByPoint(point);
		switch(dNode.NodeDetected)
		{
			case 1:ToggleNode(dNode.detectedDataNode, bInvalidate); break;
			default: 
				CStatic::OnLButtonUp(nFlags, point); break;
		}
	}
*/
	
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

		//// Find the node that has been clicked on
		SearchNodeByPoint(point);
		
		// If a node has been clicked on, use the first 45 chars of its text as the
		// first menu item (always disabled)
		if (dNode.NodeDetected != 0)
		{
			CContextMenu ccmPopUp(&m_Font);

			ccmPopUp.CreatePopupMenu();

			// Get a device context so that it'll be possible for the context menu
			// to calculate the size of the menu item's text
			CDC		*pDC = GetDC();
			int		iSaved = pDC->SaveDC();
			CFont*	pOldFont = pDC->SelectObject(&m_Font);

			// ADDING MENU ITEMS - Start
		
			CString	csDots = ((dNode.NodeDetected ==1?dNode.detectedDataNode:(dNode.NodeDetected ==2?dNode.detectedClassNode:detectedSubNode))->DisplayName.GetLength() > 45) ? _T("...") : _T("");
			CString cs = (dNode.NodeDetected ==1?dNode.detectedDataNode:(dNode.NodeDetected ==2?dNode.detectedClassNode:detectedSubNode))->DisplayName.Left(45) + csDots;

			ccmPopUp.AppendMenuItem(MF_DISABLED, WM_APP, cs, pDC);
			ccmPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), pDC);
		}

//		//Separating Menus based on Section of Tree used
//		if((dNode.detectedDataNode==m_pTopNode)
//		{
//			//Load Tree from file
//			//Save Tree to .xml file
//		}
//		else if(dNode.NodeDetected==1&&dNode.detectedDataNode.DisplayName=="Event Data")
//		{
//			//Add New Event
//		}
//		else if(dNode.NodeDetected==1&&dNode.detectedDataNode.DisplayName=="Variable Data")
//		{
//			//Add New Variable
//		}
//		else if(dNode.NodeDetected==1&&dNode.detectedDataNode.DisplayName=="Tree Data"){}
//		else
//		{
//			UINT nFlag = (m_pSelected != NULL) ? MF_ENABLED : MF_GRAYED;
//			if(dNode.NodeDetected==2)//Class Node context menu
//			{
//				// Node related items
//				//ccmPopUp.AppendMenuItem(MF_ENABLED, CM_INSERTCHILD, _T("Insert Child"), pDC);
//				//ccmPopUp.AppendMenuItem(nFlag, CM_INSERTSIBLING, _T("Insert Sibling"), pDC);
//				
//				ccmPopUp.AppendMenuItem(MF_ENABLED, CM_DELETENODE, _T("Delete Node"), pDC);
//				ccmPopUp.AppendMenuItem(MF_ENABLED, CM_MODIFYNODETEXT, _T("Modify Node Text"), pDC);
//
//				ccmPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), pDC);
//
//				// Connecting lines related items
//				ccmPopUp.AppendMenuItem(MF_ENABLED, CM_TOGGLECONNECTINGLINES, _T("Toggle Connecting Lines"), pDC);
//				ccmPopUp.AppendMenuItem(MF_ENABLED, CM_SETCONNECTINGLINESCOLOR, _T("Set Connecting Lines Color"), pDC);
//
//				ccmPopUp.AppendMenuItem(MF_SEPARATOR, 0, _T(""), pDC);
//
//				// Tree appearance items
//				ccmPopUp.AppendMenuItem(MF_ENABLED, CM_SETFONT, _T("Set Font"), pDC);
//				ccmPopUp.AppendMenuItem(MF_ENABLED, CM_SETDEFAULTCOLOR, _T("Set Default Text Color"), pDC);
//			}
//			else if(dNode.NodeDetected==3)//Class-Subnode context menu
//			{
//				//Head to related node named under cursor
//			}
//		}
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


BEGIN_MESSAGE_MAP(TreeView, CStatic)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_VSCROLL()
	//ON_WM_LBUTTONUP()
	ON_WM_MOUSEWHEEL()
	//ON_WM_CONTEXTMENU()
	//ON_COMMAND(CM_DELETENODE, OnCM_DeleteNode)
	//ON_COMMAND(CM_MODIFYNODETEXT, OnCM_ModifyNodeText)
	//ON_COMMAND(CM_TOGGLECONNECTINGLINES, OnCM_ToggleConnectingLines)
END_MESSAGE_MAP()
#endif
