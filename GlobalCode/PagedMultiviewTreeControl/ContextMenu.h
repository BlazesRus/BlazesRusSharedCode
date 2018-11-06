// ContextMenu.h: interface for the CContextMenu class.
//
//////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////
class CContextMenu : public CMenu
{
public:
	CContextMenu();
	virtual ~CContextMenu();

public:
	virtual CContextMenu&	AppendMenuItem	( UINT nFlags, UINT nID, CString csText, CDC* pDC );
	virtual CContextMenu&	SetTextFont		( CFont* font );
	virtual CContextMenu&	SetColors		(	COLORREF crText, COLORREF crBackground, COLORREF crDisabled,
												COLORREF crSelected, COLORREF crBorder );

protected:
	virtual void			MeasureItem		( LPMEASUREITEMSTRUCT lpMIS );
	virtual void			DrawItem		( LPDRAWITEMSTRUCT lpDIS );

protected:
	class CContextMenuItem
	{
	public:
		CContextMenuItem(CString csText)
		{
			m_csText = csText;
#ifdef EnableCustomTreeSounds
			m_csWavFile = R"()";
#endif
		}
#ifdef EnableCustomTreeSounds
		CContextMenuItem( CString csText, CString csWavFile )
		{
			m_csText	= csText;
			m_csWavFile	= csWavFile;
		}
#endif

		~CContextMenuItem()
		{
			m_csText.Empty();
#ifdef EnableCustomTreeSounds
			m_csWavFile.Empty();
#endif
		}

		CString m_csText;
#ifdef EnableCustomTreeSounds
		CString m_csWavFile;
#endif
	};

	CPtrArray		m_cptrMenuItems;

	CFont*			m_pFont;

	int				m_iWidth;
	int				m_iHeight;

#ifdef EnableCustomTreeSounds
	BOOL			m_bSoundOn;
#endif

	COLORREF		m_crText, m_crBackground, m_crDisabled, m_crSelected, m_crBorder;
};

#endif
