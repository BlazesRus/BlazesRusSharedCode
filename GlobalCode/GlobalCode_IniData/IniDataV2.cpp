/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#include "IniDataV2.h"
#include <string>

//
//void IniDataV2::LoadIniData(std::string FileName)
//{
//	StringVectorList TargetSettings;
//	TargetSettings.LoadFileDataV2(FileName);
//	//First part of command;Syntax:[ScriptArg01=ScriptArg02]
//	std::string ScriptArg01;
//	//Command Value;Syntax:[ScriptArg01=ScriptArg02]
//	std::string ScriptArg02;
//	//CommandScan Stage (limited to value of 255 to save little ram)
//	unsigned __int8 CommandStage = 0;
//	std::string LineString = "";
//	size_t LineSize;
//	char LineChar;
//	bool InsideParenthesis = false;
//	//IniDataV2Element ElementData;
//	for(size_t LineNumber = 0; TargetSettings.StreamLineData(); ++LineNumber)
//	{
//		LineString = TargetSettings.CurrentStreamedLineString();
//		LineSize = LineString.length();
//		for(size_t i = 0; i < LineSize; ++i)
//		{
//			LineChar = LineString.at(i);
//			if(LineChar == '"') { InsideParenthesis = !InsideParenthesis; }
//			else if(LineChar == '[')
//			{
//				ScriptArg01 = "";
//				CommandStage = 1;
//			}
//			else if(CommandStage > 0)
//			{
//				if(InsideParenthesis==false&&(LineChar == '=' || LineChar == ':'))
//				{
//					CommandStage = 2;
//				}
//				else if(CommandStage == 2)
//				{
//					if(LineChar == ']')
//					{
//						//std::cout << "Executing Command:" << ScriptArg01 << " with parameter "<<ScriptArg02<<"\n";
//						CommandStage = 0;
//						//ElementData.ScriptArg01 = ScriptArg01;
//						//ElementData.ScriptArg02 = ScriptArg02;
//						//Add(ElementData);
//						ScriptArg02 = "";
//						ScriptArg01 = "";
//					}
//					else
//					{
//						ScriptArg02 += LineChar;
//					}
//				}
//				else
//				{
//					ScriptArg01 += LineChar;
//				}
//			}
//		}
//	}
//}

/// <summary>
/// Loads the Ini data.
/// </summary>
/// <param name="FileName">Name of the file.</param>
/// <param name="IniFormat">The ini storage format.
/// (TypeDeclaration) + Other Formating
/// 0 = IniSetting:IniValue; format(Default)
/// 1= [IniSetting=IniValue] format (based on my old C++ code)
/// </param>

