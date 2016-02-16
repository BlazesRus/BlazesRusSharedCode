/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#include "BinaryVectorList.h"
#include "StringFunctions.h"


void BinaryVectorList::LoadFileDataV2(std::string FileName, unsigned short ConfigSetting/*=0*/, bool Verbose/*=false*/)
{
	FileName = StringFunctions::CheckAndCorrectFilepath(FileName);
	std::string LineString;
	std::ofstream LoadedFileStream;
	LoadedFileStream.open(FileName, std::ios::binary);//std::ios::in);
	//char NextChar;
	char LineChar;
	std::string CommentBuffer = "";
	const std::string XMLCommentHeader = "<!--";
	const std::string XMLCommentFooter = "-->";
	bool ScanningXMLComments = false;
	//---------------
	//Scanning C++ style comments
	bool ScanningComments02 = false;
	// true = LineComments; false = Multi-line comments
	bool LineCommentType = false;
	//-------------------------
	int CommentIndex = 0;
	if(LoadedFileStream.is_open())
	{
		if(LoadedFileStream.good())
		{
			std::filebuf* FileBuffer = LoadedFileStream.rdbuf();
			for(LineChar = FileBuffer->sbumpc(); LineChar != EOF; LineChar = FileBuffer->sbumpc())
			{
				//std::cout << LineChar;
				if(ScanningComments02)
				{
					if(LineCommentType == false)
					{
						if(LineChar == '*')
						{
							CommentBuffer = "*";
						}
						else if(LineChar == '/'&&CommentBuffer == "*")
						{
							ScanningComments02 = false;
							CommentBuffer = "";
						}
						else
						{
							CommentBuffer += LineChar;
						}
					}
				}
				else if(ConfigSetting != 0 && LineChar == '*'&&CommentBuffer == "/")
				{
					LineCommentType = false;
					ScanningComments02 = true;
				}
				else if(ConfigSetting != 0 && LineChar == '/')
				{
					CommentBuffer += '/';
					if(CommentBuffer == "//")
					{
						LineCommentType = true;
						ScanningComments02 = true;
					}
					else if(CommentBuffer != "/")
					{//Force buffer as "/" if anything other
						CommentBuffer = "/";
					}
					else if(CommentBuffer.size() > 2)
					{
						CommentBuffer = "";
					}
				}
				else if(ScanningXMLComments)
				{
					if(LineChar == XMLCommentFooter.at(CommentIndex))
					{
						CommentBuffer += LineChar;
						if(CommentBuffer == XMLCommentFooter)
						{
							CommentBuffer = "";
							ScanningXMLComments = true;
							CommentIndex = 0;
						}
						else if(CommentIndex < 2)
						{
							CommentIndex++;
						}
						else
						{
							CommentBuffer = "";
							CommentIndex = 0;
						}
					}
					else
					{
						CommentBuffer = "";
						CommentIndex = 0;
					}
				}
				else if(CommentBuffer != "")
				{
					if(LineChar == XMLCommentHeader.at(CommentIndex))
					{
						CommentBuffer += LineChar;
						if(CommentBuffer == XMLCommentHeader)
						{
							CommentBuffer = "";
							ScanningXMLComments = true;
							CommentIndex = 0;
						}
						else if(CommentIndex < 3)
						{
							CommentIndex++;
						}
						else
						{//Prevent Bug causing Header to search out of index
							LineString += CommentBuffer;
						}
					}
					else
					{
						LineString += CommentBuffer;
					}
				}
				else if(LineChar == '\n')
				{
					//Add(LineString);
					Add(LineChar);
					LineString = "";
				}
				else if(ConfigSetting != 0 && LineChar == '<'&&CommentBuffer == "")
				{
					CommentBuffer = "<";
					CommentIndex = 1;
				}
				else
				{
					LineString += LineChar;
					Add(LineChar);
				}
			}
		}
		else
		{
			if(LoadedFileStream.bad()) { std::cout << "Failed Read/Write operation Error!\n"; }
			else if(LoadedFileStream.fail()) { std::cout << "Failed format based Error!\n"; }
			else if(LoadedFileStream.bad()) { std::cout << "Failed Read/Write operation Error!\n"; }
			else if(LoadedFileStream.eof()) {/*Send debug message of reaching end of file?*/ }
		}
		LoadedFileStream.close();
	}
	else
	{
		std::cout << "Failed to open filepath:" << FileName << "\n";
	}
}

//void BinaryVectorList::SaveDataToFileV3(std::string FileName)
//{
//	std::string LineString;
//	std::ofstream LoadedFileStream;
//	LoadedFileStream.open(FileName, std::ios::out || std::ios::trunc);
//	size_t DataSize=0;// = Size();
//	if(LoadedFileStream.is_open())
//	{
//		if(LoadedFileStream.good())
//		{
//			for(size_t i = 0; i < DataSize; ++i)
//			{
//				if(i != 0)
//				{//Carriage Return to next line
//					LoadedFileStream << "\n";
//				}
//				//LineString = ElementAt(i);
//				//std::cout << LineString<<"\n";
//				LoadedFileStream << LineString;
//			}
//		}
//		else
//		{
//			if(LoadedFileStream.bad()) { std::cout << "Failed Read/Write operation Error!\n"; }
//			else if(LoadedFileStream.fail()) { std::cout << "Failed format based Error!\n"; }
//			else if(LoadedFileStream.bad()) { std::cout << "Failed Read/Write operation Error!\n"; }
//			else if(LoadedFileStream.eof()) {/*Send debug message of reaching end of file?*/ }
//		}
//		LoadedFileStream.close();
//	}
//	else
//	{
//		std::cout << "Failed to open" << FileName << "\n";
//	}
//}

BinaryVectorList::BinaryVectorList()
{}


BinaryVectorList::~BinaryVectorList()
{}
