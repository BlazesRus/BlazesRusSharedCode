/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.ExperimentalCode.MediumDec
namespace CSharpGlobalCode.ExperimentalCode
{
    using System.ComponentModel;

    // Represents +- 4294967295.999999999 with 100% consistency of accuracy
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


        ///// <summary>
        ///// </summary>
        ///// <param name="val"></param>
        ///// <returns></returns>
        //public static MediumDec Round(MediumDec val)
        //{
        //    return val.Round();
        //}

        ///// <summary>
        ///// </summary>
        ///// <param name="value"></param>
        ///// <param name="Precision"></param>
        ///// <returns></returns>
        //public static MediumDec Round(MediumDec value, int Precision)
        //{
        //    if (Precision == 0)
        //    {
        //        return value.Round();
        //    }
        //    else
        //    {
        //        return MediumDec.Round(value, 1, MidpointRounding.AwayFromZero);
        //    }
        //}

        ///// <summary>
        ///// </summary>
        ///// <param name="value"></param>
        ///// <param name="precision"></param>
        ///// <returns></returns>
        //public static MediumDec RoundHalfDownValue(MediumDec value, int precision)
        //{
        //    if (precision == 0)
        //    {
        //        return value.Floor();
        //    }
        //    else
        //    {
        //        return MediumDec.Round(value, precision, 1);
        //    }
        //}

        ///// <summary>
        ///// </summary>
        ///// <returns></returns>
        //public MediumDec Round()
        //{
        //    if (DecimalStatus >= 5000) { this.intValue += 1; }
        //    this.DecimalStatus = 0;
        //    return this;
        //}

        ///// <summary>
        ///// </summary>
        ///// <returns></returns>
        //public MediumDec RoundToNonZero()
        //{
        //    if (DecimalStatus >= 5000) { this.intValue += 1; }
        //    if (this.intValue == 0) { this.intValue = 1; }
        //    this.DecimalStatus = 0;
        //    return this;
        //}

        ///// <summary>
        ///// </summary>
        ///// <param name="value"></param>
        ///// <param name="precision"></param>
        ///// <param name="RoundingMethod"></param>
        ///// <returns></returns>
        //public static MediumDec Round(MediumDec value, int precision, int RoundingMethod)
        //{//https://en.wikipedia.org/wiki/Rounding
        //    if (precision >= 4)
        //    {//X.XXXX
        //        return value;
        //    }
        //    else if (precision == 3)
        //    {//X.XXX0
        //        ushort NonRoundedPart = (ushort)(value.DecimalStatus / 10);
        //        NonRoundedPart *= 10;
        //        ushort RoundSection = (ushort)(value.DecimalStatus - NonRoundedPart);
        //        MediumDec NewValue = value;
        //        NewValue.DecimalStatus = NonRoundedPart;
        //        if (RoundingMethod == 0) { }
        //        else if (RoundingMethod == 1)
        //        {
        //            if (RoundSection >= 5) { NewValue.DecimalStatus += 10; }
        //            if (NewValue.DecimalStatus > 9999) { NewValue.DecimalStatus -= 10000; NewValue.intValue += 1; }
        //        }
        //        else if (RoundingMethod == 2)
        //        {
        //        }
        //        else if (RoundingMethod == 3)
        //        {
        //        }
        //        else
        //        {
        //        }
        //        return NewValue;
        //    }
        //    else if (precision == 2)
        //    {//X.XX00
        //        ushort NonRoundedPart = (ushort)(value.DecimalStatus / 100);
        //        NonRoundedPart *= 100;
        //        ushort RoundSection = (ushort)(value.DecimalStatus - NonRoundedPart);
        //        MediumDec NewValue = value;
        //        NewValue.DecimalStatus = NonRoundedPart;
        //        if (RoundingMethod == 0) { }
        //        else if (RoundingMethod == 1)
        //        {
        //            if (RoundSection >= 50) { NewValue.DecimalStatus += 100; }
        //            if (NewValue.DecimalStatus > 9999) { NewValue.DecimalStatus -= 10000; NewValue.intValue += 1; }
        //        }
        //        else if (RoundingMethod == 2)
        //        {
        //        }
        //        else if (RoundingMethod == 3)
        //        {
        //        }
        //        else
        //        {
        //        }
        //        return NewValue;
        //    }
        //    else if (precision == 1)
        //    {//X.X000
        //        ushort NonRoundedPart = (ushort)(value.DecimalStatus / 1000);
        //        NonRoundedPart *= 1000;
        //        ushort RoundSection = (ushort)(value.DecimalStatus - NonRoundedPart);
        //        MediumDec NewValue = value;
        //        NewValue.DecimalStatus = NonRoundedPart;
        //        if (RoundingMethod == 0) { }
        //        else if (RoundingMethod == 1)
        //        {
        //            if (RoundSection >= 500) { NewValue.DecimalStatus += 1000; }
        //            if (NewValue.DecimalStatus > 9999) { NewValue.DecimalStatus -= 10000; NewValue.intValue += 1; }
        //        }
        //        else if (RoundingMethod == 2)//Floor Round
        //        {
        //        }
        //        else if (RoundingMethod == 3)
        //        {
        //        }
        //        else//round to nearest
        //        {
        //        }
        //        return NewValue;
        //    }
        //    else
        //    {
        //        switch (RoundingMethod)
        //        {
        //            case 0:

        //                break;

        //            case 1:
        //                break;

        //            case 2:
        //                break;

        //            case 3:
        //                break;

        //            case 4:
        //                break;

        //            default://round to nearest
        //                if (value.DecimalStatus >= 5000) { value.intValue += 1; }
        //                value.DecimalStatus = 0;
        //                break;
        //        }
        //        return value;
        //    }
        //}

        ///// <summary>
        ///// </summary>
        ///// <param name="value"></param>
        ///// <param name="precision"></param>
        ///// <param name="RoundingMethod"></param>
        ///// <returns></returns>
        //public static MediumDec Round(MediumDec value, int precision, MidpointRounding RoundingMethod)
        //{
        //    if (RoundingMethod == MidpointRounding.ToEven) { return Round(value, precision, 0); }
        //    else if (RoundingMethod == MidpointRounding.AwayFromZero)
        //    {
        //        return Round(value, precision, 1);
        //    }
        //    else
        //    {
        //        return Round(value, precision, 2);
        //    }
        //}
    }
}
