#pragma once

#ifndef __AFXWIN_H__
    #error "include 'MFCpch.h' before including this file for PCH"
#endif

#include "MFCApp.h"
#include "MFCView.h"
#include "OtherFunctions/MFCMacrosV2.h"

//Entry point for processing of the MFC based Application
class MFCAppProcesser : public MFCApp<MFCView>
{
	//CRuntime_Base01V2(MFCAppProcesser, MFCApp, XMLTagViewNode)//Might not be needed?
protected:
	//MFC_AltMessageMap_With1BaseArg(MFCAppProcesser, MFCApp, MFCView)
	/// <summary>
	/// Gets the this message map.
	/// </summary>
	/// <returns>const AFX_MSGMAP*</returns>
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()
	{
		//typedef MFCAppProcesser ThisClass;
		typedef MFCApp<MFCView> TheBaseClass;
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

inline AFX_COMDAT const CRuntimeClass MFCAppProcesser::classMFCAppProcesser = { "MFCAppProcesser", sizeof(MFCAppProcesser), 0xFFFF, NULL,&MFCAppProcesser::_GetBaseClass, NULL, NULL };

extern MFCAppProcesser theApp;
