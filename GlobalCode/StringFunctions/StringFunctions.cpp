/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#include "StringFunctions.h"
#include <locale>

#include <math.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iosfwd>
#include <stdint.h>
#include <limits>
#include <sys/types.h>
#include <sys/stat.h>


using std::string;
using std::cout;

/**Check if LineString Contains SearchedString
 * @param LineString
 * @param SearchedString
 * @return
 */
bool StringFunctions::LineStringContains(string LineString, string SearchedString)
{
    bool Confirmed = false;
    if((LineString.compare(SearchedString) == 0 || LineString.compare(SearchedString) >= 1))
    {
        Confirmed = true;
    }
    return Confirmed;
}

//************************************
// Method:    CreateTabSpace
// FullName:  StringFunctions::CreateTabSpace
// Access:    public static
// Returns:   string
// Qualifier:
// Parameter: int temp
//************************************
string StringFunctions::CreateTabSpace(size_t temp)
{
    string TempString = "";
    while(temp > 0)
    {
        TempString += "	";
        temp--;
    }
    return TempString;
}

/** Use to keep tabs aligned on parameters(tab is equal to 4 spaces)
 * @param LineString @return StringContaining Tabs*/
string StringFunctions::OutputLineStringTabs(string LineString)
{
    string TempString = "";
    size_t StringLength = LineString.length();
    bool Finished = false;
    string StringChar;
    for(size_t i = 0; (i < StringLength) || Finished; i++)
    {
        StringChar = "" + LineString.at(i);
        if(StringChar == "[^\\\\d]")//Only Records Whitespace/tabs
        {
            TempString += StringChar;
        }
        else
        {
            Finished = true;
        }
    }
    return TempString;
}
/** Use to keep tabs aligned on parameters
 * @param LineString
 * @return
 */
string StringFunctions::OutputQuadVariableLines(string LineString)
{
    string TempString = "";
    size_t StringLength = LineString.length();
    bool RecordString = false;
    string StringChar;
    for(size_t i = 0; (i < StringLength); i++)
    {
        StringChar = "" + LineString.at(i);
        if(RecordString)
        {
            TempString += StringChar;
        }
        else
        {
            if(StringChar == "(")//Only Records Whitespace/tabs
            {
                RecordString = true;
                TempString += StringChar;
            }
        }
    }
    return TempString;
}
/** Returns the filename from a full file-path
 * @param TempString
 * @return
 */
string StringFunctions::SeparateFilePathIntoFileName(string TempString)
{
    string FileName = "";
    size_t StringLength = TempString.length();
    char StringChar;
    for(size_t i = 0; i < StringLength; i++)
    {
        StringChar = TempString.at(i);
        if(StringChar == '/' || StringChar == '\\')//Separate filename with path slashs(and reset filename buffer)
        {
            FileName = "";
        }
        else
        {
            FileName += StringChar;
        }
    }
    return FileName;
}
/**
 * @param LineString
 * @param TargetObject
 * @return
 */
string StringFunctions::CreateLinkedHTMLString(string LineString, string TargetObject)
{
    return (string) ("<a href=" + TargetObject + "><code>" + LineString + "</code></a>");
}

/** Remove whitespace from start of line
 * @param LineString @return String*/
string StringFunctions::RemoveStringTabs(string LineString)
{
    string TempString = "";
    size_t StringLength = LineString.length();
    bool Finished = false;
    string StringChar;
    for(size_t i = 0; i < StringLength; ++i)
    {
        StringChar = "" + LineString.at(i);
        if(StringChar != "[^\\\\d]")//Only Records Whitespace/tabs
        {
            Finished = true;
        }
        if(Finished)
        {
            TempString += StringChar;
        }
    }
    return TempString;
}
/** Examines the number of tabs/(equivalent of tabs in spaces) of whitespace before text
 * Rounds up partial amount of spaces leftover as being equivalent as another tab
 //Need to fix code to currectly calculate
 * @param LineString
 * @param TabEquivalent:Amount of spaces is equal to tab
 * @return
 */
size_t StringFunctions::ExamineTabSpace(string LineString, int TabEquivalent)
{
    size_t AmountOfTabs = 0;
    size_t TotalSpaces = 0;
    size_t StringLength = LineString.length();
    bool Finished = false;
    string StringChar;
    for(size_t i = 0; (i < StringLength && Finished == false); ++i)
    {
        StringChar = LineString.at(i);
        if(StringChar == "\t" || StringChar == "	")
        {
            AmountOfTabs++;
        }
        else if(StringChar == " ")
        {
            TotalSpaces++;
        }
        else
        {
            Finished = true;
        }
        if(TotalSpaces == TabEquivalent)
        {
            TotalSpaces = 0;
            AmountOfTabs++;
        }
    }
    if(TotalSpaces > 0)
    {//Round up number of spaces as being equivalent to a tab
        AmountOfTabs++;
    }
    return AmountOfTabs;
}

