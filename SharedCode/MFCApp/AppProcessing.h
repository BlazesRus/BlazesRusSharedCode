#pragma once

#include "MFCApp.h"
#include "../OtherFunctions/MFCMacrosV3.h"
#include "../OtherFunctions/MFCBaseOneMacros.h"
#include "MFCView.h"
//#include "OtherFunctions/MFCMacrosV2.h"

class AppProcesser : public MFCApp<MFCView>
{
    MFC_RuntimeExtPart01Base01(AppProcesser, MFCApp, MFCView)
    //Any message map messages here
    MFC_RuntimeExtPart02(AppProcesser)
    //MFC_RuntimeExtClassNameWith01Args(AppProcesser, MFCApp, MFCViewV2)
};

MFC_RuntimeImplimentation(AppProcesser)
MFC_RuntimeClassImplimentation(AppProcesser)

extern AppProcesser theApp;