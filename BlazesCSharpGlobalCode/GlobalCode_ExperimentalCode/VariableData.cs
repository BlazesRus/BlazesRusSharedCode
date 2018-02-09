    public class VariableData<T> : INotifyPropertyChanged
    {
        /// <summary>
        /// Gets or sets the current value.
        /// </summary>
        /// <value>
        /// The current value selected in the ComboBox
        /// </value>
        public T CurrentValue { get; set; }

        ///// <summary>
        ///// Prevents a default instance of the <see cref="TrackedListBox"/> class from being created.
        ///// </summary>
        //public StringData() { }

        ///// <summary>
        ///// Initializes a new instance of the <see cref="VariableData{T}"/> class.
        ///// </summary>
        ///// <param name="value">The value.</param>
        //public VariableData(string value) { CurrentValue = value; }

        /// <summary>
        /// Initializes a new instance of the <see cref="VariableData{T}"/> class.
        /// </summary>
        /// <param name="value">The value.</param>
        public VariableData(T value) { CurrentValue = value; }

        #region INotifyPropertyChanged Members

        public event PropertyChangedEventHandler PropertyChanged;

        /// Need to implement this interface in order to get data binding
        /// to work properly.
        private void NotifyPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }

        #endregion INotifyPropertyChanged Members

        #region Convert to/from other types


        /// <summary>
        /// Performs an explicit conversion from <see cref="VariableData{T}"/> to <see cref="T"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <returns>
        /// The result of the conversion.
        /// </returns>
        public static explicit operator T(VariableData<T> self)
        {
            return self.CurrentValue;
        }


        ///// <summary>
        ///// Performs an explicit conversion from <see cref="System.String"/> to <see cref="VariableData{T}"/>.
        ///// </summary>
        ///// <param name="self">The self.</param>
        ///// <returns>
        ///// The result of the conversion.
        ///// </returns>
        //public static explicit operator VariableData<T>(string self)
        //{
        //    return new VariableData<T>(self);
        //}

        /// <summary>
        /// Performs an explicit conversion from <see cref="T"/> to <see cref="VariableData{T}"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <returns>
        /// The result of the conversion.
        /// </returns>
        public static explicit operator VariableData<T>(T self)
        {
            return new VariableData<T>(self);
        }

        #endregion Convert to/from other types

        #region Operator Functionality
        //public static bool operator ==(StringData self, string Value)
        //{
        //    return self.CurrentValue == Value;
        //}

        //public static bool operator !=(StringData self, string Value)
        //{
        //    return self.CurrentValue != Value;
        //}

        //public static StringData operator +(StringData self, string Value)
        //{
        //    string Total = self.CurrentValue + Value;
        //    return new StringData(Total);
        //}

        #endregion Operator Functionality
    }
