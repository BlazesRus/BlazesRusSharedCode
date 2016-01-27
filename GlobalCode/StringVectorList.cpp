/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/

#include "StringVectorList.h"
#include <iostream>
#include <fstream>
#include "StringFunctions.h"
#include <iosfwd>
#include <sys/stat.h>

using std::cout;
using std::string;

size_t StringVectorList::AddData()
{
	size_t Index = Size();
	string TempValue = "";
	Add(TempValue);
	return Index;
}

void StringVectorList::ConvertStringToStringVectorList(std::string Content)
{
	if(Size()!=0)
	{
		Reset();
	}
	const size_t StringSize = Content.length();
	char CurrentChar;
	string CurrentElement = "";
	for(size_t Index=0; Index < StringSize; ++Index)
	{
		CurrentChar = Content.at(Index);
		if(CurrentElement == "")
		{
			if(CurrentChar != '\n'&&CurrentChar != ' '&&CurrentChar != '\t'&&CurrentChar != '	')
			{
				CurrentElement = CurrentChar;
			}
		}
		else
		{
			if(CurrentChar != '\n'&&CurrentChar != ' '&&CurrentChar != '\t'&&CurrentChar != '	')
			{
				CurrentElement += CurrentChar;
			}
			else
			{
				Add(CurrentElement);
				CurrentElement = "";
			}
		}
	}
}

void StringVectorList::SaveDataToFileV2(std::string FileName)
{
	std::string LineString;
	std::fstream CraftedIniFile;
	CraftedIniFile.open(FileName.c_str(), std::ios::out || std::ios::trunc);
	size_t DataSize = Size();
	if(CraftedIniFile.is_open())
	{
		for(size_t i = 0; i < DataSize; ++i)
		{
			if(i != 0)
			{//Carriage Return to next line
				CraftedIniFile << "\r\n";
			}
			LineString = ElementAt(i);
			CraftedIniFile << LineString;
		}
		CraftedIniFile.close();
	}
	else
	{
		cout << "Failed to open" << FileName << "\n";
	}
}

bool StringVectorList::ScanData(std::string LineString)
{
	size_t StringLength = LineString.length();
	char StringChar;
	for(size_t i = 0; i < StringLength; ++i)
	{
		StringChar = LineString.at(i);
	}
	return true;
}

bool StringVectorList::LoadFileData(std::string FileName)
{
	Reset();
	bool FileStreamOpen = false;
	int FileStreamState = 0;
	string LineString = "";
	string LineChar;
	char NextChar = ' ';
	std::fstream LoadedFileStream;
	while(FileStreamState >= 0)
	{
		if(FileStreamOpen == false)
		{
			LoadedFileStream.open(FileName.c_str());//, std::ios::in | std::ios::out
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
					//FileStreamLineExtraction(LoadedFileStream, LineString, FileString, VariableScanningData);
					Add(LineString);
					LineString = "";
				}
				else
				{
					LineString += LineChar;
				}
				//cout << LineString << "\n";
				//LoadedDataString = LineString;
				FileStreamState = 2;
				//return 2;
			}
			else if(NextChar == EOF || LoadedFileStream.eof())
			{
				if(LineString != "")
				{
					Add(LineString);
					LineString = "";
				}
				cout << "Reached end of file Data Loaded \n";
				FileStreamState = 3;
				LoadedFileStream.close();
				FileStreamState = -3;
				//return 3;
			}
			else
			{
				if(LoadedFileStream.bad())
				{
					cout << "Failed Read/Write operation Error \n";
					FileStreamState = -1;
				}
				else if(LoadedFileStream.fail())
				{
					cout << "Failed format-based Error on path "<<FileName<<"\n";
					system("pause");
					FileStreamState = -1;
				}
				else if(LoadedFileStream.bad())
				{
					cout << "Failed Read/Write operation Error on path "<<FileName<<"\n";
					system("pause");
					FileStreamState = -1;
				}
				else
				{
					cout << "Error Number -2 \n";
					FileStreamState = -2;
				}
			}
		}
		else
		{
			cout << "Failed to open" << FileName << "\n";
			if(LoadedFileStream.eof())
			{
				cout << "Reached end of file Error \n";
			}
			else if(LoadedFileStream.bad())
			{
				cout << "Failed Read/Write operation Error on path " << FileName << "\n";
				system("pause");
			}
			else if(LoadedFileStream.fail())
			{
				cout << "Failed format-based Error on path " << FileName << "\n";
				system("pause");
			}
			FileStreamState = 0;
			//return 0;
		}
		//return 0;
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

