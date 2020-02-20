/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#if !defined(VirtualType_IncludeGuard)
#define VirtualType_IncludeGuard

#include <string>
#include <typeindex>
#include <list>
#include <map>
//#include "VariableLists/VariableList.h"
//#include "IniData/CustomDictionary.h"

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
/// (Based on https://stackoverflow.com/questions/2562176/storing-a-type-in-c + https://arsenmk.blogspot.com/2012/10/storing-type-on-example-of-simple.html)
/// </summary>
class VirtualTypeRef
{
public:
	template <typename T>
	struct TypeRepresentation
	{
		typedef T type;
	};

	template <typename T>
	TypeRepresentation<T> get_type(const T&)
	{
		return TypeRepresentation<T>();
	}
	class IMessage
	{
	public:
		virtual std::string Get() const = 0;
		virtual void Set(const std::string&) = 0;
	};

	class IReceiver
	{
	public:
		virtual void Receive(const IMessage&) = 0;
	};
	class Messenger
	{
	private:
		// Prohibit explicit construction and copying
		// My compiler does not support 'delete' and 'default' keywords
		Messenger() {}
		Messenger(const Messenger&);
		Messenger& operator=(const Messenger&);

		std::map<std::type_index, std::list<IReceiver *>> typeToReceivers;
		std::list<IReceiver *> allReceivers;

	public:
		static Messenger& Get()
		{
			static Messenger messenger;

			return messenger;
		}

		template <class Sender>
		void RegisterForMessagesFromType(IReceiver *receiver)
		{
			std::map<std::type_index, std::list<IReceiver *>>::
				iterator seeker = this->typeToReceivers.find(
					std::type_index(typeid(Sender)));
			if (seeker != this->typeToReceivers.end())
			{
				seeker->second.push_back(receiver);
			}
			else
			{
				std::list<IReceiver *> newList;
				newList.push_back(receiver);
				typeToReceivers.insert(std::make_pair(
					std::type_index(typeid(Sender)), newList));
			}
		}

		void RegisterForMessages(IReceiver *receiver)
		{
			std::list<IReceiver *>::const_iterator
				seeker = std::find(this->allReceivers.begin(),
					this->allReceivers.end(), receiver);
			if (seeker == this->allReceivers.end())
			{
				this->allReceivers.push_back(receiver);
			}
		}

		template <class Sender>
		void UnregisterForMessagesFromType(IReceiver *receiver)
		{
			std::map<std::type_index, std::list<IReceiver *>>::
				iterator seeker = this->typeToReceivers.find(
					std::type_index(typeid(Sender)));
			if (seeker == this->typeToReceivers.end())
			{
				return;
			}
			std::list<IReceiver *>::iterator iter =
				std::find(seeker->second.begin(),
					seeker->second.end(), receiver);
			if (iter != seeker->second.end())
			{
				seeker->second.erase(iter);
			}
		}

		template <class Sender>
		void SendMessageFrom(const IMessage& msg, const Sender& from)
		{
			std::map<std::type_index, std::list<IReceiver *>>::
				const_iterator seeker = this->typeToReceivers.find(
					std::type_index(typeid(from)));
			if (seeker != this->typeToReceivers.end())
			{
				std::for_each(seeker->second.begin(),
					seeker->second.end(),
					[&msg](IReceiver *rcvr)
				{ rcvr->Receive(msg); });
			}
		}

		template <class Receiver>
		void SendMessagesTo(const IMessage& msg)
		{
			std::for_each(allReceivers.begin(), allReceivers.end(),
				[&msg](IReceiver *rcvr)
			{ if (typeid(*rcvr) == typeid(Receiver))
			{
				rcvr->Receive(msg);
			} });
		}
	};
	VirtualType* StoredType = nullptr;
	template<typename T> VirtualTypeRef(T ObjOfType)
	{
		VirtualType* StoredType = new VirtualTypeImpl<int>;
	}
	~VirtualTypeRef()
	{
		if (StoredType != nullptr) { delete StoredType; }
	}
	template <typename ConvertedType>
	void* ConvertRef()
	{
		if (StoredType == nullptr)
		{
			return nullptr;
		}
		else
		{
			StoredType = new VirtualTypeImpl<ConvertedType>;
			return StoredType->allocate();
		}
	}
};

#endif
