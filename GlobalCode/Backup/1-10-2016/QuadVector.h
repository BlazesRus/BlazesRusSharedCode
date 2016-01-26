#pragma once

#include <string>
#include "VariableTypeLists.h"
#include "VariableList.h"

using std::string;

class QuadVector
{
public:
	double PositionX = 0.0;
	double PositionY = 0.0;
	double PositionZ = 0.0;
	double PositionW = 0.0;
	//Store values in Position in vector
	void StoreInVectorIndex(int index, double TempValue);
	//Get value based on index value
	double GetVectorValue(int index);
	//Reconstruct as string
	string ConvertToString();
	//Reconstruct as DoubleList vector
	DoubleList ConvertToDoubleList();
	////implicit conversion
	//operator string(){ return ConvertToString(); }
	//// explicit conversion
	//explicit operator string(){ return ConvertToString(); }
	////implicit conversion
	//operator DoubleList(){ return ConvertToDoubleList(); }
	//// explicit conversion
	//explicit operator DoubleList(){ return ConvertToDoubleList(); }
	//Extract Positions from TempString
	QuadVector(string TempString);
	QuadVector();
	~QuadVector();
};

class QuadVectorList : public VariableList < QuadVector >
{
	int AddData();
};