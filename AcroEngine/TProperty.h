#pragma once


namespace AcroEngine
{
	#define DECLARE_PROPERTY(Type)\
	class Property_##Type : public TProperty<Type>\
	{\
	};\

	#define DECLARE_PROPERTY_SET(Type, SetFunc)\
	class Property_##Type : public TProperty<Type>\
	{\
		virtual void Set(const Type& Value) override SetFunc;\
	};\

	#define DECLARE_PROPERTY_GET(Type, SetFunc)\
	class Property_##Type : public TProperty<Type>\
	{\
		virtual Type& Get() override GetFunc;\
	};\

	#define DECLARE_PROPERTY_SETGET(Type, SetFunc, GetFunc)\
	class Property_##Type : public TProperty<Type>\
	{\
		virtual void Set(const Type& Value) override SetFunc;\
		virtual Type& Get() override GetFunc;\
	};\

	
	/////////////////////////////////////////////////////////////////////////////
	// @ 프로퍼티.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T> class TProperty
	{
	protected:
		T m_Value;

	public:
		TProperty()
		{
			m_Value = T();
		}

		virtual ~TProperty()
		{
		}

		//operator T()
		//{
		//	return m_Value;
		//}

		//void operator = (T Value)
		//{
		//	Set(Value);
		//}

		//T& operator = (const T& Value)
		//{
		//	Set(Value);
		//	return m_Value;
		//}

		virtual void Set(const T& Value)
		{
			m_Value = Value;
		}

		virtual T& Get()
		{
			return m_Value;
		}
	};
}