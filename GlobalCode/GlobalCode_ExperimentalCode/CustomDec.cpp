#include "CustomDec.h"

#if !defined BlazesGlobalCode_CSharpCode

#if BlazesGlobalCode_FileStructureVersion == 0 || !defined (BlazesGlobalCode_FileStructureVersion)//(library style  layout)
#include "..\GlobalCode_VariableConversionFunctions\VariableConversionFunctions.h"
#else
#include "VariableConversionFunctions.h"
#endif

signed __int64 CustomDec::DecAsSignedInt()
{
#if defined SuperDec_SignedIntStatus
#	if defined SuperDec_9Decimal
	if(IntValue < 0)
	{
		return IntValue * 1000000000 - DecimalStatus;
	}
	else
	{
		return IntValue * 1000000000 + DecimalStatus;
	}
#	elif defined SuperDec_AngleDecimal
	if(IntValue<0)
	{
		return IntValue*1000000-DecimalStatus*100-DecimalStatus01;
	}
	else
	{
		return IntValue * 1000000 + DecimalStatus*100+DecimalStatus01;
	}
#	elif defined SuperDec_4Decimal
	if(IntValue<0)
	{
		return IntValue*10000-DecimalStatus;
	}
	else
	{
		return IntValue*10000+DecimalStatus;
	}
#	elif defined SuperDec_2Decimal
	if(IntValue<0)
	{
		return IntValue*100-DecimalStatus;
	}
	else
	{
		return IntValue*100+DecimalStatus;
	}
#	endif
#elif defined SuperDec_UnsignedBoolean
	//DecBoolStatus
#if SuperDec_9Decimal
	if(DecimalStatus==1)
	{
		return (IntValue*1000000000+DecimalStatus)*-1;
	}
	else
	{
		return IntValue*1000000000+DecimalStatus;
	}
#endif
#else//Unsigned Version (Stored data in Decimal Status)

#endif
	return 0;
}

void CustomDec::ConvertFromDecRep(signed __int64 Value)
{
	bool IsNegative = false;
	if(Value < 0) { IsNegative = true; }
	Value = abs(Value);
#if !defined SuperDec_AngleDecimal && defined SuperDec_SignedIntStatus
	IntValue = Value / 1000000000;
	DecimalStatus = Value - IntValue;
	if(IntValue == 0 && IsNegative)
	{
#	if defined SuperDec_sInt32
		IntValue = -2147483648;
#	elif defined SuperDec_sInt8
		IntValue = -128;
#	elif defined SuperDec_sInt16
		IntValue = -32768;
#	elif defined SuperDec_sInt64
		IntValue = -9223372036854775808;
#	endif
	}
	else { IntValue *= -1; }
#elif !defined SuperDec_AngleDecimal
	IntValue = Value/1000000000;
	DecimalStatus = Value - IntValue;
	if(IsNegative)
	{
		if(DecimalStatus==0)
		{//Can't have negative signed int of zero
#			if defined SuperDec_2Decimal
			DecimalStatus=-100;//-100 = -IntValue.00
#			elif defined SuperDec_4Decimal
			DecimalStatus=-10000;//-10000 = -IntValue.0000
#			else//9 Decimal
			DecimalStatus=-1000000000;//-1,000,000,000 = -IntValue.000000000
#			endif
		}
		else
		{
			DecimalStatus*=-1;
		}
		DecimalStatus*=-1;
	}
#else

#endif
}

void CustomDec::ConvertFromDecRep(unsigned __int64 Value)
{
#if !defined SuperDec_AngleDecimal && defined SuperDec_SignedIntStatus
	IntValue = Value / 1000000000;
	DecimalStatus = Value - IntValue;
#elif !defined SuperDec_AngleDecimal
	IntValue = Value / 1000000000;
	DecimalStatus = Value - IntValue;
#else

#endif
}

int CustomDec::AsInt32()
{
#if defined SuperDec_SignedIntStatus
	return IntValue;
#elif defined SuperDec_UnsignedBoolean
	if(DecBoolStatus==1){return IntValue*-1;}
	else { return IntValue; }
#else//Unsigned Version (Stored data in Decimal Status)

#endif
}

