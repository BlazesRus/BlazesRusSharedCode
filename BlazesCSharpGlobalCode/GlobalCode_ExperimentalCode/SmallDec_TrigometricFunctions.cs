/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Globalization;
    using System.IO;
    using System.Windows;
    using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

    // Represent +- 65535.999999(Can only represent +- 65535.9999 if SmallDec_ReducedSize or SmallDec_UseLegacyStorage set) with 100% consistency of accuracy
    //(Aka SuperDec_Int16_4Decimal)
    public
#if (!BlazesGlobalCode_SmallDec_AsStruct)
    sealed
#endif
    partial
#if (!BlazesGlobalCode_SmallDec_AsStruct)
    class
#else
    struct
#endif
    SmallDec : IFormattable, INotifyPropertyChanged
    {//https://revisionmaths.com/gcse-maths-revision/trigonometry/sin-cos-and-tan

        /// <summary>
        /// PI value (3.141592654)
        /// </summary>
        /// <returns></returns>
        private static SmallDec PIValue()
        {
            return new SmallDec(3, 141592654);
        }
        /// <summary>
        /// PI value (about 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513)
        /// </summary>
        public static readonly SmallDec PI = PIValue();

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        private static SmallDec EValue()
        {
            return new SmallDec(2, 718281828);
        }
        /// <summary>
        /// (2.7182818284590451)
        /// </summary>
        public static readonly SmallDec E = EValue();

        /// <summary>
        /// Value at one
        /// </summary>
        public static readonly SmallDec NegativeOne = NegativeOneValue();

        private static SmallDec NegativeOneValue() => new SmallDec(1, SmallDec.NegativeWholeNumber);

		/// <summary>
		/// Get Sin from Value of angle.
		/// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static SmallDec SinFromAngle(SmallDec Value)
        {
            if(Value.DecimalStatus==SmallDec.NegativeWholeNumber)
            {
                Value.DecimalStatus = 0;
                Value.IntValue %= 360;
                Value.IntValue = (ushort)(360 - (int)Value.IntValue);
                if(Value.IntValue==360) { Value.IntValue = 0; }
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
			if (Value == SmallDec.Zero) { return SmallDec.Zero; }
			else if (Value.IntValue == 30 && Value.DecimalStatus == 0)
			{
				return new SmallDec(0, 500000000);
			}
			else if (Value.IntValue == 90 && Value.DecimalStatus == 0)
			{
				return SmallDec.One;
			}
			else if (Value.IntValue == 180 && Value.DecimalStatus == 0)
			{
				return SmallDec.Zero;
			}
			else if (Value.IntValue == 270 && Value.DecimalStatus == 0)
			{
				return SmallDec.NegativeOne;
			}
			else
			{
				SmallDec NewValue = SmallDec.Zero;
				//Angle as Radian
				SmallDec Radius = SmallDec.PI * Value / 180; 
				for (int i = 0; i < 7; ++i)
				{ // That's Taylor series!!
					NewValue += Pow(-1, i) * Pow(Radius, 2 * i + 1) / SuperDecGlobalCode.Fact(2 * i + 1);
				}
				return NewValue;
				//double Temp = Math.Sin(Math.PI * (double)Value / 180.0);//Converting from Angle to Radians (https://msdn.microsoft.com/en-us/library/system.math.cos(v=vs.110).aspx)
				//return new SmallDec(Temp);//Working Placeholder code for now until change later to other formula based code
			}
        }

		/// <summary>
		/// Get Cos() from Value of Angle
		/// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static SmallDec CosFromAngle(SmallDec Value)
        {
            if (Value.DecimalStatus == SmallDec.NegativeWholeNumber)
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
            if (Value == SmallDec.Zero) { return SmallDec.One; }
            else if (Value.IntValue == 90 && Value.DecimalStatus == 0)
            {
                return SmallDec.Zero;
            }
            else if (Value.IntValue == 180 && Value.DecimalStatus == 0)
            {
                return SmallDec.NegativeOne;
            }
            else if (Value.IntValue == 270 && Value.DecimalStatus == 0)
            {
                return SmallDec.Zero;
            }
            else
            {
				SmallDec NewValue = SmallDec.Zero;
				//Angle as Radian
				SmallDec Radius = SmallDec.PI * Value / 180;
				for (int i = 0; i < 7; ++i)
				{ // That's also Taylor series!!
					NewValue += Pow(-1, i) * Pow(Radius, 2 * i) / SuperDecGlobalCode.Fact(2 * i);
				}
				return NewValue;
				//double Temp = Math.Cos(Math.PI * (double)Value / 180.0);//Converting from Angle to Radians (https://msdn.microsoft.com/en-us/library/system.math.cos(v=vs.110).aspx)
				//return new SmallDec(Temp);//Working Placeholder code for now until change later to other formula based code
			}
        }

		/// <summary>
		/// Get Tan from Value in Radians
		/// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static SmallDec Tan(SmallDec Value)
		{
			SmallDec SinValue = SmallDec.Zero;
			SmallDec CosValue = SmallDec.Zero;
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
		public static SmallDec MergedTan(SmallDec Value)
		{
			SmallDec Output = SmallDec.Zero;
			for (int i = 0; i < 7; ++i)
			{
				Output += (Pow(Value, 2 * i + 1) / SuperDecGlobalCode.Fact(2 * i + 1))/(Pow(Value, 2 * i) / SuperDecGlobalCode.Fact(2 * i));
			}
			return Output;
		}

		/// <summary>
		/// Get Tangent from Value in Degrees (SlopeInPercent:http://communityviz.city-explained.com/communityviz/s360webhelp4-2/formulas/function_library/atan_function.htm)
		/// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static SmallDec TanFromAngle(SmallDec Value)
        {
            if (Value.DecimalStatus == SmallDec.NegativeWholeNumber)
            {
                Value.DecimalStatus = 0;
                Value.IntValue %= 360;
                Value.IntValue = (ushort)(360 - (int)Value.IntValue);
                if (Value.IntValue == 360) { Value.IntValue = 0; }
            }
            else if(Value.DecimalStatus<0)
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
            if (Value == SmallDec.Zero) { return SmallDec.Zero; }
            else if (Value.IntValue == 90 && Value.DecimalStatus == 0)
            {
                return SmallDec.NaN;//Positive Infinity on left of;Negative Infinity on right
            }
            else if (Value.IntValue == 180 && Value.DecimalStatus == 0)
            {
                return SmallDec.Zero;
            }
            else if (Value.IntValue == 270 && Value.DecimalStatus == 0)
            {
                return SmallDec.NaN;//Positive Infinity on left of;Negative Infinity on right
            }
            else
            {
				//int QuadrantNum = Value.IntValue < 90? 1: (Value < 180? 2 : (Value < 270 ? 3: 4));
				//double Temp = Math.Tan(Math.PI * (double)Value / 180.0);//Converting from Angle to Radians (https://msdn.microsoft.com/en-us/library/system.math.cos(v=vs.110).aspx)
				//            return new SmallDec(Temp);//Working Placeholder code for now until change later to other formula based code
				return Tan(SmallDec.PI * Value / 180);
			}
        }

		/// <summary>
		/// Arc Sine (http://communityviz.city-explained.com/communityviz/s360webhelp4-2/formulas/function_library/asin_function.htm)
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static SmallDec ASin(SmallDec Value)
		{
			double Temp = Math.Asin((double)Value);
			return new SmallDec(Temp);//Working Placeholder code for now until change later to other formula based code 
		}

		/// <summary>
		/// Arc Sine from Value in Degrees
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static SmallDec ASinFromDegrees(SmallDec Value)
		{
			return ASin(SmallDec.PI * Value / 180);
		}

		/// <summary>
		/// Gets Inverse Tangent from Value of Angle
		/// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static SmallDec ATanFromDegrees(SmallDec Value)
        {
			return ATan(SmallDec.PI * Value / 180);
		}

		/// <summary>
		/// Gets Inverse Tangent from Value in Radians
		/// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static SmallDec ATan(SmallDec Value)
		{
			//double Temp = Math.Atan((double)Value);
			//return new SmallDec(Temp);//Working Placeholder code for now until change later to other formula based code 
			SmallDec SinValue = SmallDec.Zero;
			SmallDec CosValue = SmallDec.Zero;
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
		public static SmallDec SlopeInDegrees(SmallDec Value) => ATan(Value) * 180 / PI;

		/// <summary>
		/// Arc Cosine(http://communityviz.city-explained.com/communityviz/s360webhelp4-2/formulas/function_library/acos_function.htm)
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static SmallDec ACos(SmallDec Value)
        {
            double Temp = Math.Acos((double)Value);
            return new SmallDec(Temp);//Working Placeholder code for now until change later to other formula based code
        }


		/// <summary>
		/// Arc Sine from Value in Degrees
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static SmallDec ACosFromDegrees(SmallDec Value)
		{
			return ACos(SmallDec.PI * Value / 180);
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
		public static SmallDec ArcTan2(SmallDec y, SmallDec x)
		{
			SmallDec coeff_1 = SmallDec.PI / 4;
			SmallDec coeff_2 = 3 * coeff_1;
			SmallDec abs_y = Abs(y) + new SmallDec(0,1);// kludge to prevent 0/0 condition
			SmallDec r;
			SmallDec angle;
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