#pragma once

#include "MFCApp.h"
#include "TextView.h"

/// <summary>
/// MFC Application for viewing content of any files(preferably text files) (Mostly just an app for testing of features)
/// </summary>
class TextViewProcesser : public MFCApp<TextView>
{
protected://BEGIN_AltMESSAGE_MAP()
    /// <summary>
    /// Gets the this message map.
    /// </summary>
    /// <returns>const AFX_MSGMAP*</returns>
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()
    {
        typedef TextViewProcesser ThisClass;
        typedef MFCApp<TextView> TheBaseClass;
        __pragma(warning(push))
        __pragma(warning(disable: 4640))
        static const AFX_MSGMAP_ENTRY _messageEntries[] =
        {
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
};

extern TextViewProcesser theApp;