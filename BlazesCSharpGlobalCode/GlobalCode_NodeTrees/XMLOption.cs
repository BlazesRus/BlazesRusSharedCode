using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpGlobalCode.GlobalCode_NodeTrees
{
	public class XMLOption
	{
		public string OptionName = "";
		//Value Stored inside Option
		//[[NULL--VALUE]] or "None" = No Value Stored
		//"Undetermined" or "" = Undefined (Default)
		public string ValueType = "";
		public string ValueString = "";
		//Value not Stored in Arg within String inside Parenthesis
		public bool ValueNotInParenthesis = false;
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
		public XMLOption() { }
		~XMLOption() { }
	}

	public class XMLOptionList : List<XMLOption>
	{
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
		public void AddOption(string NameTemp, string ValueTemp)
		{
			Add(new XMLOption(NameTemp, ValueTemp));
		}
	}
}
