using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpGlobalCode.GlobalCode_VariableLists
{
    public class StringList : List<string>
    {
        //************************************
        // Method:    AddData
        // FullName:  StringList::AddData
        // Access:    public
        // Returns:   int
        // Qualifier:
        //************************************
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
        public StringList(string Value)
        {
            ConvertStringToList(Value);
        }

        public static explicit operator StringList(string Value)
        {
            return new StringList(Value);
        }
        public StringList(){}

		void LoadFileDataV2(string FileName, byte ConfigSetting/*=0*/)
		{
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
						else if (ConfigSetting != 0 && LineChar == '/')
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
			//	FileName = StringFunctions::CheckAndCorrectFilepath(FileName);
			//	std::string LineString;
			//	std::ofstream LoadedFileStream;
			//	LoadedFileStream.open(FileName, std::ios::in);
			//	size_t DataSize = Size();
			//	//char NextChar;

			//	if (LoadedFileStream.is_open())
			//	{
			//		if (LoadedFileStream.good())
			//		{
			//			std::filebuf* FileBuffer = LoadedFileStream.rdbuf();
			//			for (LineChar = FileBuffer->sbumpc(); LineChar != EOF; LineChar = FileBuffer->sbumpc())
			//			{
			//				//std::cout << LineChar;

			//			}
			//		}
			//		else
			//		{
			//			if (LoadedFileStream.bad()) { std::cout << "Failed Read/Write operation Error!\n"; }
			//			else if (LoadedFileStream.fail()) { std::cout << "Failed format based Error!\n"; }
			//			else if (LoadedFileStream.bad()) { std::cout << "Failed Read/Write operation Error!\n"; }
			//			else if (LoadedFileStream.eof()) {/*Send debug message of reaching end of file?*/ }
			//		}
			//		LoadedFileStream.close();
			//	}
			//	else
			//	{
			//		cout << "Failed to open filepath:" << FileName << "\n";
			//	}
		}
}
}
