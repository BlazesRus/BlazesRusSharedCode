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
	static const CRuntimeClass class##class_name##template_name; \
	static CRuntimeClass* PASCAL GetThisClass(); \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define _DECLARE_DYNAMIC01(class_name, template_name) \
protected: \
	static CRuntimeClass* PASCAL _GetBaseClass(); \
public: \
	static CRuntimeClass class##class_name##template_name; \
	static CRuntimeClass* PASCAL GetThisClass(); \
	virtual CRuntimeClass* GetRuntimeClass() const; \

//DECLARE_DYNAMIC01+IMPLEMENT_DYNCREATE01+IMPLEMENT_RUNTIMECLASS01 (For placing inside template header file)
/* (Errors here)
#define DECLAREFULL_DYNAMIC01(class_name, template_name, base_class_name) \
protected: \
	static CRuntimeClass* PASCAL _GetBaseClass() { return RUNTIME_CLASS(base_class_name); } \
public: \
	static const CRuntimeClass class##class_name##template_name; \
	static CRuntimeClass* PASCAL GetThisClass()	{ return _RUNTIME_CLASS01(class_name, template_class); } \
	virtual CRuntimeClass* GetRuntimeClass() const { return RUNTIME_CLASS01(class_name, template_name); }\
	CObject* PASCAL CreateObject() { return new class_name<template_name>; } \
	AFX_COMDAT const CRuntimeClass class##class_name##template_name = { \
	#class_name, sizeof(class class_name<template_class>), 0xFFFF, class_name<template_name>::CreateObject, \
	&class_name<template_class>::_GetBaseClass, NULL, NULL };
*/
#define DECLAREFULL_DYNAMIC01(class_name, template_name, base_class_name) \
protected: \
	static CRuntimeClass* PASCAL _GetBaseClass() { return RUNTIME_CLASS(base_class_name); } \
public: \
	static const CRuntimeClass class##class_name##template_name; \
	static CRuntimeClass* PASCAL GetThisClass()	{ return _RUNTIME_CLASS01(class_name, template_class); } \
	virtual CRuntimeClass* GetRuntimeClass() const { return RUNTIME_CLASS01(class_name, template_name); }\
	CObject* PASCAL CreateObject() { return new class_name<template_name>; }
    ////IMPLEMENT_RUNTIMECLASS01(class_name, template_name, base_class_name, 0xFFFF, \
    ////class_name<template_name>::CreateObject, NULL)
/* IMPLEMENT_RUNTIMECLASS01(class_name, template_class, base_class_name, wSchema, pfnNew, class_init)
	template < typename template_class > \
	CRuntimeClass* PASCAL class_name<template_class>::_GetBaseClass() \
		{ return RUNTIME_CLASS(base_class_name); } \
	template < typename template_class > \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name##template_name = { \
		#class_name, sizeof(class class_name<template_class>), 0xFFFF, class_name<template_name>::CreateObject, \
			&class_name<template_class>::_GetBaseClass, NULL, NULL }; \
	template < typename template_class > \
	CRuntimeClass* PASCAL class_name<template_class>::GetThisClass() \
		{ return _RUNTIME_CLASS01(class_name, template_class); } \
	template < typename template_class > \
	CRuntimeClass* class_name<template_class>::GetRuntimeClass() const \
		{ return _RUNTIME_CLASS01(class_name,template_class); }
*/

#define _IMPLEMENT_RUNTIMECLASS01( class_name, template_name, base_class_name, wSchema, pfnNew, class_init ) \
	template < typename template_class > \
    AFX_COMDAT CRuntimeClass class_name<template_name>::class##class_name##template_name = { \
    #class_name, sizeof(class class_name<template_name>), wSchema, pfnNew, \
    RUNTIME_CLASS01(base_class_name, template_name), NULL, class_init }; \
	template < typename template_class > \
    CRuntimeClass* class_name<template_class>::GetRuntimeClass() const \
    { return RUNTIME_CLASS01(class_name, template_name); }
#define _IMPLEMENT_RUNTIMECLASS01_Base01( class_name, template_name, base_class_name, wSchema, pfnNew, class_init ) \
	template < typename template_class > \
    AFX_COMDAT CRuntimeClass class_name<template_name>::class##class_name##template_name = { \
    #class_name, sizeof(class class_name<template_name>), wSchema, pfnNew, \
    RUNTIME_CLASS01(base_class_name, template_name), NULL, class_init }; \
	template < typename template_class > \
    CRuntimeClass* class_name<template_class>::GetRuntimeClass() const \
    { return RUNTIME_CLASS01(class_name, template_name); }

// not serializable, but dynamically constructable
#define DECLARE_DYNCREATE01(class_name, template_name) \
	DECLARE_DYNAMIC01(class_name, template_name) \
	static CObject* PASCAL CreateObject();

#define _DECLARE_DYNCREATE01(class_name, template_name) \
	_DECLARE_DYNAMIC01(class_name, template_name) \
	static CObject* PASCAL CreateObject();

#define DECLARE_SERIAL01(class_name, template_name) \
	_DECLARE_DYNCREATE01(class_name, template_name) \
	AFX_API friend CArchive& AFXAPI operator>>(CArchive& ar, class_name<template_class>* &pOb);

#define IMPLEMENT_DYNCREATE01( class_name, template_name, base_class_name ) \
	template < typename template_class > \
    CObject* PASCAL class_name<template_name>::CreateObject() \
    { return new class_name<template_name>; } \
    IMPLEMENT_RUNTIMECLASS01(class_name, template_name, base_class_name, 0xFFFF, \
    class_name<template_name>::CreateObject, NULL)
