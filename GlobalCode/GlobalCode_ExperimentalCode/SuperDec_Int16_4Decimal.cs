/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
	using System.Collections.Generic;
	using System.Globalization;
	using System.Windows;
	using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

	//Aka SuperDec_Int16_4Decimal
	public struct SmallDec : IComparable<SmallDec>
	{
		//0 = Positive;1=Negative;Other states at higher then 1;254 = Positive Infinity;255 = Negative Infinity
		public byte DecBoolStatus;

		//Stores decimal section info (4 Decimal places stored)
		public ushort DecimalStatus;

		public ushort IntValue;

		public static SmallDec Sum(IEnumerable<SmallDec> Value)
		{
			SmallDec TotalSum = SmallDec.Zero;
			foreach (var Element in Value)
			{
				TotalSum += Element;
			}
			return TotalSum;
		}

		public SmallDec Abs()
		{
			this.DecBoolStatus = 0;
			return this;
		}

		public SmallDec Floor()
		{
			this.DecimalStatus = 0;
			return this;
		}

		public static SmallDec Parse(string value, CultureInfo invariantCulture)
		{
			SmallDec NewValue = SmallDec.StringToValue(value);
			return NewValue;
		}

		// Returns rounded value with all fractional digits after specified precision cut off.
		public static SmallDec Floor(SmallDec value, int precision)
		{
			
			if(precision==0)
			{
				value.DecimalStatus = 0;
			}
			else if(precision==1)
			{
				value.DecimalStatus /= 1000;
				value.DecimalStatus *= 1000;
			}
			else if (precision == 2)
			{
				value.DecimalStatus /= 100;
				value.DecimalStatus *= 100;
			}
			else if (precision == 3)
			{
				value.DecimalStatus /= 10;
				value.DecimalStatus *= 10;
			}
			return value;
			throw new NotImplementedException();
		}

		public SmallDec Ceil()
		{
			if (this.DecimalStatus != 0)
			{
				this.DecimalStatus = 0;
				this.IntValue += 1;
			}
			return this;
		}


		public static SmallDec Pow(SmallDec self, int Value)
		{
			SmallDec NewSelf = self;
			if (Value == 0)
			{
				NewSelf.IntValue = 1;
				NewSelf.DecBoolStatus = 0;
			}
			else if(Value<0)
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

		//public static explicit operator SmallDec(DependencyProperty v)
		//{
		//	throw new NotImplementedException();
		//}

		public static SmallDec Pow(double self, double Value) { return SmallDec.Pow((SmallDec)self, (SmallDec)Value); }
		public static SmallDec Pow(SmallDec self, double Value) { return SmallDec.Pow(self, (SmallDec)Value); }
		public static SmallDec Pow(SmallDec self, float Value) { return SmallDec.Pow(self, (SmallDec)Value); }

		//Approximate version of Math.Pow(double self, double Value)
		public static SmallDec Pow(SmallDec self, SmallDec Value)
		{
			SmallDec NewSelf = self;
			//SmallDec version of Math.Pow()
			if (Value.DecimalStatus == 0)
			{
				if (Value.IntValue == 0)
				{
					NewSelf.IntValue = 1;
					NewSelf.DecBoolStatus = 0;
				}
				else if (Value.DecBoolStatus == 0)
				{
					for (ushort NumberOfTimes = Value.IntValue; NumberOfTimes > 0; --NumberOfTimes)
					{
						NewSelf *= self;
					}
				}
				else
				{
					for (ushort NumberOfTimes = Value.IntValue; NumberOfTimes > 0; --NumberOfTimes)
					{
						NewSelf /= self;
					}
				}
			}
			else
			{//To-Do need to finish remaining power part of code
			 //decimal SelfAsDecimal = (decimal) self;
				if (Value.IntValue == 0)
				{
					NewSelf.IntValue = 1;
					NewSelf.DecBoolStatus = 0;
				}
				else if (Value.DecBoolStatus == 0)
				{
					for (ushort NumberOfTimes = Value.IntValue; NumberOfTimes > 0; --NumberOfTimes)
					{
						NewSelf *= self;
					}
				}
				else
				{
					for (ushort NumberOfTimes = Value.IntValue; NumberOfTimes > 0; --NumberOfTimes)
					{
						NewSelf /= self;
					}
				}
				//Now need to deal with the remaining "power"
				Value.IntValue = 0;
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

		//SmallDec version of Math.Exp(double Value)
		public static SmallDec Exp(SmallDec Value)
		{
			double SelfAsDecimal = (double)Value;
			SelfAsDecimal = Math.Exp(SelfAsDecimal);
			return (SmallDec)SelfAsDecimal;
		}

		public static SmallDec Max(dynamic LeftSide, dynamic RightSide)
		{
			SmallDec LeftSideAsType = (SmallDec)LeftSide;
			SmallDec RightSideAsType = (SmallDec)RightSide;
			if (LeftSideAsType > RightSide) { return LeftSideAsType; }
			else { return RightSideAsType; }
		}

		public static SmallDec Min(dynamic LeftSide, dynamic RightSide)
		{
			SmallDec LeftSideAsType = (SmallDec)LeftSide;
			SmallDec RightSideAsType = (SmallDec)RightSide;
			if (LeftSideAsType < RightSide) { return LeftSideAsType; }
			else { return RightSideAsType; }
		}

		public static SmallDec Round(SmallDec val)
		{
			return val.Round();
		}

		public static SmallDec Round(SmallDec value, int Precision)
		{
			if(Precision==0)
			{
				return value.Round();
			}
			else
			{
				return SmallDec.Round(value, 1, MidpointRounding.AwayFromZero);
			}
		}

		public static SmallDec RoundHalfDownValue(SmallDec value, int precision)
		{
			if (precision == 0)
			{
				return value.Floor();
			}
			else
			{
				return SmallDec.Round(value, precision, 1);
			}
		}

		public SmallDec Round()
		{
			if (DecimalStatus >= 5000) { this.IntValue += 1; }
			this.DecimalStatus = 0;
			return this;
		}

		public SmallDec RoundToNonZero()
		{
			if (DecimalStatus >= 5000) { this.IntValue += 1; }
			if (this.IntValue == 0) { this.IntValue = 1; }
			this.DecimalStatus = 0;
			return this;
		}

		public static SmallDec Round(SmallDec value, int precision, int RoundingMethod)
		{//https://en.wikipedia.org/wiki/Rounding
			if (precision >= 4)
			{//X.XXXX
				return value;
			}
			else if (precision == 3)
			{//X.XXX0
				ushort NonRoundedPart = (ushort)(value.DecimalStatus / 10);
				NonRoundedPart *= 10;
				ushort RoundSection = (ushort)(value.DecimalStatus - NonRoundedPart);
				SmallDec NewValue = value;
				NewValue.DecimalStatus = NonRoundedPart;
				if (RoundingMethod == 0) { }
				else if (RoundingMethod == 1)
				{
					if (RoundSection >= 5) { NewValue.DecimalStatus += 10; }
					if (NewValue.DecimalStatus > 9999) { NewValue.DecimalStatus -= 10000; NewValue.IntValue += 1; }
				}
				return NewValue;
			}
			else if (precision == 2)
			{//X.XX00
				ushort NonRoundedPart = (ushort)(value.DecimalStatus / 100);
				NonRoundedPart *= 100;
				ushort RoundSection = (ushort)(value.DecimalStatus - NonRoundedPart);
				SmallDec NewValue = value;
				NewValue.DecimalStatus = NonRoundedPart;
				if (RoundingMethod == 0) { }
				else if (RoundingMethod == 1)
				{
					if (RoundSection >= 50) { NewValue.DecimalStatus += 100; }
					if (NewValue.DecimalStatus > 9999) { NewValue.DecimalStatus -= 10000; NewValue.IntValue += 1; }
				}
				return NewValue;
			}
			else if (precision == 1)
			{//X.X000
				ushort NonRoundedPart = (ushort)(value.DecimalStatus / 1000);
				NonRoundedPart *= 1000;
				ushort RoundSection = (ushort)(value.DecimalStatus - NonRoundedPart);
				SmallDec NewValue = value;
				NewValue.DecimalStatus = NonRoundedPart;
				if (RoundingMethod == 0) { }
				else if (RoundingMethod == 1)
				{
					if (RoundSection >= 500) { NewValue.DecimalStatus += 1000; }
					if (NewValue.DecimalStatus > 9999) { NewValue.DecimalStatus -= 10000; NewValue.IntValue += 1; }
				}
				else if(RoundingMethod==2)//Floor Round
				{

				}
				else if(RoundingMethod==3)
				{

				}
				else//round to nearest
				{

				}
				return NewValue;
			}
			else
			{
				switch (RoundingMethod)
				{
					case 0:

						break;
					case 1:
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					default://round to nearest
						if (value.DecimalStatus >= 5000) { value.IntValue += 1; }
						value.DecimalStatus = 0;
						break;
				}
				return value;
			}
		}

		public static SmallDec Round(SmallDec value, int precision, MidpointRounding RoundingMethod)
		{
			if (RoundingMethod == MidpointRounding.ToEven) { return Round(value, precision, 0); }
			else if (RoundingMethod == MidpointRounding.AwayFromZero)
			{
				return Round(value, precision, 1);
			}
			else
			{
				return Round(value, precision, 2);
			}
		}

		//public SmallDec Convert(SuperDec_ExtraDec32_19Decimal Value)
		//{
		//	SmallDec NewSelf;
		//	NewSelf.IntValue = (ushort)Value.IntValue;
		//	ulong TempDec = Value.DecimalStatus;
		//	TempDec /= 1000000000000000;
		//	NewSelf.DecimalStatus = (ushort)TempDec;
		//	NewSelf.DecBoolStatus = Value.DecBoolStatus;
		//	return NewSelf;
		//}

		//public SmallDec Convert(SuperDec_ExtraDec64_19Decimal Value)
		//{
		//	SmallDec NewSelf;
		//	NewSelf.IntValue = (ushort)Value.IntValue;
		//	ulong TempDec = Value.DecimalStatus / 100000000000000;
		//	NewSelf.DecimalStatus = (ushort)TempDec;
		//	NewSelf.DecBoolStatus = Value.DecBoolStatus;
		//	return NewSelf;
		//}

		public static SmallDec operator -(SmallDec Value)
		{//Place DecBoolStatus>1 checks above in V2 of type
			if (Value.DecBoolStatus == 1)
			{
				Value.DecBoolStatus = 0;
			}//No negative zero
			else if ((Value.DecimalStatus == 0 && Value.IntValue == 0) == false)
			{
				Value.DecBoolStatus = 1;
			}
			return Value;
		}

		////Limit CSharpGlobalCode.GlobalCode_ExperimentalCode explicit Conversions from other type to self (no OtherType(SelfType) explicit conversions)
		//public static SmallDec operator +(SmallDec self, SuperDec_ExtraDec32_19Decimal y)
		//{
		//	self += (SmallDec)y;
		//	return self;
		//}

		//public static SmallDec operator -(SmallDec self, SuperDec_ExtraDec32_19Decimal y)
		//{
		//	self -= (SmallDec)y;
		//	return self;
		//}

		//public static SmallDec operator *(SmallDec self, SuperDec_ExtraDec32_19Decimal y)
		//{
		//	self *= (SmallDec)y;
		//	return self;
		//}

		//public static SmallDec operator /(SmallDec self, SuperDec_ExtraDec32_19Decimal y)
		//{
		//	self /= (SmallDec)y;
		//	return self;
		//}

		//public static explicit operator SmallDec(SuperDec_Int32_9Decimal Value)
		//{
		//	return new SmallDec(Value);
		//}

		//public static explicit operator SmallDec(SuperDec_ExtraDec32_19Decimal Value)
		//{
		//	return new SmallDec().Convert(Value);
		//}

		//public static explicit operator SmallDec(SuperDec_ExtraDec64_19Decimal Value)
		//{
		//	return new SmallDec().Convert(Value);
		//}

		public static SmallDec StringToValue(string Value)
		{
			SmallDec NewSelf;
			NewSelf.IntValue = 0;
			NewSelf.DecimalStatus = 0;
			NewSelf.DecBoolStatus = 0;
			sbyte PlaceNumber;
			byte StringLength = (byte)Value.Length;
			string WholeNumberBuffer = "";
			string DecimalBuffer = "";
			bool ReadingDecimal = false;
			int TempInt;
			int TempInt02;
			foreach (char StringChar in Value)
			{
				if (IsDigit(StringChar))
				{
					if (ReadingDecimal)
					{
						DecimalBuffer += StringChar;
					}
					else
					{
						WholeNumberBuffer += StringChar;
					}
				}
				else if (StringChar == '-')
				{
					NewSelf.DecBoolStatus = 1;
				}
				else if (StringChar == '.')
				{
					ReadingDecimal = true;
				}
			}
			PlaceNumber = (sbyte)(WholeNumberBuffer.Length - 1);
			foreach (char StringChar in WholeNumberBuffer)
			{
				TempInt = CharAsInt(StringChar);
				TempInt02 = (ushort)(TempInt * Math.Pow(10, PlaceNumber));
				if (StringChar != '0')
				{
					NewSelf.IntValue += (ushort)TempInt02;
				}
				PlaceNumber--;
			}
			PlaceNumber = 3;
			foreach (char StringChar in DecimalBuffer)
			{
				//Limit stored decimal numbers to the amount it can store
				if (PlaceNumber > -1)
				{
					TempInt = CharAsInt(StringChar);
					TempInt02 = (ushort)(TempInt * Math.Pow(10, PlaceNumber));
					if (StringChar != '0')
					{
						NewSelf.DecimalStatus += (ushort)TempInt02;
					}
					PlaceNumber--;
				}
			}
			return NewSelf;
		}

		//Method version to Initialize Type instead of with Explicit operators
		public static SmallDec Initialize(dynamic Value)
		{
			return new SmallDec(Value);
		}

		public SmallDec(dynamic Value)
		{
			if (Value is string)
			{
				IntValue = 0;
				DecimalStatus = 0;
				DecBoolStatus = 0;
				sbyte PlaceNumber;
				byte StringLength = (byte)Value.Length;
				string WholeNumberBuffer = "";
				string DecimalBuffer = "";
				bool ReadingDecimal = false;
				int TempInt;
				int TempInt02;
				foreach (char StringChar in Value)
				{
					if (IsDigit(StringChar))
					{
						if (ReadingDecimal)
						{
							DecimalBuffer += StringChar;
						}
						else
						{
							WholeNumberBuffer += StringChar;
						}
					}
					else if (StringChar == '-')
					{
						DecBoolStatus = 1;
					}
					else if (StringChar == '.')
					{
						ReadingDecimal = true;
					}
				}
				PlaceNumber = (sbyte)(WholeNumberBuffer.Length - 1);
				foreach (char StringChar in WholeNumberBuffer)
				{
					TempInt = CharAsInt(StringChar);
					TempInt02 = (ushort)(TempInt * Math.Pow(10, PlaceNumber));
					if (StringChar != '0')
					{
						IntValue += (ushort)TempInt02;
					}
					PlaceNumber--;
				}
				PlaceNumber = 3;
				foreach (char StringChar in DecimalBuffer)
				{
					//Limit stored decimal numbers to the amount it can store
					if (PlaceNumber > -1)
					{
						TempInt = CharAsInt(StringChar);
						TempInt02 = (ushort)(TempInt * Math.Pow(10, PlaceNumber));
						if (StringChar != '0')
						{
							DecimalStatus += (ushort)TempInt02;
						}
						PlaceNumber--;
					}
				}
			}
			//else if (Value is SuperDec_Int32_9Decimal)
			//{
			//	IntValue = (ushort)Value.IntValue;
			//	uint TempDec = Value.DecimalStatus / 100000;
			//	DecimalStatus = (ushort)TempDec;
			//	DecBoolStatus = Value.DecBoolStatus;
			//}
			//else if (Value is SuperDec_ExtraDec32_19Decimal)
			//{
			//	IntValue = (ushort)Value.IntValue;
			//	ulong TempDec = Value.DecimalStatus / 100000000000000;
			//	DecimalStatus = (ushort)TempDec;
			//	DecBoolStatus = Value.DecBoolStatus;
			//}
			//else if (Value is SuperDec_ExtraDec64_19Decimal)
			//{
			//	IntValue = (ushort)Value.IntValue;
			//	ulong TempDec = Value.DecimalStatus / 100000000000000;
			//	DecimalStatus = (ushort)TempDec;
			//	DecBoolStatus = Value.DecBoolStatus;
			//}
			else if (Value is decimal)
			{
				if (Value < 0)
				{
					Value *= -1;
					DecBoolStatus = 1;
				}
				else
				{
					DecBoolStatus = 0;
				}
				ulong WholeValue = (ulong)Math.Floor(Value);
				//Cap value if too big on initialize (preventing overflow on conversion)
				if (Value > 65535)
				{
					Value = 65535;
				}
				Value -= WholeValue;
				IntValue = (ushort)WholeValue;
				DecimalStatus = (ushort)(Value * 10000);
			}
			else if (Value is double || Value is float)
			{
				if (Value < 0)
				{
					Value *= -1;
					DecBoolStatus = 1;
				}
				else
				{
					DecBoolStatus = 0;
				}
				ulong WholeValue = (ulong)Math.Floor(Value);
				//Cap value if too big on initialize (preventing overflow on conversion)
				if (Value > 65535)
				{
					Value = 65535;
				}
				Value -= WholeValue;
				IntValue = (ushort)WholeValue;
				DecimalStatus = ExtractDecimalHalfV3(Value);
			}
			else if (Value is sbyte || Value is ushort || Value is int || Value is long)
			{
				if (Value < 0)
				{
					this.DecBoolStatus = 1;
					Value *= -1;
				}
				else
				{
					this.DecBoolStatus = 0;
				}
				//Cap value if too big on initialize
				if (Value > 65535)
				{
					Value = 65535;
				}
				this.DecBoolStatus = 0;
				this.IntValue = (ushort)Value;
				this.DecimalStatus = 0;
			}
			else
			{
				//Cap value if too big on initialize
				if (Value > 65535)
				{
					Value = 65535;
				}
				this.DecBoolStatus = 0;
				this.IntValue = (ushort)Value;
				this.DecimalStatus = 0;
			}
		}

		public static explicit operator decimal(SmallDec self)
		{
			decimal Value = (decimal)self.IntValue;
			Value += (decimal)(self.DecimalStatus * 0.0001);
			if (self.DecBoolStatus == 1) { Value *= -1; }
			return Value;
		}

		//explicit Conversion from this to double
		public static explicit operator double(SmallDec self)
		{
			double Value = 0.0;
			Value += self.IntValue;
			Value += (self.DecimalStatus * 0.0001);
			if (self.DecBoolStatus == 1) { Value *= -1; }
			return Value;
		}

		public static explicit operator float(SmallDec self)
		{
			float Value = 0.0f;
			Value += self.IntValue;
			Value += (float)(self.DecimalStatus * 0.0001);
			if (self.DecBoolStatus == 1) { Value *= -1; }
			return Value;
		}

		//Explicit/explicit Conversion from this to int
		public static explicit operator int(SmallDec self)
		{
			int Value = (int)self.IntValue;
			if (self.DecimalStatus == 1) { Value *= -1; }
			return Value;
		}

		//Explicit Conversion from this to int 64
		public static explicit operator long(SmallDec self)
		{
			long Value = self.IntValue;
			if (self.DecimalStatus == 1) { Value *= -1; }
			return Value;
		}

		//Explicit Conversion from this to uint
		public static explicit operator uint(SmallDec self)
		{
			return self.IntValue;
		}

		//Explicit Conversion from this to unsigned int 64
		public static explicit operator ulong(SmallDec self)
		{
			return self.IntValue;
		}

		public static explicit operator byte(SmallDec self)
		{
			byte Value = (byte)self.IntValue;
			return Value;
		}

		public static explicit operator sbyte(SmallDec self)
		{
			sbyte Value = (sbyte)self.IntValue;
			if (self.DecimalStatus == 1) { Value *= -1; }
			return Value;
		}

		public static explicit operator ushort(SmallDec self)
		{
			ushort Value = (ushort)self.IntValue;
			return Value;
		}

		public static explicit operator short(SmallDec self)
		{
			short Value = (short)self.IntValue;
			if (self.DecimalStatus == 1) { Value *= -1; }
			return Value;
		}

		static public explicit operator string(SmallDec self)
		{
			System.String Value = "";
			ushort IntegerHalf = self.IntValue;
			byte CurrentDigit;
			if (self.DecBoolStatus == 1) { Value += "-"; }
			for (sbyte Index = NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
			{
				CurrentDigit = (byte)(IntegerHalf / Math.Pow(10, Index));
				IntegerHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
				Value += DigitAsChar(CurrentDigit);
			}
			Value += ".";
			ushort DecimalHalf = self.DecimalStatus;
			for (sbyte Index = 3; Index >= 0; Index--)
			{
				CurrentDigit = (byte)(DecimalHalf / Math.Pow(10, Index));
				DecimalHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
				Value += DigitAsChar(CurrentDigit);
			}
			return Value;
		}

		public static explicit operator SmallDec(decimal Value)
		{
			return new SmallDec(Value);
		}

		public static explicit operator SmallDec(double Value)
		{
			return new SmallDec(Value);
		}

		public static explicit operator SmallDec(float Value)
		{
			return new SmallDec(Value);
		}

		public static explicit operator SmallDec(int Value)
		{
			return new SmallDec(Value);
		}

		public static explicit operator SmallDec(uint Value)
		{
			return new SmallDec(Value);
		}

		public static explicit operator SmallDec(long Value)
		{
			return new SmallDec(Value);
		}

		public static explicit operator SmallDec(ulong Value)
		{
			return new SmallDec(Value);
		}

		public static explicit operator SmallDec(ushort Value)
		{
			return new SmallDec(Value);
		}

		public static explicit operator SmallDec(short Value)
		{
			return new SmallDec(Value);
		}

		public static explicit operator SmallDec(sbyte Value)
		{
			return new SmallDec(Value);
		}

		public static explicit operator SmallDec(byte Value)
		{
			return new SmallDec(Value);
		}

		// Self Less than Value
		public static bool operator <(SmallDec self, SmallDec Value)
		{
			if (self.DecBoolStatus == Value.DecBoolStatus && self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
			else
			{
				// Positive Self <= -Value
				if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return false; }
				// Negative Self <= Value
				else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return true; }
				else
				{
					ulong SelfAsInt = self.IntValue;
					SelfAsInt *= 10000;
					SelfAsInt += self.DecimalStatus;
					ulong ValueAsInt = Value.IntValue;
					ValueAsInt *= 10000;
					ValueAsInt += Value.DecimalStatus;
					//Both are either positive or negative numbers
					if (self.DecBoolStatus == 0)
					{
						return SelfAsInt < ValueAsInt;
					}
					else
					{//Larger number = farther down into negative
						return !(SelfAsInt < ValueAsInt);
					}
				}
			}
		}

		// Self Less than or equal to Value
		public static bool operator <=(SmallDec self, SmallDec Value)
		{
			if (self.DecBoolStatus == Value.DecBoolStatus && self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
			else
			{
				// Positive Self <= -Value
				if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return false; }
				// Negative Self <= Value
				else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return true; }
				else
				{
					uint SelfAsInt = self.IntValue;
					SelfAsInt *= 10000;
					SelfAsInt += self.DecimalStatus;
					uint ValueAsInt = Value.IntValue;
					ValueAsInt *= 10000;
					ValueAsInt += Value.DecimalStatus;
					//Both are either positive or negative numbers
					if (self.DecBoolStatus == 0)
					{
						return SelfAsInt <= ValueAsInt;
					}
					else
					{//Larger number = farther down into negative
						return !(SelfAsInt <= ValueAsInt);
					}
				}
			}
		}

		// Self Greater than Value
		public static bool operator >(SmallDec self, SmallDec Value)
		{
			if (self.DecBoolStatus == Value.DecBoolStatus && self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
			else
			{
				// Positive Self >= -Value
				if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return true; }
				// Negative Self >= Value
				else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return false; }
				else
				{
					uint SelfAsInt = self.IntValue;
					SelfAsInt *= 10000;
					SelfAsInt += self.DecimalStatus;
					uint ValueAsInt = Value.IntValue;
					ValueAsInt *= 10000;
					ValueAsInt += Value.DecimalStatus;
					//Both are either positive or negative numbers
					if (self.DecBoolStatus == 0)
					{
						return SelfAsInt > ValueAsInt;
					}
					else
					{//Larger number = farther down into negative
						return !(SelfAsInt > ValueAsInt);
					}
				}
			}
		}

		// Self Greater than or Equal to Value
		public static bool operator >=(SmallDec self, SmallDec Value)
		{
			if (self.DecBoolStatus == Value.DecBoolStatus && self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
			else
			{
				// Positive Self >= -Value
				if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return true; }
				// Negative Self >= Value
				else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return false; }
				else
				{
					ulong SelfAsInt = self.IntValue;
					SelfAsInt *= 10000;
					SelfAsInt += self.DecimalStatus;
					ulong ValueAsInt = Value.IntValue;
					ValueAsInt *= 10000;
					ValueAsInt += Value.DecimalStatus;
					//Both are either positive or negative numbers
					if (self.DecBoolStatus == 0)
					{
						return SelfAsInt >= ValueAsInt;
					}
					else
					{//Larger number = farther down into negative
						return !(SelfAsInt >= ValueAsInt);
					}
				}
			}
		}

		// Equality operator for comparing self to int type value
		public static bool operator ==(SmallDec self, SmallDec Value)
		{
			if (self.DecBoolStatus == Value.DecBoolStatus && self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
			else { return false; }
		}

		// Inequality operator for comparing self to multiple value types
		public static bool operator !=(SmallDec self, SmallDec Value)
		{
			if (self.DecBoolStatus != Value.DecBoolStatus || self.IntValue != Value.IntValue || self.DecimalStatus != Value.DecimalStatus) { return true; }
			else { return false; }
		}

		// Self Less than Value
		public static bool operator <(SmallDec self, dynamic Value)
		{
			if (Value is SmallDec)
			{
				if (self.DecBoolStatus == Value.DecBoolStatus && self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
				else
				{
					// Positive Self <= -Value
					if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return false; }
					// Negative Self <= Value
					else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return true; }
					else
					{
						ulong SelfAsInt = self.IntValue;
						SelfAsInt *= 10000;
						SelfAsInt += self.DecimalStatus;
						ulong ValueAsInt = Value.IntValue;
						ValueAsInt *= 10000;
						ValueAsInt += Value.DecimalStatus;
						//Both are either positive or negative numbers
						if (self.DecBoolStatus == 0)
						{
							return SelfAsInt < ValueAsInt;
						}
						else
						{//Larger number = farther down into negative
							return !(SelfAsInt < ValueAsInt);
						}
					}
				}
			}
			else if (Value is double)
			{
				if (Value < 0.0 && self.DecBoolStatus == 0) { return false; }
				else if (Value >= 0.0 && self.DecBoolStatus == 1) { return true; }
				else
				{
					Value = Math.Abs(Value);
					ushort WholeHalf = (ushort)Value;
					//Use x Int Operation instead if Value has no decimal places
					if (WholeHalf == Value)
					{
						if (self.DecimalStatus == 0)
						{
							if (self.DecBoolStatus == 0) { return self.IntValue < WholeHalf; }
							else { return !(self.IntValue < WholeHalf); }
						}
						else
						{
							uint SelfAsInt = self.DecimalStatus;
							SelfAsInt += (uint)(self.IntValue * 10000);
							if (self.DecBoolStatus == 0) { return SelfAsInt < (WholeHalf * 1000000000); }
							else { return !(SelfAsInt < (WholeHalf * 1000000000)); }
						}
					}
					else
					{
						Value -= WholeHalf;
						ushort Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalfV3(Value);
						}
						uint SelfAsInt = self.IntValue;
						SelfAsInt *= 10000;
						SelfAsInt += self.DecimalStatus;
						uint ValueAsInt = WholeHalf;
						ValueAsInt *= 10000;
						ValueAsInt += Decimalhalf;
						if (self.DecBoolStatus == 0) { return SelfAsInt < ValueAsInt; }
						else { return !(SelfAsInt < ValueAsInt); }
					}
				}
			}
			else if (Value is String)
			{
				//return (String)Value == (String)self;
				return false;
			}
			else
			{
				if (Value < 0 && self.DecBoolStatus == 0) { return false; }
				else if (Value >= 0 && self.DecBoolStatus == 1) { return true; }
				else
				{
					Value = Math.Abs(Value);
					if (Value == self.IntValue) { return true; }
					else
					{
						//Both are either positive or negative numbers
						if (self.DecBoolStatus == 0)
						{
							return self.IntValue < Value;
						}
						else
						{//Larger number = farther down into negative
							return !(self.IntValue < Value);
						}
					}
				}
			}
		}

		public static bool operator <(dynamic Value, SmallDec self)
		{
			return self > Value;
		}

		// Self Less than or equal to Value
		public static bool operator <=(SmallDec self, dynamic Value)
		{
			if (Value is SmallDec)
			{
				if (self.DecBoolStatus == Value.DecBoolStatus && self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
				else
				{
					// Positive Self <= -Value
					if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return false; }
					// Negative Self <= Value
					else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return true; }
					else
					{
						uint SelfAsInt = self.IntValue;
						SelfAsInt *= 10000;
						SelfAsInt += self.DecimalStatus;
						uint ValueAsInt = Value.IntValue;
						ValueAsInt *= 10000;
						ValueAsInt += Value.DecimalStatus;
						//Both are either positive or negative numbers
						if (self.DecBoolStatus == 0)
						{
							return SelfAsInt <= ValueAsInt;
						}
						else
						{//Larger number = farther down into negative
							return !(SelfAsInt <= ValueAsInt);
						}
					}
				}
			}
			else if (Value is double)
			{
				if (Value < 0.0 && self.DecBoolStatus == 0) { return false; }
				else if (Value >= 0.0 && self.DecBoolStatus == 1) { return true; }
				else
				{
					Value = Math.Abs(Value);
					ushort WholeHalf = (ushort)Value;
					//Use x Int Operation instead if Value has no decimal places
					if (WholeHalf == Value)
					{
						if (self.DecimalStatus == 0)
						{
							if (self.DecBoolStatus == 0) { return self.IntValue <= WholeHalf; }
							else { return !(self.IntValue <= WholeHalf); }
						}
						else
						{
							uint SelfAsInt = self.DecimalStatus;
							SelfAsInt += (uint)(self.IntValue * 10000);
							if (self.DecBoolStatus == 0) { return SelfAsInt <= (uint)(WholeHalf * 1000); }
							else { return !(SelfAsInt <= (uint)(WholeHalf * 10000)); }
						}
					}
					else
					{
						Value -= WholeHalf;
						ushort Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalfV3(Value);
						}
						uint SelfAsInt = self.IntValue;
						SelfAsInt *= 10000;
						SelfAsInt += self.DecimalStatus;
						uint ValueAsInt = WholeHalf;
						ValueAsInt *= 10000;
						ValueAsInt += Decimalhalf;
						if (self.DecBoolStatus == 0) { return SelfAsInt <= ValueAsInt; }
						else { return !(SelfAsInt <= ValueAsInt); }
					}
				}
			}
			else if (Value is String)
			{
				//return (String)Value == (String)self;
				return false;
			}
			else
			{
				if (Value < 0 && self.DecBoolStatus == 0) { return false; }
				else if (Value >= 0 && self.DecBoolStatus == 1) { return true; }
				else
				{
					Value = Math.Abs(Value);
					if (Value == self.IntValue) { return true; }
					else
					{
						//Both are either positive or negative numbers
						if (self.DecBoolStatus == 0)
						{
							return self.IntValue <= Value;
						}
						else
						{//Larger number = farther down into negative
							return !(self.IntValue <= Value);
						}
					}
				}
			}
		}

		public static bool operator <=(dynamic Value, SmallDec self)
		{
			return self >= Value;
		}

		// Self Greater than Value
		public static bool operator >(SmallDec self, dynamic Value)
		{
			if (Value is SmallDec)
			{
				if (self.DecBoolStatus == Value.DecBoolStatus && self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
				else
				{
					// Positive Self >= -Value
					if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return true; }
					// Negative Self >= Value
					else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return false; }
					else
					{
						uint SelfAsInt = self.IntValue;
						SelfAsInt *= 10000;
						SelfAsInt += self.DecimalStatus;
						uint ValueAsInt = Value.IntValue;
						ValueAsInt *= 10000;
						ValueAsInt += Value.DecimalStatus;
						//Both are either positive or negative numbers
						if (self.DecBoolStatus == 0)
						{
							return SelfAsInt > ValueAsInt;
						}
						else
						{//Larger number = farther down into negative
							return !(SelfAsInt > ValueAsInt);
						}
					}
				}
			}
			else if (Value is double)
			{
				// Positive Self >= -Value
				if (Value < 0.0 && self.DecBoolStatus == 0) { return true; }
				// Negative Self >= Value
				else if (Value >= 0.0 && self.DecBoolStatus == 1) { return false; }
				else
				{
					Value = Math.Abs(Value);
					ushort WholeHalf = (ushort)Value;
					//Use x Int Operation instead if Value has no decimal places
					if (WholeHalf == Value)
					{
						if (self.DecimalStatus == 0)
						{
							if (self.DecBoolStatus == 0) { return self.IntValue > WholeHalf; }
							else { return !(self.IntValue > WholeHalf); }
						}
						else
						{
							uint SelfAsInt = self.DecimalStatus;
							SelfAsInt += (uint)(self.IntValue * 10000);
							if (self.DecBoolStatus == 0) { return SelfAsInt > (uint)(WholeHalf * 10000); }
							else { return !(SelfAsInt > (uint)(WholeHalf * 10000)); }
						}
					}
					else
					{
						Value -= WholeHalf;
						ushort Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalfV3(Value);
						}
						uint SelfAsInt = self.IntValue;
						SelfAsInt *= 10000;
						SelfAsInt += self.DecimalStatus;
						uint ValueAsInt = WholeHalf;
						ValueAsInt *= 10000;
						ValueAsInt += Decimalhalf;
						if (self.DecBoolStatus == 0) { return SelfAsInt >= ValueAsInt; }
						else { return !(SelfAsInt > ValueAsInt); }
					}
				}
			}
			else if (Value is String)
			{
				//return (String)Value == (String)self;
				return false;
			}
			else
			{
				// Positive Self >= -Value
				if (Value < 0 && self.DecBoolStatus == 0) { return true; }
				// Negative Self >= Value
				else if (Value >= 0 && self.DecBoolStatus == 1) { return false; }
				else
				{
					Value = Math.Abs(Value);
					if (Value == self.IntValue) { return false; }
					else
					{
						//Both are either positive or negative numbers
						if (self.DecBoolStatus == 0)
						{
							return self.IntValue > Value;
						}
						else
						{//Larger number = farther down into negative
							return !(self.IntValue > Value);
						}
					}
				}
			}
		}

		public static bool operator >(dynamic Value, SmallDec self)
		{
			return self < Value;
		}

		// Self Greater than or Equal to Value
		public static bool operator >=(SmallDec self, dynamic Value)
		{
			if (Value is SmallDec)
			{
				if (self.DecBoolStatus == Value.DecBoolStatus && self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
				else
				{
					// Positive Self >= -Value
					if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return true; }
					// Negative Self >= Value
					else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return false; }
					else
					{
						ulong SelfAsInt = self.IntValue;
						SelfAsInt *= 10000;
						SelfAsInt += self.DecimalStatus;
						ulong ValueAsInt = Value.IntValue;
						ValueAsInt *= 10000;
						ValueAsInt += Value.DecimalStatus;
						//Both are either positive or negative numbers
						if (self.DecBoolStatus == 0)
						{
							return SelfAsInt >= ValueAsInt;
						}
						else
						{//Larger number = farther down into negative
							return !(SelfAsInt >= ValueAsInt);
						}
					}
				}
			}
			else if (Value is double)
			{
				if (Value < 0.0 && self.DecBoolStatus == 0) { return true; }
				else if (Value >= 0.0 && self.DecBoolStatus == 1) { return false; }
				else
				{
					Value = Math.Abs(Value);
					ushort WholeHalf = (ushort)Value;
					//Use x Int Operation instead if Value has no decimal places
					if (WholeHalf == Value)
					{
						if (self.DecimalStatus == 0)
						{
							if (self.DecBoolStatus == 0) { return self.IntValue >= WholeHalf; }
							else { return !(self.IntValue >= WholeHalf); }
						}
						else
						{
							uint SelfAsInt = (uint)(self.IntValue * 10000);
							SelfAsInt += self.DecimalStatus;
							if (self.DecBoolStatus == 0) { return SelfAsInt >= (uint)(WholeHalf * 10000); }
							else { return !(SelfAsInt >= (uint)(WholeHalf * 10000)); }
						}
					}
					else
					{
						Value -= WholeHalf;
						ushort Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalfV3(Value);
						}
						uint SelfAsInt = (uint)(self.IntValue * 10000);
						SelfAsInt += self.DecimalStatus;
						uint ValueAsInt = WholeHalf;
						ValueAsInt *= 10000;
						ValueAsInt += Decimalhalf;
						if (self.DecBoolStatus == 0) { return SelfAsInt >= ValueAsInt; }
						else { return !(SelfAsInt >= ValueAsInt); }
					}
				}
			}
			else if (Value is String)
			{
				//return (String)Value == (String)self;
				return false;
			}
			else
			{
				if (Value < 0 && self.DecBoolStatus == 0) { return true; }
				else if (Value >= 0 && self.DecBoolStatus == 1) { return false; }
				else
				{
					Value = Math.Abs(Value);
					if (Value == self.IntValue) { return true; }
					else
					{
						//Both are either positive or negative numbers
						if (self.DecBoolStatus == 0)
						{
							return self.IntValue >= Value;
						}
						else
						{//Larger number = farther down into negative
							return !(self.IntValue >= Value);
						}
					}
				}
			}
		}

		public static bool operator >=(dynamic Value, SmallDec self)
		{
			return self <= Value;
		}

		// Equality operator for comparing self to int type value
		public static bool operator ==(SmallDec self, dynamic Value)
		{
			if (Value is SmallDec)
			{
				if (self.DecBoolStatus == Value.DecBoolStatus && self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
				else { return false; }
			}
			else if (Value is double)
			{
				if (Value < 0.0 && self.DecBoolStatus == 0) { return false; }
				else if (Value >= 0.0 && self.DecBoolStatus == 1) { return false; }
				else
				{
					Value = Math.Abs(Value);
					ushort WholeHalf = (ushort)Value;
					//Use x Int Operation instead if Value has no decimal places
					if (WholeHalf == Value)
					{
						if (self.DecimalStatus == 0)
						{
							//Use normal simple (int value) * (int value) if not dealing with anValue decimals
							return self.IntValue != WholeHalf;
						}
						else
						{
							uint SelfAsInt = self.DecimalStatus;
							SelfAsInt += (uint)(self.IntValue * 10000);
							return SelfAsInt != (uint)(WholeHalf * 1000);
						}
					}
					else
					{
						Value -= WholeHalf;
						ushort Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalfV3(Value);
						}
						uint SelfAsInt = (uint)(self.IntValue * 10000);
						SelfAsInt += self.DecimalStatus;
						uint ValueAsInt = WholeHalf;
						ValueAsInt *= 10000;
						ValueAsInt += Decimalhalf;
						return SelfAsInt == ValueAsInt;
					}
				}
			}
			else if (Value is String)
			{
				return (String)Value == (String)self;
			}
			else
			{
				if (self.DecimalStatus != 0) { return false; }
				else if (Value < 0 && self.DecBoolStatus == 0) { return false; }
				else if (Value >= 0 && self.DecBoolStatus == 1) { return false; }
				else
				{
					Value = Math.Abs(Value);
					if (Value == self.IntValue) { return true; }
					else { return false; }
				}
			}
		}

		public static bool operator ==(dynamic Value, SmallDec self)
		{
			return self == Value;
		}

		// Inequality operator for comparing self to multiple value types
		public static bool operator !=(SmallDec self, dynamic Value)
		{
			if (Value is SmallDec)
			{
				if (self.DecBoolStatus != Value.DecBoolStatus || self.IntValue != Value.IntValue || self.DecimalStatus != Value.DecimalStatus) { return true; }
				else { return false; }
			}
			else if (Value is double)
			{
				if (Value < 0.0 && self.DecBoolStatus == 0) { return true; }
				else if (Value >= 0.0 && self.DecBoolStatus == 1) { return true; }
				else
				{
					Value = Math.Abs(Value);
					ushort WholeHalf = (ushort)Value;
					//Use x Int Operation instead if Value has no decimal places
					if (WholeHalf == Value)
					{
						if (self.DecimalStatus == 0)
						{
							//Use normal simple (int value) * (int value) if not dealing with anValue decimals
							return self.IntValue != WholeHalf;
						}
						else
						{
							uint SelfAsInt = self.DecimalStatus;
							SelfAsInt += (uint)(self.IntValue * 10000);
							return SelfAsInt != (uint)(WholeHalf * 10000);
						}
					}
					else
					{
						Value -= WholeHalf;
						ushort Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalfV3(Value);
						}
						uint SelfAsInt = (ushort)(self.IntValue * 10000);
						SelfAsInt += self.DecimalStatus;
						uint ValueAsInt = WholeHalf;
						ValueAsInt *= 10000;
						ValueAsInt += Decimalhalf;
						return SelfAsInt != ValueAsInt;
					}
				}
			}
			else if (Value is String)
			{
				return (String)Value != (String)self;
			}
			else
			{
				if (self.DecimalStatus != 0) { return true; }
				else if (Value < 0 && self.DecBoolStatus == 0) { return true; }
				else if (Value >= 0 && self.DecBoolStatus == 1) { return true; }
				else
				{
					Value = Math.Abs(Value);
					if (Value == self.IntValue) { return false; }
					else { return true; }
				}
			}
		}

		public static bool operator !=(dynamic Value, SmallDec self)
		{
			return self != Value;
		}

		public override bool Equals(object obj)
		{
			if (obj == null || GetType() != obj.GetType()) { return false; }

			try
			{
				return this == (SmallDec)obj;
			}
			catch
			{
				return false;
			}
		}

		public byte GetDecBoolStatus()
		{
			return DecBoolStatus;
		}

		public ushort GetDecimalStatus()
		{
			return DecimalStatus;
		}

		// Override the Object.GetHashCode() method:
		public override int GetHashCode()
		{
			if (DecBoolStatus == 1)
			{
				return ((int)IntValue + (int)DecimalStatus) * -1;
			}
			else
			{
				return (int)IntValue + (int)DecimalStatus;
			}
		}

		/// <summary>
		///
		/// </summary>
		/// <returns></returns>
		public ushort GetIntValue()
		{
			return IntValue;
		}

		public int GetIntValueAsInt32()
		{
			return (int)IntValue;
		}

		public void SwapNegativeStatus()
		{
			if (DecBoolStatus == 1) { DecBoolStatus = 0; }
			else { DecBoolStatus = 1; }
		}

		//Returns value of highest non-infinite/Special Decimal State Value that can store
		public SmallDec Maximum()
		{
			SmallDec NewSelf;
			NewSelf.IntValue = 65535;
			NewSelf.DecimalStatus = 9999;
			NewSelf.DecBoolStatus = 0;
			return NewSelf;
		}

		//Returns value of minimum non-infinite/Special Decimal State Value that can store
		public SmallDec Minimum()
		{
			SmallDec NewSelf;
			NewSelf.IntValue = 65535;
			NewSelf.DecimalStatus = 9999;
			NewSelf.DecBoolStatus = 1;
			return NewSelf;
		}

		public bool IsInfinity()
		{
			//Negative Infinity
			if (DecBoolStatus == 255)
			{ return true; }
			//Positive Infinity
			else if (DecBoolStatus == 254)
			{ return true; }
			else { return false; }
		}

		public static SmallDec FloatParse(string s, IFormatProvider provider)
		{
			SmallDec NewSelf = (SmallDec)float.Parse(s, provider);
			return NewSelf;
		}

		public static SmallDec DoubleParse(string s, IFormatProvider provider)
		{
			SmallDec NewSelf = (SmallDec)double.Parse(s, provider);
			return NewSelf;
		}

		public string ToString(string s, IFormatProvider provider)
		{
			return (string)this;
		}

		public string ToString(string s)
		{
			return (string)this;
		}

		internal string ToString(CultureInfo invariantCulture)
		{
			return (string)this;
		}

		public override string ToString(){ return (string)this; }

		//public static SmallDec operator ?(bool Condition, dynamic X, dynamic Y)
		//{
		//	if (Condition)
		//	{
		//		return X;
		//	}
		//	else
		//	{
		//		return Y;
		//	}
		//}
		public static dynamic ConditionalReturn(bool Condition, dynamic X, dynamic Y)
		{
			if (Condition)
			{
				return X;
			}
			else
			{
				return Y;
			}
		}

		public dynamic DynamicConversion()
		{
			return this;
		}

		public static SmallDec SumOfList(SmallDec[] self)
		{
			SmallDec Total = SmallDec.Zero;
			foreach(SmallDec Element in self)
			{
				Total += Element;
			}
			return Total;
		}

		public static SmallDec SumOfList(IEnumerable<SmallDec> self)
		{
			SmallDec Total = SmallDec.Zero;
			foreach (SmallDec Element in self)
			{
				Total += Element;
			}
			return Total;
		}

		public static SmallDec operator %(SmallDec self, SmallDec y)
		{
			if (y.IntValue == 0 && y.DecimalStatus == 0)
			{
				self.IntValue = 0;
				self.DecimalStatus = 0;
				self.DecBoolStatus = 0;
			}
			else
			{
				if (y.DecBoolStatus == 1) { self.SwapNegativeStatus(); }
				if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
				{//Use normal simple (int value) * (int value) if not dealing with any decimals
					self.IntValue %= y.IntValue;
				}
				else if (y.DecimalStatus == 0)
				{
					uint SelfAsInt = self.DecimalStatus;
					SelfAsInt += (uint)(self.IntValue * 10000);
					SelfAsInt %= y.IntValue;
					self.IntValue = (ushort)(SelfAsInt / 1000);
					SelfAsInt -= (uint)(self.IntValue * 10000);
					self.DecimalStatus = (ushort)SelfAsInt;
				}
				else
				{
					ulong SelfAsInt = self.DecimalStatus;
					SelfAsInt += (ulong)(self.IntValue * 10000);
					uint YAsInt = y.IntValue;
					YAsInt *= 10000;
					YAsInt += y.DecimalStatus;
					SelfAsInt %= YAsInt;
					SelfAsInt /= 10000;
					ulong TempStorage = SelfAsInt / 10000;
					self.IntValue = (ushort)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000;
					SelfAsInt -= TempStorage;
					self.DecimalStatus = (ushort)SelfAsInt;
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static SmallDec operator +(SmallDec self, SmallDec y)
		{
			bool IsYNegative = (y.DecBoolStatus == 1) ? true : false;
			if (self.DecBoolStatus == 1 && IsYNegative)
			{// -X - Y (ex. -8 + -6)
				self.IntValue = (ushort)(self.IntValue + y.IntValue);
			}
			else if (self.DecBoolStatus == 0 && IsYNegative == false)
			{
				//X + Y (ex. 8 + 6)
				self.IntValue = (ushort)(self.IntValue + y.IntValue);
			}
			else
			{
				// -X + Y
				if (self.DecBoolStatus == 1)
				{   //ex. -8 + 9
					if (y.IntValue > self.IntValue)
					{
						self.IntValue = (ushort)(y.IntValue - self.IntValue);
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 +  4
						self.IntValue = (ushort)(self.IntValue - y.IntValue);
					}
				}// X + -Y
				else
				{
					if (self.IntValue > y.IntValue)
					{//ex. 9 + -6
						self.IntValue = (ushort)(self.IntValue - y.IntValue);
					}
					else
					{//ex. 9 + -10
						self.IntValue = (ushort)(y.IntValue - self.IntValue);
						self.DecBoolStatus = 1;
					}
				}
			}
			//Decimal Section
			if (self.DecimalStatus != 0 || y.DecimalStatus != 0)
			{
				// ?.XXXXXX + ?.YYYYYY (ex. 0.9 + 0.2)
				if (self.DecBoolStatus == 0 && IsYNegative == false)
				{
					//Potential Overflow check
					ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + y.DecimalStatus);
					if (DecimalStatusTemp > 9999)
					{
						DecimalStatusTemp -= 10000;
						self.IntValue += 1;
					}
					self.DecimalStatus = DecimalStatusTemp;
				}
				// -?.XXXXXX - ?.YYYYYY (ex. -0.9 + -0.2)
				else if (self.DecBoolStatus == 1 && IsYNegative)
				{
					//Potential Overflow check
					ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + y.DecimalStatus);
					if (DecimalStatusTemp > 9999)
					{
						DecimalStatusTemp -= 10000;
						self.IntValue -= 1;
					}
					self.DecimalStatus = DecimalStatusTemp;
				}
				else
				{
					if (IsYNegative)
					{
						// ex. 0.6 + -0.5
						if (self.DecimalStatus >= y.DecimalStatus)
						{
							self.DecimalStatus = (ushort)(self.DecimalStatus - y.DecimalStatus);
						}// ex. 0.6 + -.7
						else
						{
							self.DecimalStatus = (ushort)(y.DecimalStatus - self.DecimalStatus);
							if (self.IntValue == 0)
							{
								self.DecBoolStatus = 1;
							}
							else
							{
								self.IntValue -= 1;
							}
						}
					}
					else
					{ //ex -0.6 + 0.5
						if (self.DecimalStatus >= y.DecimalStatus)
						{
							self.DecimalStatus = (ushort)(self.DecimalStatus - y.DecimalStatus);
						}// ex. -1.6 + 0.7
						else
						{
							self.DecimalStatus = (ushort)(y.DecimalStatus - self.DecimalStatus);
							if (self.IntValue == 0)
							{
								self.DecBoolStatus = 0;
							}
							else
							{
								self.IntValue -= 1;
							}
						}
					}
				}
			}
			//Fix potential negative zero
			if (self.IntValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
			return self;
		}

		public static SmallDec operator -(SmallDec self, SmallDec y)
		{
			bool IsYNegative = (y.DecBoolStatus == 1) ? true : false;
			//ex. -9 - 9
			if (self.DecBoolStatus == 1 && IsYNegative == false)
			{// -X - Y
				self.IntValue = (ushort)(self.IntValue + y.IntValue);
			}//ex. 9 - (-1)
			else if (self.DecBoolStatus == 0 && IsYNegative == true)
			{
				//X - (-Y)
				self.IntValue = (ushort)(self.IntValue + y.IntValue);
			}
			else
			{
				// X - (Y)
				if (self.DecBoolStatus == 0)
				{
					// ex. 8 - 9
					if (y.IntValue > self.IntValue)
					{
						self.IntValue = (ushort)(y.IntValue - self.IntValue);
						self.DecBoolStatus = 1;
					} //ex. 8 - 7
					else
					{
						self.IntValue = (ushort)(self.IntValue - y.IntValue);
					}
				}// -X - (Y)
				else
				{
					// ex. -8 - (-9)
					if (self.IntValue > y.IntValue)
					{
						self.IntValue = (ushort)(y.IntValue - self.IntValue);
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 - (-5)
						self.IntValue = (ushort)(self.IntValue - y.IntValue);
					}
				}
			}
			//Decimal Section
			if (self.DecimalStatus != 0 || y.DecimalStatus != 0)
			{
				// ex. -0.5 - 0.6
				if (self.DecBoolStatus == 1 && IsYNegative == false)
				{
					//Potential Overflow check
					ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + y.DecimalStatus);
					if (DecimalStatusTemp > 9999)
					{
						DecimalStatusTemp -= 10000;
						self.IntValue += 1;
					}
					self.DecimalStatus = DecimalStatusTemp;
				}// ex. 0.5 - (-0.6)
				else if (self.DecBoolStatus == 0 && IsYNegative)
				{
					//Potential Overflow check
					ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + y.DecimalStatus);
					if (DecimalStatusTemp > 9999)
					{
						DecimalStatusTemp -= 10000;
						self.IntValue += 1;
					}
					self.DecimalStatus = DecimalStatusTemp;
				}
				else
				{
					if (IsYNegative)
					{// ex. -0.7 - (-0.6)
						if (self.DecimalStatus >= y.DecimalStatus)
						{
							self.DecimalStatus = (ushort)(self.DecimalStatus - y.DecimalStatus);
						}
						else
						{
							self.DecimalStatus = (ushort)(y.DecimalStatus - self.DecimalStatus);
							if (self.IntValue == 0)
							{
								self.DecBoolStatus = 0;
							}
							else
							{
								self.IntValue -= 1;
							}
						}
					}
					else
					{ //ex  0.6 - 0.5
						if (self.DecimalStatus >= y.DecimalStatus)
						{
							self.DecimalStatus = (ushort)(self.DecimalStatus - y.DecimalStatus);
						}
						else
						{
							self.DecimalStatus = (ushort)(y.DecimalStatus - self.DecimalStatus);
							if (self.IntValue == 0)
							{
								self.DecBoolStatus = 1;
							}
							else
							{
								self.IntValue -= 1;
							}
						}
					}
				}
			}
			//Fix potential negative zero
			if (self.IntValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
			return self;
		}

		public static SmallDec operator *(SmallDec self, SmallDec y)
		{
			if (y.IntValue == 0 && y.DecimalStatus == 0)
			{
				self.IntValue = 0;
				self.DecimalStatus = 0;
				self.DecBoolStatus = 0;
			}
			else
			{
				if (y.DecBoolStatus == 1) { self.SwapNegativeStatus(); }
				if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
				{//Use normal simple (int value) * (int value) if not dealing with any decimals
					self.IntValue *= y.IntValue;
				}
				else if (y.DecimalStatus == 0)
				{
					uint SelfAsInt = self.DecimalStatus;
					SelfAsInt += (uint)(self.IntValue * 10000);
					SelfAsInt *= y.IntValue;
					self.IntValue = (ushort)(SelfAsInt / 1000);
					SelfAsInt -= (uint)(self.IntValue * 10000);
					self.DecimalStatus = (ushort)SelfAsInt;
				}
				else
				{
					ulong SelfAsInt = self.IntValue;
					SelfAsInt *= 10000;
					SelfAsInt += self.DecimalStatus;
					uint YAsInt = y.IntValue;
					YAsInt *= 10000;
					YAsInt += y.DecimalStatus;
					SelfAsInt *= YAsInt;
					SelfAsInt /= 10000;
					ulong TempStorage = SelfAsInt / 10000;
					self.IntValue = (ushort)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000;
					SelfAsInt -= TempStorage;
					self.DecimalStatus = (ushort)SelfAsInt;
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static SmallDec operator /(SmallDec self, SmallDec y)
		{
			if (y.IntValue == 0 && y.DecimalStatus == 0)
			{
				Console.WriteLine("Prevented dividing by zero");
			}
			else
			{
				if (y.DecBoolStatus == 1) { self.SwapNegativeStatus(); }
				if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
				{//Use normal simple (int value) * (int value) if not dealing with any decimals
					self.IntValue /= y.IntValue;
				}
				else if (y.DecimalStatus == 0)
				{
					uint SelfAsInt = self.DecimalStatus;
					SelfAsInt += (uint)(self.IntValue * 10000);
					SelfAsInt /= y.IntValue;
					self.IntValue = (ushort)(SelfAsInt / 1000);
					SelfAsInt -= (uint)(self.IntValue * 10000);
					self.DecimalStatus = (ushort)SelfAsInt;
				}
				else
				{
					ulong SelfAsInt = self.IntValue;
					SelfAsInt *= 10000;
					SelfAsInt += self.DecimalStatus;
					uint YAsInt = y.IntValue;
					YAsInt *= 10000;
					YAsInt += y.DecimalStatus;
					SelfAsInt /= YAsInt;
					SelfAsInt /= 10000;
					ulong TempStorage = SelfAsInt / 10000;
					self.IntValue = (ushort)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000;
					SelfAsInt -= TempStorage;
					self.DecimalStatus = (ushort)SelfAsInt;
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static SmallDec operator %(SmallDec self, dynamic y)
		{
			if (y is double || y is float || y is decimal)
			{
				if (y == 0.0)
				{
					self.IntValue = 0;
					self.DecimalStatus = 0;
					self.DecBoolStatus = 0;
				}
				else
				{
					if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
					ushort WholeHalf = (ushort)y;
					//Use x Int Operation instead if y has no decimal places
					if (WholeHalf == y)
					{
						if (self.DecimalStatus == 0)
						{
							//Use normal simple (int value) * (int value) if not dealing with any decimals
							self.IntValue %= WholeHalf;
						}
						else
						{
							uint SelfAsInt = self.DecimalStatus;
							SelfAsInt += (uint)(self.IntValue * 10000);
							SelfAsInt %= WholeHalf;
							self.IntValue = (ushort)(SelfAsInt / 1000);
							SelfAsInt -= (uint)(self.IntValue * 10000);
							self.DecimalStatus = (ushort)SelfAsInt;
						}
					}
					else
					{
						y -= WholeHalf;
						ushort Decimalhalf;
						if (y == 0.25)
						{
							Decimalhalf = 2500;
						}
						else if (y == 0.5)
						{
							Decimalhalf = 5000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalfV3(y);
						}
						ulong SelfAsInt = self.IntValue;
						SelfAsInt *= 10000;
						SelfAsInt += self.DecimalStatus;
						ulong YAsInt = WholeHalf;
						YAsInt *= 10000;
						YAsInt += Decimalhalf;
						SelfAsInt %= YAsInt;
						SelfAsInt /= 10000;
						ulong TempStorage = SelfAsInt / 10000;
						self.IntValue = (ushort)TempStorage;
						TempStorage = self.IntValue;
						TempStorage *= 10000;
						SelfAsInt -= TempStorage;
						self.DecimalStatus = (ushort)SelfAsInt;
					}
					//Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
					if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
				}
			}
			else
			{
				if (y == 0)
				{
					self.IntValue = 0;
					self.DecimalStatus = 0;
					self.DecBoolStatus = 0;
				}
				else
				{
					if (y < 0) { self.SwapNegativeStatus(); y *= -1; }
					if (self.DecimalStatus == 0)
					{//Use normal simple (int value) * (int value) if not dealing with any decimals
						self.IntValue %= (ushort)y;
					}
					else
					{
						uint SelfAsInt = self.DecimalStatus;
						SelfAsInt += (uint)(self.IntValue * 10000);
						SelfAsInt %= y;
						uint TempStorage = SelfAsInt / 10000;
						self.IntValue = (ushort)TempStorage;
						TempStorage *= 10000;
						SelfAsInt -= TempStorage;
						self.DecimalStatus = (ushort)SelfAsInt;
					}
					//Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
					if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
				}
			}
			return self;
		}

		public static SmallDec operator +(SmallDec self, dynamic y)
		{
			if (y is double || y is float || y is decimal)
			{
				bool IsYNegative = (y < 0) ? true : false;
				y = Math.Abs(y);
				ushort WholeHalfOfY = (ushort)Math.Floor(y);
				y -= WholeHalfOfY;
				if (WholeHalfOfY == 0) { }
				else if (self.DecBoolStatus == 1 && IsYNegative)
				{// -X - Y (ex. -8 + -6)
					self.IntValue = (ushort)(self.IntValue + WholeHalfOfY);
				}
				else if (self.DecBoolStatus == 0 && IsYNegative == false)
				{
					//X + Y (ex. 8 + 6)
					self.IntValue = (ushort)(self.IntValue + WholeHalfOfY);
				}
				else
				{
					// -X + Y
					if (self.DecBoolStatus == 1)
					{   //ex. -8 + 9
						if (y > self.IntValue)
						{
							self.IntValue = (ushort)(WholeHalfOfY - self.IntValue);
							self.DecBoolStatus = 0;
						}
						else
						{//ex. -8 +  4
							self.IntValue = (ushort)(self.IntValue - WholeHalfOfY);
						}
					}// X-Y
					else
					{
						if (self.IntValue > WholeHalfOfY)
						{//ex. 9 + -6
							self.IntValue = (ushort)(self.IntValue - WholeHalfOfY);
						}
						else
						{//ex. 9 + -10
							self.IntValue = (ushort)(WholeHalfOfY - self.IntValue);
							self.DecBoolStatus = 1;
						}
					}
				}
				//Decimal Calculation Section
				if (self.DecBoolStatus != 0 || y != 0)
				{
					ushort SecondDec = (ushort)((System.Math.Abs(y) - System.Math.Abs(WholeHalfOfY)) * 10000);
					// ?.XXXXXX + ?.YYYYYY
					if (self.DecBoolStatus == 0 && IsYNegative == false)
					{
						//Potential Overflow check
						ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + SecondDec);
						if (DecimalStatusTemp > 9999)
						{
							DecimalStatusTemp -= 10000;
							self.IntValue += 1;
						}
						self.DecimalStatus = DecimalStatusTemp;
					}
					// -?.XXXXXX - ?.YYYYYY
					else if (self.DecBoolStatus == 1 && IsYNegative == true)
					{
						//Potential Overflow check
						ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + SecondDec);
						if (DecimalStatusTemp > 9999)
						{
							DecimalStatusTemp -= 10000;
							self.IntValue += 1;
						}
						self.DecimalStatus = DecimalStatusTemp;
					}
					else
					{
						if (IsYNegative)
						{
							// ex. 0.6 + -0.5
							if (self.DecimalStatus >= SecondDec)
							{
								self.DecimalStatus = (ushort)(self.DecimalStatus - SecondDec);
							}// ex. 0.6 + -.7
							else
							{
								self.DecimalStatus = (ushort)(SecondDec - self.DecimalStatus);
								if (self.IntValue == 0)
								{
									self.DecBoolStatus = 1;
								}
								else
								{
									self.IntValue -= 1;
								}
							}
						}
						else
						{
							if (self.DecimalStatus >= SecondDec)
							{
								self.DecimalStatus = (ushort)(self.DecimalStatus - SecondDec);
							}// ex. -1.6 + 0.7
							else
							{
								self.DecimalStatus = (ushort)(SecondDec - self.DecimalStatus);
								if (self.IntValue == 0)
								{
									self.DecBoolStatus = 0;
								}
								else
								{
									self.IntValue -= 1;
								}
							}
						}
					}
				}
			}
			else
			{
				if (self.DecBoolStatus == 1 && y < 0)
				{// -X - Y (ex. -8 + -6)
					self.IntValue = (ushort)(self.IntValue + (ushort)Math.Abs(y));
				}
				else if (self.DecBoolStatus == 0 && y >= 0)
				{
					//X + Y (ex. 8 + 6)
					self.IntValue = (ushort)(self.IntValue + y);
				}
				else
				{
					// -X + Y
					if (self.DecBoolStatus == 1)
					{   //ex. -8 + 9
						if (y > self.IntValue)
						{
							self.IntValue = (ushort)(y - self.IntValue);
							self.DecBoolStatus = 0;
						}
						else
						{//ex. -8 +  4
							self.IntValue = (ushort)(self.IntValue - y);
						}
					}// X-Y
					else
					{
						ushort TempY = Math.Abs(y);
						if (self.IntValue > TempY)
						{//ex. 9 + -6
							self.IntValue = (ushort)(self.IntValue - TempY);
						}
						else
						{//ex. 9 + -10
							self.IntValue = (ushort)(TempY - self.IntValue);
							self.DecBoolStatus = 1;
						}
					}
				}
			}
			//Fix potential negative zero
			if (self.IntValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
			return self;
		}

		public static SmallDec operator -(SmallDec self, dynamic y)
		{
			if (y is double || y is float || y is decimal)
			{
				bool IsYNegative = (y < 0) ? true : false;
				y = Math.Abs(y);
				ushort WholeHalfOfY = (ushort)(Math.Floor(y));
				y -= WholeHalfOfY;
				if (WholeHalfOfY == 0) { }
				//ex. -9 - 9
				else if (self.DecBoolStatus == 1 && IsYNegative == false)
				{// -X - Y
					self.IntValue = (ushort)(self.IntValue + WholeHalfOfY);
				}//ex. 9 - (-1)
				else if (self.DecBoolStatus == 0 && IsYNegative)
				{
					//X - (-Y)
					self.IntValue = (ushort)(self.IntValue + WholeHalfOfY);
				}
				else
				{
					// X - (Y)
					if (self.DecBoolStatus == 0)
					{
						// ex. 8 - 9
						if (WholeHalfOfY > self.IntValue)
						{
							self.IntValue = (ushort)(WholeHalfOfY - self.IntValue);
							self.DecBoolStatus = 1;
						} //ex. 8 - 7
						else
						{
							self.IntValue = (ushort)(self.IntValue - WholeHalfOfY);
						}
					}// -X - (Y)
					else
					{
						// ex. -8 - (-9)
						if (self.IntValue > WholeHalfOfY)
						{
							self.IntValue = (ushort)(WholeHalfOfY - self.IntValue);
							self.DecBoolStatus = 0;
						}
						else
						{//ex. -8 - (-5)
							self.IntValue = (ushort)(self.IntValue - WholeHalfOfY);
						}
					}
				}
				//Decimal Calculation Section
				ushort SecondDec = (ushort)((System.Math.Abs(y) - System.Math.Abs(WholeHalfOfY)) * 10000);
				if (self.DecimalStatus != 0 || SecondDec != 0)
				{
					// ex. -0.5 - 0.6
					if (self.DecBoolStatus == 1 && IsYNegative == false)
					{
						//Potential Overflow check
						ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + SecondDec);
						if (DecimalStatusTemp > 9999)
						{
							DecimalStatusTemp -= 10000;
							self.IntValue += 1;
						}
						self.DecimalStatus = DecimalStatusTemp;
					}// ex. 0.5 - (-0.6)
					else if (self.DecBoolStatus == 0 && IsYNegative)
					{
						//Potential Overflow check
						ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + SecondDec);
						if (DecimalStatusTemp > 9999)
						{
							DecimalStatusTemp -= 10000;
							self.IntValue += 1;
						}
						self.DecimalStatus = DecimalStatusTemp;
					}
					else
					{
						if (IsYNegative)
						{// ex. -0.7 - (-0.6)
							if (self.DecimalStatus >= SecondDec)
							{
								self.DecimalStatus = (ushort)(self.DecimalStatus - SecondDec);
							}
							else
							{
								self.DecimalStatus = (ushort)(SecondDec - self.DecimalStatus);
								if (self.IntValue == 0)
								{
									self.DecBoolStatus = 0;
								}
								else
								{
									self.IntValue -= 1;
								}
							}
						}
						else
						{ //ex  0.6 - 0.5
							if (self.DecimalStatus >= SecondDec)
							{
								self.DecimalStatus = (ushort)(self.DecimalStatus - SecondDec);
							}
							else
							{
								self.DecimalStatus = (ushort)(SecondDec - self.DecimalStatus);
								if (self.IntValue == 0)
								{
									self.DecBoolStatus = 1;
								}
								else
								{
									self.IntValue -= 1;
								}
							}
						}
					}
				}
			}
			else
			{
				//ex. -9 - 9
				if (self.DecBoolStatus == 1 && y >= 0)
				{// -X - Y
					self.IntValue = (ushort)(self.IntValue + y);
				}//ex. 9 - (-1)
				else if (self.DecBoolStatus == 0 && y < 0)
				{
					//X - (-Y)
					self.IntValue = (ushort)(self.IntValue + Math.Abs(y));
				}
				else
				{
					// X - (Y)
					if (self.DecBoolStatus == 0)
					{
						// ex. 8 - 9
						if (y > self.IntValue)
						{
							self.IntValue = (ushort)(y - self.IntValue);
							self.DecBoolStatus = 1;
						} //ex. 8 - 7
						else
						{
							self.IntValue = (ushort)(self.IntValue - y);
						}
					}// -X - (Y)
					else
					{
						ushort TempY = Math.Abs(y);
						// ex. -8 - (-9)
						if (self.IntValue > TempY)
						{
							self.IntValue = (ushort)(TempY - self.IntValue);
							self.DecBoolStatus = 0;
						}
						else
						{//ex. -8 - (-5)
							self.IntValue = (ushort)(self.IntValue - TempY);
						}
					}
				}
			}
			//Fix potential negative zero
			if (self.IntValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
			return self;
		}

		public static SmallDec operator *(SmallDec self, dynamic y)
		{
			if (y is double || y is float || y is decimal)
			{
				if (y == 0.0)
				{
					self.IntValue = 0;
					self.DecimalStatus = 0;
					self.DecBoolStatus = 0;
				}
				else
				{
					if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
					ushort WholeHalf = (ushort)Math.Floor(y);
					//Use x Int Operation instead if y has no decimal places
					if (WholeHalf == y)
					{
						if (self.DecimalStatus == 0)
						{
							//Use normal simple (int value) * (int value) if not dealing with any decimals
							self.IntValue *= WholeHalf;
						}
						else
						{
							uint SelfAsInt = self.DecimalStatus;
							SelfAsInt += (uint)(self.IntValue * 10000);
							SelfAsInt *= WholeHalf;
							self.IntValue = (ushort)(SelfAsInt / 1000);
							SelfAsInt -= (uint)(self.IntValue * 10000);
							self.DecimalStatus = (ushort)SelfAsInt;
						}
					}
					else
					{
						y -= WholeHalf;
						ushort Decimalhalf;
						if (y == 0.25)
						{
							Decimalhalf = 2500;
						}
						else if (y == 0.5)
						{
							Decimalhalf = 5000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalfV3(y);
						}
						ulong SelfAsInt = self.IntValue;
						SelfAsInt *= 10000;
						SelfAsInt += self.DecimalStatus;
						uint YAsInt = WholeHalf;
						YAsInt *= 10000;
						YAsInt += Decimalhalf;
						SelfAsInt *= YAsInt;
						SelfAsInt /= 10000;
						ulong TempStorage = SelfAsInt / 10000;
						self.IntValue = (ushort)TempStorage;
						TempStorage = self.IntValue;
						TempStorage *= 10000;
						SelfAsInt -= TempStorage;
						self.DecimalStatus = (ushort)SelfAsInt;
					}
					//Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
					if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
				}
			}
			else
			{
				if (y == 0)
				{
					self.IntValue = 0;
					self.DecimalStatus = 0;
					self.DecBoolStatus = 0;
				}
				else
				{
					if (y < 0) { self.SwapNegativeStatus(); y *= -1; }
					if (self.DecimalStatus == 0)
					{//Use normal simple (int value) * (int value) if not dealing with any decimals
						self.IntValue *= y;
					}
					else
					{
						uint SelfAsInt = self.DecimalStatus;
						SelfAsInt += (uint)(self.IntValue * 10000);
						SelfAsInt *= y;
						uint TempStorage = SelfAsInt / 10000;
						self.IntValue = (ushort)TempStorage;
						TempStorage *= 10000;
						SelfAsInt -= TempStorage;
						self.DecimalStatus = (ushort)SelfAsInt;
					}
					//Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
					if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
				}
			}
			return self;
		}

		public static SmallDec operator /(SmallDec self, dynamic y)
		{
			if (y is double || y is float || y is decimal)
			{
				if (y == 0)
				{
					Console.WriteLine("Prevented dividing by zero");
				}
				else
				{
					if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
					ushort WholeHalf = (ushort)Math.Floor(y);
					//Use x Int Operation instead if y has no decimal places
					if (WholeHalf == y)
					{
						if (self.DecimalStatus == 0)
						{
							//Use normal simple (int value) * (int value) if not dealing with any decimals
							self.IntValue /= WholeHalf;
						}
						else
						{
							uint SelfAsInt = self.DecimalStatus;
							SelfAsInt += (uint)(self.IntValue * 10000);
							SelfAsInt /= WholeHalf;
							self.IntValue = (ushort)(SelfAsInt / 1000);
							SelfAsInt -= (uint)(self.IntValue * 10000);
							self.DecimalStatus = (ushort)SelfAsInt;
						}
					}
					else
					{
						y -= WholeHalf;
						ushort Decimalhalf;
						if (y == 0.25)
						{
							Decimalhalf = 2500;
						}
						else if (y == 0.5)
						{
							Decimalhalf = 5000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalfV3(y);
						}
						ulong SelfAsInt = self.IntValue;
						SelfAsInt *= 10000;
						SelfAsInt += self.DecimalStatus;
						uint YAsInt = WholeHalf;
						YAsInt *= 10000;
						YAsInt += Decimalhalf;
						SelfAsInt /= YAsInt;
						SelfAsInt /= 10000;
						ulong TempStorage = SelfAsInt / 10000;
						self.IntValue = (ushort)TempStorage;
						TempStorage = self.IntValue;
						TempStorage *= 10000;
						SelfAsInt -= TempStorage;
						self.DecimalStatus = (ushort)SelfAsInt;
					}
					//Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
					if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
				}
			}
			else
			{
				if (y == 0)
				{
					Console.WriteLine("Prevented dividing by zero");
				}
				else
				{
					if (y < 0) { self.SwapNegativeStatus(); y *= -1; }
					if (self.DecimalStatus == 0)
					{//Use normal simple (int value) * (int value) if not dealing with any decimals
						self.IntValue /= (ushort)y;
					}
					else
					{
						uint SelfAsInt = self.DecimalStatus;
						SelfAsInt += (uint)(self.IntValue * 10000);
						SelfAsInt /= y;
						uint TempStorage = SelfAsInt / 10000;
						self.IntValue = (ushort)TempStorage;
						TempStorage *= 10000;
						SelfAsInt -= TempStorage;
						self.DecimalStatus = (ushort)SelfAsInt;
					}
					//Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
					if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
				}
			}
			return self;
		}

		//Right side applications
		public static SmallDec operator -(dynamic y, SmallDec self)
		{
			SmallDec YAsSuperDec = (SmallDec)y;
			YAsSuperDec -= self;
			return YAsSuperDec;
		}

		public static SmallDec operator +(dynamic y, SmallDec self)
		{
			SmallDec YAsSuperDec = (SmallDec)y;
			YAsSuperDec += self;
			return YAsSuperDec;
		}

		public static SmallDec operator *(dynamic y, SmallDec self)
		{
			SmallDec YAsSuperDec = (SmallDec)y;
			YAsSuperDec += self;
			return YAsSuperDec;
		}

		public static SmallDec operator /(dynamic y, SmallDec self)
		{
			SmallDec YAsSuperDec = (SmallDec)y;
			YAsSuperDec += self;
			return YAsSuperDec;
		}

		public float AsFloat()
		{
			return (float)this;
		}

		public double AsDouble()
		{
			return (double)this;
		}

		public int AsInt()
		{
			return (int)this;
		}

		public string AsString()
		{
			return (string)this;
		}

		public bool IsNull()
		{
			if (DecBoolStatus==202) { return true; }
			else { return false; }
		}

		public static SmallDec Null()
		{
			SmallDec NewSelf;
			NewSelf.IntValue = 0; NewSelf.DecimalStatus = 0;
			NewSelf.DecBoolStatus = 202;
			return NewSelf;
		}

		public static SmallDec ZeroValue()
		{
			SmallDec NewSelf;
			NewSelf.IntValue = 0; NewSelf.DecimalStatus = 0; NewSelf.DecBoolStatus = 0;
			return NewSelf;
		}

		public static readonly SmallDec Zero = ZeroValue();

		//public static SmallDec ZeroValue = Zero();

		int IComparable<SmallDec>.CompareTo(SmallDec other)
		{
			if(other==this)
			{
				return 0;
			}
			else if(this<other)
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
	}
}