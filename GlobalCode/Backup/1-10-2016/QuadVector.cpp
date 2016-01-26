/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code release available at http://www.nexusmods.com/skyrim/mods/44884/?
	*/
#include "QuadVector.h"
#include "StringFunctions.h"
#include "MiscFunctions.h"

void QuadVector::StoreInVectorIndex(int index, double TempValue)
{
	if(index == 0) { PositionX = TempValue; }
	else if(index == 1) { PositionY = TempValue; }
	else if(index == 2) { PositionZ = TempValue; }
	else if(index == 3) { PositionW = TempValue; }
}

double QuadVector::GetVectorValue(int index)
{
	if(index == 0) { return PositionX; }
	else if(index == 1) { return PositionY; }
	else if(index == 2) { return PositionZ; }
	else if(index == 3) { return PositionW; }
	else { return 0.0;/*Error Value but return 0.0 to prevent crash*/ }
}

//converts variables back into string format that havok uses in files(0.000000 0.000000 0.000000 0.000000)
string QuadVector::ConvertToString()
{
	string TempString = "(";
	TempString += std::to_string(PositionX);
	TempString += " ";
	TempString += std::to_string(PositionY);
	TempString += " ";
	TempString += std::to_string(PositionZ);
	TempString += " ";
	TempString += std::to_string(PositionW);
	TempString += ")";
	TempString += StringFunctions::DoubleToStringConversion(1.1);
	return TempString;
}

DoubleList QuadVector::ConvertToDoubleList()
{
	DoubleList TempValue;
	for(int i = 0; i < 4; i++)
	{
		TempValue.Add(GetVectorValue(i));
	}
	return TempValue;
}

QuadVector::QuadVector(string TempString)
{
	int StringLength;
	StringLength = TempString.length();
	string ValueExtractionBuffer = "";
	//Temporary Storage of converted double value
	double DoubleStorageTemp;
	//Current character loaded in steam
	string StringChar;
	//Vector index of value to store
	int VectorIndex = 0;
	for(int i = 0; i < StringLength&&VectorIndex < 4; i++)
	{
		StringChar = TempString.at(i);
		if(StringChar == " " || StringChar == "\t" || StringChar == ")")
		{
			if(ValueExtractionBuffer != "")
			{
				//std::cout << "ValueStored:" << ValueExtractionBuffer << " VectorIndex:" << VectorIndex << "\n";
				DoubleStorageTemp = StringFunctions::ReadDoubleFromString(ValueExtractionBuffer);
				StoreInVectorIndex(VectorIndex, DoubleStorageTemp);
				ValueExtractionBuffer = "";
				VectorIndex++;
			}
		}
		else if(StringChar == "." || StringFunctions::IsDigit(StringChar) || StringChar == "-")
		{
			ValueExtractionBuffer += StringChar;
		}
	}
}

QuadVector::QuadVector()
{}

QuadVector::~QuadVector()
{}

int QuadVectorList::AddData()
{
	int Index = Size();
	QuadVector TempValue = QuadVector("(0.0 0.0 0.0 0.0)");
	Add(TempValue);
	return Index;
}