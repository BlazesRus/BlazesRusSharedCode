// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#ifndef MainFrameView_IncludeGuard
#define MainFrameView_IncludeGuard

#include "MultiviewPrecompile.h"
#include "GenericFrameView.h"
#include "MultiViewDoc.h"
#include "../OtherFunctions/MFCMacrosV3.h"


/// <summary>
/// Class MFView.
/// Implements the <see cref="GenericFrameView{MultiViewDoc}" />
/// </summary>
/// <seealso cref="GenericFrameView{MultiViewDoc}" />
class MFView : public GenericFrameView<MultiViewDoc>
{
    MFView()
    {
        //ViewName = "Main View";
    }
    ~MFView() {}

    MFC_RuntimeExtPart01Base01(MFView, GenericFrameView, MultiViewDoc)
    //Any message map messages here
    MFC_RuntimeExtPart02(MFView)
};

MFC_RuntimeImplimentation(MFView)

#endif