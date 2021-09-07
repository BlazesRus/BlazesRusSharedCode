﻿using System;
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
using System.Windows.Threading;

namespace CSharpSharedCode.ExperimentalCode
{
#pragma warning disable CC0001 // You should use 'var' whenever possible.
#pragma warning disable CC0105 // You should use 'var' whenever possible.
#pragma warning disable CS3001 // Argument type is not CLS-compliant
#pragma warning disable CS3002 // Return type is not CLS-compliant
#pragma warning disable CS3003 // Type is not CLS-compliant
#pragma warning disable CC0003 // Your catch should include an Exception
#pragma warning disable CS3008 // Identifier is not CLS-compliant
#pragma warning disable CC0052 // Make field readonly
#pragma warning disable CS0436 // Type conflicts with imported type
    //<summary>
    // Interaction logic for SmallDecUpdownSlider.xaml (Parts of code based on SmallDecSlider code)/Replacement for metroControls:NumericUpDown
    //Parts of code/UI based on http://www.philosophicalgeek.com/2009/11/16/a-wpf-numeric-entry-control/
    //</summary>
    public partial class SmallDecSlider : UserControl, System.ComponentModel.INotifyPropertyChanged, System.ComponentModel.INotifyPropertyChanging
    {
        /// <summary>
        /// Property Info for DesignWidth
        /// </summary>
        public static readonly DependencyProperty DesignWidthProperty = DependencyProperty.Register("DesignWidth", typeof(double), typeof(SmallDecSlider), new PropertyMetadata((double)100));

        /// <summary>
        /// Used for determining size of the UI element width(separate from maximum size of value)
        /// </summary>
        public double DesignWidth
        {
            get { return (double)GetValue(DesignWidthProperty); }
            set
            {
                SetValue(DesignWidthProperty, value);
                if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs("DesignWidth"));
            }
        }

        /// <summary>
        /// 
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public static readonly DependencyProperty MinimumProperty = DependencyProperty.Register("Minimum", typeof(SmallDec), typeof(SmallDecSlider), new PropertyMetadata(SmallDec.Zero));

        /// <summary>
        /// 
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public static readonly DependencyProperty MaximumProperty = DependencyProperty.Register("Maximum", typeof(SmallDec), typeof(SmallDecSlider), new PropertyMetadata((SmallDec)100));

        /// <summary>
        /// 
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public static readonly DependencyProperty ValueProperty = DependencyProperty.Register("Value", typeof(SmallDec), typeof(SmallDecSlider), new PropertyMetadata(SmallDec.Zero, OnValuePropertyChanged));

        /// <summary>
        /// INotifyPropertyChanged event that is called right before a property is changed.
        /// </summary>
        public event PropertyChangingEventHandler PropertyChanging;

        /// <summary>
        /// INotifyPropertyChanged event that is called right after a property is changed.
        /// </summary>
        public event PropertyChangedEventHandler PropertyChanged;

        /// <summary>
        /// Minimum limit for value
        /// </summary>
        public SmallDec Minimum
        {
            get { return (SmallDec)GetValue(MinimumProperty); }
            set
            {
                SetValue(MinimumProperty, value);
                if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs("Minimum"));
            }
        }

        /// <summary>
        /// Maximum limit for Value
        /// </summary>
        public SmallDec Maximum
        {
            get { return (SmallDec)GetValue(MaximumProperty); }
            set
            {
                SetValue(MaximumProperty, value);
                if (PropertyChanged != null)  PropertyChanged(this, new PropertyChangedEventArgs("Maximum")); 
            }
        }

        /// <summary>
        /// Current Value
        /// </summary>
        public SmallDec Value
        {
            get { return (SmallDec)GetValue(ValueProperty); }
            set
            {
                SetValue(ValueProperty, value);
                if (PropertyChanged != null) { PropertyChanged(this, new PropertyChangedEventArgs("Value")); }
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public SmallDec GetCurrentValue()
        {
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        public SmallDecSlider()
        {
            this.InitializeComponent();
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

        /// <summary>
        /// 
        /// </summary>
        /// <param name="value"></param>
        /// <param name="update"></param>
        public void UpdateThumb(SmallDec value, bool update = false)
        {
            if (ContainerCanvas != null)
            {
                if (update || !Thumb.IsDragging)
                {
                    double relativeLeft = (double)((value - Minimum) / (Maximum - Minimum)) * DesignWidth;

                    Canvas.SetLeft(Thumb, (double)relativeLeft);
                }
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private static void ContainerCanvas_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            //var relativeLeft = (double)((Value - Minimum) / (Maximum - Minimum)) * DesignWidth;
            //if (relativeLeft > DesignWidth)
            //{
            //    relativeLeft = DesignWidth;
            //}
            //Canvas.SetLeft(Thumb, (double)relativeLeft);//Only move the thumb
        }

        private void Thumb_DragDelta(object sender, DragDeltaEventArgs e)
        {
            var min = DragThumb(Thumb, 0.0, DesignWidth, e.HorizontalChange);
            UpdateThumb(min, true);
        }

        private static SmallDec DragThumb(Thumb thumb, double min, double max, double offset)
        {
            var currentPos = Canvas.GetLeft(thumb);
            var nextPos = currentPos + offset;

            nextPos = SmallDec.DynamicMax(max, nextPos);
            return nextPos;
            //return (Minimum + (nextPos / DesignWidth) * (Maximum - Minimum));
        }

        private void Thumb_DragCompleted(object sender, DragCompletedEventArgs e)
        {
            UpdateThumb(Value);
            Canvas.SetZIndex(Thumb, 10);
        }

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
        protected void SetProperty<T>(ref T backingStore, T value, Action onChanged = null, Action<T> onChanging = null,
        [System.Runtime.CompilerServices.CallerMemberName]
        string propertyName = null)
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

        /// <summary>
        /// 
        /// </summary>
        /// <param name="propertyName"></param>
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

        /// <summary>
        /// Convert stored Value to String
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            return Value.ToFullString();
        }
    }
}