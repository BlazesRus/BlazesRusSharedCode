using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    //based on http://michaelcummings.net/mathoms/using-a-custom-jsonconverter-to-fix-bad-json-results/
    //and http://www.newtonsoft.com/json/help/html/CustomJsonConverter.htm
    //and http://www.jerriepelser.com/blog/custom-converters-in-json-net-case-study-1/
    //Place [JsonConverter(typeof(CustomJSONConverter))] before variable to use
    public partial class CustomJSONConverter : Newtonsoft.Json.JsonConverter
    {
        private static readonly Type[] SupportedTypes = { typeof(string), typeof(SmallDec), typeof(double), typeof(float), typeof(decimal),
        typeof(byte),typeof(sbyte),typeof(int),typeof(uint),typeof(short),typeof(ushort),typeof(ulong),typeof(long)};
        public override void WriteJson(JsonWriter writer, object value, JsonSerializer serializer)
        {
            JToken TokenVal = JToken.FromObject(value);
            if(value is SmallDec)
            {
                Console.WriteLine("SmallDec WriteJSon detected.");
            }
            if (TokenVal.Type != JTokenType.Object)
            {
                TokenVal.WriteTo(writer);
            }
            else
            {
                JObject ObjVal = (JObject)TokenVal;
                foreach (var ValElement in ObjVal.Values())
                {
                    ValElement.WriteTo(writer);
                }
                //IList<string> propertyNames = ObjVal.Properties().Select(p => p.Name).ToList();
                //ObjVal.AddFirst(new JProperty("Keys", new JArray(propertyNames)));
                //ObjVal.WriteTo(writer);
            }
            //throw new NotImplementedException();
        }

        public override object ReadJson(JsonReader reader, Type objectType, object existingValue, JsonSerializer serializer)
        {
            object retVal = new Object();
            Console.WriteLine("JSON objectType:" + objectType.ToString() + " Existing ObjectValue:" + (string)existingValue);
            string ReaderValue = reader.ReadAsString();
            Console.Write("JSon ReaderValue:" + ReaderValue);
            if (reader.TokenType == JsonToken.StartObject)
            {
                //T instance = (T)serializer.Deserialize(reader, typeof(T));
                //retVal = new List<T>() { instance };
                retVal = serializer.Deserialize(reader, objectType);
            }
            else if (reader.TokenType == JsonToken.StartArray)
            {
                JArray ArrayValue = JArray.Load(reader);

                ////var users = ArrayValue.ToObject<IList<User>>();
                //return new PagedList<User>(users);
                retVal = serializer.Deserialize(reader, objectType);
            }
            else
            {
                retVal = serializer.Deserialize(reader, objectType);
            }
            return retVal;
        }

        public override bool CanConvert(Type objectType)
        {
            return SupportedTypes.Any(t => t == objectType);
        }
    }
}
