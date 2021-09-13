#pragma once

#ifndef __AFXWIN_H__
    #error "include 'MFCpch.h' before including this file for PCH"
#endif

#include "MFCPagedViewApp.h"
#include "MFCView.h"
#include "OtherFunctions/MFCMacrosV2.h"

//Entry point for processing of the MFC based Application
class MFCPaggedViewProcesser : public MFCPagedViewApp<MFCView>
{
protected:
	MFC_AltMessageMap_With1BaseArg(MFCPaggedViewProcesser, MFCPagedViewApp, MFCView)
};

inline AFX_COMDAT const CRuntimeClass MFCPaggedViewProcesser::classMFCPaggedViewProcesser = { "MFCPaggedViewProcesser", sizeof(MFCPaggedViewProcesser), 0xFFFF, NULL,&MFCPaggedViewProcesser::_GetBaseClass, NULL, NULL };

extern MFCPaggedViewProcesser theApp;
