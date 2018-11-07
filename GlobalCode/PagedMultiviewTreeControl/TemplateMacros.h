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

#endif // TemplateMacros_IncludeGuard
