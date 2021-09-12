#pragma once

#ifndef __AFXWIN_H__
    #error "include 'MFCpch.h' before including this file for PCH"
#endif

#include "MFCRes.h"       // main symbols

/// <summary>
/// MFC based template for generating applications with 2 different View types to switch between (Include MFCDualViewProcesser.h to generate Application with default generic view type)
/// </summary>
template <typename ViewType, typename ViewType02>
class MFCDualViewApp : public CWinApp
{
public:
    MFCDualViewApp() noexcept;


// Overrides
public:
    virtual BOOL InitInstance();

// Implementation
    UINT  m_nAppLook;
    BOOL  m_bHiColorIcons;

    afx_msg void OnAppAbout();
    DECLARE_MESSAGE_MAP()
};
