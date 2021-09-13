/*============================================================================*/
// Helper macros for declaring CRuntimeClass compatible classes with Template arguments added
//(based off https://stackoverflow.com/questions/1491971/mfc-implement-dyncreate-with-template)
#pragma once
#define MFC_AltMessageMap_With1BaseArg(class_name, baseClass, baseArgOne)\
	/// <summary>\
	/// Gets the this message map.\
	/// </summary>\
	/// <returns>const AFX_MSGMAP*</returns>\
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
	{\
		typedef class_name ThisClass;\
		typedef baseClass<baseArgOne> TheBaseClass;\
		__pragma(warning(push))\
		__pragma(warning(disable: 4640))\
		static const AFX_MSGMAP_ENTRY _messageEntries[] =\
		{\
			{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }\
		};\
		__pragma(warning(pop))\
		static const AFX_MSGMAP messageMap =\
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };\
		return &messageMap;\
	}\
public:\
	/// <summary>\
	/// Gets the message map.\
	/// </summary>\
	/// <returns>const AFX_MSGMAP *</returns>\
	virtual const AFX_MSGMAP* GetMessageMap() const\
	{\
		return GetThisMessageMap();\
	}
	
#define MFC_AltMessageMap_With1ArgAnd1BaseArg(class_name, ArgOne, baseClass, baseArgOne)\
	/// <summary>\
	/// Gets the this message map.\
	/// </summary>\
	/// <returns>const AFX_MSGMAP*</returns>\
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
	{\
		typedef class_name<ArgOne> ThisClass;\
		typedef baseClass<baseArgOne> TheBaseClass;\
		__pragma(warning(push))\
		__pragma(warning(disable: 4640))\
		static const AFX_MSGMAP_ENTRY _messageEntries[] =\
		{\
			{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }\
		};\
		__pragma(warning(pop))\
		static const AFX_MSGMAP messageMap =\
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };\
		return &messageMap;\
	}\
public:\
	/// <summary>\
	/// Gets the message map.\
	/// </summary>\
	/// <returns>const AFX_MSGMAP *</returns>\
	virtual const AFX_MSGMAP* GetMessageMap() const\
	{\
		return GetThisMessageMap();\
	}