#if !defined(TreePage_IncludeGuard)
#define TreePage_IncludeGuard

#include "MultiviewPrecompile.h"
#include "CustomTreeView.h"
#include "../OtherFunctions/MFCMacros.h"
#include "TreePageNode.h"
#include <typeinfo>
#include "MultiViewDoc.h"

/////////////////////////////////////////////////////////////////////////////
// TreePage window

class TreePage : public CustomTreeView<TreePageNode, MultiViewDoc>
{
    CRuntime_Base02V2(TreePage, CustomTreeView, TreePageNode, MultiViewDoc)
private:
    typedef CustomTreeView<TreePageNode, MultiViewDoc> TheBaseClass;
    typedef TreePage ThisClass;
protected://BEGIN_AltMESSAGE_MAP()
    static const AFX_MSGMAP* PASCAL GetThisMessageMap()
    {
        __pragma(warning(push))
        __pragma(warning(disable: 4640))
        static const AFX_MSGMAP_ENTRY _messageEntries[] =
        {
            //END_AltMESSAGE_MAP_Base02(CustomTreeView, TreePageNode, MultiViewDoc)
            { 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
        };
        __pragma(warning(pop))
        static const AFX_MSGMAP messageMap =
        { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };
        return &messageMap;
    }
    static std::string ClassString()
    {
        return "TreePage";
    }
public:
    virtual const AFX_MSGMAP* GetMessageMap() const
    {
        return GetThisMessageMap();
    }
public:
    static const std::string TreePageStr;
    static LPCSTR ClassName() { return classNameStr.c_str(); }
protected:
    static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); } 
public:
    static const CRuntimeClass classTreePage;
    static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(TreePage); }
    virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(TreePage);}
};

const std::string TreePage::TreePageStr = TreePage::TreePageStr;
const CRuntimeClass TreePage::classTreePage = { "TreePage", sizeof(TreePage), 0xFFFF, NULL,&TreePage::_GetBaseClass, NULL, NULL };

#endif
