#if !defined(TreeCtrlPage_IncludeGuard)
#define TreeCtrlPage_IncludeGuard

#include "MultiviewPrecompile.h"
#include "OtherFunctions/MFCMacros.h"
#include "CustomTreeNode.h"
#include "CustomTreeCtrl.h"
//#include "ExperimentalCode/VirtualType.h"

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
