/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#pragma once
#ifndef IniDataV2_IncludeGuard
#define IniDataV2_IncludeGuard

#ifdef BLAZESGLOBALCODE_LIBRARY
#include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
#ifndef DLL_API
#define DLL_API
#endif
#endif

#include <string>

#ifdef BlazesGlobalCode_LocalLayout//(Local version style layout)
#include "StringVectorList.h"
#include "VariableConversionFunctions.h"
#include "CustomDictionary.h"
#else
#include "..\GlobalCode_VariableLists\StringVectorList.h"
#include "..\GlobalCode_VariableConversionFunctions\VariableConversionFunctions.h"
#include "CustomDictionary.h"
#endif

class DLL_API IniDataV2
{//Non-Ordered Version for now since don't really need Ini Saved in Order for now since not using categories
private:
    const std::string IntDeclaration = "#Int";
	const std::string FloatDeclaration = "#Float";
    const std::string MediumDecDeclaration = "#MediumDec";
public:
    /// <summary>
    /// The IniSettings with Int Values
    /// </summary>
    CustomDictionary<std::string, int> IntSettings = {};

#ifdef BlazesGlobalCode_EnableFloatingIni
	/// <summary>
	/// The IniSettings with Float Values
	/// </summary>
	CustomDictionary<std::string, float> FloatSettings = {};
#endif

	CustomDictionary<std::string, bool> BoolSettings = {};


#ifndef BlazesGlobalCode_DisableMediumDecIni
	///// <summary>
	///// The IniSettings with MediumDec Values
	///// </summary>
	//CustomDictionary<std::string, MediumDec> MediumDecSettings = {};
#endif

	///// <summary>
	///// The IniSettings with unsigned long Values
	///// </summary>
	//CustomDictionary<std::string, unsigned long> ULongSettings = {};

