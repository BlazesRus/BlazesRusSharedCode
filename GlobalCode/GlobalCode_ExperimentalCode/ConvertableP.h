/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#if !defined(ConvertableP_IncludeGuard)
#define ConvertableP_IncludeGuard

template <typename NodeType>
class ConvertableP
{
	NodeType* self;
public:
	NodeType* operator->()
	{
		return &self;
	}
	template <typename ConvertedType>
	ConvertedType* ConvertRef()
	{//https://www.quora.com/Why-can-the-derived-class-pointer-not-point-to-a-base-class-pointer
		if(self==nullptr)
		{
			return nullptr;
		}
		else
		{
			return dynamic_cast<ConvertedType*>(self);
		}
	}
};

#endif