using System;
using System.Collections.Generic;

namespace CSharpGlobalCode.GlobalCode_VariableConversionFunctions
{
    class TypeDataInfo
    {
        public string ContainerTypeName = "";
        public List<string> ContainerDataTypes = new List<string>();

        /// <summary>
        /// Separate the TypeName of the Container from the Variable types contained
        /// </summary>
        /// <param name="TargetType"></param>
        public TypeDataInfo(Type TargetType)
        {
            byte ExtractionStage = 0;
            string TargetName = TargetType.ToString();
            string TempString;
            var StringBuffer = new System.Text.StringBuilder("");
            foreach (char StringChar in TargetName)
            {
                switch (ExtractionStage)
                {
                    case 0:
                        if (StringChar == '[')
                        {
                            ContainerTypeName = StringBuffer.ToString();
                            ExtractionStage = 1;
                            StringBuffer.Clear();
                        }
                        else
                        {
                            StringBuffer.Append(StringChar);
                        }
                        break;

                    case 1:
                        if (StringChar == ',')
                        {
                            TempString = StringBuffer.ToString();
                            ContainerDataTypes.Add(TempString);
                            StringBuffer.Clear();
                        }
                        else if (StringChar == ']')
                        {
                            TempString = StringBuffer.ToString();
                            ContainerDataTypes.Add(TempString);
                            ExtractionStage = 2;
                        }
                        else
                        {
                            StringBuffer.Append(StringChar);
                        }
                        break;
                }
            }
        }

        /// <summary>
        /// Return of type based on information from string
        /// </summary>
        /// <param name="TypeName"></param>
        /// <returns></returns>
        public static Type ReturnTypeByString(string TypeName)
        {
            switch (TypeName)
            {
                case "System.Int32":
                    return typeof(int);
                case "System.Boolean":
                    return typeof(bool);
                case "System.Double":
                    return typeof(double);
                case "System.Single":
                    return typeof(float);
                default:
                    return Type.GetType(TypeName);
            }
        }

        /// <summary>
        /// Create Type array from List of Strings
        /// </summary>
        /// <param name="DataTypes"></param>
        /// <returns></returns>
        public static Type[] GetTypeListFromStringList(List<string> DataTypes)
        {
            List<Type> TypeList = new List<Type>();
            foreach (var value in DataTypes)
            {
                TypeList.Add(ReturnTypeByString(value));
            }
            Type[] ArrayOfTypes = TypeList.ToArray();
            return ArrayOfTypes;
        }

        /// <summary>
        /// </summary>
        /// <returns></returns>
        public dynamic InitialyzeTypeData()
        {
            //Based on https://docs.microsoft.com/en-us/dotnet/framework/reflection-and-codedom/how-to-examine-and-instantiate-generic-types-with-reflection
            if (ContainerTypeName.Contains("Generic.Dictionary"))//Dictionary detected
            {
                Type KeyType = ReturnTypeByString(ContainerDataTypes[0]);
                Type ValueType = ReturnTypeByString(ContainerDataTypes[1]);
                Type[] typeArgs = { KeyType, ValueType };
                Type GenericDictionary = typeof(Dictionary<,>);
                Type ContainerType = GenericDictionary.MakeGenericType(typeArgs);
                dynamic Container = Activator.CreateInstance(ContainerType);
                return Container;
            }
            else
            {
                if (ContainerDataTypes.Count == 2)//Likely a dictionary like type
                {
                    Type KeyType = ReturnTypeByString(ContainerDataTypes[0]);
                    Type ValueType = ReturnTypeByString(ContainerDataTypes[1]);
                    Type[] typeArgs = { KeyType, ValueType };
                    Type GenericDictionary = ReturnTypeByString(ContainerTypeName);
                    Type ContainerType = GenericDictionary.MakeGenericType(typeArgs);
                    dynamic Container = Activator.CreateInstance(ContainerType);
                    return Container;
                }
                else if (ContainerDataTypes.Count == 1)//Likely an array or list based type
                {
                    Type ValueType = ReturnTypeByString(ContainerDataTypes[0]);
                    Type[] typeArgs = { ValueType };
                    Type GenericList = ReturnTypeByString(ContainerTypeName);
                    Type ContainerType = GenericList.MakeGenericType(typeArgs);
                    dynamic Container = Activator.CreateInstance(ContainerType);
                    return Container;
                }
                else if (ContainerDataTypes.Count > 2)//Likely a Tuple based type
                {
                    //Type ValueType = ReturnTypeByString(ContainerDataTypes[0]);
                    Type[] typeArgs = GetTypeListFromStringList(ContainerDataTypes);
                    Type GenericList = ReturnTypeByString(ContainerTypeName);
                    Type ContainerType = GenericList.MakeGenericType(typeArgs);
                    dynamic Container = Activator.CreateInstance(ContainerType);
                    return Container;
                }
                else//Non-Array based type
                {
                    Type ValueType = ReturnTypeByString(ContainerTypeName);
                    if (ValueType.IsValueType)
                    {
                        dynamic ConvertedValue = Activator.CreateInstance(ValueType);
                        return ConvertedValue;
                    }
                    else
                    {
                        dynamic ConvertedValue = default(ValueType);
                        return ConvertedValue;
                    }
                }
            }
        }
    }
}