signed _int64 CustomDec::AsSignedInt64()
{
#if defined SuperDec_SignedIntStatus
#	if defined SuperDec_sInt32
	if(IntValue == -2147483648)
	{
#	elif defined SuperDec_sInt8
	if(IntValue==-128)
	{
#	elif defined SuperDec_sInt16
	if(IntValue == -32768)
	{
#	elif defined SuperDec_sInt64
	if(IntValue == -9223372036854775808)
	{
#endif
		return 0;
	}
	else
	{
		return IntValue;
	}
#elif defined SuperDec_UnsignedBoolean
	if(DecBoolStatus==1){return IntValue*-1;}
	else { return IntValue; }
#else//Unsigned Version (Stored data in Decimal Status)

#endif
}

double CustomDec::AsDouble()
{
#if defined SuperDec_SignedIntStatus
	double ConvertedValue = IntValue;
	//-0.XX....
#	if defined SuperDec_sInt32
	if(IntValue == -2147483648)
	{
#	elif defined SuperDec_sInt8
	if(IntValue==-128)
	{
#	elif defined SuperDec_sInt16
	if(IntValue == -32768)
	{
#	elif defined SuperDec_sInt64
	if(IntValue == -9223372036854775808)
	{
#endif
#		if defined SuperDec_2Decimal
		ConvertedValue = DecimalStatus*-.01;
#		elif defined SuperDec_4Decimal
		ConvertedValue = DecimalStatus*-.0001;
#		else defined SuperDec_9Decimal
		ConvertedValue = DecimalStatus*-.000000001;
#		endif
	}
	else if(IntValue < 0)//Negative Decimal Value
	{
#	if defined SuperDec_2Decimal
		ConvertedValue -= DecimalStatus*.01;
#	elif defined SuperDec_4Decimal
		ConvertedValue -= DecimalStatus*.0001;
#	else defined SuperDec_9Decimal
		ConvertedValue -= DecimalStatus*.000000001;
#	endif
	}
	else
	{
#	if defined SuperDec_2Decimal
		ConvertedValue += DecimalStatus*.01;
#	elif defined SuperDec_4Decimal
		ConvertedValue += DecimalStatus*.0001;
#	else defined SuperDec_9Decimal
		ConvertedValue += DecimalStatus*.000000001;
#	endif
	}
	return ConvertedValue;
#elif defined SuperDec_UnsignedBoolean

#else//Unsigned Version (Stored data in Decimal Status)

#endif
}

std::string CustomDec::AsString()
{
#if defined SuperDec_SignedIntStatus
#if defined SuperDec_Enable128BitUsage

#else
	std::string ConvertedValue = VariableConversionFunctions::IntToStringConversion(IntValue);
#if !defined SuperDec_AngleDecimal
	if(DecimalStatus != 0)
	{
		ConvertedValue += ".";
		//0 = 0th Decimal Places; 11 = 1th Decimal Place
		//(Max Decimal Storage of int field - 1) - NumberOfPlaces
		__int8 SpacesToCreate;
#if defined SuperDec_9Decimal
		SpacesToCreate = 8 - VariableConversionFunctions::NumberOfPlaces(DecimalStatus);
#elif defined SuperDec_4Decimal
		SpacesToCreate = 3 - VariableConversionFunctions::NumberOfPlaces(DecimalStatus);
#elif defined SuperDec_2Decimal
		SpacesToCreate = 1 - VariableConversionFunctions::NumberOfPlaces(DecimalStatus);
#else
		SpacesToCreate = 2;
#endif
		for(__int8 SpacesCreated = 0; SpacesCreated < SpacesToCreate; SpacesCreated++)
		{
			ConvertedValue += "0";
		}
		ConvertedValue += VariableConversionFunctions::IntToStringConversion(DecimalStatus);
	}
#else
	ConvertedValue += ".";
	__int8 SpacesToCreate = 12 - VariableConversionFunctions::NumberOfPlaces(DecimalStatus);
	for(__int8 SpacesCreated = 0; SpacesCreated < SpacesToCreate; SpacesCreated++)
	{
		ConvertedValue += "0";
	}
	ConvertedValue += VariableConversionFunctions::IntToStringConversion(DecimalStatus);
	SpacesToCreate = 3 - VariableConversionFunctions::NumberOfPlaces(DecimalStatus01);
	for(__int8 SpacesCreated = 0; SpacesCreated < SpacesToCreate; SpacesCreated++)
	{
		ConvertedValue += "0";
	}
	ConvertedValue += VariableConversionFunctions::IntToStringConversion(DecimalStatus01);
#endif
	return ConvertedValue;
#endif
#elif defined SuperDec_UnsignedBoolean

#else//Unsigned Version (Stored data in Decimal Status)

#endif
}

CustomDec CustomDec::operator+(std::string Value)
{
	if(Value == "PI")
	{
#	if defined SuperDec_EnableSpecialDecimalStatus
#	else
#		if defined SuperDec_2Decimal
		IntValue += 3;
		DecimalStatus += 14;
		if(DecimalStatus>99)
		{
			DecimalStatus -= 100;
			++IntValue;
		}
#		endif
#	endif
	}
	else
	{
	}
}

CustomDec CustomDec::operator+(double Value)
{
	int WholeHalf = floor(Value);
	IntValue += WholeHalf;
	double DecHalf;
#	if defined SuperDec_AngleDecimal
	signed __int64 DecimalRep = DecimalStatus * 10000 + DecimalStatus01;
#	else
	signed __int64 DecimalRep = DecimalStatus;
#	endif
	if(Value < 0)
	{
		DecHalf = abs(Value + WholeHalf);
		if(DecHalf != 0)
		{
#		if defined SuperDec_9Decimal
			DecimalRep += DecHalf * 1000000000;
#		elif SuperDec_4Decimal
			DecimalRep += DecHalf * 10000;
#		elif SuperDec_2Decimal
			DecimalRep += DecHalf * 100;
#		endif
		}
	}
	else
	{
		DecHalf = Value - WholeHalf;
		if(DecHalf != 0)
		{
#		if defined SuperDec_9Decimal
			DecimalRep -= DecHalf * 1000000000;
#		elif SuperDec_4Decimal
			DecimalRep -= DecHalf * 10000;
#		elif SuperDec_2Decimal
			DecimalRep -= DecHalf * 100;
#		endif
		}
	}
	if(DecimalRep < 0)
	{
#	if defined SuperDec_AngleDecimal

#	endif
	}
	else
	{
#	if defined SuperDec_AngleDecimal

#	endif
	}
}

CustomDec CustomDec::operator=(double Value)
{
	int WholeHalf = floor(Value);
	double DecHalf;
#if !defined SuperDec_RequiresMoreThan64BitCalculation
	if(Value < 0)
	{
		DecHalf = abs(Value + WholeHalf);
		if(DecHalf == 0)
		{
#		if defined SuperDec_SignedIntStatus
#		elif defined SuperDec_UnsignedBoolean
#		else
#		endif
		}
		else
		{
		}
	}
	else
	{
		DecHalf = Value - WholeHalf;
		if(DecHalf == 0)
		{
#		if defined SuperDec_SignedIntStatus
#		elif defined SuperDec_UnsignedBoolean
#		else
#		endif
		}
		else
		{
		}
	}
#else
#endif
}

CustomDec CustomDec::operator^(unsigned int Value)
{
#	ifdef SuperDec_sInt64
	signed __int64 TempValue = IntValue;
#	elif defined (SuperDec_sInt16)
	signed __int16 TempValue = IntValue;
#	elif defined (SuperDec_sInt8)
	signed __int8 TempValue = IntValue;
#	elif defined (SuperDec_Int64)
	unsigned __int16 TempValue = IntValue;
#	elif defined (SuperDec_Int32)
	unsigned __int8 TempValue = IntValue;
#	elif defined (SuperDec_Int16)
	unsigned __int16 TempValue = IntValue;
#	elif defined (SuperDec_Int8)
	unsigned __int8 TempValue = IntValue;
#	else//Default to SuperDec_sInt32
	signed __int32 TempValue = IntValue;
#	endif
	if(Value == 0)
	{
		IntValue = 1;
		DecimalStatus = 0;
#		if defined SuperDec_AngleDecimal
		DecimalStatus01 = 0;
#		endif
	}
#	if !defined SuperDec_AngleDecimal
	else if(Value < 0)
	{
		if(DecimalStatus == 0)
		{
			for(unsigned __int8 PowerIndex = 0; PowerIndex > Value; --PowerIndex)
			{
				TempValue /= IntValue;
			}
			IntValue = TempValue;
		}
		else
		{//Write code for Decimal to power of later
		}
	}
	else
	{
		if(DecimalStatus == 0)
		{
			for(unsigned __int8 PowerIndex = 0; PowerIndex < Value; ++PowerIndex)
			{
				TempValue *= IntValue;
			}
			IntValue = TempValue;
		}
		else
		{//Write code for Decimal to power of later
		}
	}
#	else
#	endif
}

unsigned __int64 CustomDec::DecAsUnsignedInt()
{
	//Fit inside X,XXX,XXX,XXX,XXX,XXX,XXX,XXX
	unsigned __int64 DecRep;
	//Negative Zero
#	if defined SuperDec_sInt32
	if(IntValue == -2147483648)
	{
#	elif defined SuperDec_sInt8
	if(IntValue == -128)
	{
#	elif defined SuperDec_sInt16
	if(IntValue == -32768)
	{
#	elif defined SuperDec_sInt64
	if(IntValue == -9223372036854775808)
	{
#	endif
#		if defined SuperDec_SignedIntStatus || defined SuperDec_UnsignedBoolean
#			if defined SuperDec_AngleDecimal
		DecRep = DecimalStatus * 100 + DecimalStatus01;
#			else
		DecRep = DecimalStatus;
#			endif
#		else//Unsigned Version (Stored data in Decimal Status)
#			if defined SuperDec_AngleDecimal
		DecRep = DecimalStatus * 100 + abs(DecimalStatus01);
#			else
		DecRep = abs(DecimalStatus);
#			endif
#		endif
	}
	else
	{
#		if defined SuperDec_SignedIntStatus || defined SuperDec_UnsignedBoolean
#			if defined SuperDec_9Decimal
		DecRep = abs(IntValue) * 1000000000 + DecimalStatus;
#			elif defined SuperDec_AngleDecimal
		DecRep = abs(IntValue) * 1000000 + DecimalStatus * 100 + DecimalStatus01;
#			elif defined SuperDec_4Decimal
		DecRep = abs(IntValue) * 10000 + DecimalStatus;
#			elif defined SuperDec_2Decimal
		DecRep = abs(IntValue) * 100 + DecimalStatus;
#			endif
#		else//Unsigned Version (Stored data in Decimal Status)
#			if defined SuperDec_9Decimal
		DecRep = IntValue * 1000000000 + abs(DecimalStatus);
#			elif defined SuperDec_AngleDecimal
		DecRep = IntValue * 1000000 + abs(DecimalStatus) * 100 + DecimalStatus01;
#			elif defined SuperDec_4Decimal
		DecRep = IntValue * 10000 + abs(DecimalStatus);
#			elif defined SuperDec_2Decimal
		DecRep = IntValue * 100 + abs(DecimalStatus);
#			endif
#		endif
	}
	return DecRep;
}

CustomDec CustomDec::operator*(double Value)
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
#	if defined SuperDec_SignedIntStatus
#		if defined SuperDec_sInt32
		else if(IntValue == -2147483648)
		{
#		elif defined SuperDec_sInt8
		else if(IntValue == -128)
		{
#		elif defined SuperDec_sInt16
		else if(IntValue == -32768)
		{
#		elif defined SuperDec_sInt64
		else if(IntValue == -9223372036854775808)
		{
#		endif
			IntValue = 0;
		}
		else if(IntValue == 0)
		{//Set to representation -Zero.XX.....
#		if defined SuperDec_sInt32
			IntValue = -2147483648;
#		elif defined SuperDec_sInt8
			IntValue = -128;
#		elif defined SuperDec_sInt16
			IntValue = -32768;
#		elif defined SuperDec_sInt64
			IntValue = -9223372036854775808;
#		endif
		}
		else
		{
			IntValue *= -1;
		}
#	elif defined SuperDec_UnsignedBoolean
		if(DecBoolStatus == 1)
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
#	else
		if(DecimalStatus == 0)
		{
			if(IntValue == 0) {}
			else
			{
#		if defined SuperDec_9Decimal
				DecimalStatus = -2147483648;
#		elif defined SuperDec_2Decimal
				DecimalStatus = -128;
#		elif defined SuperDec_4Decimal
				DecimalStatus = -32768;
#		elif defined SuperDec_18Decimal
				DecimalStatus = -9223372036854775808;
#		endif
			}
		}
#		if defined SuperDec_9Decimal
		else if(DecimalStatus == -2147483648)
		{
#		elif defined SuperDec_2Decimal
		else if(DecimalStatus == -128)
		{
#		elif defined SuperDec_4Decimal
		else if(DecimalStatus == -32768)
		{
#		elif defined SuperDec_18Decimal
		else if(DecimalStatus == -9223372036854775808)
		{
#		endif
			DecimalStatus = 0;
		}
		else
		{
			DecimalStatus *= -1;
		}
#	endif
	}
	else
	{
		bool ResultIsNegative = false;
		if(Value < 0)
		{
#		if defined SuperDec_UnsignedBoolean
			if(DecBoolStatus == 0)
			{
				ResultIsNegative = true;
			}
#		elif defined SuperDec_SignedIntStatus
			if(IntValue > 0)
			{
				ResultIsNegative = true;
			}
#		else
			if(DecimalStatus > 0)
			{
				ResultIsNegative = true;
			}
#		endif
		}
		else
		{
#		if defined SuperDec_UnsignedBoolean
			if(DecBoolStatus == 1)
			{
				ResultIsNegative = true;
			}
#		elif defined SuperDec_SignedIntStatus
			if(IntValue < 0)
			{
				ResultIsNegative = true;
			}
#		else
			if(DecimalStatus < 0)
			{
				ResultIsNegative = true;
			}
#		endif
		}
		unsigned __int64 DecRep = DecAsUnsignedInt();
#	if SuperDec_PreventTruncationToZero == 2
		//DecRep is multiplied by 10 to allow rounding up remaining value
		DecRep *= 10;
#	endif
		DecRep *= Value;
#	if SuperDec_PreventTruncationToZero == 2//Place code here for extra rounding up feature
#	endif
		ConvertFromDecRep(DecRep);
		if(ResultIsNegative)
		{
#		if defined SuperDec_UnsignedBoolean
			DecBoolStatus = 1;
#		elif defined SuperDec_SignedIntStatus
			if(IntValue == 0 && ResultIsNegative)
			{
#			if defined SuperDec_sInt32
				IntValue = -2147483648;
#			elif defined SuperDec_sInt8
				IntValue = -128;
#			elif defined SuperDec_sInt16
				IntValue = -32768;
#			elif defined SuperDec_sInt64
				IntValue = -9223372036854775808;
#			endif
			}
			else { IntValue *= -1; }
#		elif !defined SuperDec_AngleDecimal
			DecimalStatus *= -1;
#		endif
		}
		else
		{
#		if defined SuperDec_UnsignedBoolean
			DecBoolStatus = 0;
#		endif
		}
	}
}

CustomDec CustomDec::operator/(double Value)
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
#	if defined SuperDec_SignedIntStatus
#		if defined SuperDec_sInt32
		else if(IntValue == -2147483648)
		{
#		elif defined SuperDec_sInt8
		else if(IntValue == -128)
		{
#		elif defined SuperDec_sInt16
		else if(IntValue == -32768)
		{
#		elif defined SuperDec_sInt64
		else if(IntValue == -9223372036854775808)
		{
#		endif
			IntValue = 0;
		}
		else if(IntValue == 0)
		{//Set to representation -Zero.XX.....
#		if defined SuperDec_sInt32
			IntValue = -2147483648;
#		elif defined SuperDec_sInt8
			IntValue = -128;
#		elif defined SuperDec_sInt16
			IntValue = -32768;
#		elif defined SuperDec_sInt64
			IntValue = -9223372036854775808;
#		endif
		}
		else
		{
			IntValue *= -1;
		}
#	elif defined SuperDec_UnsignedBoolean
		if(DecBoolStatus == 1)
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
#	else
		if(DecimalStatus == 0)
		{
			if(IntValue == 0) {}
			else
			{
#		if defined SuperDec_9Decimal
				DecimalStatus = -2147483648;
#		elif defined SuperDec_2Decimal
				DecimalStatus = -128;
#		elif defined SuperDec_4Decimal
				DecimalStatus = -32768;
#		elif defined SuperDec_18Decimal
				DecimalStatus = -9223372036854775808;
#		endif
			}
		}
#		if defined SuperDec_9Decimal
		else if(DecimalStatus == -2147483648)
		{
#		elif defined SuperDec_2Decimal
		else if(DecimalStatus == -128)
		{
#		elif defined SuperDec_4Decimal
		else if(DecimalStatus == -32768)
		{
#		elif defined SuperDec_18Decimal
		else if(DecimalStatus == -9223372036854775808)
		{
#		endif
			DecimalStatus = 0;
		}
		else
		{
			DecimalStatus *= -1;
		}
#	endif
	}
	else
	{
		bool ResultIsNegative = false;
		if(Value < 0)
		{
#		if defined SuperDec_UnsignedBoolean
			if(DecBoolStatus > 0)
			{
				ResultIsNegative = true;
			}
#		elif defined SuperDec_SignedIntStatus
			if(IntValue > 0)
			{
				ResultIsNegative = true;
			}
#		else
			if(DecimalStatus > 0)
			{
				ResultIsNegative = true;
			}
#		endif
		}
		else
		{
#		if defined SuperDec_UnsignedBoolean
			if(DecBoolStatus < 0)
			{
				ResultIsNegative = true;
			}
#		elif defined SuperDec_SignedIntStatus
			if(IntValue < 0)
			{
				ResultIsNegative = true;
			}
#		else
			if(DecimalStatus < 0)
			{
				ResultIsNegative = true;
			}
#		endif
		}
		unsigned __int64 DecRep = DecAsUnsignedInt();
#	if SuperDec_PreventTruncationToZero == 2
		//DecRep is multiplied by 10 to allow rounding up remaining value
		DecRep *= 10;
#	endif
		DecRep /= Value;
		ConvertFromDecRep(DecRep);
		if(ResultIsNegative)
		{
#		if defined SuperDec_UnsignedBoolean
			DecBoolStatus = 1;
#		elif defined SuperDec_SignedIntStatus
			if(IntValue == 0 && ResultIsNegative)
			{
#			if defined SuperDec_sInt32
				IntValue = -2147483648;
#			elif defined SuperDec_sInt8
				IntValue = -128;
#			elif defined SuperDec_sInt16
				IntValue = -32768;
#			elif defined SuperDec_sInt64
				IntValue = -9223372036854775808;
#			endif
			}
			else { IntValue *= -1; }
#		elif !defined SuperDec_AngleDecimal
			DecimalStatus *= -1;
#		endif
		}
		else
		{
#		if defined SuperDec_UnsignedBoolean
			DecBoolStatus = 0;
#		endif
		}
	}
}

CustomDec CustomDec::operator=(std::string Value)
{
	if(Value == "PI")
	{
		//Pi = ~355/113(From http://www.wired.com/2011/03/what-is-the-best-fractional-representation-of-pi/  && https://www.math.hmc.edu/funfacts/ffiles/10004.5.shtml) (Accuracy of -0.00000026676418906242231236893288649634 according to http://qin.laya.com/tech_projects_approxpi.html)
		//Pi = 2646693125139304345/842468587426513207 with Accuracy of 0.00000000000000000000000000000000000001 according to http://qin.laya.com/tech_projects_approxpi.html (37 decimal places of accuracy)
		// when dividing pi by integer store 2646693125139304345 inside signed/unsigned int 64
		//Pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100
#	if defined SuperDec_EnableSpecialDecimalStatus
#	else
		IntValue = 3;
#if defined SuperDec_2Decimal
		DecimalStatus = 14;
#elif defined SuperDec_4Decimal
		DecimalStatus = 1416;
#elif defifed SuperDec_9Decimal
		DecimalStatus = 141592654;
#endif
#	endif
	}
	else
	{

	}
}
#else//C# version of code here

#endif