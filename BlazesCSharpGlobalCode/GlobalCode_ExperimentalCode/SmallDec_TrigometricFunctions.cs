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
                double Temp = Math.Tan(Math.PI * (double)Value / 180.0);//Converting from Angle to Radians (https://msdn.microsoft.com/en-us/library/system.math.cos(v=vs.110).aspx)
                return new SmallDec(Temp);//Working Placeholder code for now until change later to other formula based code
            }
        }

		public static SmallDec ASin(SmallDec Value)
		{
			double Temp = Math.Asin((double)Value);
			return new SmallDec(Temp);//Working Placeholder code for now until change later to other formula based code 
		}

		public static SmallDec ATan(SmallDec Value)
        {
            double Temp = Math.Atan((double)Value);
            return new SmallDec(Temp);//Working Placeholder code for now until change later to other formula based code 
        }

        public static SmallDec ACos(SmallDec Value)
        {
            double Temp = Math.Acos((double)Value);
            return new SmallDec(Temp);//Working Placeholder code for now until change later to other formula based code
        }
    }
}