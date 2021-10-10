// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// IniDataV2 varient with specific settings only stored and searched
// instead of having dynamic storage of lists(Unless MFCApp_StoreDynamicAppSettings is defined)
// ***********************************************************************
#pragma once
#ifndef AppSettings_IncludeGuard
#define AppSettings_IncludeGuard

#ifdef BlazesSharedCode_LocalLayout
#ifndef DLL_API
#ifdef UsingBlazesSharedCodeDLL
#define DLL_API __declspec(dllimport)
#elif defined(BLAZESSharedCode_LIBRARY)
#define DLL_API __declspec(dllexport)
#else
#define DLL_API
#endif
#endif
#else
#include "..\DLLAPI.h"
#endif

#include <string>

#include "..\VariableLists\StringVectorList.h"
#include "..\OtherFunctions\VariableConversionFunctions.h"
#ifdef BlazesMFCAppIni_EnableAltDec
   #include "..\AltNum\MediumDec.hpp"
#endif
#ifdef MFCApp_StoreDynamicAppSettings
#include "..\Databases\CustomDictionary.h"
#endif

/// <summary>
/// Class named AppSettings for settings Registry like data for app(without storing data inside registry).
/// </summary>
class DLL_API AppSettings
#ifdef MFCApp_StoreDynamicAppSettings
: public CustomDictionary<std::string, std::string>
#endif
{
#ifdef MFCApp_StoreDynamicAppSettings
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

#ifdef BlazesMFCAppIni_EnableFloat
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

#ifdef BlazesMFCAppIni_EnableAltDec
    /// <summary>
    /// The IniSettings with MediumDec Values
    /// </summary>
    CustomDictionary<std::string, MediumDec> MediumDecSettings = {};
#endif

    /// <summary>
    /// IniSettings with string values and key linkage to IniSettings
    /// </summary>
    CustomOrderedDictionary<std::string, std::string> self = {};
#endif
protected:
    bool CreateFileIfDoesntExist(std::string fileName)
    {
        bool FileExists = false;
        //Based on https://www.quora.com/What-is-the-best-way-to-check-whether-a-particular-file-exists-or-not-in-C++
        struct stat buffer;
        FileExists = (stat(fileName.c_str(), &buffer) == 0);
        //Based on http://stackoverflow.com/questions/17818099/how-to-check-if-a-file-exists-before-creating-a-new-file
        if (!FileExists)
        {
            std::ofstream file(fileName);
            if (!file)
            {
                std::cout << "File could not be created" << std::endl;
                return;
            }
        }
        return FileExists;
    }
#ifndef MFCApp_SaveFreshConfigFile
#endif
public:
    /// <summary>
    /// Loads the Ini data.
    /// </summary>
    /// <param name="FileName">Name of the file.</param>
    /// <param name="IniFormat">The ini storage format.
    /// (TypeDeclaration) + Other Formating
    /// IniSetting:IniValue; format is (Default)</param>
    /// if(MFCApp_UseOldIniDataFormatForSettings) enabled, then [IniSetting=IniValue] format (based on my old C++ code)</param>
    /// <returns>bool.</returns>
    bool Load()
    {
        StringVectorList FileData;
        bool FileLoaded = FileData.LoadFileDataV2("AppSettings.ini", 1);
        if (FileLoaded == false)
        { 
            SetToDefaultSettings(); return false;
        }
        std::string LineData;
        std::string IniSetting = "";
        std::string IniValue = "";
        //byte InsideComment = 0;
#ifdef MFCApp_StoreDynamicAppSettings
        std::string TypeName = "";
        bool InsideTypeDeclaration = false;
#endif
        std::string builder = "";
#ifdef MFCApp_UseOldIniDataFormatForSettings
        bool InsideParenthesis = false;
        int CommandStage = 0;
#endif
#ifdef MFCApp_StoreDynamicAppSettings

#endif
        for (int Index = 0; Index < FileData.length(); ++Index)
        {
            LineData = FileData[Index];
            for (const char LineChar : LineData)
            {
#ifdef MFCApp_UseOldIniDataFormatForSettings
                if (LineChar == '"') { InsideParenthesis = !InsideParenthesis; }
                else if (LineChar == '[')
                {
                    IniSetting = "";
                    CommandStage = 1;
                }
#ifdef MFCApp_StoreDynamicAppSettings
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
#endif
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
                            //if(IniSetting=="AppSetting")
                            //	AppSetting = IniValue=="true"?true:false;
#ifdef MFCApp_StoreDynamicAppSettings
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
#ifdef BlazesMFCAppIni_EnableAltDec
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
#else
                            //else
                                std::cout<<"Unknown setting named "+IniSetting+" not loaded from AppSettings.ini."<<std::endl;
#endif
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
#else
                if (LineChar == ':')
                {
                    IniSetting = builder;
                    builder.clear();
                }
#ifdef MFCApp_StoreDynamicAppSettings
                else if (InsideTypeDeclaration)
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
                else if (LineChar == '(')
                {
                    builder.clear(); InsideTypeDeclaration = true;
                }
#endif
                else if (LineChar == ';')
                {
                    IniValue = builder;
                    builder.clear();
                    //if(IniSetting=="AppSetting")
                    //	AppSetting = IniValue=="true"?true:false;
#ifdef MFCApp_StoreDynamicAppSettings
                        if (TypeName == "Int")
                        {
                            if(self.AddOnlyNew(IniSetting, IntDeclaration)){ IntSettings.Add(IniSetting, VariableConversionFunctions::ReadIntFromString(IniValue)); }
                        }
                        else if (TypeName == "Bool")
                        {
                            if (self.AddOnlyNew(IniSetting, BoolDeclaration)) { BoolSettings.Add(IniSetting, VariableConversionFunctions::ReadBoolFromString(IniValue)); }
                        }
#ifdef BlazesMFCAppIni_EnableFloat
                        else if (TypeName == "Float")
                        {
                            if (self.AddOnlyNew(IniSetting, FloatDeclaration)) { BoolSettings.Add(IniSetting, VariableConversionFunctions::ReadFloatFromString(IniValue)); }
                        }
#endif
#ifdef BlazesMFCAppIni_EnableAltDec
                        else if (TypeName == "MediumDec")
                        {
                            if (self.AddOnlyNew(IniSetting, MediumDecDeclaration)) { MediumDecSettings.Add(IniSetting, (MediumDec)IniValue); }
                        }
#endif
                        else//String Based Ini Setting
                        {
                            self.Add(IniSetting, IniValue);
                        }
#else
                    //else
                        std::cout<<"Unknown setting named "+IniSetting+" not loaded from AppSettings.ini."<<std::endl;
#endif


                }
                else if (LineChar == '/')//Start of line comment detected so skip rest of line
                {
                    if (builder == "/")
                    {
                        builder.clear();
                        break;
                    }
                    else//False alarm on line comment detection
                    {
                        builder.append(&LineChar);
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
                        builder.append(&LineChar);
                        continue;
                    }
                }
            }
#endif
        }
        return true;
    }

    /// <summary>
    /// Saves the INI data.
    /// </summary>
    /// <param name="FileName">Name of the file.</param>
    /// <param name="IniFormat">The INI format.</param>
    /// <returns>bool.</returns>
    bool Save()
    {
        std::string FilePath = "AppSettings.ini";
        size_t StringLength;
        char StringChar;
        std::string LineString;
        std::fstream LoadedFileStream;
#ifndef MFCApp_SaveFreshConfigFile
        bool CreatingFreshIni =
#endif
        CreateFileIfDoesntExist(FilePath);
        LoadedFileStream.open(FilePath.c_str(), std::fstream::out | std::fstream::trunc);
        if (LoadedFileStream.is_open())
        {
            if (LoadedFileStream.good())
            {//Saving to file now
#ifndef MFCApp_SaveFreshConfigFile
                if(CreatingFreshIni)
                {
#endif
#ifdef MFCApp_UseOldIniDataFormatForSettings//[IniSetting=IniValue]
                    //LoadedFileStream << "[IniSetting=";
                    //if(IniValue)
                    //	LoadedFileStream << "true";
                    //else
                    //	LoadedFileStream << "false";
                    //LoadedFileStream << "]\n";
#else//IniSetting:IniValue;
                    //LoadedFileStream << "IniSetting:";
                    //if(IniValue)
                    //	LoadedFileStream << "true";
                    //else
                    //	LoadedFileStream << "false";
                    //LoadedFileStream << ";\n";
#endif
#ifdef MFCApp_StoreDynamicAppSettings
                    if(!empty())
                    {
                        //LineString = ElementAt(0);
                        //StringLength = LineString.length();
                        //for (size_t StringIndex = 0; StringIndex < StringLength; ++StringIndex)
                        //{
                        //	StringChar = LineString.at(StringIndex);
                        //	LoadedFileStream << StringChar;
                        //}
                        //for (size_t i = 1; i < DataSize; ++i)
                        //{
                        //	//Carriage Return to next line
                        //	LoadedFileStream << "\n";
                        //	LineString = ElementAt(i);
                        //	StringLength = LineString.length();
                        //	for (size_t StringIndex = 0; StringIndex < StringLength; ++StringIndex)
                        //	{
                        //		StringChar = LineString.at(StringIndex);
                        //		LoadedFileStream << StringChar;
                        //	}
                        //}
                    }
#endif
#ifndef MFCApp_SaveFreshConfigFile
                }
                else
                {
                    while (inFile >> LineChar)
                    {
                    
                    }
                }
#endif
            }
            else
            {
                if (LoadedFileStream.bad()) { std::cout << "Failed Read/Write operation Error!\n"; }
                else if (LoadedFileStream.fail()) { std::cout << "Failed format based Error!\n"; }
                else if (LoadedFileStream.bad()) { std::cout << "Failed Read/Write operation Error!\n"; }
                else if (LoadedFileStream.eof()) {/*Send debug message of reaching end of file?*/ }
            }
            LoadedFileStream.close();
        }
        else
        {
            std::cout << "Failed to open " << FilePath << ".\n";
        }
        return false;
    }

#ifdef MFCApp_StoreDynamicAppSettings
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
#ifdef BlazesMFCAppIni_EnableFloat
            else if (ElementValue == FloatDeclaration)
            {
                return VariableConversionFunctions::FloatToStringConversion(FloatSettings[Value]);
            }
#endif
#ifdef BlazesMFCAppIni_EnableAltDec
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

#ifdef BlazesMFCAppIni_EnableFloat
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

#ifdef BlazesMFCAppIni_EnableAltDec
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
    /// Returns number of ini elements stored.
    /// </summary>
    /// <returns>size_t.</returns>
    size_t Size()
    {
        return self.size();
    }
#endif

#ifdef MFCApp_StoreDynamicAppSettings
    void clear()
    {
        IntSettings.clear();
        BoolSettings.clear();
#ifdef BlazesMFCAppIni_EnableFloat
        FloatSettings.clear();
#endif
#ifdef BlazesMFCAppIni_EnableAltDec
        MediumDecSettings.clear();
#endif
    }
#endif

    void SetToDefaultSettings()
    {
#ifdef MFCApp_StoreDynamicAppSettings
        clear();
#endif
    }

    /// <summary>
    /// Initializes a new instance of the <see cref="AppSettings" /> class.
    /// </summary>
    AppSettings()
    {
#ifdef MFCApp_StoreDynamicAppSettings
        IntSettings = CustomDictionary<std::string, int>({});
        BoolSettings = CustomDictionary<std::string, bool>({});
#ifdef BlazesMFCAppIni_EnableFloat
        FloatSettings = CustomDictionary<std::string, float>({});
#endif
#ifdef BlazesMFCAppIni_EnableAltDec
        MediumDecSettings = CustomDictionary<std::string, MediumDec>({});
#endif
#endif
        Load();
    };

#ifdef MFCApp_StoreDynamicAppSettings
    /// <summary>
    /// Copies the data.
    /// </summary>
    /// <param name="additionTagOptions">The addition tag options.</param>
    void CopyData(AppSettings additionTagOptions)
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
#ifdef BlazesMFCAppIni_EnableAltDec
            else if(TempString==MediumDecDeclaration)
            {
                Add(it.key(), additionTagOptions.MediumDecSettings[it.key()]);
            }
#endif
#ifdef BlazesMFCAppIni_EnableFloat
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
#endif

    /// <summary>
    /// Finalizes an instance of the <see cref="AppSettings" /> class.
    /// </summary>
    ~AppSettings() {};
};

#ifdef MFCApp_StoreDynamicAppSettings
const std::string IniDataV2::BoolDeclaration = "#Bool";
const std::string IniDataV2::IntDeclaration = "#Int";
const std::string IniDataV2::VoidDeclaration = "#Void";
#ifdef BlazesMFCAppIni_EnableAltDec
    const std::string IniDataV2::MediumDecDeclaration = "#MediumDec";
#endif
#ifdef BlazesMFCAppIni_EnableFloat
    const std::string IniDataV2::FloatDeclaration = "#Float";
#endif
#endif

#endif