
// MFCApp.h : main header file for the MFCApp application
//
#pragma once

#ifndef __AFXWIN_H__
    #error "include 'MFCpch.h' before including this file for PCH"
#endif

#include "MFCRes.h"       // main symbols


// MFCApp:
// See MFCApp.cpp for the implementation of this class
//

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

extern MFCApp theApp;
