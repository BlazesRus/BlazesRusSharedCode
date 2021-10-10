// ContextMenu.cpp: implementation of the CContextMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "MultiviewPrecompile.h"
#include "customtreecontrol.h"
#include "ContextMenu.h"
#include "mmsystem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CContextMenu::~CContextMenu()
{
    for( int i = 0; i < m_cptrMenuItems.GetSize(); i++ )
        delete (CContextMenuItem*)( m_cptrMenuItems.GetAt( i ) );

    m_cptrMenuItems.RemoveAll();
}

/////////////////////////////////////////////////////////////////////////////
//	PUBLIC METHODS
/////////////////////////////////////////////////////////////////////////////
CContextMenu& CContextMenu::SetTextFont( CFont* font )
{
    m_pFont = font;

    return *this;
}

CContextMenu& CContextMenu::AppendMenuItem(UINT nFlags, UINT nID, CString csText, CDC* pDC)
{
    CContextMenuItem* cccItem = new CContextMenuItem(csText);

    // Store the pointer
    m_cptrMenuItems.Add( cccItem );

    // Append menu
    //CMenu::AppendMenu( nFlags | MF_OWNERDRAW, nID, (ODDCHAR*)cccItem );
    CMenu::AppendMenu(nFlags | MF_OWNERDRAW, nID, (LPCTSTR)cccItem);

    // Calculate the size of the menu's text
    if( !csText.IsEmpty() )
    {
        CSize cSize	= pDC->GetTextExtent( csText );

        m_iWidth	= max( m_iWidth, cSize.cx );
        m_iHeight	= max( m_iHeight, 8 + cSize.cy );
    }

    return *this;
}

CContextMenu& CContextMenu::SetColors(	COLORREF crText, COLORREF crBackground, COLORREF crDisabled,
                                        COLORREF crSelected, COLORREF crBorder )
{
    m_crText		= crText;
    m_crBackground	= crBackground;
    m_crDisabled	= crDisabled;
    m_crSelected	= crSelected;
    m_crBorder		= crBorder;

    return *this;
}


/////////////////////////////////////////////////////////////////////////////
//	PROTECTED METHODS
/////////////////////////////////////////////////////////////////////////////
void CContextMenu::MeasureItem( LPMEASUREITEMSTRUCT lpMIS )
{
    // Separator?
    if( GetMenuState( lpMIS->itemID, MF_BYCOMMAND ) & MF_SEPARATOR )
    {
        lpMIS->itemWidth	= m_iWidth;
        lpMIS->itemHeight	= 6;
    }
    else
    {
        lpMIS->itemWidth	= m_iWidth;
        lpMIS->itemHeight	= m_iHeight;
    }
}

void CContextMenu::DrawItem( LPDRAWITEMSTRUCT lpDIS )
{
    // Get the relevant information
    CDC*				pDC			= CDC::FromHandle( lpDIS->hDC );
    CRect				rItem		= lpDIS->rcItem;
    BOOL				bSelected	= lpDIS->itemState & ODS_SELECTED;
    UINT				nAction		= lpDIS->itemAction;
    UINT				nState		= GetMenuState( lpDIS->itemID, MF_BYCOMMAND );
    CContextMenuItem*	cccItem		= reinterpret_cast<CContextMenuItem*>( lpDIS->itemData );

    // Does this menu item need to be drawn?
    if( nAction & ODA_SELECT || nAction & ODA_DRAWENTIRE )
    {
        // Background
        pDC->FillSolidRect( rItem, m_crBackground );

        // Separator or Text
        if( nState & MF_SEPARATOR )
        {
            rItem.DeflateRect( 4, 2, 4, 2 );

            // A thin rectangle that could be anything you want
            pDC->FillSolidRect( rItem, m_crBorder );
        }
        else
        {
            // Prepare the device context and store previous values
            COLORREF	crOldColor	= pDC->SetTextColor( m_crText );
            int			iMode		= pDC->SetBkMode( TRANSPARENT );
            CFont*		pOldFont	= pDC->SelectObject( m_pFont );

            // Is the item disabled?
            if( nState & MFS_DISABLED )
            {
                rItem.DeflateRect( 8, 0, 0, 0 );
                pDC->SetTextColor( m_crDisabled );
                pDC->DrawText( cccItem->m_csText, rItem, DT_VCENTER | DT_LEFT | DT_SINGLELINE );
            }
            else
            {
                // If the item is selected, paint a rectangle, change the background color
                // and play the sound file if relevant
                if( bSelected )
                {
                    rItem.DeflateRect( 2, 2, 2, 2 );
                    pDC->Draw3dRect( rItem, m_crBorder, m_crBorder );
                    rItem.DeflateRect( 1, 1, 1, 1 );
                    pDC->FillSolidRect( rItem, m_crSelected );
                    rItem.DeflateRect( 5, -3, 0, -3 );
                }
                else
                    rItem.DeflateRect( 8, 0, 0, 0 );

                // Last, draw the text on top of everything else
                pDC->DrawText( cccItem->m_csText, rItem, DT_VCENTER | DT_LEFT | DT_SINGLELINE );
            }

            // Clean up
            pDC->SelectObject	( pOldFont );
            pDC->SetBkMode		( iMode );
            pDC->SetTextColor	( crOldColor );
        }
    }
}

