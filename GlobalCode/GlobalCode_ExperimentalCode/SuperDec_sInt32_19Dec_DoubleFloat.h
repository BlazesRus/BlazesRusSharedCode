
#include "CustomDec.h"

	class DLL_API SuperDec_sInt32_19Dec_DoubleFloat
	{
		signed __int32 IntValue;
		unsigned __int64 DecimalStatus;
		DoubleFloatingInt TrailingDec;
		//************************************
		// Method:    AsInt32
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::AsInt32
		// Access:    private
		// Returns:   signed __int32
		// Qualifier:
		//************************************
		signed __int32 AsInt32();
		//************************************
		// Method:    AsDouble
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::AsDouble
		// Access:    private
		// Returns:   double
		// Qualifier:
		//************************************
		double AsDouble();
		//************************************
		// Method:    AsString
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::AsString
		// Access:    private
		// Returns:   std::string
		// Qualifier:
		//************************************
		std::string AsString();
		//************************************
		// Method:    ApplyAddition
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::ApplyAddition
		// Access:    private
		// Returns:   void
		// Qualifier:
		// Parameter: ValueType Value
		//************************************
		template <typename ValueType>
		void ApplyIntAddition(ValueType Value);
		SuperDec_sInt32_19Dec_DoubleFloat operator+(unsigned int Value) { ApplyIntAddition(Value); };
		SuperDec_sInt32_19Dec_DoubleFloat operator+(signed int Value) { ApplyIntAddition(Value); };
		SuperDec_sInt32_19Dec_DoubleFloat operator+(unsigned __int64 Value) { ApplyIntAddition(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator+(signed __int64 Value) { ApplyIntAddition(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator+(unsigned __int16 Value) { ApplyIntAddition(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator+(signed __int16 Value) { ApplyIntAddition(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator+(unsigned __int8 Value) { ApplyIntAddition(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator+(signed __int8 Value) { ApplyIntAddition(Value); }
		//************************************
		// Method:    operator+
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::operator+
		// Access:    private
		// Returns:   SuperDec_sInt32_19Dec_DoubleFloat
		// Qualifier:
		// Parameter: double Value
		//************************************
		SuperDec_sInt32_19Dec_DoubleFloat operator+(double Value);
		//************************************
		// Method:    operator+
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::operator+
		// Access:    private
		// Returns:   SuperDec_sInt32_19Dec_DoubleFloat
		// Qualifier:
		// Parameter: std::string Value
		//************************************
		SuperDec_sInt32_19Dec_DoubleFloat operator+(std::string Value);
		//************************************
		// Method:    ApplySubtraction
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::ApplySubtraction
		// Access:    private
		// Returns:   void
		// Qualifier:
		// Parameter: ValueType Value
		//************************************
		template <typename ValueType>
		void ApplyIntSubtraction(ValueType Value);
		SuperDec_sInt32_19Dec_DoubleFloat operator-(unsigned int Value) { ApplyIntSubtraction(Value); };
		SuperDec_sInt32_19Dec_DoubleFloat operator-(signed int Value) { ApplyIntSubtraction(Value); };
		SuperDec_sInt32_19Dec_DoubleFloat operator-(unsigned __int64 Value) { ApplyIntSubtraction(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator-(signed __int64 Value) { ApplyIntSubtraction(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator-(unsigned __int16 Value) { ApplyIntSubtraction(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator-(signed __int16 Value) { ApplyIntSubtraction(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator-(unsigned __int8 Value) { ApplyIntSubtraction(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator-(signed __int8 Value) { ApplyIntSubtraction(Value); }
		//************************************
		// Method:    ApplyEqual
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::ApplyEqual
		// Access:    private
		// Returns:   void
		// Qualifier:
		// Parameter: ValueType Value
		//************************************
		template <typename ValueType>
		void ApplyIntEqual(ValueType Value);
		SuperDec_sInt32_19Dec_DoubleFloat operator=(std::string Value);
		SuperDec_sInt32_19Dec_DoubleFloat operator=(unsigned int Value) { ApplyIntEqual(Value); };
		SuperDec_sInt32_19Dec_DoubleFloat operator=(signed int Value) { ApplyIntEqual(Value); };
		SuperDec_sInt32_19Dec_DoubleFloat operator=(unsigned __int64 Value) { ApplyIntEqual(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator=(signed __int64 Value) { ApplyIntEqual(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator=(unsigned __int16 Value) { ApplyIntEqual(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator=(signed __int16 Value) { ApplyIntEqual(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator=(unsigned __int8 Value) { ApplyIntEqual(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator=(signed __int8 Value) { ApplyIntEqual(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator=(double Value);
		//************************************
		// Method:    ApplyModulus
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::ApplyModulus
		// Access:    private
		// Returns:   void
		// Qualifier:
		// Parameter: ValueType Value
		//************************************
		template <typename ValueType>
		void ApplyModulus(ValueType Value);
		SuperDec_sInt32_19Dec_DoubleFloat operator%(unsigned int Value) { ApplyModulus(Value); };
		SuperDec_sInt32_19Dec_DoubleFloat operator%(signed int Value) { ApplyModulus(Value); };
		SuperDec_sInt32_19Dec_DoubleFloat operator%(unsigned __int64 Value) { ApplyModulus(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator%(signed __int64 Value) { ApplyModulus(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator%(unsigned __int16 Value) { ApplyModulus(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator%(signed __int16 Value) { ApplyModulus(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator%(unsigned __int8 Value) { ApplyModulus(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator%(signed __int8 Value) { ApplyModulus(Value); }
		//Value to power of Value
		SuperDec_sInt32_19Dec_DoubleFloat operator^(unsigned int Value);
		//************************************
		// Method:    ApplyIntCompare
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::ApplyIntCompare
		// Access:    private
		// Returns:   bool
		// Qualifier:
		// Parameter: SuperDec_sInt32_19Dec_DoubleFloat c1
		// Parameter: ValueType Value
		//************************************
		template <typename ValueType>
		bool ApplyIntCompare(SuperDec_sInt32_19Dec_DoubleFloat c1, ValueType Value);
		//************************************
		// Method:    ApplyIntNotEquals
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::ApplyIntNotEquals
		// Access:    private
		// Returns:   bool
		// Qualifier:
		// Parameter: SuperDec_sInt32_19Dec_DoubleFloat c1
		// Parameter: ValueType Value
		//************************************
		template <typename ValueType>
		bool ApplyIntNotEquals(SuperDec_sInt32_19Dec_DoubleFloat c1, ValueType Value);
		friend bool operator== (const SuperDec_sInt32_19Dec_DoubleFloat &c1, unsigned int &c2) { return ApplyIntCompare(c1, c2); };
		friend bool operator!= (const SuperDec_sInt32_19Dec_DoubleFloat &c1, unsigned int &c2) { return ApplyIntNotEquals(c1, c2); };
		//************************************
		// Method:    operator*
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::operator*
		// Access:    private
		// Returns:   SuperDec_sInt32_19Dec_DoubleFloat
		// Qualifier:
		// Parameter: double Value
		//************************************
		SuperDec_sInt32_19Dec_DoubleFloat operator*(double Value);
		template <typename ValueType>
		void ApplyIntMultiply(ValueType Value)
		{
#		if defined SuperDec_SignedIntStatus
			if(DecimalStatus==0)
			{
				IntValue *= Value;
			}
			else
			{
				signed __int64 DecRep = DecAsSignedInt();
				DecRep *= Value;
				ConvertFromDecRep(DecRep);
			}
#		else
			signed __int64 DecRep = DecAsSignedInt();
			DecRep *= Value;
			ConvertFromDecRep(DecRep);
#		endif
		}
		SuperDec_sInt32_19Dec_DoubleFloat operator*(unsigned int Value) { ApplyIntMultiply(Value); };
		SuperDec_sInt32_19Dec_DoubleFloat operator*(signed int Value) { ApplyIntMultiply(Value); };
		SuperDec_sInt32_19Dec_DoubleFloat operator*(unsigned __int64 Value) { ApplyIntMultiply(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator*(signed __int64 Value) { ApplyIntMultiply(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator*(unsigned __int16 Value) { ApplyIntMultiply(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator*(signed __int16 Value) { ApplyIntMultiply(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator*(unsigned __int8 Value) { ApplyIntMultiply(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator*(signed __int8 Value) { ApplyIntMultiply(Value); }
		//************************************
		// Method:    operator/
		// FullName:  SuperDec_sInt32_19Dec_DoubleFloat::operator/
		// Access:    private
		// Returns:   SuperDec_sInt32_19Dec_DoubleFloat
		// Qualifier:
		// Parameter: double Value
		//************************************
		SuperDec_sInt32_19Dec_DoubleFloat operator/(double Value);
		template <typename ValueType>
		void ApplyIntDivide(ValueType Value)
		{
			signed __int64 DecRep = DecAsSignedInt();
			DecRep /= Value;
			ConvertFromDecRep(DecRep);
		}
		SuperDec_sInt32_19Dec_DoubleFloat operator/(unsigned int Value) { ApplyIntDivide(Value); };
		SuperDec_sInt32_19Dec_DoubleFloat operator/(signed int Value) { ApplyIntDivide(Value); };
		SuperDec_sInt32_19Dec_DoubleFloat operator/(unsigned __int64 Value) { ApplyIntDivide(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator/(signed __int64 Value) { ApplyIntDivide(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator/(unsigned __int16 Value) { ApplyIntDivide(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator/(signed __int16 Value) { ApplyIntDivide(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator/(unsigned __int8 Value) { ApplyIntDivide(Value); }
		SuperDec_sInt32_19Dec_DoubleFloat operator/(signed __int8 Value) { ApplyIntDivide(Value); }
	};

	template <typename ValueType>
	void SuperDec_sInt32_19Dec_DoubleFloat::ApplyIntAddition(ValueType Value)
	{
#	if defined SuperDec_SignedIntStatus
		IntValue += Value;
#	elif defined SuperDec_UnsignedBoolean
		if(DecBoolStatus==0)
		{
			if(Value<0)
			{
				if(Value>IntValue)
				{
					IntValue = Value - IntValue;
					DecBoolStatus = 1;
				}
				else
				{
				}
			}
			else
			{
			}
		}
		else if(DecBoolStatus==1)
		{
		}
		else//Other Values used for special Decimal Statuses etc
		{
		}
		if(IntValue==0&&DecBoolStatus==1)//Fix so negative zero is positive zero
		{
			DecBoolStatus = 0;
		}
#	else//Unsigned Version (Stored data in Decimal Status)

#	endif
	}

	template <typename ValueType>
	void SuperDec_sInt32_19Dec_DoubleFloat::ApplyIntSubtraction(ValueType Value)
	{
		IntValue -= Value;
	}

	template <typename ValueType>
	void SuperDec_sInt32_19Dec_DoubleFloat::ApplyIntEqual(ValueType Value)
	{
	}

	template <typename ValueType>
	void SuperDec_sInt32_19Dec_DoubleFloat::ApplyModulus(ValueType Value)
	{
		IntValue %= Value;
	}

	template <typename ValueType>
	bool SuperDec_sInt32_19Dec_DoubleFloat::ApplyIntCompare(SuperDec_sInt32_19Dec_DoubleFloat c1, ValueType Value)
	{
		return c1.IntValue == Value&&c1.DecimalStatus == 0;
	}

	template <typename ValueType>
	bool SuperDec_sInt32_19Dec_DoubleFloat::ApplyIntNotEquals(SuperDec_sInt32_19Dec_DoubleFloat c1, ValueType Value)
	{
		return !ApplyIntCompare(c1, Value);
	}

