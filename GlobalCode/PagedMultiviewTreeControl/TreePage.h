#if !defined(TreePage_IncludeGuard)
#define TreePage_IncludeGuard

#include "MultiviewPrecompile.h"
#include "CustomTreeView.h"
#include "TemplateMacros.h"
#include "TreePageNode.h"
#include <typeinfo>

/////////////////////////////////////////////////////////////////////////////
// TreePage window

class TreePage : public CustomTreeView<TreePageNode>
{
	//BEGIN_AltMESSAGE_MAP()
	//END_AltMESSAGE_MAP_Base01(CustomTreeView, TreePageNode)
protected:
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()
	{
		typedef CustomTreeView<TreePageNode> ThisClass;
		typedef CustomTreeView<TreePageNode> TheBaseClass;
		__pragma(warning(push))
		__pragma(warning(disable: 4640))
		static const AFX_MSGMAP_ENTRY _messageEntries[] =
		{
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

#endif
