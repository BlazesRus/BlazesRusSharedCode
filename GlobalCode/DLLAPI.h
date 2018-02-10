//This file ensures that DLL_API is defined

#ifndef DLLAPI_IncludeGuard
#define DLLAPI_IncludeGuard

//#ifdef DLLAPI_EXPORTS
//#define DLL_API __declspec(dllexport)
//#else
//#define DLL_API __declspec(dllimport)
//#endif

//Some parts(define is renamed and some parts are changed/missing) based on https://github.com/arx/ArxLibertatis/blob/master/src/lib/ArxIO.h
/*
 * Copyright 2013 Arx Libertatis Team (see the AUTHORS file)
 *
 * This file is part of Arx Libertatis.
 *
 * Arx Libertatis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arx Libertatis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Arx Libertatis.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifdef __LIB
// Building static library
#define DLL_API
#else
#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define DLL_API __attribute__ ((dllexport))
#else

#ifdef DLLAPI_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#endif
#else
#if __GNUC__ >= 4
#define DLL_API __attribute__ ((visibility ("default")))
#endif
#endif

#endif
#endif
//#ifdef __cplusplus
//extern "C" 
//{
//#endif
//
//#ifdef __cplusplus
//}
//#endif