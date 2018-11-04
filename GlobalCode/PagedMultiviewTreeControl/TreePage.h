#if !defined(TreePage_IncludeGuard)
#define TreePage_IncludeGuard

#include "MultiviewPrecompile.h"
#include "CustomTreeView.h"
#include "CustomTreeNode.h"

class TreePage;
class TreePageNode;
class TreePageNode : public CustomTreeNode<TreePage, TreePageNode >
{
public:
	TreePageNode() : CustomTreeNode<TreePage, TreePageNode>() {}
};

/////////////////////////////////////////////////////////////////////////////
// TreePage window

class TreePage;
class TreePage : public CustomTreeView<TreePageNode>
{
public:
	//virtual ~TreePage()
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
