#include "MultiviewPrecompile.h"
#include "AudioSupportedContextMenu.h"
#include "mmsystem.h"

/// <summary>
/// Draws the item.
/// </summary>
/// <param name="lpDIS">The lp dis.</param>


/// <summary>
/// Appends the menu item.
/// </summary>
/// <param name="nFlags">The n flags.</param>
/// <param name="nID">The n identifier.</param>
/// <param name="csText">The cs text.</param>
/// <param name="pDC">The p dc.</param>
/// <param name="csWavFile">The cs wav file.</param>
/// <returns>CContextMenu &.</returns>

inline CContextMenu & AudioSupportedContextMenu::AppendMenuItem(UINT nFlags, UINT nID, CString csText, CDC * pDC, CString csWavFile)
{
    ContextMenuItem* cccItem = new ContextMenuItem(csText, csWavFile);
    // Store the pointer
    m_cptrMenuItems.Add(cccItem);

    // Append menu
    //CMenu::AppendMenu( nFlags | MF_OWNERDRAW, nID, (ODDCHAR*)cccItem );
    CMenu::AppendMenu(nFlags | MF_OWNERDRAW, nID, (LPCTSTR)cccItem);

    // Calculate the size of the menu's text
    if (!csText.IsEmpty())
    {
        CSize cSize = pDC->GetTextExtent(csText);

        m_iWidth = max(m_iWidth, cSize.cx);
        m_iHeight = max(m_iHeight, 8 + cSize.cy);
    }

    return *this;
}

inline CContextMenu & AudioSupportedContextMenu::ToggleSound(BOOL bSoundOn)
{
    m_bSoundOn = bSoundOn;
    return *this;
}

inline void AudioSupportedContextMenu::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
    // Get the relevant information
    CDC*				pDC = CDC::FromHandle(lpDIS->hDC);
    CRect				rItem = lpDIS->rcItem;
    BOOL				bSelected = lpDIS->itemState & ODS_SELECTED;
    UINT				nAction = lpDIS->itemAction;
    UINT				nState = GetMenuState(lpDIS->itemID, MF_BYCOMMAND);
    ContextMenuItem*	cccItem = reinterpret_cast<ContextMenuItem*>(lpDIS->itemData);

    // Does this menu item need to be drawn?
    if (nAction & ODA_SELECT || nAction & ODA_DRAWENTIRE)
    {
        // Background
        pDC->FillSolidRect(rItem, m_crBackground);

        // Separator or Text
        if (nState & MF_SEPARATOR)
        {
            rItem.DeflateRect(4, 2, 4, 2);

            // A thin rectangle that could be anything you want
            pDC->FillSolidRect(rItem, m_crBorder);
        }
        else
        {
            // Prepare the device context and store previous values
            COLORREF	crOldColor = pDC->SetTextColor(m_crText);
            int			iMode = pDC->SetBkMode(TRANSPARENT);
            CFont*		pOldFont = pDC->SelectObject(m_pFont);

            // Is the item disabled?
            if (nState & MFS_DISABLED)
            {
                rItem.DeflateRect(8, 0, 0, 0);
                pDC->SetTextColor(m_crDisabled);
                pDC->DrawText(cccItem->m_csText, rItem, DT_VCENTER | DT_LEFT | DT_SINGLELINE);
            }
            else
            {
                // If the item is selected, paint a rectangle, change the background color
                // and play the sound file if relevant
                if (bSelected)
                {
                    rItem.DeflateRect(2, 2, 2, 2);
                    pDC->Draw3dRect(rItem, m_crBorder, m_crBorder);
                    rItem.DeflateRect(1, 1, 1, 1);
                    pDC->FillSolidRect(rItem, m_crSelected);
                    rItem.DeflateRect(5, -3, 0, -3);
                    if (m_bSoundOn)
                    {
                        // Stop any currently playing wave file
                        PlaySound(NULL, NULL, SND_NOWAIT | SND_PURGE);
                        // Play this item's wave file
                        PlaySound(cccItem->m_csWavFile, NULL, SND_NOWAIT | SND_FILENAME | SND_ASYNC);
                    }
                }
                else
                    rItem.DeflateRect(8, 0, 0, 0);

                // Last, draw the text on top of everything else
                pDC->DrawText(cccItem->m_csText, rItem, DT_VCENTER | DT_LEFT | DT_SINGLELINE);
            }

            // Clean up
            pDC->SelectObject(pOldFont);
            pDC->SetBkMode(iMode);
            pDC->SetTextColor(crOldColor);
        }
    }
}
