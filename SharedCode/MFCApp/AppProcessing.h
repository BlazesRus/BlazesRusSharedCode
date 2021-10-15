#pragma once

#include "MFCApp.h"
#include "MFCView.h"

#include "../OtherFunctions/MFCMacrosV3.h"
#include "../OtherFunctions/MFCBaseOneMacros.h"

class AppProcesser : public MFCApp<MFCView>
{
    MFC_RuntimeExtPart01Base01(AppProcesser, MFCApp, MFCView)
/*
protected:
    /// <summary>
    /// Gets the this message map.
    /// </summary>
    /// <returns>const AFX_MSGMAP*</returns>
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()
    {
        typedef AppProcesser ThisClass;
        typedef MFCApp<MFCView> TheBaseClass;
        __pragma(warning(push))
            __pragma(warning(disable: 4640))
            static const AFX_MSGMAP_ENTRY _messageEntries[] =
        {
*/
    //Any message map messages here
    MFC_RuntimeExtPart02()
/*
            { 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
        };
        __pragma(warning(pop))
            static const AFX_MSGMAP messageMap =
        { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };
        return &messageMap;
    }
public:
    /// <summary>
    /// Gets the message map.
    /// </summary>
    /// <returns>const AFX_MSGMAP *</returns>
    virtual const AFX_MSGMAP* GetMessageMap() const
    {
        return GetThisMessageMap();
    }
*/
    MFC_RuntimeExtClassName(AppProcesser)
};

MFC_RuntimeImplimentation(AppProcesser)
MFC_RuntimeClassImplimentation(AppProcesser)

extern AppProcesser theApp;