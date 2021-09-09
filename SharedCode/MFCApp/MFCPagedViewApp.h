#pragma once

#ifndef __AFXWIN_H__
    #error "include 'MFCpch.h' before including this file for PCH"
#endif

#include "MFCRes.h"       // main symbols
#include "MFCView.h"//Default view type

// MFCApp:
// See MFCApp.cpp for the implementation of this class
//

template <typename ViewType=MFCView>
class MFCApp : public CWinApp
{
public:
    MFCApp() noexcept;


// Overrides
public:
    virtual BOOL InitInstance();

// Implementation
    UINT  m_nAppLook;
    BOOL  m_bHiColorIcons;

    afx_msg void OnAppAbout();
    DECLARE_MESSAGE_MAP()
};

//extern MFCApp theApp;
