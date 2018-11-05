#ifndef TemplateMacros_IncludeGuard
#define TemplateMacros_IncludeGuard
#pragma once

/*============================================================================*/
// Helper macros for declaring CRuntimeClass compatible classes with Template arguments added(adding 01 suffix to prevent conflicts with default AFX macros)

//https://stackoverflow.com/questions/1491971/mfc-implement-dyncreate-with-template
#define _RUNTIME_CLASS01(class_name, template_name) ((CRuntimeClass*)(&class_name<template_name>::class##class_name##template_name))
#define RUNTIME_CLASS01(class_name, template_name) _RUNTIME_CLASS01(class_name, template_name)

#ifdef _AFXDLL
#define DECLARE_DYNAMIC01(class_name, template_name) \
protected: \
	static CRuntimeClass* PASCAL _GetBaseClass(); \
public: \
	static const CRuntimeClass class##class_name<template_name>; \
	static CRuntimeClass* PASCAL GetThisClass(); \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define _DECLARE_DYNAMIC01(class_name, template_name) \
protected: \
	static CRuntimeClass* PASCAL _GetBaseClass(); \
public: \
	static CRuntimeClass class##class_name<template_name>; \
	static CRuntimeClass* PASCAL GetThisClass(); \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#else
#define DECLARE_DYNAMIC01(class_name, template_name) \
public: \
	static const CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define _DECLARE_DYNAMIC01(class_name, template_name) \
public: \
	static CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#endif

// not serializable, but dynamically constructable
#define DECLARE_DYNCREATE01(class_name, template_name) \
	DECLARE_DYNAMIC01(class_name, template_name) \
	static CObject* PASCAL CreateObject();

#define _DECLARE_DYNCREATE01(class_name, template_name) \
	_DECLARE_DYNAMIC01(class_name, template_name) \
	static CObject* PASCAL CreateObject();

#define DECLARE_SERIAL01(class_name, template_name) \
	_DECLARE_DYNCREATE01(class_name, template_name) \
	AFX_API friend CArchive& AFXAPI operator>>(CArchive& ar, class_name* &pOb);

#ifdef _AFXDLL
#define _IMPLEMENT_RUNTIMECLASS01( class_name, template_name, base_class_name, wSchema, pfnNew, class_init ) \
                                 AFX_COMDAT CRuntimeClass class_name<template_name>::class##class_name##template_name = { \
                                 #class_name, sizeof(class class_name<template_name>), wSchema, pfnNew, \
                                 RUNTIME_CLASS01(base_class_name, template_name), NULL, class_init }; \
                                 CRuntimeClass* class_name<template_class::GetRuntimeClass() const \
                                 { return RUNTIME_CLASS01(class_name, template_name); }

#define IMPLEMENT_DYNCREATE01( class_name, template_name, base_class_name ) \
                             CObject* PASCAL class_name<template_name>::CreateObject() \
                             { return new class_name<template_name>; } \
                             IMPLEMENT_RUNTIMECLASS01(class_name, template_name, base_class_name, 0xFFFF, \
                             class_name<template_name>::CreateObject, NULL)

#define IMPLEMENT_RUNTIMECLASS01(class_name, template_class, base_class_name, wSchema, pfnNew, class_init) \
	CRuntimeClass* PASCAL class_name::_GetBaseClass() \
		{ return RUNTIME_CLASS(base_class_name); } \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name<template_class>), wSchema, pfnNew, \
			&class_name::_GetBaseClass, NULL, class_init }; \
	CRuntimeClass* PASCAL class_name<template_class>::GetThisClass() \
		{ return _RUNTIME_CLASS(class_name<template_class>); } \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return _RUNTIME_CLASS(class_name<template_class>); }

#define _IMPLEMENT_RUNTIMECLASS01(class_name, template_class, base_class_name, wSchema, pfnNew, class_init) \
	CRuntimeClass* PASCAL class_name::_GetBaseClass() \
		{ return RUNTIME_CLASS(base_class_name); } \
	AFX_COMDAT CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			&class_name::_GetBaseClass, NULL, class_init }; \
	CRuntimeClass* PASCAL class_name::GetThisClass() \
		{ return _RUNTIME_CLASS(class_name); } \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return _RUNTIME_CLASS(class_name); }

#else
#define IMPLEMENT_RUNTIMECLASS01(class_name, template_class, base_class_name, wSchema, pfnNew, class_init) \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL, class_init }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); }

#define _IMPLEMENT_RUNTIMECLASS01(class_name, template_class, base_class_name, wSchema, pfnNew, class_init) \
	AFX_COMDAT CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL, class_init }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS(class_name); }

#endif

#define IMPLEMENT_DYNAMIC01(class_name, template_class, base_class_name) \
	IMPLEMENT_RUNTIMECLASS01(class_name, template_class, base_class_name, 0xFFFF, NULL, NULL)

#define IMPLEMENT_DYNCREATE01(class_name, template_class, base_class_name) \
	CObject* PASCAL class_name::CreateObject() \
		{ return new class_name; } \
	IMPLEMENT_RUNTIMECLASS01(class_name, base_class_name, 0xFFFF, \
		class_name::CreateObject, NULL)

#define IMPLEMENT_SERIAL01(class_name, base_class_name, wSchema) \
	CObject* PASCAL class_name::CreateObject() \
		{ return new class_name; } \
	extern AFX_CLASSINIT _init_##class_name; \
	_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, \
		class_name::CreateObject, &_init_##class_name) \
	AFX_CLASSINIT _init_##class_name(RUNTIME_CLASS(class_name)); \
	CArchive& AFXAPI operator>>(CArchive& ar, class_name* &pOb) \
		{ pOb = (class_name*) ar.ReadObject(RUNTIME_CLASS(class_name)); \
			return ar; }

#endif // TemplateMacros_IncludeGuard
