/*============================================================================*/
// Steamlined full runtime helper macros for declaring CRuntimeClass compatible classes
//(based off https://stackoverflow.com/questions/1491971/mfc-implement-dyncreate-with-template)
#ifndef MFCMacrosV3_IncludeGuard
#define MFCMacrosV3_IncludeGuard
#pragma once

/*
class class_name: public baseClass
{
	class_name(){}
	~class_name(){}
	//And other class stuff
	MFC_RuntimeExtPart01(class_name, baseClass)
	//Any message map messages here
	MFC_RuntimeExtPart02(class_name, baseClass)
};

MFC_RuntimeImplimentation(class_name)
*/
#define MFC_RuntimeExtPart01(class_name, baseClass)\
private:\
	typedef baseClass TheBaseClass;\
	typedef class_name ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	static const CRuntimeClass class##class_name;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name); }\
protected:\
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
	{\
		typedef class_name ThisClass;\
		typedef baseClass TheBaseClass;\
		__pragma(warning(push))\
		__pragma(warning(disable: 4640))\
		static const AFX_MSGMAP_ENTRY _messageEntries[] =\
		{

#define MFC_RuntimeExtPart02(class_name, baseClass)\
			{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }\
		};\
		__pragma(warning(pop))\
		static const AFX_MSGMAP messageMap =\
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };\
		return &messageMap;\
	}\
	static std::string ClassString()\
	{\
		return "class_name";\
	}\
public:\
	virtual const AFX_MSGMAP* GetMessageMap() const\
	{\
		return GetThisMessageMap();\
	}\
public:\
	static const std::string class_nameStr;\
	static LPCSTR ClassName() { return classNameStr.c_str(); }\
private:\
	typedef baseClass TheBaseClass;\
	typedef class_name ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	static const CRuntimeClass classclass_name;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name);}

/*
class class_name: public baseClass<baseArg01>
{
	class_name(){}
	~class_name(){}
	//And other class stuff
	MFC_RuntimeExtPart01Base01(class_name, baseClass, baseArg01)
	//Any message map messages here
	MFC_RuntimeExtPart02Base01(class_name, baseClass, baseArg01)
};

MFC_RuntimeImplimentation(class_name)
*/
#define MFC_RuntimeExtPart01Base01(class_name, baseClass, baseArg01)\
private:\
	typedef baseClass<baseArg01> TheBaseClass;\
	typedef class_name ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	static const CRuntimeClass class##class_name;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name); }\
protected:\
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
	{\
		typedef class_name ThisClass;\
		typedef baseClass<baseArg01> TheBaseClass;\
		__pragma(warning(push))\
		__pragma(warning(disable: 4640))\
		static const AFX_MSGMAP_ENTRY _messageEntries[] =\
		{

#define MFC_RuntimeExtPart02Base01(class_name, baseClass, baseArg01)\
			{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }\
		};\
		__pragma(warning(pop))\
		static const AFX_MSGMAP messageMap =\
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };\
		return &messageMap;\
	}\
	static std::string ClassString()\
	{\
		return "class_name";\
	}\
public:\
	virtual const AFX_MSGMAP* GetMessageMap() const\
	{\
		return GetThisMessageMap();\
	}\
public:\
	static const std::string class_nameStr;\
	static LPCSTR ClassName() { return classNameStr.c_str(); }\
private:\
	typedef baseClass<baseArg01> TheBaseClass;\
	typedef class_name ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	static const CRuntimeClass classclass_name;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name);}

/*
class class_name: public baseClass<baseArg01, baseArg02>
{
	class_name(){}
	~class_name(){}
	//And other class stuff
	
	MFC_RuntimeExtPart01Base02(class_name, baseClass, baseArg01, baseArg02)
	//Any message map messages here
	MFC_RuntimeExtPart02Base02(class_name, baseClass, baseArg01, baseArg02)
};

MFC_RuntimeImplimentation(class_name)
*/
#define MFC_RuntimeExtPart01Base02(class_name, baseClass, baseArg01, baseArg02)\
private:\
	typedef baseClass<baseArg01, baseArg02> TheBaseClass;\
	typedef class_name ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	static const CRuntimeClass class##class_name;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name); }\
protected:\
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
	{\
		typedef class_name ThisClass;\
		typedef baseClass<baseArg01, baseArg02> TheBaseClass;\
		__pragma(warning(push))\
		__pragma(warning(disable: 4640))\
		static const AFX_MSGMAP_ENTRY _messageEntries[] =\
		{

#define MFC_RuntimeExtPart02Base02(class_name, baseClass, baseArg01, baseArg02)\
			{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }\
		};\
		__pragma(warning(pop))\
		static const AFX_MSGMAP messageMap =\
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };\
		return &messageMap;\
	}\
	static std::string ClassString()\
	{\
		return "class_name";\
	}\
public:\
	virtual const AFX_MSGMAP* GetMessageMap() const\
	{\
		return GetThisMessageMap();\
	}\
public:\
	static const std::string class_nameStr;\
	static LPCSTR ClassName() { return classNameStr.c_str(); }\
private:\
	typedef baseClass<baseArg01, baseArg02> TheBaseClass;\
	typedef class_name ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	static const CRuntimeClass classclass_name;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name);}

#define MFC_RuntimeImplimentation(class_name)\
const std::string class_name::class_nameStr = class_name::class_nameStr;\
const CRuntimeClass class_name::classclass_name = { "class_name", sizeof(class_name), 0xFFFF, NULL,&class_name::_GetBaseClass, NULL, NULL };

#define MFC_RuntimeImplimentation_WithArg01(class_name,templateArg01)\
const std::string class_name::class_nameStr = class_name::class_name##_##templateArg01Str;\
const CRuntimeClass class_name::classclass_name = { "class_name", sizeof(class_name), 0xFFFF, NULL,&class_name::_GetBaseClass, NULL, NULL };

#endif
