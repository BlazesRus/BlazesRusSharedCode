#if !defined(XMLTagViewNode_IncludeGuard)
#define XMLTagViewNode_IncludeGuard

#include "MultiviewPrecompile.h"
#include "TemplateMacros.h"
#include "CustomTreeNode.h"

class XMLTagViewNode : public CustomTreeNode
{
public:
	XMLTagViewNode() : CustomTreeNode()
	{
	}
	XMLTagViewNode(int MenuType) : CustomTreeNode(MenuType)
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