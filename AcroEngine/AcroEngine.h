#pragma once

#include "../AcroCore/AcroCore.h"


/////////////////////////////////////////////////////////////////////////////
// @ 디파인 매크로 목록.
/////////////////////////////////////////////////////////////////////////////
#define A_TYPEOF(Class) AcroEngine::GetType(L#Class)
#define A_INSTANTIATE(Class) AcroEngine::Cast<AcroEngine::Object, Class>(AcroEngine::Instantiate(A_TYPEOF(Class)))
#define A_DESTROY(Object) if (Object != nullptr) { AcroEngine::Destroy(Object); Object = nullptr; }
#define A_DESTROYIMMEDIATE(Object) if (Object != nullptr) { AcroEngine::DestroyImmediate(Object); Object = nullptr; }


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 클래스 전방선언 목록.
	/////////////////////////////////////////////////////////////////////////////
	class Type;
	class FieldInfo;
	class MethodInfo;
	class Object;
	class Json;
	class Property;
	class Delegate;
	class Variable;
	class Boolean;
	class Short;
	class UShort;
	class Int;
	class UInt;
	class Float;
	class Double;
	class String;
	class Vector2;
	class Vector3;
	class Vector4;
	class List;
	class Queue;
	class Stack;
	class Set;
	class Dictionary;


	/////////////////////////////////////////////////////////////////////////////
	// @ 참조 오브젝트.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T = Object> class ARef
	{
	private:
		std::weak_ptr<T> m_WeakPtr;

	public:
		ARef()
		{
			m_WeakPtr = std::weak_ptr<T>();
		}

		ARef(std::shared_ptr<T> Object)
		{
			m_WeakPtr = std::weak_ptr<T>(Object);
		}

		virtual ~ARef()
		{
		}

		T* operator ->()
		{
			return Get();
		}

		T* operator *()
		{
			return Get();
		}

		std::shared_ptr<Object> GetSharedPointer()
		{
			if (IsNull(*this))
				return std::shared_ptr<Object>();

			return m_WeakPtr.lock();
		}

		T* Get()
		{
			if (IsNull(*this))
				return nullptr;

			auto object = m_WeakPtr.lock();
			return (T*)object.get();
		}

		bool8 IsNull()
		{
			if (m_WeakPtr.expired())
				return true;

			return false;
		}

		template<typename TDest = Object> TDest* Get()
		{
			if (ARef<T>::IsNull(*this))
				return nullptr;

			auto object = Get();
			return (TDest*)object;
		}

		template<typename TDest = Object> ARef<TDest> Cast()
		{
			if (ARef<T>::IsNull(*this))
				return ARef<TDest>();

			auto object = GetSharedPointer();
			return ARef<TDest>(std::dynamic_pointer_cast<TDest>(object));
		}

		static bool8 IsNull(ARef<T> Object)
		{
			return Object.IsNull();
		}

		static ARef<T> Null()
		{
			return ARef<T>();
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 레퍼런스 전방선언 목록.
	/////////////////////////////////////////////////////////////////////////////
	typedef pointer AUnknownObject;
	typedef class ARef<FieldInfo> AFieldInfo;
	typedef class ARef<MethodInfo> AMethodInfo;
	typedef class ARef<Type> AType;
	typedef class ARef<Object> AObject;
	typedef class ARef<Json> AJson;
	typedef class ARef<Property> AProperty;
	typedef class ARef<Delegate> ADelegate;
	typedef class ARef<Variable> AVariable;
	typedef class ARef<Boolean> ABoolean;
	typedef class ARef<Short> AShort;
	typedef class ARef<UShort> AUShort;
	typedef class ARef<Int> AInt;
	typedef class ARef<UInt> AUInt;
	typedef class ARef<Float> AFloat;
	typedef class ARef<Double> ADouble;
	typedef class ARef<String> AString;
	typedef class ARef<Vector2> AVector2;
	typedef class ARef<Vector3> AVector3;
	typedef class ARef<Vector4> AVector4;
	typedef class ARef<List> AList;
	typedef class ARef<Queue> AQueue;
	typedef class ARef<Stack> AStack;
	typedef class ARef<Set> ASet;
	typedef class ARef<Dictionary> ADictionary;
	
	//class AFlag;
	//class AEnum;
	//class ACollection;
	//class AAction


	/////////////////////////////////////////////////////////////////////////////
	// @ 함수 목록.
	/////////////////////////////////////////////////////////////////////////////
	AType LoadType(Type* Type);
	void UnloadType(AType Type);
	AType GetType(const char16 TypeName[]);

	AObject Instantiate(AType Type);
	AObject Instantiate(const char16 TypeName[]);

	void Destroy(AObject Object);
	void DestroyImmediate(AObject Object);

	bool8 IsDestroyed(AObject Object);
	AString Format(const char16 Format[], AList Arguments);

	template<typename T = Object, typename TDest = Object>
	ARef<TDest> Cast(ARef<T> Object)
	{
		return Object.Cast<TDest>();
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션.
	/////////////////////////////////////////////////////////////////////////////
	class Application : public AcroCore::IApplication
	{
	protected:
		virtual void OnCreate() override;
		virtual void OnDestroy() override;
		virtual void OnPause() override;
		virtual void OnResume() override;
		virtual void OnUpdate(float32 DeltaTime) override;
		virtual void OnDraw(AcroCore::XGL GL) override;
		virtual void OnResize(uint32 Width, uint32 Height) override;
	};
}