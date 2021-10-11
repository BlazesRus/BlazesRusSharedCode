#ifndef MFCOneArgMacros_IncludeGuard
#define MFCOneArgMacros_IncludeGuard
#pragma once

#include <string>
        
/*
template<typename arg01>
class classType: public baseClass
{
    classType(){}
    ~classType(){}
    //And other class stuff
    MFC_RuntimeExtPart01With01Args(classType, arg01, baseClass)
    //Any message map messages here
    MFC_RuntimeExtPart02(classType)
    //MFC_RuntimeExtClassNameWith01Args(classType, arg01)//If need classType info
};

MFC_RuntimeImplimentationWith01Args(classType, arg01)
//MFC_RuntimeClassImplimentationWith01Args(classType, arg01)//If need classType info
*/
#define MFC_RuntimeExtPart01With01Args(classType, arg01, baseClass)\
private:\
    typedef classType<arg01> ThisClass;\
    typedef baseClass TheBaseClass;\
protected:\
    static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
    static const CRuntimeClass class##classType##_##arg01;\
    static CRuntimeClass* PASCAL GetThisClass() { return ((CRuntimeClass*)(&classType<arg01>::class##classType##_##arg01)) }\
    virtual CRuntimeClass* GetRuntimeClass() const { return ((CRuntimeClass*)(&classType<arg01>::class##classType##_##arg01)) }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {

#define MFC_RuntimeExtClassNameWith01Args(classType, arg01)\
public:\
    static std::string ClassString()\
    {\
        std::string Combined = "classType<"; \
        Combined += typeid(arg01).name(); \
        Combined += ">"; \
        return Combined; \
    }\
    static const std::string classNameStr;\
    static LPCSTR ClassName() { return classNameStr.c_str(); }

#define MFC_RuntimeClassImplimentationWith01Args(classType, arg01)\
template <typename arg01>\
inline const std::string classType<arg01>::classNameStr = classType<arg01>::ClassString();
    
#define MFC_RuntimeImplimentationWith01Args(classType,arg01)\
template <typename arg01>\
inline AFX_COMDAT const CRuntimeClass classType<arg01>::class##classType##_##arg01 = { ClassName(), sizeof(classType<arg01>), 0xFFFF, NULL,&classType<arg01>::_GetBaseClass, NULL, NULL };

#endif