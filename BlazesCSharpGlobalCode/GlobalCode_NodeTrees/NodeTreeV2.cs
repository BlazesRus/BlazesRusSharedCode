// ***********************************************************************
// Assembly         : BlazesCSharpGlobalCode
// Author           : BlazesRus
// Created          : 07-15-2018
//
// Last Modified By : BlazesRus
// Last Modified On : 07-22-2018
// ***********************************************************************
// <copyright file="NodeTreeV2.cs" company="">
//     Copyright ©  2018
// </copyright>
// <summary></summary>
// ***********************************************************************
using CSharpGlobalCode.GlobalCode_StringFunctions;
using CSharpGlobalCode.GlobalCode_VariableLists;
using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpGlobalCode.GlobalCode_NodeTrees
{
	////Send and share Data through Node optimization (less complicated detection of TagContent variable types)
	//public class OptimizationData
	//{
	//	public string CurrentHavokClass = "";
	//	public string CurrentActionDataSection_01 = "";
	//};

	//public class TagNodeTreeSharedData
	//{
	//	public long TabLevel = 0;
	//};

	/// <summary>
	/// Alternative version of Node class for containing XML like node with Lists of nodes within each
	/// </summary>
	/// <typeparam name="NodeTreeType">The type of the node tree type.</typeparam>
	/// <typeparam name="CurrentType">Class name of the Derived Node</typeparam>
	public class NodeV2<NodeTreeType, CurrentType>
    {
		/// <summary>
		/// NodeLists containing other Nodes of itself or derived classes
		/// </summary>
		public List<CurrentType> NodeLists;
    }

	/// <summary>
	/// Create a NodeTree for storing xml like layout info (alternative version that contains nodes holding other node lists)
	/// </summary>
	/// <typeparam name="NodeType">Either NodeV2 or a derivative.</typeparam>
	public class NodeTreeV2<NodeType>
    {
		/// <summary>
		/// The root nodes
		/// </summary>
		public List<NodeType> RootNodes;

		//public List<string> GenerateXMLStringList()
		//{
		//    List<string> LineDataList = new List<string>();
		//    return LineDataList;
		//}

		/// <summary>
		/// Clears this instance.
		/// </summary>
		public void Clear()
        {
            RootNodes.Clear();
        }
    }
}