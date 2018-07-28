using CSharpGlobalCode.GlobalCode_ExperimentalCode;
using CSharpGlobalCode.GlobalCode_VariableConversionFunctions;
using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpGlobalCode.GlobalCode_IniDataV2
{
	public class IniStringElement
	{
		bool IsIniCategory = false;
		//public string IniSetting;
		public string IniValue;
		public IniStringElement() { }
		//      public IniStringElement(string Arg01, string Arg02)
		//      {
		//          IniSetting = Arg01;
		//          IniValue = Arg02;
		//      }
	}

	public class IniDataV2 : System.Collections.Specialized.OrderedDictionary
	{
		private const string IntDeclaration = "#Int";
		private const string MediumDecDeclaration = "#MediumDec";
		private Dictionary<string, int> IntSettings = new Dictionary<string, int>();
		private Dictionary<string, MediumDec> MediumDecSettings = new Dictionary<string, MediumDec>();
		//Dictionary<string, IniStringElement> OtherStringSettings = new Dictionary<string, IniStringElement>();
		/// <summary>
		/// Loads the Ini data. 
		/// </summary>
		/// <param name="FileName">Name of the file.</param>
		/// <param name="IniFormat">The ini storage format.
		/// (TypeDeclaration) + Other Formating
		/// 0 = IniSetting:IniValue; format(Default)
		/// 1= [IniSetting=IniValue] format (based on my old C++ code)
		/// </param>
		public void LoadIniDataV2(string FileName, byte IniFormat = 0)
		{
			List<string> FileData = CSharpGlobalCode.GlobalMiscCode.FileAccessCommands.ReturnFileContentsAsList(FileName);
			string LineData;
			string IniSetting = "";
			string IniValue = "";
			//			byte InsideComment = 0;
			bool InsideTypeDeclaration = false;
			string TypeName = "";
			var builder = new StringBuilder();
			if (IniFormat == 1)
			{
				bool InsideParenthesis = false;
				int LineSize;
				char LineChar;
				int CommandStage = 0;
				//IniDataV2Element ElementData = new IniDataV2Element();
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
						else if (InsideTypeDeclaration)
						{
							if (LineChar == ')')
							{
								TypeName = builder.ToString();
								InsideTypeDeclaration = false;
							}
							else
							{
								builder.Append(LineChar);
							}
						}
						else if (LineChar == '(')
						{
							builder.Clear(); InsideTypeDeclaration = true;
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
									switch (TypeName)
									{
										case "Int":
											this.Add(IniSetting, IntDeclaration);
											IntSettings.Add(IniSetting, VariableConversionFunctions.ReadIntFromString(IniValue));
											break;
										case "MediumDec":
											this.Add(IniSetting, MediumDecDeclaration);
											MediumDecSettings.Add(IniSetting, (MediumDec)IniValue);
											break;
										default:
											this.Add(IniSetting, IniValue);
											break;
									}
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
						if (InsideTypeDeclaration)
						{
							if (StringChar == ')')
							{
								TypeName = builder.ToString();
								InsideTypeDeclaration = false;
							}
							else
							{
								builder.Append(StringChar);
							}
						}
						else if (StringChar == ':')
						{//IniSetting
							IniSetting = builder.ToString();
							builder.Clear();
						}
						else if (StringChar == ';')
						{
							IniValue = builder.ToString();
							builder.Clear();
							switch (TypeName)
							{
								case "Int":
									this.Add(IniSetting, IntDeclaration);
									IntSettings.Add(IniSetting, VariableConversionFunctions.ReadIntFromString(IniValue));
									break;
								case "MediumDec":
									this.Add(IniSetting, MediumDecDeclaration);
									MediumDecSettings.Add(IniSetting, (MediumDec)IniValue);
									break;
								default:
									this.Add(IniSetting, IniValue);
									break;
							}

						}
						else if (StringChar == '(')
						{
							builder.Clear(); InsideTypeDeclaration = true;
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

		public bool CheckIfElementExists(string Value) => this.Contains(Value);
		/// <summary>
		/// Gets the element data.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public dynamic GetElementData(string Value)
		{
			string ElementValue = (string)this[Value];
			if (ElementValue == IntDeclaration)
			{
				return IntSettings[Value];//return VariableConversionFunctions.IntToStringConversion(IntSettings[Value]);
			}
			else if (ElementValue == MediumDecDeclaration)
			{
				return MediumDecSettings[Value];
			}
			else
			{
				return ElementValue;
			}
		}
		/// <summary>
		/// Gets the element data as string
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public string GetIniValue(string Value)
		{
			string ElementValue = (string)this[Value];
			if (ElementValue == IntDeclaration)
			{
				return VariableConversionFunctions.IntToStringConversion(IntSettings[Value]);
			}
			else if (ElementValue == MediumDecDeclaration)
			{
				return MediumDecSettings[Value].ToFullString();
			}
			else
			{
				return ElementValue;
			}
		}
		public int GetIntElementData(string Value) => IntSettings[Value];
		public MediumDec GetMediumDecElementData(string Value) => MediumDecSettings[Value];
		public IniDataV2() { }
	}
}
