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
    public class IniDataElement
    {
        public string ScriptArg01;
        public string ScriptArg02;
        public IniDataElement(){}
        public IniDataElement(string Arg01, string Arg02)
        {
            ScriptArg01 = Arg01;
            ScriptArg02 = Arg02;
        }
    }

    public class IniData : List<IniDataElement>
    {
        byte IniType = 0;
        ////************************************
        //// Method:    LoadIniData
        //// FullName:  IniData::LoadIniData
        //// Access:    public 
        //// Returns:   void
        //// Qualifier:
        //// Parameter: std::string FileName
        ////************************************
        //void LoadIniData(string FileName)
        //{
        //    VariableList<string> TargetSettings;
        //    TargetSettings.LoadFileDataV2(FileName);
        //    //First part of command;Syntax:[ScriptArg01=ScriptArg02]
        //    string ScriptArg01 = "";
        //    //Command Value;Syntax:[ScriptArg01=ScriptArg02]
        //    string ScriptArg02 = "";
        //    //CommandScan Stage (limited to value of 255 to save little ram)
        //    byte CommandStage = 0;
        //    string LineString = "";
        //    int LineSize;
        //    char LineChar;
        //    bool InsideParenthesis = false;
        //    IniDataElement ElementData = new IniDataElement();
        //    for (int LineNumber = 0; TargetSettings.StreamLineData(); ++LineNumber)
        //    {
        //        LineString = TargetSettings.CurrentStreamedLineString();
        //        LineSize = LineString.Length;
        //        for (int i = 0; i < LineSize; ++i)
        //        {
        //            LineChar = LineString[i];
        //            if (LineChar == '"') { InsideParenthesis = !InsideParenthesis; }
        //            else if (LineChar == '[')
        //            {
        //                ScriptArg01 = "";
        //                CommandStage = 1;
        //            }
        //            else if (CommandStage > 0)
        //            {
        //                if (InsideParenthesis == false && (LineChar == '=' || LineChar == ':'))
        //                {
        //                    CommandStage = 2;
        //                }
        //                else if (CommandStage == 2)
        //                {
        //                    if (LineChar == ']')
        //                    {
        //                        //std::cout << "Executing Command:" << ScriptArg01 << " with parameter "<<ScriptArg02<<"\n";
        //                        CommandStage = 0;
        //                        ElementData = new IniDataElement(ScriptArg01, ScriptArg02);
        //                        Add(ElementData);
        //                        ScriptArg02 = "";
        //                        ScriptArg01 = "";
        //                    }
        //                    else
        //                    {
        //                        ScriptArg02 += LineChar;
        //                    }
        //                }
        //                else
        //                {
        //                    ScriptArg01 += LineChar;
        //                }
        //            }
        //        }
        //    }
        //}

        //bool CheckIfElementExists(string Value)
        //{
        //    int ListSize = this.Count;
        //    IniDataElement ElementData;
        //    bool ElementExists = false;
        //    for (int Index = 0; Index < ListSize && ElementExists == false; ++Index)
        //    {
        //        ElementData = ElementAt(Index);
        //        if (ElementData.ScriptArg01 == Value)
        //        {
        //            ElementExists = true;
        //        }
        //    }
        //    return ElementExists;
        //}
        //string GetElementData(string Value)
        //{
        //    int ListSize = this.Count;
        //    string ElementValue = "";
        //    IniDataElement ElementData;
        //    bool ElementExists = false;
        //    for (int Index = 0; Index < ListSize && ElementExists == false; ++Index)
        //    {
        //        ElementData = ElementAt(Index);
        //        if (ElementData.ScriptArg01 == Value)
        //        {
        //            ElementExists = true;
        //            ElementValue = ElementData.ScriptArg02;
        //        }
        //    }
        //    if (ElementExists == false)
        //    {
        //        Console.WriteLine("Ini setting named " + Value + "not found.\n");
        //    }
        //    return ElementValue;
        //}
        public IniData() {}
    }
    //class IniData : public VariableList<IniDataElement>
    //{
    //	unsigned __int8 IniType = 0;


    //};
}
