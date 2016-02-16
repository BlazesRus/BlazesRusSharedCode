// DLLTest.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DLLTest.h"


// This is an example of an exported variable
DLLTEST_API int nDLLTest=0;

// This is an example of an exported function.
DLLTEST_API int fnDLLTest(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see DLLTest.h for the class definition
CDLLTest::CDLLTest()
{
	return;
}
