/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/

#include "MiscFunctions.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

#ifdef BlazesSharedCode_LocalLayout//(Local version style layout)
#include "StringFunctions.h"
#else
#include "..\OtherFunctions\StringFunctions.h"
#endif

using std::string;

void MiscFunctions::VariableScanning::ScanData(string LineString)
{
    TabLevel = StringFunctions::ExamineTabSpace(LineString);
    VariableTypeName = "";
    VariableName = "";
    VariableTypeScanned = false;
    VariableNameScanned = false;
    if(LineCommentType)
    {
        ScanningComments = false;
        CommentStringBuffer = "";
    }
    StringLength = LineString.length();
    TempInt = StringLength - 1;
    for(size_t i = 0; i < StringLength; ++i)
    {
        StringChar = LineString.at(i);
        if(ScanningComments)
        {
            if(LineCommentType == false)
            {
                if(StringChar == '*')
                {
                    CommentStringBuffer = "*";
                }
                else if(StringChar == '/'&&CommentStringBuffer == "*")
                {
                    ScanningComments = false;
                    CommentStringBuffer = "";
                    if(DisplayCommentsToConsole) { std::cout << "\n"; }
                    if(SaveCommentData)
                    {
                        CommentDataBuffer.Add(CommentDataString);
                        CommentDataString = "";
                    }
                }
                else
                {
                    if(SaveCommentData) { CommentDataString += StringChar; }
                    if(SaveCommentData&&i >= TempInt)
                    {
                        CommentDataBuffer.Add(CommentDataString);
                        CommentDataString = "";
                    }
                    if(DisplayCommentsToConsole) { std::cout << StringChar; }
                    CommentStringBuffer += StringChar;
                }
            }
            //End of LineString
            else if(i >= TempInt)
            {
                if(SaveCommentData)
                {
                    CommentDataString += StringChar;
                    CommentDataBuffer.Add(CommentDataString);
                    CommentDataString = "";
                }
                if(DisplayCommentsToConsole) { std::cout << StringChar; }
                if(DisplayCommentsToConsole) { std::cout << "\n"; }
            }
            else
            {
                if(SaveCommentData) { CommentDataString += StringChar; }
                if(DisplayCommentsToConsole) { std::cout << StringChar; }
            }
        }
        else if(StringChar == '*'&&CommentStringBuffer == "/")
        {
            LineCommentType = false;
            ScanningComments = true;
            CommentDataString = "";
        }
        else if(StringChar == '/')
        {
            CommentStringBuffer += '/';
            if(CommentStringBuffer == "//")
            {
                LineCommentType = true;
                ScanningComments = true;
                CommentDataString = "";
            }
            else if(CommentStringBuffer != "/")
            {//Force buffer as "/" if anything other
                CommentStringBuffer = "/";
            }
            else if(CommentStringBuffer.size() > 2)
            {
                CommentStringBuffer = "";
            }
        }
        else if(StringChar != ' ' && StringChar != '	' && StringChar != ';'&&StringChar != '=')
        {
            if(VariableTypeScanned == false)
            {
                VariableTypeName += StringChar;
            }
            else if(VariableNameScanned == false)
            {
                VariableName += StringChar;
            }
        }
        else
        {
            if(VariableTypeScanned == false)
            {
                if(VariableTypeName != "")
                {
                    VariableTypeScanned = true;
                }
            }
            else if(VariableNameScanned == false)
            {
                if(VariableName != "")
                {
                    VariableNameScanned = true;
                }
            }
            if(VariableTypeScanned&&VariableNameScanned)
            {
                SendVariableAssignmentInfo();
                i = StringLength;
            }
        }
    }
}

