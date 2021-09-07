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
    // <summary>
    // Interaction logic for SmallDecUpdownSlider.xaml (Parts of code based on SmallDecSlider code)/Replacement for metroControls:NumericUpDown
    //Parts of code/UI based on http://www.philosophicalgeek.com/2009/11/16/a-wpf-numeric-entry-control/
    //</summary>
    public partial class SmallDecUpdownSlider : UserControl, System.ComponentModel.INotifyPropertyChanged, System.ComponentModel.INotifyPropertyChanging
    {
        /// <summary>
        /// 
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public static readonly DependencyProperty IncrementProperty = DependencyProperty.Register("Increment", typeof(SmallDec), typeof(SmallDecUpdownSlider), new PropertyMetadata((SmallDec)1));

        /// <summary>
        /// 
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public static readonly DependencyProperty LargeIncrementProperty = DependencyProperty.Register("LargeIncrement", typeof(SmallDec), typeof(SmallDecUpdownSlider), new PropertyMetadata((SmallDec)10));

        /// <summary>
        /// 
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public SmallDec Increment
        {
            get { return (SmallDec)GetValue(IncrementProperty); }
            [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
            set
            {
                SetValue(IncrementProperty, (SmallDec)value);
                if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs("IncrementProperty"));
            }
        }
        
        /// <summary>
        /// 
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public SmallDec LargeIncrement
        {
            get { return (SmallDec)GetValue(IncrementProperty); }
            [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
            set
            {
                SetValue(LargeIncrementProperty, (SmallDec)value);
                if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs("LargeIncrementProperty"));
            }
        }

        /// <summary>
        /// 
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public static readonly DependencyProperty MinimumProperty = DependencyProperty.Register("Minimum", typeof(SmallDec), typeof(SmallDecUpdownSlider), new PropertyMetadata(SmallDec.Zero));

        /// <summary>
        /// 
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public static readonly DependencyProperty MaximumProperty = DependencyProperty.Register("Maximum", typeof(SmallDec), typeof(SmallDecUpdownSlider), new PropertyMetadata(SmallDec.Maximum));

        /// <summary>
        /// 
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public static readonly DependencyProperty ValueProperty = DependencyProperty.Register("Value", typeof(SmallDec), typeof(SmallDecUpdownSlider), new PropertyMetadata(SmallDec.Zero,OnValuePropertyChanged));
        /// <summary>
        /// INotifyPropertyChanged event that is called right before a property is changed.
        /// </summary>
        public event PropertyChangingEventHandler PropertyChanging;

        /// <summary>
        /// INotifyPropertyChanged event that is called right after a property is changed.
        /// </summary>
        public event PropertyChangedEventHandler PropertyChanged;

        /// <summary>
        /// Minimum Value Limit
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public SmallDec Minimum
        {
            get { return (SmallDec)GetValue(MinimumProperty); }
            [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
            set
            {
                SetValue(MinimumProperty, (SmallDec)value);
                if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs("Minimum"));
            }
        }

        /// <summary>
        /// Maximum Value Limit
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public SmallDec Maximum
        {
            get { return (SmallDec)GetValue(MaximumProperty); }
            [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
            set
            {
                SetValue(MaximumProperty, (SmallDec)value);
                if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs("Maximum"));
            }
        }

        /// <summary>
        /// Current Value
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public SmallDec Value
        {
            get { return (SmallDec)GetValue(ValueProperty); }
            [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
            set
            {
                SetValue(ValueProperty, (SmallDec)value);
                if (PropertyChanged != null) { PropertyChanged(this, new PropertyChangedEventArgs("Value")); }
            }
        }

        /// <summary>
        /// Current Value Method
        /// </summary>
        /// <returns></returns>
        public SmallDec GetCurrentValue()
        {
            return Value;
        }

        private DispatcherTimer _timer =   new DispatcherTimer();
        private static int _delayRate = System.Windows.SystemParameters.KeyboardDelay;
        private static int _repeatSpeed = Math.Max(1, System.Windows.SystemParameters.KeyboardSpeed);
        private bool _isIncrementing = false;
        /// <summary>
        /// Previous stored value
        /// </summary>
        public SmallDec _previousValue;
        
        /// <summary>
        /// 
        /// </summary>
        public SmallDecUpdownSlider()
        {
            InitializeComponent();
            ValueDisplay.PreviewTextInput +=   new TextCompositionEventHandler(ValuePreviewTextInput);
            ValueDisplay.GotFocus +=  new RoutedEventHandler(_textbox_GotFocus);
            ValueDisplay.LostFocus +=   new RoutedEventHandler(_textbox_LostFocus);
            ValueDisplay.PreviewKeyDown +=   new KeyEventHandler(_textbox_PreviewKeyDown);
            //ValueDisplay.PreviewMouseUp += new MouseButtonEventHandler(_textbox_MouseWheelUp);

            IncreaseButton.PreviewMouseLeftButtonDown += new MouseButtonEventHandler(IncreaseButton_PreviewMouseLeftButtonDown);
            IncreaseButton.PreviewMouseLeftButtonUp +=  new MouseButtonEventHandler(IncreaseButton_PreviewMouseLeftButtonUp);
            DecreaseButton.PreviewMouseLeftButtonDown += new MouseButtonEventHandler(DecreaseButton_PreviewMouseLeftButtonDown);
            DecreaseButton.PreviewMouseLeftButtonUp += new MouseButtonEventHandler(DecreaseButton_PreviewMouseLeftButtonUp);
            
            _timer.Tick += new EventHandler(_timer_Tick);
        }

        void IncreaseButton_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            IncreaseButton.CaptureMouse();

            _timer.Interval = TimeSpan.FromMilliseconds(_delayRate * 250);
            _timer.Start();
            _isIncrementing = true;
        }

        void IncreaseButton_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            _timer.Stop();
            IncreaseButton.ReleaseMouseCapture();
            IncrementValue();
        }

        void DecreaseButton_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            DecreaseButton.CaptureMouse();
            _timer.Interval = TimeSpan.FromMilliseconds(_delayRate * 250);
            _timer.Start();
            _isIncrementing = false;
        }

        void DecreaseButton_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            _timer.Stop();
            DecreaseButton.ReleaseMouseCapture();
            DecrementValue();
        }

        void _timer_Tick(object sender, EventArgs e)
        {
            if (_isIncrementing)
            {
                IncrementValue();
            }
            else
            {
                DecrementValue();
            }

            _timer.Interval = TimeSpan.FromMilliseconds(1000.0 / _repeatSpeed);
        }

        void ConvertTextFocusEvent(object sender, RoutedEventArgs e)
        {
            SmallDec newValue = ValueDisplay.Text;
            if (newValue > Maximum)
            {
                Value = Maximum;
            }
            else if (newValue < Minimum)
            {
                Value = Minimum;
            }
            else
            {
                //Value = _previousValue;
            }
            ValueDisplay.Text = Value.ToOptimalString();
        }

        //void _textbox_MouseWheelUp(object sender, MouseButtonEventArgs e)
        //{
        //    IncrementValue();
        //}

        void _textbox_GotFocus(object sender, RoutedEventArgs e)
        {
            //_previousValue = Value;//Causes it to lose info
            ConvertTextFocusEvent(sender, e);
        }

        void _textbox_LostFocus(object sender, RoutedEventArgs e)
        {
            ConvertTextFocusEvent(sender, e);
        }

        void _textbox_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            switch (e.Key)
            {
                case Key.Up:
                    IncrementValue();
                    break;
                case Key.Down:
                    DecrementValue();
                    break;
                case Key.PageUp:
                    Value = SmallDec.Min(Value + LargeIncrement, Maximum);
                    break;
                case Key.PageDown:
                    Value = SmallDec.Max(Value - LargeIncrement, Minimum);
                    break;
                case Key.Enter:
                    Value = ValueDisplay.Text;
                    break;
                case Key.Escape:
                    _previousValue = Value;
                    break;
                default:
                    //do nothing
                    break;
            }
        }

        private void IncrementValue()
        {
            Value = SmallDec.Min(Value + Increment, Maximum);
        }
         
        private void DecrementValue()
        {
            Value = SmallDec.Max(Value - Increment, Minimum);
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
        protected virtual SmallDecUpdownSlider SafeMemberwiseClone()
        {
            var t = (SmallDecUpdownSlider)MemberwiseClone();
            t.PropertyChanged = null;
            t.PropertyChanging = null;
            return t;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            return Value.ToFullString();
        }

        //Added mostly for support of StringFormat parameter of UpDown 
        /// <summary>
        /// 
        /// </summary>
        public static readonly DependencyProperty StringFormatProperty = DependencyProperty.Register("StringFormat", typeof(string), typeof(SmallDecUpdownSlider), new PropertyMetadata(""));
        /// <summary>
        /// 
        /// </summary>
        public string StringFormat
        {
            get { return (string)GetValue(StringFormatProperty); }
            set
            {
                SetValue(StringFormatProperty, value);
                if (PropertyChanged != null) { PropertyChanged(this, new PropertyChangedEventArgs("StringFormat")); }
            }
        }

#pragma warning disable CC0091 // Use static method
        void ValuePreviewTextInput(object self, TextCompositionEventArgs e)//Used in handler
#pragma warning restore CC0091 // Use static method
        {
            if (!IsNumericInput(e.Text))
            {
                e.Handled = true;
                return;
            }
        }

        private static bool IsNumericInput(string text)
        {
            foreach (char c in text)
            {
                if (!char.IsDigit(c))
                {
                    return false;
                }
            }
            return true;
        }

        ////Used for determining size of the UI element width(separate from maximum size of value)
        //public static readonly DependencyProperty DesignWidthProperty = DependencyProperty.Register("DesignWidth", typeof(double), typeof(SmallDecSlider), new PropertyMetadata((double)100.0));
        //public double DesignWidth
        //{
        //    get { return (double)GetValue(DesignWidthProperty); }
        //    set
        //    {
        //        SetValue(DesignWidthProperty, value);
        //        if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs("DesignWidth"));
        //    }
        //}

        /// <summary>
        /// 
        /// </summary>
        public static readonly DependencyProperty RelativeSliderWidthProperty = DependencyProperty.Register("RelativeSliderWidth", typeof(double), typeof(SmallDecSlider), new PropertyMetadata((double)0.01));

        //Used for determining size of the UI width of slider rectangle
        /// <summary>
        /// 
        /// </summary>
        public double RelativeSliderWidth
        {
            get { return (double)GetValue(RelativeSliderWidthProperty); }
            set
            {
                SetValue(RelativeSliderWidthProperty, value);
                if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs("RelativeSliderWidth"));
            }
        }
        
        private static void OnValuePropertyChanged(DependencyObject self, DependencyPropertyChangedEventArgs e)
        {
            var Self = (SmallDecUpdownSlider)self;
            
            //var newValue = (SmallDec)e.NewValue;
   //         if (newValue < Self.Minimum)
   //         {
   //             Self.Value = Self.Minimum;
   //         }
   //         else if (newValue > Self.Maximum)
   //         {
   //             Self.Value = Self.Maximum;
   //         }
   //         else
   //         {
   //             Self.Value = newValue;
   //         }
//Update Slider position
            //Only need accuracy of relative position to XX.XX% 
            SmallDec PercentPosition = ((Self.Value - Self.Minimum) / (Self.Maximum - Self.Minimum));
            double RelativePosition = (double)(PercentPosition*Self.ValueDisplay.ActualWidth);
            Self.RelativeSliderWidth = RelativePosition;
            Self.ValueDisplay.Text = (string)Self.Value;
        }
        private void ContainerCanvas_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            var relativeLeft = ((Value - Minimum) / (Maximum - Minimum)) * ContainerCanvas.ActualWidth;
            //var relativeRight = ContainerCanvas.ActualWidth;

            Canvas.SetLeft(Thumb, (double)relativeLeft);
            Canvas.SetLeft(ActiveRectangle, (double)relativeLeft);

            ActiveRectangle.Width = (double)((Maximum - Value) / (Maximum - Minimum) * ContainerCanvas.ActualWidth);
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
                    var relativeLeft = ((value - Minimum) / (Maximum - Minimum)) * ContainerCanvas.ActualWidth;

                    Canvas.SetLeft(Thumb, (double)relativeLeft);
                    Canvas.SetLeft(ActiveRectangle, (double)relativeLeft);

                    ActiveRectangle.Width = (double)((Maximum - value) / (Maximum - Minimum) * ContainerCanvas.ActualWidth);
                }
            }
        }

        private void Thumb_DragDelta(object sender, DragDeltaEventArgs e)
        {
            var min = DragThumb(Thumb, 0.0, (double)Maximum, e.HorizontalChange);
            UpdateThumb(min, true);
        }

        private double DragThumb(Thumb thumb, double min, double max, double offset)
        {
            var currentPos = Canvas.GetLeft(thumb);
            double nextPos = currentPos + offset;

            nextPos = Math.Max(RelativeSliderWidth, nextPos);

            return nextPos;
        }
        //
        private void Thumb_DragCompleted(object sender, DragCompletedEventArgs e)
        {
            UpdateThumb(Value);
            Canvas.SetZIndex(Thumb, 10);
        }
    }
}
