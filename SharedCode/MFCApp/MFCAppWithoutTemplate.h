#pragma once

#ifndef __AFXWIN_H__
    #error "include 'MFCpch.h' before including this file for PCH"
#endif

#include "MFCRes.h"       // main symbols

/// <summary>
/// MFC based template for generating applications with a single view (Include MFCAppProcesser.h to generate Application with default generic view type)
/// </summary>
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