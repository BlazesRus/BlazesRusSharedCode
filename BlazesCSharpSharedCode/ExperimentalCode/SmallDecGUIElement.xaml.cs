using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
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
    // Base Interaction Logic for GUI Elements
    // Parts of code on http://www.philosophicalgeek.com/2009/11/16/a-wpf-numeric-entry-control/
    //</summary>
    /// <summary>
    /// 
    /// </summary>
    public partial class SmallDecGUIElement : UserControl, System.ComponentModel.INotifyPropertyChanged, System.ComponentModel.INotifyPropertyChanging, IDataErrorInfo, IInputElement
#if (SharedCode_UseIConvertibleForGUIElement)
    , IConvertible
#endif
#if (SharedCode_UseIEquatableForGUIElement)
    , IEquatable<SmallDec>
#endif
    {
        ///// <summary>
        ///// Dependency Property for Increment
        ///// </summary>
        //[System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        //public static readonly DependencyProperty IncrementProperty = DependencyProperty.Register("Increment", typeof(SmallDec), typeof(SmallDecUpdown), new PropertyMetadata((SmallDec)1));

        ///// <summary>
        ///// Dependency Property for Large Increment
        ///// </summary>
        //[System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        //public static readonly DependencyProperty LargeIncrementProperty = DependencyProperty.Register("LargeIncrement", typeof(SmallDec), typeof(SmallDecUpdown), new PropertyMetadata((SmallDec)5));

        ///// <summary>
        ///// Amount to Increase/decrease by when pressing up/down
        ///// </summary>
        //[System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        //public SmallDec Increment
        //{
        //    get { return (SmallDec)GetValue(IncrementProperty); }
        //    set
        //    {
        //        SetValue(IncrementProperty, SmallDec.Initialize(value));
        //        if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs("IncrementProperty"));
        //    }
        //}

        ///// <summary>
        ///// Amount to Increase/decrease by when pressing page up/down
        ///// </summary>
        //[System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        //public SmallDec LargeIncrement
        //{
        //    get { return (SmallDec)GetValue(IncrementProperty); }
        //    set
        //    {
        //        SetValue(LargeIncrementProperty, SmallDec.Initialize(value));
        //        if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs("LargeIncrementProperty"));
        //    }
        //}

        /// <summary>
        /// Minimum Value Limit
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public static readonly DependencyProperty MinimumProperty = DependencyProperty.Register("Minimum", typeof(SmallDec), typeof(SmallDecUpdown), new PropertyMetadata(SmallDec.Zero));

        /// <summary>
        /// Maximum Value Limit
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public static readonly DependencyProperty MaximumProperty = DependencyProperty.Register("Maximum", typeof(SmallDec), typeof(SmallDecUpdown), new PropertyMetadata(SmallDec.Maximum));

        /// <summary>
        /// Current Value
        /// </summary>
        [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
        public static readonly DependencyProperty ValueProperty = DependencyProperty.Register("Value", typeof(SmallDec), typeof(SmallDecUpdown),
        new FrameworkPropertyMetadata(SmallDec.Zero, FrameworkPropertyMetadataOptions.BindsTwoWayByDefault, OnValuePropertyChanged));

        private static void OnValuePropertyChanged(DependencyObject self, DependencyPropertyChangedEventArgs e)
        {
            var Self = (SmallDecUpdown)self;
            Self.ValueDisplay.Text = (string)Self.Value;
        }

        /// <summary>
        /// INotifyPropertyChanged event that is called right before a property is changed.
        /// </summary>
        public event PropertyChangingEventHandler PropertyChanging;

        /// <summary>
        /// INotifyPropertyChanged event that is called right after a property is changed.
        /// </summary>
        public event PropertyChangedEventHandler PropertyChanged;

        /// <summary>
        /// SetPropertyEventsToNull
        /// </summary>
        public void SetPropertyEventsToNull()
        {
            this.PropertyChanged = null;
            this.PropertyChanging = null;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="PropertyName"></param>
        public void ApplyPropertyChange(string PropertyName)
        {
            if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs(PropertyName));
        }

        /// <summary>
        /// Sets <paramref name="backingStore"/> to <paramref name="value"/> and raises 
        /// <see cref="PropertyChanging"/> before and <see cref="PropertyChanged"/> after setting the value.
        /// </summary>
        /// <param name="backingStore">Target variable</param>
        /// <param name="value">Source variable</param>
        /// <param name="onChanged">Called after changing the value but before raising <see cref="PropertyChanged"/>.</param>
        /// <param name="onChanging">
        /// Called before changing the value and before raising <see cref="PropertyChanging"/> with
        /// <paramref name="value"/> as parameter.
        /// </param>
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

        /// <summary>
        /// Method Invoked on changing property
        /// </summary>
        /// <param name="propertyName"></param>
        public void OnPropertyChanging(string propertyName)
        {
            PropertyChanging?.Invoke(this, new PropertyChangingEventArgs(propertyName));
        }

        /// <summary>
        /// Method Invoked when property changed
        /// </summary>
        /// <param name="propertyName"></param>
        protected virtual void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        /// <summary>
        /// Equivalent to <c>o.MemberwiseClone()</c> except that events are set to null. Override if
        /// your subclass has events or if you need to re-register handlers.
        /// </summary>
        protected virtual SmallDecGUIElement SafeMemberwiseClone()
        {
            var t = (SmallDecGUIElement)MemberwiseClone();
            t.PropertyChanged = null;
            t.PropertyChanging = null;
            return t;
        }

        /// <summary>
        /// Minimum Value Limit
        /// </summary>
        public SmallDec Minimum
        {
            get { return (SmallDec)GetValue(MinimumProperty); }
            set
            {
                SetValue(MinimumProperty, value);
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Minimum"));
            }
        }

        /// <summary>
        /// Maximum Value Limit
        /// </summary>
        public SmallDec Maximum
        {
            get { return (SmallDec)GetValue(MaximumProperty); }
            set
            {
                SetValue(MaximumProperty, value);
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Maximum"));
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
                //object LocalValue = ReadLocalValue(ValueProperty);
                //if (LocalValue == DependencyProperty.UnsetValue)
                //{
                //    Console.WriteLine("Local Value is set as " + LocalValue.ToString());
                //    SetValue(ValueProperty, value);
                //    //if (value == SmallDec.Zero)
                //    //{
                //    //    SetCurrentValue(ValueProperty, SmallDec.Zero);
                //    //}
                //}
                //else
                //{
                //    SetCurrentValue(ValueProperty, value);
                //}
                SetValue(ValueProperty, value);
#if (!SmallDecUpDown_DontPreviousValues)
                _previousValue = Value;
#endif
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Value"));
            }
        }

#if (!SmallDecUpDown_DontPreviousValues)

        /// <summary>
        /// Previous value saved
        /// </summary>
        public SmallDec _previousValue;

#endif

        /// <summary>
        /// Component Initializer
        /// </summary>
        public SmallDecGUIElement()
        {
            //InitializeComponent();

            //ValueDisplay.PreviewTextInput += new TextCompositionEventHandler(ValuePreviewTextInput);
            //ValueDisplay.GotFocus += new RoutedEventHandler(_textbox_GotFocus);
            //ValueDisplay.LostFocus += new RoutedEventHandler(_textbox_LostFocus);
            //ValueDisplay.PreviewKeyDown += new KeyEventHandler(_textbox_PreviewKeyDown);
            ////ValueDisplay.PreviewMouseUp += new MouseButtonEventHandler(_textbox_MouseWheelUp);

            //IncreaseButton.PreviewMouseLeftButtonDown += new MouseButtonEventHandler(IncreaseButton_PreviewMouseLeftButtonDown);
            //IncreaseButton.PreviewMouseLeftButtonUp += new MouseButtonEventHandler(IncreaseButton_PreviewMouseLeftButtonUp);
            //DecreaseButton.PreviewMouseLeftButtonDown += new MouseButtonEventHandler(DecreaseButton_PreviewMouseLeftButtonDown);
            //DecreaseButton.PreviewMouseLeftButtonUp += new MouseButtonEventHandler(DecreaseButton_PreviewMouseLeftButtonUp);

            //_timer.Tick += new EventHandler(_timer_Tick);

            ////Binding workaround based on http://blog.jerrynixon.com/2013/07/solved-two-way-binding-inside-user.html
            //(this.Content as FrameworkElement).DataContext = this;
        }

//        void IncreaseButton_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
//        {
//            IncreaseButton.CaptureMouse();

//            _timer.Interval = TimeSpan.FromMilliseconds(_delayRate * 250);
//            _timer.Start();
//            _isIncrementing = true;
//        }

//        void IncreaseButton_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
//        {
//            _timer.Stop();
//            IncreaseButton.ReleaseMouseCapture();
//            IncrementValue();
//        }

//        void DecreaseButton_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
//        {
//            DecreaseButton.CaptureMouse();
//            _timer.Interval = TimeSpan.FromMilliseconds(_delayRate * 250);
//            _timer.Start();
//            _isIncrementing = false;
//        }

//        void DecreaseButton_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
//        {
//            _timer.Stop();
//            DecreaseButton.ReleaseMouseCapture();
//            DecrementValue();
//        }

//        void _timer_Tick(object sender, EventArgs e)
//        {
//            if (_isIncrementing)
//            {
//                IncrementValue();
//            }
//            else
//            {
//                DecrementValue();
//            }

//            _timer.Interval = TimeSpan.FromMilliseconds(1000.0 / _repeatSpeed);
//        }

//        void ConvertTextFocusEvent(object sender, RoutedEventArgs e)
//        {
//            SmallDec newValue = (SmallDec)ValueDisplay.Text;
//            if (newValue > Maximum)
//            {
//                Value = Maximum;
//            }
//            else if (newValue < Minimum)
//            {
//                Value = Minimum;
//            }
//            ValueDisplay.Text = Value.ToString();
//        }

//        //void _textbox_MouseWheelUp(object sender, MouseButtonEventArgs e)
//        //{
//        //    IncrementValue();
//        //}

//        void _textbox_GotFocus(object sender, RoutedEventArgs e)
//        {
//            //_previousValue = Value;//Causes it to lose info
//            ConvertTextFocusEvent(sender, e);
//        }

//        void _textbox_LostFocus(object sender, RoutedEventArgs e)
//        {
//            ConvertTextFocusEvent(sender, e);
//        }

//        void _textbox_PreviewKeyDown(object sender, KeyEventArgs e)
//        {
//            switch (e.Key)
//            {
//                case Key.Up:
//                    IncrementValue();
//                    break;

//                case Key.Down:
//                    DecrementValue();
//                    break;

//                case Key.PageUp:
//                    Value = SmallDec.Min(Value + LargeIncrement, Maximum);
//                    break;

//                case Key.PageDown:
//                    Value = SmallDec.Max(Value - LargeIncrement, Minimum);
//                    break;

//                case Key.Enter:
//                    Value = ValueDisplay.Text;
//                    break;

//                case Key.Escape:
//#if (!SmallDecUpDown_DontPreviousValues)
//                    Value = _previousValue;
//#endif
//                    break;

//                default:
//                    //do nothing
//                    break;
//            }
//        }

//        private void IncrementValue()
//        {
//            Value = SmallDec.Min(Value + Increment, Maximum);
//        }

//        private void DecrementValue()
//        {
//            Value = SmallDec.Max(Value - Increment, Minimum);
//        }

        //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        /// <summary>
        /// Get Value as String
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            return Value.ToOptimalString();
        }

        ///// <summary>
        ///// Added mostly for support of StringFormat parameter of UpDown
        ///// </summary>
        //public static readonly DependencyProperty StringFormatProperty = DependencyProperty.Register("StringFormat", typeof(string), typeof(SmallDecUpdown), new PropertyMetadata(""));

        ///// <summary>
        ///// Added mostly for support of StringFormat parameter of UpDown
        ///// </summary>
        //public string StringFormat
        //{
        //    get { return (string)GetValue(StringFormatProperty); }
        //    set
        //    {
        //        SetValue(StringFormatProperty, value);
        //        if (PropertyChanged != null) { PropertyChanged(this, new PropertyChangedEventArgs("StringFormat")); }
        //    }
        //}

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <param name="e"></param>
        public static void ValuePreviewTextInput(object self, TextCompositionEventArgs e)
        {
            if (!IsNumericInput(e.Text))
            {
                e.Handled = true;
                return;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="text"></param>
        /// <returns></returns>
        public static bool IsNumericInput(string text)
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

        //private static void OnValuePropertyChanged(DependencyObject self, DependencyPropertyChangedEventArgs e)
        //{
        //    var Self = (SmallDecUpdown)self;
        //    Self.ValueDisplay.Text = (string)Self.Value;
        //}

#if (SharedCode_UseIConvertibleForGUIElement)

        /// <summary>
        /// Returns the TypeCode for Value instance.
        /// </summary>
        /// <returns></returns>
        public TypeCode GetTypeCode()
        {
            return TypeCode.Object;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public bool ToBoolean(IFormatProvider provider)
        {
            return (bool)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public char ToChar(IFormatProvider provider)
        {
            return (char)(short)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public sbyte ToSByte(IFormatProvider provider)
        {
            return (sbyte)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public byte ToByte(IFormatProvider provider)
        {
            return (byte)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public short ToInt16(IFormatProvider provider)
        {
            return (short)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public ushort ToUInt16(IFormatProvider provider)
        {
            return (ushort)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public int ToInt32(IFormatProvider provider)
        {
            return (int)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public uint ToUInt32(IFormatProvider provider)
        {
            return (uint)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public long ToInt64(IFormatProvider provider)
        {
            return (long)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public ulong ToUInt64(IFormatProvider provider)
        {
            return (ulong)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public float ToSingle(IFormatProvider provider)
        {
            return (float)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public double ToDouble(IFormatProvider provider)
        {
            return (double)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public decimal ToDecimal(IFormatProvider provider)
        {
            return (decimal)Value;
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public DateTime ToDateTime(IFormatProvider provider)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// </summary>
        /// <param name="conversionType"></param>
        /// <param name="provider"></param>
        /// <returns></returns>
        public object ToType(Type conversionType, IFormatProvider provider)
        {
            dynamic changedObj = System.Convert.ChangeType(Value, conversionType, provider);
            return changedObj;
        }

        /// <summary>
        /// </summary>
        /// <param name="culture"></param>
        /// <returns></returns>
        public string ToString(CultureInfo culture)
        {
            return String.Format(culture, Value.ToOptimalString());//Ensure to reformat string based on culture
        }

        /// <summary>
        /// </summary>
        /// <param name="numberFormat"></param>
        /// <returns></returns>
        public string ToString(NumberFormatInfo numberFormat)
        {
            return String.Format(numberFormat, Value.ToOptimalString());//Ensure to reformat string based on format type
        }

        /// <summary>
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public string ToString(IFormatProvider provider)
        {
            return String.Format(provider, Value.ToOptimalString());
        }

        /// <summary>
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        public bool Equals(SmallDec other)
        {
            return Value == other;
        }
#endif
        /// <summary>
        /// </summary>
        public string Error
        {
            get
            {
                return (this as IDataErrorInfo).Error;
            }
        }

        /// <summary>
        /// </summary>
        /// <param name="columnName"></param>
        /// <returns></returns>
        public string this[string columnName]
        {
            get
            {
                string ErrorType = (this as IDataErrorInfo)[columnName];
                return ErrorType;
            }
        }

        /// <summary>
        /// </summary>
        /// <param name="e"></param>
        /// <returns></returns>
        protected override void OnInitialized(System.EventArgs e)
        {
            //    //            //ValidationOverride.InitializeValidation(sender);
            //    //            //DependencyProperty property = GetDependencyPropertyByName(SelectedObject, "Value");
            //    //            BindingGroup CurrentBindingGroup = ValueDisplay.BindingGroup;
            //    //            if (CurrentBindingGroup.ValidationRules.Count >= 1)//Check if already have validation rules
            //    //            {
            //    //#if (DEBUG)
            //    //                string RuleName;
            //    //                foreach (ValidationRule rule in CurrentBindingGroup.ValidationRules)
            //    //                {
            //    //                    RuleName = rule.ToString();
            //    //                    Console.WriteLine("Found validation rule named "+RuleName);
            //    //                }
            //    //#endif
            //    //            }
            //    //            CurrentBindingGroup.NotifyOnValidationError = true;
            //    //            CurrentBindingGroup.ValidatesOnNotifyDataError = true;
            //    //            CurrentBindingGroup.ValidationRules.Add(new ValidationOverride());
            //    //            ValueDisplay.BindingGroup = CurrentBindingGroup;
            base.OnInitialized(e);
        }
    }

#pragma warning restore CS3008 // Identifier is not CLS-compliant
}
