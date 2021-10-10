#if !defined(MultiviewAboutDlg_Included)
#define MultiviewAboutDlg_Included
#pragma once

#include "MultiviewPrecompile.h"

#ifndef __AFXWIN_H__
#error "include 'MultiviewPrecompile.h' before including this file for PCH"
#endif

#if !defined(BehaviorFileEditorSpeced)
#include "resource.h"       // main symbols
#endif

#if !defined(IDD_ABOUTBOX)
#define IDD_ABOUTBOX                    100
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class AboutDlg : public CDialog
{
public:
    AboutDlg() : CDialog(AboutDlg::IDD)
    {
        //{{AFX_DATA_INIT(CAboutDlg)
        //}}AFX_DATA_INIT
    }

    // Dialog Data
        //{{AFX_DATA(CAboutDlg)
    enum { IDD = IDD_ABOUTBOX };
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CAboutDlg)
protected:
    virtual void DoDataExchange(CDataExchange* pDX)
    {
        CDialog::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CAboutDlg)
        //}}AFX_DATA_MAP
    }    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    //{{AFX_MSG(CAboutDlg)
        // No message handlers
    //}}AFX_MSG
protected://DECLARE_MESSAGE_MAP()
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()
    {
        __pragma(warning(push))
        __pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */
        static const AFX_MSGMAP_ENTRY _messageEntries[] =
        {
            //	//{{AFX_MSG_MAP(CAboutDlg)
            //		// No message handlers
            //	//}}AFX_MSG_MAP
            {	0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
        };
        __pragma(warning(pop))
            static const AFX_MSGMAP messageMap =
        { &CDialog::GetThisMessageMap, &_messageEntries[0] };
        return &messageMap;
    }

public:
    virtual const AFX_MSGMAP* GetMessageMap() const
    {
        return GetThisMessageMap();
    }
};

#endif
