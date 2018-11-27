#if !defined(LinkedTreeView_IncludeGuard)
#define LinkedTreeView_IncludeGuard

#include "CustomTreeView.h"

template <typename TreeNode, typename NodeDictionaryType>
class LinkedTreeView : public CustomTreeView<TreeNode>
{
	LinkedTreeView(string FilePath) : CustomTreeView()
	{

	}
};
#endif