bool StringVectorList::AddFileData(std::string FileName)
{
	bool FileStreamOpen = false;
	int FileStreamState = 0;
	string LineString = "";
	string LineChar;
	char NextChar = ' ';
	std::fstream LoadedFileStream;
	while(FileStreamState >= 0)
	{
		if(FileStreamOpen == false)
		{
			LoadedFileStream.open(FileName.c_str());//, std::ios::in | std::ios::out
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
					//FileStreamLineExtraction(LoadedFileStream, LineString, FileString, VariableScanningData);
					Add(LineString);
					LineString = "";
				}
				else
				{
					LineString += LineChar;
				}
				//cout << LineString << "\n";
				//LoadedDataString = LineString;
				FileStreamState = 2;
				//return 2;
			}
			else if(NextChar == EOF || LoadedFileStream.eof())
			{
				if(LineString != "")
				{
					Add(LineString);
					LineString = "";
				}
				cout << "Reached end of file Data Loaded \n";
				FileStreamState = 3;
				LoadedFileStream.close();
				FileStreamState = -3;
				//return 3;
			}
			else
			{
				if(LoadedFileStream.bad())
				{
					cout << "Failed Read/Write operation Error \n";
					FileStreamState = -1;
				}
				else if(LoadedFileStream.fail())
				{
					cout << "Failed format-based Error \n";
					FileStreamState = -1;
				}
				else if(LoadedFileStream.bad())
				{
					cout << "Failed Read/Write operation Error \n";
					FileStreamState = -1;
				}
				else
				{
					cout << "Error Number -2 \n";
					FileStreamState = -2;
				}
			}
		}
		else
		{
			cout << "Failed to open" << FileName << "\n";
			if(LoadedFileStream.eof())
			{
				cout << "Reached end of file Error \n";
			}
			else if(LoadedFileStream.bad())
			{
				cout << "Failed Read/Write operation Error \n";
			}
			else if(LoadedFileStream.fail())
			{
				cout << "Failed format-based Error \n";
			}
			else if(LoadedFileStream.bad())
			{
				cout << "Failed Read/Write operation Error \n";
			}
			FileStreamState = 0;
			//return 0;
		}
		//return 0;
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

