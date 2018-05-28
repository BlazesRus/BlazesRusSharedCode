/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.ComponentModel;

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

        //public static SmallDec NthRoot(SmallDec self, int Value)
        //{
        //}

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

        public static SmallDec Pow(double self, double Value)
        {
            return SmallDec.Pow((SmallDec)self, (SmallDec)Value);
        }

        ///// <summary>
        /////
        ///// </summary>
        ///// <param name="self"></param>
        ///// <param name="Value"></param>
        ///// <returns></returns>
        public static SmallDec Pow(SmallDec self, double Value) => SmallDec.Pow(self, (SmallDec)Value);

#endif
        //public class FractionalV1
        //{
        //    public long Part01;
        //    public long Part02;
        //    public FractionalV1(SmallDec Value)
        //    {
        //        //long ValueAsIntRep = Value.IntValue * DecimalOverflow + Value.DecimalStatus;
        //        //Value = (Value.DecimalStatus * DecimalOverflow)/ 0.DecimalStatus * DecimalOverflow
        //        long PartOne = (long)Value.IntValue * DecimalOverflow;
        //        long PartTwo = Value.DecimalStatus + PartOne;
        //        bool TryToDecreasePlacement = true;
        //        bool KeepAttempting = true;
        //        for (int Attempts = 0; Attempts < 14 && KeepAttempting; ++Attempts)//Reduce Fractional Size
        //        {
        //            if (TryToDecreasePlacement)//Try to remove excess decimal places first
        //            {
        //                if (PartTwo % 100000 == 0 && PartOne % 100000 == 0) { PartTwo /= 100000; PartOne /= 100000; }
        //                else if (PartTwo % 100 == 0 && PartOne % 100 == 0) { PartTwo /= 100; PartOne /= 100; }
        //                else if (PartTwo % 10 == 0 && PartOne % 10 == 0) { PartTwo /= 10; PartOne /= 10; }
        //                else
        //                {
        //                    TryToDecreasePlacement = false;
        //                }
        //            }
        //            else
        //            {
        //                if (PartTwo % 7 == 0 && PartOne % 7 == 0) { PartTwo /= 7; PartOne /= 7; }
        //                else if (PartTwo % 5 == 0 && PartOne % 5 == 0) { PartTwo /= 5; PartOne /= 5; }
        //                else if (PartTwo % 3 == 0 && PartOne % 3 == 0) { PartTwo /= 3; PartOne /= 3; }
        //                else if (PartTwo % 2 == 0 && PartOne % 2 == 0) { PartTwo /= 2; PartOne /= 2; }
        //                else if (PartTwo % 11 == 0 && PartOne % 11 == 0) { PartTwo /= 11; PartOne /= 11; }
        //                else if (PartTwo % 13 == 0 && PartOne % 13 == 0) { PartTwo /= 13; PartOne /= 13; }
        //                else if (PartTwo % 17 == 0 && PartOne % 17 == 0) { PartTwo /= 17; PartOne /= 17; }
        //                else if (PartTwo % 23 == 0 && PartOne % 23 == 0) { PartTwo /= 23; PartOne /= 23; }
        //                else if (PartTwo % 29 == 0 && PartOne % 29 == 0) { PartTwo /= 29; PartOne /= 29; }
        //                else if (PartTwo % 31 == 0 && PartOne % 31 == 0) { PartTwo /= 31; PartOne /= 31; }
        //                else
        //                {
        //                    KeepAttempting = false;
        //                }
        //            }
        //        }
        //    }
        //}

        public class Fractional
        {
            public int Part01;
            public SmallDec Part02;

            /// <summary>
            /// Initializes a new instance of the <see cref="FractionalV2"/> class.
            /// Self ^ Value = Self ^ Part01) ^ (1/Part02)
            /// </summary>
            /// <param name="Value">The value.</param>
            /// <param name="self">The self.</param>
            public Fractional(SmallDec Value, SmallDec self)
            {
                //Limit Part01 based on self to prevent overflow from first Pow integer operation
                int PowLimit = 25;
                switch (self.IntValue)
                {
                    case 0: PowLimit = 999; break;//Could go even higher without overflow(although more lost to decimal places) but not worth processing time cost
                    case 1:
                        if (self.DecimalStatus < 250000000)
                        {
                            PowLimit = 49; break;//1.25^49 = ~56k
                        }
                        else if (self.DecimalStatus < 500000000)
                        {
                            PowLimit = 27; break;//1.5^27 = ~57k
                        }
                        else if (self.DecimalStatus < 850000000)
                        {
                            PowLimit = 18; break;
                        }
                        else
                        {
                            PowLimit = 15; break;//2^16 = 65536
                        }
                    case 2:
                        PowLimit = 10; break;//3^10 = 59k
                    case 3:
                        if (self.DecimalStatus < 500000000)
                        {
                            PowLimit = 8; break;//2.5^8 = ~22k
                        }
                        else
                        {
                            PowLimit = 7; break;//4^8 = 65536
                        }
                    case 4:
                        PowLimit = (self.DecimalStatus < 500000000) ? 7 : 6; break;
                    case 5:
                        PowLimit = 6; break;
                    case 6:
                    case 7:
                    case 8:
                        PowLimit = 5; break;

                    case 9:
                    case 10:
                    case 11:
                    case 12:
                    case 13:
                    case 14:
                        PowLimit = 4; break;
                    case 15://16^4 = 65536
                        PowLimit = (self.DecimalStatus <= 999900000) ? 4 : 3; break;
                    default:
                        if (self.IntValue < 39)
                        {
                            PowLimit = 3;
                        }
                        else if (self.IntValue < 254)
                        {
                            PowLimit = 2;
                        }
                        else if (self.IntValue == 255 && self.DecimalStatus <= 998000000)//256^2 = = 65536
                        {
                            PowLimit = 2;
                        }
                        else
                        {
                            PowLimit = 1;
                        }
                        break;
                }
                for (Part01 = 1; Part01 < PowLimit || Part02.DecimalStatus == 0; ++Part01)
                {
                    Part02 = Part01 / Value;
                }
            }
        }

        /// <summary>
        /// Approximate version of Math.Pow(double self, double Value) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
        /// and https://stackoverflow.com/questions/3606734/calculate-fractional-exponent-in-for-loop-without-power-function
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static SmallDec Pow(SmallDec self, SmallDec Value)
        {
            if (Value.DecimalStatus == 0)
            {
                return SmallDec.Pow(self, Value.IntValue);
            }
            else if (Value.DecimalStatus == NegativeWholeNumber)
            {
                return SmallDec.Pow(self, Value.IntValue * -1);
            }
            else if (Value.DecimalStatus > 0)//Positive Non-Whole Number Value
            {
                //In many cases splitting into Fractional to perform Pow might cause overflows(so need to limit which cases uses Fractional based Pow)
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