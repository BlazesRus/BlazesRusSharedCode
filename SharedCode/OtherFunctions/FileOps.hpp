#pragma once
#ifndef FileOps_IncludeGuard
#define FileOps_IncludeGuard

#ifdef BlazesSharedCode_LocalLayout
    #ifndef DLL_API
        #ifdef UsingBlazesSharedCodeDLL
            #define DLL_API __declspec(dllimport)
        #elif defined(BLAZESSharedCode_LIBRARY)
            #define DLL_API __declspec(dllexport)
        #else
            #define DLL_API
        #endif
    #endif
#else
    #include "..\DLLAPI.h"
#endif

//#include <vector>
//#include <list>
#include <string>
#include <iostream>
//#include <sstream>//std::ostringstream definition
#include <fstream>
//#include <typeinfo>
//#include <memory>
//#include <io.h>
//#include "StringFunctions.h"

namespace BlazesRusCode
{
    class DLL_API FileOps
    {
public:
		bool CreateFileIfDoesntExist(std::string fileName)
		{
			bool FileExists = false;
			//Based on https://www.quora.com/What-is-the-best-way-to-check-whether-a-particular-file-exists-or-not-in-C++
			struct stat buffer;
			FileExists = (stat(fileName.c_str(), &buffer) == 0);
			//Based on http://stackoverflow.com/questions/17818099/how-to-check-if-a-file-exists-before-creating-a-new-file
			if (!FileExists)
			{
				std::ofstream file(fileName);
				if (!file)
				{
					std::cout << "File could not be created" << std::endl;
					return;
				}
			}
			return FileExists;
		}
	}
}
#endif