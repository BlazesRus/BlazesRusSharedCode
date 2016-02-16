/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef SuperDec_IncludeGuard
#define SuperDec_IncludeGuard

#include <io.h>
#include <math.h>
#include <iostream>

//Class holding higher possible precision Decimal Values (64Bit only version)(Not Finished)
class SuperDec
{
public:
	size_t IntValue = 0;
	size_t ExtraIntValue01;
	bool IsNegative = false;
	//Only the non-negative decimal half of the value
	double DecimalValue = 0.0;
	//0 = default
	//1 = Value has hit over maximum value(storing extra overflow into ExtraIntValue01)
	unsigned __int8 ValueState = 0;
	//************************************
	// Method:    AsInt
	// FullName:  SuperDec::AsInt
	// Access:    public 
	// Returns:   int
	// Qualifier:
	//************************************
	int AsInt()
	{
		int ValueAsInt;
		//Check for overflow value
		if(IntValue<=2147483647)
		{
			ValueAsInt = IntValue;
		}
		else
		{
			std::cout << "Only partial of value could convert to int(Int value stored exceeds 2,147,483,647).";
			ValueAsInt = 2147483647;
		}
		if(IsNegative) { ValueAsInt*=-1; }
		return ValueAsInt;
	}
	unsigned int AsUnsignedInt()
	{
		unsigned int ValueAsInt;
		//Check for overflow value
		if(IntValue <= 4294967295)
		{
			ValueAsInt = IntValue;
		}
		else
		{
			std::cout << "Only partial of value could convert to int(Int value stored exceeds 4,294,967,295).";
			ValueAsInt = 4294967295;
		}
		if(IsNegative) { std::cout << "Value auto-converted to positive value.\n"; }
		return ValueAsInt;
	}
	void ConvertFromIntToSuperDec(int Value)
	{
		if(Value<0)
		{
			IsNegative = true;
			IntValue = Value*-1;
		}
		else
		{
			IsNegative = false;
			IntValue = Value;
		}
		DecimalValue = 0.0;
	}
	void ConvertFromDoubleToSuperDec(double Value)
	{
		double RemainingValue = Value;
		if(Value < 0)
		{
			IsNegative = true;
			RemainingValue *= -1;
		}
		else
		{
			IsNegative = false;
		}
		IntValue = floor(RemainingValue);
		DecimalValue = RemainingValue - (double) IntValue;
	}
	SuperDec();
	~SuperDec();
};
#endif