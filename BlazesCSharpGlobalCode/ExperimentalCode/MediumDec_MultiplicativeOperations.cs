/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.ExperimentalCode.MediumDec
namespace CSharpGlobalCode.ExperimentalCode
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
        /// Implements the operator *.(Self*TargetValue)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="y">The y.</param>
        /// <returns>
        /// The result of the operator.
        /// </returns>
        public static MediumDec operator *(MediumDec self, MediumDec y)
        {
            if (y.intValue == 0 && y.DecimalStatus == 0)
            {
                self.intValue = 0;
                self.DecimalStatus = 0;
                return self;
            }
            bool SelfIsNegative = self.DecimalStatus < 0;
            bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            if (SelfIsNegative)
            {
                if (SelfIsWholeN) { self.DecimalStatus = 0; }
                else { self.DecimalStatus *= -1; }
            }
            bool ValueIsNegative = y.DecimalStatus < 0;
            bool ValueIsWholeN = y.DecimalStatus == NegativeWholeNumber;
            if (ValueIsNegative)
            {
                if (ValueIsWholeN) { y.DecimalStatus = 0; }
                else { y.DecimalStatus *= -1; }
            }
            if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
            {
                self.IntValue *= y.IntValue;
            }
            else if (y.DecimalStatus == 0)//Y is integer
            {
                //long IntHalf = (long)self.IntValue* DecimalOverflow;
                //long DecimalHalf = (long)self.DecimalStatus;
                ////XXXXXXXXXXX00000000 * y.Int
                ////00000000000YYYYYYYY * y.int
                self *= y.IntValue;
            }
            else if (self.DecimalStatus == 0)
            {
                y *= self.IntValue;
                self = y;
            }
            else if (y.IntValue == 0 && self.IntValue == 0)
            {
                long Temp04 = (long)self.DecimalStatus * (long)y.DecimalStatus;
                Temp04 /= DecimalOverflow;
                self.DecimalStatus = (int)Temp04;
            }
            else
            {
                //X.Y * Z.V == ((X * Z) + (X * .V) + (.Y * Z) + (.Y * .V))
                long Temp02 = (long)(self.IntValue * DecimalOverflow) + self.DecimalStatus;
                Temp02 *= y.IntValue;//Temp02 holds long version of X.Y * Z
                //X.Y *.V
                long Temp03 = (long)self.IntValue * y.DecimalStatus;//Temp03 holds long version of X *.V
                long Temp04 = (long)self.DecimalStatus * (long)y.DecimalStatus;
                Temp04 /= DecimalOverflow;
                //Temp04 holds long version of .Y * .V
                long IntegerRep = Temp02 + Temp03 + Temp04;
                long IntHalf = IntegerRep / DecimalOverflow;
                IntegerRep -= IntHalf * (long)DecimalOverflow;
                self.IntValue = (uint)IntHalf;
                self.DecimalStatus = (int)IntegerRep;
            }
            if (ValueIsNegative)
            {
                SelfIsNegative = !SelfIsNegative;
            }
            if (SelfIsNegative) { if (self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; } else { self.DecimalStatus *= -1; } }
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator /(MediumDec self, MediumDec y)
        {

            if (y.intValue == 0 && y.DecimalStatus == 0)
            {
#if (MediumDec_PreventDivideByZeroException)
                Console.WriteLine("Prevented dividing by zero");
                return self;
#else
                throw new DivideByZeroException("MediumDec value can not be divided by zero");
#endif
            }
            bool SelfIsNegative = self.DecimalStatus < 0;
            bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            if (SelfIsNegative)
            {
                if (SelfIsWholeN) { self.DecimalStatus = 0; }
                else { self.DecimalStatus *= -1; }
            }
            bool ValueIsNegative = y.DecimalStatus < 0;
            bool ValueIsWholeN = y.DecimalStatus == NegativeWholeNumber;
            if (ValueIsNegative)
            {
                if (ValueIsWholeN) { y.DecimalStatus = 0; }
                else { y.DecimalStatus *= -1; }
            }
            if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
            {
                long SRep = self.IntValue * DecimalOverflow;
                long YRep = y.IntValue;
                SRep /= y.IntValue;
                if (SRep >= DecimalOverflow)
                {
                    long OverflowVal = SRep / DecimalOverflow;
                    SRep -= OverflowVal * DecimalOverflow;
                    self.IntValue = (ushort)OverflowVal;
                    self.DecimalStatus = (short)SRep;
                }
            }
            else if (y.DecimalStatus == 0)//Y is integer
            {
                self /= y.IntValue;
            }
            else if (self.IntValue < 10 && y.IntValue == 0)//Using this method would cause overflow of SelfRep if more in most cases
            {//this part seems to work unless y.int is more than 0 for some reason
                long SelfRep = (long)(self.IntValue * DecimalOverflow) + self.DecimalStatus;
                SelfRep *= DecimalOverflow;
                long ValueRep = (long)(y.IntValue * DecimalOverflow) + y.DecimalStatus;
                SelfRep /= ValueRep;
                long IntHalf = SelfRep / DecimalOverflow;
                SelfRep -= IntHalf * (long)DecimalOverflow;
                self.IntValue = (uint)IntHalf;
                self.DecimalStatus = (int)SelfRep;
            }
            else
            {
                long SelfRep = ((long)self.IntValue * DecimalOverflow) + self.DecimalStatus;
                long ValueRep = ((long)y.IntValue * DecimalOverflow) + y.DecimalStatus;
                SelfRep /= ValueRep;
                ushort IntResult = (ushort)SelfRep;
                SelfRep = ((long)self.IntValue * DecimalOverflow) + self.DecimalStatus;
                long Temp01 = (long)IntResult * ValueRep;
                SelfRep -= Temp01;
                SelfRep *= DecimalOverflow;
                SelfRep /= ValueRep;
                self.IntValue = IntResult;
                self.DecimalStatus = (int)SelfRep;
            }
            if (ValueIsNegative)
            {
                SelfIsNegative = !SelfIsNegative;
            }
            if (SelfIsNegative) { if (self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; } else { self.DecimalStatus *= -1; } }
            return self;
        }
    }
}
