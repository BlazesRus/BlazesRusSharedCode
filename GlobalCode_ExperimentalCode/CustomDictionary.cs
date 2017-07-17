using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    class CustomDictionary<TKey, TValue> : Dictionary<TKey, TValue>
    {
        /// <summary>
        /// Holds an index referring to keys contained for optional ordered retrieval of values
        /// </summary>
        List<TKey> KeyIndex = new List<TKey>();
        public void Add(TKey key, TValue value)
        {
            KeyIndex.Add(key);
            Base.Add(key, value);
        }
        /// <summary>
        /// Applies Add without recording into key index (default Dictionary Add operation)
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public void AddUnindexed(TKey key, TValue value)
        {
            Base.Add(key, value);
        }
        public bool Remove(TKey key)
        {
            KeyIndex.Remove(key);
            Base.Remove(key);
        }
        /// <summary>
        /// Applies Remove without removing from key index (default Dictionary Remove operation);Might causes errors for ValueAt operation
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public bool RemoveUnindexed(TKey key)
        {
            Base.Remove(key);
        }
        public void Clear()
        {
            KeyIndex.Clear();
            base.Clear();
        }
        /// <summary>
        /// Retrieves value in Dictionary at key index
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public TValue ValueAt(int index)
        {
            TKey IndexedKey = KeyIndex[index];
            TValue RetrievedValue = default(TValue);
            TryGetValue(IndexedKey, RetrievedValue);
            return RetrievedValue;
        }
    }
}
