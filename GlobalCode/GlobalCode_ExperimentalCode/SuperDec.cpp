/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
	*/
#include "SuperDec.h"

//Non-Alternating headers above (Structure based headers in this section)
#if BlazesGlobalCode_FileStructureVersion == 0 || #ifndef (BlazesGlobalCode_FileStructureVersion)//(library style  layout)
	#include "..\GlobalCode_VariableConversionFunctions\VariableConversionFunctions.h"
#elif BlazesGlobalCode_FileStructureVersion == 1//(Local version style layout)
	#include "VariableConversionFunctions.h"
#endif


//#ifndef BLAZESGLOBALCODE_EnableFloatingPointMultiplication
//	#define BLAZESGLOBALCODE_EnableFloatingPointMultiplication 1
//#endif

//#ifndef BLAZESGLOBALCODE_SpecialDecStatus
//	#define BLAZESGLOBALCODE_SpecialDecStatus 0
//#endif

template <typename IntType>
SuperDec_BaseClass SuperDec_BaseClass<IntType>::operator=(std::string Value)
{

}

template <typename IntType>
SuperDec_BaseClass SuperDec_BaseClass<IntType>::operator+(std::string Value)
{

}

template <typename IntType>
SuperDec_BaseClass SuperDec_BaseClass::operator=(unsigned int Value)
{
	if(Value = 0)
	{
		DecimalStatus = 0;
		IntValue = 0;
	}
	else
	{
		DecimalStatus = 0;
		IntValue = Value;
	}
}

template <typename IntType>
SuperDec_BaseClass SuperDec_BaseClass::operator=(int Value)
{
	if(Value = 0)
	{
		DecimalStatus = 0;
		IntValue = 0;
	}
	else if(Value < 0)
	{
		DecimalStatus = 100;
		IntValue = Value*-1;
	}
	else
	{
		DecimalStatus = 0;
		IntValue = Value;
	}
}

template <typename IntType>
SuperDec_BaseClass SuperDec_BaseClass::operator=(signed __int64 Value)
{
	if(Value = 0)
	{
		DecimalStatus = 0;
		IntValue = 0;
	}
	else if(Value < 0)
	{
		DecimalStatus = 100;
		IntValue = Value*-1;
	}
	else
	{
		DecimalStatus = 0;
		IntValue = Value;
	}
}

template <typename IntType>
SuperDec_BaseClass SuperDec_BaseClass::operator=(unsigned __int64 Value)
{
	if(Value = 0)
	{
		DecimalStatus = 0;
		IntValue = 0;
	}
	else
	{
		DecimalStatus = 0;
		IntValue = Value;
	}
}

SuperDec_Basic SuperDec_Basic::operator=(double Value)
{
	signed __int64 WholeHalf = floor(Value);
	SuperDec_BaseClass::operator=(WholeHalf);
	std::string DecimalPart = VariableConversionFunctions::DoubleToStringConversion(Value);
	bool IsNegative;
	if(DecimalPart.at(0) == '-')
	{
		IsNegative = true;
	}
	else
	{
		IsNegative = false;
	}
	unsigned int SizeTemp = DecimalPart.length();
	bool InsideDecimal = false;
	unsigned __int16 DecimalBuffer = 0;
	unsigned __int8 DecimalIndex = 0;
	for(unsigned __int8 Index = 0; Index < SizeTemp; ++Index)
	{
		if(InsideDecimal)
		{
			++DecimalIndex;
			if(DecimalIndex == 1)
			{
				DecimalBuffer += VariableConversionFunctions::CharAsInt(DecimalPart.at(Index));
			}
			else if(DecimalIndex == 2)
			{
				DecimalBuffer += VariableConversionFunctions::CharAsInt(DecimalPart.at(Index)) * 10;
				if(IsNegative)
				{
					DecimalStatus = DecimalBuffer + 100;
				}
				else
				{
					DecimalStatus = DecimalBuffer;
				}
				DecimalBuffer = 0;
			}
			else//For Decimal Places higher than 2
			{
				//Create code for this later
			}
		}
	}
	//Calculate Buffer difference if haven't yet
	if(DecimalIndex < 2)
	{
		if(IsNegative) { DecimalStatus = DecimalBuffer + 100; }
		else { DecimalStatus = DecimalBuffer; }
	}
}

SuperDec_Basic SuperDec_Basic::operator*(float Value)
{
	if(floor(Value) == Value)//Whole Number Detected
	{
		ApplyIntValueMultOperation((int) Value);
	}
	else
	{

	}
}

SuperDec_Basic SuperDec_Basic::operator*(double Value)
{
	int WholeHalfValue = floor(Value);
	if(WholeHalfValue==Value)//Whole Number Detected
	{
		ApplyIntValueMultOperation((int)Value);
	}
	else
	{
		bool IsNegative=false;
		if(WholeHalfValue<0)
		{
			IsNegative = true;
			Value*=-1;
			WholeHalfValue*=-1;
		}
		double DecimalHalfValue = Value - WholeHalfValue;
		#ifdef BLAZESGLOBALCODE_SpecialDecStatus
		if(DecimalStatus>200)//Only Makes this check if BLAZESGLOBALCODE_SpecialDecStatus usage is enabled
		{
		
		}
		else
		{
		#endif
			//Represents stored value as IntValue then (Decimal Value) for rest of degits (need to reserve more of Decimal Places for if larger max stored decimal value or use alternative represention (should work with most decimal storage as long as IntValue is int32 instead of int64 otherwise need to check size before deciding representation
			__int64 StoredValue = IntValue*100+(DecimalStatus>100?DecimalStatus-100:DecimalStatus);
			//if(WholeHalfValue==0)//Decimal Only Multiplication
			//{
			//	#if BLAZESGLOBALCODE_EnableFloatingPointMultiplication == 1
			//	
			//	#else
			//	
			//	#endif
			//}
			//else
			//{
			//	//(IntValue+Decimal)*X = (IntValue*X) + (Decimal*X)
			//	//X = (XIntPart+XDecimalPart)
			//	//(IntValue*XIntPart)+(IntValue*XDecimalPart)+(Decimal*XIntPart)+(Decimal*XDecimalPart)
			//}
		#ifdef BLAZESGLOBALCODE_SpecialDecStatus
		}
		#endif
	}
}

