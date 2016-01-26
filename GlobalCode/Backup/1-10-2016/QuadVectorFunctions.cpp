/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code release available at http://www.nexusmods.com/skyrim/mods/44884/?
	*/
#include "QuadVectorFunctions.h"
#include <string>
#include "StringFunctions.h"

using std::string;

QuadVector QuadVectorFunctions::ReadQuadVectorFromString(string LineString)
{
	//Current character loaded in steam
	char StringChar;
	QuadVector StorageValue;
	//Current Characters worth of string found of Double Value
	string PartialSearchBuffer = "";
	//Temporary Storage of converted double value
	double DoubleStorageTemp;
	//Vector index of value to store
	int VectorIndex = 0;
	//Scanning Double value check for index
	bool ScanningDouble = false;
	//Total size of LineString to load
	int StringSize = LineString.size();
	for(int i = 0; i < StringSize&&VectorIndex < 4; i++)
	{
		StringChar = LineString.at(i);
		if(StringChar == ' ' || StringChar == '	'&&PartialSearchBuffer != "")
		{
			if(ScanningDouble)
			{
				DoubleStorageTemp = StringFunctions::ReadDoubleFromString(PartialSearchBuffer);
				StorageValue.StoreInVectorIndex(VectorIndex, DoubleStorageTemp);
				PartialSearchBuffer = "";
				VectorIndex++;
			}
		}
		else if(StringChar == '.' || StringChar == '0' || StringChar == '1' || StringChar == '2' || StringChar == '3' || StringChar == '4' || StringChar == '5' || StringChar == '6' || StringChar == '7' || StringChar == '8' || StringChar == '9' || StringChar == '-')
		{
			PartialSearchBuffer += StringChar;
			if(ScanningDouble == false) { ScanningDouble = true; }
		}
	}
	return StorageValue;
}

std::string QuadVectorFunctions::QuadVectorToStringConversion(QuadVector TempValue)
{
	return TempValue.ConvertToString();
}

QuadVectorFunctions::QuadVectorFunctions()
{}

QuadVectorFunctions::~QuadVectorFunctions()
{}