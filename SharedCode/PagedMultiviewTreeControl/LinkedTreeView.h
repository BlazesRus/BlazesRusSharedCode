// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#pragma once
#if !defined(LinkedTreeView_IncludeGuard)
#define LinkedTreeView_IncludeGuard

#include "CustomTreeView.h"

/// <summary>
/// Class named LinkedTreeView.
/// Implements the <see cref="CustomTreeView{TreeNode}" />
/// </summary>
/// <seealso cref="CustomTreeView{TreeNode}" />
template <typename TreeNode, typename NodeDictionaryType>
class LinkedTreeView : public CustomTreeView<TreeNode>
{
    CRuntime_Arg02Base01(LinkedTreeView, TreeNode, NodeDictionaryType, CustomTreeView, TreeNode)
        /// <summary>
        /// Initializes a new instance of the <see cref="LinkedTreeView"/> class.
        /// </summary>
        /// <param name="FilePath">The file path.</param>
        LinkedTreeView(string FilePath) : CustomTreeView<TreeNode>()
    {

    }
};

CRuntimeImplimentation_Arg02(LinkedTreeView, TreeNode, NodeDictionaryType)
#endif