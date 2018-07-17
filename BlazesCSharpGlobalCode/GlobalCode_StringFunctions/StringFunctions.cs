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
		}

		/// <summary>
		/// Check if LineString Contains SearchedString
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <param name="SearchedString">The searched string.</param>
		/// <returns></returns>
		public static bool LineStringContains(string LineString, string SearchedString)
		{
		}

		/// <summary>
		/// Use to keep tabs aligned on parameters(tab is equal to 4 spaces)
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <returns></returns>
		public static string OutputLineStringTabs(string LineString)
		{
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
		public static string CreateLinkedHTMLString(string LineString, string TargetObject)
		{
		}

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
		}

		//************************************
		//	Examines the number of tabs / (equivalent of tabs in spaces) of whitespace before text
		//	Rounds up partial amount of spaces leftover as being equivalent as another tab
		//	This is reduced parameter version of the function that uses Netbeans / Programmer's Notepad equivalent for tabs being 4 spaces
		// Method:    ExamineTabSpace
		// FullName:  StringFunctions::ExamineTabSpace
		// Access:    public static
		// Returns:   dynamic
		// Qualifier:
		// Parameter: string LineString
		//************************************
		/// <summary>
		/// Examines the number of tabs / (equivalent of tabs being 4 spaces) of whitespace before text (Rounds up partial amount of spaces leftover as being equivalent as another tab)
		/// </summary>
		/// <param name="LineString">The line string.</param>
		/// <returns></returns>
		public static int ExamineTabSpace(string LineString)
		{
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
		}

		////Replace first matching of SearchString inside LineString with ReplacementString (Functions similar to Java version of same function)
		////************************************
		//// Method:    ReplaceFirst
		//// FullName:  StringFunctions::ReplaceFirst
		//// Access:    public static
		//// Returns:   string
		//// Qualifier:
		//// Parameter: string LineString
		//// Parameter: string SearchString
		//// Parameter: string ReplacementString
		////************************************
		public static string ReplaceFirst(string LineString, string SearchString, string ReplacementString)
		{
		}

		////Replace all matching of SearchString inside LineString with ReplacementString (Functions similar to Java version of same function)
		////************************************
		//// Method:    ReplaceAll
		//// FullName:  StringFunctions::ReplaceAll
		//// Access:    public static
		//// Returns:   string
		//// Qualifier:
		//// Parameter: string LineString
		//// Parameter: string SearchString
		//// Parameter: string ReplacementString
		////************************************
		public static string ReplaceAll(string LineString, string SearchString, string ReplacementString)
		{
		}

		////Return ParamName of first <hkparam name="ParamName"> tag; if no name found returns ""
		////************************************
		//// Method:    ReturnParamName
		//// FullName:  StringFunctions::ReturnParamName
		//// Access:    public static
		//// Returns:   string
		//// Qualifier:
		//// Parameter: string LineString
		////************************************
		public static string ReturnParamName(string LineString)
		{
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
		////************************************
		//// Method:    CheckAndCorrectDirectoryLocation
		//// FullName:  StringFunctions::CheckAndCorrectDirectoryLocation
		//// Access:    public static
		//// Returns:   string
		//// Qualifier:
		//// Parameter: string Directory
		//// Parameter: bool Verbose
		////************************************
		public static string CheckAndCorrectDirectoryLocation(string Directory, bool Verbose = false)
		{
		}

		////************************************
		//// Method:    CheckAndCorrectFilepath
		//// FullName:  StringFunctions::CheckAndCorrectFilepath
		//// Access:    public static
		//// Returns:   string
		//// Qualifier:
		//// Parameter: string FileName
		//// Parameter: bool Verbose
		////************************************
		public static string CheckAndCorrectFilepath(string FileName, bool Verbose = false)
		{
		}

		/// <summary>
		/// Reads String to predict ContentType (Refer to TagNodeTreeTemplate for ContentType values)
		/// </summary>
		/// <param name="Content">The content.</param>
		/// <returns></returns>
		public static byte FindContentType(string Content)
		{
		}
	}
}