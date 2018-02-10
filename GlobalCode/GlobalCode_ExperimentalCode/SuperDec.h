/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
	(Consider this old version of CustomDec; Using as reference for new version of code)
*/
#ifndef SuperDec_IncludeGuard
#define SuperDec_IncludeGuard

//#ifndef BlazesGlobalCode_FileStructureVersion
//	#define BlazesGlobalCode_FileStructureVersion 0
//	//FileStructureVersion 0 = Refers to required files set up similar/same as Library Versions of files
//	//FileStructureVersion 1 = All required files from GlobalCode within same folder locally
//#endif

#ifdef BLAZESGLOBALCODE_LIBRARY
	#include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
	#ifndef DLL_API
		#define DLL_API
	#endif
#endif

#include <io.h>
#include <math.h>
#include <iostream>
#include <string>
#include "SuperDecHex.h"

//Non-Alternating headers above (Structure based headers in this section)
//#ifndef BlazesGlobalCode_FileStructureVersion || BlazesGlobalCode_FileStructureVersion == 0
	//Place  library Style  layout here
//#elif BlazesGlobalCode_FileStructureVersion == 1
	//Place Local version layout here
//#endif

//High Precision Decimal Class (BaseClass defaults to up to 32 Bit unsigned int of whole numbers, plus negative modifier and 2 decimal places of stored digits;5 Bytes Total Stored for Base class if using Unsigned __int32 for wholenumber half(default))
template <typename IntType = unsigned __int32>
class DLL_API SuperDec_BaseClass
{
public:
	IntType IntValue = 0;

#ifdef SuperDec_EnableOverflowStorage
	unsigned __int64 ExtraIntValue01;
#endif

