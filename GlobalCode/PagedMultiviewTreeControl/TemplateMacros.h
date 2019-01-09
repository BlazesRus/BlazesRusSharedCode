#ifndef TemplateMacros_IncludeGuard
#define TemplateMacros_IncludeGuard
#pragma once

/*============================================================================*/
// Helper macros for declaring CRuntimeClass compatible classes with Template arguments added(adding 01 suffix to prevent conflicts with default AFX macros)

//(based off https://stackoverflow.com/questions/1491971/mfc-implement-dyncreate-with-template)
#define _RUNTIME_CLASS01(class_name, template_class) ((CRuntimeClass*)(&class_name<template_class>::class##class_name##_##template_class))
#ifdef _AFXDLL
#define RUNTIME_CLASS01(class_name, template_class) (class_name<template_class>::GetThisClass())
#else
#define RUNTIME_CLASS01(class_name, template_class) _RUNTIME_CLASS01(class_name, template_class)
#endif

#define _RUNTIME_CLASS02(class_name, template_class, template_class02) ((CRuntimeClass*)(&class_name<template_class,template_class02>::class##class_name##_##template_class##_##template_class02))
#ifdef _AFXDLL
#define RUNTIME_CLASS02(class_name, template_class, template_class02) (class_name<template_class, template_class02>::GetThisClass())
#else
#define RUNTIME_CLASS02(class_name, template_class, template_class02) _RUNTIME_CLASS02(class_name, template_class, template_class02)
#endif

#define _RUNTIME_CLASS03(class_name, template_class, template_class02, template_class03) ((CRuntimeClass*)(&class_name<template_class,template_class02,template_class03>::class##class_name##_##template_class##_##template_class02##_##template_class03))
#ifdef _AFXDLL
#define RUNTIME_CLASS03(class_name, template_class, template_class02, template_class03) (class_name<template_class, template_class02, template_class03>::GetThisClass())
#else
#define RUNTIME_CLASS03(class_name, template_class, template_class02, template_class03) _RUNTIME_CLASS03(class_name, template_class, template_class02, template_class03)
#endif

#define DEFINERTCNAME01(class_name, template_class) class##class_name##_##template_class
#define DEFINERTCNAME02(class_name, template_class, template_class02) class##class_name##_##template_class##_##template_class02
#define DEFINERTCNAME03(class_name, template_class, template_class02, template_class03) class##class_name##_##template_class##_##template_class02##_##template_class03
#define DEFINERTCINIT01(class_name, template_class) _init_##class_name##_##template_class
#define DEFINERTCNAME(class_name) class##class_name

//Use #define StaticTypeDefName(PrefixName, VariableName) type
#define StaticTypeDefName(PrefixName, VariableName) Prefixname##_##VariableName

//Altered version of Message map for those that use base class templates
#define BEGIN_AltMESSAGE_MAP() \
protected:\
static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
{\
		__pragma(warning(push))							   \
		__pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */ \
		static const AFX_MSGMAP_ENTRY _messageEntries[] =  \
		{
#define END_AltMESSAGE_MAP(baseClass) \
		{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
	}; \
	__pragma(warning(pop)) \
	static const AFX_MSGMAP messageMap = \
	{ &baseClass::GetThisMessageMap, &_messageEntries[0] };\
	return &messageMap;\
}\
public:\
	virtual const AFX_MSGMAP* GetMessageMap() const\
	{\
		return GetThisMessageMap();\
	}
#define END_AltMESSAGE_MAP_Base01(baseClass, baseargOne) \
		{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
	}; \
	__pragma(warning(pop)) \
	static const AFX_MSGMAP messageMap = \
	{ &baseClass<baseargOne>::GetThisMessageMap, &_messageEntries[0] };\
	return &messageMap;\
}\
public:\
	virtual const AFX_MSGMAP* GetMessageMap() const\
	{\
		return GetThisMessageMap();\
	}

#ifdef _AFXDLL
//based off of https://stackoverflow.com/questions/3004870/can-a-custom-mfc-window-dialog-be-a-class-template-instantiation + afx.h
#define CRuntime_Arg01(class_name, template_class, baseClass)\
private:\
	static std::string ClassString()\
	{\
		std::string Combined = "class_name<"; \
		Combined += typeid(template_class).name(); \
		Combined += ">"; \
		return Combined; \
	}\
public:\
	static const std::string classNameStr;\
	static LPCSTR ClassName() { return classNameStr.c_str(); }\
private:\
	typedef baseClass TheBaseClass;\
	typedef class_name<template_class> ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	CObject* PASCAL CreateObject() { return new class_name<template_class>; }\
	static const CRuntimeClass class##class_name##_##template_class;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS01(class_name, template_class); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS01(class_name, template_class); }

#define CRuntime_Arg01V2(class_name, template_class, baseClass)\
private:\
	static std::string ClassString()\
	{\
		std::string Combined = "class_name<"; \
		Combined += typeid(template_class).name(); \
		Combined += ">"; \
		return Combined; \
	}\
