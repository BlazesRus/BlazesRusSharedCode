#ifndef TemplateMacros_IncludeGuard
#define TemplateMacros_IncludeGuard
#pragma once

/*============================================================================*/
// Helper macros for declaring CRuntimeClass compatible classes with Template arguments added(adding 01 suffix to prevent conflicts with default AFX macros)

//(based off https://stackoverflow.com/questions/1491971/mfc-implement-dyncreate-with-template)
#define _RUNTIME_CLASS01(class_name, template_class) ((CRuntimeClass*)(&class_name<template_class>::class##class_name##_##template_class))
#define RUNTIME_CLASS01(class_name, template_class) _RUNTIME_CLASS01(class_name, template_class)

#define DEFINERTCNAME01(class_name, template_class) class##class_name##_##template_class
#define DEFINERTCNAME01Define(class_name, template_class) class##class_name##_##template_class
#define DEFINERTCINIT01(class_name, template_class) _init_##class_name##_##template_class

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

#define CRuntimeMPT01_Arg01(class_name, template_class, baseClass)\
private:\
	static LPCSTR ClassName() { return TEXT("class_name" + "<" + typeid(template_class).name() + ">"); }\
	typedef baseClass TheBaseClass;\
	typedef class_name<template_class> ThisClass;\
protected:\
	static CRuntimeClass* PASCAL _GetBaseClass() { return RUNTIME_CLASS(baseClass); }\
public:\
	CObject* PASCAL CreateObject() { return new class_name<template_class>; }

#define CRuntimeMPT01_Base01(class_name, baseClass, baseargOne)\
private:\
	static LPCSTR ClassName() { return TEXT("class_name"); }\
	typedef baseClass<baseargOne> TheBaseClass;\
	typedef class_name ThisClass;\
public:\
	CObject* PASCAL CreateObject() { return new class_name; }
//I"ll need to fix CRuntimeClass part before adding this part
//protected:
//	static CRuntimeClass* PASCAL _GetBaseClass() { return RUNTIME_CLASS01(baseClass,baseargOne); }

#endif // TemplateMacros_IncludeGuard