void MiscFunctions::VariableScanning::SendVariableAssignmentInfo()
{
    size_t CommentSize;
    string TempComment = "";
    //Create Lines of code for variable set function
    if(VariableName != ""&&VariableTypeName != "")
    {
        //Only add Non-used Variable to lists
        if(VariableNameList.ElementExists(VariableName) == false)
        {
            VariableNameList.Add(VariableName);
            VariableTypeList.Add(VariableTypeName);
            CommentSize = CommentDataBuffer.Size();
            for(size_t i = 0; i < CommentSize; i++)
            {
                if(i != 0)
                {
                    TempComment += "\n";
                }
                TempComment += CommentDataBuffer.ElementAt(i);
            }
            LinkedCommentData.Add(TempComment);
        }
        else
        {
            std::cout << "Duplicate Variable Data Found!\n" << VariableName << " already used.\n";
        }
        VariableName = "";
        VariableTypeName = "";
        CommentDataBuffer.Reset();
    }
}

void MiscFunctions::VariableScanning::CreateFileWithVariableData(string FileName)
{
    string LineString;
    std::fstream OutputStream;
    OutputStream.open(FileName, std::ios::out | std::ios::trunc);
    if(OutputStream.fail())
    {
        std::cout << "Output file opening failed.\n";
        system("pause");
        //exit(1);
    }
    //Double check to ensure both same size and not empty
    size_t ListSize = VariableNameList.Size();
    bool TempBool;
    if(ListSize > 0 && ListSize == VariableTypeList.Size())
    {
        for(size_t LineNumber = 0; VariableNameList.StreamLineData(); ++LineNumber)
        {
            CommentDataString = LinkedCommentData.ElementAt(LineNumber);
            if(CommentDataString != "")
            {
                if(LineNumber == 0)
                {
                    LineString = "";
                }
                else
                {
                    LineString = "\n";
                }
                //Detect between comment types
                TempBool = MiscFunctions::FindWrappedText(CommentDataString, "\n");
                if(TempBool)
                {
                    LineString += ("/* " + CommentDataString + " */");
                }
                else
                {
                    LineString += ("//" + CommentDataString);
                }
                if(LineNumber == 0)
                {
                    LineString += "\n";
                }
                OutputStream << LineString;
            }

            LineString = ReconstructVariableAssignment(VariableNameList.CurrentStreamedLineString(), VariableTypeList.ElementAt(LineNumber));
            if(LineNumber != 0)
            {
                OutputStream << "\n";
            }
            OutputStream << LineString;
        }
    }
    OutputStream.close();
}

string MiscFunctions::VariableScanning::ReconstructVariableAssignment(string Name, string Type)
{
    string TempString = Type + " " + Name;
    //Ensure all variables properly initialized
    if(Type == "bool")
    {
        TempString += " = false;";
    }
    else if(Type == "int")
    {
        TempString += " = 0;";
    }
    else if(Type == "double")
    {
        TempString += " = 0.0;";
    }
    else if(Type == "string")
    {
        TempString += " = \"\";";
    }
    else
    {
        TempString += ";";
    }
    TempString += "\n";
    TempString += "void Set_";
    TempString += Name;
    TempString += "(";
    TempString += Type;
    TempString += " temp)\n";
    TempString += "{\n";
    TempString += "\t";
    TempString += Name;
    TempString += " = temp;\n";
    TempString += "}";
    if(CreateGetFunctions)
    {
        TempString += "\n";
        TempString += Type;
        TempString += " Get_";
        TempString += Name;
        TempString += "()\n";
        TempString += "{\n";
        TempString += "\t";
        TempString += "return ";
        TempString += Name;
        TempString += ";\n";
        TempString += "}";
    }
    return TempString;
}