public:\
	static const std::string classNameStr;\
	static LPCSTR ClassName() { return classNameStr.c_str(); }\
private:\
	typedef baseClass TheBaseClass;\
	typedef class_name<template_class> ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	static const CRuntimeClass class##class_name##_##template_class;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS01(class_name, template_class); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS01(class_name, template_class); }

#define CRuntime_Arg02V2(class_name, template_class, template_class02, baseClass)\
private:\
	static std::string ClassString()\
	{\
		std::string Combined = "class_name<"; \
		Combined += typeid(template_class).name(); \
		Combined += ", ";\
		Combined += typeid(template_class02).name();\
		Combined += ">"; \
		return Combined; \
	}\
public:\
	static const std::string classNameStr;\
	static LPCSTR ClassName() { return classNameStr.c_str(); }\
private:\
	typedef baseClass TheBaseClass;\
	typedef class_name<template_class, template_class02> ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	static const CRuntimeClass class##class_name##_##template_class##_##template_class02;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS02(class_name, template_class, template_class02); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS02(class_name, template_class, template_class02); }

#define CRuntime_Arg03V2(class_name, template_class, template_class02, template_class03, baseClass)\
private:\
	static std::string ClassString()\
	{\
		std::string Combined = "class_name<"; \
		Combined += typeid(template_class).name(); \
		Combined += ", ";\
		Combined += typeid(template_class02).name();\
		Combined += ", ";\
		Combined += typeid(template_class03).name();\
		Combined += ">"; \
		return Combined; \
	}\
public:\
	static const std::string classNameStr;\
	static LPCSTR ClassName() { return classNameStr.c_str(); }\
private:\
	typedef baseClass TheBaseClass;\
	typedef class_name<template_class, template_class02, template_class03> ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	static const CRuntimeClass class##class_name##_##template_class##_##template_class02##_##template_class03;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS03(class_name, template_class, template_class02, template_class03); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS03(class_name, template_class, template_class02, template_class03); }

//Reusing template variables in base class for class_name<template_class, template_class02> : baseClass<template_class, template_class02, base_arg03>
#define CRuntime_Arg02Base03_Reused01(class_name, template_class, template_class02, baseClass, base_arg03)\
private:\
	static std::string ClassString()\
	{\
		std::string Combined = "class_name<"; \
		Combined += typeid(template_class).name(); \
		Combined += ", ";\
		Combined += typeid(template_class02).name();\
		Combined += ">"; \
		return Combined; \
	}\
public:\
	static const std::string classNameStr;\
	static LPCSTR ClassName() { return classNameStr.c_str(); }\
private:\
	typedef baseClass<template_class, template_class02, base_arg03> TheBaseClass;\
	typedef class_name<template_class, template_class02> ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	static const CRuntimeClass class##class_name##_##template_class##_##template_class02;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS02(class_name, template_class, template_class02); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS02(class_name, template_class, template_class02); }



#define CRuntime_Base01(class_name, baseClass, baseargOne)\
private:\
	typedef baseClass<baseargOne> TheBaseClass;\
	typedef class_name ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	CObject* PASCAL CreateObject() { return new class_name; }\
	static const CRuntimeClass class##class_name;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name); }

#define CRuntime_Base01V2(class_name, baseClass, baseargOne)\
private:\
	typedef baseClass<baseargOne> TheBaseClass;\
	typedef class_name ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	static const CRuntimeClass class##class_name;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name); }

#define CRuntime_Arg02Base01(class_name, template_class, template_class02, baseClass, baseargOne)\
private:\
	static std::string ClassString()\
	{\
		std::string Combined = "class_name<";\
		Combined += typeid(template_class).name();\
		Combined += ", ";\
		Combined += typeid(template_class02).name();\
		Combined += ">";\
		return Combined;\
	}\
public:\
	static const std::string classNameStr;\
	static LPCSTR ClassName() { return classNameStr.c_str(); }\
private:\
	typedef baseClass<baseargOne> TheBaseClass;\
	typedef class_name<template_class, template_class02> ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
	static const CRuntimeClass class##class_name##_##template_class##_##template_class02;\
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS02(class_name, template_class, template_class02); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS02(class_name, template_class, template_class02); }

#else
//based off of https://stackoverflow.com/questions/3004870/can-a-custom-mfc-window-dialog-be-a-class-template-instantiation + afx.h
#define CRuntime_Arg01(class_name, template_class, baseClass)\
private:\
	static std::string ClassString();\
public:\
	static const std::string classNameStr;\
	static LPCSTR ClassName() { return classNameStr.c_str(); }\
private:\
	typedef baseClass TheBaseClass;\
	typedef class_name<template_class> ThisClass;\
protected:\
	static const CRuntimeClass* PASCAL _GetBaseClass();\
