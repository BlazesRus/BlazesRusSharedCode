#ifndef MFCTwoArgMacros_IncludeGuard
#define MFCTwoArgMacros_IncludeGuard
#pragma once

#include <string>

/*
template<typename arg01, arg02>
class classType: public baseClass
{
    classType(){}
    ~classType(){}
    //And other class stuff
    MFC_RuntimeExtPart01With02Args(classType, arg01, arg02, baseClass)
    //Any message map messages here
    MFC_RuntimeExtPart02(classType)
    //MFC_RuntimeExtClassNameWith02Args(classType, arg01, arg02)//If need classType info
};

MFC_RuntimeImplimentationWith02Args(classType, arg01, arg02)
//MFC_RuntimeClassImplimentationWith02Args(classType, arg01, arg02)//If need classType info
*/
#define MFC_RuntimeExtPart01With02Args(classType, arg01, arg02, baseClass)\
private:\
    typedef baseClass TheBaseClass;\
    typedef classType<arg01, arg02> ThisClass;\
protected:\
    static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
    static const CRuntimeClass class##classType##_##arg01##_##arg02;\
    static CRuntimeClass* PASCAL GetThisClass() { return ((CRuntimeClass*)(&classType<arg01,arg02>::class##classType##_##arg01##_##arg02)); }\
    virtual CRuntimeClass* GetRuntimeClass() const { return ((CRuntimeClass*)(&classType<arg01,arg02>::class##classType##_##arg01##_##arg02)); }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {

#define MFC_RuntimeExtClassNameWith02Args(classType, arg01)\
public:\
    static std::string ClassString()\
    {\
        std::string Combined = "classType<"; \
        Combined += typeid(arg01).name(); \
        Combined += ", "; \
        Combined += typeid(arg02).name(); \
        Combined += ">"; \
        return Combined; \
    }\
    static const std::string classNameStr;\
    static LPCSTR ClassName() { return classNameStr.c_str(); }

#define MFC_RuntimeImplimentationWith02Args(classType,arg01,arg02)\
template <typename arg01, typename arg02>\
inline AFX_COMDAT const CRuntimeClass classType<arg01, arg02>::class##classType##_##arg01##_##arg02 = { ClassName(), sizeof(class_name<arg01, arg02>), 0xFFFF, NULL,&class_name<arg01, arg02>::_GetBaseClass, NULL, NULL };

#define MFC_RuntimeClassImplimentationWith02Args(classType, arg01, arg02)\
template <typename arg01, typename arg02>\
inline const std::string classType<arg01, arg02>::classNameStr = classType<arg01,arg02>::ClassString();

#endif