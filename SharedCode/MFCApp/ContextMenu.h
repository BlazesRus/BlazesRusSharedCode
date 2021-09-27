// ***********************************************************************
// base code from https://www.codeproject.com/Articles/9887/CStaticTreeCtrl-A-CStatic-derived-custom-Tree-cont
// Code modified by James Michael Armstrong (https://github.com/BlazesRus)
// Code changes from BhvTreeEditor/PagedMultiviewTreeControl focused on streamlining the code for can store larger amounts of data(larger files loaded) without running out of memory
// ***********************************************************************

#if !defined(ContextMenu_Included)
#define ContextMenu_Included

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(STRCPY)
#if defined( _UNICODE )
	#define STRCPY(x,y)				wcscpy(x,y)
	#define	ODDCHAR					USHORT
#else
	#define STRCPY(x,y)				strcpy(x,y)
	#define	ODDCHAR					TCHAR
#endif
#endif

#include <string>

/// <summary>
/// Class named ContextMenu.
/// Implements the <see cref="CMenu" />
/// </summary>
/// ///////////////////////////////////////////////////////////////////////////
/// <seealso cref="CMenu" />
class ContextMenu : public CMenu
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="ContextMenu"/> class.
	/// </summary>
	ContextMenu(CFont* font)
	{
		m_pFont = font;
		m_iWidth = 0;
		m_iHeight = 0;
	}
	/// <summary>
	/// Finalizes an instance of the <see cref="ContextMenu"/> class.
	/// </summary>
	virtual ~ContextMenu();

public:
	/// <summary>
	/// Appends the menu item.
	/// </summary>
	/// <param name="nFlags">The n flags.</param>
	/// <param name="nID">The n identifier.</param>
	/// <param name="csText">The cs text.</param>
	/// <param name="pDC">The p dc.</param>
	/// <returns>ContextMenu &.</returns>
	virtual ContextMenu&	AppendMenuItem(UINT nFlags, UINT nID, CString csText, CDC* pDC);
protected:
	/// <summary>
	/// Measures the item.
	/// </summary>
	/// <param name="lpMIS">The lp mis.</param>
	virtual void			MeasureItem(LPMEASUREITEMSTRUCT lpMIS);
	/// <summary>
	/// Draws the item.
	/// </summary>
	/// <param name="lpDIS">The lp dis.</param>
	virtual void			DrawItem(LPDRAWITEMSTRUCT lpDIS);

protected:
	/// <summary>
	/// Class named ContextMenuItem.
	/// </summary>
	class ContextMenuItem
	{
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="ContextMenuItem"/> class.
		/// </summary>
		/// <param name="csText">The cs text.</param>
		ContextMenuItem(CString csText)
		{
			m_csText = csText;
		}

		/// <summary>
		/// Finalizes an instance of the <see cref="ContextMenuItem"/> class.
		/// </summary>
		~ContextMenuItem()
		{
			m_csText.Empty();
		}

		/// <summary>
		/// The Text Displayed inside Content Menu item
		/// </summary>
		CString m_csText;
	};

	/// <summary>
	/// The m CPTR menu items
	/// </summary>
	CPtrArray		m_cptrMenuItems;

	

	/// <summary>
	/// The font type used for ContextMenu (Only single instance saved)
	/// </summary>
	CFont* m_pFont;

	/// <summary>
	/// The m i width
	/// </summary>
	int				m_iWidth;

	/// <summary>
	/// The m i height
	/// </summary>
	int				m_iHeight;

	/// <summary>
	/// Context Menu color references
	/// </summary>
	const COLORREF m_crText = RGB(70, 36, 36);
	const COLORREF m_crBackground = RGB(253, 249, 249);
	const COLORREF m_crDisabled = RGB(172, 96, 96);
	const COLORREF m_crSelected = RGB(244, 234, 234);
	const COLORREF m_crBorder = RGB(182, 109, 109);
};

#endif
