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
    using System.Windows;
    using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

    // Represent +- 65535.999999999(Can only represent +- 65535.9999 if SmallDec_ReducedSize or SmallDec_UseLegacyStorage set) with 100% consistency of accuracy
    //(Aka SuperDec_Int16_9Decimal Or SuperDec_Int16_4Decimal)
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
    {
#if (!SmallDec_ReducedSize && !SmallDec_UseLegacyStorage)//Only enable for current implementation of SmallDec
        /// <summary>
        /// Removes decimal place info on self
        /// </summary>
        public void Ceil()
        {
            if (DecimalStatus < 0)
            {
                if(IntValue==0)
                {
                    DecimalStatus = 0;
                }
                else
                {
                    DecimalStatus = NegativeWholeNumber;
                }
            }
            else
            {
                DecimalStatus = 0;
            }
        }

        /// <summary>
        /// Removes decimal place info from Value
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns></returns>
        public static SmallDec Ceil(SmallDec Value)
        {
            Value.Ceil();
            return Value;
        }

        /// <summary>
        /// Converts any negative number into positive
        /// </summary>
        public void Abs()
        {
            if (DecimalStatus < 0)
            {
                DecimalStatus *= -1;
            }
        }

        /// <summary>
        /// Perform absolute value on the Value
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns></returns>
        public static SmallDec Abs(SmallDec Value)
        {
            Value.Abs();
            return Value;
        }

        /// <summary>
        /// Perform square root on this instance.
        /// </summary>
        public void Sqrt()
        {//Unfinished
            if (IntValue == 0)
            {

            }
            else if (IntValue==1 && DecimalStatus==0)
            {
                IntValue = 1;
            }
            else if (IntValue == 4 && DecimalStatus == 0)
            {
                IntValue = 2;
            }
            else if(IntValue<4)
            {
                IntValue = 1;//Unfinished
            }
            else if (IntValue == 9 && DecimalStatus == 0)
            {
                IntValue = 3;
            }
            else if(IntValue<9)
            {
                IntValue = 2;//Unfinished
            }
            else if (IntValue == 16 && DecimalStatus == 0)
            {
                IntValue = 4;
            }
            else if(IntValue<16)
            {
                IntValue = 3;//Unfinished
            }
            else if (IntValue == 25 && DecimalStatus == 0)
            {
                IntValue = 5;
            }
            else if(IntValue<25)
            {
                IntValue = 4;//Unfinished
            }
            else if (IntValue == 36 && DecimalStatus == 0)
            {
                IntValue = 6;
            }
            else if (IntValue < 36)
            {
                IntValue = 5;//Unfinished
            }
            else if (IntValue == 49 && DecimalStatus == 0)
            {
                IntValue = 7;
            }
            else if (IntValue < 49)
            {
                IntValue = 6;//Unfinished
            }
            else if (IntValue == 64 && DecimalStatus == 0)
            {
                IntValue = 8;
            }
            else if (IntValue < 64)
            {
                IntValue = 7;//Unfinished
            }
            else
            {
                //Unfinished
            }
        }

        /// <summary>
        /// Gets the square root of the specified value.
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns></returns>
        public static SmallDec Sqrt(SmallDec Value)
        {
            Value.Sqrt();
            return Value;
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static SmallDec Pow(SmallDec self, int Value)
        {
            var NewSelf = self;
            if (Value == 0)
            {
                NewSelf.intValue = 1;
                NewSelf.DecimalStatus = 0;
            }
            else if (Value < 0)
            {
                for (int NumberOfTimes = Value; NumberOfTimes > 0; --NumberOfTimes)
                {
                    NewSelf /= self;
                }
            }
            else
            {
                for (int NumberOfTimes = Value; NumberOfTimes > 0; --NumberOfTimes)
                {
                    NewSelf *= self;
                }
            }
            return NewSelf;
        }

        //        //public static SmallDec Pow(double self, double Value) { return SmallDec.Pow((SmallDec)self, (SmallDec)Value); }

        ///// <summary>
        ///// 
        ///// </summary>
        ///// <param name="self"></param>
        ///// <param name="Value"></param>
        ///// <returns></returns>
        //public static SmallDec Pow(SmallDec self, double Value) => SmallDec.Pow(self, (SmallDec)Value);
        //#if (BlazesGlobalCode_StandardExplicitConversionFrom)//Gets confused since it tries auto converting to SmallDec inside parameter first
        //        public static SmallDec Pow(SmallDec self, SmallDec Value) { return SmallDec.Pow(self, Value); }
        //#endif

        ///// <summary>
        ///// Approximate version of Math.Pow(double self, double Value)
        ///// </summary>
        ///// <param name="self"></param>
        ///// <param name="Value"></param>
        ///// <returns></returns>
        //public static SmallDec Pow(SmallDec self, SmallDec Value)
        //{
        //    var NewSelf = self;
        //    //SmallDec version of Math.Pow()
        //    if (Value.DecimalStatus == 0)
        //    {
        //        if (Value.intValue == 0)
        //        {
        //            NewSelf.intValue = 1;
        //            NewSelf.DecimalStatus = 0;
        //        }
        //        else if (Value.DecimalStatus == 0)
        //        {
        //            for (ushort NumberOfTimes = Value.intValue; NumberOfTimes > 0; --NumberOfTimes)
        //            {
        //                NewSelf *= self;
        //            }
        //        }
        //        else
        //        {
        //            for (ushort NumberOfTimes = Value.intValue; NumberOfTimes > 0; --NumberOfTimes)
        //            {
        //                NewSelf /= self;
        //            }
        //        }
        //    }
        //    else
        //    {//To-Do need to finish remaining power part of code
        //     //decimal SelfAsDecimal = (decimal) self;
        //        if (Value.intValue == 0)
        //        {
        //            NewSelf.intValue = 1;
        //            NewSelf.DecimalStatus = 0;
        //        }
        //        else if (Value.DecimalStatus == 0)
        //        {
        //            for (ushort NumberOfTimes = Value.intValue; NumberOfTimes > 0; --NumberOfTimes)
        //            {
        //                NewSelf *= self;
        //            }
        //        }
        //        else
        //        {
        //            for (ushort NumberOfTimes = Value.intValue; NumberOfTimes > 0; --NumberOfTimes)
        //            {
        //                NewSelf /= self;
        //            }
        //        }
        //        //Now need to deal with the remaining "power"
        //        Value.intValue = 0;
        //        //Number is less then NewSelf Currently is (Sloping Curve in closeness to next power)
        //        SmallDec TempDouble = Math.Pow((double)self, (double)Value);
        //        if (Value.DecimalStatus == 0)
        //        {
        //            NewSelf *= TempDouble;
        //        }
        //        else
        //        {
        //            NewSelf /= TempDouble;
        //        }
        //    }
        //    return NewSelf;
        //}

        //        /// <summary>
        //        /// SmallDec version of Math.Exp(double Value)
        //        /// </summary>
        //        /// <param name="Value"></param>
        //        /// <returns></returns>
        //        public static SmallDec Exp(SmallDec Value)
        //        {
        //            double SelfAsDecimal = (double)Value;
        //            SelfAsDecimal = Math.Exp(SelfAsDecimal);
        //            return (SmallDec)SelfAsDecimal;
        //        }
    }
#endif
}
