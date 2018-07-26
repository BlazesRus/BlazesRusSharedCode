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
        /// Removes decimal place info from Value
        /// </summary>
        public void Floor()
        {
            this.DecimalStatus = 0;
        }

        /// <summary>
        /// Removes decimal place info from Value
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns></returns>
        public static SmallDec Floor(SmallDec Value)
        {
            Value.Floor();
            return Value;
        }

        /// <summary>
        /// Returns floored value with all fractional digits after specified precision cut off.
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <param name="precision">The precision.</param>
        /// <returns></returns>
        public static SmallDec Floor(SmallDec Value, int precision)
        {
            Value.Floor(precision);
            return Value;
        }

        /// <summary>
        /// Returns floored value with all fractional digits after specified precision cut off.
        /// </summary>
        /// <param name="precision">The precision.</param>
        public void Floor(int precision)
        {
            switch (precision)
            {
                case 9: break;
                case 8: this.DecimalStatus /= 10; this.DecimalStatus *= 10; break;
                case 7: this.DecimalStatus /= 100; this.DecimalStatus *= 100; break;
                case 6: this.DecimalStatus /= 1000; this.DecimalStatus *= 1000; break;
                case 5: this.DecimalStatus /= 10000; this.DecimalStatus *= 10000; break;
                case 4: this.DecimalStatus /= 100000; this.DecimalStatus *= 100000; break;
                case 3: this.DecimalStatus /= 1000000; this.DecimalStatus *= 1000000; break;
                case 2: this.DecimalStatus /= 10000000; this.DecimalStatus *= 10000000; break;
                case 1: this.DecimalStatus /= 100000000; this.DecimalStatus *= 100000000; break;
                default: this.DecimalStatus = 0; break;
            }
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
        {
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
                    case 121: IntValue = 11; break;
                    case 144: IntValue = 12; break;
                    case 196: IntValue = 13; break;
                    case 225: IntValue = 15; break;
                    case 256: IntValue = 16; break;
                    case 289: IntValue = 17; break;
                    case 324: IntValue = 18; break;
                    case 361: IntValue = 19; break;
                    case 400: IntValue = 20; break;
                    default:
                        NthRoot(this, 2);
                        break;
                }
            }
            else
            {
                NthRoot(this, 2);
            }
        }

        /// <summary>
        /// Get the (Value)th Root
        /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns></returns>
        public static SmallDec NthRoot(SmallDec self, SmallDec Value, SmallDec Precision)
        {
            SmallDec[] x = new SmallDec[2];
            x[0] = self;
            x[1] = self / Value;
            while (SmallDec.Abs(x[0] - x[1]) > Precision)
            {
                x[1] = x[0];
                x[0] = (1 / Value) * (((Value - 1) * x[1]) + (self / SmallDec.Pow(x[1], Value - 1)));

            }
            return x[0];
        }

        public static SmallDec NthRoot(SmallDec self, SmallDec Value)
        {
            return NthRoot(self, Value, OneMillionth);
        }

        public static SmallDec NthRoot(SmallDec self, int Value)
        {
            return NthRoot(self, (SmallDec) Value, OneMillionth);
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
        /// <summary>
        /// 2.3025850929940456840179914546844
        /// (Based on https://stackoverflow.com/questions/35968963/trying-to-calculate-logarithm-base-10-without-math-h-really-close-just-having)
        /// </summary>
        public static readonly SmallDec LN10 = LN10Value();

        private static SmallDec LN10Value() => new SmallDec(2, 302585093);

        /// <summary>
        /// Natural log of Value(https://en.wikipedia.org/wiki/Natural_logarithm)
        /// Based mostly on https://stackoverflow.com/questions/35968963/trying-to-calculate-logarithm-base-10-without-math-h-really-close-just-having
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns></returns>
        public static SmallDec Ln(SmallDec Value)
        {
            SmallDec old_sum = SmallDec.Zero;
            SmallDec xmlxpl = (Value - 1) / (Value + 1);
            SmallDec xmlxpl_2 = xmlxpl * xmlxpl;
            SmallDec denom = SmallDec.One;
            SmallDec frac = xmlxpl;
            SmallDec term = frac;                 // denom start from 1.0
            SmallDec sum = term;

            while (sum != old_sum)
            {
                old_sum = sum;
                denom += 2.0;
                frac *= xmlxpl_2;
                sum += frac / denom;
            }
            return 2.0 * sum;
        }

        /// <summary>
        /// Log Base 10 of Value
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns></returns>
        public static SmallDec Log10(SmallDec Value)
        {
            return Ln(Value) / LN10;
        }

        /// <summary>
        /// Log with Base of BaseVal of Value
        /// Based on http://home.windstream.net/okrebs/page57.html
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <param name="BaseVal">The base of Log</param>
        /// <returns></returns>
        public static SmallDec Log(SmallDec Value, SmallDec BaseVal)
        {
            return Log10(Value) / Log10(BaseVal);
        }

        /// <summary>
        /// Log with Base of BaseVal of Value
        /// Based on http://home.windstream.net/okrebs/page57.html
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <param name="BaseVal">The base of Log</param>
        /// <returns></returns>
        public static SmallDec Log(SmallDec Value, int BaseVal)
        {
            return Log10(Value) / Log10((SmallDec)BaseVal);
        }

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
                Fractional ValueSplit = new Fractional(Value, self);
                SmallDec NewSelf = Pow(self, ValueSplit.Part01);
                return NthRoot(NewSelf, ValueSplit.Part02);
            }
            else//Negative Non-Whole Number Value
            {
                Fractional ValueSplit = new Fractional(Value, self);
                SmallDec NewSelf = Pow(self, ValueSplit.Part01);
                NewSelf = NthRoot(NewSelf, ValueSplit.Part02);
                double SelfAsDecimal = (double)self;
                double ValueAsDecimal = (double)Value;
                SelfAsDecimal = Math.Pow(SelfAsDecimal, ValueAsDecimal);//Debug checking difference between code outputs
                return NewSelf;
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