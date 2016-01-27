/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#include "TagNodeTreeTemplate.h"
using std::string;

unsigned __int8 TagNodeTreeTemplateData::TagNodeFunctions::FindContentType(std::string Content)
{
	unsigned __int8 DetectedContentType = 0;
	//0 = No List Detected
	//1 = List Detected
	//2 = Possible List Detected
	unsigned __int8 ListDetectionState = 0;
	//false = testing for false value;true = testing for true value
	bool BoolValueDetecting;
	const string TrueString = "true";
	const string FalseString = "false";
	string CurrentElement = "";
	char CurrentChar;
	bool ContentTypeConfirmed=false;
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
	unsigned __int8 CurrentDetectionStatus = 0;
	//---------------------------------------------------------
	const size_t StringSize = Content.length();
	size_t ElementIndex;
	for(size_t Index=0; Index < StringSize&&!ContentTypeConfirmed;++Index)
	{
		CurrentChar = Content.at(Index);
		if(CurrentElement=="")
		{
			if(ListDetectionState==2)
			{
				if(CurrentChar!='\n'&&CurrentChar!=' '&&CurrentChar!='\t'&&CurrentChar!='	')
				{
					ListDetectionState = 1;
					//Convert detected type to List
					CurrentElement = CurrentChar;
					if(CurrentDetectionStatus<11)
					{
						CurrentDetectionStatus += 5;
					}
					else if(CurrentDetectionStatus==11)
					{
						CurrentDetectionStatus = 12;
					}
					ContentTypeConfirmed = true;
				}
			}
			else if(CurrentChar != '\n'&&CurrentChar != ' '&&CurrentChar != '\t'&&CurrentChar != '	')
			{
				if(CurrentChar=='t')
				{
					//Possible Bool/String Detected
					BoolValueDetecting = true;
					CurrentDetectionStatus = 1;
				}
				else if(CurrentChar=='f')
				{
					//Possible Bool/String Detected
					BoolValueDetecting = false;
					CurrentDetectionStatus = 1;
				}
				else if(CurrentChar=='-')//Only the first character of digit can be negative to count
				{
					//Possible Int/Double detected
					CurrentDetectionStatus = 3;
				}
				else if(CurrentChar=='#')
				{
					//Possible Havok Class Target Detected
					CurrentDetectionStatus = 2;
				}
				else if(CurrentChar=='1'||CurrentChar=='2'||CurrentChar=='3'||CurrentChar=='4'||CurrentChar=='5'
				||CurrentChar=='6'||CurrentChar=='7'||CurrentChar=='8'||CurrentChar=='9'||CurrentChar=='0')
				{
					//Possible Int/Double detected
					CurrentDetectionStatus = 3;
				}
				else if(CurrentChar=='(')
				{
					CurrentDetectionStatus = 11;
				}
				else
				{
					//Likely either String Value or value type not listed for detection
					CurrentDetectionStatus = 5;
				}
				CurrentElement = CurrentChar;
			}
		}
		else
		{
			if(CurrentDetectionStatus==11)
			{
				if(CurrentChar==')')
				{
					CurrentElement = "";
					ListDetectionState = 2;
				}
			}
			else if(CurrentChar != '\n'&&CurrentChar != ' '&&CurrentChar != '\t'&&CurrentChar != '	')
			{
				ElementIndex = CurrentElement.length();
				CurrentElement += CurrentChar;
				//check to see if matches pattern
				switch(CurrentDetectionStatus)
				{
					case 1:
						if(BoolValueDetecting)
						{
							if(CurrentElement.at(ElementIndex)!=TrueString.at(ElementIndex)){CurrentDetectionStatus = 5;}
						}
						else
						{
							if(CurrentElement.at(ElementIndex)!=FalseString.at(ElementIndex)){CurrentDetectionStatus = 5;}
						}
						break;
					case 2:
						//Allow all but whitespace to be counted as havok class character
						break;
					case 3:
						if(CurrentChar=='.')
						{
							CurrentDetectionStatus = 4;
						}
						else if(CurrentChar!='1'&&CurrentChar!='2'&&CurrentChar!='3'&&CurrentChar!='4'&&CurrentChar!='5'&&CurrentChar!='6'&&CurrentChar!='7'&&CurrentChar!='8'&&CurrentChar!='9'&&CurrentChar!='0')//Non-Digit Char detected
						{
							CurrentDetectionStatus = 5;
						}
						break;
					case 4:
						if(CurrentChar!='1'&&CurrentChar!='2'&&CurrentChar!='3'&&CurrentChar!='4'&&CurrentChar!='5'&&CurrentChar!='6'&&CurrentChar!='7'&&CurrentChar!='8'&&CurrentChar!='9'&&CurrentChar!='0')//Non-Digit Char detected
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
	switch(CurrentDetectionStatus)
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

StringVectorList TagNodeTreeTemplateData::TagNodeFunctions::ConvertStringToStringVectorList(std::string Content)
{
	StringVectorList ConvertedValue;
	const size_t StringSize = Content.length();
	char CurrentChar;
	std::string CurrentElement="";
	for(size_t Index=0; Index < StringSize;++Index)
	{
		CurrentChar = Content.at(Index);
		if(CurrentElement=="")
		{
			if(CurrentChar != '\n'&&CurrentChar != ' '&&CurrentChar != '\t'&&CurrentChar != '	')
			{
				CurrentElement = CurrentChar;
			}
		}
		else
		{
			if(CurrentChar != '\n'&&CurrentChar != ' '&&CurrentChar != '\t'&&CurrentChar != '	')
			{
				CurrentElement += CurrentChar;
			}
			else
			{
				ConvertedValue.Add(CurrentElement);
				CurrentElement = "";
			}
		}
	}
	return ConvertedValue;
}
