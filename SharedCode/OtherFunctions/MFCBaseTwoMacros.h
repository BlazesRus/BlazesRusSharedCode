#ifndef MFCBaseTwoMacros_IncludeGuard
#define MFCBaseTwoMacros_IncludeGuard
#pragma once

/*
class classType: public baseClass<baseArg01, baseArg02>
{
    classType(){}
    ~classType(){}
    //And other class stuff
    
    MFC_RuntimeExtPart01Base02(classType, baseClass, baseArg01, baseArg02)
    //Any message map messages here
    MFC_RuntimeExtPart02(classType, baseClass, baseArg01, baseArg02)
    //MFC_RuntimeExtclassType(classType, arg01)//If need classType info
};

MFC_RuntimeImplimentation(classType, arg01)
//MFC_RuntimeClassImplimentation(classType, arg01)//If need classType info
*/
#define MFC_RuntimeExtPart01Base02(classType, baseClass, baseArg01, baseArg02)\
private:\
    typedef baseClass<baseArg01, baseArg02> TheBaseClass;\
    typedef classType ThisClass;\
protected:\
    static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } \
public:\
    static const CRuntimeClass class##classType;\
    static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(classType); }\
    virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(classType); }\
protected:\
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
    {\
        __pragma(warning(push))\
        __pragma(warning(disable: 4640))\
        static const AFX_MSGMAP_ENTRY _messageEntries[] =\
        {
        
#endif