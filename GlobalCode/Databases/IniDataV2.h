// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#pragma once
#ifndef IniDataV2_IncludeGuard
#define IniDataV2_IncludeGuard

#ifdef BlazesGlobalCode_LocalLayout
#ifndef DLL_API
#ifdef UsingBlazesGlobalCodeDLL
#define DLL_API __declspec(dllimport)
#elif defined(BLAZESGLOBALCODE_LIBRARY)
#define DLL_API __declspec(dllexport)
#else
#define DLL_API
#endif
#endif
#else
#include "..\DLLAPI.h"
#endif

#include <string>

#include "CustomDictionary.h"
#include "CustomOrderedDictionary.h"
#ifdef BlazesGlobalCode_LocalLayout//(Local version style layout)
    #include "StringVectorList.h"
    #include "VariableConversionFunctions.h"
#else
    #include "..\VariableLists\StringVectorList.h"
    #include "..\OtherFunctions\VariableConversionFunctions.h"
    #ifdef IniDataV2_EnableAltDec
        #include "..\AltNum\MediumDec.hpp"
    #endif
#endif

/// <summary>
/// Class named IniDataV2.
/// </summary>
class DLL_API IniDataV2
{
public:
    /// <summary>
    /// The int declaration
    /// </summary>
    const static std::string IntDeclaration;
    /// <summary>
    /// The medium decimal declaration
    /// </summary>
    const static std::string MediumDecDeclaration;
    /// <summary>
    /// The bool declaration
    /// </summary>
    const static std::string BoolDeclaration;
    /// <summary>
    /// The Void declaration(No Parameter Value)
    /// </summary>
    const static std::string VoidDeclaration;

    /// <summary>
    /// The IniSettings with Int Values
    /// </summary>
    CustomDictionary<std::string, int> IntSettings = {};

#ifndef IniDataV2_DisableFloat
    /// <summary>
    /// The float declaration
    /// </summary>
    const static std::string FloatDeclaration;

    /// <summary>
    /// The IniSettings with Float Values
    /// </summary>
    CustomDictionary<std::string, float> FloatSettings = {};
#endif

    /// <summary>
    /// The bool settings
    /// </summary>
    CustomDictionary<std::string, bool> BoolSettings = {};

#ifdef IniDataV2_EnableAltDec
    /// <summary>
    /// The IniSettings with MediumDec Values
    /// </summary>
    CustomDictionary<std::string, MediumDec> MediumDecSettings = {};
#endif

    /// <summary>
    /// IniSettings with string values and key linkage to IniSettings
    /// </summary>
    CustomOrderedDictionary<std::string, std::string> self = {};

    /// <summary>
    /// Loads the Ini data.
    /// </summary>
    /// <param name="FileName">Name of the file.</param>
    /// <param name="IniFormat">The ini storage format.
    /// (TypeDeclaration) + Other Formating
    /// 0 = IniSetting:IniValue; format(Default)
    /// 1= [IniSetting=IniValue] format (based on my old C++ code)</param>
    /// <returns>bool.</returns>
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
#ifdef IniDataV2_DisableFloat
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
#ifdef IniDataV2_EnableAltDec
                                else if (TypeName == "MediumDec")
                                {
                                    self.Add(IniSetting, MediumDecDeclaration);
                                    MediumDecSettings.Add(IniSetting, (MediumDec)IniValue);
                                }
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
                            if(self.AddOnlyNew(IniSetting, IntDeclaration)){ IntSettings.Add(IniSetting, VariableConversionFunctions::ReadIntFromString(IniValue)); }
                        }
                        else if (TypeName == "Bool")
                        {
                            if (self.AddOnlyNew(IniSetting, BoolDeclaration)) { BoolSettings.Add(IniSetting, VariableConversionFunctions::ReadBoolFromString(IniValue)); }
                        }
#ifndef IniDataV2_DisableFloat
                        else if (TypeName == "Float")
                        {
                            if (self.AddOnlyNew(IniSetting, FloatDeclaration)) { BoolSettings.Add(IniSetting, VariableConversionFunctions::ReadFloatFromString(IniValue)); }
                        }
