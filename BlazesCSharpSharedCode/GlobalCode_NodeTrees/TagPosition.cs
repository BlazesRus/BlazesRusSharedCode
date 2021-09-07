// ***********************************************************************
// Assembly         : BlazesCSharpSharedCode
// Author           : BlazesRus
// Created          : 07-14-2018
//
// Last Modified By : BlazesRus
// Last Modified On : 07-14-2018
// ***********************************************************************
// <copyright file="TagPosition.cs" company="">
//     Copyright ©  2018
// </copyright>
// <summary></summary>
// ***********************************************************************
using CSharpSharedCode.VariableLists;
using CSharpSharedCode.VariableConversionFunctions;

namespace CSharpSharedCode.SharedCode_NodeTrees
{
	/// <summary>
	/// Class TagPosition.
	/// </summary>
	public class TagPosition
    {
		//Example ParentIndexPosition="0_1"
		/// <summary>
		/// The parent index position
		/// </summary>
		public XIntegerList ParentIndexPosition;

		//Index in CurrentList
		/// <summary>
		/// The list position
		/// </summary>
		private long ListPosition = -1;

		/// <summary>
		/// Increases the list position.
		/// </summary>
		private void IncreaseListPos()
        {
            ListPosition += 1;
        }

		/// <summary>
		/// Increases the index of the parent.
		/// </summary>
		private void IncreaseParentIndex()
        {
            ParentIndexPosition.Add(ListPosition);
            ListPosition = -1;
        }

		//************************************
		// Returns String in format ParentIndexPosition(Index:0)_ParentIndexPosition(Index:1)-ListPosition
		// Method:    PositionString
		// FullName:  TagData::TagPosition::PositionString
		// Access:    public
		// Returns:   string
		// Qualifier:
		//************************************
		/// <summary>
		/// Positions the string.
		/// </summary>
		/// <returns>System.String.</returns>
		public string PositionString()
        {
            string PositionString = ParentIndexPosition.GenerateAsString();
            PositionString += "-";
            PositionString += VariableConversionFunctions.LongToStringConversion(ListPosition);
            return PositionString;
        }
    }
}