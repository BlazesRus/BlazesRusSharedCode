// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest BlazesSharedCode Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#include "MultiviewPrecompile.h"
#include "XMLTagView.h"

#include <string>
#include <fstream>
using namespace std;
#include "VariableLists/StringVectorList.h"
#include "IniData/IniDataV2.h"
#include "BasicXMLNode.h"

/// <summary>
/// Loads the data from file.
/// </summary>
/// <param name="FilePath">The file path.</param>
/// <returns>bool</returns>
bool XMLTagView::LoadDataFromFile(std::string FilePath)
{
    char LineChar;
    bool InsideXMLComment = false;
    bool InsideTag = false;
    std::string ScanBuffer = "";
    //std::string ContentBuffer = "";
    BasicNodeList TagDepth;
    std::string CurrentTag = "";
    unsigned _int64 CurrentTagIndex = EmptyNode;
    std::string NextTag = "";
    IniDataV2 AdditionTagOptions;
    //         signed int CommandStage = 0;

     //0=NormalTag; 1:SelfContainedTag; 2:TagIsClosing; 3:XMLVersionTag
    int TagType = 0;
    bool ArgHasNoValue = false;
    bool PotentialComment = false;
    bool InsideParenthesis = false;
    bool ScanningArgData = false;
    bool TagNameHasArg02 = false;
    std::string TagNameArg02 = "";
    size_t StageOrSize = 0;

    ifstream inFile;
    inFile.open(FilePath);
    if (!inFile)
    {
        return false;
    }
    while (inFile >> LineChar)
    {
        if (PotentialComment)
        {
            ScanBuffer += LineChar;
            if (ScanBuffer == "--")
            {
                InsideXMLComment = true;
                PotentialComment = false;
                ScanBuffer = "";
            }
            else if (ScanBuffer.size() >= 2)//Detecting non-normal format TagName?
            {
                PotentialComment = false;
                ScanBuffer = "!" + ScanBuffer;
            }
        }
        else if (InsideXMLComment)//Ignoring all xml inside xml formatted comment
        {
            StageOrSize = ScanBuffer.size();
            if (StageOrSize == 0)
            {
                if (LineChar == '-')
                {
                    ScanBuffer = "-";
                }
            }
            else if (StageOrSize == 1)
            {
                if (LineChar == '-')
                {
                    ScanBuffer = "--";
                }
                else
                {
                    ScanBuffer = "";
                }
            }
            else
            {
                if (LineChar == '>')
                {
                    InsideXMLComment = false;
                }
                ScanBuffer = "";
            }
        }
        else if(ScanningArgData)
        {
            if(StageOrSize==0)
            {
                if(LineChar!='=')
                {
                    StageOrSize = 1; TagNameArg02 = "";
                }
                else if(LineChar != ' ' && LineChar != '\t' && LineChar != '\n')//Skip Whitespace
                {
                    ScanBuffer += LineChar;
                }
            }
            else
            {
                if(LineChar=='\"')
                {
                    if (InsideParenthesis&&!TagNameArg02.empty())//End argument inside parenthesis with second parenthesis instead of space
                    {
                        ////Detect Argument type(0=Default/String; 1:Int; 2:Non-WholeNumber)
                        //int DetectedArgType = 0;
                        //for(int Index=0;Index<TagNameArg02.length();++Index)
                        //{

                        //}
                        //switch(DetectedArgType)
                        //{
                        //	case 2:
                        //		AdditionTagOptions.Add(ScanBuffer, TagNameArg02);
                        //	break;
                        //	default:
                                AdditionTagOptions.Add(ScanBuffer, TagNameArg02);
                        //	break;
                        //}
                    }
                    InsideParenthesis = !InsideParenthesis;
                }
                else
                {
                    if(InsideParenthesis)
                    {
                        TagNameArg02 += LineChar;
                    }
                }
            }
        }
        else if (InsideTag)
        {
            if (LineChar == '>')
            {
                unsigned _int64 IndexPos;
                InsideTag = false;
                //Add NextTag into tree
                if (TagType == 1)
                {
                    IndexPos = AddNode(NextTag, 1, CurrentTagIndex);
                    //NodeBank[IndexPos].AdditionTagOptions
                }
                else if (TagType == 2)
                {
                    if (NextTag == CurrentTag)//Normal Exiting of Previous Tag
                    {
                        TagDepth.Remove(TagDepth.size() - 1);//Remove last tag from depth
                    }
                    else//Rare exiting of non-previous tag
                    {
                        //Write code for this later(not as important)
                    }
                    //Add TagContent Buffer into Node
                }
                else
                {
                    IndexPos = AddNode(NextTag, 0, CurrentTagIndex);
                    CurrentTag = NextTag;
                    CurrentTagIndex = IndexPos;
                    TagDepth.Add(CurrentTag);
                }
                //Clear Buffers after adding Tag to tree
                NextTag = ""; ScanBuffer = ""; TagType = 0;
            }
            else if (NextTag.empty())
            {
                if (ScanBuffer.empty())
                {
                    if (LineChar == '/')//Detected Closing Tag
                    {
                        TagType = 2;
                    }
                    else if (LineChar == '?'&&TagType == 0)
                    {
                        TagType = 3;
                    }
                    else if (LineChar == ' ' || LineChar == '\t' || LineChar == '\n')
                    {
                        if (!ScanBuffer.empty())//End Tag on whitespace if buffer not empty
                        {
                            NextTag = ScanBuffer;
                            ScanBuffer = "";
                        }
                    }
                    else if (LineChar == '!')
                    {
                        PotentialComment = true;
                    }
                    else
                    {
                        ScanBuffer += LineChar;
                    }
                }
                else
                {
                    if (LineChar == '?'&&TagType == 0)
                    {
                        TagType = 3;
                    }
                    else if (LineChar == ' ' || LineChar == '\t' || LineChar == '\n')
                    {
                        if (!ScanBuffer.empty())//End Tag on whitespace if buffer not empty
                        {
                            NextTag = ScanBuffer;
                            ScanBuffer = "";
                        }
                    }
                    else
                    {
                        ScanBuffer += LineChar;
                    }
                }
            }
            else
            {
                if (LineChar == '/')//Detected Self-Contained Tag
                {
                    TagType = 1;
                }
                else if (LineChar != '?' && LineChar != ' ' && LineChar != '\t' && LineChar != '\n')//Get Tag arguments etc here
                {
                    ScanningArgData = true; StageOrSize = 0; ScanBuffer = LineChar;
                }
            }
        }
        else
        {
            if (LineChar == '<')
            {
                InsideTag = true;
            }
            else
            {
                if (!CurrentTag.empty())//Get TagContent here
                {
                    TagDepth.LastNode().TagContent += LineChar;
                }
            }
        }
    }
    return true;
}

XMLTagView::XMLTagView(std::string FilePath) : CustomTreeView<XMLTagViewNode>()
{
    LoadDataFromFile(FilePath);
}

XMLTagView::XMLTagView() : CustomTreeView<XMLTagViewNode>()
{
    LoadDataFromFile("I:/UserFiles/Sample.xml");
}