using CSharpGlobalCode.GlobalCode_ExperimentalCode;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpGlobalCode.GlobalCode_VariableLists
{
    /// <summary>
    /// 4 Coordinate Vector (X,Y,Z,W) (C# version of my QuadVector with MediumDec used instead of double)
    /// </summary>
    public class QuadVector
    {
        public MediumDec PositionX = MediumDec.Zero;
        public MediumDec PositionY = MediumDec.Zero;
        public MediumDec PositionZ = MediumDec.Zero;
        public MediumDec PositionW = MediumDec.Zero;
        //Store values in Position in vector
        public void StoreInVectorIndex(int index, MediumDec TempValue)
        {
            if (index == 0) { PositionX = TempValue; }
            else if (index == 1) { PositionY = TempValue; }
            else if (index == 2) { PositionZ = TempValue; }
            else if (index == 3) { PositionW = TempValue; }
        }
        //Get value based on index value
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
        /// <returns></returns>
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
        /// <returns></returns>
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
        /// Construct QuadVector from String
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

        public static explicit operator QuadVector(string LineString)
        {
            return new QuadVector(LineString);
        }

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
        public QuadVector(MediumDec x, MediumDec y, MediumDec z, MediumDec w)
        {
            PositionX = x;
            PositionY = y;
            PositionZ = z;
            PositionW = w;
        }

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
    /// </summary>
    /// <seealso cref="System.Collections.Generic.List{CSharpGlobalCode.GlobalCode_VariableLists.QuadVector}" />
    public class QuadVectorList : List<QuadVector>
    {
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
                    if (VectorIndex == 4)//Code caveat in case of slight format change of having no ) in formating
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

        public QuadVectorList(string Value)
        {
            ConvertStringToList(Value);
        }

        public static explicit operator QuadVectorList(string Value)
        {
            return new QuadVectorList(Value);
        }

        public QuadVectorList() { }
    }
}
