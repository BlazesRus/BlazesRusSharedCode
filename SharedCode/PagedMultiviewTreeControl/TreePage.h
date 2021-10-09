#if !defined(TreePage_IncludeGuard)
#define TreePage_IncludeGuard

#include "MultiviewPrecompile.h"
#include "CustomTreeView.h"
#include "../OtherFunctions/MFCMacros.h"
#include "TreePageNode.h"
#include <typeinfo>

/////////////////////////////////////////////////////////////////////////////
// TreePage window

class TreePage : public CustomTreeView<TreePageNode>
{
	CRuntime_Base01V2(TreePage, CustomTreeView, TreePageNode)
protected://BEGIN_AltMESSAGE_MAP()
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()
	{
		typedef TreePage ThisClass;
		typedef CustomTreeView<TreePageNode> TheBaseClass;
		__pragma(warning(push))
		__pragma(warning(disable: 4640))
		static const AFX_MSGMAP_ENTRY _messageEntries[] =
		{
			//END_AltMESSAGE_MAP_Base01(CustomTreeView, TreePageNode)
			{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
		};
		__pragma(warning(pop))
		static const AFX_MSGMAP messageMap =
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };
		return &messageMap;
	}
public:
	virtual const AFX_MSGMAP* GetMessageMap() const
	{
		return GetThisMessageMap();
	}
};

inline AFX_COMDAT const CRuntimeClass TreePage::classTreePage = { "TreePage", sizeof(TreePage), 0xFFFF, NULL,&TreePage::_GetBaseClass, NULL, NULL };

#endif
