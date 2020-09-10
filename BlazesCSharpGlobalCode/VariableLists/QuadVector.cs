// ***********************************************************************
// Assembly         : BlazesCSharpGlobalCode
// Author           : BlazesRus
// Created          : 07-17-2018
//
// Last Modified By : BlazesRus
// Last Modified On : 07-19-2018
// ***********************************************************************
// <copyright file="QuadVector.cs" company="">
//     Copyright ©  2018
// </copyright>
// <summary></summary>
// ***********************************************************************
using CSharpGlobalCode.ExperimentalCode;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpGlobalCode.VariableLists
{
	/// <summary>
	/// 4 Coordinate Vector (X,Y,Z,W) (C# version of my QuadVector with MediumDec used instead of double)
	/// </summary>
	public class QuadVector
    {
		/// <summary>
		/// The position x
		/// </summary>
		public MediumDec PositionX = MediumDec.Zero;
		/// <summary>
		/// The position y
		/// </summary>
		public MediumDec PositionY = MediumDec.Zero;
		/// <summary>
		/// The position z
		/// </summary>
		public MediumDec PositionZ = MediumDec.Zero;
		/// <summary>
		/// The position w
		/// </summary>
		public MediumDec PositionW = MediumDec.Zero;
		//Store values in Position in vector
		/// <summary>
		/// Stores the TempValue inside position index.
		/// </summary>
		/// <param name="index">The index.</param>
		/// <param name="TempValue">The temporary value.</param>
		public void StoreInVectorIndex(int index, MediumDec TempValue)
        {
            if (index == 0) { PositionX = TempValue; }
            else if (index == 1) { PositionY = TempValue; }
            else if (index == 2) { PositionZ = TempValue; }
            else if (index == 3) { PositionW = TempValue; }
        }
		//Get value based on index value
		/// <summary>
		/// Gets the vector value.
		/// </summary>
		/// <param name="index">The index.</param>
		/// <returns>MediumDec.</returns>
		public MediumDec GetVectorValue(int index)
        {
            if (index == 0) { return PositionX; }
            else if (index == 1) { return PositionY; }
            else if (index == 2) { return PositionZ; }
            else { return PositionW; }
        }
		/// <summary>
		/// Reconstruct variables back into string format that Havok uses in files(0.000000 0.000000 0.000000 0.000000)
		/// </summary>
		/// <returns>System.String.</returns>
		public string ConvertToString()
        {
            string TempString = "(";
            TempString += PositionX.ToFullString();
            TempString += " ";
            TempString += PositionY.ToFullString();
            TempString += " ";
            TempString += PositionZ.ToFullString();
            TempString += " ";
            TempString += PositionW.ToFullString();
            TempString += ")";
            return TempString;
        }
		/// <summary>
		/// Converts to list.
		/// </summary>
		/// <returns>List&lt;MediumDec&gt;.</returns>
		public List<MediumDec> ConvertToList()
        {
            List<MediumDec> TempValue = new List<MediumDec>();
            for (int i = 0; i < 4; i++)
            {
                TempValue.Add(GetVectorValue(i));
            }
            return TempValue;
        }
		/// <summary>
		/// Reads the quad vector from string.
		/// </summary>
		/// <param name="LineString">The line string.</param>
		public void ReadQuadVectorFromString(string LineString)
        {
            //Current character loaded in steam
            char StringChar;
            //Current Characters worth of string found of Double Value
            string PartialSearchBuffer = "";
            //Temporary Storage of converted double value
            MediumDec StorageTemp;
            //Vector index of value to store
            byte VectorIndex = 0;
            //Scanning Double value check for index
            bool ScanningValue = false;
            //Total size of LineString to load
            int StringSize = LineString.Length;
            for (int i = 0; i < StringSize && VectorIndex < 4; ++i)
            {
                StringChar = LineString[i];
                if (StringChar == ' ' || StringChar == '	' || StringChar == ')'&& PartialSearchBuffer != "")
                {
                    if (ScanningValue)
                    {
                        StorageTemp = (MediumDec) PartialSearchBuffer;
                        StoreInVectorIndex(VectorIndex, StorageTemp);
                        PartialSearchBuffer = "";
                        VectorIndex++;
                    }
                }
                else if (StringChar == '.' || StringChar == '0' || StringChar == '1' || StringChar == '2' || StringChar == '3' || StringChar == '4' || StringChar == '5' || StringChar == '6' || StringChar == '7' || StringChar == '8' || StringChar == '9' || StringChar == '-')
                {
                    PartialSearchBuffer += StringChar;
                    if (ScanningValue == false) { ScanningValue = true; }
                }
            }
        }

		/// <summary>
		/// Performs an explicit conversion from <see cref="System.String"/> to <see cref="QuadVector"/>.
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <returns>The result of the conversion.</returns>
		public static explicit operator QuadVector(string LineString)
        {
            return new QuadVector(LineString);
        }

		/// <summary>
		/// Initializes a new instance of the <see cref="QuadVector"/> class.
		/// </summary>
		/// <param name="LineString">The line string.</param>
		public QuadVector(string LineString)
        {
            //Current character loaded in steam
            char StringChar;
            //Current Characters worth of string found of Double Value
            string PartialSearchBuffer = "";
            //Temporary Storage of converted double value
            MediumDec StorageTemp;
            //Vector index of value to store
            byte VectorIndex = 0;
            //Scanning Double value check for index
            bool ScanningValue = false;
            //Total size of LineString to load
            int StringSize = LineString.Length;
            for (int i = 0; i < StringSize && VectorIndex < 4; ++i)
            {
                StringChar = LineString[i];
                if (StringChar == ' ' || StringChar == '	' || StringChar == ')' && PartialSearchBuffer != "")
                {
                    if (ScanningValue)
                    {
                        StorageTemp = (MediumDec)PartialSearchBuffer;
                        StoreInVectorIndex(VectorIndex, StorageTemp);
                        PartialSearchBuffer = "";
                        VectorIndex++;
                    }
                }
                else if (StringChar == '.' || StringChar == '0' || StringChar == '1' || StringChar == '2' || StringChar == '3' || StringChar == '4' || StringChar == '5' || StringChar == '6' || StringChar == '7' || StringChar == '8' || StringChar == '9' || StringChar == '-')
                {
                    PartialSearchBuffer += StringChar;
                    if (ScanningValue == false) { ScanningValue = true; }
                }
            }
        }
		/// <summary>
		/// Initializes a new instance of the <see cref="QuadVector"/> class.
		/// </summary>
		/// <param name="x">The x.</param>
		/// <param name="y">The y.</param>
		/// <param name="z">The z.</param>
		/// <param name="w">The w.</param>
		public QuadVector(MediumDec x, MediumDec y, MediumDec z, MediumDec w)
        {
            PositionX = x;
            PositionY = y;
            PositionZ = z;
            PositionW = w;
        }

		/// <summary>
		/// Initializes a new instance of the <see cref="QuadVector"/> class.
		/// </summary>
		public QuadVector()
        {
            PositionX = MediumDec.Zero;
            PositionY = MediumDec.Zero;
            PositionZ = MediumDec.Zero;
            PositionW = MediumDec.Zero;
        }
    }
	/// <summary>
	/// List of (X,Y,Z,W) vector(C# version of my QuadVectorList with MediumDec used instead of double)
	/// Implements the <see cref="System.Collections.Generic.List{CSharpGlobalCode.VariableLists.QuadVector}" />
	/// </summary>
	/// <seealso cref="System.Collections.Generic.List{CSharpGlobalCode.VariableLists.QuadVector}" />
	public class QuadVectorList : List<QuadVector>
    {
		/// <summary>
		/// Adds the data.
		/// </summary>
		/// <returns>System.Int32.</returns>
		public int AddData()
        {
            int Index = Count;
            Add(new QuadVector());
            return Index;
        }

		/// <summary>
		/// Converts one or more lines of QuadVectors into QuadVectorList for LineString
		/// </summary>
		/// <param name="LineString">The line string.</param>
		public void ConvertStringToList(string LineString)
        {
            if (Count != 0)
            {
                Clear();
            }
            QuadVector CurrentQuadVector = new QuadVector();
            //Current character loaded in steam
            char StringChar;
            //Current Characters worth of string found of Double Value
            string PartialSearchBuffer = "";
            //Temporary Storage of converted double value
            MediumDec StorageTemp;
            //Vector index of value to store
            byte VectorIndex = 0;
            //Scanning Double value check for index
            bool ScanningValue = false;
            //Total size of LineString to load
            int StringSize = LineString.Length;
            for (int i = 0; i < StringSize; ++i)
            {
                StringChar = LineString[i];
                if (StringChar == ')')
                {
                    Add(CurrentQuadVector);
                    VectorIndex = 0;
                }
                else if (StringChar == ' ' || StringChar == '	' && PartialSearchBuffer != "")
                {
                    if (VectorIndex == 4)//Code caveat in case of slight format change of having no ')' in formating
                    {
                        Add(CurrentQuadVector);
                        VectorIndex = 0;
                    }
                    if (ScanningValue)
                    {
                        StorageTemp = (MediumDec)PartialSearchBuffer;
                        CurrentQuadVector.StoreInVectorIndex(VectorIndex, StorageTemp);
                        PartialSearchBuffer = "";
                        VectorIndex++;
                    }
                }
                else if (StringChar == '.' || StringChar == '0' || StringChar == '1' || StringChar == '2' || StringChar == '3' || StringChar == '4' || StringChar == '5' || StringChar == '6' || StringChar == '7' || StringChar == '8' || StringChar == '9' || StringChar == '-')
                {
                    PartialSearchBuffer += StringChar;
                    if (ScanningValue == false) { ScanningValue = true; }
                }
            }
            if (VectorIndex == 4)//Code caveat in case of slight format change of having no ) in formating
            {
                Add(CurrentQuadVector);
            }
        }

		/// <summary>
		/// Initializes a new instance of the <see cref="QuadVectorList"/> class.
		/// </summary>
		/// <param name="Value">The value.</param>
		public QuadVectorList(string Value)
        {
            ConvertStringToList(Value);
        }

		/// <summary>
		/// Performs an explicit conversion from <see cref="System.String"/> to <see cref="QuadVectorList"/>.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>The result of the conversion.</returns>
		public static explicit operator QuadVectorList(string Value)
        {
            return new QuadVectorList(Value);
        }

		/// <summary>
		/// Initializes a new instance of the <see cref="QuadVectorList"/> class.
		/// </summary>
		public QuadVectorList() { }
    }
}
