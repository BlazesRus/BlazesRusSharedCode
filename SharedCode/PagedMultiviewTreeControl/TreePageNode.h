// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#if !defined(TreePageNode_IncludeGuard)
#define TreePageNode_IncludeGuard

#include "MultiviewPrecompile.h"
#include "../OtherFunctions/MFCMacros.h"
#include "CustomTreeNode.h"

/// <summary>
/// Class named TreePageNode.
/// Implements the <see cref="CustomTreeNode" />
/// </summary>
/// <seealso cref="CustomTreeNode" />
class TreePageNode : public CustomTreeNode
{
public:
    /// <summary>
    /// Initializes a new instance of the <see cref="TreePageNode"/> class.
    /// </summary>
    TreePageNode() : CustomTreeNode()
    {
    }
    /// <summary>
    /// Initializes a new instance of the <see cref="TreePageNode"/> class.
    /// </summary>
    /// <param name="MenuType">Type of the menu.</param>
    TreePageNode(int MenuType) : CustomTreeNode(MenuType)
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