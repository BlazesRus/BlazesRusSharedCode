#include "CustomDec_19Decimal.h"

#include <afx.h>

#if BlazesGlobalCode_FileStructureVersion == 0 || !defined (BlazesGlobalCode_FileStructureVersion)//(library style  layout)
#include "..\GlobalCode_VariableConversionFunctions\VariableConversionFunctions.h"
#else
#include "VariableConversionFunctions.h"
#endif

//void CustomDec_19Decimal::ConvertFromDecRep(signed __int64 Value)
//{
//	bool IsNegative = false;
//	if(Value < 0) { IsNegative = true; }
//	Value = abs(Value);
//#if !defined SuperDec_AngleDecimal && defined SuperDec_SignedIntStatus
//	IntValue = Value / 1000000000;
//	DecimalStatus = Value - IntValue;
//	if(IntValue == 0 && IsNegative)
//	{
//#	if defined SuperDec_sInt32
//		IntValue = -2147483648;
//#	elif defined SuperDec_sInt8
//		IntValue = -128;
//#	elif defined SuperDec_sInt16
//		IntValue = -32768;
//#	elif defined SuperDec_sInt64
//		IntValue = -9223372036854775808;
//#	endif
//	}
//	else { IntValue *= -1; }
//#elif !defined SuperDec_AngleDecimal
//	IntValue = Value/1000000000;
//	DecimalStatus = Value - IntValue;
//	if(IsNegative)
//	{
//		if(DecimalStatus==0)
//		{//Can't have negative signed int of zero
//#			if defined SuperDec_2Decimal
//			DecimalStatus=-100;//-100 = -IntValue.00
//#			elif defined SuperDec_4Decimal
//			DecimalStatus=-10000;//-10000 = -IntValue.0000
//#			else//9 Decimal
//			DecimalStatus=-1000000000;//-1,000,000,000 = -IntValue.000000000
//#			endif
//		}
//		else
//		{
//			DecimalStatus*=-1;
//		}
//		DecimalStatus*=-1;
//	}
//#else
//
//#endif
//}
//
//void CustomDec_19Decimal::ConvertFromDecRep(unsigned __int64 Value)
//{
//#if !defined SuperDec_AngleDecimal && defined SuperDec_SignedIntStatus
//	IntValue = Value / 1000000000;
//	DecimalStatus = Value - IntValue;
//#elif !defined SuperDec_AngleDecimal
//	IntValue = Value / 1000000000;
//	DecimalStatus = Value - IntValue;
//#else
//
//#endif
//}

int CustomDec_19Decimal::AsInt32()
{
		if(DecBoolStatus == 1) { return IntValue*-1; }
		else { return IntValue; }
}

signed _int64 CustomDec_19Decimal::AsSignedInt64()
{
	if(DecBoolStatus==1){return IntValue*-1;}
	else { return IntValue; }
}

double CustomDec_19Decimal::AsDouble()
{
//#if defined SuperDec_SignedIntStatus
//	double ConvertedValue = IntValue;
//	//-0.XX....
//#	if defined SuperDec_sInt32
//	if(IntValue == -2147483648)
//	{
//#	elif defined SuperDec_sInt8
//	if(IntValue==-128)
//	{
//#	elif defined SuperDec_sInt16
//	if(IntValue == -32768)
//	{
//#	elif defined SuperDec_sInt64
//	if(IntValue == -9223372036854775808)
//	{
//#endif
//#		if defined SuperDec_2Decimal
//		ConvertedValue = DecimalStatus*-.01;
//#		elif defined SuperDec_4Decimal
//		ConvertedValue = DecimalStatus*-.0001;
//#		else defined SuperDec_9Decimal
//		ConvertedValue = DecimalStatus*-.000000001;
//#		endif
//	}
//	else if(IntValue < 0)//Negative Decimal Value
//	{
//#	if defined SuperDec_2Decimal
//		ConvertedValue -= DecimalStatus*.01;
//#	elif defined SuperDec_4Decimal
//		ConvertedValue -= DecimalStatus*.0001;
//#	else defined SuperDec_9Decimal
//		ConvertedValue -= DecimalStatus*.000000001;
//#	endif
//	}
//	else
//	{
//#	if defined SuperDec_2Decimal
//		ConvertedValue += DecimalStatus*.01;
//#	elif defined SuperDec_4Decimal
//		ConvertedValue += DecimalStatus*.0001;
//#	else defined SuperDec_9Decimal
//		ConvertedValue += DecimalStatus*.000000001;
//#	endif
//	}
//	return ConvertedValue;
//#elif defined SuperDec_UnsignedBoolean
//
//#else//Unsigned Version (Stored data in Decimal Status)
//
//#endif
}

