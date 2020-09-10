// ***********************************************************************
// Assembly         : BlazesCSharpGlobalCode
// Author           : BlazesRus
// Created          : 07-14-2018
//
// Last Modified By : BlazesRus
// Last Modified On : 07-25-2018
// ***********************************************************************
// <copyright file="StringList.cs" company="">
//     Copyright ©  2018
// </copyright>
// <summary></summary>
// ***********************************************************************
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CSharpGlobalCode.VariableLists
{
	/// <summary>
	/// Class StringList.
	/// Implements the <see cref="System.Collections.Generic.List{System.String}" />
	/// </summary>
	/// <seealso cref="System.Collections.Generic.List{System.String}" />
	public class StringList : List<string>
    {
		//************************************
		// Method:    AddData
		// FullName:  StringList::AddData
		// Access:    public
		// Returns:   int
		// Qualifier:
		//************************************
		/// <summary>
		/// Adds the data.
		/// </summary>
		/// <returns>System.Int32.</returns>
		public int AddData()
        {
            int Index = Count;
            Add("");
            return Index;
        }

		//************************************
		// Method:    AddEntry
		// FullName:  StringList::AddEntry
		// Access:    public
		// Returns:   void
		// Qualifier:
		//Adds new entry into list at index 0(Used mainly for InfiniteScopePosInt)
		//************************************
		/// <summary>
		/// Adds the entry.
		/// </summary>
		public void AddEntry()
        {
            this.Add("");
        }

		//************************************
		// Method:    EditLastEntry
		// FullName:  StringList::EditLastEntry
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: int TempValue
		// Edits last value in List(Used mainly for InfiniteScopePosInt)
		//************************************
		/// <summary>
		/// Edits the last entry.
		/// </summary>
		/// <param name="TempValue">The temporary value.</param>
		public void EditLastEntry(string TempValue)
        {
            int LastIndex = Count - 1;
            this[LastIndex] = TempValue;
        }

		//************************************
		// Generates String with format Index:0_Index:1...Index:5
		// Method:    GenerateAsString
		// FullName:  StringList::GenerateAsString
		// Access:    public
		// Returns:   string
		// Qualifier:
		//************************************
		/// <summary>
		/// Generates as string.
		/// </summary>
		/// <returns>System.String.</returns>
		public string GenerateAsString()
        {
            string ConvertedString = "";
            int NumberLines = Count;
            for (int i = 0; i < NumberLines; ++i)
            {
                if (i != 0)
                {
                    ConvertedString += "\n";
                }
                ConvertedString += this[i];
            }
            return ConvertedString;
        }

		/// <summary>
		/// Converts the string to list.
		/// </summary>
		/// <param name="Content">The content.</param>
		public void ConvertStringToList(string Content)
        {
            if (Count != 0)
            {
                Clear();
            }
            int StringSize = Content.Length;
            char CurrentChar;
            var CurrentElement = new StringBuilder();
            string CurrentAsString;
            for (int Index = 0; Index < StringSize; ++Index)
            {
                CurrentChar = Content[Index];
                CurrentAsString = CurrentElement.ToString();
                if (CurrentAsString == "")
                {
                    if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
                    {
                        CurrentElement.Append(CurrentChar);
                    }
                }
                else
                {
                    if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
                    {
                        CurrentElement.Append(CurrentChar);
                    }
                    else
                    {
                        Add(CurrentAsString);
                        CurrentElement.Clear();
                    }
                }
            }
        }

		/// <summary>
		/// Initializes a new instance of the <see cref="StringList"/> class.
		/// </summary>
		/// <param name="Value">The value.</param>
		public StringList(string Value)
        {
            ConvertStringToList(Value);
        }

		/// <summary>
		/// Performs an explicit conversion from <see cref="System.String"/> to <see cref="StringList"/>.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>The result of the conversion.</returns>
		public static explicit operator StringList(string Value)
        {
            return new StringList(Value);
        }

		/// <summary>
		/// Initializes a new instance of the <see cref="StringList"/> class.
		/// </summary>
		public StringList()
        {
        }

		/// <summary>
		/// Saves the file data.
		/// </summary>
		/// <param name="FileName">Name of the file.</param>
		public void SaveFileData(string FileName)
        {
            byte[] encodedText;
            int NumberLines = Count;

            if (File.Exists(FileName))
            {
                using (FileStream sourceStream = new FileStream(FileName, FileMode.CreateNew, FileAccess.Write, FileShare.None, bufferSize: 4096, useAsync: true))
                {
                }
            }
            else
            {
                using (FileStream sourceStream = new FileStream(FileName, FileMode.Truncate, FileAccess.Write, FileShare.None, bufferSize: 4096, useAsync: true))
                {
                }
            }
            using (FileStream sourceStream = new FileStream(FileName, FileMode.Append, FileAccess.Write, FileShare.None, bufferSize: 4096, useAsync: false))
            {
                for (int i = 0; i < NumberLines; ++i)
                {
                    encodedText = Encoding.ASCII.GetBytes(this[i]);
                    sourceStream.Write(encodedText, 0, encodedText.Length);
                }
            };
        }

		/// <summary>
		/// save file data as an asynchronous operation.
		/// </summary>
		/// <param name="FileName">Name of the file.</param>
		/// <returns>System.Threading.Tasks.Task.</returns>
		public async System.Threading.Tasks.Task SaveFileDataAsync(string FileName)
        {
            byte[] encodedText;
            int NumberLines = Count;

            if (File.Exists(FileName))
            {
                using (FileStream sourceStream = new FileStream(FileName, FileMode.CreateNew, FileAccess.Write, FileShare.None, bufferSize: 4096, useAsync: true))
                {
                }
            }
            else
            {
                using (FileStream sourceStream = new FileStream(FileName, FileMode.Truncate, FileAccess.Write, FileShare.None, bufferSize: 4096, useAsync: true))
                {
                }
            }

            using (FileStream sourceStream = new FileStream(FileName, FileMode.Append, FileAccess.Write, FileShare.None, bufferSize: 4096, useAsync: true))
            {
                for (int i = 0; i < NumberLines; ++i)
                {
                    encodedText = Encoding.ASCII.GetBytes(this[i]);
                    await sourceStream.WriteAsync(encodedText, 0, encodedText.Length);
                }
            };
        }

		/// <summary>
		/// Loads the all file data into StringList
		/// </summary>
		/// <param name="FileName">Name of the file.</param>
		public void LoadFileData(string FileName)
        {
            this.Clear();
            /// <summary>
            /// Indicates that
            /// 1. The file is to be accessed sequentially from beginning to end.
            /// </summary>
            const FileOptions FileLoadOptions = FileOptions.SequentialScan;
            // Open the FileStream with the same FileMode, FileAccess
            // and FileShare as a call to File.OpenText would've done.
            using (var stream = new FileStream(FileName, FileMode.Open, FileAccess.Read, FileShare.Read, 4096, FileLoadOptions))
            using (var reader = new StreamReader(stream, Encoding.UTF8))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    this.Add(line);
                }
            }
        }

		/// <summary>
		/// Loads the file data with optional Comment Exclusion later
		/// </summary>
		/// <param name="FileName">Name of the file.</param>
		/// <param name="ConfigSetting">The configuration setting.</param>
		public void LoadFileDataV2(string FileName, byte ConfigSetting/*=0*/)
        {
            this.Clear();
            //char LineChar;
            string CommentBuffer = "";
            const string XMLCommentHeader = "<!--";
            const string XMLCommentFooter = "-->";
            bool ScanningXMLComments = false;
            //---------------
            //Scanning C++ style comments
            bool ScanningComments02 = false;
            // true = LineComments; false = Multi-line comments
            bool LineCommentType = false;
            //-------------------------
            int CommentIndex = 0;
            var Buffer = new StringBuilder();
            string LineString;
            /// <summary>
            /// Indicates that
            /// 1. The file is to be accessed sequentially from beginning to end.
            /// </summary>
            const FileOptions FileLoadOptions = FileOptions.SequentialScan;
            // Open the FileStream with the same FileMode, FileAccess
            // and FileShare as a call to File.OpenText would've done.
            using (var stream = new FileStream(FileName, FileMode.Open, FileAccess.Read, FileShare.Read, 4096, FileLoadOptions))
            using (var reader = new StreamReader(stream, Encoding.UTF8))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    foreach (var LineChar in line)
                    {
                        if (ScanningComments02)
                        {
                            if (LineCommentType == false)
                            {
                                if (LineChar == '*')
                                {
                                    CommentBuffer = "*";
                                }
                                else if (LineChar == '/' && CommentBuffer == "*")
                                {
                                    ScanningComments02 = false;
                                    CommentBuffer = "";
                                }
                                else
                                {
                                    CommentBuffer += LineChar;
                                }
                            }
                        }
                        else if (ConfigSetting != 0 && LineChar == '*' && CommentBuffer == "/")
                        {
                            LineCommentType = false;
                            ScanningComments02 = true;
                        }
                        else if (ConfigSetting != 0 && LineChar == '/' )
                        {
                            CommentBuffer += '/';
                            if (CommentBuffer == "//")
                            {
                                LineCommentType = true;
                                ScanningComments02 = true;
                            }
                            else if (CommentBuffer != "/")
                            {//Force buffer as "/" if anything other
                                CommentBuffer = "/";
                            }
                            else if (CommentBuffer.Length > 2)
                            {
                                CommentBuffer = "";
                            }
                        }
                        else if (ScanningXMLComments)
                        {
                            if (LineChar == XMLCommentFooter[CommentIndex])
                            {
                                CommentBuffer += LineChar;
                                if (CommentBuffer == XMLCommentFooter)
                                {
                                    CommentBuffer = "";
                                    ScanningXMLComments = true;
                                    CommentIndex = 0;
                                }
                                else if (CommentIndex < 2)
                                {
                                    CommentIndex++;
                                }
                                else
                                {
                                    CommentBuffer = "";
                                    CommentIndex = 0;
                                }
                            }
                            else
                            {
                                CommentBuffer = "";
                                CommentIndex = 0;
                            }
                        }
                        else if (CommentBuffer != "")
                        {
                            if (LineChar == XMLCommentHeader[CommentIndex])
                            {
                                CommentBuffer += LineChar;
                                if (CommentBuffer == XMLCommentHeader)
                                {
                                    CommentBuffer = "";
                                    ScanningXMLComments = true;
                                    CommentIndex = 0;
                                }
                                else if (CommentIndex < 3)
                                {
                                    CommentIndex++;
                                }
                                else
                                {//Prevent Bug causing Header to search out of index
                                    Buffer.Append(CommentBuffer);
                                }
                            }
                            else
                            {
                                Buffer.Append(CommentBuffer);
                            }
                        }
                        else if (ConfigSetting != 0 && LineChar == '<' && CommentBuffer == "")
                        {
                            CommentBuffer = "<";
                            CommentIndex = 1;
                        }
                        else
                        {
                            Buffer.Append(LineChar);
                        }
                    }
                    LineString = Buffer.ToString();
                    if (LineString != "")
                    {
                        Add(LineString);
                        Buffer.Clear();
                    }
                }
            }
        }
    }
}