public:\
	CObject* PASCAL CreateObject() { return new class_name<template_class>; }\
	static const CRuntimeClass class##class_name##_##template_class;\
	CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS01(class_name, template_class); }\
	CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS01(class_name, template_class); }\

#define CRuntime_Arg01V2(class_name, template_class, baseClass)\
private:\
	static std::string ClassString();\
public:\
	static const std::string classNameStr;\
	static LPCSTR ClassName() { return classNameStr.c_str(); }\
private:\
	typedef baseClass TheBaseClass;\
	typedef class_name<template_class> ThisClass;\
protected:\
	static const CRuntimeClass* PASCAL _GetBaseClass();\
public:\
	static const CRuntimeClass class##class_name##_##template_class;\
	CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS01(class_name, template_class); }\
	CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS01(class_name, template_class); }\

#define CRuntime_Base01(class_name, baseClass, baseargOne)\
private:\
	typedef baseClass<baseargOne> TheBaseClass;\
	typedef class_name ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return _RUNTIME_CLASS01(baseClass, baseargOne); } \
public:\
	CObject* PASCAL CreateObject() { return new class_name; }\
	static const CRuntimeClass class##class_name;\
	CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
	CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name); }\

#define CRuntime_Base01V2(class_name, baseClass, baseargOne)\
private:\
	typedef baseClass<baseargOne> TheBaseClass;\
	typedef class_name ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return _RUNTIME_CLASS01(baseClass, baseargOne); } \
public:\
	static const CRuntimeClass class##class_name;\
	CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
	CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name); }\

#endif

#ifdef _AFXDLL
#define CRuntimeImplimentation_Arg01(class_name, template_class)\
template <typename template_class>\
inline const std::string class_name<template_class>::classNameStr = ClassString();\
template <typename template_class>\
inline AFX_COMDAT const CRuntimeClass class_name<template_class>::DEFINERTCNAME01(class_name, template_class) = { ClassName(), sizeof(class_name<template_class>), 0xFFFF, NULL,&class_name<template_class>::_GetBaseClass, NULL, NULL };

#define CRuntimeImplimentation_Base01(class_name)\
inline AFX_COMDAT const CRuntimeClass class_name::DEFINERTCNAME(class_name) = { "class_name", sizeof(class_name), 0xFFFF, NULL,&class_name::_GetBaseClass, NULL, NULL };

#define CRuntimeImplimentation_Arg02(class_name, template_class, template_class02)\
template <typename template_class, typename template_class02>\
inline const std::string class_name<template_class, template_class02>::classNameStr = ClassString();\
template <typename template_class, typename template_class02>\
inline AFX_COMDAT const CRuntimeClass class_name<template_class, template_class02>::DEFINERTCNAME02(class_name, template_class, template_class02) = { ClassName(), sizeof(class_name<template_class, template_class02>), 0xFFFF, NULL,&class_name<template_class, template_class02>::_GetBaseClass, NULL, NULL };

#define CRuntimeImplimentation_Arg03(class_name, template_class, template_class02, template_class03)\
template <typename template_class, typename template_class02, typename template_class03>\
inline const std::string class_name<template_class, template_class02, template_class03>::classNameStr = ClassString();\
template <typename template_class, typename template_class02, typename template_class03>\
inline AFX_COMDAT const CRuntimeClass class_name<template_class, template_class02, template_class03>::DEFINERTCNAME03(class_name, template_class, template_class02, template_class03) = { ClassName(), sizeof(class_name<template_class, template_class02, template_class03>), 0xFFFF, NULL,&class_name<template_class, template_class02, template_class03>::_GetBaseClass, NULL, NULL };


#else
#define CRuntimeImplimentation_Arg01(class_name, template_class, baseClass)\
template <class TreeNode>\
std::string class_name<template_class>::ClassString()\
{\
	std::string Combined = "class_name<";\
	Combined += typeid(template_class).name();\
	Combined += ">";\
	return Combined;\
}\
template <class template_class>\
inline const std::string class_name<template_class>::classNameStr = ClassString();\
inline const CRuntimeClass* class_name::_GetBaseClass() { return _RUNTIME_CLASS01(baseClass, baseargOne); }\
template <class template_class>\
inline AFX_COMDAT const CRuntimeClass class_name<template_class>::DEFINERTCNAME01(class_name, template_class) = { ClassName(), sizeof(class_name<template_class>), 0xFFFF, NULL,&class_name<template_class>::_GetBaseClass, NULL, NULL };

#define CRuntimeImplimentation_Base01(class_name, template_class, baseClass)\
inline const CRuntimeClass* class_name::_GetBaseClass() { return _RUNTIME_CLASS01(baseClass, baseargOne); }\
inline AFX_COMDAT const CRuntimeClass class_name::DEFINERTCNAME(class_name) = { "class_name", sizeof(class_name), 0xFFFF, NULL,&class_name::_GetBaseClass, NULL, NULL };
#endif

#endif // TemplateMacros_IncludeGuard
