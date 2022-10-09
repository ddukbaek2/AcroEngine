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
	template<typename TSource = Object> class ARef
	{
	private:
		std::weak_ptr<TSource> m_WeakPtr;

	public:
		ARef()
		{
			m_WeakPtr = std::weak_ptr<TSource>();
		}

		ARef(std::shared_ptr<TSource> Object)
		{
			m_WeakPtr = std::weak_ptr<TSource>(Object);
		}

		virtual ~ARef()
		{
		}

		TSource* operator ->()
		{
			return Get();
		}

		TSource* operator *()
		{
			return Get();
		}

		std::shared_ptr<Object> GetSharedPointer()
		{
			if (IsNull(*this))
				return std::shared_ptr<Object>();

			return m_WeakPtr.lock();
		}

		TSource* Get()
		{
			if (IsNull(*this))
				return nullptr;

			auto object = m_WeakPtr.lock();
			return (TSource*)object.get();
		}

		static BOOL8 IsNull(ARef<TSource> Object)
		{
			if (Object.m_WeakPtr.expired())
				return true;

			return false;
		}

		static ARef<TSource> Null()
		{
			return ARef<TSource>();
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 레퍼런스 전방선언 목록.
	/////////////////////////////////////////////////////////////////////////////
	typedef POINTER AUnknownObject;
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
	VOID UnloadType(AType Type);
	AType GetType(const CHAR16 ClassName[]);
	AObject Instantiate(AType Type);
	VOID Destroy(AObject Object);
	VOID DestroyImmediate(AObject Object);
	BOOL8 IsDestroyed(AObject Object);
	AString Format(const CHAR16 Format[], AList Arguments);

	template<typename TSource = Object, typename TDest = Object>
	ARef<TDest> Cast(ARef<TSource> Object)
	{
		if (ARef<TSource>::IsNull(Object))
			return ARef<TDest>();

		auto object = Object.GetSharedPointer();
		return ARef<TDest>(std::dynamic_pointer_cast<TDest>(object));
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션.
	/////////////////////////////////////////////////////////////////////////////
	class Application : public AcroCore::IApplication
	{
	protected:
		virtual VOID OnCreate() override;
		virtual VOID OnDestroy() override;
		virtual VOID OnPause() override;
		virtual VOID OnResume() override;
		virtual VOID OnUpdate(FLOAT32 DeltaTime) override;
		virtual VOID OnDraw(AcroCore::XGL GL) override;
		virtual VOID OnResize(UINT32 Width, UINT32 Height) override;
	};
}