std::string CustomDec_19Decimal::AsString()
{
//#if defined SuperDec_SignedIntStatus
//#if defined SuperDec_Enable128BitUsage
//
//#else
//	std::string ConvertedValue = VariableConversionFunctions::IntToStringConversion(IntValue);
//#if !defined SuperDec_AngleDecimal
//	if(DecimalStatus != 0)
//	{
//		ConvertedValue += ".";
//		//0 = 0th Decimal Places; 11 = 1th Decimal Place
//		//(Max Decimal Storage of int field - 1) - NumberOfPlaces
//		__int8 SpacesToCreate;
//#if defined SuperDec_9Decimal
//		SpacesToCreate = 8 - VariableConversionFunctions::NumberOfPlaces(DecimalStatus);
//#elif defined SuperDec_4Decimal
//		SpacesToCreate = 3 - VariableConversionFunctions::NumberOfPlaces(DecimalStatus);
//#elif defined SuperDec_2Decimal
//		SpacesToCreate = 1 - VariableConversionFunctions::NumberOfPlaces(DecimalStatus);
//#else
//		SpacesToCreate = 2;
//#endif
//		for(__int8 SpacesCreated = 0; SpacesCreated < SpacesToCreate; SpacesCreated++)
//		{
//			ConvertedValue += "0";
//		}
//		ConvertedValue += VariableConversionFunctions::IntToStringConversion(DecimalStatus);
//	}
//#else
//	ConvertedValue += ".";
//	__int8 SpacesToCreate = 12 - VariableConversionFunctions::NumberOfPlaces(DecimalStatus);
//	for(__int8 SpacesCreated = 0; SpacesCreated < SpacesToCreate; SpacesCreated++)
//	{
//		ConvertedValue += "0";
//	}
//	ConvertedValue += VariableConversionFunctions::IntToStringConversion(DecimalStatus);
//	SpacesToCreate = 3 - VariableConversionFunctions::NumberOfPlaces(DecimalStatus01);
//	for(__int8 SpacesCreated = 0; SpacesCreated < SpacesToCreate; SpacesCreated++)
//	{
//		ConvertedValue += "0";
//	}
//	ConvertedValue += VariableConversionFunctions::IntToStringConversion(DecimalStatus01);
//#endif
//	return ConvertedValue;
//#endif
//#elif defined SuperDec_UnsignedBoolean
//
//#else//Unsigned Version (Stored data in Decimal Status)
//
//#endif
}

CustomDec_19Decimal CustomDec_19Decimal::operator+(std::string Value)
{
	if(Value == "PI")
	{
//#	if defined SuperDec_EnableSpecialDecimalStatus
//#	else
//#		if defined SuperDec_2Decimal
//		IntValue += 3;
//		DecimalStatus += 14;
//		if(DecimalStatus>99)
//		{
//			DecimalStatus -= 100;
//			++IntValue;
//		}
//#		endif
//#	endif
	}
	else
	{
	}
}

CustomDec_19Decimal CustomDec_19Decimal::operator+(double Value)
{
	int WholeHalf = floor(Value);
	IntValue += WholeHalf;
	//double DecHalf;
	//signed __int64 DecimalRep = DecimalStatus;
	//if(Value < 0)
	//{
	//	DecHalf = abs(Value + WholeHalf);
	//	if(DecHalf != 0)
	//	{
	//		DecimalRep += DecHalf * 10000000000000000000;
	//	}
	//}
	//else
	//{
	//	DecHalf = Value - WholeHalf;
	//	if(DecHalf != 0)
	//	{
	//		DecimalRep -= DecHalf * 10000000000000000000;
	//	}
	//}
	//if(DecimalRep < 0)
	//{
	//}
	//else
	//{
	//}
}

CustomDec_19Decimal CustomDec_19Decimal::operator=(double Value)
{
	int WholeHalf = floor(Value);
//	double DecHalf;
//	if(Value < 0)
//	{
//		DecHalf = abs(Value + WholeHalf);
//		if(DecHalf == 0)
//		{
//
//		}
//		else
//		{
//		}
//	}
//	else
//	{
//		DecHalf = Value - WholeHalf;
//		if(DecHalf == 0)
//		{
//
//		}
//		else
//		{
//		}
//	}
}

