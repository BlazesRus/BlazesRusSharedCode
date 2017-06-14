using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpGlobalCode.GlobalCode_VariableConversionFunctions
{
    class TypeDataInfo
    {
        string ContainerTypeName="";
        IList<string> ContainerDataTypes;
        /// <summary>
        /// Separate the TypeName of the Container from the Variable types contained
        /// </summary>
        /// <param name="TargetType"></param>
        public TypeDataInfo(Type TargetType)
        {
            string TargetName = TargetType.ToString();

        }
    }
}