#endif
#ifdef IniDataV2_EnableAltDec
                        else if (TypeName == "MediumDec")
                        {
                            if (self.AddOnlyNew(IniSetting, MediumDecDeclaration)) { MediumDecSettings.Add(IniSetting, (MediumDec)IniValue); }
                        }
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


    /// <summary>
    /// Saves the INI data.
    /// </summary>
    /// <param name="FileName">Name of the file.</param>
    /// <param name="IniFormat">The INI format.</param>
    /// <returns>bool.</returns>
    bool SaveIniData(std::string FileName, unsigned _int8 IniFormat = 0)
    {
        return false;
    }


    /// <summary>
    /// Checks if element exists.
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>bool.</returns>
    bool CheckIfElementExists(std::string Value)
    {
        return self.find(Value) != self.end();
    }


    /// <summary>
    /// Adds the specified key.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    /// <returns>bool</returns>
    bool Add(std::string Key, bool Value)
    {
        if (self.AddOnlyNew(Key, BoolDeclaration)) { BoolSettings.AddOnlyNew(Key, Value); return true; }
        else { return false; }
    }


    /// <summary>
    /// Adds the specified key.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    /// <returns>bool</returns>
    bool Add(std::string Key, int Value)
    {
        if (self.AddOnlyNew(Key, IntDeclaration)) { return IntSettings.AddOnlyNew(Key, Value); return true; }
        else { return false; }
    }

    /// <summary>
    /// Adds the specified key.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    /// <returns>bool</returns>
    bool Add(std::string Key, std::string Value)
    {
        return self.AddOnlyNew(Key, Value);
    }

