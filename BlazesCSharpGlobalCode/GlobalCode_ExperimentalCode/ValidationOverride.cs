// ***********************************************************************
// Assembly         : BlazesCSharpGlobalCode
// Author           : BlazesRus
// Created          : 02-09-2018
//
// Last Modified By : BlazesRus
// Last Modified On : 05-21-2018
// ***********************************************************************
// <copyright file="ValidationOverride.cs" company="">
//     Copyright ©  2018
// </copyright>
// <summary></summary>
// ***********************************************************************
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
	/// <summary>
	/// Class ValidationOverride.
	/// Implements the <see cref="System.Windows.Controls.ValidationRule" />
	/// </summary>
	/// <seealso cref="System.Windows.Controls.ValidationRule" />
	class ValidationOverride : ValidationRule
    {
		/// <summary>
		/// When overridden in a derived class, performs validation checks on a value.
		/// </summary>
		/// <param name="value">The value from the binding target to check.</param>
		/// <param name="cultureInfo">The culture to use in this rule.</param>
		/// <returns>A <see cref="T:System.Windows.Controls.ValidationResult" /> object.</returns>
		public override ValidationResult Validate(object value, CultureInfo cultureInfo)
        {
            ValidationResult ValidResult = ValidationResult.ValidResult;
            return value != null ? ValidResult : new ValidationResult(false, "Value required");
		}
		/// <summary>
		/// Initializes the validation.
		/// </summary>
		/// <param name="SelectedObject">The selected object.</param>
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

		/// <summary>
		/// Gets the name of the dependency property by.
		/// </summary>
		/// <param name="dependencyObject">The dependency object.</param>
		/// <param name="dpName">Name of the dp.</param>
		/// <returns>DependencyProperty.</returns>
		public static DependencyProperty GetDependencyPropertyByName(DependencyObject dependencyObject, string dpName)
        {
            return GetDependencyPropertyByName(dependencyObject.GetType(), dpName);
        }

		/// <summary>
		/// Gets the name of the dependency property by.
		/// </summary>
		/// <param name="dependencyObjectType">Type of the dependency object.</param>
		/// <param name="dpName">Name of the dp.</param>
		/// <returns>DependencyProperty.</returns>
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
