/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.MediumDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Globalization;
    using System.IO;
    using System.Windows;
    using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

    // Represents +- 4294967295.999999999 with 100% consistency of accuracy
    //(Aka SuperDec_Int16_4Decimal)
    public
#if (!BlazesGlobalCode_MediumDec_AsStruct)
    sealed
#endif
    partial
#if (!BlazesGlobalCode_MediumDec_AsStruct)
    class
#else
    struct
#endif
    MediumDec : IFormattable, INotifyPropertyChanged
    {
        /// <summary>
        /// PI value (3.141592654)
        /// </summary>
        /// <returns></returns>
        private static MediumDec PIValue()
        {
            return new MediumDec(3, 141592654);
        }
        /// <summary>
        /// PI value (about 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513)
        /// </summary>
        public static MediumDec PI = PIValue();

		/// <summary>
		///  (about 2.71828182845904523536028747135266249775724709369995)
		/// </summary>
		/// <returns></returns>
		private static MediumDec EValue()
		{
			return new MediumDec(2, 718281828);
		}
		/// <summary>
		/// Euler's number (2.7182818284590451)
		/// </summary>
		public static readonly MediumDec E = EValue();

		/// <summary>
		/// Value at one
		/// </summary>
		public static readonly MediumDec NegativeOne = NegativeOneValue();

		private static MediumDec NegativeOneValue() => new MediumDec(1, MediumDec.NegativeWholeNumber);

		/// <summary>
		/// Get Sin from Value of angle.
		/// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec SinFromAngle(MediumDec Value)
		{
			if (Value.DecimalStatus == MediumDec.NegativeWholeNumber)
			{
				Value.DecimalStatus = 0;
				Value.IntValue %= 360;
				Value.IntValue = (ushort)(360 - (int)Value.IntValue);
				if (Value.IntValue == 360) { Value.IntValue = 0; }
			}
			else if (Value.DecimalStatus < 0)
			{
				Value.DecimalStatus = NegativeWholeNumber + Value.DecimalStatus;
				++Value.IntValue;
				Value.IntValue %= 360;
				Value.IntValue = (ushort)(360 - (int)Value.IntValue);
				if (Value.IntValue == 360) { Value.IntValue = 0; }
			}
			else
			{
				Value %= 360;
			}
			if (Value == MediumDec.Zero) { return MediumDec.Zero; }
			else if (Value.IntValue == 30 && Value.DecimalStatus == 0)
			{
				return new MediumDec(0, 500000000);
			}
			else if (Value.IntValue == 90 && Value.DecimalStatus == 0)
			{
				return MediumDec.One;
			}
			else if (Value.IntValue == 180 && Value.DecimalStatus == 0)
			{
				return MediumDec.Zero;
			}
			else if (Value.IntValue == 270 && Value.DecimalStatus == 0)
			{
				return MediumDec.NegativeOne;
			}
			else
			{
				MediumDec NewValue = MediumDec.Zero;
				//Angle as Radian
				MediumDec Radius = MediumDec.PI * Value / 180;
				for (int i = 0; i < 7; ++i)
				{ // That's Taylor series!!
					NewValue += Pow(-1, i) * Pow(Radius, 2 * i + 1) / SuperDecGlobalCode.Fact(2 * i + 1);
				}
				return NewValue;
				//double Temp = Math.Sin(Math.PI * (double)Value / 180.0);//Converting from Angle to Radians (https://msdn.microsoft.com/en-us/library/system.math.cos(v=vs.110).aspx)
				//return new MediumDec(Temp);//Working Placeholder code for now until change later to other formula based code
			}
		}

		/// <summary>
		/// Get Cos() from Value of Angle
		/// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec CosFromAngle(MediumDec Value)
		{
			if (Value.DecimalStatus == MediumDec.NegativeWholeNumber)
			{
				Value.DecimalStatus = 0;
				Value.IntValue %= 360;
				Value.IntValue = (ushort)(360 - (int)Value.IntValue);
				if (Value.IntValue == 360) { Value.IntValue = 0; }
			}
			else if (Value.DecimalStatus < 0)
			{
				Value.DecimalStatus = NegativeWholeNumber + Value.DecimalStatus;
				++Value.IntValue;
				Value.IntValue %= 360;
				Value.IntValue = (ushort)(360 - (int)Value.IntValue);
				if (Value.IntValue == 360) { Value.IntValue = 0; }
			}
			else
			{
				Value %= 360;
			}
			if (Value == MediumDec.Zero) { return MediumDec.One; }
			else if (Value.IntValue == 90 && Value.DecimalStatus == 0)
			{
				return MediumDec.Zero;
			}
			else if (Value.IntValue == 180 && Value.DecimalStatus == 0)
			{
				return MediumDec.NegativeOne;
			}
			else if (Value.IntValue == 270 && Value.DecimalStatus == 0)
			{
				return MediumDec.Zero;
			}
			else
			{
				MediumDec NewValue = MediumDec.Zero;
				//Angle as Radian
				MediumDec Radius = MediumDec.PI * Value / 180;
				for (int i = 0; i < 7; ++i)
				{ // That's also Taylor series!!
					NewValue += Pow(-1, i) * Pow(Radius, 2 * i) / SuperDecGlobalCode.Fact(2 * i);
				}
				return NewValue;
				//double Temp = Math.Cos(Math.PI * (double)Value / 180.0);//Converting from Angle to Radians (https://msdn.microsoft.com/en-us/library/system.math.cos(v=vs.110).aspx)
				//return new MediumDec(Temp);//Working Placeholder code for now until change later to other formula based code
			}
		}

		/// <summary>
		/// Get Tan from Value in Radians
		/// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec Tan(MediumDec Value)
		{
			MediumDec SinValue = MediumDec.Zero;
			MediumDec CosValue = MediumDec.Zero;
			for (int i = 0; i < 7; ++i)
			{
				SinValue += Pow(-1, i) * Pow(Value, 2 * i + 1) / SuperDecGlobalCode.Fact(2 * i + 1);
			}
			for (int i = 0; i < 7; ++i)
			{
				CosValue += Pow(-1, i) * Pow(Value, 2 * i) / SuperDecGlobalCode.Fact(2 * i);
			}
			return SinValue / CosValue;
		}

		//Attempt to merge Sin and Cos loops together
		public static MediumDec MergedTan(MediumDec Value)
		{
			MediumDec Output = MediumDec.Zero;
			for (int i = 0; i < 7; ++i)
			{
				Output += (Pow(Value, 2 * i + 1) / SuperDecGlobalCode.Fact(2 * i + 1)) / (Pow(Value, 2 * i) / SuperDecGlobalCode.Fact(2 * i));
			}
			return Output;
		}

		/// <summary>
		/// Get Tangent from Value in Degrees (SlopeInPercent:http://communityviz.city-explained.com/communityviz/s360webhelp4-2/formulas/function_library/atan_function.htm)
		/// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec TanFromAngle(MediumDec Value)
		{
			if (Value.DecimalStatus == MediumDec.NegativeWholeNumber)
			{
				Value.DecimalStatus = 0;
				Value.IntValue %= 360;
				Value.IntValue = (ushort)(360 - (int)Value.IntValue);
				if (Value.IntValue == 360) { Value.IntValue = 0; }
			}
			else if (Value.DecimalStatus < 0)
			{
				Value.DecimalStatus = NegativeWholeNumber + Value.DecimalStatus;
				++Value.IntValue;
				Value.IntValue %= 360;
				Value.IntValue = (ushort)(360 - (int)Value.IntValue);
				if (Value.IntValue == 360) { Value.IntValue = 0; }
			}
			else
			{
				Value %= 360;
			}
			if (Value == MediumDec.Zero) { return MediumDec.Zero; }
			else if (Value.IntValue == 90 && Value.DecimalStatus == 0)
			{
				return MediumDec.NaN;//Positive Infinity on left of;Negative Infinity on right
			}
			else if (Value.IntValue == 180 && Value.DecimalStatus == 0)
			{
				return MediumDec.Zero;
			}
			else if (Value.IntValue == 270 && Value.DecimalStatus == 0)
			{
				return MediumDec.NaN;//Positive Infinity on left of;Negative Infinity on right
			}
			else
			{
				//int QuadrantNum = Value.IntValue < 90? 1: (Value < 180? 2 : (Value < 270 ? 3: 4));
				//double Temp = Math.Tan(Math.PI * (double)Value / 180.0);//Converting from Angle to Radians (https://msdn.microsoft.com/en-us/library/system.math.cos(v=vs.110).aspx)
				//            return new MediumDec(Temp);//Working Placeholder code for now until change later to other formula based code
				return Tan(MediumDec.PI * Value / 180);
			}
		}

		/// <summary>
		/// Arc Sine (http://communityviz.city-explained.com/communityviz/s360webhelp4-2/formulas/function_library/asin_function.htm)
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec ASin(MediumDec Value)
		{
			double Temp = Math.Asin((double)Value);
			return new MediumDec(Temp);//Working Placeholder code for now until change later to other formula based code 
		}

		/// <summary>
		/// Arc Sine from Value in Degrees
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec ASinFromDegrees(MediumDec Value)
		{
			return ASin(MediumDec.PI * Value / 180);
		}

		/// <summary>
		/// Gets Inverse Tangent from Value of Angle
		/// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec ATanFromDegrees(MediumDec Value)
		{
			return ATan(MediumDec.PI * Value / 180);
		}

		/// <summary>
		/// Gets Inverse Tangent from Value in Radians
		/// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec ATan(MediumDec Value)
		{
			//double Temp = Math.Atan((double)Value);
			//return new MediumDec(Temp);//Working Placeholder code for now until change later to other formula based code 
			MediumDec SinValue = MediumDec.Zero;
			MediumDec CosValue = MediumDec.Zero;
			//Angle as Radian
			for (int i = 0; i < 7; ++i)
			{ // That's Taylor series!!
				SinValue += Pow(-1, i) * Pow(Value, 2 * i + 1) / SuperDecGlobalCode.Fact(2 * i + 1);
			}
			for (int i = 0; i < 7; ++i)
			{ // That's also Taylor series!!
				CosValue += Pow(-1, i) * Pow(Value, 2 * i) / SuperDecGlobalCode.Fact(2 * i);
			}
			return CosValue / SinValue;
		}

		/// <summary>
		/// Get the slope in degrees from percentage of slope (Based on formula from http://communityviz.city-explained.com/communityviz/s360webhelp4-2/formulas/function_library/atan_function.htm)
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec SlopeInDegrees(MediumDec Value) => ATan(Value) * 180 / PI;

		/// <summary>
		/// Arc Cosine(http://communityviz.city-explained.com/communityviz/s360webhelp4-2/formulas/function_library/acos_function.htm)
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec ACos(MediumDec Value)
		{
			double Temp = Math.Acos((double)Value);
			return new MediumDec(Temp);//Working Placeholder code for now until change later to other formula based code
		}


		/// <summary>
		/// Arc Sine from Value in Degrees
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec ACosFromDegrees(MediumDec Value)
		{
			return ACos(MediumDec.PI * Value / 180);
		}

		/// <summary>
		/// atan2 calculation with self normalization
		/// Application: Used when one wants to compute the 4-quadrant arctangent of a complex number (or any number with x-y coordinates) with a self-normalizing function.
		/// Example Applications: digital FM demodulation, phase angle computations
		/// Code from http://dspguru.com/dsp/tricks/fixed-point-atan2-with-self-normalization/ with some slight edit to get working
		/// </summary>
		/// <param name="y">The y.</param>
		/// <param name="X">The x.</param>
		/// <returns></returns>
		public static MediumDec ArcTan2(MediumDec y, MediumDec x)
		{
			MediumDec coeff_1 = MediumDec.PI / 4;
			MediumDec coeff_2 = 3 * coeff_1;
			MediumDec abs_y = Abs(y) + new MediumDec(0, 1);// kludge to prevent 0/0 condition
			MediumDec r;
			MediumDec angle;
			if (x >= 0)
			{
				r = (x - abs_y) / (x + abs_y);
				angle = coeff_1 - coeff_1 * r;
			}
			else
			{
				r = (x + abs_y) / (abs_y - x);
				angle = coeff_2 - coeff_1 * r;
			}
			if (y < 0)
				return -angle;     // negate if in quad III or IV
			else
				return angle;
		}
	}
}