size_t StringFunctions::ExamineTabSpace(string LineString)
{
    return ExamineTabSpace(LineString, 4);
}

string StringFunctions::RemoveAmountOfTabSpace(string LineString, int TabEquivalent, int AmountOfWhitespaceRemoval)
{
    string TempString = "";
    size_t AmountOfTabs = 0;
    size_t TotalSpaces = 0;
    size_t StringLength = LineString.length();
    bool Finished = false;
    string StringChar;
    for(size_t i = 0; i < StringLength; ++i)
    {
        StringChar = "" + LineString.at(i);
        if(Finished == false)
        {
            if(StringChar == "[^\\\\d]")//Only Records Whitespace/tabs
            {
                if(StringChar == "\t")
                {
                    ++AmountOfTabs;
                }
                else if(StringChar == " ")
                {
                    ++TotalSpaces;
                }
            }
            else
            {
                TempString += StringChar;
                Finished = true;
            }
            if(TotalSpaces == TabEquivalent)
            {
                TotalSpaces = 0;
                ++AmountOfTabs;
            }
            if(AmountOfTabs >= AmountOfWhitespaceRemoval)
            {
                Finished = true;
            }
        }
        else
        {
            TempString += StringChar;
        }
    }
    return TempString;
}

string StringFunctions::RemoveXMLTags(string LineString)
{
    size_t StringLength = LineString.length();
    string TempString = "";
    bool InsideTag = false;
    char StringChar;
    for(size_t i = 0; i < StringLength; ++i)
    {
        StringChar = LineString.at(i);
        if(InsideTag)
        {
            if(StringChar == '>')
            {
                InsideTag = false;
            }
        }
        else if(StringChar == '<')
        {
            InsideTag = true;
        }
        else
        {
            TempString += StringChar;
        }
    }
    return TempString;
}

string StringFunctions::ReturnXMLTagContent(string LineString)
{
    size_t StringLength = LineString.length();
    string TempString = "";
    bool InsideTag = false;
    unsigned __int8 TagDataStage = 0;
    char StringChar;
    for(size_t i = 0; i < StringLength; i++)
    {
        StringChar = LineString.at(i);
        if(InsideTag)
        {
            if(StringChar == '>')
            {
                InsideTag = false;
                if(TagDataStage == 0)
                {
                    TagDataStage = 1;
                }
            }
        }
        else if(StringChar == '<')
        {
            InsideTag = true;
            if(TagDataStage == 1)
            {
                TagDataStage = 2;
            }
        }
        else if(TagDataStage == 1)
        {
            TempString += StringChar;
        }
    }
    return TempString;
}

string StringFunctions::ReplaceFirst(string LineString, string SearchString, string ReplacementString)
{
    if(SearchString != "")
    {
        //Current character loaded in steam
        char StringChar;
        //Current Loaded parts of LineString
        string LoadedLineString = "";
        //Current Characters worth of string found that match SearchString
        string PartialSearchBuffer = "";
        //Current Index of Loaded PartialSearch
        size_t PartialBufferIndex = 0;
        //Total size of LineString to load
        size_t StringSize = LineString.size();
        //Boolean check to determine if have found first string match
        bool SearchSuccess = false;
        for(size_t i = 0; i < StringSize; ++i)
        {
            StringChar = LineString.at(i);
            if(SearchSuccess)
            {
                LoadedLineString += StringChar;
            }
            else
            {
                //Matching Partial String Search
                if(SearchString.at(PartialBufferIndex) == StringChar)
                {
                    PartialSearchBuffer += StringChar;
                    //Successful Find And Replace
                    if(PartialSearchBuffer == SearchString)
                    {
                        LoadedLineString += ReplacementString;
                        //PartialSearchBuffer = "";
                        SearchSuccess = true;
                    }
                    else
                    {
                        PartialBufferIndex++;
                    }
                }
                //Failed Partial String Search
                else
                {
                    LoadedLineString += PartialSearchBuffer;
                    PartialSearchBuffer = "";
                    PartialBufferIndex = 0;
                    LoadedLineString += StringChar;
                }
            }
        }
        LoadedLineString += PartialSearchBuffer;
        return LoadedLineString;
    }
    else
    {
        return LineString;
    }
}

