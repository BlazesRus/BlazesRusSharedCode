#if !defined(TreeCtrlPage_IncludeGuard)
#define TreeCtrlPage_IncludeGuard

#include "MultiviewPrecompile.h"
#include "TemplateMacros.h"
#include "CustomTreeCtrl.h"
#include "CustomTreeNode.h"
#include "VirtualType.h"

class TreeCtrlPageNode;
class TreeCtrlPageNode : public CustomTreeNode
{
public:
#if defined(CustomTree_EnableLocalTypedefs)
	virtual typedef TreeType = void;
	virtual typedef NodeType = TreePageNode;
#else
	virtual typedef TreeType = void;
	virtual typedef NodeType = TreePageNode;
#endif
	TreeCtrlPageNode() : CustomTreeNode() {
#if defined(CustomTree_EnableLocalTypedefs)
		TreeType = TreeTypeDef;
		NodeType = TreePageNode;
#endif
	}
#if !defined(CustomTree_EnableLocalTypedefs)
	/// <summary>
	/// Sends the information about TreeType and current derived NodeType(Called on TreePage initialyzation)
	/// </summary>
	/// <param name="">The .</param>
	static void SendTypeDefInfo(typedef TreeTypeDef)
	{
		TreeType = TreeTypeDef;
		NodeType = TreePageNode;
	}
#endif
};

/////////////////////////////////////////////////////////////////////////////
// TreeCtrlPage window

class TreeCtrlPage : public CustomTreeCtrl<TreeCtrlPageNode>
{
public:
	TreeCtrlPage : CustomTreeCtrl<TreeCtrlPageNode>()
	{
		TreeCtrlPageNode::SendTypeDefInfo(TreeType);
	}
	//virtual ~TreeCtrlPage()
	//{
	//	DeleteNode(m_pTopNode);	// Delete all children if there are any
	//	delete m_pTopNode;			// Delete top node
	//	m_pTopNode = NULL;

	//	m_Font.DeleteObject();

	//	if (m_bmpBackground.GetSafeHandle() != NULL)
	//		m_bmpBackground.DeleteObject();
	//}
	BEGIN_AltMESSAGE_MAP()
	END_AltMESSAGE_MAP_Base01(CustomTreeCtrl, TreeCtrlPageNode)
};

#endif
