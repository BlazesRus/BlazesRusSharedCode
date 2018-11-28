#if !defined(LinkedTreeView_IncludeGuard)
#define LinkedTreeView_IncludeGuard

#include "CustomTreeView.h"

template <typename TreeNode, typename NodeDictionaryType>
class LinkedTreeView : public CustomTreeView<TreeNode>
{
	CRuntime_Arg02Base01(LinkedTreeView, TreeNode, NodeDictionaryType, CustomTreeView, TreeNode)
	LinkedTreeView(string FilePath) : CustomTreeView<TreeNode>()
	{

	}
};

CRuntimeImplimentation_Arg02Base01(LinkedTreeView, TreeNode, NodeDictionaryType)
#endif