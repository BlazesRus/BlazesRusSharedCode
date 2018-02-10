/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#ifndef CustomDecTemplates_IncludeGuard
#define CustomDecTemplates_IncludeGuard
#include "CustomDec.h"

template <typename IntType = signed __int32, typename DecType = unsigned __int32>
class DLL_API CustomDec_Template
{
};

#ifdef CustomDec_sInt32_9Dec
class DLL_API SuperDec_sInt32_9Dec : public CustomDec
#else
class DLL_API SuperDec_sInt32_9Dec
#endif
{};

#ifdef CustomDec_AngleDec
class DLL_API AngleDec : public CustomDec
#else
class DLL_API AngleDec
#endif
{};
#endif