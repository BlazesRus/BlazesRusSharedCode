// ***********************************************************************
// Assembly         : BlazesCSharpSharedCode
// Author           : BlazesRus
// Created          : 07-17-2018
//
// Last Modified By : BlazesRus
// Last Modified On : 07-19-2018
// ***********************************************************************
// <copyright file="NifNodeTree.cs" company="">
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
	/// Class NifNode.
	/// </summary>
	public class NifNode
    {
		/// <summary>
		/// The node lists
		/// </summary>
		public List<NifNode> NodeLists;
    }
	/// <summary>
	/// Class NifNodeTree.
	/// </summary>
	public class NifNodeTree
    {
		/// <summary>
		/// The root nodes
		/// </summary>
		public List<NifNode> RootNodes;
    }
}
