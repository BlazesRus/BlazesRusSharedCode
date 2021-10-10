// ***********************************************************************
// base code from https://www.codeproject.com/Articles/9887/CStaticTreeCtrl-A-CStatic-derived-custom-Tree-cont
// Code modified by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************

#if !defined(AudioSupportedContextMenu_Included)
#define AudioSupportedContextMenu_Included

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MultiviewPrecompile.h"
#include "ContextMenu.h"

class AudioSupportedContextMenu : public CContextMenu
{
public:
    AudioSupportedContextMenu() : CContextMenu()
    {
        m_bSoundOn = TRUE;
    }
    /// <summary>
    /// Appends the menu item.
    /// </summary>
    /// <param name="nFlags">The n flags.</param>
    /// <param name="nID">The n identifier.</param>
    /// <param name="csText">The cs text.</param>
    /// <param name="pDC">The p dc.</param>
    /// <param name="csWavFile">The cs wav file.</param>
    /// <returns>CContextMenu &.</returns>
    virtual CContextMenu&	AppendMenuItem(UINT nFlags, UINT nID, CString csText, CDC* pDC, CString csWavFile);
    virtual CContextMenu&	ToggleSound(BOOL bSoundOn);
protected:
    /// <summary>
    /// Boolean toggle for whether sound is enabled
    /// </summary>
    BOOL			m_bSoundOn;
    /// <summary>
    /// Class named ContextMenuItem.
    /// </summary>
    class ContextMenuItem
    {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="CContextMenuItem"/> class.
        /// </summary>
        /// <param name="csText">The cs text.</param>
        ContextMenuItem(CString csText)
        {
            m_csText = csText;
            m_csWavFile = R"()";
        }
        /// <summary>
        /// Initializes a new instance of the <see cref="CContextMenuItem"/> class.
        /// </summary>
        /// <param name="csText">The cs text.</param>
        /// <param name="csWavFile">The cs wav file.</param>
        ContextMenuItem(CString csText, CString csWavFile)
        {
            m_csText = csText;
            m_csWavFile = csWavFile;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="CContextMenuItem"/> class.
        /// </summary>
        ~ContextMenuItem()
        {
            m_csText.Empty();
            m_csWavFile.Empty();
        }

        /// <summary>
        /// The Context Menu text
        /// </summary>
        CString m_csText;
        /// <summary>
        /// The sound file to play on context menu usage
        /// </summary>
        CString m_csWavFile;
    };
    /// <summary>
    /// Draws the item.
    /// </summary>
    /// <param name="lpDIS">The lp dis.</param>
    virtual void			DrawItem(LPDRAWITEMSTRUCT lpDIS);
};
#endif