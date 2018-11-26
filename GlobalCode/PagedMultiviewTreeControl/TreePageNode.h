#if !defined(TreePageNode_IncludeGuard)
#define TreePageNode_IncludeGuard

#include "MultiviewPrecompile.h"
#include "TemplateMacros.h"
#include "CustomTreeNode.h"
//#include <typeinfo>

class TreePageNode : public CustomTreeNode
{
public:
	TreePageNode() : CustomTreeNode()
	{
	}
	TreePageNode(int MenuType) : CustomTreeNode(MenuType)
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

#endif