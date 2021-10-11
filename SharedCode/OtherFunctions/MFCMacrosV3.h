/*============================================================================*/
// Streamlined full runtime helper macros for declaring CRuntimeClass compatible classes
//(based off https://stackoverflow.com/questions/1491971/mfc-implement-dyncreate-with-template)
#ifndef MFCMacrosV3_IncludeGuard
#define MFCMacrosV3_IncludeGuard
#pragma once

#include <string>
/*
class className: public baseClass
{
    className(){}
    ~className(){}
    //And other class stuff
    MFC_RuntimeExtPart01(className, baseClass)
    //Any message map messages here
    MFC_RuntimeExtPart02(className, baseClass, baseArg01, baseArg02)
    //MFC_RuntimeExtClassName(className, arg01)//If need ClassName info
};

MFC_RuntimeImplimentation(className, arg01)
//MFC_RuntimeClassImplimentation(className, arg01)//If need ClassName info
*/
#define MFC_RuntimeExtPart01(className, baseClass)\
private:\
    typedef baseClass TheBaseClass;\
    typedef className ThisClass;\
protected:\
    static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
    static const CRuntimeClass class##className;\
    static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(className); }\
    virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(className); }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {

#define MFC_RuntimeExtPart02(className)\
            { 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }\
        };\
        __pragma(warning(pop))\
        static const AFX_MSGMAP messageMap =\
        { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };\
        return &messageMap;\
    }\
    static std::string ClassString()\
    {\
        return "className";\
    }\
public:\
    virtual const AFX_MSGMAP* GetMessageMap() const\
    {\
        return GetThisMessageMap();\
    }

#define MFC_RuntimeExtClassName(className)\
protected:\
    static std::string ClassString()\
    {\
        return "className"; \
    }\
public:\
    static const std::string classNameStr;\
    static LPCSTR ClassName() { return classNameStr.c_str(); }

#define MFC_RuntimeClassImplimentation(className)\
const std::string className::classNameStr = className::ClassString();

#define MFC_RuntimeImplimentation(className)\
const CRuntimeClass className::class##className = { "className", sizeof(className), 0xFFFF, NULL,&className::_GetBaseClass, NULL, NULL };

/*
class className: public baseClass<baseArg01>
{
    className(){}
    ~className(){}
    //And other class stuff
    MFC_RuntimeExtPart01Base01(className, baseClass, baseArg01)
    //Any message map messages here
    MFC_RuntimeExtPart02(className, baseClass, baseArg01, baseArg02)
    //MFC_RuntimeExtClassName(className, arg01)//If need ClassName info
};

MFC_RuntimeImplimentation(className, arg01)
//MFC_RuntimeClassImplimentation(className, arg01)//If need ClassName info
*/
#define MFC_RuntimeExtPart01Base01(className, baseClass, baseArg01)\
private:\
    typedef baseClass<baseArg01> TheBaseClass;\
    typedef className ThisClass;\
protected:\
    static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
    static const CRuntimeClass class##className;\
    static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(className); }\
    virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(className); }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {

/*
class className: public baseClass<baseArg01, baseArg02>
{
    className(){}
    ~className(){}
    //And other class stuff
    
    MFC_RuntimeExtPart01Base02(className, baseClass, baseArg01, baseArg02)
    //Any message map messages here
    MFC_RuntimeExtPart02(className, baseClass, baseArg01, baseArg02)
    //MFC_RuntimeExtClassName(className, arg01)//If need ClassName info
};

MFC_RuntimeImplimentation(className, arg01)
//MFC_RuntimeClassImplimentation(className, arg01)//If need ClassName info
*/
#define MFC_RuntimeExtPart01Base02(className, baseClass, baseArg01, baseArg02)\
private:\
    typedef baseClass<baseArg01, baseArg02> TheBaseClass;\
    typedef className ThisClass;\
protected:\
    static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
    static const CRuntimeClass class##className;\
    static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(className); }\
    virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(className); }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {

#define MFC_RuntimeImplimentationWith01Args(className,arg01)\
const CRuntimeClass className::class##className_##arg01 = { "className<arg01>", sizeof(className<arg01>), 0xFFFF, NULL,&className::_GetBaseClass, NULL, NULL };

#define MFC_RuntimeImplimentationWith02Args(className,arg01,arg02)\
const CRuntimeClass className::class##className_##arg01_##arg02 = { "className<arg01,arg02>", sizeof(className<arg01,arg02>), 0xFFFF, NULL,&className::_GetBaseClass, NULL, NULL };

/*
template<typename arg01>
class className: public baseClass
{
    className(){}
    ~className(){}
    //And other class stuff
    MFC_RuntimeExtPart01With01Args(className, arg01, baseClass)
    //Any message map messages here
    MFC_RuntimeExtPart02With01Args(className, arg01)
    //MFC_RuntimeExtClassNameWith01Args(className, arg01)//If need ClassName info
};

MFC_RuntimeImplimentationWith01Args(className, arg01)
//MFC_RuntimeClassImplimentationWith01Args(className, arg01)//If need ClassName info
*/
#define MFC_RuntimeExtPart01With01Args(className, arg01, baseClass)\
private:\
    typedef className<arg01> ThisClass;\
    typedef baseClass TheBaseClass;\
protected:\
    static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
    static const CRuntimeClass class##className##_##arg01;\
    static CRuntimeClass* PASCAL GetThisClass() { return ((CRuntimeClass*)(&className<arg01>::class##className##_##arg01)) }\
    virtual CRuntimeClass* GetRuntimeClass() const { return ((CRuntimeClass*)(&className<arg01>::class##className##_##arg01)) }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {

#define MFC_RuntimeExtClassNameWith01Args(className, arg01)\
protected:\
    static std::string ClassString()\
    {\
        std::string Combined = "className<"; \
        Combined += typeid(arg01).name(); \
        Combined += ">"; \
        return Combined; \
    }\
public:\
    static const std::string className##_##arg01Str;\
    static LPCSTR ClassName() { return className##_##arg01##Str.c_str(); }

#define MFC_RuntimeClassImplimentationWith01Args(className, arg01)\
const std::string className::className##_##arg01Str = className::ClassString();

/*
template<typename arg01>
class className: public baseClass
{
    className(){}
    ~className(){}
    //And other class stuff
    MFC_RuntimeExtPart01With02Args(className, arg01, arg02, baseClass)
    //Any message map messages here
    MFC_RuntimeExtPart02With02Args(className, arg01, arg02)
};

MFC_RuntimeImplimentationWith02Args(className, arg01, arg02)
*/
#define MFC_RuntimeExtPart01With02Args(className, arg01, arg02, baseClass)\
private:\
    typedef baseClass TheBaseClass;\
    typedef className<arg01, arg02> ThisClass;\
protected:\
    static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
    static const CRuntimeClass class##className##_##arg01##_##arg02;\
    static CRuntimeClass* PASCAL GetThisClass() { return ((CRuntimeClass*)(&className<arg01>::class##className##_##arg01##_##arg02)) }\
    virtual CRuntimeClass* GetRuntimeClass() const { return ((CRuntimeClass*)(&className<arg01>::class##className##_##arg01##_##arg02)) }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {

#define MFC_RuntimeExtPart02With02Args(className, arg01, arg02)\
            { 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }\
        };\
        __pragma(warning(pop))\
        static const AFX_MSGMAP messageMap =\
        { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };\
        return &messageMap;\
    }\
    static std::string ClassString()\
    {\
        std::string Combined = "className<"; \
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
