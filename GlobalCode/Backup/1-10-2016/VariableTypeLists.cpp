/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code release available at http://www.nexusmods.com/skyrim/mods/44884/?
	*/
#include "VariableTypeLists.h"
#include <iostream>
#include <fstream>
#include "StringFunctions.h"

using std::cout;
using std::string;

void DoubleList::SaveDataToFile(std::string Path)
{
	std::string LineString;
	fstream CraftedIniFile;
	CraftedIniFile.open(Path, std::ios::out || std::ios::trunc);
	int DataSize = Size();
	if(CraftedIniFile.is_open())
	{
		for(int i = 0; i < DataSize; i++)
		{
			if(i != 0)
			{//Carriage Return to next line
				CraftedIniFile << "\r\n";
			}
			LineString = StringFunctions::DoubleToStringConversion(ElementAt(i));
			CraftedIniFile << LineString;
		}
		CraftedIniFile.close();
	}
	else
	{
		cout << "Failed to open" << Path << "\n";
	}
}

int DoubleList::AddData()
{
	int Index = Size();
	double TempValue = 0.0;
	Add(TempValue);
	return Index;
}

int IntegerList::AddData()
{
	int Index = Size();
	int TempValue = 0;
	Add(TempValue);
	return Index;
}

void IntegerList::SaveDataToFile(std::string Path)
{
	std::string LineString;
	fstream CraftedIniFile;
	CraftedIniFile.open(Path, std::ios::out || std::ios::trunc);
	int DataSize = Size();
	if(CraftedIniFile.is_open())
	{
		for(int i = 0; i < DataSize; i++)
		{
			if(i != 0)
			{//Carriage Return to next line
				CraftedIniFile << "\r\n";
			}
			LineString = StringFunctions::IntToStringConversion(ElementAt(i));
			CraftedIniFile << LineString;
		}
		CraftedIniFile.close();
	}
	else
	{
		cout << "Failed to open" << Path << "\n";
	}
}

StringVectorList DoubleList::AsStringList()
{
	StringVectorList TempStringList;
	string TempString;
	int TempInt = Size();
	for(int i = 0; i < TempInt; i++)
	{
		TempString = StringFunctions::DoubleAsString(ElementAt(i));
		TempStringList.Add(TempString);
	}
	return TempStringList;
}

StringVectorList IntegerList::AsStringList()
{
	StringVectorList TempStringList;
	string TempString;
	int TempInt = Size();
	for(int i = 0; i < TempInt; i++)
	{
		TempString = StringFunctions::IntToStringConversion(ElementAt(i));
		TempStringList.Add(TempString);
	}
	return TempStringList;
}

void IntegerList::AddEntry()
{
	this->Add(0);
}

void IntegerList::EditLastEntry(int TempValue)
{
	int LastIndex = this->Size() - 1;
	this->ElementAt(LastIndex);
}

string IntegerList::GenerateAsString()
{
	string ListString;
	int TempValue;
	int TempSize = this->Size();
	for(int i = 0; i < TempSize; i++)
	{
		TempValue = this->ElementAt(i);
		if(i == 0)
		{
			ListString = StringFunctions::IntToStringConversion(TempValue);
		}
		else
		{
			ListString += "_";
			ListString += StringFunctions::IntToStringConversion(TempValue);
		}
	}
	return ListString;
}

int BoolList::AddData()
{
	int Index = Size();
	bool TempValue = false;
	Add(TempValue);
	return Index;
}

void BoolList::SaveDataToFile(std::string Path)
{
	std::string LineString;
	fstream CraftedIniFile;
	CraftedIniFile.open(Path, std::ios::out || std::ios::trunc);
	int DataSize = Size();
	if(CraftedIniFile.is_open())
	{
		for(int i = 0; i < DataSize; i++)
		{
			if(i != 0)
			{//Carriage Return to next line
				CraftedIniFile << "\r\n";
			}
			LineString = StringFunctions::BoolAsString(ElementAt(i));
			CraftedIniFile << LineString;
		}
		CraftedIniFile.close();
	}
	else
	{
		cout << "Failed to open" << Path << "\n";
	}
}

StringVectorList BoolList::AsStringList()
{
	StringVectorList TempStringList;
	string TempString;
	int TempInt = Size();
	for(int i = 0; i < TempInt; i++)
	{
		TempString = StringFunctions::BoolAsString(ElementAt(i));
		TempStringList.Add(TempString);
	}
	return TempStringList;
}