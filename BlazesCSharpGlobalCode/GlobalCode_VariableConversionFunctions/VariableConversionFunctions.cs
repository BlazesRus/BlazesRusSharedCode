using CSharpGlobalCode.GlobalCode_ExperimentalCode;
using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpGlobalCode.GlobalCode_VariableConversionFunctions
{
    struct VariableConversionFunctions
    {
        //************************************
        // Method:    NumberOfPlaces
        // FullName:  VariableConversionFunctions::NumberOfPlaces
        // Access:    public static 
        // Returns:   sbyte
        // Qualifier:
        // Parameter: int Value
        //************************************
        public static sbyte NumberOfPlaces(dynamic Value)
        {
            sbyte NumberOfPlaces = (sbyte) Math.Floor(Math.Log10(Value));
            return NumberOfPlaces;
        }
        //************************************
        // Method:    NumberOfDecimalPlaces
        // FullName:  VariableConversionFunctions::NumberOfDecimalPlaces
        // Access:    public static 
        // Returns:   signed byte
        // Qualifier:
        // Parameter: int Value
        //************************************
        public static sbyte NumberOfDecimalPlaces(dynamic Value)
        {
            sbyte NumberOfPlaces = (sbyte) Math.Floor(Math.Log(Value));
            NumberOfPlaces *= -1;
            NumberOfPlaces += 1;
            return NumberOfPlaces;
        }
        //************************************
        // Method:    NumberOfDecimalPlaces
        // FullName:  VariableConversionFunctions::NumberOfDecimalPlaces
        // Access:    public static 
        // Returns:   int
        // Qualifier:
        // Parameter: double Value
        //************************************
        public static sbyte NumberOfDecimalPlaces(double Value)
        {
            sbyte NumberOfPlaces = (sbyte) Math.Floor(Math.Log(Value));
            NumberOfPlaces *= -1;
            NumberOfPlaces += 1;
            return NumberOfPlaces;
        }
        
        //************************************
        // Method:    CharAsInt
        // FullName:  VariableConversionFunctions::CharAsInt
        // Access:    public static 
        // Returns:   int
        // Qualifier:
        // Parameter: char Temp
        //************************************
        public static dynamic CharAsInt(char Temp)
        {
            int Value = 0;
            switch (Temp)
            {
                case '0':
                    Value = 0;
                    break;
                case '1':
                    Value = 1;
                    break;
                case '2':
                    Value = 2;
                    break;
                case '3':
                    Value = 3;
                    break;
                case '4':
                    Value = 4;
                    break;
                case '5':
                    Value = 5;
                    break;
                case '6':
                    Value = 6;
                    break;
                case '7':
                    Value = 7;
                    break;
                case '8':
                    Value = 8;
                    break;
                case '9':
                    Value = 9;
                    break;
            }

            return Value;
        }
        //************************************
        // Method:    DigitAsChar
        // FullName:  VariableConversionFunctions::DigitAsChar
        // Access:    public static 
        // Returns:   char
        // Qualifier:
        // Parameter: int Temp
        //************************************
        public static char DigitAsChar(dynamic Temp)
        {
            char Value = '0';
            switch ((int)Temp)
            {
                case 0:
                    Value = '0';
                    break;
                case 1:
                    Value = '1';
                    break;
                case 2:
                    Value = '2';
                    break;
                case 3:
                    Value = '3';
                    break;
                case 4:
                    Value = '4';
                    break;
                case 5:
                    Value = '5';
                    break;
                case 6:
                    Value = '6';
                    break;
                case 7:
                    Value = '7';
                    break;
                case 8:
                    Value = '8';
                    break;
                case 9:
                    Value = '9';
                    break;
            }

            return Value;
        }

        //************************************
        // Method:    IsDigit
        // FullName:  VariableConversionFunctions::IsDigit
        // Access:    public static 
        // Returns:   bool
        // Qualifier:
        // Parameter: char Temp
        //************************************
        public static bool IsDigit(char Temp)
        {
            bool DigitType = false;
            if(Temp == '0') { DigitType = true; }
            else if(Temp == '1') { DigitType = true; }
            else if(Temp == '2') { DigitType = true; }
            else if(Temp == '3') { DigitType = true; }
            else if(Temp == '4') { DigitType = true; }
            else if(Temp == '5') { DigitType = true; }
            else if(Temp == '6') { DigitType = true; }
            else if(Temp == '7') { DigitType = true; }
            else if(Temp == '8') { DigitType = true; }
            else if(Temp == '9') { DigitType = true; }
            return DigitType;
        }
        //************************************
        // Method:    IsDigit
        // FullName:  VariableConversionFunctions::IsDigit
        // Access:    public static 
        // Returns:   bool
        // Qualifier:
        // Parameter: string Temp
        //************************************
        public static bool IsDigit(string Temp)
        {
            return IsDigit(Temp[0]);
        }
        ////Returns Double Value version of String
        ////************************************
        //// Method:    ReadDoubleFromString
        //// FullName:  VariableConversionFunctions::ReadDoubleFromString
        //// Access:    public static 
        //// Returns:   double
        //// Qualifier:
        //// Parameter: string TempString
        ////************************************
        //static double ReadDoubleFromString(string TempString);
        ////Returns Integer value version of String
        ////************************************
        //// Method:    ReadIntFromString
        //// FullName:  VariableConversionFunctions::ReadIntFromString
        //// Access:    public static 
        //// Returns:   int
        //// Qualifier:
        //// Parameter: string TempString
        ////************************************
        //static int ReadIntFromString(string TempString);
        ////Returns first string of either true,false,1, or 0 in string; if no value found returns false
        ////************************************
        //// Method:    ReadBoolFromString
        //// FullName:  VariableConversionFunctions::ReadBoolFromString
        //// Access:    public static 
        //// Returns:   bool
        //// Qualifier:
        //// Parameter: string LineString
        ////************************************
        //static bool ReadBoolFromString(string LineString);
        ////Returns long long int value from string(int 64 bit)
        ////************************************
        //// Method:    ReadXIntFromString
        //// FullName:  VariableConversionFunctions::ReadXIntFromString
        //// Access:    public static 
        //// Returns:   long long int
        //// Qualifier:
        //// Parameter: string TempString
        ////************************************
        //static long long int ReadXIntFromString(string TempString);
        ////************************************
        //// Scan int for bool value
        //// Method:    ReadBoolFromInt
        //// FullName:  VariableConversionFunctions::ReadBoolFromInt
        //// Access:    public static 
        //// Returns:   bool
        //// Qualifier:
        //// Parameter: int Temp
        ////************************************
        //static bool ReadBoolFromInt(int Temp);
        ////************************************
        //// Method:    DoubleAsString
        //// FullName:  VariableConversionFunctions::DoubleAsString
        //// Access:    public static 
        //// Returns:   string
        //// Qualifier:
        //// Parameter: double TempValue
        ////************************************
        //static string DoubleAsString(double TempValue);
        ////************************************
        //// Method:    BoolAsString
        //// FullName:  VariableConversionFunctions::BoolAsString
        //// Access:    public static 
        //// Returns:   string
        //// Qualifier:
        //// Parameter: bool TempValue
        ////************************************
        //static string BoolAsString(bool TempValue);
        //************************************
        // Method:    DoubleToStringConversion
        // FullName:  VariableConversionFunctions::DoubleToStringConversion
        // Access:    public static 
        // Returns:   string
        // Qualifier:
        // Parameter: double TempValue
        //************************************
        static string DoubleToStringConversion(double TempValue)
        {
            System.String Value = "";
            if (TempValue<0) { Value += "-"; TempValue *=-1;}
            uint IntegerHalf = (uint) TempValue;
            byte CurrentDigit;
            for(sbyte Index= NumberOfPlaces(IntegerHalf);Index>=0;Index--)
            {
                CurrentDigit = (byte)(IntegerHalf / SuperDecGlobalCode.PowerOfTens[Index]);
                IntegerHalf -= (uint) (CurrentDigit * SuperDecGlobalCode.PowerOfTens[Index]);
                Value += DigitAsChar(CurrentDigit);
            }
            Value += ".";
            double DecimalHalf = TempValue - IntegerHalf;
            sbyte DecimalPlaces = NumberOfDecimalPlaces(DecimalHalf);
            for(byte Index = 0; Index < DecimalPlaces; ++Index)
            {
                CurrentDigit = (byte) Math.Floor(DecimalHalf* SuperDecGlobalCode.PowerOfTens[Index+1]);
                Value += DigitAsChar(CurrentDigit);
            }
            return Value;
        }
        /// <summary>
        /// Attempts to extract value of decimal half as ulong (19 decimals worth extracted)
        /// </summary>
        /// <param name="TempValue"></param>
        /// <returns></returns>
        public static ulong ExtractDecimalHalf(double TempValue)
        {
            ulong DecimalHalf = 0;
            ulong TempStorage;
            double CurrentDecimalSection;
            byte CurrentDigit;
            byte ValueDigit = 18;
            for (byte Index = 0; Index < 19; ++Index)
            {
                CurrentDigit = (byte)Math.Floor(TempValue * SuperDecGlobalCode.PowerOfTens[Index+1]);
                CurrentDecimalSection = CurrentDigit * SuperDecGlobalCode.PowerOfTens[(Index * -1) - 1];
                TempStorage = (ulong) (SuperDecGlobalCode.PowerOfTens[Index]) * CurrentDigit;
                //Console.WriteLine("Index:" + Index + " CurrentDecimalSection:" + CurrentDecimalSection + " CurrentDigit:" + CurrentDigit + " TempStorage:" + TempStorage);
                TempValue -= CurrentDecimalSection;
                DecimalHalf += TempStorage;
                --ValueDigit;
            }
            return DecimalHalf;
        }
        
        //9 Decimal Storage version of ExtractDecimalHalf
        public static uint ExtractDecimalHalfV2(double TempValue)
        {
            uint DecimalHalf = 0;
            uint TempStorage;
            double CurrentDecimalSection;
            byte CurrentDigit;
            byte ValueDigit = 8;
            for (byte Index = 0; Index < 9; ++Index)
            {
                CurrentDigit = (byte)Math.Floor(TempValue * (10 * SuperDecGlobalCode.PowerOfTens[Index]));
                CurrentDecimalSection = CurrentDigit * SuperDecGlobalCode.PowerOfTens[(Index * -1) - 1];
                TempStorage = (uint) (SuperDecGlobalCode.PowerOfTens[Index]) * CurrentDigit;
                //Console.WriteLine("Index:" + Index + " CurrentDecimalSection:" + CurrentDecimalSection + " CurrentDigit:" + CurrentDigit + " TempStorage:" + TempStorage);
                TempValue -= CurrentDecimalSection;
                DecimalHalf += TempStorage;
                --ValueDigit;
            }
            return DecimalHalf;
        }

        //9 Decimal Storage version of ExtractDecimalHalf
        public static ushort ExtractDecimalHalfV3(double TempValue)
        {
            ushort DecimalHalf = 0;
            ushort TempStorage;
            double CurrentDecimalSection;
            byte CurrentDigit;
            byte ValueDigit = 3;
            for (byte Index = 0; Index < 4; ++Index)
            {
                CurrentDigit = (byte)Math.Floor(TempValue * (10 * SuperDecGlobalCode.PowerOfTens[Index]));
                CurrentDecimalSection = CurrentDigit * SuperDecGlobalCode.PowerOfTens[(Index*-1)-1];
                TempStorage = (ushort)(SuperDecGlobalCode.PowerOfTens[Index] * CurrentDigit);
                //Console.WriteLine("Index:" + Index + " CurrentDecimalSection:" + CurrentDecimalSection + " CurrentDigit:" + CurrentDigit + " TempStorage:" + TempStorage);
                TempValue -= CurrentDecimalSection;
                DecimalHalf += TempStorage;
                --ValueDigit;
            }
            return DecimalHalf;
        }

        //************************************
        // Method:    IntToStringConversion
        // FullName:  VariableConversionFunctions::IntToStringConversion
        // Access:    public static 
        // Returns:   string
        // Qualifier:
        // Parameter: int TempValue
        //************************************
        public static string IntToStringConversion(dynamic TempValue)
        {
            var Value = "";
            if (TempValue < 0) { Value += "-"; TempValue *= -1; }
            uint IntegerHalf = TempValue;
            byte CurrentDigit;
            var builder = new StringBuilder();
            builder.Append(Value);
            for (sbyte Index = NumberOfPlaces(IntegerHalf); Index >= 0; --Index)
            {
                CurrentDigit = (byte)(IntegerHalf / SuperDecGlobalCode.PowerOfTens[Index]);
                IntegerHalf -= (uint)(CurrentDigit * SuperDecGlobalCode.PowerOfTens[Index]);
                builder.Append(DigitAsChar(CurrentDigit));
            }
            Value = builder.ToString();
            return Value;
        }
        //string DisplayFullValues_Vector(float x, float y, float z, float w);
        //string DisplayFullValues_Vector(float x, float y, float z);
        //string DisplayFullValues_Vector(float x, float y);
        //string DisplayFullValues(float x, float y, float z, float w);
        //string DisplayFullValues(float x, float y, float z);
        //string DisplayFullValues(float x, float y);

        public static string DoubleToStringV2(double Value)
        {
            uint IntegerHalf = (uint) Value;
            byte CurrentDigit;
            //if (self.DecBoolStatus == 1) { Value += "-"; }
            var builder = new StringBuilder();
            builder.Append("");
            for (sbyte Index = NumberOfPlaces(IntegerHalf); Index >= 0; --Index)
            {
                CurrentDigit = (byte)(IntegerHalf / SuperDecGlobalCode.PowerOfTens[Index]);
                IntegerHalf -= (uint)(CurrentDigit * SuperDecGlobalCode.PowerOfTens[Index]);
                builder.Append(DigitAsChar(CurrentDigit));
            }
            builder.Append(".");

            return builder.ToString();
        }


    }
}
