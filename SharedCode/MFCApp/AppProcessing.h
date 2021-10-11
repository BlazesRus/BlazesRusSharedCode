#pragma once

#include "MFCApp.h"
#include "../OtherFunctions/MFCMacrosV3.h"
#include "MFCViewV2.h"
//#include "OtherFunctions/MFCMacrosV2.h"

class AppProcesser : public MFCApp<MFCViewV2>
{
#pragma region RuntimeCodePart01
#ifdef MFCApp_UseMacroInsteadOfDirectCode
	MFC_RuntimeExtPart01Base01(AppProcesser, MFCApp, MFCViewV2)
#else
private:
	typedef MFCApp<MFCViewV2> TheBaseClass;
	typedef AppProcesser ThisClass;
protected:
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); }
public:
	static const CRuntimeClass classAppProcesser;
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(AppProcesser); }
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(AppProcesser); }
protected:
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()
	{
		__pragma(warning(push))
			__pragma(warning(disable: 4640))
			static const AFX_MSGMAP_ENTRY _messageEntries[] =
		{
#endif
#pragma endregion RuntimeCodePart01
			//Any message map messages here
	#pragma region RuntimeCodePart02
	#ifdef MFCApp_UseMacroInsteadOfDirectCode
		MFC_RuntimeExtPart02(AppProcesser)
	#else
				{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
		};
		__pragma(warning(pop))
			static const AFX_MSGMAP messageMap =
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };
		return &messageMap;
	}
	static std::string ClassString()
	{
		return "AppProcesser";
	}
public:
	virtual const AFX_MSGMAP* GetMessageMap() const
	{
		return GetThisMessageMap();
	}
#endif
#pragma endregion RuntimeCodePart02
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