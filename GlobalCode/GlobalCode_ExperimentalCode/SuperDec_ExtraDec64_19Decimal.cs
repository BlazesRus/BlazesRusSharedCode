/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
using System;

//Requires BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.SuperDec_ExtraDec64_19Decimal
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
	using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

	public struct SuperDec_ExtraDec64_19Decimal
	{
		//0 = Positive;1=Negative;Other states at higher then 1
		public byte DecBoolStatus;

		//Stores decimal section info
		public ulong DecimalStatus;

		public ulong IntValue;

		public SuperDec_ExtraDec64_19Decimal Abs()
		{
			this.DecBoolStatus = 0;
			return this;
		}

		public SuperDec_ExtraDec64_19Decimal Floor()
		{
			this.DecimalStatus = 0;
			return this;
		}

		public SuperDec_ExtraDec64_19Decimal Ceil()
		{
			if (this.DecimalStatus!=0)
			{
				this.DecimalStatus = 0;
				this.IntValue += 1;
			}
			return this;
		}

		public SuperDec_ExtraDec64_19Decimal Round()
		{
			if(DecimalStatus>=5000000000000000000){	this.IntValue += 1;}
			this.DecimalStatus = 0;
			return this;
		}

		public SuperDec_ExtraDec64_19Decimal(dynamic Value)
		{
			if (Value is double || Value is float)
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
				IntValue = (uint)System.Math.Floor(Value);
				Value -= IntValue;
				DecimalStatus = ExtractDecimalHalf(Value);
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
				if (Value > 18446744073709551615)
				{
					Value = 18446744073709551615;
				}
				this.DecBoolStatus = 0;
				this.IntValue = (uint)Value;
				this.DecimalStatus = 0;
			}
			else
			{
				//Cap value if too big on initialize
				if (Value > 18446744073709551615)
				{
					Value = 18446744073709551615;
				}
				this.DecBoolStatus = 0;
				this.IntValue = (uint)Value;
				this.DecimalStatus = 0;
			}
		}

		public static explicit operator SuperDec_ExtraDec64_19Decimal(SmallDec self)
		{
			SuperDec_ExtraDec64_19Decimal NewSelf;
			NewSelf.IntValue = self.IntValue;
			NewSelf.DecimalStatus = (ulong)self.DecimalStatus * 1000000000000000;
			NewSelf.DecBoolStatus = self.DecBoolStatus;
			return NewSelf;
		}

		public static explicit operator SuperDec_ExtraDec64_19Decimal(SuperDec_ExtraDec32_19Decimal self)
		{
			SuperDec_ExtraDec64_19Decimal NewSelf;
			NewSelf.IntValue = self.IntValue;
			NewSelf.DecimalStatus = self.DecimalStatus;
			NewSelf.DecBoolStatus = self.DecBoolStatus;
			return NewSelf;
		}

		public static explicit operator SuperDec_ExtraDec64_19Decimal(SuperDec_Int32_9Decimal self)
		{
			SuperDec_ExtraDec64_19Decimal NewSelf;
			NewSelf.IntValue = self.IntValue;
			NewSelf.DecimalStatus = (ulong)self.DecimalStatus*10000000000;
			NewSelf.DecBoolStatus = self.DecBoolStatus;
			return NewSelf;
		}

		public static explicit operator float(SuperDec_ExtraDec64_19Decimal self)
		{
			float Value = 0.0f;
			Value += self.IntValue;
			Value += (float)(self.DecimalStatus * 0.0000000000000000001);
			if (self.DecBoolStatus == 1) { Value *= -1; }
			return Value;
		}

		//Explicit Conversion from this to double
		public static explicit operator double(SuperDec_ExtraDec64_19Decimal self)
		{
			double Value = 0.0;
			Value += self.IntValue;
			Value += (self.DecimalStatus * 0.0000000000000000001);
			if (self.DecBoolStatus == 1) { Value *= -1; }
			return Value;
		}

		//Explicit Conversion from this to int
		public static explicit operator int(SuperDec_ExtraDec64_19Decimal self)
		{
			int Value = (int)self.IntValue;
			if (self.DecimalStatus == 1) { Value *= -1; }
			return Value;
		}

		//Explicit Conversion from this to int 64
		public static explicit operator long(SuperDec_ExtraDec64_19Decimal self)
		{
			long Value = (long) self.IntValue;
			if (self.DecimalStatus == 1) { Value *= -1; }
			return Value;
		}

		//Explicit Conversion from this to uint
		public static explicit operator uint(SuperDec_ExtraDec64_19Decimal self)
		{
			return (uint) self.IntValue;
		}

		//Explicit Conversion from this to unsigned int 64
		public static explicit operator ulong(SuperDec_ExtraDec64_19Decimal self)
		{
			return self.IntValue;
		}

		public static ulong ForceConvertFromInt256(BigMath.Int256 Value)
		{
			ulong ConvertedValue = 0;
			//Larger than ulong (default to zero)
			if (Value > 18446744073709551615)
			{
				Console.WriteLine("Overflow Detected");
			}
			else
			{
				BigMath.Int128 Value02 = (BigMath.Int128)Value;
				ConvertedValue = (ulong)Value02;
			}
			return ConvertedValue;
		}

		static public explicit operator string(SuperDec_ExtraDec64_19Decimal self)
		{
			System.String Value = "";
			ulong IntegerHalf = self.IntValue;
			byte CurrentDigit;
			if (self.DecBoolStatus == 1) { Value += "-"; }
			for (sbyte Index = NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
			{
				CurrentDigit = (byte)(IntegerHalf / Math.Pow(10, Index));
				IntegerHalf -= (uint)(CurrentDigit * Math.Pow(10, Index));
				Value += DigitAsChar(CurrentDigit);
			}
			Value += ".";
			ulong DecimalHalf = self.DecimalStatus;
			for (sbyte Index = 18; Index >= 0; Index--)
			{
				CurrentDigit = (byte)(DecimalHalf / Math.Pow(10, Index));
				DecimalHalf -= (ulong)(CurrentDigit * Math.Pow(10, Index));
				Value += DigitAsChar(CurrentDigit);
			}
			return Value;
		}
		
		public static explicit operator byte(SuperDec_ExtraDec64_19Decimal self)
		{
			byte Value = (byte)self.IntValue;
			return Value;
		}

		public static explicit operator sbyte(SuperDec_ExtraDec64_19Decimal self)
		{
			sbyte Value = (sbyte)self.IntValue;
			if (self.DecimalStatus == 1) { Value *= -1; }
			return Value;
		}

		public static explicit operator ushort(SuperDec_ExtraDec64_19Decimal self)
		{
			ushort Value = (ushort)self.IntValue;
			return Value;
		}

		public static explicit operator short(SuperDec_ExtraDec64_19Decimal self)
		{
			short Value = (short)self.IntValue;
			if (self.DecimalStatus == 1) { Value *= -1; }
			return Value;
		}

		public static explicit operator SuperDec_ExtraDec64_19Decimal(double Value)
		{
			return new SuperDec_ExtraDec64_19Decimal(Value);
		}

		public static explicit operator SuperDec_ExtraDec64_19Decimal(int Value)
		{
			return new SuperDec_ExtraDec64_19Decimal(Value);
		}

		public static explicit operator SuperDec_ExtraDec64_19Decimal(uint Value)
		{
			return new SuperDec_ExtraDec64_19Decimal(Value);
		}

		public static explicit operator SuperDec_ExtraDec64_19Decimal(long Value)
		{
			return new SuperDec_ExtraDec64_19Decimal(Value);
		}

		public static explicit operator SuperDec_ExtraDec64_19Decimal(ulong Value)
		{
			return new SuperDec_ExtraDec64_19Decimal(Value);
		}

		public static explicit operator SuperDec_ExtraDec64_19Decimal(short Value)
		{
			return new SuperDec_ExtraDec64_19Decimal(Value);
		}

		public static explicit operator SuperDec_ExtraDec64_19Decimal(ushort Value)
		{
			return new SuperDec_ExtraDec64_19Decimal(Value);
		}

		public static explicit operator SuperDec_ExtraDec64_19Decimal(byte Value)
		{
			return new SuperDec_ExtraDec64_19Decimal(Value);
		}

		public static explicit operator SuperDec_ExtraDec64_19Decimal(sbyte Value)
		{
			return new SuperDec_ExtraDec64_19Decimal(Value);
		}

		public static SuperDec_ExtraDec64_19Decimal operator -(SuperDec_ExtraDec64_19Decimal self, double y)
		{
			bool IsYNegative = (y < 0) ? true : false;
			y = Math.Abs(y);
			uint WholeHalfOfY = (uint)Math.Floor(y);
			y -= WholeHalfOfY;
			if (WholeHalfOfY == 0) { }
			//ex. -9 - 9
			else if (self.GetBoolStatus() == 1 && IsYNegative == false)
			{// -X - Y
				self.IntValue = self.GetIntValue() + WholeHalfOfY;
			}//ex. 9 - (-1)
			else if (self.GetBoolStatus() == 0 && IsYNegative)
			{
				//X - (-Y)
				self.IntValue = self.GetIntValue() + WholeHalfOfY;
			}
			else
			{
				// X - (Y)
				if (self.GetBoolStatus() == 0)
				{
					// ex. 8 - 9
					if (WholeHalfOfY > self.GetIntValue())
					{
						self.IntValue = WholeHalfOfY - self.GetIntValue();
						self.DecBoolStatus = 1;
					} //ex. 8 - 7
					else
					{
						self.IntValue = self.IntValue - WholeHalfOfY;
					}
				}// -X - (Y)
				else
				{
					// ex. -8 - (-9)
					if (self.IntValue > WholeHalfOfY)
					{
						self.IntValue = WholeHalfOfY - self.IntValue;
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 - (-5)
						self.IntValue = self.GetIntValue() - WholeHalfOfY;
					}
				}
			}
			//Decimal Calculation Section
			ulong SecondDec = (ulong)(System.Math.Abs(y) - System.Math.Abs(WholeHalfOfY)) * 10000000000000000000;
			if (self.GetDecimalStatus() != 0 || SecondDec != 0)
			{
				// ex. -0.5 - 0.6
				if (self.GetBoolStatus() == 1 && IsYNegative == false)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + SecondDec;
					if (DecimalStatusTemp > 999999999999999999)
					{

						DecimalStatusTemp -= 1000000000000000000;
						self.IntValue += 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}// ex. 0.5 - (-0.6)
				else if (self.GetBoolStatus() == 0 && IsYNegative)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + SecondDec;
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 1000000000000000000;
						self.IntValue -= 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}
				else
				{
					if (IsYNegative)
					{// ex. -0.7 - (-0.6)
						if (self.GetDecimalStatus() >= SecondDec)
						{
							self.DecimalStatus = self.GetDecimalStatus() - SecondDec;
						}
						else
						{
							self.DecimalStatus = SecondDec - self.GetDecimalStatus();
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
						if (self.GetDecimalStatus() >= SecondDec)
						{
							self.DecimalStatus = self.GetDecimalStatus() - SecondDec;
						}
						else
						{
							self.DecimalStatus = SecondDec - self.GetDecimalStatus();
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

		public static SuperDec_ExtraDec64_19Decimal operator -(SuperDec_ExtraDec64_19Decimal self, SuperDec_ExtraDec64_19Decimal y)
		{
			bool IsYNegative = (y.GetBoolStatus() == 1) ? true : false;
			//ex. -9 - 9
			if (self.GetBoolStatus() == 1 && IsYNegative == false)
			{// -X - Y
				self.IntValue = self.GetIntValue() + y.GetIntValue();
			}//ex. 9 - (-1)
			else if (self.GetBoolStatus() == 0 && IsYNegative == true)
			{
				//X - (-Y)
				self.IntValue = self.GetIntValue() + y.GetIntValue();
			}
			else
			{
				// X - (Y)
				if (self.GetBoolStatus() == 0)
				{
					// ex. 8 - 9
					if (y.GetIntValue() > self.GetIntValue())
					{
						self.IntValue = y.GetIntValue() - self.GetIntValue();
						self.DecBoolStatus = 1;
					} //ex. 8 - 7
					else
					{
						self.IntValue = self.IntValue - y.GetIntValue();
					}
				}// -X - (Y)
				else
				{
					// ex. -8 - (-9)
					if (self.IntValue > y.GetIntValue())
					{
						self.IntValue = y.GetIntValue() - self.IntValue;
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 - (-5)
						self.IntValue = self.GetIntValue() - y.GetIntValue();
					}
				}
			}
			//Decimal Section
			if (self.GetDecimalStatus() != 0 || y.GetDecimalStatus() != 0)
			{
				//ulong SecondDec = (ulong)(System.Math.Abs(y) - System.Math.Abs(WholeHalfOfY)) * 10000000000000000000;
				// ex. -0.5 - 0.6
				if (self.GetBoolStatus() == 1 && IsYNegative == false)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + y.GetDecimalStatus();
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 1000000000000000000;
						self.IntValue += 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}// ex. 0.5 - (-0.6)
				else if (self.GetBoolStatus() == 0 && IsYNegative)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + y.GetDecimalStatus();
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 1000000000000000000;
						self.IntValue -= 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}
				else
				{
					if (IsYNegative)
					{// ex. -0.7 - (-0.6)
						if (self.GetDecimalStatus() >= y.GetDecimalStatus())
						{
							self.DecimalStatus = self.GetDecimalStatus() - y.GetDecimalStatus();
						}
						else
						{
							self.DecimalStatus = y.GetDecimalStatus() - self.GetDecimalStatus();
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
						if (self.GetDecimalStatus() >= y.GetDecimalStatus())
						{
							self.DecimalStatus = self.GetDecimalStatus() - y.GetDecimalStatus();
						}
						else
						{
							self.DecimalStatus = y.GetDecimalStatus() - self.GetDecimalStatus();
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

		public static SuperDec_ExtraDec64_19Decimal operator -(SuperDec_ExtraDec64_19Decimal self, dynamic y)
		{
			//ex. -9 - 9
			if (self.GetBoolStatus() == 1 && y >= 0)
			{// -X - Y
				self.IntValue = self.GetIntValue() + (uint)y;
			}//ex. 9 - (-1)
			else if (self.GetBoolStatus() == 0 && y < 0)
			{
				//X - (-Y)
				self.IntValue = self.GetIntValue() + (uint)Math.Abs(y);
			}
			else
			{
				// X - (Y)
				if (self.GetBoolStatus() == 0)
				{
					// ex. 8 - 9
					if (y > self.GetIntValue())
					{
						self.IntValue = (uint)y - self.GetIntValue();
						self.DecBoolStatus = 1;
					} //ex. 8 - 7
					else
					{
						self.IntValue = self.IntValue - (uint)y;
					}
				}// -X - (Y)
				else
				{
					uint TempY = (uint)Math.Abs(y);
					// ex. -8 - (-9)
					if (self.IntValue > TempY)
					{
						self.IntValue = TempY - self.IntValue;
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 - (-5)
						self.IntValue = self.GetIntValue() - TempY;
					}
				}
			}
			//Fix potential negative zero
			if (self.IntValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0)
			{
				self.DecBoolStatus = 0;
			}
			return self;
		}

		public static SuperDec_ExtraDec64_19Decimal operator %(SuperDec_ExtraDec64_19Decimal self, int y)
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
					self.IntValue %= (uint)y;
				}
				else
				{
					BigMath.Int128 SelfAsInt128 = (BigMath.Int128)self.DecimalStatus;
					SelfAsInt128 += self.IntValue * 10000000000000000000;
					SelfAsInt128 %= y;
					BigMath.Int128 TempStorage = SelfAsInt128 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage *= 10000000000000000000;
					SelfAsInt128 -= TempStorage;
					self.DecimalStatus = (ulong)SelfAsInt128;
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}

			return self;
		}

		public static SuperDec_ExtraDec64_19Decimal operator %(SuperDec_ExtraDec64_19Decimal self, double y)
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
				uint WholeHalf = (uint)y;
				//Use x Int Operation instead if y has no decimal places
				if (WholeHalf == y)
				{
					if (self.DecimalStatus == 0)
					{
						//Use normal simple (int value) * (int value) if not dealing with any decimals
						self.IntValue %= (uint)y;
					}
					else
					{
						BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
						SelfAsInt128 += self.IntValue * 10000000000000000000;
						SelfAsInt128 *= WholeHalf;
						self.IntValue = (uint)(SelfAsInt128 / 10000000000000000000);
						SelfAsInt128 -= self.IntValue * 10000000000000000000;
						self.DecimalStatus = (uint)SelfAsInt128;
					}
				}
				else
				{
					y -= WholeHalf;
					ulong Decimalhalf;
					if (y == 0.25)
					{
						Decimalhalf = 2500000000000000000;
					}
					else if (y == 0.5)
					{
						Decimalhalf = 5000000000000000000;
					}
					else
					{
						Decimalhalf = ExtractDecimalHalf(y);
					}
					BigMath.Int256 SelfAsInt256 = self.IntValue;
					SelfAsInt256 *= 10000000000000000000;
					SelfAsInt256 += self.DecimalStatus;
					BigMath.Int256 YAsInt256 = WholeHalf;
					YAsInt256 *= 10000000000000000000;
					YAsInt256 += Decimalhalf;
					SelfAsInt256 *= YAsInt256;
					SelfAsInt256 /= 10000000000000000000;
					BigMath.Int256 TempStorage = SelfAsInt256 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000000000000000000;
					SelfAsInt256 -= TempStorage;
					self.DecimalStatus = ForceConvertFromInt256(SelfAsInt256);
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}

			return self;
		}

		public static SuperDec_ExtraDec64_19Decimal operator %(SuperDec_ExtraDec64_19Decimal self, SuperDec_ExtraDec64_19Decimal y)
		{
			if (y.GetIntValue() == 0 && y.GetDecimalStatus() == 0)
			{
				self.IntValue = 0;
				self.DecimalStatus = 0;
				self.DecBoolStatus = 0;
			}
			else
			{
				if (y.GetBoolStatus() == 1) { self.SwapNegativeStatus(); }
				if (self.DecimalStatus == 0 && y.GetDecimalStatus() == 0)
				{//Use normal simple (int value) * (int value) if not dealing with any decimals
					self.IntValue %= y.IntValue;
				}
				else if (y.GetDecimalStatus() == 0)
				{
					BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
					SelfAsInt128 += self.IntValue * 10000000000000000000;
					SelfAsInt128 %= y.IntValue;
					self.IntValue = (uint)(SelfAsInt128 / 10000000000000000000);
					SelfAsInt128 -= self.IntValue * 10000000000000000000;
					self.DecimalStatus = (uint)SelfAsInt128;
				}
				else
				{
					BigMath.Int256 SelfAsInt256 = self.IntValue;
					SelfAsInt256 *= 10000000000000000000;
					SelfAsInt256 += self.DecimalStatus;
					BigMath.Int256 YAsInt256 = y.IntValue;
					YAsInt256 *= 10000000000000000000;
					YAsInt256 += y.DecimalStatus;
					SelfAsInt256 %= YAsInt256;
					SelfAsInt256 /= 10000000000000000000;
					BigMath.Int256 TempStorage = SelfAsInt256 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000000000000000000;
					SelfAsInt256 -= TempStorage;
					self.DecimalStatus = ForceConvertFromInt256(SelfAsInt256);
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static SuperDec_ExtraDec64_19Decimal operator *(SuperDec_ExtraDec64_19Decimal self, SuperDec_ExtraDec64_19Decimal y)
		{
			if (y.GetIntValue() == 0 && y.GetDecimalStatus() == 0)
			{
				self.IntValue = 0;
				self.DecimalStatus = 0;
				self.DecBoolStatus = 0;
			}
			else
			{
				if (y.GetBoolStatus() == 1) { self.SwapNegativeStatus(); }
				if (self.DecimalStatus == 0 && y.GetDecimalStatus() == 0)
				{//Use normal simple (int value) * (int value) if not dealing with any decimals
					self.IntValue *= y.IntValue;
				}
				else if (y.GetDecimalStatus() == 0)
				{
					BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
					SelfAsInt128 += self.IntValue * 10000000000000000000;
					SelfAsInt128 *= y.IntValue;
					self.IntValue = (uint)(SelfAsInt128 / 10000000000000000000);
					SelfAsInt128 -= self.IntValue * 10000000000000000000;
					self.DecimalStatus = (uint)SelfAsInt128;
				}
				else
				{
					//((self.IntValue * 10000000000000000000)+self.DecimalStatus)*(DecimalAsInt+(WholeHalf*10000000000000000000))/10000000000000000000 = ((self.IntValue*10000000000000000000)+self.DecimalStatus))
					BigMath.Int256 SelfAsInt256 = self.IntValue;
					SelfAsInt256 *= 10000000000000000000;
					SelfAsInt256 += self.DecimalStatus;
					BigMath.Int256 YAsInt256 = y.IntValue;
					YAsInt256 *= 10000000000000000000;
					YAsInt256 += y.DecimalStatus;
					SelfAsInt256 *= YAsInt256;
					SelfAsInt256 /= 10000000000000000000;
					BigMath.Int256 TempStorage = SelfAsInt256 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000000000000000000;
					SelfAsInt256 -= TempStorage;
					self.DecimalStatus = ForceConvertFromInt256(SelfAsInt256);
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static SuperDec_ExtraDec64_19Decimal operator *(SuperDec_ExtraDec64_19Decimal self, int y)
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
					self.IntValue *= (uint)y;
				}
				else
				{
					BigMath.Int128 SelfAsInt128 = (BigMath.Int128)self.DecimalStatus;
					SelfAsInt128 += self.IntValue * 10000000000000000000;
					SelfAsInt128 *= y;
					BigMath.Int128 TempStorage = SelfAsInt128 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage *= 10000000000000000000;
					SelfAsInt128 -= TempStorage;
					self.DecimalStatus = (ulong)SelfAsInt128;
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}

			return self;
		}

		public static SuperDec_ExtraDec64_19Decimal operator *(SuperDec_ExtraDec64_19Decimal self, double y)
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
				uint WholeHalf = (uint)y;
				//Use x Int Operation instead if y has no decimal places
				if (WholeHalf == y)
				{
					if (self.DecimalStatus == 0)
					{
						//Use normal simple (int value) * (int value) if not dealing with any decimals
						self.IntValue *= (uint)y;
					}
					else
					{
						BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
						SelfAsInt128 += self.IntValue * 10000000000000000000;
						SelfAsInt128 *= WholeHalf;
						self.IntValue = (uint)(SelfAsInt128 / 10000000000000000000);
						SelfAsInt128 -= self.IntValue * 10000000000000000000;
						self.DecimalStatus = (uint)SelfAsInt128;
					}
				}
				else
				{
					y -= WholeHalf;
					ulong Decimalhalf;
					if (y == 0.25)
					{
						Decimalhalf = 2500000000000000000;
					}
					else if (y == 0.5)
					{
						Decimalhalf = 5000000000000000000;
					}
					else
					{
						Decimalhalf = ExtractDecimalHalf(y);
					}
					//((self.IntValue * 10000000000000000000)+self.DecimalStatus)*(DecimalAsInt+(WholeHalf*10000000000000000000))/10000000000000000000 = ((self.IntValue*10000000000000000000)+self.DecimalStatus))
					BigMath.Int256 SelfAsInt256 = self.IntValue;
					SelfAsInt256 *= 10000000000000000000;
					SelfAsInt256 += self.DecimalStatus;
					BigMath.Int256 YAsInt256 = WholeHalf;
					YAsInt256 *= 10000000000000000000;
					YAsInt256 += Decimalhalf;
					SelfAsInt256 *= YAsInt256;
					SelfAsInt256 /= 10000000000000000000;
					BigMath.Int256 TempStorage = SelfAsInt256 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000000000000000000;
					SelfAsInt256 -= TempStorage;
					self.DecimalStatus = ForceConvertFromInt256(SelfAsInt256);
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}

			return self;
		}

		public static SuperDec_ExtraDec64_19Decimal operator /(SuperDec_ExtraDec64_19Decimal self, SuperDec_ExtraDec64_19Decimal y)
		{
			if (y.GetIntValue() == 0 && y.GetDecimalStatus() == 0)
			{
				Console.WriteLine("Prevented dividing by zero");
			}
			else
			{
				if (y.GetBoolStatus() == 1) { self.SwapNegativeStatus(); }
				if (self.DecimalStatus == 0 && y.GetDecimalStatus() == 0)
				{//Use normal simple (int value) * (int value) if not dealing with any decimals
					self.IntValue /= y.IntValue;
				}
				else if (y.GetDecimalStatus() == 0)
				{
					BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
					SelfAsInt128 += self.IntValue * 10000000000000000000;
					SelfAsInt128 /= y.IntValue;
					self.IntValue = (uint)(SelfAsInt128 / 10000000000000000000);
					SelfAsInt128 -= self.IntValue * 10000000000000000000;
					self.DecimalStatus = (uint)SelfAsInt128;
				}
				else
				{
					//((self.IntValue * 10000000000000000000)+self.DecimalStatus)/(DecimalAsInt+(WholeHalf*10000000000000000000))/10000000000000000000 = ((self.IntValue*10000000000000000000)+self.DecimalStatus))
					BigMath.Int256 SelfAsInt256 = self.IntValue;
					SelfAsInt256 *= 10000000000000000000;
					SelfAsInt256 += self.DecimalStatus;
					BigMath.Int256 YAsInt256 = y.IntValue;
					YAsInt256 *= 10000000000000000000;
					YAsInt256 += y.DecimalStatus;
					SelfAsInt256 /= YAsInt256;
					SelfAsInt256 /= 10000000000000000000;
					BigMath.Int256 TempStorage = SelfAsInt256 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000000000000000000;
					SelfAsInt256 -= TempStorage;
					self.DecimalStatus = ForceConvertFromInt256(SelfAsInt256);
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static SuperDec_ExtraDec64_19Decimal operator /(SuperDec_ExtraDec64_19Decimal self, int y)
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
					self.IntValue *= (uint)y;
				}
				else
				{
					BigMath.Int128 SelfAsInt128 = (BigMath.Int128)self.DecimalStatus;
					SelfAsInt128 += self.IntValue * 10000000000000000000;
					SelfAsInt128 /= y;
					BigMath.Int128 TempStorage = SelfAsInt128 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage *= 10000000000000000000;
					SelfAsInt128 -= TempStorage;
					self.DecimalStatus = (ulong)SelfAsInt128;
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static SuperDec_ExtraDec64_19Decimal operator /(SuperDec_ExtraDec64_19Decimal self, double y)
		{
			if (y == 0)
			{
				Console.WriteLine("Prevented dividing by zero");
			}
			else
			{
				if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
				uint WholeHalf = (uint)y;
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
						BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
						SelfAsInt128 += self.IntValue * 10000000000000000000;
						SelfAsInt128 /= WholeHalf;
						self.IntValue = (uint)(SelfAsInt128 / 10000000000000000000);
						SelfAsInt128 -= self.IntValue * 10000000000000000000;
						self.DecimalStatus = (uint)SelfAsInt128;
					}
				}
				else
				{
					y -= WholeHalf;
					ulong Decimalhalf;
					if (y == 0.25)
					{
						Decimalhalf = 2500000000000000000;
					}
					else if (y == 0.5)
					{
						Decimalhalf = 5000000000000000000;
					}
					else
					{
						Decimalhalf = ExtractDecimalHalf(y);
					}
					//((self.IntValue * 10000000000000000000)+self.DecimalStatus)*(DecimalAsInt+(WholeHalf*10000000000000000000))/10000000000000000000 = ((self.IntValue*10000000000000000000)+self.DecimalStatus))
					BigMath.Int256 SelfAsInt256 = self.IntValue;
					SelfAsInt256 *= 10000000000000000000;
					SelfAsInt256 += self.DecimalStatus;
					BigMath.Int256 YAsInt256 = WholeHalf;
					YAsInt256 *= 10000000000000000000;
					YAsInt256 += Decimalhalf;
					SelfAsInt256 /= YAsInt256;
					SelfAsInt256 /= 10000000000000000000;
					BigMath.Int256 TempStorage = SelfAsInt256 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000000000000000000;
					SelfAsInt256 -= TempStorage;
					self.DecimalStatus = ForceConvertFromInt256(SelfAsInt256);
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static SuperDec_ExtraDec64_19Decimal operator +(SuperDec_ExtraDec64_19Decimal self, double y)
		{
			bool IsYNegative = (y < 0) ? true : false;
			y = Math.Abs(y);
			uint WholeHalfOfY = (uint)Math.Floor(y);
			y -= WholeHalfOfY;
			if (WholeHalfOfY == 0) { }
			else if (self.GetBoolStatus() == 1 && IsYNegative)
			{// -X - Y (ex. -8 + -6)
				self.IntValue = self.GetIntValue() + WholeHalfOfY;
			}
			else if (self.GetBoolStatus() == 0 && IsYNegative == false)
			{
				//X + Y (ex. 8 + 6)
				self.IntValue = self.GetIntValue() + WholeHalfOfY;
			}
			else
			{
				// -X + Y
				if (self.GetBoolStatus() == 1)
				{   //ex. -8 + 9
					if (y > self.GetIntValue())
					{
						self.IntValue = WholeHalfOfY - self.GetIntValue();
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 +  4
						self.IntValue = self.GetIntValue() - WholeHalfOfY;
					}
				}// X-Y
				else
				{
					if (self.GetIntValue() > WholeHalfOfY)
					{//ex. 9 + -6
						self.IntValue = self.GetIntValue() - WholeHalfOfY;
					}
					else
					{//ex. 9 + -10
						self.IntValue = WholeHalfOfY - self.GetIntValue();
						self.DecBoolStatus = 1;
					}
				}
			}
			//Decimal Calculation Section
			if (self.GetBoolStatus() != 0 || y != 0)
			{
				ulong SecondDec = (ulong)(System.Math.Abs(y) - System.Math.Abs(WholeHalfOfY)) * 10000000000000000000;
				// ?.XXXXXX + ?.YYYYYY
				if (self.GetBoolStatus() == 0 && IsYNegative == false)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + SecondDec;
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 999999999999999999;
						self.IntValue += 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}
				// -?.XXXXXX - ?.YYYYYY
				else if (self.GetBoolStatus() == 1 && IsYNegative == true)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + SecondDec;
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 999999999999999999;
						self.IntValue -= 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}
				else
				{
					if (IsYNegative)
					{
						// ex. 0.6 + -0.5
						if (self.GetDecimalStatus() >= SecondDec)
						{
							self.DecimalStatus = self.GetDecimalStatus() - SecondDec;
						}// ex. 0.6 + -.7
						else
						{
							self.DecimalStatus = SecondDec - self.GetDecimalStatus();
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
						if (self.GetDecimalStatus() >= SecondDec)
						{
							self.DecimalStatus = self.GetDecimalStatus() - SecondDec;
						}// ex. -1.6 + 0.7
						else
						{
							self.DecimalStatus = SecondDec - self.GetDecimalStatus();
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

		public static SuperDec_ExtraDec64_19Decimal operator +(SuperDec_ExtraDec64_19Decimal self, SuperDec_ExtraDec64_19Decimal y)
		{
			bool IsYNegative = (y.GetBoolStatus() == 1) ? true : false;
			if (self.GetBoolStatus() == 1 && IsYNegative)
			{// -X - Y (ex. -8 + -6)
				self.IntValue = self.GetIntValue() + y.GetIntValue();
			}
			else if (self.GetBoolStatus() == 0 && IsYNegative == false)
			{
				//X + Y (ex. 8 + 6)
				self.IntValue = self.GetIntValue() + y.GetIntValue();
			}
			else
			{
				// -X + Y
				if (self.GetBoolStatus() == 1)
				{   //ex. -8 + 9
					if (y.GetIntValue() > self.GetIntValue())
					{
						self.IntValue = y.GetIntValue() - self.GetIntValue();
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 +  4
						self.IntValue = self.GetIntValue() - y.GetIntValue();
					}
				}// X + -Y
				else
				{
					if (self.GetIntValue() > y.GetIntValue())
					{//ex. 9 + -6
						self.IntValue = self.GetIntValue() - y.GetIntValue();
					}
					else
					{//ex. 9 + -10
						self.IntValue = y.GetIntValue() - self.IntValue;
						self.DecBoolStatus = 1;
					}
				}
			}
			//Decimal Section
			if (self.GetDecimalStatus() != 0 || y.GetDecimalStatus() != 0)
			{
				// ?.XXXXXX + ?.YYYYYY (ex. 0.9 + 0.2)
				if (self.GetBoolStatus() == 0 && IsYNegative == false)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + y.GetDecimalStatus();
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 999999999999999999;
						self.IntValue += 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}
				// -?.XXXXXX - ?.YYYYYY (ex. -0.9 + -0.2)
				else if (self.GetBoolStatus() == 1 && IsYNegative)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + y.GetDecimalStatus();
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 999999999999999999;
						self.IntValue -= 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}
				else
				{
					if (IsYNegative)
					{
						// ex. 0.6 + -0.5
						if (self.GetDecimalStatus() >= y.GetDecimalStatus())
						{
							self.DecimalStatus = self.GetDecimalStatus() - y.GetDecimalStatus();
						}// ex. 0.6 + -.7
						else
						{
							self.DecimalStatus = y.GetDecimalStatus() - self.GetDecimalStatus();
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
						if (self.GetDecimalStatus() >= y.GetDecimalStatus())
						{
							self.DecimalStatus = self.GetDecimalStatus() - y.GetDecimalStatus();
						}// ex. -1.6 + 0.7
						else
						{
							self.DecimalStatus = y.GetDecimalStatus() - self.GetDecimalStatus();
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

		public static SuperDec_ExtraDec64_19Decimal operator +(SuperDec_ExtraDec64_19Decimal self, dynamic y)
		{
			if (self.GetBoolStatus() == 1 && y < 0)
			{// -X - Y (ex. -8 + -6)
				self.IntValue = self.GetIntValue() + (uint)Math.Abs(y);
			}
			else if (self.GetBoolStatus() == 0 && y >= 0)
			{
				//X + Y (ex. 8 + 6)
				self.IntValue = self.GetIntValue() + (uint)y;
			}
			else
			{
				// -X + Y
				if (self.GetBoolStatus() == 1)
				{   //ex. -8 + 9
					if (y > self.GetIntValue())
					{
						self.IntValue = (uint)y - self.GetIntValue();
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 +  4
						self.IntValue = self.GetIntValue() - (uint)y;
					}
				}// X-Y
				else
				{
					uint TempY = Math.Abs(y);
					if (self.GetIntValue() > TempY)
					{//ex. 9 + -6
						self.IntValue = self.GetIntValue() - TempY;
					}
					else
					{//ex. 9 + -10
						self.IntValue = TempY - self.GetIntValue();
						self.DecBoolStatus = 1;
					}
				}
			}
			//Fix potential negative zero
			if (self.IntValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
			return self;
		}

		// Self Less than Value
		public static bool operator <(SuperDec_ExtraDec64_19Decimal self, dynamic Value)
		{
			if (Value is SuperDec_ExtraDec64_19Decimal)
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
						BigMath.Int128 SelfAsInt256 = self.IntValue;
						SelfAsInt256 *= 10000000000000000000;
						SelfAsInt256 += self.DecimalStatus;
						BigMath.Int128 ValueAsInt256 = Value.IntValue;
						ValueAsInt256 *= 10000000000000000000;
						ValueAsInt256 += Value.DecimalStatus;
						//Both are either positive or negative numbers
						if (self.DecBoolStatus == 0)
						{
							return SelfAsInt256 < ValueAsInt256;
						}
						else
						{//Larger number = farther down into negative
							return !(SelfAsInt256 < ValueAsInt256);
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
					uint WholeHalf = (uint)Value;
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
							BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
							SelfAsInt128 += self.IntValue * 10000000000000000000;
							if (self.DecBoolStatus == 0) { return SelfAsInt128 < (WholeHalf * 10000000000000000000); }
							else { return !(SelfAsInt128 < (WholeHalf * 10000000000000000000)); }
						}
					}
					else
					{
						Value -= WholeHalf;
						ulong Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500000000000000000;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000000000000000000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalf(Value);
						}
						BigMath.Int128 SelfAsInt128 = self.IntValue;
						SelfAsInt128 *= 10000000000000000000;
						SelfAsInt128 += self.DecimalStatus;
						BigMath.Int128 ValueAsInt128 = WholeHalf;
						ValueAsInt128 *= 10000000000000000000;
						ValueAsInt128 += Decimalhalf;
						if (self.DecBoolStatus == 0) { return SelfAsInt128 < ValueAsInt128; }
						else { return !(SelfAsInt128 < ValueAsInt128); }
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

		// Self Less than or equal to Value
		public static bool operator <=(SuperDec_ExtraDec64_19Decimal self, dynamic Value)
		{
			if (Value is SuperDec_ExtraDec64_19Decimal)
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
						BigMath.Int128 SelfAsInt256 = self.IntValue;
						SelfAsInt256 *= 10000000000000000000;
						SelfAsInt256 += self.DecimalStatus;
						BigMath.Int128 ValueAsInt256 = Value.IntValue;
						ValueAsInt256 *= 10000000000000000000;
						ValueAsInt256 += Value.DecimalStatus;
						//Both are either positive or negative numbers
						if (self.DecBoolStatus == 0)
						{
							return SelfAsInt256 <= ValueAsInt256;
						}
						else
						{//Larger number = farther down into negative
							return !(SelfAsInt256 <= ValueAsInt256);
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
					uint WholeHalf = (uint)Value;
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
							BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
							SelfAsInt128 += self.IntValue * 10000000000000000000;
							if (self.DecBoolStatus == 0) { return SelfAsInt128 <= (WholeHalf * 10000000000000000000); }
							else { return !(SelfAsInt128 <= (WholeHalf * 10000000000000000000)); }
						}
					}
					else
					{
						Value -= WholeHalf;
						ulong Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500000000000000000;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000000000000000000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalf(Value);
						}
						BigMath.Int128 SelfAsInt128 = self.IntValue;
						SelfAsInt128 *= 10000000000000000000;
						SelfAsInt128 += self.DecimalStatus;
						BigMath.Int128 ValueAsInt128 = WholeHalf;
						ValueAsInt128 *= 10000000000000000000;
						ValueAsInt128 += Decimalhalf;
						if (self.DecBoolStatus == 0) { return SelfAsInt128 <= ValueAsInt128; }
						else { return !(SelfAsInt128 <= ValueAsInt128); }
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

		// Self Greater than Value
		public static bool operator >(SuperDec_ExtraDec64_19Decimal self, dynamic Value)
		{
			if (Value is SuperDec_ExtraDec64_19Decimal)
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
						//((self.IntValue * 10000000000000000000)+self.DecimalStatus)*(DecimalAsInt+(WholeHalf*10000000000000000000))/10000000000000000000 = ((self.IntValue*10000000000000000000)+self.DecimalStatus))
						BigMath.Int128 SelfAsInt256 = self.IntValue;
						SelfAsInt256 *= 10000000000000000000;
						SelfAsInt256 += self.DecimalStatus;
						BigMath.Int128 ValueAsInt256 = Value.IntValue;
						ValueAsInt256 *= 10000000000000000000;
						ValueAsInt256 += Value.DecimalStatus;
						//Both are either positive or negative numbers
						if (self.DecBoolStatus == 0)
						{
							return SelfAsInt256 > ValueAsInt256;
						}
						else
						{//Larger number = farther down into negative
							return !(SelfAsInt256 > ValueAsInt256);
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
					uint WholeHalf = (uint)Value;
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
							BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
							SelfAsInt128 += self.IntValue * 10000000000000000000;
							if (self.DecBoolStatus == 0){ return SelfAsInt128 > (WholeHalf * 10000000000000000000); }
							else { return !(SelfAsInt128 > (WholeHalf * 10000000000000000000)); }
						}
					}
					else
					{
						Value -= WholeHalf;
						ulong Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500000000000000000;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000000000000000000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalf(Value);
						}
						BigMath.Int128 SelfAsInt128 = self.IntValue;
						SelfAsInt128 *= 10000000000000000000;
						SelfAsInt128 += self.DecimalStatus;
						BigMath.Int128 ValueAsInt128 = WholeHalf;
						ValueAsInt128 *= 10000000000000000000;
						ValueAsInt128 += Decimalhalf;
						if (self.DecBoolStatus == 0) { return SelfAsInt128 >= ValueAsInt128; }
						else { return !(SelfAsInt128 > ValueAsInt128); }
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

		// Self Greater than or Equal to Value
		public static bool operator >=(SuperDec_ExtraDec64_19Decimal self, dynamic Value)
		{
			if (Value is SuperDec_ExtraDec64_19Decimal)
			{
				if (self.DecBoolStatus == Value.DecBoolStatus && self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
				else
				{
					// Positive Self >= -Value
					if (Value.DecBoolStatus==1 && self.DecBoolStatus == 0) { return true; }
					// Negative Self >= Value
					else if (Value.DecBoolStatus==0 && self.DecBoolStatus == 1) { return false; }
					else
					{
						BigMath.Int128 SelfAsInt256 = self.IntValue;
						SelfAsInt256 *= 10000000000000000000;
						SelfAsInt256 += self.DecimalStatus;
						BigMath.Int128 ValueAsInt256 = Value.IntValue;
						ValueAsInt256 *= 10000000000000000000;
						ValueAsInt256 += Value.DecimalStatus;
						//Both are either positive or negative numbers
						if(self.DecBoolStatus==0)
						{
							return SelfAsInt256 >= ValueAsInt256;
						}
						else
						{//Larger number = farther down into negative
							return !(SelfAsInt256 >= ValueAsInt256);
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
					uint WholeHalf = (uint)Value;
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
							BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
							SelfAsInt128 += self.IntValue * 10000000000000000000;
							if (self.DecBoolStatus == 0) { return SelfAsInt128 >= (WholeHalf * 10000000000000000000); }
							else { return !(SelfAsInt128 >= (WholeHalf * 10000000000000000000)); }
						}
					}
					else
					{
						Value -= WholeHalf;
						ulong Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500000000000000000;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000000000000000000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalf(Value);
						}
						BigMath.Int128 SelfAsInt128 = self.IntValue;
						SelfAsInt128 *= 10000000000000000000;
						SelfAsInt128 += self.DecimalStatus;
						BigMath.Int128 ValueAsInt128 = WholeHalf;
						ValueAsInt128 *= 10000000000000000000;
						ValueAsInt128 += Decimalhalf;
						if (self.DecBoolStatus == 0) { return SelfAsInt128 >= ValueAsInt128; }
						else { return !(SelfAsInt128 >= ValueAsInt128); }
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

		// Equality operator for comparing self to int type value
		public static bool operator ==(SuperDec_ExtraDec64_19Decimal self, dynamic Value)
		{
			if (Value is SuperDec_ExtraDec64_19Decimal)
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
					uint WholeHalf = (uint)Value;
					//Use x Int Operation instead if Value has no decimal places
					if (WholeHalf == Value)
					{
						if (self.DecimalStatus == 0)
						{
							return self.IntValue == WholeHalf;
						}
						else
						{
							BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
							SelfAsInt128 += self.IntValue * 10000000000000000000;
							return SelfAsInt128 == (WholeHalf * 10000000000000000000);
						}
					}
					else
					{
						Value -= WholeHalf;
						ulong Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500000000000000000;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000000000000000000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalf(Value);
						}
						//((self.IntValue * 10000000000000000000)+self.DecimalStatus)*(DecimalAsInt+(WholeHalf*10000000000000000000))/10000000000000000000 = ((self.IntValue*10000000000000000000)+self.DecimalStatus))
						BigMath.Int128 SelfAsInt128 = self.IntValue;
						SelfAsInt128 *= 10000000000000000000;
						SelfAsInt128 += self.DecimalStatus;
						BigMath.Int128 ValueAsInt128 = WholeHalf;
						ValueAsInt128 *= 10000000000000000000;
						ValueAsInt128 += Decimalhalf;
						return SelfAsInt128 == ValueAsInt128;
					}
				}
			}
			else if (Value is String)
			{
				return (String) Value==(String) self;
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

		// Inequality operator for comparing self to multiple value types
		public static bool operator !=(SuperDec_ExtraDec64_19Decimal self, dynamic Value)
		{
			if (Value is SuperDec_ExtraDec64_19Decimal)
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
					uint WholeHalf = (uint)Value;
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
							BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
							SelfAsInt128 += self.IntValue * 10000000000000000000;
							return SelfAsInt128 != (WholeHalf * 10000000000000000000);
						}
					}
					else
					{
						Value -= WholeHalf;
						ulong Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500000000000000000;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000000000000000000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalf(Value);
						}
						BigMath.Int128 SelfAsInt128 = self.IntValue;
						SelfAsInt128 *= 10000000000000000000;
						SelfAsInt128 += self.DecimalStatus;
						BigMath.Int128 ValueAsInt128 = WholeHalf;
						ValueAsInt128 *= 10000000000000000000;
						ValueAsInt128 += Decimalhalf;
						return SelfAsInt128 != ValueAsInt128;
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

		public override bool Equals(object obj)
		{
			if (obj == null || GetType() != obj.GetType()) { return false; }

			try
			{
				return this == (SuperDec_ExtraDec64_19Decimal)obj;
			}
			catch
			{
				return false;
			}
		}

		public byte GetBoolStatus()
		{
			return DecBoolStatus;
		}

		public ulong GetDecimalStatus()
		{
			return DecimalStatus;
		}

		// Override the Object.GetHashCode() method:
		public override int GetHashCode()
		{
			if (DecBoolStatus == 1)
			{
				return (int)(IntValue / 2 - 2147483648);
			}
			else
			{
				return (int)(IntValue / 2);
			}
		}

		/// <summary>
		///
		/// </summary>
		/// <returns></returns>
		public ulong GetIntValue()
		{
			return IntValue;
		}

		public int GetIntValueAsInt32()
		{
			return (int)this;
		}

		public long GetIntValueAsInt64()
		{
			return (long)this;
		}

		public void SwapNegativeStatus()
		{
			if (DecBoolStatus == 1) { DecBoolStatus = 0; }
			else { DecBoolStatus = 1; }
		}

		//Returns value of highest non-infinite/Special Decimal State Value that can store
		public SuperDec_ExtraDec64_19Decimal Maximum()
		{
			SuperDec_ExtraDec64_19Decimal NewSelf;
			NewSelf.IntValue = 18446744073709551615;
			NewSelf.DecimalStatus = 9999999999999999999;
			NewSelf.DecBoolStatus = 0;
			return NewSelf;
		}

		//Returns value of minimum non-infinite/Special Decimal State Value that can store
		public SuperDec_ExtraDec64_19Decimal Minimum()
		{
			SuperDec_ExtraDec64_19Decimal NewSelf;
			NewSelf.IntValue = 18446744073709551615;
			NewSelf.DecimalStatus = 9999999999999999999;
			NewSelf.DecBoolStatus = 1;
			return NewSelf;
		}

		public bool IsInfinity()
		{
			//Negative Infinity
			if(DecBoolStatus==255)
			{ return true; }
			//Positive Infinity
			else if (DecBoolStatus == 254)
			{ return true; }
			else { return false; }
		}

		public float AsFloat() { return (float)this; }
		public double AsDouble() { return (double)this; }
		public int AsInt() { return (int)this; }
		public string AsString() { return (string)this; }
	}
}
