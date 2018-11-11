#if !defined(VirtualType_IncludeGuard)
#define VirtualType_IncludeGuard

//#include <typeinfo>

//class VirtualType
//{
//	static std::type_info TypeInfo;
//};
class VirtualType
{
public:
	virtual ~VirtualType() {}
	virtual void* allocate()const = 0;
	virtual void* cast(void* obj)const = 0;
};

template<typename T> class VirtualTypeImpl : public VirtualType
{
public:
	virtual void* allocate()const { return new T; }
	virtual void* cast(void* obj)const { return static_cast<T*>(obj); }
};

/// <summary>
/// https://stackoverflow.com/questions/2562176/storing-a-type-in-c
/// </summary>
class VirtualTypeRef
{
	VirtualType* StoredType = nullptr;
	template<typename T> VirtualTypeRef(T ObjOfType)
	{
		VirtualType* StoredType = new VirtualTypeImpl<int>;
	}
	~VirtualTypeRef()
	{
		if (StoredType != nullptr) { delete StoredType; }
	}
	//VirtualType* StoredType = new VirtualTypeImpl<int>;
	//void* myint = type->allocate();
};

#endif
