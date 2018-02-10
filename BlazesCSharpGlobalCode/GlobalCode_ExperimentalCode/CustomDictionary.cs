using System.Collections.Generic;

namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    class CustomDictionary<TKey, TValue> : Dictionary<TKey, TValue>
    {
        /// <summary>
        /// Holds an index referring to keys contained for optional ordered retrieval of values
        /// </summary>
        List<TKey> KeyIndex = new List<TKey>();

        /// <summary>
        /// 
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public new void Add(TKey key, TValue value)
        {
            KeyIndex.Add(key);
            base.Add(key, value);
        }
        /// <summary>
        /// Applies Add without recording into key index (default Dictionary Add operation)
        /// </summary>
        /// <param name="key"></param>
        /// <param name="value"></param>
        public void AddUnindexed(TKey key, TValue value)
        {
            base.Add(key, value);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public new bool Remove(TKey key)
        {
            KeyIndex.Remove(key);
            return base.Remove(key);
        }
        /// <summary>
        /// Applies Remove without removing from key index (default Dictionary Remove operation);Might causes errors for ValueAt operation
        /// </summary>
        /// <param name="key"></param>
        /// <returns></returns>
        public bool RemoveUnindexed(TKey key)
        {
            return base.Remove(key);
        }

        /// <summary>
        /// 
        /// </summary>
        public new void Clear()
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
            TryGetValue(IndexedKey, out RetrievedValue);
            return RetrievedValue;
        }
    }
}
