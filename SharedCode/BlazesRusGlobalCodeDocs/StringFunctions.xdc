<?xml version="1.0"?><doc>
<members>
<member name="M:StringFunctions.LineStringContains(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\blazesrus\documents\visual studio 2013\projects\niflibtestenvironment\SharedCode\OtherFunctions\stringfunctions.cpp" line="21">
Check if LineString Contains SearchedString
 * @param LineString
 * @param SearchedString
 * @return

</member>
<member name="M:StringFunctions.OutputLineStringTabs(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\blazesrus\documents\visual studio 2013\projects\niflibtestenvironment\SharedCode\OtherFunctions\stringfunctions.cpp" line="55">
Use to keep tabs aligned on parameters(tab is equal to 4 spaces)
 * @param LineString @return StringContaining Tabs
</member>
<member name="M:StringFunctions.OutputQuadVariableLines(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\blazesrus\documents\visual studio 2013\projects\niflibtestenvironment\SharedCode\OtherFunctions\stringfunctions.cpp" line="77">
Use to keep tabs aligned on parameters
 * @param LineString
 * @return

</member>
<member name="M:StringFunctions.SeparateFilePathIntoFileName(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\blazesrus\documents\visual studio 2013\projects\niflibtestenvironment\SharedCode\OtherFunctions\stringfunctions.cpp" line="105">
Returns the filename from a full file-path
 * @param TempString
 * @return

</member>
<member name="M:StringFunctions.CreateLinkedHTMLString(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\blazesrus\documents\visual studio 2013\projects\niflibtestenvironment\SharedCode\OtherFunctions\stringfunctions.cpp" line="128">
@param LineString
@param TargetObject
@return

</member>
<member name="M:StringFunctions.RemoveStringTabs(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;)" decl="false" source="c:\users\blazesrus\documents\visual studio 2013\projects\niflibtestenvironment\SharedCode\OtherFunctions\stringfunctions.cpp" line="138">
Remove whitespace from start of line
 * @param LineString @return String
</member>
<member name="M:StringFunctions.ExamineTabSpace(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,System.Int32)" decl="false" source="c:\users\blazesrus\documents\visual studio 2013\projects\niflibtestenvironment\SharedCode\OtherFunctions\stringfunctions.cpp" line="160">
Examines the number of tabs/(equivalent of tabs in spaces) of whitespace before text
 * Rounds up partial amount of spaces leftover as being equivalent as another tab
 //Need to fix code to currectly calculate
 * @param LineString
 * @param TabEquivalent:Amount of spaces is equal to tab
 * @return

</member>
</members>
</doc>