void StringVectorList::LoadXMLFileWithoutComments(std::string InputFile)
{
	Reset();
	bool FileStreamOpen = false;
	int FileStreamState = 0;
	string LineString = "";
	string LineChar;
	char NextChar = ' ';
	string XMLCommentBuffer = "";
	const string XMLCommentHeader = "<!--";
	const string XMLCommentFooter = "-->";
	bool ScanningXMLComments = false;
	int CommentIndex = 0;
	std::fstream LoadedFileStream;
	while(FileStreamState >= 0)
	{
		if(FileStreamOpen == false)
		{
			LoadedFileStream.open(InputFile.c_str());//, std::ios::in | std::ios::out
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
				if(ScanningXMLComments)
				{
					if(LineChar.at(0) == XMLCommentFooter.at(CommentIndex))
					{
						XMLCommentBuffer += LineChar;
						if(XMLCommentBuffer == XMLCommentFooter)
						{
							XMLCommentBuffer = "";
							ScanningXMLComments = true;
							CommentIndex = 0;
						}
						else if(CommentIndex < 2)
						{
							CommentIndex++;
						}
						else
						{
							XMLCommentBuffer = "";
							CommentIndex = 0;
						}
					}
					else
					{
						XMLCommentBuffer = "";
						CommentIndex = 0;
					}
				}
				else if(XMLCommentBuffer != "")
				{
					if(LineChar.at(0) == XMLCommentHeader.at(CommentIndex))
					{
						XMLCommentBuffer += LineChar;
						if(XMLCommentBuffer == XMLCommentHeader)
						{
							XMLCommentBuffer = "";
							ScanningXMLComments = true;
							CommentIndex = 0;
						}
						else if(CommentIndex < 3)
						{
							CommentIndex++;
						}
						else
						{//Prevent Bug causing Header to search out of index
							LineString += XMLCommentBuffer;
						}
					}
					else
					{
						LineString += XMLCommentBuffer;
					}
				}
				else if(LineChar == "\n")
				{
					Add(LineString);
					LineString = "";
				}
				else if(LineChar == "<"&&XMLCommentBuffer == "")
				{
					XMLCommentBuffer = "<";
					CommentIndex = 1;
				}
				else
				{
					LineString += LineChar;
				}
				FileStreamState = 2;
			}
			else if(NextChar == EOF || LoadedFileStream.eof())
			{
				if(XMLCommentBuffer != "")
				{
					LineString += XMLCommentBuffer;
				}
				if(LineString != "")
				{
					Add(LineString);
					LineString = "";
				}
				cout << "Reached end of file Data Loaded \n";
				FileStreamState = 3;
				LoadedFileStream.close();
				FileStreamState = -3;
			}
			else
			{
				if(LoadedFileStream.bad())
				{
					cout << "Failed Read/Write operation Error \n";
					FileStreamState = -1;
				}
				else if(LoadedFileStream.fail())
				{
					cout << "Failed format-based Error at Path"<<InputFile<<"\n";
					system("pause");
					FileStreamState = -1;
				}
				else if(LoadedFileStream.bad())
				{
					cout << "Failed Read/Write operation Error \n";
					FileStreamState = -1;
				}
				else
				{
					cout << "Error Number -2 \n";
					FileStreamState = -2;
				}
			}
		}
		else
		{
			cout << "Failed to open" << InputFile << "\n";
			if(LoadedFileStream.eof())
			{
				cout << "Reached end of file Error \n";
			}
			else if(LoadedFileStream.bad())
			{
				cout << "Failed Read/Write operation Error \n";
			}
			else if(LoadedFileStream.fail())
			{
				cout << "Failed format-based Error at Path"<<InputFile<<"\n";
			}
			FileStreamState = 0;
		}
	}
}
void StringVectorList::LoadFileWithoutComments(std::string InputFile)
{
	Reset();
	bool FileStreamOpen = false;
	int FileStreamState = 0;
	string LineString = "";
	string LineChar;
	char NextChar = ' ';
	string CommentBuffer = "";
	const string XMLCommentHeader = "<!--";
	const string XMLCommentFooter = "-->";
	bool ScanningXMLComments = false;
	//---------------
	//Scanning C++ style comments
	bool ScanningComments02 = false;
	// true = LineComments; false = Multi-line comments
	bool LineCommentType = false;
	//-------------------------
	size_t CommentIndex = 0;
	std::fstream LoadedFileStream;
	while(FileStreamState >= 0)
	{
		if(FileStreamOpen == false)
		{
			LoadedFileStream.open(InputFile.c_str());//, std::ios::in | std::ios::out
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
				if(ScanningComments02)
				{
					if(LineCommentType == false)
					{
						if(LineChar == "*")
						{
							CommentBuffer = "*";
						}
						else if(LineChar == "/"&&CommentBuffer == "*")
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
				else if(LineChar == "*"&&CommentBuffer == "/")
				{
					LineCommentType = false;
					ScanningComments02 = true;
				}
				else if(LineChar == "/")
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
					if(LineChar.at(0) == XMLCommentFooter.at(CommentIndex))
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
					if(LineChar.at(0) == XMLCommentHeader.at(CommentIndex))
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
				else if(LineChar == "\n")
				{
					Add(LineString);
					LineString = "";
				}
				else if(LineChar == "<"&&CommentBuffer == "")
				{
					CommentBuffer = "<";
					CommentIndex = 1;
				}
				else
				{
					LineString += LineChar;
				}
				FileStreamState = 2;
			}
			else if(NextChar == EOF || LoadedFileStream.eof())
			{
				if(CommentBuffer != "")
				{
					LineString += CommentBuffer;
				}
				if(LineString != "")
				{
					Add(LineString);
					LineString = "";
				}
				cout << "Reached end of file Data Loaded \n";
				FileStreamState = 3;
				LoadedFileStream.close();
				FileStreamState = -3;
			}
			else
			{
				if(LoadedFileStream.bad())
				{
					cout << "Failed Read/Write operation Error \n";
					FileStreamState = -1;
				}
				else if(LoadedFileStream.fail())
				{
					cout << "Failed format-based Error at Path"<<InputFile<<"\n";
					FileStreamState = -1;
				}
				else if(LoadedFileStream.bad())
				{
					cout << "Failed Read/Write operation Error \n";
					FileStreamState = -1;
				}
				else
				{
					cout << "Error Number -2 \n";
					FileStreamState = -2;
				}
			}
		}
		else
		{
			cout << "Failed to open" << InputFile << "\n";
			if(LoadedFileStream.eof())
			{
				cout << "Reached end of file Error \n";
			}
			else if(LoadedFileStream.bad())
			{
				cout << "Failed Read/Write operation Error \n";
			}
			else if(LoadedFileStream.fail())
			{
				cout << "Failed format-based Error at Path"<<InputFile<<"\n";
			}
			else if(LoadedFileStream.bad())
			{
				cout << "Failed Read/Write operation Error \n";
			}
			FileStreamState = 0;
		}
	}
}

std::string StringVectorList::ConvertToString()
{
	string ConvertedString = "";
	size_t NumberLines = Size();
	for(size_t i = 0; i < NumberLines; ++i)
	{
		if(i != 0)
		{
			ConvertedString += "\n";
		}
		ConvertedString += ElementAt(i);
	}
	return ConvertedString;
}

void StringVectorList::CreateFileIfDoesntExist(std::string FileName)
{
	bool FileExists = false;
	//Based on https://www.quora.com/What-is-the-best-way-to-check-whether-a-particular-file-exists-or-not-in-C++
	struct stat buffer;
	FileExists = (stat(FileName.c_str(), &buffer) == 0);
	return;
	//Based on http://stackoverflow.com/questions/17818099/how-to-check-if-a-file-exists-before-creating-a-new-file
	//if(std::ifstream(FileName))
	//{
	//	std::cout << "File already exists" << std::endl;
	//	return;
	//}
	if(!FileExists)
	{
		std::ofstream file(FileName);
		if(!file)
		{
			std::cout << "File could not be created" << std::endl;
			return;
		}
	}
}

void StringVectorList::SaveDataToFileV3(std::string FileName, bool Verbose/*=false*/)
{
	std::string LineString;
	std::fstream LoadedFileStream;
	//Fix for non-existing file
	CreateFileIfDoesntExist(FileName);
	LoadedFileStream.open(FileName, std::fstream::out || std::fstream::trunc);
	size_t DataSize = Size();
	if(LoadedFileStream.is_open())
	{
		if(LoadedFileStream.good())
		{
			for(size_t i = 0; i < DataSize; ++i)
			{
				if(i != 0)
				{//Carriage Return to next line
					LoadedFileStream << "\n";
				}
				LineString = ElementAt(i);
				if(Verbose) { std::cout << LineString << "\n"; }
				LoadedFileStream << LineString;
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
		cout << "Failed to open " << FileName << ".\n";
	}
}

void StringVectorList::LoadFileDataV2(std::string FileName, unsigned short ConfigSetting/*=0*/, bool Verbose/*=false*/)
{
	FileName = StringFunctions::CheckAndCorrectFilepath(FileName);
	std::string LineString;
	std::ofstream LoadedFileStream;
	LoadedFileStream.open(FileName, std::ios::in);
	size_t DataSize = Size();
	//char NextChar;
	char LineChar;
	string CommentBuffer = "";
	const string XMLCommentHeader = "<!--";
	const string XMLCommentFooter = "-->";
	bool ScanningXMLComments = false;
	//---------------
	//Scanning C++ style comments
	bool ScanningComments02 = false;
	// true = LineComments; false = Multi-line comments
	bool LineCommentType = false;
	//-------------------------
	size_t CommentIndex = 0;
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
					Add(LineString);
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
		cout << "Failed to open filepath:" << FileName << "\n";
	}
}
