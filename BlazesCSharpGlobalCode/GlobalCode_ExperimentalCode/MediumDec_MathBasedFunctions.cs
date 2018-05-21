/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.MediumDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Globalization;
    using System.Windows;
    using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

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
//        /// <summary>
//        /// 
//        /// </summary>
//        /// <param name="self"></param>
//        /// <param name="Value"></param>
//        /// <returns></returns>
//        public static MediumDec Pow(MediumDec self, int Value)
//        {
//            var NewSelf = self;
//            if (Value == 0)
//            {
//                NewSelf.intValue = 1;
//                NewSelf.DecBoolStatus = 0;
//            }
//            else if (Value < 0)
//            {
//                for (int NumberOfTimes = Value; NumberOfTimes > 0; --NumberOfTimes)
//                {
//                    NewSelf /= self;
//                }
//            }
//            else
//            {
//                for (int NumberOfTimes = Value; NumberOfTimes > 0; --NumberOfTimes)
//                {
//                    NewSelf *= self;
//                }
//            }
//            return NewSelf;
//        }

//        //public static MediumDec Pow(double self, double Value) { return MediumDec.Pow((MediumDec)self, (MediumDec)Value); }
//        /// <summary>
//        /// 
//        /// </summary>
//        /// <param name="self"></param>
//        /// <param name="Value"></param>
//        /// <returns></returns>
//        public static MediumDec Pow(MediumDec self, double Value) => MediumDec.Pow(self, (MediumDec)Value);
//#if (BlazesGlobalCode_StandardExplicitConversionFrom)//Gets confused since it tries auto converting to MediumDec inside parameter first
//        public static MediumDec Pow(MediumDec self, MediumDec Value) { return MediumDec.Pow(self, Value); }
//#endif
//        /// <summary>
//        /// Approximate version of Math.Pow(double self, double Value)
//        /// </summary>
//        /// <param name="self"></param>
//        /// <param name="Value"></param>
//        /// <returns></returns>
//        public static MediumDec Pow(MediumDec self, MediumDec Value)
//        {
//            var NewSelf = self;
//            //MediumDec version of Math.Pow()
//            if (Value.DecimalStatus == 0)
//            {
//                if (Value.intValue == 0)
//                {
//                    NewSelf.intValue = 1;
//                    NewSelf.DecBoolStatus = 0;
//                }
//                else if (Value.DecBoolStatus == 0)
//                {
//                    for (ushort NumberOfTimes = Value.intValue; NumberOfTimes > 0; --NumberOfTimes)
//                    {
//                        NewSelf *= self;
//                    }
//                }
//                else
//                {
//                    for (ushort NumberOfTimes = Value.intValue; NumberOfTimes > 0; --NumberOfTimes)
//                    {
//                        NewSelf /= self;
//                    }
//                }
//            }
//            else
//            {//To-Do need to finish remaining power part of code
//             //decimal SelfAsDecimal = (decimal) self;
//                if (Value.intValue == 0)
//                {
//                    NewSelf.intValue = 1;
//                    NewSelf.DecBoolStatus = 0;
//                }
//                else if (Value.DecBoolStatus == 0)
//                {
//                    for (ushort NumberOfTimes = Value.intValue; NumberOfTimes > 0; --NumberOfTimes)
//                    {
//                        NewSelf *= self;
//                    }
//                }
//                else
//                {
//                    for (ushort NumberOfTimes = Value.intValue; NumberOfTimes > 0; --NumberOfTimes)
//                    {
//                        NewSelf /= self;
//                    }
//                }
//                //Now need to deal with the remaining "power"
//                Value.intValue = 0;
//                //Number is less then NewSelf Currently is (Sloping Curve in closeness to next power)
//                double TempDouble = Math.Pow((double)self, (double)Value);
//                if (Value.DecBoolStatus == 0)
//                {
//                    NewSelf *= TempDouble;
//                }
//                else
//                {
//                    NewSelf /= TempDouble;
//                }
//            }
//            return NewSelf;
//        }

//        /// <summary>
//        /// MediumDec version of Math.Exp(double Value)
//        /// </summary>
//        /// <param name="Value"></param>
//        /// <returns></returns>
//        public static MediumDec Exp(MediumDec Value)
//        {
//            double SelfAsDecimal = (double)Value;
//            SelfAsDecimal = Math.Exp(SelfAsDecimal);
//            return (MediumDec)SelfAsDecimal;
//        }
    }
}