inline void IniDataV2::LoadIniDataV2(std::string FileName, byte IniFormat)
{
	StringVectorList FileData;
	FileData.LoadFileDataV2(FileName);
	std::string LineData;
	std::string IniSetting = "";
	std::string IniValue = "";
	std::pair<std::string, int> TempIntPair;
	//byte InsideComment = 0;
	bool InsideTypeDeclaration = false;
	std::string TypeName = "";
	std::string builder = "";
	if (IniFormat == 1)
	{
		bool InsideParenthesis = false;
		int LineSize;
		char LineChar;
		int CommandStage = 0;
		//IniDataV2Element ElementData = new IniDataV2Element();
		for (int Index = 0; Index < FileData.length(); ++Index)
		{
			LineData = FileData[Index];
			LineSize = LineData.length();
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
						TypeName = builder;
						InsideTypeDeclaration = false;
					}
					else
					{
						builder.append(&LineChar);//builder += LineChar;
					}
				}
				else if (LineChar == '(')
				{
					builder.clear(); InsideTypeDeclaration = true;
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
							CommandStage = 0;
							if (TypeName == "Int")
							{
								self.insert(IniSetting, IntDeclaration);
								TempIntPair = { IniSetting, VariableConversionFunctions::ReadIntFromString(IniValue) };
								IntSettings.insert(TempIntPair);
							}
							//else if(TypeName=="MediumDec")
							//{
							//	this.Add(IniSetting, MediumDecDeclaration);
							//	MediumDecSettings.Add(IniSetting, (MediumDec)IniValue);
							//}
							else
							{
								self.insert(IniSetting, IniValue);
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
		for (int Index = 0; Index < FileData.length(); ++Index)
		{
			LineData = FileData[Index];
			//foreach(char StringChar in LineData)
			//{
			//	if (InsideTypeDeclaration)
			//	{
			//		if (std::stringChar == ')')
			//		{
			//			TypeName = builder.Tostd::string();
			//			InsideTypeDeclaration = false;
			//		}
			//		else
			//		{
			//			builder.Append(std::stringChar);
			//		}
			//	}
			//	else if (StringChar == ':')
			//	{//IniSetting
			//		IniSetting = builder.Tostd::string();
			//		builder.Clear();
			//	}
			//	else if (StringChar == ';')
			//	{
			//		IniValue = builder.Tostd::string();
			//		builder.Clear();
			//if (TypeName == "Int")
			//{
			//	self.insert(IniSetting, IntDeclaration);
			//	TempIntPair = { IniSetting, VariableConversionFunctions::ReadIntFromString(IniValue) };
			//	IntSettings.insert(TempIntPair);
			//}
			////else if(TypeName=="MediumDec")
			////{
			////	this.Add(IniSetting, MediumDecDeclaration);
			////	MediumDecSettings.Add(IniSetting, (MediumDec)IniValue);
			////}
			//else
			//{
			//	self.insert(IniSetting, IniValue);
			//}

			//	}
			//	//else if (StringChar == '(')
			//	//{
			//	//	builder.Clear(); InsideTypeDeclaration = true;
			//	//}
			//	else if (std::stringChar == '/')//Start of line comment detected so skip rest of line
			//	{
			//		if (builder.Tostd::string() == "/")
			//		{
			//			builder.Clear();
			//			break;
			//		}
			//		else//False alarm on line comment detection
			//		{
			//			builder.Append(std::stringChar);
			//		}
			//	}
			//	else
			//	{
			//		switch (builder.Length)
			//		{ /* Ignore whitespace if no words started*/
			//		case 0 when std::stringChar == ' ':
			//			continue;
			//		default:
			//			builder.Append(std::stringChar);
			//			continue;
			//		}
			//	}
			//}
		}
	}
}

inline bool IniDataV2::CheckIfElementExists(std::string Value)
{
	return self.find(Value) != self.end();
}

///// <summary>
///// Gets the element data.
///// </summary>
///// <param name="Value">The value.</param>
///// <returns></returns>
//dynamic GetElementData(std::string Value)
//{
//	std::string ElementValue = (std::string)this[Value];
//	if (ElementValue == IntDeclaration)
//	{
//		return IntSettings[Value];//return VariableConversionFunctions.IntTostd::stringConversion(IntSettings[Value]);
//	}
//	//else if (ElementValue == MediumDecDeclaration)
//	//{
//	//	return MediumDecSettings[Value];
//	//}
//	else
//	{
//		return ElementValue;
//	}
//}
/// <summary>
/// Gets the element data as std::string
/// </summary>
/// <param name="Value">The value.</param>
/// <returns></returns>

inline std::string IniDataV2::GetElementData(std::string Value)
{
	std::unordered_map<std::string, std::string>::iterator ValueInfo = self.find(Value);
	if (ValueInfo == self.end())
	{
		return "";
	}
	else
	{
		std::string ElementValue = ValueInfo->second;
		if (ElementValue == IntDeclaration)
		{
			return VariableConversionFunctions::IntToStringConversion(IntSettings[Value]);
		}
		//else if (ElementValue == MediumDecDeclaration)
		//{
		//	return MediumDecSettings[Value].ToFullString();
		//}
		else
		{
			return ElementValue;
		}
	}
}

inline int IniDataV2::GetIntElementData(std::string Value)
{
	return IntSettings[Value];
}
