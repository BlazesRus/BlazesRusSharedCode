using System;
using System.Collections;
using System.Collections.Generic;
using System.Windows.Media;

namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
#pragma warning disable CS3021 // Type or member does not need a CLSCompliant attribute because the assembly does not have a CLSCompliant attribute
#pragma warning disable CS0436 // Type conflicts with imported type
    //[Serializable]
    /// <summary>
    /// Collection of SmallDec's
    /// </summary>
    public class SmallDecCollection : CollectionBase, IFormattable, IList, ICollection, IList<SmallDec>, ICollection<SmallDec>, IEnumerable<SmallDec>, IEnumerable
    {
        /// <summary>
        /// Initialize from IEnumerable(SmallDec)
        /// </summary>
        /// <param name="tics"></param>
        public SmallDecCollection(IEnumerable<SmallDec> tics)
        {
            this.InnerList.Clear();
            this.InnerList.Add(tics);
        }

        /// <summary>
        /// Initialize from IEnumerable(int)
        /// </summary>
        /// <param name="tics"></param>
        public SmallDecCollection(IEnumerable<int> tics)
        {
            this.InnerList.Clear();
            this.InnerList.Add(tics);
        }

        /// <summary>
        /// Initialize from IEnumerable(double)
        /// </summary>
        /// <param name="tics"></param>
        public SmallDecCollection(IEnumerable<double> tics)
        {
            this.InnerList.Clear();
            this.InnerList.Add(tics);
        }

        /// <summary>
        /// Initialize or Clear current Collection
        /// </summary>
        public SmallDecCollection()
        {
            this.InnerList.Clear();
        }

        /// <summary>
        /// Retrieve value at index
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public SmallDec this[int index]
        {
            get
            {
                return (SmallDec)List[index];
            }

            set
            {
                this.List[index] = value;
            }
        }

        /// <summary>
        /// Convert from this to DoubleCollection
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator DoubleCollection(SmallDecCollection self)
        {
            DoubleCollection NewCollection = new DoubleCollection();
            foreach (var Element in self)
            {
                NewCollection.Add((double)Element);
            }
            return NewCollection;
        }

        /// <summary>
        /// Convert from DoubleCollection to this
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator SmallDecCollection(DoubleCollection self)
        {
            SmallDecCollection NewCollection = new SmallDecCollection();
            foreach (var Element in self)
            {
                NewCollection.Add((SmallDec)Element);
            }
            return NewCollection;
        }

        object IList.this[int index]
        {
            get
            {
                return (SmallDec)List[index];
            }

            set
            {
                List[index] = value;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool IsReadOnly
        {
            get { return false; }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        [CLSCompliant(false)]
        public int Add(object value)
        {
            return this.InnerList.Add((SmallDec)value);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="value"></param>
        [CLSCompliant(false)]
        public void Add(SmallDec value)
        {
            this.InnerList.Add(value);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="collection"></param>
        public void AddRange(SmallDecCollection collection)
        {
            if (collection != null)
            {
                this.InnerList.AddRange(collection);
            }
        }

        /// <summary>
        /// Removes all objects from Collection
        /// </summary>
        public new void Clear() => base.Clear();

        /// <summary>
        /// 
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public bool Contains(object value)
        {
            return this.List.Contains((SmallDec)value);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        [CLSCompliant(false)]
        public bool Contains(SmallDec value)
        {
            return this.List.Contains(value);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="array"></param>
        /// <param name="index"></param>
        public void CopyTo(Array array, int index)
        {
            this.List.CopyTo(array, index);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="array"></param>
        /// <param name="arrayIndex"></param>
        public void CopyTo(SmallDec[] array, int arrayIndex)
        {
            foreach (int i in List)
            {
                array.SetValue(i, arrayIndex);
                arrayIndex = arrayIndex + 1;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public int IndexOf(object value)
        {
            return base.List.IndexOf((SmallDec)value);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public int IndexOf(SmallDec value)
        {
            return base.List.IndexOf(value);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="index"></param>
        /// <param name="value"></param>
        public void Insert(int index, object value)
        {
            if (index <= List.Count)
            {
                this.List.Insert(index, (SmallDec)value);
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="index"></param>
        /// <param name="value"></param>
        public void Insert(int index, SmallDec value)
        {
            if (index <= List.Count)
            {
                this.List.Insert(index, value);
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="value"></param>
        public void Remove(object value)
        {
            this.InnerList.Remove((SmallDec)value);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="value"></param>
        public void Remove(SmallDec value)
        {
            this.InnerList.Remove(value);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="format"></param>
        /// <param name="formatProvider"></param>
        /// <returns></returns>
        public string ToString(string format, IFormatProvider formatProvider)
        {
            throw new NotImplementedException();
        }

        IEnumerator<SmallDec> IEnumerable<SmallDec>.GetEnumerator()
        {
            return new SmallDecEnumerator(List);
        }

        bool ICollection<SmallDec>.Remove(SmallDec value)
        {
            throw new NotImplementedException();
        }
    }

    /// <summary>
    /// 
    /// </summary>
    public class SmallDecEnumerator : IEnumerator<SmallDec>
    {
        private IList listValue;

        /// <summary>
        /// 
        /// </summary>
        public IList ListValue
        {
            get
            {
                return listValue;
            }

            set
            {
                listValue = value;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="ListValue"></param>
        public SmallDecEnumerator(IList ListValue)
        {
            this.ListValue = ListValue;
        }

        object IEnumerator.Current
        {
            get;
        }

        internal static object Range(SmallDec smallDec1, SmallDec smallDec2)
        {
            throw new NotImplementedException();
        }

        internal static object Range(int v1, int v2)
        {
            throw new NotImplementedException();
        }

        SmallDec IEnumerator<SmallDec>.Current
        {
            get
            {
                throw new NotImplementedException();
            }
        }

        bool IEnumerator.MoveNext()
        {
            throw new NotImplementedException();
        }

        void IEnumerator.Reset()
        {
            throw new NotImplementedException();
        }

        #region IDisposable Support

        private bool disposedValue = false; // To detect redundant calls

        /// <summary>
        /// 
        /// </summary>
        /// <param name="disposing"></param>
        protected virtual void Dispose(bool disposing)
        {
            if (!disposedValue)
            {
                if (disposing)
                {
                    // TODO: dispose managed state (managed objects).
                }

                // TODO: free unmanaged resources (unmanaged objects) and override a finalizer below.
                // TODO: set large fields to null.

                disposedValue = true;
            }
        }

        // TODO: override a finalizer only if Dispose(bool disposing) above has code to free unmanaged resources.
        // ~Enumerator() {
        //   // Do not change this code. Put cleanup code in Dispose(bool disposing) above.
        //   Dispose(false);
        // }

        // This code added to correctly implement the disposable pattern.
        void IDisposable.Dispose()
        {
            // Do not change this code. Put cleanup code in Dispose(bool disposing) above.
            Dispose(true);
            // TODO: uncomment the following line if the finalizer is overridden above.
            // GC.SuppressFinalize(this);
        }

        #endregion IDisposable Support
    }
}