CustomDec_19Decimal CustomDec_19Decimal::operator^(unsigned int Value)
{
	unsigned __int32 TempValue = IntValue;
	if(Value == 0)
	{
		IntValue = 1;
		DecimalStatus = 0;
	}
	else if(Value < 0)
	{
		if(DecimalStatus == 0)
		{
			bool NegativeStatus=0;
			if(DecBoolStatus==1){NegativeStatus=1;}
			for(unsigned __int8 PowerIndex = 0; PowerIndex > Value; --PowerIndex)
			{
				TempValue /= IntValue;
				if(DecBoolStatus==1){NegativeStatus = !NegativeStatus;}
			}
			IntValue = TempValue;
			if(NegativeStatus){DecimalStatus =1;}
			else{DecimalStatus = 0;}
		}
		else
		{//Write code for Decimal to power of later
		}
	}
	else
	{
		if(DecimalStatus == 0)
		{
			bool NegativeStatus = DecBoolStatus;
			for(unsigned __int8 PowerIndex = 0; PowerIndex < Value; ++PowerIndex)
			{
				TempValue *= IntValue;
				if(DecBoolStatus==1){NegativeStatus = !NegativeStatus;}
			}
			IntValue = TempValue;
			if(NegativeStatus){DecimalStatus =1;}
			else{DecimalStatus = 0;}
		}
		else
		{//Write code for Decimal to power of later
		}
	}
}

//unsigned __int64 CustomDec_19Decimal::DecAsUnsignedInt()
//{
//	//Fit inside X,XXX,XXX,XXX,XXX,XXX,XXX,XXX
//	unsigned __int64 DecRep;
//	//Negative Zero
//#	if defined SuperDec_sInt32
//	if(IntValue == -2147483648)
//	{
//#	elif defined SuperDec_sInt8
//	if(IntValue == -128)
//	{
//#	elif defined SuperDec_sInt16
//	if(IntValue == -32768)
//	{
//#	elif defined SuperDec_sInt64
//	if(IntValue == -9223372036854775808)
//	{
//#	endif
//#		if defined SuperDec_SignedIntStatus || defined SuperDec_UnsignedBoolean
//#			if defined SuperDec_AngleDecimal
//		DecRep = DecimalStatus * 100 + DecimalStatus01;
//#			else
//		DecRep = DecimalStatus;
//#			endif
//#		else//Unsigned Version (Stored data in Decimal Status)
//#			if defined SuperDec_AngleDecimal
//		DecRep = DecimalStatus * 100 + abs(DecimalStatus01);
//#			else
//		DecRep = abs(DecimalStatus);
//#			endif
//#		endif
//	}
//	else
//	{
//#		if defined SuperDec_SignedIntStatus || defined SuperDec_UnsignedBoolean
//#			if defined SuperDec_9Decimal
//		DecRep = abs(IntValue) * 1000000000 + DecimalStatus;
//#			elif defined SuperDec_AngleDecimal
//		DecRep = abs(IntValue) * 1000000 + DecimalStatus * 100 + DecimalStatus01;
//#			elif defined SuperDec_4Decimal
//		DecRep = abs(IntValue) * 10000 + DecimalStatus;
//#			elif defined SuperDec_2Decimal
//		DecRep = abs(IntValue) * 100 + DecimalStatus;
//#			endif
//#		else//Unsigned Version (Stored data in Decimal Status)
//#			if defined SuperDec_9Decimal
//		DecRep = IntValue * 1000000000 + abs(DecimalStatus);
//#			elif defined SuperDec_AngleDecimal
//		DecRep = IntValue * 1000000 + abs(DecimalStatus) * 100 + DecimalStatus01;
//#			elif defined SuperDec_4Decimal
//		DecRep = IntValue * 10000 + abs(DecimalStatus);
//#			elif defined SuperDec_2Decimal
//		DecRep = IntValue * 100 + abs(DecimalStatus);
//#			endif
//#		endif
//	}
//	return DecRep;
//}

