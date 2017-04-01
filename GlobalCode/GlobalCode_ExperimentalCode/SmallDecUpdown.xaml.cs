using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.ComponentModel;

namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    /// <summary>
    ///	Interaction logic for SmallDecUpDown.xaml
    //		Parts of code based on SmallDecSlider code
    /// Follow steps 1a or 1b and then 2 to use this custom control in a XAML file.
    ///
    /// Step 1a) Using this custom control in a XAML file that exists in the current project.
    /// Add this XmlNamespace attribute to the root element of the markup file where it is 
    /// to be used:
    ///
    ///     xmlns:GlobalCode="clr-namespace:CSharpGlobalCode.GlobalCode_ExperimentalCode"
    ///or
    ///	xmlns:SmallDecUpDown="clr-namespace:CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDecUpDown"
    /// Step 1b) Using this custom control in a XAML file that exists in a different project.
    /// Add this XmlNamespace attribute to the root element of the markup file where it is 
    /// to be used:
    ///
    ///     xmlns:GlobalCode="clr-namespace:CSharpGlobalCode.GlobalCode_ExperimentalCode;assembly=CSharpGlobalCode.GlobalCode_ExperimentalCode"
    ///
    /// You will also need to add a project reference from the project where the XAML file lives
    /// to this project and Rebuild to avoid compilation errors:
    ///
    ///     Right click on the target project in the Solution Explorer and
    ///     "Add Reference"->"Projects"->[Browse to and select this project]
    ///
    ///
    /// Step 2)
    /// Go ahead and use your control in the XAML file.
    ///
    ///     <GlobalCode:SmallDecUpDown/>
    /// </summary>
    [Newtonsoft.Json.JsonConverter(typeof(CustomJSONConverter))]
    public partial class SmallDecUpDown : UserControl, System.ComponentModel.INotifyPropertyChanged, System.ComponentModel.INotifyPropertyChanging
	{
		public static readonly DependencyProperty MinimumProperty = DependencyProperty.Register("Minimum", typeof(SmallDec), typeof(SmallDecUpDown), new PropertyMetadata(SmallDec.Zero));

		public static readonly DependencyProperty MaximumProperty = DependencyProperty.Register("Maximum", typeof(SmallDec), typeof(SmallDecUpDown), new PropertyMetadata(SmallDec.Maximum));

		public static readonly DependencyProperty ValueProperty = DependencyProperty.Register("Value", typeof(SmallDec), typeof(SmallDecUpDown), new PropertyMetadata(SmallDec.Zero, OnValuePropertyChanged));
        /// <summary>
        /// INotifyPropertyChanged event that is called right before a property is changed.
        /// </summary>
        public event PropertyChangingEventHandler PropertyChanging;

		/// <summary>
		/// INotifyPropertyChanged event that is called right after a property is changed.
		/// </summary>
		public event PropertyChangedEventHandler PropertyChanged;

		public SmallDec Minimum
		{
			get { return (SmallDec)GetValue(MinimumProperty); }
			set
			{
				SetValue(MinimumProperty, value);
				if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs("Minimum"));
			}
		}

		public SmallDec Maximum
		{
			get { return (SmallDec)GetValue(MaximumProperty); }
			set
			{
				SetValue(MaximumProperty, value);
				if (PropertyChanged != null)  PropertyChanged(this, new PropertyChangedEventArgs("Maximum")); 
			}
		}

		public SmallDec Value
		{
			get { return (SmallDec)GetValue(ValueProperty); }
			set
			{
				SetValue(ValueProperty, value);
				if (PropertyChanged != null) { PropertyChanged(this, new PropertyChangedEventArgs("Value")); }
			}
		}

		public SmallDec GetCurrentValue()
		{
			return Value;
		}

		public SmallDecUpDown()
		{
            this.InitializeComponent();
		}

        //private void InitializeComponent()
        //{
        //    throw new NotImplementedException();
        //}

        private static void OnValuePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			var Self = (SmallDecUpDown)d;
			var newValue = (SmallDec)e.NewValue;

			if (newValue < Self.Minimum)
			{
				Self.Value = Self.Minimum;
			}
			else if (newValue > Self.Maximum)
			{
				Self.Value = Self.Maximum;
			}
			else
			{
				Self.Value = newValue;
			}

		}

		private static void OnLabelStringChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			var Self = (SmallDecUpDown)d;
			var newValueAsString = (SmallDec)e.NewValue;
			SmallDec newValue = (SmallDec)newValueAsString;

			if (newValue < Self.Minimum)
			{
				Self.Value = Self.Minimum;
				//Set label to minimum value as String
			}
			else if (newValue > Self.Maximum)
			{
				Self.Value = Self.Maximum;
				//Set label to maximum value as String
			}
			else
			{
				Self.Value = newValue;
			}
            //Self.ValueDisplay.Text = Value.ToFullString();
        }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		/// <summary>
		/// Sets <paramref name="backingStore"/> to <paramref name="value"/> and
		/// raises <see cref="PropertyChanging"/> before and <see cref="PropertyChanged"/>
		/// after setting the value.
		/// </summary>
		/// <param name="backingStore">Target variable</param>
		/// <param name="value">Source variable</param>
		/// <param name="onChanged">Called after changing the value but before raising <see cref="PropertyChanged"/>.</param>
		/// <param name="onChanging">Called before changing the value and before raising <see cref="PropertyChanging"/> with <paramref name="value"/> as parameter.</param>
		/// <param name="propertyName">Name of the changed property</param>
		protected void SetProperty<T>(ref T backingStore, T value, Action onChanged = null, Action<T> onChanging = null, [System.Runtime.CompilerServices.CallerMemberName] string propertyName = null)
		{
			if (EqualityComparer<T>.Default.Equals(backingStore, value)) return;

			onChanging?.Invoke(value);
			OnPropertyChanging(propertyName);

			backingStore = value;

			onChanged?.Invoke();
			OnPropertyChanged(propertyName);
		}

		private void OnPropertyChanging(string propertyName)
		{
			PropertyChanging?.Invoke(this, new PropertyChangingEventArgs(propertyName));
		}

		protected virtual void OnPropertyChanged(string propertyName)
		{
			PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
		}

		/// <summary>
		/// Equivalent to <c>o.MemberwiseClone()</c> except that events are set to null.
		/// Override if your subclass has events or if you need to re-register handlers.
		/// </summary>
		protected virtual SmallDecUpDown SafeMemberwiseClone()
		{
			var t = (SmallDecUpDown)MemberwiseClone();
			t.PropertyChanged = null;
			t.PropertyChanging = null;
			return t;
		}

        public override string ToString()
        {
            return Value.ToFullString();
        }

        public bool IsAmbientPropertyAvailable(string propertyName)
        {
            throw new NotImplementedException();
        }
        private void HandleScroll(Object sender, ScrollEventArgs e)
        {
            var Self = (SmallDecUpDown)sender;
            var newValue = (SmallDec)e.NewValue;

            if (newValue < Self.Minimum)
            {
                Self.Value = Self.Minimum;
            }
            else if (newValue > Self.Maximum)
            {
                Self.Value = Self.Maximum;
            }
            else
            {
                Self.Value = newValue;
            }
        }
            //private void UpdateTextBasedonValue(DependencyObject ControlObject)
            //{
            //    if(ControlObject.ValueDisplay!=null)
            //    {
            //        ControlObject.Text = Value.ToFullString();
            //    }
            //}
            //private void OnLoaded(ref SmallDecUpDown ControlObject, RoutedEventArgs routedEventArgs)
            //{
            //    //UpdateTextBasedonValue(ref ControlObject);
            //}
    }
}