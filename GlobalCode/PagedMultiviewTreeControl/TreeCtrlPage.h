#if !defined(TreeCtrlPage_IncludeGuard)
#define TreeCtrlPage_IncludeGuard

#include "MultiviewPrecompile.h"
#include "CustomTreeCtrl.h"
#include "CustomTreeNode.h"

class TreeCtrlPage;
class TreeCtrlPageNode;
class TreeCtrlPageNode : public CustomTreeNode<TreeCtrlPage, TreeCtrlPageNode >
{
public:
	TreeCtrlPageNode() : CustomTreeNode<TreeCtrlPage, TreeCtrlPageNode>() {}
};

/////////////////////////////////////////////////////////////////////////////
// TreeCtrlPage window

class TreeCtrlPage;
class TreeCtrlPage : public CustomTreeCtrl<TreeCtrlPageNode>
{
public:
	//virtual ~TreeCtrlPage()
	//{
	//	DeleteNode(m_pTopNode);	// Delete all children if there are any
	//	delete m_pTopNode;			// Delete top node
	//	m_pTopNode = NULL;

	//	m_Font.DeleteObject();

	//	if (m_bmpBackground.GetSafeHandle() != NULL)
	//		m_bmpBackground.DeleteObject();
	//}
	DECLARE_MESSAGE_MAP()
};

#endif
