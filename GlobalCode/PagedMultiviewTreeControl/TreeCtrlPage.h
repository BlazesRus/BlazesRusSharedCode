#if !defined(TreeCtrlPage_IncludeGuard)
#define TreeCtrlPage_IncludeGuard

#include "MultiviewPrecompile.h"
#include "TemplateMacros.h"
#include "CustomTreeNode.h"
#include "CustomTreeCtrl.h"
//#include "GlobalCode_ExperimentalCode/VirtualType.h"

class TreeCtrlPageNode;
class TreeCtrlPageNode : public CustomTreeNode
{
public:
	TreeCtrlPageNode() : CustomTreeNode()
	{
	}
};

/////////////////////////////////////////////////////////////////////////////
// TreeCtrlPage window

class TreeCtrlPage : public CustomTreeCtrl<TreeCtrlPageNode>
{
public:
	BEGIN_AltMESSAGE_MAP()
	END_AltMESSAGE_MAP_Base01(CustomTreeCtrl, TreeCtrlPageNode)
};

#endif
