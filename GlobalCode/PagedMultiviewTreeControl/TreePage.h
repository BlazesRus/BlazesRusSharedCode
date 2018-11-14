#if !defined(TreePage_IncludeGuard)
#define TreePage_IncludeGuard

#include "MultiviewPrecompile.h"
#include "CustomTreeView.h"
#include "CustomTreeNode.h"
#include "TemplateMacros.h"
#include <typeinfo>

class TreePageNode;
class TreePageNode : public CustomTreeNode
{
public:
	TreePageNode() : CustomTreeNode()
	{
	}
	explicit operator CustomTreeNode*()
	{
		if (this == nullptr)
		{
			return nullptr;
		}
		else
		{
			return dynamic_cast<CustomTreeNode*>(this);
		}
	}
};

/////////////////////////////////////////////////////////////////////////////
// TreePage window

class TreePage : public CustomTreeView<TreePageNode>
{
public:
	//BEGIN_AltMESSAGE_MAP()
	//END_AltMESSAGE_MAP_Base01(CustomTreeView, TreePageNode)
protected:
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()
	{
		__pragma(warning(push))
		__pragma(warning(disable: 4640))
		static const AFX_MSGMAP_ENTRY _messageEntries[] =
		{
			{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
		};
		__pragma(warning(pop))
		static const AFX_MSGMAP messageMap =
		{ &CustomTreeView<TreePageNode>::GetThisMessageMap, &_messageEntries[0] };
		return &messageMap;
	}
public:
	virtual const AFX_MSGMAP* GetMessageMap() const
	{
		return GetThisMessageMap();
	}
};

#endif
