/*============================================================================*/
// Helper macros for declaring CRuntimeClass compatible classes with Template arguments added
//(based off https://stackoverflow.com/questions/1491971/mfc-implement-dyncreate-with-template)
#pragma once
#define MFC_BeginMessageMapInHeader_With1BaseArg(class_name, baseClass, baseArgOne)\
	/// <summary>\
	/// Gets the this message map.\
	/// </summary>\
	/// <returns>const AFX_MSGMAP*</returns>\
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
	{\
		typedef class_name ThisClass;\
		typedef baseClass<baseArgOne> TheBaseClass;\
		__pragma(warning(push))\
		__pragma(warning(disable: 4640))\
		static const AFX_MSGMAP_ENTRY _messageEntries[] =\
		{\
			{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }\
		};\
		__pragma(warning(pop))\
		static const AFX_MSGMAP messageMap =\
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };\
		return &messageMap;\
	}\
public:\
	/// <summary>\
	/// Gets the message map.\
	/// </summary>\
	/// <returns>const AFX_MSGMAP *</returns>\
	virtual const AFX_MSGMAP* GetMessageMap() const\
	{\
		return GetThisMessageMap();\
	}
	
#define MFC_AltMessageMapInHeader_With1ArgAnd1BaseArg(class_name, ArgOne, baseClass, baseArgOne)\
	/// <summary>\
	/// Gets the this message map.\
	/// </summary>\
	/// <returns>const AFX_MSGMAP*</returns>\
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()\
	{\
		typedef class_name<ArgOne> ThisClass;\
		typedef baseClass<baseArgOne> TheBaseClass;\
		__pragma(warning(push))\
		__pragma(warning(disable: 4640))\
		static const AFX_MSGMAP_ENTRY _messageEntries[] =\
		{

#define MFC_EndMessageMapInHeader()\
			{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }\
		}; \
		__pragma(warning(pop))\
				static const AFX_MSGMAP messageMap = \
			{ &TheBaseClass::GetThisMessageMap, & _messageEntries[0] }; \
				return &messageMap; \
	}\
public:\
				/// <summary>\
				/// Gets the message map.\
				/// </summary>\
				/// <returns>const AFX_MSGMAP *</returns>\
				virtual const AFX_MSGMAP* GetMessageMap() const\
				{\
					return GetThisMessageMap();\
				}


#define MFC_BeginMessageMapInSource_With1Arg(theClass, ArgOne, baseClass) \
	PTM_WARNING_DISABLE \
	const AFX_MSGMAP* theClass::GetMessageMap() const \
		{ return GetThisMessageMap(); } \
	const AFX_MSGMAP* PASCAL theClass::GetThisMessageMap() \
	{ \
		typedef theClass<ArgOne> ThisClass;						   \
		typedef baseClass TheBaseClass;					   \
		__pragma(warning(push))							   \
		__pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */ \
		static const AFX_MSGMAP_ENTRY _messageEntries[] =  \
		{

//#define END_MESSAGE_MAP() \
//		{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
//	}; \
//		__pragma(warning(pop))	\
//		static const AFX_MSGMAP messageMap = \
//		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] }; \
//		return &messageMap; \
//	}								  \
//	PTM_WARNING_RESTORE