string StringFunctions::ReplaceAll(string LineString, string SearchString, string ReplacementString)
{
    if(SearchString != "")
    {
        //Current character loaded in steam
        char StringChar;
        //Current Loaded parts of LineString
        string LoadedLineString = "";
        //Current Characters worth of string found that match SearchString
        string PartialSearchBuffer = "";
        //Current Index of Loaded PartialSearch
        size_t PartialBufferIndex = 0;
        //Total size of LineString to load
        size_t StringSize = LineString.size();
        for(size_t i = 0; i < StringSize; ++i)
        {
            StringChar = LineString.at(i);
            //Matching Partial String Search
            if(SearchString.at(PartialBufferIndex) == StringChar)
            {
                PartialSearchBuffer += StringChar;
                //Successful Find And Replace
                if(PartialSearchBuffer == SearchString)
                {
                    LoadedLineString += ReplacementString;
                    PartialSearchBuffer = "";
                }
                else
                {
                    ++PartialBufferIndex;
                }
            }
            //Failed Partial String Search
            else
            {
                LoadedLineString += PartialSearchBuffer;
                PartialSearchBuffer = "";
                PartialBufferIndex = 0;
                LoadedLineString += StringChar;
            }
        }
        LoadedLineString += PartialSearchBuffer;
        return LoadedLineString;
    }
    else
    {
        return LineString;
    }
}

string StringFunctions::ReturnParamName(string LineString)
{
    string SearchString = "<hkparam name=\"";
    //Temporary convert of char to string
    string TempChar;
    //Current character loaded in steam
    string StringChar;
    //Current Loaded parts of ParamName
    string ParamName = "";
    //Current Characters worth of string found that match SearchString
    string PartialSearchBuffer = "";
    //Current Index of Loaded PartialSearch
    size_t PartialBufferIndex = 0;
    //Total size of LineString to load
    size_t StringSize = LineString.size();
    //Boolean check to determine if have found first string match of SearchString
    bool SearchSuccess = false;
    //Boolean check to determine if done scanning ParamName
    bool ParamNameScanInProgress = true;
    for(size_t i = 0; i < StringSize&&ParamNameScanInProgress; ++i)
    {
        StringChar = LineString.at(i);
        if(SearchSuccess)
        {
            if(ParamNameScanInProgress)
            {
                if(StringChar != "\"")
                {
                    ParamName += StringChar;
                }
                else
                {
                    ParamNameScanInProgress = false;
                }
            }
        }
        else
        {
            TempChar = SearchString.at(PartialBufferIndex);
            //Matching Partial String Search
            if(TempChar == StringChar)
            {
                PartialSearchBuffer += StringChar;
                //Successful Find And Replace
                if(PartialSearchBuffer == SearchString)
                {
                    PartialSearchBuffer = "";
                    SearchSuccess = true;
                }
                else
                {
                    PartialBufferIndex++;
                }
            }
            //Failed Partial String Search
            else
            {
                PartialSearchBuffer = "";
                PartialBufferIndex = 0;
            }
        }
    }
    return ParamName;
}

std::string StringFunctions::AddStringInFront(std::string ValueAdded, std::string TargetString)
{
    string TempString;
    TempString = ValueAdded + TargetString;
    return TempString;
}

std::string StringFunctions::AddStringInFront(char ValueAdded, std::string TargetString)
{
    string TempString = "";
    TempString += ValueAdded;
    return AddStringInFront(TempString, TargetString);
}

template <typename T>
std::string StringFunctions::ConvertPointerToStringAddress(const T* obj)
{
    int address(reinterpret_cast<int>(obj));
    std::stringstream ss;
    ss << address;
    return ss.str();
}

template <typename T>
std::string StringFunctions::ConvertPointerToStringAddressV2(T* obj)
{
    int address(reinterpret_cast<int>(obj));
    std::stringstream ss;
    ss << address;
    return ss.str();
}


typedef union
{
    float f;
    uint32_t i;
} conversion_t;





//String to char array code from http://stackoverflow.com/questions/13294067/how-to-convert-string-to-char-array-in-c
//Directory checking code from http://stackoverflow.com/questions/18100097/portable-way-to-check-if-directory-exists-windows-linux-c
std::string StringFunctions::CheckAndCorrectDirectoryLocation(std::string Directory, bool Verbose/*=false*/)
{
    bool DirectoryExists;
    struct stat info;
    char CharStringBuffer[1024];
    strncpy_s(CharStringBuffer, Directory.c_str(), sizeof(CharStringBuffer));
    CharStringBuffer[sizeof(CharStringBuffer) - 1] = 0;
    if(stat(CharStringBuffer, &info) != 0)
    {
        if(Verbose) { printf("cannot access %s\n", CharStringBuffer); }
        DirectoryExists = false;
    }
    else if(info.st_mode & S_IFDIR)
    {
        if(Verbose) { printf("%s is a directory\n", CharStringBuffer); }
        DirectoryExists = true;
    }
    else
    {
        if(Verbose) { printf("%s is no directory\n", CharStringBuffer); }
        DirectoryExists = false;
    }
    if(DirectoryExists==false)
    {
        //Create code to Attempt Auto-fix format of directory later
    }
    return Directory;
}

