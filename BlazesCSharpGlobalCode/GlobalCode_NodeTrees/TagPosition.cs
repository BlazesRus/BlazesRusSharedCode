using CSharpGlobalCode.GlobalCode_VariableLists;
using CSharpGlobalCode.GlobalCode_VariableConversionFunctions;

namespace CSharpGlobalCode.GlobalCode_NodeTrees
{
    public class TagPosition
    {
        //Example ParentIndexPosition="0_1"
        public XIntegerList ParentIndexPosition;

        //Index in CurrentList
        private long ListPosition = -1;

        private void IncreaseListPos()
        {
            ListPosition += 1;
        }

        private void IncreaseParentIndex()
        {
            ParentIndexPosition.Add(ListPosition);
            ListPosition = -1;
        }

        //************************************
        // Returns String in format ParentIndexPosition(Index:0)_ParentIndexPosition(Index:1)-ListPosition
        // Method:    PositionString
        // FullName:  TagData::TagPosition::PositionString
        // Access:    public
        // Returns:   string
        // Qualifier:
        //************************************
        public string PositionString()
        {
            string PositionString = ParentIndexPosition.GenerateAsString();
            PositionString += "-";
            PositionString += VariableConversionFunctions.LongToStringConversion(ListPosition);
            return PositionString;
        }
    }
}