/// <summary>
/// Gets the element data.
/// </summary>
/// <param name="Value">The value.</param>
/// <returns>std::string</returns>
    std::string GetElementData(std::string Value)
    {
        tsl::ordered_map<std::string, std::string>::iterator ValueInfo = self.find(Value);
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
            else if (ElementValue == BoolDeclaration)
            {
                if(BoolSettings[Value]==true)
                {
                    return "true";
                }
                else
                {
                    return "false";
                }
            }
#ifndef IniDataV2_DisableFloat
            else if (ElementValue == FloatDeclaration)
            {
                return VariableConversionFunctions::FloatToStringConversion(FloatSettings[Value]);
            }
#endif
#ifdef IniDataV2_EnableAltDec
            else if (ElementValue == MediumDecDeclaration)
            {
                return MediumDecSettings[Value].ToFullString();
            }
#endif
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
    /// <returns>int.</returns>
    int GetIntElementData(std::string Value)
    {
        return IntSettings[Value];
    }



    /// <summary>
    /// Sets the int element data.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void SetIntElementData(std::string Key, int Value)
    {
        if (Add(Key, Value) == false) {//Only set Int Element setting if key already exists
            std::unordered_map<std::string, int>::iterator ValueInfo = IntSettings.find(Key);
            if (ValueInfo != IntSettings.end())
            {
                IntSettings.Add(Key, Value);
            }
        }
    }


    /// <summary>
    /// Adds the int element data.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void AddIntElementData(std::string Key, int Value)
    {
        IntSettings[Key] += Value;
    }

#ifndef IniDataV2_DisableFloat
    /// <summary>
    /// Adds the specified key.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    /// <returns>bool</returns>
    bool Add(std::string Key, float Value)
    {
        if (self.AddOnlyNew(Key, FloatDeclaration)) { return FloatSettings.AddOnlyNew(Key, Value); return true; }
        else { return false; }
    }

    /// <summary>
    /// Gets the float element data.
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>float</returns>
    float GetFloatElementData(std::string Value){return FloatSettings[Value];}


    /// <summary>
    /// Sets the float element data.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void SetFloatElementData(std::string Key, int Value)
    {
        FloatSettings.Add(Key, Value);
    }
#endif


    /// <summary>
    /// Gets the element data.
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>bool</returns>
    bool GetBoolElementData(std::string Value)
    {
        return BoolSettings[Value];
    }


    /// <summary>
    /// Sets the element data.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void SetBoolElementData(std::string Key, bool Value)
    {
        BoolSettings.Add(Key, Value);
    }


    /// <summary>
    /// Toggle the element data.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <returns>bool</returns>
    bool ToggleBoolElementData(std::string Key)
    {
        bool Value = !this->BoolSettings[Key];
        BoolSettings[Key] = Value;
        return Value;
    }

#ifdef IniDataV2_EnableAltDec
    /// <summary>
    /// Adds the specified key.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    /// <returns>bool</returns>
    bool Add(std::string Key, MediumDec Value)
    {
        if (self.AddOnlyNew(Key, MediumDecDeclaration)) { return MediumDecSettings.AddOnlyNew(Key, Value); return true; }
        else { return false; }
    }


    /// <summary>
    /// Adds the medium decimal element data.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void AddMediumDecElementData(std::string Key, MediumDec Value)
    {
        MediumDecSettings[Key] += Value;
    }


    /// <summary>
    /// Gets the medium decimal element data.
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>MediumDec.</returns>
    MediumDec GetMediumDecElementData(std::string Value)
    {
        return MediumDecSettings[Value];
    }


    /// <summary>
    /// Sets the medium decimal element data.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void SetMediumDecElementData(std::string Key, MediumDec Value)
    {
        if (Add(Key, Value) == false) {//Only set Int Element setting if key already exists
            std::unordered_map<std::string, MediumDec>::iterator ValueInfo = MediumDecSettings.find(Key);
            if (ValueInfo != MediumDecSettings.end())
            {
                MediumDecSettings.Add(Key, Value);
            }
        }
    }
#endif


    /// <summary>
    /// Sizes this instance.
    /// </summary>
    /// <returns>size_t.</returns>
    size_t Size()
    {
        return self.size();
    }

    //std::string operator[](int Index)
    //{
    //    return self.KeyAt(Index);
    //}

    /// <summary>
    /// Initializes a new instance of the <see cref="IniDataV2" /> class.
    /// </summary>
    IniDataV2()
    {
        IntSettings = CustomDictionary<std::string, int>({});
        BoolSettings = CustomDictionary<std::string, bool>({});
#ifndef IniDataV2_DisableFloat
        FloatSettings = CustomDictionary<std::string, float>({});
#endif
#ifdef IniDataV2_EnableAltDec
        MediumDecSettings = CustomDictionary<std::string, MediumDec>({});
#endif
    };

    /// <summary>
    /// Copies the data.
    /// </summary>
    /// <param name="additionTagOptions">The addition tag options.</param>
    void CopyData(IniDataV2 additionTagOptions)
    {
        std::string TempString;
        for (auto it = additionTagOptions.self.begin(); it != additionTagOptions.self.end(); ++it) {
            //it.key();
            TempString = it.value();
            if (TempString == IntDeclaration)
            {
                Add(it.key(), additionTagOptions.IntSettings[it.key()]);
            }
            else if(TempString==BoolDeclaration)
            {
                Add(it.key(), additionTagOptions.BoolSettings[it.key()]);
            }
#ifdef IniDataV2_EnableAltDec
            else if(TempString==MediumDecDeclaration)
            {
                Add(it.key(), additionTagOptions.MediumDecSettings[it.key()]);
            }
#endif
#ifndef IniDataV2_DisableFloat
            else if(TempString==FloatDeclaration)
            {
                Add(it.key(), additionTagOptions.FloatSettings[it.key()]);
            }
#endif
            else
            {
                Add(it.key(), TempString);
            }
        }
    }

    /// <summary>
    /// Finalizes an instance of the <see cref="IniDataV2" /> class.
    /// </summary>
    ~IniDataV2() {};
};

const std::string IniDataV2::BoolDeclaration = "#Bool";
const std::string IniDataV2::IntDeclaration = "#Int";
const std::string IniDataV2::VoidDeclaration = "#Void";
#ifdef IniDataV2_EnableAltDec
    const std::string IniDataV2::MediumDecDeclaration = "#MediumDec";
#endif
#ifndef IniDataV2_DisableFloat
    const std::string IniDataV2::FloatDeclaration = "#Float";
#endif

#endif