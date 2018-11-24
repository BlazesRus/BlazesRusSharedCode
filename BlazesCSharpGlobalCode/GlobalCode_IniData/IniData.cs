// ***********************************************************************
// Assembly         : BlazesCSharpGlobalCode
// Author           : BlazesRus
// Created          : 02-09-2018
//
// Last Modified By : BlazesRus
// Last Modified On : 07-27-2018
// ***********************************************************************
// <copyright file="IniData.cs" company="">
//     Copyright ©  2018
// </copyright>
// <summary></summary>
// ***********************************************************************
using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpGlobalCode.GlobalCode_IniData
{
	/// <summary>
	/// Class IniDataElement.
	/// </summary>
	public class IniDataElement
    {
		/// <summary>
		/// The ini setting
		/// </summary>
		public string IniSetting;
		/// <summary>
		/// The ini value
		/// </summary>
		public string IniValue;
		/// <summary>
		/// Initializes a new instance of the <see cref="IniDataElement"/> class.
		/// </summary>
		public IniDataElement(){}
		/// <summary>
		/// Initializes a new instance of the <see cref="IniDataElement"/> class.
		/// </summary>
		/// <param name="Arg01">The arg01.</param>
		/// <param name="Arg02">The arg02.</param>
		public IniDataElement(string Arg01, string Arg02)
        {
            IniSetting = Arg01;
            IniValue = Arg02;
        }
    }

	/// <summary>
	/// Class IniData.
	/// Implements the <see cref="System.Collections.Generic.List{CSharpGlobalCode.GlobalCode_IniData.IniDataElement}" />
	/// </summary>
	/// <seealso cref="System.Collections.Generic.List{CSharpGlobalCode.GlobalCode_IniData.IniDataElement}" />
	public class IniData : List<IniDataElement>
    {
		//byte IniType = 0;

		/// <summary>
		/// Loads the Ini data.
		/// </summary>
		/// <param name="FileName">Name of the file.</param>
		/// <param name="IniFormat">The ini storage format.
		/// 0 = IniSetting:IniValue; format(Default)
		/// 1= [IniSetting=IniValue] format (based on my old C++ code)</param>
		public void LoadIniData(string FileName, byte IniFormat = 0)
        {
            List<string> FileData = CSharpGlobalCode.GlobalMiscCode.FileAccessCommands.ReturnFileContentsAsList(FileName);
            string LineData;
            string IniSetting = "";
//			byte InsideComment = 0;
            var builder = new StringBuilder();
            if (IniFormat == 1)
            {
                bool InsideParenthesis = false;
                string IniValue="";
                int LineSize;
                char LineChar;
                int CommandStage = 0;
                IniDataElement ElementData = new IniDataElement();
                for (int Index = 0; Index < FileData.Count; ++Index)
                {
                    LineData = FileData[Index];
                    LineSize = LineData.Length;
                    for (int i = 0; i < LineSize; ++i)
                    {
                        LineChar = LineData[i];
                        if (LineChar == '"') { InsideParenthesis = !InsideParenthesis; }
                        else if (LineChar == '[')
                        {
                            IniSetting = "";
                            CommandStage = 1;
                        }
                        else if (CommandStage > 0)
                        {
                            if (InsideParenthesis == false && (LineChar == '=' || LineChar == ':'))
                            {
                                CommandStage = 2;
                            }
                            else if (CommandStage == 2)
                            {
                                if (LineChar == ']')
                                {
                                    //std::cout << "Executing Command:" << IniSetting << " with parameter "<<IniValue<<"\n";
                                    CommandStage = 0;
                                    ElementData = new IniDataElement(IniSetting, IniValue);
                                    Add(ElementData);
                                    IniValue = "";
                                    IniSetting = "";
                                }
                                else
                                {
                                    IniValue += LineChar;
                                }
                            }
                            else
                            {
                                IniSetting += LineChar;
                            }
                        }
                    }
                }
            }
            else
            {
                for (int Index = 0; Index < FileData.Count; ++Index)
                {
                    LineData = FileData[Index];
                    foreach (char StringChar in LineData)
                    {
                        if (StringChar == ':')
                        {//IniSetting
                            IniSetting = builder.ToString();
                            builder.Clear();
                        }
                        else if (StringChar == ';')
                        {
                            Add(new IniDataElement(IniSetting, builder.ToString()));
                            builder.Clear();
                        }
                        else if (StringChar == '/')//Start of line comment detected so skip rest of line
                        {
                            if (builder.ToString() == "/")
                            {
                                builder.Clear();
                                break;
                            }
                            else//False alarm on line comment detection
                            {
                                builder.Append(StringChar);
                            }
                        }
                        else
                        {

                            switch (builder.Length)
                            { /* Ignore whitespace if no words started*/
                                case 0 when StringChar == ' ':
                                    continue;
                                default:
                                    builder.Append(StringChar);
                                    continue;
                            }
                        }
                    }
                }
            }
        }

		/// <summary>
		/// Checks if element exists.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns><c>true</c> if XXXX, <c>false</c> otherwise.</returns>
		public bool CheckIfElementExists(string Value)
        {
            int ListSize = this.Count;
            IniDataElement ElementData;
            bool ElementExists = false;
            for (int Index = 0; Index < ListSize && ElementExists == false; ++Index)
            {
                ElementData = this[Index];
                if (ElementData.IniSetting == Value)
                {
                    ElementExists = true;
                }
            }
            return ElementExists;
        }
		/// <summary>
		/// Gets the element data.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>System.String.</returns>
		public string GetElementData(string Value)
        {
            int ListSize = this.Count;
            string ElementValue = "";
            IniDataElement ElementData;
            bool ElementExists = false;
            for (int Index = 0; Index < ListSize && ElementExists == false; ++Index)
            {
                ElementData = this[Index];
                if (ElementData.IniSetting == Value)
                {
                    ElementExists = true;
                    ElementValue = ElementData.IniValue;
                }
            }
            if (ElementExists == false)
            {
                Console.WriteLine("Ini setting named " + Value + "not found.\n");
            }
            return ElementValue;
        }
		/// <summary>
		/// Initializes a new instance of the <see cref="IniData"/> class.
		/// </summary>
		public IniData() {}
    }
}
