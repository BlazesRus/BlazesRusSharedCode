/*============================================================================*/
// Streamlined full runtime helper macros for declaring CRuntimeClass compatible classes
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
    MFC_RuntimeExtPart02(class_name)
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
    static const std::string class_nameStr;\
    static LPCSTR ClassName() { return class_nameStr.c_str(); }\
    static const CRuntimeClass class##class_name;\
    static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
    virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name); }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {

#define MFC_RuntimeExtPart02(class_name)\
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
    }

/*
class class_name: public baseClass<baseArg01>
{
    class_name(){}
    ~class_name(){}
    //And other class stuff
    MFC_RuntimeExtPart01Base01(class_name, baseClass, baseArg01)
    //Any message map messages here
    MFC_RuntimeExtPart02(class_name)
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
    static LPCSTR ClassName() { return class_name##Str.c_str(); }\
    static const CRuntimeClass class##class_name;\
    static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
    virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name); }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {

/*
class class_name: public baseClass<baseArg01, baseArg02>
{
    class_name(){}
    ~class_name(){}
    //And other class stuff
    
    MFC_RuntimeExtPart01Base02(class_name, baseClass, baseArg01, baseArg02)
    //Any message map messages here
    MFC_RuntimeExtPart02(class_name)
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
    static LPCSTR ClassName() { return class_nameStr.c_str(); }\
    static const CRuntimeClass class##class_name;\
    static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(class_name); }\
    virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(class_name); }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {

#define MFC_RuntimeImplimentation(class_name)\
const std::string class_name::class_name##Str = class_name::class_nameStr;\
const CRuntimeClass class_name::class##class_name = { "class_name", sizeof(class_name), 0xFFFF, NULL,&class_name::_GetBaseClass, NULL, NULL };

#define MFC_RuntimeImplimentationWith01Args(class_name,arg01)\
const std::string class_name::class_nameStr = class_name::class_name##_##arg01Str;\
const CRuntimeClass class_name::class##class_name_##arg01 = { "class_name<arg01>", sizeof(class_name<arg01>), 0xFFFF, NULL,&class_name::_GetBaseClass, NULL, NULL };

#define MFC_RuntimeImplimentationWith02Args(class_name,arg01,arg02)\
const std::string class_name::class_name_##arg01_##arg02Str = class_name::class_name##_##arg01##_##arg02Str;\
const CRuntimeClass class_name::class##class_name_##arg01_##arg02 = { "class_name<arg01,arg02>", sizeof(class_name<arg01,arg02>), 0xFFFF, NULL,&class_name::_GetBaseClass, NULL, NULL };

/*
template<typename arg01>
class class_name: public baseClass
{
    class_name(){}
    ~class_name(){}
    //And other class stuff
    MFC_RuntimeExtPart01With01Args(class_name, arg01, baseClass)
    //Any message map messages here
    MFC_RuntimeExtPart02With01Args(class_name, arg01)
};

MFC_RuntimeImplimentationWith01Args(class_name, arg01)
*/
#define MFC_RuntimeExtPart01With01Args(class_name, arg01, baseClass)\
private:\
    typedef baseClass TheBaseClass;\
    typedef class_name<arg01> ThisClass;\
protected:\
    static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
    static const std::string class_name##_##arg01##Str;\
    static LPCSTR ClassName() { return class_name##_##arg01##Str.c_str(); }\
    static const CRuntimeClass class##class_name##_##arg01;\
    static CRuntimeClass* PASCAL GetThisClass() { return ((CRuntimeClass*)(&class_name<arg01>::class##class_name##_##arg01)) }\
    virtual CRuntimeClass* GetRuntimeClass() const { return ((CRuntimeClass*)(&class_name<arg01>::class##class_name##_##arg01)) }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {

#define MFC_RuntimeExtPart02With01Args(class_name, arg01)\
            { 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }\
        };\
        __pragma(warning(pop))\
        static const AFX_MSGMAP messageMap =\
        { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };\
        return &messageMap;\
    }\
    static std::string ClassString()\
    {\
        std::string Combined = "class_name<"; \
        Combined += typeid(arg01).name(); \
        Combined += ">"; \
        return Combined; \
    }\
public:\
    virtual const AFX_MSGMAP* GetMessageMap() const\
    {\
        return GetThisMessageMap();\
    }
    
/*
template<typename arg01>
class class_name: public baseClass
{
    class_name(){}
    ~class_name(){}
    //And other class stuff
    MFC_RuntimeExtPart01With02Args(class_name, arg01, arg02, baseClass)
    //Any message map messages here
    MFC_RuntimeExtPart02With02Args(class_name, arg01, arg02)
};

MFC_RuntimeImplimentationWith02Args(class_name, arg01, arg02)
*/
#define MFC_RuntimeExtPart01With02Args(class_name, arg01, arg02, baseClass)\
private:\
    typedef baseClass TheBaseClass;\
    typedef class_name<arg01, arg02> ThisClass;\
protected:\
    static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
    static const std::string class_name##_##arg01##_##arg02##Str;\
    static LPCSTR ClassName() { return class_name##_##arg01##_##arg02##Str.c_str(); }\
    static const CRuntimeClass class##class_name##_##arg01##_##arg02;\
    static CRuntimeClass* PASCAL GetThisClass() { return ((CRuntimeClass*)(&class_name<arg01>::class##class_name##_##arg01##_##arg02)) }\
    virtual CRuntimeClass* GetRuntimeClass() const { return ((CRuntimeClass*)(&class_name<arg01>::class##class_name##_##arg01##_##arg02)) }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {

#define MFC_RuntimeExtPart02With02Args(class_name, arg01, arg02)\
            { 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }\
        };\
        __pragma(warning(pop))\
        static const AFX_MSGMAP messageMap =\
        { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };\
        return &messageMap;\
    }\
    static std::string ClassString()\
    {\
        std::string Combined = "class_name<"; \
        Combined += typeid(arg01).name(); \
        Combined += ", "; \
        Combined += typeid(arg02).name(); \
        Combined += ">"; \
        return Combined; \
    }\
public:\
    virtual const AFX_MSGMAP* GetMessageMap() const\
    {\
        return GetThisMessageMap();\
    }

#endif
