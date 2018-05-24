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
                if (IntValue == 0)
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
        /// Info on Related Formulas:
        /// https://jacksondunstan.com/articles/1217
        /// https://en.wikipedia.org/wiki/Nth_root_algorithm
        /// </summary>
#if !BlazesGlobalCode_PostCompileBasedSqrt
        public void Sqrt()
        {//Unfinished
            if (DecimalStatus == 0)
            {
                switch (IntValue)
                {
                    case 1: IntValue = 1; break;
                    case 4: IntValue = 2; break;
                    case 9: IntValue = 3; break;
                    case 16: IntValue = 4; break;
                    case 25: IntValue = 5; break;
                    case 36: IntValue = 6; break;
                    case 49: IntValue = 7; break;
                    case 64: IntValue = 8; break;
                    case 81: IntValue = 9; break;
                    case 100: IntValue = 10; break;
                    default:
                        double Temp = Math.Sqrt((double)this);//Just use Math.Sqrt(double Value) for now
                        AssignFromVal(Temp);
                        break;
                }
            }
            else
            {
                //if (IntValue == 0)
                //{
                //    //Unfinished
                //}
                //else if (IntValue < 4)
                //{
                //    IntValue = 1;//Unfinished
                //}
                //else if (IntValue < 9)
                //{
                //    IntValue = 2;//Unfinished
                //}
                //else if (IntValue < 16)
                //{
                //    IntValue = 3;//Unfinished
                //}
                //else if (IntValue < 25)
                //{
                //    IntValue = 4;//Unfinished
                //}
                //else if (IntValue < 36)
                //{
                //    IntValue = 5;//Unfinished
                //}
                //else if (IntValue < 49)
                //{
                //    IntValue = 6;//Unfinished
                //}
                //else if (IntValue < 64)
                //{
                //    IntValue = 7;//Unfinished
                //}
                double Temp = Math.Sqrt((double)this);//Just use Math.Sqrt(double Value) for now
                AssignFromVal(Temp);
            }
        }
#else
        public void Sqrt()
        {
        }
#endif

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
        /// Self multiplied by itself Value number of times
        /// Related Formula info:
        /// https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
        /// https://en.wikipedia.org/wiki/Exponentiation_by_squaring
        /// https://stackoverflow.com/questions/3606734/calculate-fractional-exponent-in-for-loop-without-power-function
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static SmallDec Pow(SmallDec self, int Value)
        {
            if (Value > 0)
            {
                //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                SmallDec res = SmallDec.One; // Initialize result
                while (Value > 0)
                {
                    // If Value is odd, multiply self with result
                    if (Value % 2 == 1)
                        res = res * self;

                    // n must be even now
                    Value = Value >> 1; // y = y/2
                    self = self * self; // Change x to x^2
                }
                return res;
                //Old code:
                //for (int NumberOfTimes = Value; NumberOfTimes > 0; --NumberOfTimes)
                //{
                //    NewSelf *= self;
                //}
            }
            else if (Value == 0)
            {
                return SmallDec.One;
            }
            else
            {//Negative Power
                var NewSelf = self;
                for (int NumberOfTimes = Value; NumberOfTimes > 0; --NumberOfTimes)
                {
                    NewSelf /= self;
                }
                return NewSelf;
            }
        }

#if (!BlazesGlobalCode_ImplicitConversionFrom)//Gets confused since it tries auto converting to SmallDec inside parameter first if Explicitly converts
        public static SmallDec Pow(double self, double Value) { return SmallDec.Pow((SmallDec)self, (SmallDec)Value); }

        ///// <summary>
        ///// 
        ///// </summary>
        ///// <param name="self"></param>
        ///// <param name="Value"></param>
        ///// <returns></returns>
        public static SmallDec Pow(SmallDec self, double Value) => SmallDec.Pow(self, (SmallDec)Value);
#endif

        ///// <summary>
        ///// Pow function with Values of less than One
        ///// </summary>
        ///// <param name="self">The self.</param>
        ///// <param name="Value">The value.</param>
        ///// <returns></returns>
        //public static SmallDec PartialPow(SmallDec self, SmallDec Value)
        //{
        //}

        //public struct Fractional
        //{
        //}
        //public static Fractional ConvertValueIntoFractional()
        //{
        //}


        /// <summary>
        /// Approximate version of Math.Pow(double self, double Value) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
        /// and https://stackoverflow.com/questions/3606734/calculate-fractional-exponent-in-for-loop-without-power-function
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static SmallDec Pow(SmallDec self, SmallDec Value)
        {
            if(Value.DecimalStatus==0)
            {
                return SmallDec.Pow(self, Value.IntValue);
            }
            else if(Value.DecimalStatus==NegativeWholeNumber)
            {
                return SmallDec.Pow(self, Value.IntValue*-1);
            }
            else if(Value.DecimalStatus>0)//Positive Non-Whole Number Value
            {
                ////Separate Value into Fractional
                ////long ValueAsIntRep = Value.IntValue * DecimalOverflow + Value.DecimalStatus;
                //long PartOne;
                //long PartTwo;
                //if(Value.IntValue<10)
                //{

                //}
                //else if(Value.IntValue<100)
                //{

                //}
                //else if(Value.IntValue<1000)
                //{

                //}
                //else if(Value.IntValue)
                //Working placeholder code for now
                double SelfAsDecimal = (double)self;
                double ValueAsDecimal = (double)Value;
                SelfAsDecimal = Math.Pow(SelfAsDecimal, ValueAsDecimal);
                return (SmallDec)SelfAsDecimal;
            }
            else//Negative Non-Whole Number Value
            {
                //Working placeholder code for now
                double SelfAsDecimal = (double)self;
                double ValueAsDecimal = (double)Value;
                SelfAsDecimal = Math.Pow(SelfAsDecimal, ValueAsDecimal);
                return (SmallDec)SelfAsDecimal;
            }
        }

        /// <summary>
        /// SmallDec version of Math.Exp(double Value)
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static SmallDec Exp(SmallDec Value)
        {//Working placeholder code for now
            double SelfAsDecimal = (double)Value;
            SelfAsDecimal = Math.Exp(SelfAsDecimal);
            return (SmallDec)SelfAsDecimal;
        }
    }

#endif
    }
