// ***********************************************************************
// base code from https://www.codeproject.com/Articles/9887/CStaticTreeCtrl-A-CStatic-derived-custom-Tree-cont
// Code modified by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************

#if !defined(CustomTreeContextMenu_Included)
#define CustomTreeContextMenu_Included

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

#include "MultiviewPrecompile.h"

/// <summary>
/// Class named CContextMenu.
/// Implements the <see cref="CMenu" />
/// </summary>
/// ///////////////////////////////////////////////////////////////////////////
/// <seealso cref="CMenu" />
class CContextMenu : public CMenu
{
public:
    /// <summary>
    /// Initializes a new instance of the <see cref="CContextMenu"/> class.
    /// </summary>
    CContextMenu()
    {
        m_iWidth = 0;
        m_iHeight = 0;
    }
    /// <summary>
    /// Finalizes an instance of the <see cref="CContextMenu"/> class.
    /// </summary>
    virtual ~CContextMenu();

public:
    /// <summary>
    /// Appends the menu item.
    /// </summary>
    /// <param name="nFlags">The n flags.</param>
    /// <param name="nID">The n identifier.</param>
    /// <param name="csText">The cs text.</param>
    /// <param name="pDC">The p dc.</param>
    /// <returns>CContextMenu &.</returns>
    virtual CContextMenu&	AppendMenuItem(UINT nFlags, UINT nID, CString csText, CDC* pDC);
    /// <summary>
    /// Sets the text font.
    /// </summary>
    /// <param name="font">The font.</param>
    /// <returns>CContextMenu &.</returns>
    virtual CContextMenu&	SetTextFont(CFont* font);
    /// <summary>
    /// Sets the colors.
    /// </summary>
    /// <param name="crText">The cr text.</param>
    /// <param name="crBackground">The cr background.</param>
    /// <param name="crDisabled">The cr disabled.</param>
    /// <param name="crSelected">The cr selected.</param>
    /// <param name="crBorder">The cr border.</param>
    /// <returns>CContextMenu &.</returns>
    virtual CContextMenu&	SetColors(COLORREF crText, COLORREF crBackground, COLORREF crDisabled,
                                                COLORREF crSelected, COLORREF crBorder );

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
    /// Class named CContextMenuItem.
    /// </summary>
    class CContextMenuItem
    {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="CContextMenuItem"/> class.
        /// </summary>
        /// <param name="csText">The cs text.</param>
        CContextMenuItem(CString csText)
        {
            m_csText = csText;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="CContextMenuItem"/> class.
        /// </summary>
        ~CContextMenuItem()
        {
            m_csText.Empty();
        }

        /// <summary>
        /// The m cs text
        /// </summary>
        CString m_csText;
    };

    /// <summary>
    /// The m CPTR menu items
    /// </summary>
    CPtrArray		m_cptrMenuItems;

    /// <summary>
    /// The m p font
    /// </summary>
    CFont*			m_pFont;

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
    COLORREF		m_crText, m_crBackground, m_crDisabled, m_crSelected, m_crBorder;
};

#endif
