#include "MultiviewPrecompile.h"
#include "XMLTagView.h"

#include <string>
#include <fstream>
using namespace std;
#include "GlobalCode_VariableLists/StringVectorList.h"

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
	std::string NextTag = "";
   //         signed int CommandStage = 0;
   //         //------------------------------------------------------------------------------------

	//0=NormalTag; 1:SelfContainedTag; 2:TagIsClosing
	int TagType = 0;
   //         bool SpecialXMLVersionTag = false;
   //         bool ArgHasNoValue = false;
   //         XMLOption TagArg = new XMLOption();
   //         XMLOptionList TagArgments = new XMLOptionList();
   //         //------------------------------------------------------------------------------------
   //         int LineSize;
   //         bool InsideParenthesis = false;
   //         std::string TagNameTemp = "";
   //         bool TagNameHasArg02 = false;
   //         std::string TagNameArg02 = "";

	ifstream inFile;
	inFile.open(FilePath);
	if (!inFile)
	{
		return false;
	}
	while (inFile >> LineChar)
	{
		if(InsideTag)
		{
			if (LineChar == '>')
			{
				InsideTag = false;
				//Add NextTag into tree
				if (TagType==1)
				{
				}
				else if (TagType == 2)
				{
					if(NextTag==CurrentTag)//Normal Exiting of Previous Tag
					{
						TagDepth.Remove(TagDepth.size()-1);//Remove last tag from depth
					}
					else//Rare exiting of non-previous tag
					{

					}

				}
				else
				{
					if (CurrentTag.empty())//If no tag above, then add to root
					{

					}
					else
					{

					}
					CurrentTag = NextTag;
					TagDepth.Add(CurrentTag);
				}
				//Clear Buffers after adding Tag to tree
				NextTag = "";ScanBuffer = ""; TagType=0;
			}
			else if (NextTag.empty())
			{
				if (LineChar == '/')//Detected Closing Tag
				{
					TagType = 2;
				}
				else if(LineChar==' '||LineChar=='	')
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
			else
			{
				if (LineChar == '/')//Detected Self-Contained Tag
				{
					TagType = 1;
				}
			}
		}
		else if(InsideXMLComment)
		{
			if(ScanBuffer.empty())
			{

			}
			else
			{

			}
		}
		else
		{

		}
	}
#if !defined(BlazesGUICode_UseDictionaryBasedNodes)
#else
#endif
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