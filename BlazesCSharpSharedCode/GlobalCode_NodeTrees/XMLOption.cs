// ***********************************************************************
// Assembly         : BlazesCSharpSharedCode
// Author           : BlazesRus
// Created          : 07-14-2018
//
// Last Modified By : BlazesRus
// Last Modified On : 07-19-2018
// ***********************************************************************
// <copyright file="XMLOption.cs" company="">
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
    public class XMLOption
    {
		/// <summary>
		/// The option name
		/// </summary>
		public string OptionName = "";
		//Value Stored inside Option
		//[[NULL--VALUE]] or "None" = No Value Stored
		//"Undetermined" or "" = Undefined (Default)
		/// <summary>
		/// The value type
		/// </summary>
		public string ValueType = "";
		/// <summary>
		/// The value string
		/// </summary>
		public string ValueString = "";
		//Value not Stored in Arg within String inside Parenthesis
		/// <summary>
		/// The value not in parenthesis
		/// </summary>
		public bool ValueNotInParenthesis = false;
		/// <summary>
		/// Initializes a new instance of the <see cref="XMLOption"/> class.
		/// </summary>
		/// <param name="Name">The name.</param>
		/// <param name="Value">The value.</param>
		public XMLOption(string Name, string Value)
        {
            OptionName = Name;
            ValueString = Value;
            //Auto-Detect ValueType
            if (Value == "[[NULL--VALUE]]")
            {
                ValueType = "None";
            }
            else
            {
                ValueType = "Undetermined";
            }
        }
		/// <summary>
		/// Initializes a new instance of the <see cref="XMLOption"/> class.
		/// </summary>
		public XMLOption() { }
		/// <summary>
		/// Finalizes an instance of the <see cref="XMLOption"/> class.
		/// </summary>
		~XMLOption() { }
    }

	/// <summary>
	/// Class XMLOptionList.
	/// Implements the <see cref="System.Collections.Generic.List{CSharpSharedCode.SharedCode_NodeTrees.XMLOption}" />
	/// </summary>
	/// <seealso cref="System.Collections.Generic.List{CSharpSharedCode.SharedCode_NodeTrees.XMLOption}" />
	public class XMLOptionList : List<XMLOption>
    {
		/// <summary>
		/// Determines whether the specified option name temporary has option.
		/// </summary>
		/// <param name="OptionNameTemp">The option name temporary.</param>
		/// <returns><c>true</c> if the specified option name temporary has option; otherwise, <c>false</c>.</returns>
		public bool HasOption(string OptionNameTemp)
        {
            bool OptionFound = false;
            int ListSize = this.Count;
            XMLOption TargetOption;
            for (int i = 0; i < ListSize && OptionFound == false; ++i)
            {
                TargetOption = this.ElementAt(i);
                if (TargetOption.OptionName == OptionNameTemp)
                {
                    OptionFound = true;
                }
            }
            return OptionFound;
        }

		/// <summary>
		/// Gets the option value.
		/// </summary>
		/// <param name="OptionNameTemp">The option name temporary.</param>
		/// <returns>System.String.</returns>
		public string GetOptionValue(string OptionNameTemp)
        {
            bool OptionFound = false;
            string OptionValue = "";
            int ListSize = this.Count;
            XMLOption TargetOption;
            for (int i = 0; i < ListSize && OptionFound == false; ++i)
            {
                TargetOption = this.ElementAt(i);
                if (TargetOption.OptionName == OptionNameTemp)
                {
                    OptionValue = TargetOption.ValueString;
                }
            }
            return OptionValue;
        }
		/// <summary>
		/// Adds the option.
		/// </summary>
		/// <param name="NameTemp">The name temporary.</param>
		/// <param name="ValueTemp">The value temporary.</param>
		public void AddOption(string NameTemp, string ValueTemp)
        {
            Add(new XMLOption(NameTemp, ValueTemp));
        }
    }
}
