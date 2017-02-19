using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpGlobalCode.GlobalCode_IniData
{
	//class IniDataElement
	//{
	//	bool IsIniCategory = false;
	//	std::string ScriptArg01;
	//	std::string ScriptArg02;
	//	//IniDataElement();
	//	//~IniDataElement();
	//};

	//class IniData : public VariableList<IniDataElement>
	//{
	//	unsigned __int8 IniType = 0;
	//	//************************************
	//	// Method:    LoadIniData
	//	// FullName:  IniData::LoadIniData
	//	// Access:    public 
	//	// Returns:   void
	//	// Qualifier:
	//	// Parameter: std::string FileName
	//	//************************************
	//	void LoadIniData(std::string FileName)
	//	{
	//			StringVectorList TargetSettings;
	//			TargetSettings.LoadFileDataV2(FileName);
	//			//First part of command;Syntax:[ScriptArg01=ScriptArg02]
	//			std::string ScriptArg01;
	//			//Command Value;Syntax:[ScriptArg01=ScriptArg02]
	//			std::string ScriptArg02;
	//			//CommandScan Stage (limited to value of 255 to save little ram)
	//			unsigned __int8 CommandStage = 0;
	//			std::string LineString = "";
	//			size_t LineSize;
	//			char LineChar;
	//			bool InsideParenthesis = false;
	//			IniDataElement ElementData;
	//			for(size_t LineNumber = 0; TargetSettings.StreamLineData(); ++LineNumber)
	//			{
	//				LineString = TargetSettings.CurrentStreamedLineString();
	//				LineSize = LineString.length();
	//				for(size_t i = 0; i<LineSize; ++i)
	//				{
	//					LineChar = LineString.at(i);
	//					if(LineChar == '"') { InsideParenthesis = !InsideParenthesis; }
	//					else if(LineChar == '[')
	//					{
	//						ScriptArg01 = "";
	//						CommandStage = 1;
	//					}
	//					else if(CommandStage > 0)
	//					{
	//						if(InsideParenthesis==false&&(LineChar == '=' || LineChar == ':'))
	//						{
	//							CommandStage = 2;
	//						}
	//						else if(CommandStage == 2)
	//						{
	//							if(LineChar == ']')
	//							{
	//								//std::cout << "Executing Command:" << ScriptArg01 << " with parameter "<<ScriptArg02<<"\n";
	//								CommandStage = 0;
	//								ElementData.ScriptArg01 = ScriptArg01;
	//								ElementData.ScriptArg02 = ScriptArg02;
	//								Add(ElementData);
	//								ScriptArg02 = "";
	//								ScriptArg01 = "";
	//							}
	//							else
	//							{
	//								ScriptArg02 += LineChar;
	//							}
	//						}
	//						else
	//						{
	//							ScriptArg01 += LineChar;
	//						}
	//					}
	//				}
	//			}
	//		}
	//	bool CheckIfElementExists(std::string Value)
	//	{
	//		const size_t ListSize = Size();
	//		IniDataElement ElementData;
	//		bool ElementExists = false;
	//		for (size_t Index = 0; Index < ListSize && ElementExists == false; ++Index)
	//		{
	//			ElementData = ElementAt(Index);
	//			if (ElementData.ScriptArg01 == Value)
	//			{
	//				ElementExists = true;
	//			}
	//		}
	//		return ElementExists;
	//	}
	//	std::string GetElementData(std::string Value)
	//	{
	//		const size_t ListSize = Size();
	//		std::string ElementValue = "";
	//		IniDataElement ElementData;
	//		bool ElementExists = false;
	//		for (size_t Index = 0; Index < ListSize && ElementExists == false; ++Index)
	//		{
	//			ElementData = ElementAt(Index);
	//			if (ElementData.ScriptArg01 == Value)
	//			{
	//				ElementExists = true;
	//				ElementValue = ElementData.ScriptArg02;
	//			}
	//		}
	//		if (ElementExists == false)
	//		{
	//			std::cout << "Ini setting named " << Value << "not found.\n";
	//		}
	//		return ElementValue;
	//	}
	//	IniData();
	//	~IniData();
	//};
}
