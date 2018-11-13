#if !defined(TreePage_IncludeGuard)
#define TreePage_IncludeGuard

#include "MultiviewPrecompile.h"
#include "CustomTreeView.h"
#include "CustomTreeNode.h"
#include "TemplateMacros.h"
#include <typeinfo>

class TreePageNode : public CustomTreeNode
{
public:
	TreePageNode() : CustomTreeNode()
	{
	}
};

/////////////////////////////////////////////////////////////////////////////
// TreePage window

class TreePage : public CustomTreeView<TreePageNode>
{
public:
	BEGIN_AltMESSAGE_MAP()
	END_AltMESSAGE_MAP_Base01(CustomTreeView, TreePageNode)
};

#endif
