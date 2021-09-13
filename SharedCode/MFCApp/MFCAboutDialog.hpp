#pragma once

//#include "MFCpch.h"

/// <summary>
/// Class named MFCAboutDlg that is used as to generate the dialog used for App About.
/// Implements the <see cref="CDialogEx" />
/// </summary>
class MFCAboutDlg : public CDialogEx
{
public:
    MFCAboutDlg() noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
    DECLARE_MESSAGE_MAP()
};

MFCAboutDlg::MFCAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void MFCAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MFCAboutDlg, CDialogEx)
END_MESSAGE_MAP()