	//0 = IntValue.000
	//1 - 99 = IntValue.XX
	//100 = -IntValue
	//100-199 = -IntValue.XX
	//200 = Positive Infinity
	//201 = IntValue+1/3
	//202 = IntValue+2/3
	//203 = IntValue+1/6
	//204 = IntValue+5/6
	//205 = pi
	//206 = -IntValue-1/3
	//207 = -IntValue-2/3
	//208 = -IntValue-1/6
	//209 = -IntValue-5/6
	//210 = -pi
	//211 = Negative Infinity
	//212 = IntValue/pi
	//213 = -IntValue/pi
	//214 = IntValue*pi
	//215 = -IntValue*pi
	//216 = IntValue/3
	//217 = -IntValue/3
	//218 = -IntValue/6
	//219 = -IntValue/7
	//220 = -IntValue/9
	//221 = -IntValue/11
	//222 = -IntValue/13
	//223 = IntValue/6
	//224 = IntValue/7
	//225 = IntValue/9
	//226 = IntValue/11
	//227 = IntValue/13
	//250 = Undefined Value Flag (Usable without SuperDec_EnableFractionalStorage but only for status of not setting actual value)
	//251 = N/A (value sent if divide by zero and such for now)
	//Holds first 2 places in Decimal as perfect Accuracy (plus some other specific values if optional preprocessor switch SuperDec_EnableFractionalStorage is on)
	//All statuses here above 199(except value 250) require SuperDec_EnableFractionalStorage on to be used right now
	unsigned __int8 DecimalStatus;
	//************************************
	// Method:    GetAsDouble
	// FullName:  SuperDec_BaseClass<IntType>::GetAsDouble
	// Access:    public
	// Returns:   double
	// Qualifier:
	//************************************
	double GetAsDouble()
	{
#ifdef SuperDec_EnableFractionalStorage
#endif
		bool IsPositive = DecimalStatus < 100;
		if(IsPositive == false) { DecimalStatus -= 100; }
		return IsPositive ? (IntValue + (DecimalStatus*.01)) : (IntValue + (DecimalStatus*.01))*-1;
	}
	template <typename ValueType>
	void ApplyUnsignedAddition(ValueType Value)
	{
		if(DecimalStatus < 100)//IntValue is Positive
		{
			if(Value > 0)
			{
				IntValue += Value;
			}
			else
			{
				Value *= -1;
				if(Value > IntValue)
				{
					IntValue = Value - IntValue;
					DecimalStatus += 100;
				}
				else
				{
					IntValue -= Value;
				}
			}
		}
		else if(DecimalStatus == 211 || DecimalStatus == 200)
		{
			std::cout << "Can't add to Infinity\n";
		}
		else if(DecimalStatus < 199)//IntValue is Negative
		{
			if(Value < 0)
			{
				IntValue -= Value;
			}
			else
			{
				if(Value > IntValue)
				{
					IntValue = Value - IntValue;
					DecimalStatus -= 100;
				}
				else
				{
					IntValue -= Value;
				}
			}
		}
	}
	template <typename ValueType>
	void ApplySignedAddition(ValueType Value)
	{
		if(DecimalStatus < 100)
		{
			IntValue += Value;
		}
		else if(DecimalStatus == 211 || DecimalStatus == 200)
		{
			std::cout << "Can't add to Infinity\n";
		}
		else if(DecimalStatus < 199)
		{
			if(Value > IntValue)
			{
				IntValue = Value - IntValue;
				DecimalStatus -= 100;
			}
			else
			{
				IntValue -= Value;
			}
		}
	}
	SuperDec_BaseClass operator+(unsigned int Value) { ApplyUnsignedAddition(&Value); }
	SuperDec_BaseClass operator+(signed int Value) { ApplySignedAddition(&Value); }
	SuperDec_BaseClass operator+(unsigned __int64 Value) { ApplyUnsignedAddition(&Value); }
	SuperDec_BaseClass operator+(signed __int64 Value) { ApplySignedAddition(&Value); }
	void PlusOperation_AddDecimalBuffer(unsigned __int8 DecimalBuffer)
	{
		if(IsNegative)
		{
			if(DecimalStatus == 0) { DecimalStatus = DecimalBuffer*-1; }
			else if(DecimalStatus < 100)
			{//Positive Value Minus Negative Value
				if(DecimalStatus > DecimalBuffer)
				{
					DecimalStatus -= DecimalBuffer;
				}
				else
				{
					DecimalStatus -= DecimalBuffer;
					//Minus 1 from Int part
					if(IntValue == 1)
					{
						IntValue = 0;
					}
					else if(IntValue == 0)
					{
						DecimalStatus += 100;
						IntValue = 1;
					}
					else
					{
						--IntValue;
					}
				}
			}
			else if(DecimalStatus < 199)
			{//Negative Value - Negative Value
				DecimalStatus += DecimalBuffer;
				if(DecimalStatus > 199)
				{
					DecimalStatus -= 100;
					++IntValue;
				}
			}
		}
		else
		{
			if(DecimalStatus == 0) { DecimalStatus = DecimalBuffer; }
			else if(DecimalStatus < 100)
			{//Positive Value + Positive Value
				DecimalStatus += DecimalBuffer;
				if(DecimalStatus > 99)
				{
					DecimalStatus -= 100;
					++IntValue;
				}
			}
			else if(DecimalStatus < 199)
			{//Negative Value + Positive Value
				//DecimalStatus -= DecimalBuffer;
				if(DecimalBuffer = DecimalStatus)
					(
					DecimalBuffer = 0;
			}
			else if(DecimalBuffer > DecimalStatus)
			{//-.2+..3
				//DecimalStatus = DecimalBuffer-DecimalStatus;
				DecimalStatus -= DecimalBuffer;
				if(DecimalStatus < 100)
				{
					if(IntValue == 0)
					{//Moves from negative to positive
						IntValue = 1;
					}
					else if(IntValue == 1)
					{//Still Negative ??.??
						IntValue = 0;
						DecimalBuffer += 100;
					}
					else
					{//Still Negative but closer to positive now
						DecimalBuffer += 100;
						--IntValue;
					}
				}
			}
		}
	}
	SuperDec_BaseClass operator+(double Value)
	{
		unsigned __int64 WholeNumberPart = floor(Value);
		/* Start of WholeNumberPart of Calculations */
		if(DecimalStatus < 100)//IntValue is Positive
		{
			if(WholeNumberPart > 0)
			{
				IntValue += WholeNumberPart;
			}
			else
			{
				WholeNumberPart *= -1;
				if(WholeNumberPart > IntValue)
				{
					IntValue = WholeNumberPart - IntValue;
					DecimalStatus += 100;
				}
				else
				{
					IntValue -= WholeNumberPart;
				}
			}
		}
		else if(DecimalStatus == 211 || DecimalStatus == 200)
		{
			std::cout << "Can't add to Infinity\n";
		}
		else if(DecimalStatus < 199)//IntValue is Negative
		{
			if(WholeNumberPart < 0)
			{
				IntValue -= WholeNumberPart;
			}
			else
			{
				if(Value > IntValue)
				{
					IntValue = WholeNumberPart - IntValue;
					DecimalStatus -= 100;
				}
				else
				{
					IntValue -= WholeNumberPart;
				}
			}
		}
		/* End of WholeNumberPart of Calculations*/
		//Now perform decimal half of calculations
		//Convert Value to String to prevent multiple minor floating-point inaccuracies from adding extra potential error
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
		unsigned __int8 DecimalBuffer = 0;
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
					PlusOperation_AddDecimalBuffer(DecimalBuffer);
				}
				else
				{/*--Placeholder for Extra Digit Calculations--*/
				}
			}
			else if(DecimalPart.at(Index) == '.')
			{
				InsideDecimal = true;
			}
		}
		//Calculate Buffer difference if haven't yet
		if(DecimalIndex < 2)
		{
			PlusOperation_AddDecimalBuffer(DecimalBuffer);
		}
	}
	SuperDec_BaseClass operator+(std::string Value);
	template <typename ValueType>
	void ApplyEqualFloatValueOperation(ValueType Value)
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
				{/*--Placeholder for other derived classes extra decimal place storage*/
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
	SuperDec_BaseClass operator=(double Value)
	{
		SuperDec_BaseClass::operator=((signed __int64) floor(Value));
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
				{/*--Placeholder for other derived classes extra decimal place storage*/
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
	SuperDec_BaseClass operator=(float Value) { ApplyEqualFloatValueOperation(&Value); }
	SuperDec_BaseClass operator=(std::string Value);
	SuperDec_BaseClass operator=(unsigned int Value);
	SuperDec_BaseClass operator=(int Value);
	template <typename ValueType>
	SuperDec_BaseClass operator%(ValueType Value) { IntValue %= Value; }
	template <typename ValueType>
	void ApplyIntValueMultOperation(ValueType Value)
	{
		if(Value == 0 || (DecimalStatus == 0 && IntValue == 0))
		{
			IntValue = 0;
			DecimalStatus = 0;
		}
#ifdef SuperDec_EnableFractionalStorage
#endif
		else
		{
			//bool ValueIsNegative = Value < 0;
			if(Value < 0)
			{
				Value *= -1;
				if(DecimalStatus < 100)//Flip positive to negative
				{
					DecimalStatus += 100;
				}
				else
				{
					DecimalStatus -= 100;
				}
			}
			if(Value == IntValue)
			{
				IntValue = 1;
			}
			else
			{
				IntValue *= Value;
			}
			bool StatusIsNegative = DecimalStatus>100;
			unsigned __int64 DecimalBuffer = DecimalStatus;
			if(StatusIsNegative)
			{
				DecimalBuffer -= 100;
			}
			for(DecimalBuffer *= Value; DecimalBuffer > 100; DecimalBuffer -= 100;)
			{
				++IntValue;
			}
			if(StatusIsNegative)
			{
				DecimalBuffer += 100;
			}
			DecimalStatus = DecimalBuffer;
		}
	}
//	template <typename ValueType>
//	void ApplyFloatValueMultOperation(ValueType Value, unsigned __int8 MethodType = 0, bool DivideInstead = false)
//	{
//		if(DivideInstead&&Value==0)
//		{//Return similar to N/A result
//			DecimalStatus = 251;
//		}
//		else if(Value == 0 || (DecimalStatus == 0 && IntValue == 0))
//		{
//			IntValue = 0;
//			DecimalStatus = 0;
//		}
//		else if(DecimalStatus>199)
//		{//Fractional And other such more "abstract" value operations here(Not implimented yet)
//		}
//		else
//		{
//			bool StatusIsNegative = DecimalStatus>100;
//			if(StatusIsNegative)
//			{
//				DecimalStatus -= 100;
//			}
//			//(IntValue+Decimal)*X = (IntValue*X) + (Decimal*X)
//			//X = (XIntPart+XDecimalPart)
//			//(IntValue*XIntPart)+(IntValue*XDecimalPart)+(Decimal*XIntPart)+(Decimal*XDecimalPart)
//			bool ValueIsNegative;
//			if(Value < 0)
//			{
//				Value *= -1;
//				ValueIsNegative = true;
//			}
//			else { ValueIsNegative = false; }
//			unsigned __int64 ValueIntPart = floor(Value);
//			//Store Decimal Half as 
//			switch(MethodType)
//			{
//				case 2://DecimalHalf of Value x 1000000 (Keep only 6 Digits of decimal half of value)
//				{
//					//(IntValue*XIntPart)+(IntValue*XDecimalPart)+(Decimal*XIntPart)+(Decimal*XDecimalPart)
//					unsigned __int64 ValueDecimalPart_X1000000 = (Value - ValueIntPart) * 1000000;
//				}break;
//				case 1://just apply operations using double to multiple
//				{
//				
//				}break;
//				default://Store Decimal Half as double
//				{
//				
//				}
//			}
//			if(MethodType==2)
//			{
//			
//			}
//			else
//			{
//				
//				
//			}
//
//			if(MethodType == 2)
//			{
//
//				//Split value into decimal and whole half
//				unsigned __int64 WholeHalfOfValue = floor(Value);
//				//
//				//ApplyIntValueMultOperation(ValueType Value)
//			}
//			else
//			{
//				//bool ValueIsNegative = Value < 0;
//				if(Value < 0)
//				{
//					Value *= -1;
//					if(DecimalStatus < 100)//Flip positive to negative
//					{
//						DecimalStatus += 100;
//					}
//#ifdef SuperDec_EnableFractionalStorage
//#endif
//					else
//					{
//						DecimalStatus -= 100;
//					}
//				}
//				bool StatusIsNegative = DecimalStatus>100;
//				unsigned __int64 DecimalBuffer = DecimalStatus;
//				if(StatusIsNegative)
//				{
//					DecimalBuffer -= 100;
//				}
//				switch(MethodType)
//				{
//					case 0:
//					{
//						unsigned __int64 IntBuffer = IntValue;
//					}break;
//					//Convert Values to double then multiple method here
//					case 1:
//					{
//						double TempValue GetAsDouble()*Value;
//					}break;
//				}
//				//ValueType WholeHalfOfValue = floor(Value);
//				//double DecimalHalfTemp = 0.0;
//				//DecimalHalfTemp = Value - WholeHalfOfValue;
//				////DecimalHalfOfValue = Value -
//				//unsigned __int64 DecimalBuffer = DecimalStatus;
//				}
//			}
//			//IntValue *= Value;
//		}
	//void ApplySuperDecValueMultOperation(SuperDec_BaseClass Value, bool DivideInstead = false)
	//{
	//	if(Value.DecimalStatus==0)//Positive Whole Number Value
	//	{
	//		if(DecimalStatus==0)//WholeNumber x (Whole Number Value)
	//		{
	//		
	//		}
	//		else if(DecimalStatus==100)//WholeNumber x (Negative Whole Number Value)
	//		{
	//		
	//		}
	//		else
	//		{
	//		
	//		}
	//	}
	//	else if(Value.DecimalStatus==100)//Negative Whole Number Value
	//	{
	//		if(DecimalStatus==0)//WholeNumber x (Whole Number Value)
	//		{
	//		
	//		}
	//		else if(DecimalStatus==100)//WholeNumber x (Negative Whole Number Value)
	//		{
	//			DecimalStatus = 0;//Flip Negative Number to positive
	//			
	//		}
	//		else
	//		{
	//		
	//		}
	//	}
	//	else if(Value.DecimalStatus>199)//Operation using non-standard Value Status(Work on code for this last)
	//	{}
	//	else if(Value.DecimalStatus<100)//Positive Decimal Number Value
	//	{
	//	
	//	}
	//	else//Negative Decimal Value
	//	{
	//	
	//	}
	//}
	template <typename ValueType>
	void ApplyIntValueDivideOperation(ValueType Value)
	{
		if(Value == 0)
		{//Return similar to N/A result
			DecimalStatus = 251;
		}
		else if(DecimalStatus == 0 && IntValue == 0)
		{
			IntValue = 0;
			DecimalStatus = 0;
		}
		else
		{
			if(Value < 0)
			{
				if(DecimalStatus < 100)//Flip positive to negative
				{
					DecimalStatus += 100;
				}
#ifdef SuperDec_EnableFractionalStorage
#endif
				else
				{
					DecimalStatus -= 100;
				}
				Value *= -1;
			}
			//Create rest of the code here later
		}
		}
	//template <typename ValueType>
	//void ApplyFloatValueDivideOperation(ValueType Value, unsigned __int8 MethodType = 0)
	//{
	//	//Placing Divide Operation code inside one actual function to make easier to work on code and "maintain"
	//	ApplyFloatValueMultOperation(ValueType Value, MethodType, true);
	//}
	//void ApplySuperDecValueDivideOperation(SuperDec_BaseClass Value)
	//{
	//	//Actual Code inside Multi Version to make easier to update
	//	ApplySuperDecValueMultOperation(Value, true);
	//}
	SuperDec_BaseClass operator*(signed int Value) { ApplyIntValueMultOperation(&Value); }
	SuperDec_BaseClass operator*(unsigned int Value) { ApplyIntValueMultOperation(&Value); }
	SuperDec_BaseClass operator*(signed __int8 Value) { ApplyIntValueMultOperation(&Value); }
	SuperDec_BaseClass operator*(unsigned __int8 Value) { ApplyIntValueMultOperation(&Value); }
	SuperDec_BaseClass operator*(signed __int64 Value) { ApplyIntValueMultOperation(&Value); }
	SuperDec_BaseClass operator*(unsigned __int64 Value) { ApplyIntValueMultOperation(&Value); }
	SuperDec_BaseClass operator%(signed int Value) { ApplyIntValueDivideOperation(&Value); }
	SuperDec_BaseClass operator%(unsigned int Value) { ApplyIntValueDivideOperation(&Value); }
	SuperDec_BaseClass operator%(signed __int8 Value) { ApplyIntValueDivideOperation(&Value); }
	SuperDec_BaseClass operator%(unsigned __int8 Value) { ApplyIntValueDivideOperation(&Value); }
	SuperDec_BaseClass operator%(signed __int64 Value) { ApplyIntValueDivideOperation(&Value); }
	SuperDec_BaseClass operator%(unsigned __int64 Value) { ApplyIntValueDivideOperation(&Value); }
	SuperDec_BaseClass operator=(signed __int64 Value);
	SuperDec_BaseClass operator=(unsigned __int64 Value);
	SuperDec_BaseClass(SuperDec_BaseClass const& copy) = default;
	SuperDec_BaseClass& operator=(SuperDec_BaseClass const& copy) = default;
	SuperDec_BaseClass() {}
	~SuperDec_BaseClass() {}
	};

class SuperDec_64BitBasic : public SuperDec_BaseClass <unsigned __int64>
{};

/* Notes on digit storable space possible for different Interger values (such as XXXXXX.XXXXX digits):
signed __int64 holds XX digits

unsigned __int8 (aka unsigned char) holds 2 digits (plus +- status) 
unsigned __int16 (aka unsigned short) holds XX digits (plus +- status)
unsigned __int32 holds XX digits (plus +- status)
unsigned __int64 holds XX digits (plus +- status)

Required amount of storage for whole number half of representation:
signed __int16 needs
signed __int32 needs 
signed __int64 needs 

*/

//Stores 5 Bytes worth of data to store with 100% accuracy +- Int32 with 2 Decimal places stored
//(4 Bytes for Int32;1 Byte for 2 Decimal places plus decimal status of +- and other statuses as optional later)
class SuperDec_Basic : public SuperDec_BaseClass <unsigned __int32>
{
	//Base::operator=(d);
	SuperDec_Basic operator=(double Value);
	SuperDec_Basic operator*(double Value);
	SuperDec_Basic operator*(float Value);
};

//Design to hold at least 7 decimal digits of storage plus Full signed Int32 range of whole values plus negative/positive status 
//Might need to override DecimalStatus into larger storage type to optimize decimal representation calculations
//Limit storage variables to less than 8 Bytes 
class HalfDec : public SuperDec_Basic
{

};

//Design to hopefully replace usage of double
//Limit storage variables to 8 Bytes (whole value representation costs 4 bytes of 8)
//Needs to hold at least 14 digits of decimal representation
class SuperDec_8Byte : public SuperDec_Basic
{

};

class SuperDec_21Dec : public SuperDec_Basic 
{
	//Holds data for Digits(3-21)
	//Value 1 = Digit # 3 has value of 1 and Digits #4-21 have values of zero
	unsigned __int64 ExtraDecimal00;
};

//Stores 9 Bytes worth of data to store with 100% accuracy +- Int32 with 11 Decimal places stored
//For reference TI-83 Plus Calculators values inside 9 Byte Variables with some inaccuracies) (Reference:http://merthsoft.com/linkguide/ti83+/vars.html)
//Traditionally Manually calculate to 14 significant digits?
class SuperDec_11Dec : public SuperDec_Basic
{
	//Holds data for Digits(3-21)
	//Value 1 = Digit # 3 has value of 1 and Digits #4-11 have values of zero
	unsigned __int32 ExtraDecimal00;
};

class SuperDec_15Dec : public SuperDec_Basic
{
	//Holds data for Digits(3-21)
	//Value 1 = Digit # 3 has value of 1 and Digits #4-11 have values of zero
	unsigned __int32 ExtraDecimal00;
};


//78 Perfect Digits Decimal,Holds 64Bt unsigned int worth of whole numbers, holds Negative/Positive Status, Holds optional Fractionals/things like pi, Total Storage space used = 42 Bytes Used
class SuperDec_64Bit78Dec : public  SuperDec_64BitBasic
{
	//Holds data for Digits(3-21)
	//Value 1 = Digit # 3 has value of 1 and Digits #4-21 have values of zero
	unsigned __int64 ExtraDecimal00;
	//Holds data for Digits(22-40)
	unsigned __int64 ExtraDecimal01;
	//Holds data for Digits(41-59)
	unsigned __int64 ExtraDecimal00;
	//Holds data for Digits(60-78)
	unsigned __int64 ExtraDecimal01;
};

//Store Global Functions for SuperDec here
struct DLL_API SuperDec_Globals
{
	//************************************
	// Method:    MaxWholeValue
	// FullName:  SuperDec_Globals::MaxWholeValue
	// Access:    public static
	// Returns:   unsigned __int64
	// Qualifier:
	// Parameter: unsigned __int8 NumBytes
	//************************************
	static unsigned __int64 MaxWholeValue(unsigned __int8 NumBytes)
	{
		return pow(256, NumBytes) - 1;
	}
};

#endif