//Refer to CheckAndCorrectDirectoryLocation comments for links to code base used
std::string StringFunctions::CheckAndCorrectFilepath(std::string FileName, bool Verbose/*=false*/)
{
    bool DirectoryExists=false;
    bool IsFilePath=false;
    struct stat info;
    char CharStringBuffer[1024];
    strncpy_s(CharStringBuffer, FileName.c_str(), sizeof(CharStringBuffer));
    CharStringBuffer[sizeof(CharStringBuffer) - 1] = 0;
    if(stat(CharStringBuffer, &info) != 0)
    {
        if(Verbose) { printf("cannot access %s\n", CharStringBuffer); }
        DirectoryExists = false;
    }
    else if(stat(CharStringBuffer, &info) == 0)
    {
        if(Verbose) { printf("%s is a filepath\n", CharStringBuffer); }
        IsFilePath = true;
    }
    else if(info.st_mode & S_IFDIR)
    {
        if(Verbose) { printf("%s is a directory\n", CharStringBuffer); }
        DirectoryExists = true;
    }
    else
    {
        if(Verbose) { printf("%s is no directory\n", CharStringBuffer); }
        DirectoryExists = false;
    }
    if(IsFilePath==false&&DirectoryExists==false)
    {
        //Create code to attempt Auto-Fix filepath format later
    }
    return FileName;
}

