#pragma once

#ifndef __AFXWIN_H__
    #error "include 'MFCpch.h' before including this file for PCH"
#endif

#include "MFCDualViewApp.h"
#include "MFCView.h"

//Entry point for processing of the MFC based Application
class MFCDualViewProcesser : public MFCDualViewApp<MFCView, MFCView>
{
};

extern MFCDualViewProcesser theApp;
