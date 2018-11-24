// ***********************************************************************
// Assembly         : BlazesCSharpGlobalCode
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

namespace CSharpGlobalCode.GlobalCode_NodeTrees
{
	/// <summary>
	/// Class StringNode.
	/// Implements the <see cref="CSharpGlobalCode.GlobalCode_NodeTrees.NodeV2{CSharpGlobalCode.GlobalCode_NodeTrees.StringTree, CSharpGlobalCode.GlobalCode_NodeTrees.StringNode}" />
	/// </summary>
	/// <seealso cref="CSharpGlobalCode.GlobalCode_NodeTrees.NodeV2{CSharpGlobalCode.GlobalCode_NodeTrees.StringTree, CSharpGlobalCode.GlobalCode_NodeTrees.StringNode}" />
	public class StringNode : NodeV2<StringTree, StringNode>
    {
    }

	/// <summary>
	/// Class StringTree.
	/// Implements the <see cref="CSharpGlobalCode.GlobalCode_NodeTrees.NodeTreeV2{CSharpGlobalCode.GlobalCode_NodeTrees.StringNode}" />
	/// </summary>
	/// <seealso cref="CSharpGlobalCode.GlobalCode_NodeTrees.NodeTreeV2{CSharpGlobalCode.GlobalCode_NodeTrees.StringNode}" />
	public class StringTree : NodeTreeV2<StringNode>
    {
    }
}
