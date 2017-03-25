﻿/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
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
	public partial struct SmallDec : IComparable<SmallDec>
	{
		public static Tuple<string, SmallDec> ConvertTuple(Tuple<string, dynamic> Value)
		{
			Tuple<string, SmallDec> self = Tuple.Create(Value.Item1, (SmallDec)Value.Item2);
			return self;
		}
		//public static implicit operator Tuple<string, SmallDec>(Tuple<string, dynamic> Value)
		//{
		//	return ConvertTuple(Value);
		//}

		public static dynamic DynamicMax(dynamic LeftSide, dynamic RightSide)
		{
			SmallDec LeftSideAsType = (SmallDec)LeftSide;
			SmallDec RightSideAsType = (SmallDec)RightSide;
			if (LeftSideAsType > RightSide) { return LeftSideAsType; }
			else { return RightSideAsType; }
		}

		public static dynamic DynamicMin(dynamic LeftSide, dynamic RightSide)
		{
			if (LeftSide < RightSide) { return LeftSide; }
			else { return RightSide; }
		}
	}
	//class SmallDecTuple : Tuple<string, SmallDec>
	//{
	//}
}