CustomDec_19Decimal CustomDec_19Decimal::operator*(double Value)
{
	if(Value == 0)
	{
		IntValue = 0;
		DecimalStatus = 0;
	}
	else if(Value == 1.0) {}
	else if(Value == -1.0)
	{
		if(DecimalStatus == 0 && IntValue == 0) {}
		else if(DecBoolStatus == 1)
		{
			DecBoolStatus = 0;
		}
		else if(DecBoolStatus == 0)
		{
			DecBoolStatus = 1;
		}
#		if defined SuperDec_EnableSpecialDecimalStatus
		else
		{
		}
#		endif
	}
	else
	{
		bool ResultIsNegative = false;
		if(Value < 0)
		{
			if(DecBoolStatus == 0)
			{
				ResultIsNegative = true;
			}
		}
		else
		{
			if(DecBoolStatus == 1)
			{
				ResultIsNegative = true;
			}
		}
		//unsigned __int64 DecRep = DecAsUnsignedInt();
		//DecRep *= Value;
		//ConvertFromDecRep(DecRep);
		if(ResultIsNegative)
		{
			DecBoolStatus = 1;
		}
		else
		{
			DecBoolStatus = 0;
		}
	}
}

CustomDec_19Decimal CustomDec_19Decimal::operator/(double Value)
{
	if(Value == 0)
	{
#		if defined SuperDec_EnableSpecialDecimalStatus

#		else
		IntValue = 0;
		DecimalStatus = 0;
#		endif
	}
	else if(Value == 1.0) {}
	else if(Value == -1.0)
	{
		if(DecimalStatus == 0 && IntValue == 0) {}
		else if(DecBoolStatus == 1)
		{
			DecBoolStatus = 0;
		}
		else if(DecBoolStatus == 0)
		{
			DecBoolStatus = 1;
		}
#		if defined SuperDec_EnableSpecialDecimalStatus
		else
		{
		}
#		endif
	}
	else
	{
		bool ResultIsNegative = false;
		if(Value < 0)
		{
			if(DecBoolStatus == 0)
			{
				ResultIsNegative = true;
			}
		}
		else
		{
			if(DecBoolStatus == 1)
			{
				ResultIsNegative = true;
			}
		}
		//unsigned __int64 DecRep = DecAsUnsignedInt();
		//DecRep /= Value;
		//ConvertFromDecRep(DecRep);
		if(ResultIsNegative)
		{
			DecBoolStatus = 1;
		}
		else
		{
			DecBoolStatus = 0;
		}
	}
}

CustomDec_19Decimal CustomDec_19Decimal::operator=(std::string Value)
{
	if(Value == "PI")
	{
		//Pi = ~355/113(From http://www.wired.com/2011/03/what-is-the-best-fractional-representation-of-pi/  && https://www.math.hmc.edu/funfacts/ffiles/10004.5.shtml) (Accuracy of -0.00000026676418906242231236893288649634 according to http://qin.laya.com/tech_projects_approxpi.html)
		//Pi = 2646693125139304345/842468587426513207 with Accuracy of 0.00000000000000000000000000000000000001 according to http://qin.laya.com/tech_projects_approxpi.html (37 decimal places of accuracy)
		// when dividing pi by integer store 2646693125139304345 inside signed/unsigned int 64
		//Pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100
//#	if defined SuperDec_EnableSpecialDecimalStatus
//		IntValue = 3;
//#	else
		IntValue = 3;
		DecimalStatus = 1415926535897932385;
//#	endif
	}
	else
	{
		bool IsNegative=false;
		_int8 StringSize = Value.GetSize();
		if(Value.at(0)='-'){IsNegative=true;}
		_int8 CurrentBlockCount = 0;
		unsigned _int64 DecimalValue = 0;
		unsigned _int64 CurrentBlock = 0;
		bool DecimalStored = false;
		char CurChar;
		for(_int8 Index=StringSize-1;Index>=0;++Index)
		{
			CurChar = Value.at(Index);
			if(CurChar=='-'){}
			else if(CurChar=='.')
			{
				if(DecimalStored==false)
				{
					if(CurrentBlockCount==19)
					{
						DecimalValue = CurrentBlock;
					}
					else(CurrentBlockCount<19)
					{
					
					}
					else//Larger block of data then can store
					{
						//Likely to crash from overflow for before reaching this for SuperDec_ExtraDec64_19Decimal (Might create overflow exception alternative block that cuts of the extra data)
					}
					CurrentBlockCount = 0;
					DecimalStored = true;
				}
			}
		}
	}
}