bool MiscFunctions::RearrangedVariableDataFromFile(std::string FileName, std::string OutputFileName)
{
    bool FileStreamOpen = false;
    int FileStreamState = 0;
    string LineString = "";
    string LineChar;
    char NextChar = ' ';
    std::fstream LoadedFileStream;
    VariableScanning VariableScanningData;
    while(FileStreamState >= 0)
    {
        if(FileStreamOpen == false)
        {
            LoadedFileStream.open(FileName);//, std::ios::in | std::ios::out
            FileStreamState = 1;
            FileStreamOpen = true;
            //return 1;
        }
        else if(LoadedFileStream.is_open())
        {
            NextChar = LoadedFileStream.peek();
            if(LoadedFileStream.good())
            {//Current Line has data in it
                LineChar = LoadedFileStream.get();
                if(LineChar == "\n")
                {
                    VariableScanningData.ScanData(LineString);
                    LineString = "";
                }
                else
                {
                    LineString += LineChar;
                }
                FileStreamState = 2;
            }
            else if(NextChar == EOF || LoadedFileStream.eof())
            {
                if(LineString != "")
                {
                    VariableScanningData.ScanData(LineString);
                    LineString = "";
                }
                std::cout << "Reached end of file Data Loaded \n";
                FileStreamState = 3;
                LoadedFileStream.close();
                VariableScanningData.CreateFileWithVariableData(OutputFileName);
                FileStreamState = -3;
            }
            else
            {
                if(LoadedFileStream.bad())
                {
                    std::cout << "Failed Read/Write operation Error \n";
                    FileStreamState = -1;
                }
                else if(LoadedFileStream.fail())
                {
                    std::cout << "Failed format-based Error \n";
                    FileStreamState = -1;
                }
                else if(LoadedFileStream.bad())
                {
                    std::cout << "Failed Read/Write operation Error \n";
                    FileStreamState = -1;
                }
                else
                {
                    std::cout << "Error Number -2 \n";
                    FileStreamState = -2;
                }
            }
        }
        else
        {
            std::cout << "Failed to open" << FileName << "\n";
            if(LoadedFileStream.eof())
            {
                std::cout << "Reached end of file Error \n";
            }
            else if(LoadedFileStream.bad())
            {
                std::cout << "Failed Read/Write operation Error \n";
            }
            else if(LoadedFileStream.fail())
            {
                std::cout << "Failed format-based Error \n";
            }
            else if(LoadedFileStream.bad())
            {
                std::cout << "Failed Read/Write operation Error \n";
            }
            FileStreamState = 0;
        }
    }
    if(FileStreamState == -3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

MiscFunctions::MiscFunctions()
{}

MiscFunctions::~MiscFunctions()
{}

bool MiscFunctions::TextNotFound(std::string LineString, std::string SearchedString)
{
    bool Success = false;
    string StringBuffer = "";
    char LineChar;
    size_t StringLength;
    size_t TempInt = 0;
    StringLength = LineString.length();
    //Double-checks to ensure Search does not exceed SearchedString.Size()---Although impossible to fail unless major glitch occurs
    size_t SearchLength;
    SearchLength = SearchedString.size();
    for(size_t i = 0; i < StringLength&&Success == false && i < SearchLength; ++i)
    {
        LineChar = LineString.at(i);
        if(StringBuffer == "")
        {
            if(LineChar == SearchedString.at(0))
            {
                StringBuffer = LineChar;
                TempInt = 1;
            }
        }
        else
        {
            if(LineChar == SearchedString.at(TempInt))
            {
                StringBuffer += LineChar;
                TempInt++;
            }
            else
            {
                StringBuffer = "";
            }
        }
        if(StringBuffer == SearchedString)
        {
            Success = true;
        }
    }
    Success = !Success;
    return Success;
}

bool MiscFunctions::FindWrappedText(std::string LineString, std::string SearchedString)
{
    bool Success = false;
    string StringBuffer = "";
    char LineChar;
    size_t StringLength;
    size_t TempInt = 0;
    StringLength = LineString.length();
    //Double-checks to ensure Search does not exceed SearchedString.Size()---Although impossible to fail unless major glitch occurs
    size_t SearchLength;
    SearchLength = SearchedString.size();
    for(size_t i = 0; i < StringLength&&Success == false && i < SearchLength; ++i)
    {
        LineChar = LineString.at(i);
        if(StringBuffer == "")
        {
            if(LineChar == SearchedString.at(0))
            {
                StringBuffer = LineChar;
                TempInt = 1;
            }
        }
        else
        {
            if(LineChar == SearchedString.at(TempInt))
            {
                StringBuffer += LineChar;
                TempInt++;
            }
            else
            {
                StringBuffer = "";
            }
        }
        if(StringBuffer == SearchedString)
        {
            Success = true;
        }
    }
    return Success;
}

std::string MiscFunctions::ConvertFileToString(std::string FileName)
{
    string ConvertedString = "";
    bool FileStreamOpen = false;
    unsigned __int8 FileStreamState = 0;
    string LineString = "";
    string LineChar;
    char NextChar = ' ';
    std::fstream LoadedFileStream;
    while(FileStreamState >= 0)
    {
        if(FileStreamOpen == false)
        {
            LoadedFileStream.open(FileName, std::ios::in);
            FileStreamState = 1;
            FileStreamOpen = true;
            //return 1;
        }
        else if(LoadedFileStream.is_open())
        {
            NextChar = LoadedFileStream.peek();
            if(LoadedFileStream.good())
            {//Current Line has data in it
                LineChar = LoadedFileStream.get();
                ConvertedString += LineChar;
                FileStreamState = 2;
            }
            else if(NextChar == EOF || LoadedFileStream.eof())
            {
                std::cout << "Reached end of file Data Loaded \n";
                LoadedFileStream.close();
                FileStreamState = -3;
            }
            else
            {
                if(LoadedFileStream.bad())
                {
                    std::cout << "Failed Read/Write operation Error \n";
                    FileStreamState = -1;
                }
                else if(LoadedFileStream.fail())
                {
                    std::cout << "Failed format-based Error \n";
                    FileStreamState = -1;
                }
                else if(LoadedFileStream.bad())
                {
                    std::cout << "Failed Read/Write operation Error \n";
                    FileStreamState = -1;
                }
                else
                {
                    std::cout << "Error Number -2 \n";
                    FileStreamState = -2;
                }
                LoadedFileStream.close();
            }
        }
        else
        {
            std::cout << "Failed to open" << FileName << "\n";
            if(LoadedFileStream.eof())
            {
                std::cout << "Reached end of file Error \n";
            }
            else if(LoadedFileStream.bad())
            {
                std::cout << "Failed Read/Write operation Error \n";
            }
            else if(LoadedFileStream.fail())
            {
                std::cout << "Failed format-based Error \n";
            }
            else if(LoadedFileStream.bad())
            {
                std::cout << "Failed Read/Write operation Error \n";
            }
            FileStreamState = 0;
        }
    }
    return ConvertedString;
}

void MiscFunctions::ConvertStringToFile(std::string FileName, std::string TargetString)
{
    size_t StringSize;
    StringSize = TargetString.size();
    std::fstream OutputStream;
    OutputStream.open(FileName, std::ios::out | std::ios::trunc);
    if(OutputStream.fail())
    {
        std::cout << "Output file opening failed.\n";
        system("pause");
        exit(1);
    }
    for(int i = 0; i < StringSize; i++)
    {
        OutputStream << TargetString.at(i);
    }
    OutputStream.close();
}

bool MiscFunctions::IsRecordedHavokClassType(std::string HavokClass)
{
    if(HavokClass == "BSIsActiveModifier")
    {
        return true;
    }
    if(HavokClass == "hkbVariableBindingSet")
    {
        return true;
    }
    if(HavokClass == "BSBoneSwitchGenerator")
    {
        return true;
    }
    if(HavokClass == "BSBoneSwitchGeneratorBoneData")
    {
        return true;
    }
    if(HavokClass == "BSDirectAtModifier")
    {
        return true;
    }
    if(HavokClass == "BSEventOnDeactivateModifier")
    {
        return true;
    }
    if(HavokClass == "BSEventOnFalseToTrueModifier")
    {
        return true;
    }
    if(HavokClass == "BSCyclicBlendTransitionGenerator")
    {
        return true;
    }
    if(HavokClass == "BSModifyOnceModifier")
    {
        return true;
    }
    if(HavokClass == "BSSpeedSamplerModifier")
    {
        return true;
    }
    if(HavokClass == "BSSynchronizedClipGenerator")
    {
        return true;
    }
    if(HavokClass == "hkbBehaviorGraphData")
    {
        return true;
    }
    if(HavokClass == "hkbBehaviorReferenceGenerator")
    {
        return true;
    }
    if(HavokClass == "hkbBlenderGenerator")
    {
        return true;
    }
    if(HavokClass == "hkbBlendingTransitionEffect")
    {
        return true;
    }
    if(HavokClass == "hkbBoneIndexArray")
    {
        return true;
    }
    if(HavokClass == "hkbBoneWeightArray")
    {
        return true;
    }
    if(HavokClass == "hkbClipGenerator")
    {
        return true;
    }
    if(HavokClass == "hkbClipTriggerArray")
    {
        return true;
    }
    if(HavokClass == "hkbDampingModifier")
    {
        return true;
    }
    if(HavokClass == "hkbEvaluateExpressionModifier")
    {
        return true;
    }
    if(HavokClass == "hkbEventDrivenModifier")
    {
        return true;
    }
    if(HavokClass == "hkbFootIkControlsModifier")
    {
        return true;
    }
    if(HavokClass == "hkbKeyframeBonesModifier")
    {
        return true;
    }
    if(HavokClass == "hkbManualSelectorGenerator")
    {
        return true;
    }
    if(HavokClass == "hkbModifierGenerator")
    {
        return true;
    }
    if(HavokClass == "hkbModifierList")
    {
        return true;
    }
    if(HavokClass == "hkbPoseMatchingGenerator")
    {
        return true;
    }
    if(HavokClass == "hkbPoweredRagdollControlsModifier")
    {
        return true;
    }
    if(HavokClass == "hkbRigidBodyRagdollControlsModifier")
    {
        return true;
    }
    if(HavokClass == "hkbStateMachine")
    {
        return true;
    }
    if(HavokClass == "hkbStateMachineEventPropertyArray")
    {
        return true;
    }
    if(HavokClass == "hkbStateMachineStateInfo")
    {
        return true;
    }
    if(HavokClass == "hkbStateMachineTransitionInfoArray")
    {
        return true;
    }
    if(HavokClass == "hkbStringEventPayload")
    {
        return true;
    }
    if(HavokClass == "hkbTimerModifier")
    {
        return true;
    }
    if(HavokClass == "hkbTwistModifier")
    {
        return true;
    }
    if(HavokClass == "hkRootLevelContainer")
    {
        return true;
    }
    if(HavokClass == "hkbBlenderGeneratorChild")
    {
        return true;
    }
    return false;
}

string MiscFunctions::ExtractFirstTagContents(std::string LineString)
{
    string TagContents = "";
    bool TagHeaderFound = false, TagFooterFound = false, ExtractingContents = false, InsideParenthesis = false, IsFooterTag = false;
    string StringChar, StringBuffer = "";
    size_t StringLength, TempInt;
    StringLength = LineString.length();
    TempInt = StringLength - 1;
    for(size_t i = 0; i < StringLength&&TagFooterFound == false; ++i)
    {
        StringChar = LineString.at(i);
        if(StringChar == "\"")
        {
            InsideParenthesis = !InsideParenthesis;
        }
        if(TagHeaderFound)
        {
            if(InsideParenthesis == false && StringChar == "<")
            {
                ExtractingContents = false;
                TagFooterFound = true;
            }
            else
            {
                TagContents += StringChar;
            }
        }
        else
        {
            if(StringBuffer == ""&&StringChar == "<")
            {
                StringBuffer = "<";
            }
            else
            {
                //Prevent XML tag param contents from closing tag early
                if(InsideParenthesis == false && StringChar == ">")
                {
                    if(IsFooterTag)
                    {
                        StringBuffer = "";
                        IsFooterTag = false;
                    }
                    else
                    {
                        TagHeaderFound = true;
                        std::cout << "TagHeader:" << StringBuffer << ">\n";
                        StringBuffer = "";
                    }
                }
                else
                {
                    StringBuffer += StringChar;
                    if(StringBuffer == "</")
                    {
                        //Found Footer type tag instead of Header tag
                        IsFooterTag = true;
                    }
                }
            }
        }
    }
    return TagContents;
}

std::string MiscFunctions::RemoveExcessSpacing(std::string LineString)
{
    string TempString = "";
    bool SpacingUsed = false;
    string StringChar, StringBuffer = "";
    size_t StringLength;
    StringLength = LineString.length();
    for(size_t i = 0; i < StringLength; i++)
    {
        StringChar = LineString.at(i);
        if(SpacingUsed)
        {
            if(StringChar == "\t")
            {
            }
            else if(StringChar == " ")
            {
            }
            else if(StringChar == "\n")
            {
            }
            else
            {
                TempString += StringChar;
                SpacingUsed = false;
            }
        }
        else
        {
            if(StringChar == "\t")
            {
                TempString += " ";
                SpacingUsed = true;
            }
            else if(StringChar == " ")
            {
                TempString += StringChar;
                SpacingUsed = true;
            }
            //Count New lines as spacing
            else if(StringChar == "\n")
            {
                TempString += " ";
                SpacingUsed = true;
            }
            else
            {
                TempString += StringChar;
            }
        }
    }
    return LineString;
}

bool MiscFunctions::FindTextWithNearMatch(std::string LineString, std::string SearchedString)
{
    SearchedString = RemoveExcessSpacing(SearchedString);
    LineString = RemoveExcessSpacing(LineString);
    return FindWrappedText(LineString, SearchedString);
}

//Extract class name of toplevelobject=""
std::string MiscFunctions::RetrieveTopLevelObjectFromString(std::string LineString)
{
    string TopLevelObject = "toplevelobject=";
    string TopLevelObjectClassName = "";
    size_t TempInt, TempInt02;
    bool TempBool, TempBool02, TempBool03;
    TempBool = false; TempBool02 = false; TempBool03 = false;
    string StringChar;
    TempInt = LineString.length();
    TempInt02 = 0;
    TempBool = false;
    string TempString = "";
    string TempString03 = "";
    for(size_t i = 0; i < TempInt&&TempBool == false; i++)
    {
        StringChar = LineString.at(i);
        if(TempBool03)
        {
            if(StringChar == "\"")
            {
                //if (ActionObjectVector.ReturnClassNameIndex(TempString03) != -1)
                //{
                TopLevelObjectClassName = TempString03;
                //}
                TempBool = true;
            }
            else
            {
                TempString03 += StringChar;
            }
        }
        else if(TempBool02)
        {
            if(StringChar == "\"")
            {
                TempBool03 = true;
                TempString03 = "";
            }
        }
        else
        {
            if(StringChar == " " || StringChar == "\t") {/*Ignore tabs and spaces to find text even if have potential formating changes*/ }
            else if(StringChar.at(TempInt02) == TopLevelObject.at(TempInt02))
            {
                TempString03 += StringChar;
                TempInt02++;
            }
            else
            {
                TempString03 = "";
                TempInt02 = 0;
            }
            if(TempString03 == TopLevelObject)
            {
                TempBool02 = true;
            }
        }
    }
    return TopLevelObjectClassName;
}
