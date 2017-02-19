#include "SuperDec_sInt32_19Dec_DoubleFloat.h"

#if BlazesGlobalCode_FileStructureVersion == 0 || !defined (BlazesGlobalCode_FileStructureVersion)//(library style  layout)
	#include "..\GlobalCode_VariableConversionFunctions\VariableConversionFunctions.h"
#else
	#include "VariableConversionFunctions.h"
#endif


//signed __int64 CustomDec::DecAsSignedInt()
//{
//	#if defined SuperDec_SignedIntStatus
//		#if defined SuperDec_9Decimal
//			if(IntValue<0)
//			{
//				return IntValue*1000000000-DecimalStatus;
//			}
//			else
//			{
//				return IntValue*1000000000+DecimalStatus;
//			}
//		#elif defined SuperDec_AngleDecimal
//			if(IntValue<0)
//			{
//				return IntValue*1000000-DecimalStatus*100-DecimalStatus01;
//			}
//			else
//			{
//				return IntValue * 1000000 + DecimalStatus*100+DecimalStatus01;
//			}
//		#elif defined SuperDec_4Decimal
//			if(IntValue<0)
//			{
//				return IntValue*10000-DecimalStatus;
//			}
//			else
//			{
//				return IntValue*10000+DecimalStatus;
//			}
//		#elif defined SuperDec_2Decimal
//			if(IntValue<0)
//			{
//				return IntValue*100-DecimalStatus;
//			}
//			else
//			{
//				return IntValue*100+DecimalStatus;
//			}
//		#endif
//	return 0;
//}
//
//void CustomDec::ConvertFromDecRep(signed __int64 Value)
//{
//	bool IsNegative=false;
//	if(Value<0){IsNegative=true;}
//	Value = abs(Value);
//#if !defined SuperDec_AngleDecimal && SuperDec_SignedIntStatus
//	IntValue = Value/1000000000;
//	DecimalStatus = Value - IntValue;
//	if(IsNegative){IntValue*=-1;}
//
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
//#endif
//}

int CustomDec::AsInt32()
{
	return IntValue;
}

double CustomDec::AsDouble()
{
	//Create code for this later
	//if(IntValue<0)//Negative Decimal Value
	//{

	//}
	//else
	//{

	//}
	return 0.0;
}

std::string CustomDec::AsString()
{
		std::string ConvertedValue = VariableConversionFunctions::IntToStringConversion(IntValue);
		if(DecimalStatus!=0)
		{
			ConvertedValue += ".";
			//0 = 0th Decimal Places; 11 = 1th Decimal Place
			//(Max Decimal Storage of int field - 1) - NumberOfPlaces
			__int8 SpacesToCreate = 18 - VariableConversionFunctions::NumberOfPlaces(DecimalStatus);
			for(__int8 SpacesCreated = 0; SpacesCreated < SpacesToCreate; SpacesCreated++)
			{
				ConvertedValue += "0";
			}
			ConvertedValue += VariableConversionFunctions::IntToStringConversion(DecimalStatus);
		}
		return ConvertedValue;
}

CustomDec CustomDec::operator+(std::string Value)
{
	if(Value=="PI")
	{

	}
	else
	{

	}
}

//CustomDec CustomDec::operator+(double Value)
//{
//	int WholeHalf = floor(Value);
//	double DecHalf;
//#if !defined SuperDec_RequiresMoreThan64BitCalculation
//#	if defined SuperDec_AngleDecimal && defined SuperDec_SignedIntStatus
//	signed __int64 DecimalRep = DecimalStatus * 10000 + DecimalStatus01;
//#	else
//	signed __int64 DecimalRep = DecimalStatus;
//#	endif
//	if(Value < 0)
//	{
//		DecHalf = abs(Value + WholeHalf);
//		if(DecHalf == 0)
//		{
//#		if defined SuperDec_SignedIntStatus
//#		elif defined SuperDec_UnsignedBoolean
//#		else
//#		endif
//		}
//		else
//		{
//
//		}
//	}
//	else
//	{
//		DecHalf = Value - WholeHalf;
//		if(DecHalf == 0)
//		{
//#		if defined SuperDec_SignedIntStatus
//#		elif defined SuperDec_UnsignedBoolean
//#		else
//#		endif
//		}
//		else
//		{
//
//		}
//	}
//#else
//#endif
//}

//CustomDec CustomDec::operator=(double Value)
//{
//	int WholeHalf = floor(Value);
//	double DecHalf;
//#if !defined SuperDec_RequiresMoreThan64BitCalculation
//	if(Value < 0)
//	{
//		DecHalf = abs(Value + WholeHalf);
//		if(DecHalf == 0)
//		{
//#		if defined SuperDec_SignedIntStatus
//#		elif defined SuperDec_UnsignedBoolean
//#		else
//#		endif
//		}
//		else
//		{
//
//		}
//	}
//	else
//	{
//		DecHalf = Value - WholeHalf;
//		if(DecHalf == 0)
//		{
//#		if defined SuperDec_SignedIntStatus
//#		elif defined SuperDec_UnsignedBoolean
//#		else
//#		endif
//		}
//		else
//		{
//
//		}
//	}
//#else
//#endif
//}

CustomDec CustomDec::operator^(unsigned int Value)
{
	signed __int32 TempValue = IntValue;
	if(Value == 0)
	{
		IntValue = 1;
		DecimalStatus = 0;
		TrailingDec = 0;
	}
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
}

//CustomDec CustomDec::operator*(double Value)
//{
//	signed __int64 DecRep = DecAsSignedInt();
//	DecRep *= Value;
//	ConvertFromDecRep(DecRep);
//}
//
//CustomDec CustomDec::operator/(double Value)
//{
//	signed __int64 DecRep = DecAsSignedInt();
//	DecRep /= Value;
//	ConvertFromDecRep(DecRep);
//}

//CustomDec CustomDec::operator=(std::string Value)
//{
//	if(Value == "PI")
//	{
//		//Pi = ~355/113(From http://www.wired.com/2011/03/what-is-the-best-fractional-representation-of-pi/  && https://www.math.hmc.edu/funfacts/ffiles/10004.5.shtml) (Accuracy of -0.00000026676418906242231236893288649634 according to http://qin.laya.com/tech_projects_approxpi.html)
//		//Pi = 2646693125139304345/842468587426513207 with Accuracy of 0.00000000000000000000000000000000000001 according to http://qin.laya.com/tech_projects_approxpi.html (37 decimal places of accuracy)
//		// when dividing pi by integer store 2646693125139304345 inside signed/unsigned int 64
//		//Pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100
//		IntValue = 3;
//
//	}
//	else
//	{
//
//	}
//}
