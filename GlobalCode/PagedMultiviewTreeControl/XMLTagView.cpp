#include "MultiviewPrecompile.h"
#include "XMLTagView.h"

XMLTagView::XMLTagView(std::string FilePath) : CustomTreeView<XMLTagViewNode>()
{
	bool InsideXMLComment = false;
	std::string TagBuffer = "";
	std::string ContentBuffer = "";
}
