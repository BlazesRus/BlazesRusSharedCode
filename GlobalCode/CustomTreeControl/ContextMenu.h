// ContextMenu.h: interface for the CContextMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTEXTMENU_H__910CF638_44A0_4741_8E1A_A0F9C964D199__INCLUDED_)
#define AFX_CONTEXTMENU_H__910CF638_44A0_4741_8E1A_A0F9C964D199__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//
/////////////////////////////////////////////////////////////////////////////

#if defined( _UNICODE )
	#define STRCPY(x,y)				wcscpy(x,y)
	#define	ODDCHAR					USHORT
#else
	#define STRCPY(x,y)				strcpy(x,y)
	#define	ODDCHAR					TCHAR
#endif

/////////////////////////////////////////////////////////////////////////////
class CContextMenu : public CMenu
{
public:
	CContextMenu();
	virtual ~CContextMenu();

public:
	virtual CContextMenu&	AppendMenuItem	( UINT nFlags, UINT nID, CString csText, CString csWavFile, CDC* pDC );
	virtual CContextMenu&	SetTextFont		( CFont* font );
	virtual CContextMenu&	ToggleSound		( BOOL bSoundOn );
	virtual CContextMenu&	SetColors		(	COLORREF crText, COLORREF crBackground, COLORREF crDisabled,
												COLORREF crSelected, COLORREF crBorder );

protected:
	virtual void			MeasureItem		( LPMEASUREITEMSTRUCT lpMIS );
	virtual void			DrawItem		( LPDRAWITEMSTRUCT lpDIS );

protected:
	class CContextMenuItem
	{
	public:
		CContextMenuItem( CString csText, CString csWavFile )
		{
			m_csText	= csText;
			m_csWavFile	= csWavFile;
		}

		~CContextMenuItem()
		{
			m_csText.Empty();
			m_csWavFile.Empty();
		}

		CString m_csText;
		CString m_csWavFile;
	};

	CPtrArray		m_cptrMenuItems;

	CFont*			m_pFont;

	int				m_iWidth;
	int				m_iHeight;

	BOOL			m_bSoundOn;

	COLORREF		m_crText, m_crBackground, m_crDisabled, m_crSelected, m_crBorder;
};

#endif // !defined(AFX_CONTEXTMENU_H__910CF638_44A0_4741_8E1A_A0F9C964D199__INCLUDED_)
