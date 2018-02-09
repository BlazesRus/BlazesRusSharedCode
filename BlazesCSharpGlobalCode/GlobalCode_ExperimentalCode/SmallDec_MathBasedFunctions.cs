/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
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

#pragma warning disable CC0001 // You should use 'var' whenever possible.
#pragma warning disable CC0105 // You should use 'var' whenever possible.
#pragma warning disable CS3001 // Argument type is not CLS-compliant
#pragma warning disable CS3002 // Return type is not CLS-compliant
#pragma warning disable CS3003 // Type is not CLS-compliant
#pragma warning disable CC0003 // Your catch should include an Exception
#pragma warning disable CS0436 // Type conflicts with imported type
#pragma warning disable CS3021 // Type or member does not need a CLSCompliant attribute because the assembly does not have a CLSCompliant attribute
    //Aka SuperDec_Int16_4Decimal
    public
#if (BlazesGlobalCode_SmallDec_AsClass)
    sealed
#endif
    partial
#if (BlazesGlobalCode_SmallDec_AsClass)
    class
#else
    struct
#endif
    SmallDec : IComparable<SmallDec>, IConvertible, IEquatable<SmallDec>, IFormattable
#if (!SmallDec_DisableCustomTypeDescriptor)
    , ICustomTypeDescriptor
#endif
    {
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
                NewSelf.DecBoolStatus = 0;
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

        //public static SmallDec Pow(double self, double Value) { return SmallDec.Pow((SmallDec)self, (SmallDec)Value); }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static SmallDec Pow(SmallDec self, double Value) => SmallDec.Pow(self, (SmallDec)Value);
#if (BlazesGlobalCode_StandardExplicitConversionFrom)//Gets confused since it tries auto converting to SmallDec inside parameter first
        public static SmallDec Pow(SmallDec self, SmallDec Value) { return SmallDec.Pow(self, Value); }
#endif
        /// <summary>
        /// Approximate version of Math.Pow(double self, double Value)
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static SmallDec Pow(SmallDec self, SmallDec Value)
        {
            var NewSelf = self;
            //SmallDec version of Math.Pow()
            if (Value.DecimalStatus == 0)
            {
                if (Value.intValue == 0)
                {
                    NewSelf.intValue = 1;
                    NewSelf.DecBoolStatus = 0;
                }
                else if (Value.DecBoolStatus == 0)
                {
                    for (ushort NumberOfTimes = Value.intValue; NumberOfTimes > 0; --NumberOfTimes)
                    {
                        NewSelf *= self;
                    }
                }
                else
                {
                    for (ushort NumberOfTimes = Value.intValue; NumberOfTimes > 0; --NumberOfTimes)
                    {
                        NewSelf /= self;
                    }
                }
            }
            else
            {//To-Do need to finish remaining power part of code
             //decimal SelfAsDecimal = (decimal) self;
                if (Value.intValue == 0)
                {
                    NewSelf.intValue = 1;
                    NewSelf.DecBoolStatus = 0;
                }
                else if (Value.DecBoolStatus == 0)
                {
                    for (ushort NumberOfTimes = Value.intValue; NumberOfTimes > 0; --NumberOfTimes)
                    {
                        NewSelf *= self;
                    }
                }
                else
                {
                    for (ushort NumberOfTimes = Value.intValue; NumberOfTimes > 0; --NumberOfTimes)
                    {
                        NewSelf /= self;
                    }
                }
                //Now need to deal with the remaining "power"
                Value.intValue = 0;
                //Number is less then NewSelf Currently is (Sloping Curve in closeness to next power)
                double TempDouble = Math.Pow((double)self, (double)Value);
                if (Value.DecBoolStatus == 0)
                {
                    NewSelf *= TempDouble;
                }
                else
                {
                    NewSelf /= TempDouble;
                }
            }
            return NewSelf;
        }

        /// <summary>
        /// SmallDec version of Math.Exp(double Value)
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static SmallDec Exp(SmallDec Value)
        {
            double SelfAsDecimal = (double)Value;
            SelfAsDecimal = Math.Exp(SelfAsDecimal);
            return (SmallDec)SelfAsDecimal;
        }
    }
}
