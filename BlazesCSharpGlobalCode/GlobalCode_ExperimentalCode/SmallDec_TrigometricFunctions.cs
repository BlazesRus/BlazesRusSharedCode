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
        /// Value at one
        /// </summary>
        public static readonly SmallDec NegativeOne = NegativeOneValue();

        private static SmallDec NegativeOneValue() => new SmallDec(1, SmallDec.NegativeWholeNumber);

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
            else if(Value.IntValue==90&&Value.DecimalStatus==0)
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
                double Temp = Math.Sin(Math.PI * (double)Value / 180.0);//Converting from Angle to Radians (https://msdn.microsoft.com/en-us/library/system.math.cos(v=vs.110).aspx)
                return new SmallDec(Temp);//Working Placeholder code for now until change later to other formula based code
            }
        }

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
                double Temp = Math.Cos(Math.PI * (double)Value / 180.0);//Converting from Angle to Radians (https://msdn.microsoft.com/en-us/library/system.math.cos(v=vs.110).aspx)
                return new SmallDec(Temp);//Working Placeholder code for now until change later to other formula based code
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