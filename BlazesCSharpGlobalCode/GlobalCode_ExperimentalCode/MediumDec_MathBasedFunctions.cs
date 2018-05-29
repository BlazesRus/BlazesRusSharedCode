/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.MediumDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.ComponentModel;

    // Represent +- 4294967295.999999999 with 100% consistency of accuracy
    //(Aka SuperDec_Int32_9Decimal)
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
        public static MediumDec Ceil(MediumDec Value)
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
        public static MediumDec Abs(MediumDec Value)
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
		public static MediumDec NthRoot(MediumDec self, MediumDec Value, MediumDec Precision)
		{
			MediumDec[] x = new MediumDec[2];
			x[0] = self;
			x[1] = self / Value;
			while (MediumDec.Abs(x[0] - x[1]) > Precision)
			{
				x[1] = x[0];
				x[0] = (1 / Value) * (((Value - 1) * x[1]) + (self / MediumDec.Pow(x[1], Value - 1)));

			}
			return x[0];
		}

		public static MediumDec NthRoot(MediumDec self, MediumDec Value)
		{
			return NthRoot(self, Value, OneMillionth);
		}

		public static MediumDec NthRoot(MediumDec self, int Value)
		{
			return NthRoot(self, (MediumDec)Value, OneMillionth);
		}

		/// <summary>
		/// Gets the square root of the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec Sqrt(MediumDec Value)
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
		public static MediumDec Pow(MediumDec self, int Value)
        {
            if (Value > 0)
            {
                //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                MediumDec res = MediumDec.One; // Initialize result
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
            }
            else if (Value == 0)
            {
                return MediumDec.One;
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

#if (!BlazesGlobalCode_ImplicitConversionFrom)//Gets confused since it tries auto converting to MediumDec inside parameter first if Explicitly converts

        public static MediumDec Pow(double self, double Value)
        {
            return MediumDec.Pow((MediumDec)self, (MediumDec)Value);
        }

        ///// <summary>
        /////
        ///// </summary>
        ///// <param name="self"></param>
        ///// <param name="Value"></param>
        ///// <returns></returns>
        public static MediumDec Pow(MediumDec self, double Value) => MediumDec.Pow(self, (MediumDec)Value);

#endif
		/// <summary>
		/// 2.3025850929940456840179914546844
		/// (Based on https://stackoverflow.com/questions/35968963/trying-to-calculate-logarithm-base-10-without-math-h-really-close-just-having)
		/// </summary>
		public static readonly MediumDec LN10 = LN10Value();

		private static MediumDec LN10Value() => new MediumDec(2, 302585093);

		/// <summary>
		/// Natural log of Value(https://en.wikipedia.org/wiki/Natural_logarithm)
		/// Based mostly on https://stackoverflow.com/questions/35968963/trying-to-calculate-logarithm-base-10-without-math-h-really-close-just-having
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec Ln(MediumDec Value)
		{
			MediumDec old_sum = MediumDec.Zero;
			MediumDec xmlxpl = (Value - 1) / (Value + 1);
			MediumDec xmlxpl_2 = xmlxpl * xmlxpl;
			MediumDec denom = MediumDec.One;
			MediumDec frac = xmlxpl;
			MediumDec term = frac;                 // denom start from 1.0
			MediumDec sum = term;

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
		public static MediumDec Log10(MediumDec Value)
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
		public static MediumDec Log(MediumDec Value, MediumDec BaseVal)
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
		public static MediumDec Log(MediumDec Value, int BaseVal)
		{
			return Log10(Value) / Log10((MediumDec)BaseVal);
		}

		public class Fractional
        {
            public int Part01;
            public MediumDec Part02;

            /// <summary>
            /// Initializes a new instance of the <see cref="FractionalV2"/> class with limits to Part01 to prevent overflow of operation
            /// Self ^ Value = Self ^ Part01) ^ (1/Part02)
            /// </summary>
            /// <param name="Value">The value.</param>
            /// <param name="self">The self.</param>
            public Fractional(MediumDec Value, MediumDec self)
            {
                //Limit Part01 based on self to prevent overflow from first Pow integer operation
                int PowLimit;
                switch (self.IntValue)
                {
                    case 0: PowLimit = 9999; break;
                    case 1:
                        if (self.DecimalStatus < 250000000)
                        {
                            PowLimit = 99; break;
                        }
                        else if (self.DecimalStatus < 500000000)
                        {
                            PowLimit = 37; break;
                        }
                        else if (self.DecimalStatus < 750000000)
                        {
                            PowLimit = 39; break;
                        }
                        else
                        {
                            PowLimit = 31; break;//2^32 = 4,294,967,296
                        }
                    case 2:
                        PowLimit = 20; break;
                    case 3:
                        if (self.DecimalStatus < 500000000)
                        {
                            PowLimit = 17; break;
                        }
                        else
                        {
                            PowLimit = 15; break;//4^16== 4,294,967,296
                        }
                    case 4:
                        PowLimit = (self.DecimalStatus < 800000000) ? 14 : 13; break;
                    case 5:
                        PowLimit = (self.DecimalStatus < 500000000) ? 13 : 12; break;
                    case 6:
                        PowLimit = 11; break;
                    case 7:
                    case 8:
                        PowLimit = 10; break;

                    case 9:
                    case 10:
                        PowLimit = 9; break;
                    case 11:
                    case 12:
                    case 13:
                    case 14:
                        PowLimit = 8; break;
                    case 15:
                        if (self.DecimalStatus < 999999500)
                        {
                            PowLimit = 8; break;
                        }
                        else
                        {
                            PowLimit = 5; break;
                        }
                    default:
                        if (self.IntValue <= 83)
                        {
                            PowLimit = 5;
                        }
                        else if (self.IntValue < 254)//256^4 = 4,294,967,296
                        {
                            PowLimit = 4;
                        }
                        else if (self.IntValue == 255)
                        {
                            PowLimit = self.DecimalStatus <= 998000000 ? 4 : 3;
                        }
                        else if (self.IntValue < 2073)
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
        public static MediumDec Pow(MediumDec self, MediumDec Value)
        {
            if (Value.DecimalStatus == 0)
            {
                return MediumDec.Pow(self, Value.IntValue);
            }
            else if (Value.DecimalStatus == NegativeWholeNumber)
            {
                return MediumDec.Pow(self, Value.IntValue * -1);
            }
            else if (Value.DecimalStatus > 0)//Positive Non-Whole Number Value
            {
				Fractional ValueSplit = new Fractional(Value, self);
				MediumDec NewSelf = Pow(self, ValueSplit.Part01);
				return NthRoot(NewSelf, ValueSplit.Part02);
            }
            else//Negative Non-Whole Number Value
            {
				Fractional ValueSplit = new Fractional(Value, self);
				MediumDec NewSelf = Pow(self, ValueSplit.Part01);
				NewSelf = NthRoot(NewSelf, ValueSplit.Part02);
				double SelfAsDecimal = (double)self;
				double ValueAsDecimal = (double)Value;
				SelfAsDecimal = Math.Pow(SelfAsDecimal, ValueAsDecimal);//Debug checking difference between code outputs
				return NewSelf;
			}
        }

        /// <summary>
        /// MediumDec version of Math.Exp(double Value)
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static MediumDec Exp(MediumDec Value)
        {//Working placeholder code for now
            double SelfAsDecimal = (double)Value;
            SelfAsDecimal = Math.Exp(SelfAsDecimal);
            return (MediumDec)SelfAsDecimal;
        }
    }
}