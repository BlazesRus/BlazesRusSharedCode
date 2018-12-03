#include "MultiviewPrecompile.h"
#include "XMLTagView.h"

void XMLTagView::LoadDataFromFile(std::string FilePath)
{
	bool InsideXMLComment = false;
	std::string TagBuffer = "";
	std::string ContentBuffer = "";
}

XMLTagView::XMLTagView(std::string FilePath) : CustomTreeView<XMLTagViewNode>()
{
	LoadDataFromFile(FilePath);
}


XMLTagView::XMLTagView() : CustomTreeView<XMLTagViewNode>()
{
	LoadDataFromFile("I:/UserFiles/Sample.xml");
}