﻿using CSharpGlobalCode.GlobalCode_ExperimentalCode;
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
	///	Interaction logic for SmallDecSlider.xaml
	//		Range slider code based mostly on	http://stackoverflow.com/questions/36545896/universal-windows-uwp-range-slider
	/// Follow steps 1a or 1b and then 2 to use this custom control in a XAML file.
	///
	/// Step 1a) Using this custom control in a XAML file that exists in the current project.
	/// Add this XmlNamespace attribute to the root element of the markup file where it is 
	/// to be used:
	///
	///     xmlns:GlobalCode="clr-namespace:CSharpGlobalCode.GlobalCode_ExperimentalCode"
	///or
	///	xmlns:SmallDecSlider="clr-namespace:CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDecSlider"
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
	///     <GlobalCode:SmallDecSlider/>
	/// </summary>
	public partial class SmallDecSlider : UserControl, System.ComponentModel.INotifyPropertyChanged, System.ComponentModel.INotifyPropertyChanging
	{
		public static readonly DependencyProperty MinimumProperty = DependencyProperty.Register("Minimum", typeof(SmallDec), typeof(SmallDecSlider), new PropertyMetadata(0.0));

		public static readonly DependencyProperty MaximumProperty = DependencyProperty.Register("Maximum", typeof(SmallDec), typeof(SmallDecSlider), new PropertyMetadata(1.0));

		public static readonly DependencyProperty ValueProperty = DependencyProperty.Register("Value", typeof(SmallDec), typeof(SmallDecSlider), new PropertyMetadata(0.0, OnValuePropertyChanged));

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

		public SmallDecSlider()
		{
			this.InitializeComponent();
		}
		
		//public static readonly DependencyProperty ExtraFeaturesSettingProp = DependencyProperty.Register("ExtraFeaturesSetting", typeof(byte), typeof(SmallDecSlider), new PropertyMetadata(0, OnValuePropertyChanged));

		//public byte ExtraFeaturesSetting
		//{
		//	get { return (byte)GetValue(ExtraFeaturesSettingProp); }
		//	set
		//	{
		//		SetValue(ExtraFeaturesSettingProp, value);
		//		if (PropertyChanged != null) { PropertyChanged(this, new PropertyChangedEventArgs("ExtraFeaturesSetting")); }
		//	}
		//}
		
		public SmallDecSlider(byte OptionValue)
		{
			this.InitializeComponent();
			//if(OptionValue!=0){	ExtraFeaturesSetting = OptionValue; }
		}

		private static void OnValuePropertyChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
		{
			var slider = (SmallDecSlider)d;
			var newValue = (SmallDec)e.NewValue;

			if (newValue < slider.Minimum)
			{
				slider.Value = slider.Minimum;
			}
			else if (newValue > slider.Maximum)
			{
				slider.Value = slider.Maximum;
			}
			else
			{
				slider.Value = newValue;
			}

			slider.UpdateThumb(slider.Value);
		}

		public void UpdateThumb(SmallDec value, bool update = false)
		{
			if (ContainerCanvas != null)
			{
				if (update || !Thumb.IsDragging)
				{
					var relativeLeft = ((value - Minimum) / (Maximum - Minimum)) * ContainerCanvas.ActualWidth;

					Canvas.SetLeft(Thumb, (double)relativeLeft);
					Canvas.SetLeft(ActiveRectangle, (double)relativeLeft);

					ActiveRectangle.Width = (double)((Maximum - value) / (Maximum - Minimum) * ContainerCanvas.ActualWidth);
				}
			}
		}

		private void ContainerCanvas_SizeChanged(object sender, SizeChangedEventArgs e)
		{
			var relativeLeft = ((Value - Minimum) / (Maximum - Minimum)) * ContainerCanvas.ActualWidth;
			var relativeRight = ContainerCanvas.ActualWidth;

			Canvas.SetLeft(Thumb, (double)relativeLeft);
			Canvas.SetLeft(ActiveRectangle, (double)relativeLeft);

			ActiveRectangle.Width = (double)((Maximum - Value) / (Maximum - Minimum) * ContainerCanvas.ActualWidth);
		}

		private void Thumb_DragDelta(object sender, DragDeltaEventArgs e)
		{
			var min = DragThumb(Thumb, SmallDec.Zero, Maximum, e.HorizontalChange);
			UpdateThumb(min, true);
			Value = min.Round();
		}

		private SmallDec DragThumb(Thumb thumb, SmallDec min, SmallDec max, double offset)
		{
			var currentPos = Canvas.GetLeft(thumb);
			SmallDec nextPos = (SmallDec) currentPos + offset;

			nextPos = SmallDec.Max(min, nextPos);
			nextPos = SmallDec.Min(max, nextPos);

			return (Minimum + (nextPos / ContainerCanvas.ActualWidth) * (Maximum - Minimum));
		}

		private void Thumb_DragCompleted(object sender, DragCompletedEventArgs e)
		{
			UpdateThumb(Value);
			Canvas.SetZIndex(Thumb, 10);
		}

#if (BlazesGlobalCode_SmallDecSliderEnableExtraFeatures)
		//Tick based code parts (for adding in tick features of slider later to control)
		//Will try to program in ticks features later (mainly to reduce errors from missing properties for now)
		public double SmallChange
		{
			get { return (double)GetValue(SmallChangeProperty); }
			set { SetValue(SmallChangeProperty, value); }
		}
		public double LargeChange
		{
			get { return (double)GetValue(LargeChangeProperty); }
			set { SetValue(LargeChangeProperty, value); }
		}
		public double TickFrequency
		{
			get { return (double)GetValue(TickFrequencyProperty); }
			set { SetValue(TickFrequencyProperty, value); }
		}
		public static readonly DependencyProperty SmallChangeProperty = DependencyProperty.Register("SmallChange", typeof(double), typeof(SmallDecSlider), new PropertyMetadata(0.01, OnValuePropertyChanged));
		public static readonly DependencyProperty LargeChangeProperty = DependencyProperty.Register("SmallChange", typeof(double), typeof(SmallDecSlider), new PropertyMetadata(1.0, OnValuePropertyChanged));
		public static readonly DependencyProperty TickFrequencyProperty = DependencyProperty.Register("TickFrequency", typeof(double), typeof(SmallDecSlider), new PropertyMetadata(10.0, OnValuePropertyChanged));
		public DoubleCollection Ticks
		{
			get { return (DoubleCollection)GetValue(TicksProperty); }
			set { SetValue(TicksProperty, value); }
		}
		public static readonly DependencyProperty TicksProperty = DependencyProperty.Register("Ticks", typeof(DoubleCollection), typeof(SmallDecSlider), new PropertyMetadata(new DoubleCollection(), OnValuePropertyChanged));
		public string TickPlacement
		{
			get { return (string)GetValue(TickPlacementProperty); }
			set { SetValue(TickPlacementProperty, value); }
		}
		public static readonly DependencyProperty TickPlacementProperty = DependencyProperty.Register("TickPlacement", typeof(string), typeof(SmallDecSlider), new PropertyMetadata("TopLeft", OnValuePropertyChanged));
		public bool IsSnapToTickEnabled
		{
			get { return (bool)GetValue(IsSnapToTickEnabledProperty); }
			set { SetValue(IsSnapToTickEnabledProperty, value); }
		}
		public static readonly DependencyProperty IsSnapToTickEnabledProperty = DependencyProperty.Register("IsSnapToTickEnabled", typeof(bool), typeof(SmallDecSlider), new PropertyMetadata(false, OnValuePropertyChanged));
#endif
		////Routed Event from http://stackoverflow.com/questions/21033509/routedevent-the-member-is-not-recognized-or-is-not-accessible
		//public static readonly RoutedEvent fooEvent = EventManager.RegisterRoutedEvent("foo", RoutingStrategy.Direct, typeof(RoutedEventHandler), typeof(MainWindow));
		//// Provide CLR accessors for the event 
	   //public event RoutedEventHandler foo
	   //{
		  // add { AddHandler(fooEvent, value); }
		  // remove { RemoveHandler(fooEvent, value); }
	   //}

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
		protected virtual SmallDecSlider SafeMemberwiseClone()
		{
			var t = (SmallDecSlider)MemberwiseClone();
			t.PropertyChanged = null;
			t.PropertyChanging = null;
			return t;
		}
	}
}
//Property change code for the most part from Notifier.cs in PoESkillTree code (required license for related part of code below)
//Copyright © 2012-2016 PoESkillTree Team
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.