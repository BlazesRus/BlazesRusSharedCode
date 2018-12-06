#include "MultiviewPrecompile.h"
#include "XMLTagView.h"

#include <string>
#include <fstream>
using namespace std;
#include "GlobalCode_VariableLists/StringVectorList.h"
#include "GlobalCode_IniData/IniDataV2.h"

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
	StringVectorList TagDepth;
	std::string CurrentTag = "";
	unsigned _int64 CurrentTagIndex = EmptyNode;
	std::string NextTag = "";
	IniDataV2 AdditionTagOptions;
	//         signed int CommandStage = 0;
	//         //------------------------------------------------------------------------------------

	 //0=NormalTag; 1:SelfContainedTag; 2:TagIsClosing; 3:XMLVersionTag
	int TagType = 0;
	bool ArgHasNoValue = false;
	bool PotentialComment = false;
	//         XMLOption TagArg = new XMLOption();
	//         XMLOptionList TagArgments = new XMLOptionList();
	//         //------------------------------------------------------------------------------------
	//         int LineSize;
	bool InsideParenthesis = false;
	//         std::string TagNameTemp = "";
	bool TagNameHasArg02 = false;
	std::string TagNameArg02 = "";

	ifstream inFile;
	inFile.open(FilePath);
	if (!inFile)
	{
		return false;
	}
	while (inFile >> LineChar)
	{
		if (InsideTag)
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
			else if (PotentialComment)
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
				if (ScanBuffer.empty())
				{
				}
				else
				{
				}
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
				else//Get Tag arguments etc here
				{

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
					//		CurrentNode->TagContent += LineChar;
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