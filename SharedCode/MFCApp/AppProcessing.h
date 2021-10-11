#pragma once

#include "MFCApp.h"
#include "../OtherFunctions/MFCMacrosV3.h"
#include "MFCView.h"
//#include "OtherFunctions/MFCMacrosV2.h"

class AppProcesser : public MFCApp<MFCView>
{
    MFC_RuntimeExtPart01Base01(AppProcesser, MFCApp, MFCView)
    //Any message map messages here
    MFC_RuntimeExtPart02(AppProcesser)
    //MFC_RuntimeExtClassNameWith01Args(AppProcesser, MFCApp, MFCViewV2)
};

#pragma region RuntimeCodeImplimentation
#ifdef MFCApp_UseMacroInsteadOfDirectCode
MFC_RuntimeImplimentation(AppProcesser)
#else
//const std::string AppProcesser::AppProcesserStr = AppProcesser::ClassString();
const CRuntimeClass AppProcesser::classAppProcesser = { "AppProcesser", sizeof(AppProcesser), 0xFFFF, NULL,&AppProcesser::_GetBaseClass, NULL, NULL };
#endif
#pragma endregion RuntimeCodeImplimentation
//MFC_RuntimeClassNameImpWith01Args(AppProcesser, MFCApp, MFCViewV2)

extern AppProcesser theApp;