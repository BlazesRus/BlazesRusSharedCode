// ***********************************************************************
// Assembly         : BlazesCSharpSharedCode
// Author           : BlazesRus
// Created          : 07-19-2018
//
// Last Modified By : BlazesRus
// Last Modified On : 07-23-2018
// ***********************************************************************
// <copyright file="StringTree.cs" company="">
//     Copyright ©  2018
// </copyright>
// <summary></summary>
// ***********************************************************************
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpSharedCode.SharedCode_NodeTrees
{
	/// <summary>
	/// Class StringNode.
	/// Implements the <see cref="CSharpSharedCode.SharedCode_NodeTrees.NodeV2{CSharpSharedCode.SharedCode_NodeTrees.StringTree, CSharpSharedCode.SharedCode_NodeTrees.StringNode}" />
	/// </summary>
	/// <seealso cref="CSharpSharedCode.SharedCode_NodeTrees.NodeV2{CSharpSharedCode.SharedCode_NodeTrees.StringTree, CSharpSharedCode.SharedCode_NodeTrees.StringNode}" />
	public class StringNode : NodeV2<StringTree, StringNode>
    {
    }

	/// <summary>
	/// Class StringTree.
	/// Implements the <see cref="CSharpSharedCode.SharedCode_NodeTrees.NodeTreeV2{CSharpSharedCode.SharedCode_NodeTrees.StringNode}" />
	/// </summary>
	/// <seealso cref="CSharpSharedCode.SharedCode_NodeTrees.NodeTreeV2{CSharpSharedCode.SharedCode_NodeTrees.StringNode}" />
	public class StringTree : NodeTreeV2<StringNode>
    {
    }
}
