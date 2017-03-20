/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
using System;

namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
	public class SuperDecGlobalCode
	{
		// SuperDec generic reused code section
		public static dynamic ConditionalReturn(bool Condition, dynamic X, dynamic Y)
		{
			if (Condition)
			{
				return X;
			}
			else
			{
				return Y;
			}
		}


		//End of SuperDec generic reused code section
		//Trigonometrical method section
		public static double RadianToAngleAsDouble(dynamic Value)
		{
			double ConvertedValue = (double)Value;

			return 0.0;
		}
		public static double AngleToRadianAsFloat(dynamic Value)
		{
			double ConvertedValue = (double)Value;

			return 0.0;
		}
		public static double SinFromAngleAsDouble(dynamic Value)
		{
			double ConvertedValue = (double)Value;

			return 0.0;
		}
		public static double ConFromAngleAsDouble(dynamic Value)
		{
			double ConvertedValue = (double)Value;

			return 0.0;
		}
		public static double TransFromAngleAsDouble(dynamic Value)
		{
			double ConvertedValue = (double)Value;

			return 0.0;
		}
		//end of Trigonometrical method section	
	}
	public struct SuperDecBase
	{

		//0 = Positive;1=Negative;Other states at higher then 1
		//public byte DecBoolStatus;
		
		//public bool IsInfinity()
		//{
		//	//Negative Infinity
		//	if (DecBoolStatus == 255)
		//	{ return true; }
		//	//Positive Infinity
		//	else if (DecBoolStatus == 254)
		//	{ return true; }
		//	else { return false; }
		//}
		
		//public bool IsNull()
		//{
		//	if (DecBoolStatus==202) { return true; }
		//	else { return false; }
		//}

		
		//public byte GetBoolStatus()
		//{
		//	return DecBoolStatus;
		//}
		
		//public void SwapNegativeStatus()
		//{
		//	if (DecBoolStatus == 1) { DecBoolStatus = 0; }
		//	else { DecBoolStatus = 1; }
		//}
		
		public static dynamic ConditionalReturn(bool Condition, dynamic X, dynamic Y)
		{
			return CSharpGlobalCode.GlobalCode_ExperimentalCode.SuperDecGlobalCode.ConditionalReturn(Condition, X, Y);
		}
		
		public dynamic DynamicConversion()
		{
			return this;
		}
	}
}