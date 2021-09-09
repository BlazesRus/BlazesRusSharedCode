#pragma once

#ifndef __AFXWIN_H__
    #error "include 'MFCpch.h' before including this file for PCH"
#endif

#include "MFCApp.h"
#include "MFCView.h"

//Entry point for processing of the MFC based Application
class MFCAppProcesser : public MFCApp<MFCView>
{
};

extern MFCAppProcesser theApp;
