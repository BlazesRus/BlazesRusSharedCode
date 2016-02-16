#include "XMLTagTree.h"

int main(unsigned int ConsoleParamNumber, char *CommandArgs [])
{
	if(ConsoleParamNumber==2)
	{
		const std::string FileName(CommandArgs[1]);
		TagTreeData::TagTree XMLNodeTree;
		XMLNodeTree.LoadDataFromXML(FileName);
		XMLNodeTree.OutputInternalNamesTreeToFile("InternalNameTest.txt");
		XMLNodeTree.DetectTagContentTypesWithinV2();
		XMLNodeTree.AddMenuItemData("(Core)", "", "DeleteMeTest", "TestDestroyNode");
		XMLNodeTree.AddMenuItemData("(LastItem)", "AddSubItem", "ChildNodeTest");
		XMLNodeTree.AddMenuItemData("(LastItem)", "AddSubItem", "ChildNodeTest02");
		XMLNodeTree.AddMenuItemData("(LastItem)", "AddSubItem", "ChildNodeTest03");
		XMLNodeTree.DestroyNodeAndAllItsChildren("TestDestroyNode");
		XMLNodeTree.GenerateHTMLDoc(FileName, true);
	}
}