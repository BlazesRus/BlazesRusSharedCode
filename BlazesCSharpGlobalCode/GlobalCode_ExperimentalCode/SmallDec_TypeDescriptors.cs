/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Globalization;
    using System.Windows;
    using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

    // Represent +- 65535.999999999(Can only represent +- 65535.9999 if SmallDec_ReducedSize or SmallDec_UseLegacyStorage set) with 100% consistency of accuracy
    //(Aka SuperDec_Int16_9Decimal Or SuperDec_Int16_4Decimal)
    public
#if (!BlazesGlobalCode_SmallDec_AsStruct)
    sealed
#endif
    partial
#if (!BlazesGlobalCode_SmallDec_AsStruct)
    class
#else
    struct
#endif
    SmallDec : IFormattable, INotifyPropertyChanged
    {
//#if (!SmallDec_DisableCustomTypeDescriptor)
//        /// <summary>
//        /// 
//        /// </summary>
//        /// <returns></returns>
//        public AttributeCollection GetAttributes()
//        {
//            return TypeDescriptor.GetAttributes(this, true);
//        }

//        /// <summary>
//        /// 
//        /// </summary>
//        /// <returns></returns>
//        public string GetClassName()
//        {
//            return "SmallDec";
//        }

//        /// <summary>
//        /// 
//        /// </summary>
//        /// <returns></returns>
//        public string GetComponentName()
//        {
//            return TypeDescriptor.GetComponentName(this, true);
//        }

//        /// <summary>
//        /// 
//        /// </summary>
//        /// <returns></returns>
//        public TypeConverter GetConverter()
//        {
//            return TypeDescriptor.GetConverter(this, true);
//        }

//        /// <summary>
//        /// 
//        /// </summary>
//        /// <returns></returns>
//        public EventDescriptor GetDefaultEvent()
//        {
//            return TypeDescriptor.GetDefaultEvent(this, true);
//        }

//        /// <summary>
//        /// 
//        /// </summary>
//        /// <returns></returns>
//        public PropertyDescriptor GetDefaultProperty()
//        {
//            return null;
//        }

//        /// <summary>
//        /// 
//        /// </summary>
//        /// <param name="editorBaseType"></param>
//        /// <returns></returns>
//        public object GetEditor(Type editorBaseType)
//        {
//            return TypeDescriptor.GetEditor(this, editorBaseType, true);
//        }

//        /// <summary>
//        /// 
//        /// </summary>
//        /// <param name="attributes"></param>
//        /// <returns></returns>
//        public EventDescriptorCollection GetEvents(Attribute[] attributes)
//        {
//            return TypeDescriptor.GetEvents(this, attributes, true);
//        }

//        /// <summary>
//        /// 
//        /// </summary>
//        /// <returns></returns>
//        public EventDescriptorCollection GetEvents()
//        {
//            return TypeDescriptor.GetEvents(this, true);
//        }

//        /// <summary>
//        /// 
//        /// </summary>
//        /// <returns></returns>
//        public PropertyDescriptorCollection GetProperties()
//        {
//            //return ((ICustomTypeDescriptor)this).GetProperties();
//            return TypeDescriptor.GetProperties(this, true);
//        }

//        /// <summary>
//        /// 
//        /// </summary>
//        /// <param name="attributes"></param>
//        /// <returns></returns>
//        public PropertyDescriptorCollection GetProperties(Attribute[] attributes)
//        {
//            return ((ICustomTypeDescriptor)this).GetProperties(attributes);
//        }

//        /// <summary>
//        /// 
//        /// </summary>
//        /// <param name="pd"></param>
//        /// <returns></returns>
//        public object GetPropertyOwner(PropertyDescriptor pd)
//        {
//            return ((ICustomTypeDescriptor)this).GetPropertyOwner(pd);
//        }
//#endif
    }
}
