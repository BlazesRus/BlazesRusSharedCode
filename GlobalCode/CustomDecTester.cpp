// CustomDecTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ExperimentalCode/VirtualType.h"
#include "VariableLists/VariableList.h"

class BasicNode
{
	/// <summary>
	/// Globally stored under BasicNode::TreeType (for sending information about type of ParentTree)
	/// </summary>
	static VirtualTypeRef TreeType;
	void AddToTree()
	{

	}
	template <typename VariableType>
	static void RecieveTypeInfo(VariableType TreeInfo)//(dynamic TreeObject)
	{
		//TreeType
	}
};

class BasicNodeTree:VariableList<BasicNode>
{
	void SendTypeInfoToNode()
	{

	}
};

int main()
{
    std::cout << "Hello World!\n";
}
