/*	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;
using System.Collections.Generic;
using System.Globalization;
using System.Reflection;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;

namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    //Based mostly(if not all) on http://stackoverflow.com/questions/30936861/add-validationrule-in-xaml-from-code-behind
    class ValidationOverride : ValidationRule
    {
        public override ValidationResult Validate(object value, CultureInfo cultureInfo)
        {
            ValidationResult ValidResult = ValidationResult.ValidResult;
            return value != null ? ValidResult : new ValidationResult(false, "Value required");
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="SelectedObject"></param>
        public static void InitializeValidation(FrameworkElement SelectedObject)
        {

            //    //FrameworkElement SelectedObject = Txt0;
            //DependencyProperty property = GetDependencyPropertyByName(SelectedObject, "Value");
            BindingGroup CurrentBindingGroup = SelectedObject.BindingGroup;
            CurrentBindingGroup.ValidationRules.Add(new ValidationOverride());
            //Binding binding = SelectedObject.
            //    //Binding binding = new Binding("Model.Txt0");
            //    //binding.UpdateSourceTrigger = UpdateSourceTrigger.PropertyChanged;
            //    //binding.ValidatesOnDataErrors = true;
            //    //RequiredValidate role = new RequiredValidate();
            //    //binding.ValidationRules.Add(role);
            //SelectedObject.SetBinding(property, binding);
        }

        public static DependencyProperty GetDependencyPropertyByName(DependencyObject dependencyObject, string dpName)
        {
            return GetDependencyPropertyByName(dependencyObject.GetType(), dpName);
        }

        public static DependencyProperty GetDependencyPropertyByName(Type dependencyObjectType, string dpName)
        {
            DependencyProperty dp = null;

            var fieldInfo = dependencyObjectType.GetField(dpName, BindingFlags.Public | BindingFlags.Static | BindingFlags.FlattenHierarchy);
            if (fieldInfo != null)
            {
                dp = fieldInfo.GetValue(null) as DependencyProperty;
            }

            return dp;
        }
    }
}
