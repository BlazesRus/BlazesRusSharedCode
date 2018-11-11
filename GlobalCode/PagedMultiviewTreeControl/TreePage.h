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
//#if defined(CustomTree_EnableLocalTypedefs)
//	virtual typedef TreeType = void;
//	virtual typedef NodeType = TreePageNode;
//#else
//	virtual static typedef TreeType = void;
//	std::type_info NodeType = typeid(TreePageNode);
//#endif
	//TreePageNode(bool DummySwitch) : CustomTreeNode<TreePageNode>(bool DummySwitch){}
	TreePageNode() : CustomTreeNode()
	{
#if defined(CustomTree_EnableLocalTypedefs)
		TreeType = TreeTypeDef;
		NodeType = TreePageNode;
#endif
	}
#if !defined(CustomTree_EnableLocalTypedefs)
	///// <summary>
	///// Sends the information about TreeType and current derived NodeType(Called on TreePage initialyzation)
	///// </summary>
	///// <param name="">The .</param>
	//static void SendTypeDefInfo(typedef TreeTypeDef)
	//{
	//	TreeType = TreeTypeDef;
	//	NodeType = TreePageNode;
	//}
#endif
	//TreePageNode(typedef TreeTypeDef) : CustomTreeNode<TreePageNode>()
	//{
	//	if (TreeType == void) { TreeType = TreeTypeDef; }
	//}
};

/////////////////////////////////////////////////////////////////////////////
// TreePage window

class TreePage : public CustomTreeView<TreePageNode>
{
public:
	//static typedef TreeType = TreePage;
	//virtual ~TreePage()
	//{
	//	DeleteNode(m_pTopNode);	// Delete all children if there are any
	//	delete m_pTopNode;			// Delete top node
	//	m_pTopNode = NULL;

	//	m_Font.DeleteObject();

	//	if (m_bmpBackground.GetSafeHandle() != NULL)
	//		m_bmpBackground.DeleteObject();
	//}
	BEGIN_AltMESSAGE_MAP()
	END_AltMESSAGE_MAP_Base01(CustomTreeView, TreePageNode)
};

#endif