#define IMPLEMENT_DYNCREATE01_Base01( class_name, template_name, base_class_name, base_templateclass ) \
	template < typename template_class > \
    CObject* PASCAL class_name<template_name>::CreateObject() \
    { return new class_name<template_name>; } \
    IMPLEMENT_RUNTIMECLASS01_Base01(class_name, template_name, base_class_name, base_templateclass, 0xFFFF, \
    class_name<template_name>::CreateObject, NULL)

#define IMPLEMENT_RUNTIMECLASS01(class_name, template_class, base_class_name, wSchema, pfnNew, class_init) \
	template < typename template_class > \
	CRuntimeClass* PASCAL class_name<template_class>::_GetBaseClass() \
		{ return RUNTIME_CLASS(base_class_name); } \
	template < typename template_class > \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name##template_name = { \
		#class_name, sizeof(class class_name<template_class>), wSchema, pfnNew, \
			&class_name<template_class>::_GetBaseClass, NULL, class_init }; \
	template < typename template_class > \
	CRuntimeClass* PASCAL class_name<template_class>::GetThisClass() \
		{ return _RUNTIME_CLASS01(class_name, template_class); } \
	template < typename template_class > \
	CRuntimeClass* class_name<template_class>::GetRuntimeClass() const \
		{ return _RUNTIME_CLASS01(class_name,template_class); }
#define IMPLEMENT_RUNTIMECLASS01_Base01(class_name, template_class, base_class_name, base_templateclass, wSchema, pfnNew, class_init) \
	template < typename template_class > \
	CRuntimeClass* PASCAL class_name<template_class>::_GetBaseClass() \
		{ return RUNTIME_CLASS01(base_class_name, base_templateclass); } \
	template < typename template_class > \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name##template_name = { \
		#class_name, sizeof(class class_name<template_class>), wSchema, pfnNew, \
			&class_name<template_class>::_GetBaseClass, NULL, class_init }; \
	template < typename template_class > \
	CRuntimeClass* PASCAL class_name<template_class>::GetThisClass() \
		{ return _RUNTIME_CLASS01(class_name, template_class); } \
	template < typename template_class > \
	CRuntimeClass* class_name<template_class>::GetRuntimeClass() const \
		{ return _RUNTIME_CLASS01(class_name,template_class); }

#else
#define DECLARE_DYNAMIC01(class_name, template_name) \
public: \
	static const CRuntimeClass class##class_name##template_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define _DECLARE_DYNAMIC01(class_name, template_name) \
public: \
	static CRuntimeClass class##class_name##template_name; \
	virtual CRuntimeClass* GetRuntimeClass() const; \

#define IMPLEMENT_RUNTIMECLASS01(class_name, template_class, base_class_name, wSchema, pfnNew, class_init) \
	AFX_COMDAT const CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL, class_init }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS01(class_name, template_class); }

#define _IMPLEMENT_RUNTIMECLASS01(class_name, template_class, base_class_name, wSchema, pfnNew, class_init) \
	AFX_COMDAT CRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), wSchema, pfnNew, \
			RUNTIME_CLASS(base_class_name), NULL, class_init }; \
	CRuntimeClass* class_name::GetRuntimeClass() const \
		{ return RUNTIME_CLASS01(class_name, template_class); }

#endif

#define IMPLEMENT_DYNAMIC01(class_name, template_class, base_class_name) \
	IMPLEMENT_RUNTIMECLASS01(class_name, template_class, base_class_name, 0xFFFF, NULL, NULL)
#define IMPLEMENT_DYNAMIC01_Base01(class_name, template_class, base_class_name, base_templateclass) \
	IMPLEMENT_RUNTIMECLASS01(class_name, template_class, base_class_name, base_templateclass, 0xFFFF, NULL, NULL)

#define IMPLEMENT_SERIAL01(class_name, template_class, base_class_name, wSchema) \
	template < typename template_class > \
	CObject* PASCAL class_name<template_class>::CreateObject() \
		{ return new class_name<template_class>; } \
	template < typename template_class > \
	extern AFX_CLASSINIT _init_##class_name##template_class; \
	_IMPLEMENT_RUNTIMECLASS01(class_name, template_class, base_class_name, wSchema, \
		class_name<template_class>::CreateObject, &_init_##class_name##template_class) \
	AFX_CLASSINIT _init_##class_name(RUNTIME_CLASS01(class_name, template_class)); \
	template < typename template_class > \
	CArchive& AFXAPI operator>>(CArchive& ar, class_name<template_class>* &pOb) \
		{ pOb = (class_name<template_class>*) ar.ReadObject(RUNTIME_CLASS01(class_name, template_class)); \
			return ar; }
#define IMPLEMENT_SERIAL01_Base01(class_name, template_class, base_class_name, base_templateclass, wSchema) \
	template < typename template_class > \
	CObject* PASCAL class_name<template_class>::CreateObject() \
		{ return new class_name<template_class>; } \
	template < typename template_class > \
	extern AFX_CLASSINIT _init_##class_name##template_class; \
	_IMPLEMENT_RUNTIMECLASS01_Base01(class_name, template_class, base_class_name, base_templateclass, wSchema, \
		class_name<template_class>::CreateObject, &_init_##class_name##template_class) \
	AFX_CLASSINIT _init_##class_name(RUNTIME_CLASS01(class_name, template_class)); \
	template < typename template_class > \
	CArchive& AFXAPI operator>>(CArchive& ar, class_name<template_class>* &pOb) \
		{ pOb = (class_name<template_class>*) ar.ReadObject(RUNTIME_CLASS01(class_name, template_class)); \
			return ar; }

#endif // TemplateMacros_IncludeGuard
