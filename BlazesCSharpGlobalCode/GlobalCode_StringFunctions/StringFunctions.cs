namespace CSharpGlobalCode.GlobalCode_StringFunctions
{
	internal class StringFunctions
	{
		/// <summary>
		/// Adds the string in front.
		/// </summary>
		/// <param name="ValueAdded">The value added.</param>
		/// <param name="TargetString">The target string.</param>
		/// <returns></returns>
		public static string AddStringInFront(string ValueAdded, string TargetString)
		{
			string TempString;
			TempString = ValueAdded + TargetString;
			return TempString;
		}

		public static string AddStringInFront(char ValueAdded, string TargetString)
		{
			string TempString;
			TempString = ValueAdded + TargetString;
			return TempString;
		}

		/// <summary>
		/// Check if LineString Contains SearchedString
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <param name="SearchedString">The searched string.</param>
		/// <returns></returns>
		public static bool LineStringContains(string LineString, string SearchedString)
		{
			bool Confirmed = false;
			if ((LineString.CompareTo(SearchedString) == 0 || LineString.CompareTo(SearchedString) >= 1))
			{
				Confirmed = true;
			}
			return Confirmed;
		}

		/// <summary>
		/// Use to keep tabs aligned on parameters(tab is equal to 4 spaces)
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <returns></returns>
		public static string OutputLineStringTabs(string LineString)
		{
			string TempString = "";
			int StringLength = LineString.Length;
			bool Finished = false;
			string StringChar;
			for (int i = 0; i < StringLength || Finished; i++)
			{
				StringChar = "" + LineString[i];
				if (StringChar == "[^\\\\d]")//Only Records Whitespace/tabs
				{
					TempString += StringChar;
				}
				else
				{
					Finished = true;
				}
			}
			return TempString;
		}

		//************************************
		//Create TabSpace string based on TabSpace amount
		// Method:    CreateTabSpace
		// FullName:  StringFunctions::CreateTabSpace
		// Access:    public static
		// Returns:   string
		// Qualifier:
		// Parameter: dynamic temp
		//************************************
		public static string CreateTabSpace(int temp)
		{
			string TempString = "";
			while (temp > 0)
			{
				TempString += "	";
				temp--;
			}
			return TempString;
		}

		//************************************
		// Use to keep tabs aligned on parameters
		// Method:    OutputQuadVariableLines
		// FullName:  StringFunctions::OutputQuadVariableLines
		// Access:    public static
		// Returns:   string
		// Qualifier:
		// Parameter: string LineString
		//************************************
		public static string OutputQuadVariableLines(string LineString)
		{
			string TempString = "";
			int StringLength = LineString.Length;
			bool RecordString = false;
			string StringChar;
			for (int i = 0; (i < StringLength); i++)
			{
				StringChar = "" + LineString[i];
				if (RecordString)
				{
					TempString += StringChar;
				}
				else
				{
					if (StringChar == "(")//Only Records Whitespace/tabs
					{
						RecordString = true;
						TempString += StringChar;
					}
				}
			}
			return TempString;
		}

		//************************************
		// Returns the filename from a full file-path
		// Method:    SeparateFilePathIntoFileName
		// FullName:  StringFunctions::SeparateFilePathIntoFileName
		// Access:    public static
		// Returns:   string
		// Qualifier:
		// Parameter: string TempString
		//************************************
		public static string SeparateFilePathIntoFileName(string TempString)
		{
			string FileName = "";
			int StringLength = TempString.Length;
			char StringChar;
			for (int i = 0; i < StringLength; i++)
			{
				StringChar = TempString[i];
				if (StringChar == '/' || StringChar == '\\')//Separate filename with path slashes(and reset filename buffer)
				{
					FileName = "";
				}
				else
				{
					FileName += StringChar;
				}
			}
			return FileName;
		}

		//************************************
		// Method:    CreateLinkedHTMLString
		// FullName:  StringFunctions::CreateLinkedHTMLString
		// Access:    public static
		// Returns:   string
		// Qualifier:
		// Parameter: string LineString
		// Parameter: string TargetObject
		//************************************
		public static string CreateLinkedHTMLString(string LineString, string TargetObject) => "<a href=" + TargetObject + "><code>" + LineString + "</code></a>";

		//************************************
		//Remove whitespace from start of line
		// Method:    RemoveStringTabs
		// FullName:  StringFunctions::RemoveStringTabs
		// Access:    public static
		// Returns:   string
		// Qualifier:
		// Parameter: string LineString
		//************************************
		public static string RemoveStringTabs(string LineString)
		{
			string TempString = "";
			int StringLength = LineString.Length;
			bool Finished = false;
			string StringChar;
			for (int i = 0; i < StringLength; ++i)
			{
				StringChar = "" + LineString[i];
				if (StringChar != "[^\\\\d]")//Only Records Whitespace/tabs
				{
					Finished = true;
				}
				if (Finished)
				{
					TempString += StringChar;
				}
			}
			return TempString;
		}

		//************************************
		// Examines the number of tabs/(equivalent of tabs in spaces) of whitespace before text (TabEquivalent=Amount of spaces is equal to tab)
		// Method:    ExamineTabSpace
		// FullName:  StringFunctions::ExamineTabSpace
		// Access:    public static
		// Returns:   dynamic
		// Qualifier:
		// Parameter: string LineString
		// Parameter: dynamic TabEquivalent
		//************************************
		public static int ExamineTabSpace(string LineString, dynamic TabEquivalent)
		{
			int AmountOfTabs = 0;
			int TotalSpaces = 0;
			int StringLength = LineString.Length;
			bool Finished = false;
			string StringChar;
			for (int i = 0; i < StringLength && Finished == false; ++i)
			{
				StringChar = ""+LineString[i];
				if (StringChar == "\t" || StringChar == "	")
				{
					AmountOfTabs++;
				}
				else if (StringChar == " ")
				{
					TotalSpaces++;
				}
				else
				{
					Finished = true;
				}
				if (TotalSpaces == TabEquivalent)
				{
					TotalSpaces = 0;
					AmountOfTabs++;
				}
			}
			if (TotalSpaces > 0)
			{//Round up number of spaces as being equivalent to a tab
				AmountOfTabs++;
			}
			return AmountOfTabs;
		}

		/// <summary>
		/// Examines the number of tabs / (equivalent of tabs being 4 spaces) of whitespace before text (Rounds up partial amount of spaces leftover as being equivalent as another tab)
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <returns></returns>
		public static int ExamineTabSpace(string LineString)
		{
			return ExamineTabSpace(LineString, 4);
		}

		/// <summary>
		/// Removes Specific amount of whitespace from front of LineString(AmountOfWhitespaceRemoval=How many tabs worth of whitespace to remove)
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <param name="TabEquivalent">The tab equivalent.</param>
		/// <param name="AmountOfWhitespaceRemoval">The amount of whitespace removal.</param>
		/// <returns></returns>
		public static string RemoveAmountOfTabSpace(string LineString, int TabEquivalent, int AmountOfWhitespaceRemoval)
		{
			string TempString = "";
			int AmountOfTabs = 0;
			int TotalSpaces = 0;
			int StringLength = LineString.Length;
			bool Finished = false;
			string StringChar;
			for (int i = 0; i < StringLength; ++i)
			{
				StringChar = "" + LineString[i];
				if (Finished == false)
				{
					if (StringChar == "[^\\\\d]")//Only Records Whitespace/tabs
					{
						if (StringChar == "\t")
						{
							++AmountOfTabs;
						}
						else if (StringChar == " ")
						{
							++TotalSpaces;
						}
					}
					else
					{
						TempString += StringChar;
						Finished = true;
					}
					if (TotalSpaces == TabEquivalent)
					{
						TotalSpaces = 0;
						++AmountOfTabs;
					}
					if (AmountOfTabs >= AmountOfWhitespaceRemoval)
					{
						Finished = true;
					}
				}
				else
				{
					TempString += StringChar;
				}
			}
			return TempString;
		}

		//************************************
		// Removes all XML/HTML type tags (Things like<XML Data>) from LineString
		// Method:    RemoveXMLTags
		// FullName:  StringFunctions::RemoveXMLTags
		// Access:    public static
		// Returns:   string
		// Qualifier:
		// Parameter: string LineString
		//************************************
		/// <summary>
		/// Removes all XML/HTML type tags (Things like<XML Data>) from LineString
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <returns></returns>
		public static string RemoveXMLTags(string LineString)
		{
			int StringLength = LineString.Length;
			string TempString = "";
			bool InsideTag = false;
			char StringChar;
			for (int i = 0; i < StringLength; ++i)
			{
				StringChar = LineString[i];
				if (InsideTag)
				{
					if (StringChar == '>')
					{
						InsideTag = false;
					}
				}
				else if (StringChar == '<')
				{
					InsideTag = true;
				}
				else
				{
					TempString += StringChar;
				}
			}
			return TempString;
		}

		//************************************
		// Similar to RemoveXMLTags but only returns data after first tag(only gives data for first tag contents)
		// Method:    ReturnXMLTagContent
		// FullName:  StringFunctions::ReturnXMLTagContent
		// Access:    public static
		// Returns:   string
		// Qualifier:
		// Parameter: string LineString
		//************************************
		/// <summary>
		/// Returns the content of the XML tag.
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <returns></returns>
		public static string ReturnXMLTagContent(string LineString)
		{
			int StringLength = LineString.Length;
			string TempString = "";
			bool InsideTag = false;
			byte TagDataStage = 0;
			char StringChar;
			for (int i = 0; i < StringLength; i++)
			{
				StringChar = LineString[i];
				if (InsideTag)
				{
					if (StringChar == '>')
					{
						InsideTag = false;
						if (TagDataStage == 0)
						{
							TagDataStage = 1;
						}
					}
				}
				else if (StringChar == '<')
				{
					InsideTag = true;
					if (TagDataStage == 1)
					{
						TagDataStage = 2;
					}
				}
				else if (TagDataStage == 1)
				{
					TempString += StringChar;
				}
			}
			return TempString;
		}

		/// <summary>
		/// Replace first matching of SearchString inside LineString with ReplacementString (Functions similar to Java version of same function)
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <param name="SearchString">The search string.</param>
		/// <param name="ReplacementString">The replacement string.</param>
		/// <returns></returns>
		public static string ReplaceFirst(string LineString, string SearchString, string ReplacementString)
		{
			if (SearchString != "")
			{
				//Current character loaded in steam
				char StringChar;
				//Current Loaded parts of LineString
				string LoadedLineString = "";
				//Current Characters worth of string found that match SearchString
				string PartialSearchBuffer = "";
				//Current Index of Loaded PartialSearch
				int PartialBufferIndex = 0;
				//Total size of LineString to load
				int StringSize = LineString.Length;
				//Boolean check to determine if have found first string match
				bool SearchSuccess = false;
				for (int i = 0; i < StringSize; ++i)
				{
					StringChar = LineString[i];
					if (SearchSuccess)
					{
						LoadedLineString += StringChar;
					}
					else
					{
						//Matching Partial String Search
						if (SearchString[PartialBufferIndex] == StringChar)
						{
							PartialSearchBuffer += StringChar;
							//Successful Find And Replace
							if (PartialSearchBuffer == SearchString)
							{
								LoadedLineString += ReplacementString;
								//PartialSearchBuffer = "";
								SearchSuccess = true;
							}
							else
							{
								PartialBufferIndex++;
							}
						}
						//Failed Partial String Search
						else
						{
							LoadedLineString += PartialSearchBuffer;
							PartialSearchBuffer = "";
							PartialBufferIndex = 0;
							LoadedLineString += StringChar;
						}
					}
				}
				LoadedLineString += PartialSearchBuffer;
				return LoadedLineString;
			}
			else
			{
				return LineString;
			}
		}

		/// <summary>
		/// Replace all matching of SearchString inside LineString with ReplacementString (Functions similar to Java version of same function)
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <param name="SearchString">The search string.</param>
		/// <param name="ReplacementString">The replacement string.</param>
		/// <returns></returns>
		public static string ReplaceAll(string LineString, string SearchString, string ReplacementString)
		{
			if (SearchString != "")
			{
				//Current character loaded in steam
				char StringChar;
				//Current Loaded parts of LineString
				string LoadedLineString = "";
				//Current Characters worth of string found that match SearchString
				string PartialSearchBuffer = "";
				//Current Index of Loaded PartialSearch
				int PartialBufferIndex = 0;
				//Total size of LineString to load
				int StringSize = LineString.Length;
				for (int i = 0; i < StringSize; ++i)
				{
					StringChar = LineString[i];
					//Matching Partial String Search
					if (SearchString[PartialBufferIndex] == StringChar)
					{
						PartialSearchBuffer += StringChar;
						//Successful Find And Replace
						if (PartialSearchBuffer == SearchString)
						{
							LoadedLineString += ReplacementString;
							PartialSearchBuffer = "";
						}
						else
						{
							++PartialBufferIndex;
						}
					}
					//Failed Partial String Search
					else
					{
						LoadedLineString += PartialSearchBuffer;
						PartialSearchBuffer = "";
						PartialBufferIndex = 0;
						LoadedLineString += StringChar;
					}
				}
				LoadedLineString += PartialSearchBuffer;
				return LoadedLineString;
			}
			else
			{
				return LineString;
			}
		}

		/// <summary>
		/// Return ParamName of first <hkparam name="ParamName"> tag; if no name found returns ""
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <returns></returns>
		public static string ReturnParamName(string LineString)
		{
			string SearchString = "<hkparam name=\"";
			//Temporary convert of char to string
			string TempChar;
			//Current character loaded in steam
			string StringChar;
			//Current Loaded parts of ParamName
			string ParamName = "";
			//Current Characters worth of string found that match SearchString
			string PartialSearchBuffer = "";
			//Current Index of Loaded PartialSearch
			int PartialBufferIndex = 0;
			//Total size of LineString to load
			int StringSize = LineString.Length;
			//Boolean check to determine if have found first string match of SearchString
			bool SearchSuccess = false;
			//Boolean check to determine if done scanning ParamName
			bool ParamNameScanInProgress = true;
			for (int i = 0; i < StringSize && ParamNameScanInProgress; ++i)
			{
				StringChar = ""+LineString[i];
				if (SearchSuccess)
				{
					if (ParamNameScanInProgress)
					{
						if (StringChar != "\"")
						{
							ParamName += StringChar;
						}
						else
						{
							ParamNameScanInProgress = false;
						}
					}
				}
				else
				{
					TempChar = ""+SearchString[PartialBufferIndex];
					//Matching Partial String Search
					if (TempChar == StringChar)
					{
						PartialSearchBuffer += StringChar;
						//Successful Find And Replace
						if (PartialSearchBuffer == SearchString)
						{
							PartialSearchBuffer = "";
							SearchSuccess = true;
						}
						else
						{
							PartialBufferIndex++;
						}
					}
					//Failed Partial String Search
					else
					{
						PartialSearchBuffer = "";
						PartialBufferIndex = 0;
					}
				}
			}
			return ParamName;
		}

		////************************************
		//// Converts Pointer into String Address(Code from http://www.cplusplus.com/forum/general/8597/)
		//// Method:    ConvertPointerToStringAddress
		//// FullName:  StringFunctions::ConvertPointerToStringAddress
		//// Access:    public
		//// Returns:   string
		//// Qualifier:
		//// Parameter: const T * obj
		////************************************
		//template <typename T>
		//static string ConvertPointerToStringAddress(const T* obj);
		////************************************
		//// Method:    ConvertPointerToStringAddressV2
		//// FullName:  StringFunctions::ConvertPointerToStringAddressV2
		//// Access:    public
		//// Returns:   string
		//// Qualifier:
		//// Parameter: T * obj
		////************************************
		//template <typename T>
		//static string ConvertPointerToStringAddressV2(T* obj);

	//	/// <summary>
	//	/// String to char array code from http://stackoverflow.com/questions/13294067/how-to-convert-string-to-char-array-in-c
	//	/// Directory checking code from http://stackoverflow.com/questions/18100097/portable-way-to-check-if-directory-exists-windows-linux-c
	//	/// </summary>
	//	/// <param name="Directory">The directory.</param>
	//	/// <param name="Verbose">if set to <c>true</c> [verbose].</param>
	//	/// <returns></returns>
	//	public static string CheckAndCorrectDirectoryLocation(string Directory, bool Verbose = false)
	//	{
	//		bool DirectoryExists;
	//		struct stat info;
	//		char CharStringBuffer[1024];
	//		strncpy_s(CharStringBuffer, Directory.c_str(), sizeof(CharStringBuffer));
	//		CharStringBuffer[sizeof(CharStringBuffer) - 1] = 0;
	//		if(stat(CharStringBuffer, &info) != 0)
	//		{
	//			if(Verbose) { printf("cannot access %s\n", CharStringBuffer);
	//		}
	//		DirectoryExists = false;
	//		}
	//		else if(info.st_mode & S_IFDIR)
	//		{
	//			if(Verbose) { printf("%s is a directory\n", CharStringBuffer); }
	//			DirectoryExists = true;
	//		}
	//		else
	//		{
	//			if(Verbose) { printf("%s is no directory\n", CharStringBuffer); }
	//			DirectoryExists = false;
	//		}
	//		if(DirectoryExists==false)
	//		{
	//		//Create code to Attempt Auto-fix format of directory later
	//		}
	//	return Directory;
	//}


	//public static string CheckAndCorrectFilepath(string FileName, bool Verbose = false)
	//{
	//	bool DirectoryExists=false;
	//	bool IsFilePath=false;
	//	struct stat info;
	//	char CharStringBuffer[1024];
	//	strncpy_s(CharStringBuffer, FileName.c_str(), sizeof(CharStringBuffer));
	//	CharStringBuffer[sizeof(CharStringBuffer) - 1] = 0;
	//	if(stat(CharStringBuffer, &info) != 0)
	//	{
	//		if(Verbose) { printf("cannot access %s\n", CharStringBuffer); }
	//		DirectoryExists = false;
	//	}
	//	else if(stat(CharStringBuffer, &info) == 0)
	//	{
	//		if(Verbose) { printf("%s is a filepath\n", CharStringBuffer); }
	//		IsFilePath = true;
	//	}
	//	else if(info.st_mode & S_IFDIR)
	//	{
	//		if(Verbose) { printf("%s is a directory\n", CharStringBuffer); }
	//		DirectoryExists = true;
	//	}
	//	else
	//	{
	//		if(Verbose) { printf("%s is no directory\n", CharStringBuffer); }
	//		DirectoryExists = false;
	//	}
	//	if(IsFilePath==false&&DirectoryExists==false)
	//	{
	//		//Create code to attempt Auto-Fix filepath format later
	//	}
	//	return FileName;
	//}

		/// <summary>
		/// Reads String to predict ContentType (Refer to TagNodeTreeTemplate for ContentType values)
		/// </summary>
		/// <param name="Content">The content.</param>
		/// <returns></returns>
		public static byte FindContentType(string Content)
		{
			byte DetectedContentType = 0;
			//0 = No List Detected
			//1 = List Detected
			//2 = Possible List Detected
			byte ListDetectionState = 0;
			//false = testing for false value;true = testing for true value
			bool BoolValueDetecting = false;
			const string TrueString = "true";
			const string FalseString = "false";
			string CurrentElement = "";
			char CurrentChar;
			bool ContentTypeConfirmed = false;
			//0 = Whitespace only/Nothing so far
			//1 = Possible Bool/String Detected
			//2 = Possible Havok Class Target Detected
			//3 = Possible Int/Double Detected
			//4 = Possible Double Detected
			//5 = Likely String Detected
			//6 = Possible BoolList Detected
			//7 = Possible Havok Class Target List Detected
			//8 = Possible IntegerList Detected
			//9 = Possible DoubleList Detected
			//10 = Likely StringList Detected
			//11 = Possible QuadVector Detected
			//12 = Possible QuadVectorList Detected
			byte CurrentDetectionStatus = 0;
			//---------------------------------------------------------
			int StringSize = Content.Length;
			int ElementIndex;
			for (int Index = 0; Index < StringSize && !ContentTypeConfirmed; ++Index)
			{
				CurrentChar = Content[Index];
				if (CurrentElement == "")
				{
					if (ListDetectionState == 2)
					{
						if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
						{
							ListDetectionState = 1;
							//Convert detected type to List
							CurrentElement = ""+CurrentChar;
							if (CurrentDetectionStatus < 11)
							{
								CurrentDetectionStatus += 5;
							}
							else if (CurrentDetectionStatus == 11)
							{
								CurrentDetectionStatus = 12;
							}
							ContentTypeConfirmed = true;
						}
					}
					else if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
					{
						if (CurrentChar == 't')
						{
							//Possible Bool/String Detected
							BoolValueDetecting = true;
							CurrentDetectionStatus = 1;
						}
						else if (CurrentChar == 'f')
						{
							//Possible Bool/String Detected
							BoolValueDetecting = false;
							CurrentDetectionStatus = 1;
						}
						else if (CurrentChar == '-')//Only the first character of digit can be negative to count
						{
							//Possible Int/Double detected
							CurrentDetectionStatus = 3;
						}
						else if (CurrentChar == '#')
						{
							//Possible Havok Class Target Detected
							CurrentDetectionStatus = 2;
						}
						else if (CurrentChar == '1' || CurrentChar == '2' || CurrentChar == '3' || CurrentChar == '4' || CurrentChar == '5'
							|| CurrentChar == '6' || CurrentChar == '7' || CurrentChar == '8' || CurrentChar == '9' || CurrentChar == '0')
						{
							//Possible Int/Double detected
							CurrentDetectionStatus = 3;
						}
						else if (CurrentChar == '(')
						{
							CurrentDetectionStatus = 11;
						}
						else
						{
							//Likely either String Value or value type not listed for detection
							CurrentDetectionStatus = 5;
						}
						CurrentElement = ""+CurrentChar;
					}
				}
				else
				{
					if (CurrentDetectionStatus == 11)
					{
						if (CurrentChar == ')')
						{
							CurrentElement = "";
							ListDetectionState = 2;
						}
					}
					else if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
					{
						ElementIndex = CurrentElement.Length;
						CurrentElement += CurrentChar;
						//check to see if matches pattern
						switch (CurrentDetectionStatus)
						{
							case 1:
								if (BoolValueDetecting)
								{
									if (CurrentElement[ElementIndex] != TrueString[ElementIndex]) { CurrentDetectionStatus = 5; }
								}
								else
								{
									if (CurrentElement[ElementIndex] != FalseString[ElementIndex]) { CurrentDetectionStatus = 5; }
								}
								break;
							case 2:
								//Allow all but whitespace to be counted as Havok class character
								break;
							case 3:
								if (CurrentChar == '.')
								{
									CurrentDetectionStatus = 4;
								}
								else if (CurrentChar != '1' && CurrentChar != '2' && CurrentChar != '3' && CurrentChar != '4' && CurrentChar != '5' && CurrentChar != '6' && CurrentChar != '7' && CurrentChar != '8' && CurrentChar != '9' && CurrentChar != '0')//Non-Digit Char detected
								{
									CurrentDetectionStatus = 5;
								}
								break;
							case 4:
								if (CurrentChar != '1' && CurrentChar != '2' && CurrentChar != '3' && CurrentChar != '4' && CurrentChar != '5' && CurrentChar != '6' && CurrentChar != '7' && CurrentChar != '8' && CurrentChar != '9' && CurrentChar != '0')//Non-Digit Char detected
								{
									CurrentDetectionStatus = 5;
								}
								break;
								//default:
								//	break;
						}
					}
					else
					{
						//End of Current Element
						CurrentElement = "";
						ListDetectionState = 2;
					}
				}
			}
			switch (CurrentDetectionStatus)
			{
				//Type of data stores inside Tag (Strings stored in TagContent)
				//0:Default Extracted content
				//1:Int
				//2:Bool
				//3:Double
				//4:String
				//5:Event Index(Int)
				//6:Variable Index(Int)
				//7:Havok Class index(Int)
				//9:QuadVector
				//10:Event String
				//11:Variable String
				//12:Animation Path String
				//13:Condition (String)
				//14:Havok Class Target Name (String)
				//15:Havok Class Target List (StringVectorList)
				//20:IntegerList
				//21:DoubleList
				//22:StringVectorList
				//23:BooleanList
				//24:QuadVectorList
				//50:flags (String)
				//51:Clip Mode (String)
				//240:Holds Havok Class info
				//241:hkobject Container
				//242:Closing Tag of Havok Class
				//250:Unknown (String)
				//251:Unknown(String) with only whitespace and
				case 1:
					DetectedContentType = 2;
					break;
				case 2:
					DetectedContentType = 14;
					break;
				case 3:
					DetectedContentType = 1;
					break;
				case 4:
					DetectedContentType = 3;
					break;
				case 5:
					DetectedContentType = 4;
					break;
				case 6:
					DetectedContentType = 23;
					break;
				case 7:
					DetectedContentType = 15;
					break;
				case 8:
					DetectedContentType = 20;
					break;
				case 9:
					DetectedContentType = 21;
					break;
				case 10:
					DetectedContentType = 22;
					break;
				case 11:
					DetectedContentType = 9;
					break;
				case 12:
					DetectedContentType = 24;
					break;
				default:
					DetectedContentType = 251;
					break;
			}
			return DetectedContentType;
		}
	}
}