    /// <summary>
    /// IniSettings with string values and key linkage to IniSettings
    /// </summary>
    CustomDictionary<std::string, std::string> self = {};
	/// <summary>
	/// Loads the Ini data. (Returns false if fails to load data from file)
	/// </summary>
	/// <param name="FileName">Name of the file.</param>
	/// <param name="IniFormat">The ini storage format.
	/// (TypeDeclaration) + Other Formating
	/// 0 = IniSetting:IniValue; with single line comments removed(default)
	/// 1= [IniSetting=IniValue] format (based on my old C++ code)</param>
	/// <returns></returns>
	/// <summary>
	/// Loads the Ini data.
	/// </summary>
	/// <param name="FileName">Name of the file.</param>
	/// <param name="IniFormat">The ini storage format.
	/// (TypeDeclaration) + Other Formating
	/// 0 = IniSetting:IniValue; format(Default)
	/// 1= [IniSetting=IniValue] format (based on my old C++ code)
	/// </param>
	bool LoadIniData(std::string FileName, unsigned _int8 IniFormat = 0)
	{
		StringVectorList FileData;
		bool FileLoaded = FileData.LoadFileDataV2(FileName, 1);
		if (FileLoaded == false) { return false; }
		std::string LineData;
		std::string IniSetting = "";
		std::string IniValue = "";
		//byte InsideComment = 0;
		bool InsideTypeDeclaration = false;
		std::string TypeName = "";
		std::string builder = "";
		if (IniFormat == 1)
		{
			bool InsideParenthesis = false;
			size_t LineSize;
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
									self.Add(IniSetting, IntDeclaration);
									IntSettings.Add(IniSetting, VariableConversionFunctions::ReadIntFromString(IniValue));
								}
#ifdef BlazesGlobalCode_EnableFloatingIni
								else if (TypeName == "Float")
								{
									self.Add(IniSetting, FloatDeclaration);
									FloatSettings.Add(IniSetting, VariableConversionFunctions::ReadFloatFromString(IniValue));
								}
#endif
								else if (TypeName == "Bool")
								{
									self.Add(IniSetting, FloatDeclaration);
									BoolSettings.Add(IniSetting, VariableConversionFunctions::ReadBoolFromString(IniValue));
								}
#ifndef BlazesGlobalCode_DisableMediumDecIni
								//else if(TypeName=="MediumDec")
								//{
								//	self.Add(IniSetting, MediumDecDeclaration);
								//	MediumDecSettings.Add(IniSetting, (MediumDec)IniValue);
								//}
#endif
								else
								{
									self.Add(IniSetting, IniValue);
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
				for (const char StringChar : LineData)
				{
					if (InsideTypeDeclaration)
					{
						if (StringChar == ')')
						{
							TypeName = builder;
							InsideTypeDeclaration = false;
						}
						else
						{
							builder.append(&StringChar);
						}
					}
					else if (StringChar == ':')
					{//IniSetting
						IniSetting = builder;
						builder.clear();
					}
					else if (StringChar == ';')
					{
						IniValue = builder;
						builder.clear();
						if (TypeName == "Int")
						{
							self.Add(IniSetting, IntDeclaration);
							IntSettings.Add(IniSetting, VariableConversionFunctions::ReadIntFromString(IniValue));
						}

#ifdef BlazesGlobalCode_EnableFloatingIni
						//else if(TypeName=="Float")
						//{
						//	self.Add(IniSetting, MediumDecDeclaration);
						//	FloatSettings.Add(IniSetting, VariableConversionFunctions::ReadFloatFromString(IniValue));
						//}
#endif
#ifndef BlazesGlobalCode_DisableMediumDecIni
						//else if(TypeName=="MediumDec")
						//{
						//	self.Add(IniSetting, MediumDecDeclaration);
						//	MediumDecSettings.Add(IniSetting, (MediumDec)IniValue);
						//}
#endif
						else
						{
							self.Add(IniSetting, IniValue);
						}
					}
					else if (StringChar == '(')
					{
						builder.clear(); InsideTypeDeclaration = true;
					}
					else if (StringChar == '/')//Start of line comment detected so skip rest of line
					{
						if (builder == "/")
						{
							builder.clear();
							break;
						}
						else//False alarm on line comment detection
						{
							builder.append(&StringChar);
						}
					}
					else
					{
						if (builder.length() == 0)
						{
							continue;
						}
						else
						{
							builder.append(&StringChar);
							continue;
						}
					}
				}
			}
		}
		return true;
	}

	bool SaveIniData(std::string FileName, unsigned _int8 IniFormat = 0)
	{
		return false;
	}

	bool CheckIfElementExists(std::string Value)
	{
		return self.find(Value) != self.end();
	}

	bool Add(std::string Key, bool Value)
	{
		BoolSettings.Add(Key, Value);
	}

	bool Add(std::string Key, int Value)
	{
		IntSettings.Add(Key, Value);
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
	std::string GetElementData(std::string Value)
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
	/// <summary>
	/// Sets the string element data.
	/// </summary>
	/// <param name="Key">The key.</param>
	/// <param name="Value">The value.</param>
	void SetStringElementData(std::string Key, std::string Value)
	{
		self.Add(Key, Value);
	}
	/// <summary>
	/// Sets the string element data.
	/// </summary>
	/// <param name="Key">The key.</param>
	/// <param name="Value">if set to <c>true</c> then [value] is "true" otherwise "false".</param>
	void SetStringElementData(std::string Key, bool Value)
	{
		if(Value==true){ self.Add(Key, "true"); }
		else { self.Add(Key, "false"); }
		
	}
	/// <summary>
	/// Gets the int element data.
	/// </summary>
	/// <param name="Value">The value.</param>
	/// <returns></returns>
	int GetIntElementData(std::string Value)
	{
		return IntSettings[Value];
	}
	/// <summary>
	/// Sets the int element data.
	/// </summary>
	/// <param name="Key">The key.</param>
	/// <param name="Value">The value.</param>
	/// <summary>
	/// Sets the int element data.
	/// </summary>
	/// <param name="Key">The key.</param>
	/// <param name="Value">The value.</param>
	void SetIntElementData(std::string Key, int Value)
	{
		IntSettings.Add(Key, Value);
	}

	void AddIntElementData(std::string Key, int Value)
	{
		IntSettings[Key] += Value;
	}

#ifdef BlazesGlobalCode_EnableFloatingIni
	/// <summary>
	/// Gets the float element data.
	/// </summary>
	/// <param name="Value">The value.</param>
	/// <returns></returns>
	float GetFloatElementData(std::string Value);

	void SetFloatElementData(std::string Key, int Value)
	{
		FloatSettings.Add(Key, Value);
	}
#endif

	bool GetBoolElementData(std::string Value)
	{
		return BoolSettings[Value];
	}

	void SetBoolElementData(std::string Key, bool Value)
	{
		BoolSettings.Add(Key, Value);
	}

	bool ToggleBoolElementData(std::string Key)
	{
		bool Value = !this->BoolSettings[Key];
		BoolSettings[Key] = Value;
		return Value;
	}

#ifndef BlazesGlobalCode_DisableMediumDecIni
	//MediumDec GetMediumDecElementData(std::string Value){}
	void SetMediumDecElementData(std::string Key, int Value);
#endif

	size_t Size()
	{
		size_t TotalSize = IntSettings.size()+BoolSettings.size();
		return TotalSize;
	}
    IniDataV2() 
	{
		IntSettings = CustomDictionary<std::string, int>({});
		BoolSettings = CustomDictionary<std::string, bool>({});
	};
    ~IniDataV2() {};
};
#endif