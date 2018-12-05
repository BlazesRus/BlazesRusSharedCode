// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#if !defined(XMLTagViewNode_IncludeGuard)
#define XMLTagViewNode_IncludeGuard

#include "MultiviewPrecompile.h"
#include "TemplateMacros.h"
#include "CustomTreeNode.h"
#include "GlobalCode_IniData/IniDataV2.h"

/// <summary>
/// Class named XMLTagViewNode.
/// Implements the <see cref="CustomTreeNode" />
/// </summary>
/// <seealso cref="CustomTreeNode" />
class XMLTagViewNode : public CustomTreeNode
{
public:
	/// <summary>
	/// The addition tag options
	/// </summary>
	IniDataV2 AdditionTagOptions;
	//0=NormalTag; 1:SelfContainedTag; 2:TagIsClosing; 3:XMLVersionTag
	int TagType = 0;
	///<summary>
	/// Initializes a new instance of the <see cref="XMLTagViewNode"/> class.
	///</summary>
	XMLTagViewNode() : CustomTreeNode()
	{
	}
	/// <summary>
	/// Initializes a new instance of the <see cref="XMLTagViewNode"/> class.
	/// </summary>
	/// <param name="MenuType">Type of the menu.</param>
	XMLTagViewNode(int MenuType) : CustomTreeNode(MenuType)
	{
	}
	/// <summary>
	/// Implements the operator CustomTreeNode* operator.
	/// </summary>
	/// <returns>The result of the operator.</returns>
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