unsigned __int8 StringFunctions::FindContentType(std::string Content)
{
    unsigned __int8 DetectedContentType = 0;
    //0 = No List Detected
    //1 = List Detected
    //2 = Possible List Detected
    unsigned __int8 ListDetectionState = 0;
    //false = testing for false value;true = testing for true value
    bool BoolValueDetecting;
    const string TrueString = "true";
    const string FalseString = "false";
    string CurrentElement = "";
    char CurrentChar;
    bool ContentTypeConfirmed = false;
    //0 = Whitespace only/Nothing so far
    //1 = Possible Bool/String Detected
    //2 = Possible Havok Class Target Detected
    //3 = Possible Int/Double Detected
    //4 = Possible Double Detected
    //5 = Likely String Detected
    //6 = Possible BoolList Detected
    //7 = Possible Havok Class Target List Detected
    //8 = Possible IntegerList Detected
    //9 = Possible DoubleList Detected
    //10 = Likely StringList Detected
    //11 = Possible QuadVector Detected
    //12 = Possible QuadVectorList Detected
    unsigned __int8 CurrentDetectionStatus = 0;
    //---------------------------------------------------------
    const size_t StringSize = Content.length();
    size_t ElementIndex;
    for(size_t Index = 0; Index < StringSize&&!ContentTypeConfirmed; ++Index)
    {
        CurrentChar = Content.at(Index);
        if(CurrentElement == "")
        {
            if(ListDetectionState == 2)
            {
                if(CurrentChar != '\n'&&CurrentChar != ' '&&CurrentChar != '\t'&&CurrentChar != '	')
                {
                    ListDetectionState = 1;
                    //Convert detected type to List
                    CurrentElement = CurrentChar;
                    if(CurrentDetectionStatus < 11)
                    {
                        CurrentDetectionStatus += 5;
                    }
                    else if(CurrentDetectionStatus == 11)
                    {
                        CurrentDetectionStatus = 12;
                    }
                    ContentTypeConfirmed = true;
                }
            }
            else if(CurrentChar != '\n'&&CurrentChar != ' '&&CurrentChar != '\t'&&CurrentChar != '	')
            {
                if(CurrentChar == 't')
                {
                    //Possible Bool/String Detected
                    BoolValueDetecting = true;
                    CurrentDetectionStatus = 1;
                }
                else if(CurrentChar == 'f')
                {
                    //Possible Bool/String Detected
                    BoolValueDetecting = false;
                    CurrentDetectionStatus = 1;
                }
                else if(CurrentChar == '-')//Only the first character of digit can be negative to count
                {
                    //Possible Int/Double detected
                    CurrentDetectionStatus = 3;
                }
                else if(CurrentChar == '#')
                {
                    //Possible Havok Class Target Detected
                    CurrentDetectionStatus = 2;
                }
                else if(CurrentChar == '1' || CurrentChar == '2' || CurrentChar == '3' || CurrentChar == '4' || CurrentChar == '5'
                    || CurrentChar == '6' || CurrentChar == '7' || CurrentChar == '8' || CurrentChar == '9' || CurrentChar == '0')
                {
                    //Possible Int/Double detected
                    CurrentDetectionStatus = 3;
                }
                else if(CurrentChar == '(')
                {
                    CurrentDetectionStatus = 11;
                }
                else
                {
                    //Likely either String Value or value type not listed for detection
                    CurrentDetectionStatus = 5;
                }
                CurrentElement = CurrentChar;
            }
        }
        else
        {
            if(CurrentDetectionStatus == 11)
            {
                if(CurrentChar == ')')
                {
                    CurrentElement = "";
                    ListDetectionState = 2;
                }
            }
            else if(CurrentChar != '\n'&&CurrentChar != ' '&&CurrentChar != '\t'&&CurrentChar != '	')
            {
                ElementIndex = CurrentElement.length();
                CurrentElement += CurrentChar;
                //check to see if matches pattern
                switch(CurrentDetectionStatus)
                {
                    case 1:
                        if(BoolValueDetecting)
                        {
                            if(CurrentElement.at(ElementIndex) != TrueString.at(ElementIndex)) { CurrentDetectionStatus = 5; }
                        }
                        else
                        {
                            if(CurrentElement.at(ElementIndex) != FalseString.at(ElementIndex)) { CurrentDetectionStatus = 5; }
                        }
                        break;
                    case 2:
                        //Allow all but whitespace to be counted as havok class character
                        break;
                    case 3:
                        if(CurrentChar == '.')
                        {
                            CurrentDetectionStatus = 4;
                        }
                        else if(CurrentChar != '1'&&CurrentChar != '2'&&CurrentChar != '3'&&CurrentChar != '4'&&CurrentChar != '5'&&CurrentChar != '6'&&CurrentChar != '7'&&CurrentChar != '8'&&CurrentChar != '9'&&CurrentChar != '0')//Non-Digit Char detected
                        {
                            CurrentDetectionStatus = 5;
                        }
                        break;
                    case 4:
                        if(CurrentChar != '1'&&CurrentChar != '2'&&CurrentChar != '3'&&CurrentChar != '4'&&CurrentChar != '5'&&CurrentChar != '6'&&CurrentChar != '7'&&CurrentChar != '8'&&CurrentChar != '9'&&CurrentChar != '0')//Non-Digit Char detected
                        {
                            CurrentDetectionStatus = 5;
                        }
                        break;
                        //default:
                        //	break;
                }
            }
            else
            {
                //End of Current Element
                CurrentElement = "";
                ListDetectionState = 2;
            }
        }
    }
    switch(CurrentDetectionStatus)
    {
        //Type of data stores inside Tag (Strings stored in TagContent)
        //0:Default Extracted content
        //1:Int
        //2:Bool
        //3:Double
        //4:String
        //5:Event Index(Int)
        //6:Variable Index(Int)
        //7:Havok Class index(Int)
        //9:QuadVector
        //10:Event String
        //11:Variable String
        //12:Animation Path String
        //13:Condition (String)
        //14:Havok Class Target Name (String)
        //15:Havok Class Target List (StringVectorList)
        //20:IntegerList
        //21:DoubleList
        //22:StringVectorList
        //23:BooleanList
        //24:QuadVectorList
        //50:flags (String)
        //51:Clip Mode (String)
        //240:Holds Havok Class info
        //241:hkobject Container
        //242:Closing Tag of Havok Class
        //250:Unknown (String)
        //251:Unknown(String) with only whitespace and
        case 1:
            DetectedContentType = 2;
            break;
        case 2:
            DetectedContentType = 14;
            break;
        case 3:
            DetectedContentType = 1;
            break;
        case 4:
            DetectedContentType = 3;
            break;
        case 5:
            DetectedContentType = 4;
            break;
        case 6:
            DetectedContentType = 23;
            break;
        case 7:
            DetectedContentType = 15;
            break;
        case 8:
            DetectedContentType = 20;
            break;
        case 9:
            DetectedContentType = 21;
            break;
        case 10:
            DetectedContentType = 22;
            break;
        case 11:
            DetectedContentType = 9;
            break;
        case 12:
            DetectedContentType = 24;
            break;
        default:
            DetectedContentType = 251;
            break;
    }
    return DetectedContentType;
}
