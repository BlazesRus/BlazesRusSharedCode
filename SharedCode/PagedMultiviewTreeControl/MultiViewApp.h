// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#if !defined(AFX_MultiViewApp_INCLUDED)
#define AFX_MultiViewApp_INCLUDED

#include "MultiviewPrecompile.h"

#ifndef __AFXWIN_H__
	#error include 'MultiviewPrecompile.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "HalfPagedMultiview.h"

#include "MainFrm.h"
#include "OtherView.h"
#include "TreePage.h"

#include <IniData/IniDataV2.h>

/////////////////////////////////////////////////////////////////////////////
// CMultiViewApp:
// See MultiView.cpp for the implementation of this class
//

/// <summary>
/// Class named MultiViewApp.
/// Implements the <see cref="HalfPagedMultiview{MainFrameView, TreePage, MainFrame}" />
/// </summary>
/// <seealso cref="HalfPagedMultiview{MainFrameView, TreePage, MainFrame}" />
class MultiViewApp : public HalfPagedMultiview<MainFrameView, TreePage, MainFrame>
{
//private:
//	static std::string ClassString() { return "MultiViewApp"; }
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="MultiViewApp"/> class.
	/// </summary>
	MultiViewApp() {};
	/// <summary>
	/// The INI settings
	/// </summary>
	IniDataV2 IniSettings;
private:
	/// <summary>
	/// Edit this virtual function inside Derived Class with method void InitializationCode() defined to run edit code thats run just before displays main view on InitInstance()
	/// </summary>
	void InitializationCode()
	{
	}
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiViewApp)
	//public:
	//virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMultiViewApp)
	//afx_msg void OnAppAbout();
	//afx_msg void OnViewOtherview();
	//afx_msg void OnViewFirstview();
	////}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern MultiViewApp theApp;
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
