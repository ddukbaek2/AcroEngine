#pragma once


#include "../AcroCore/AcroCore.h"
#include "TAction.h"
#include "TRef.h"


/////////////////////////////////////////////////////////////////////////////
// @ 디파인 매크로 목록.
/////////////////////////////////////////////////////////////////////////////
#define A_TYPEOF(Class) AcroEngine::GetType(L##Class)
#define A_INSTANTIATE(Class) AcroEngine::Cast<AcroEngine::Object, Class>(AcroEngine::Instantiate(AcroEngine::GetType(L#Class)))
#define A_DESTROY(Object) if (!Object.IsNull()) { AcroEngine::Destroy(Object.Cast<AcroEngine::Object>()); Object.Empty(); }
#define A_DESTROYIMMEDIATE(Object) if (!Object.IsNull()) { AcroEngine::DestroyImmediate(Object.Cast<AcroEngine::Object>()); Object.Empty(); }


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
	// @ 레퍼런스 전방선언 목록.
	/////////////////////////////////////////////////////////////////////////////
	typedef pointer AUnknownObject;
	typedef class TRef<FieldInfo> AFieldInfo;
	typedef class TRef<MethodInfo> AMethodInfo;
	typedef class TRef<Type> AType;
	typedef class TRef<Object> AObject;
	typedef class TRef<Json> AJson;
	typedef class TRef<Property> AProperty;
	typedef class TRef<Delegate> ADelegate;
	typedef class TRef<Variable> AVariable;
	typedef class TRef<Boolean> ABoolean;
	typedef class TRef<Short> AShort;
	typedef class TRef<UShort> AUShort;
	typedef class TRef<Int> AInt;
	typedef class TRef<UInt> AUInt;
	typedef class TRef<Float> AFloat;
	typedef class TRef<Double> ADouble;
	typedef class TRef<String> AString;
	typedef class TRef<Vector2> AVector2;
	typedef class TRef<Vector3> AVector3;
	typedef class TRef<Vector4> AVector4;
	typedef class TRef<List> AList;
	typedef class TRef<Queue> AQueue;
	typedef class TRef<Stack> AStack;
	typedef class TRef<Set> ASet;
	typedef class TRef<Dictionary> ADictionary;
	
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

	void Destroy(AObject Target);
	void DestroyImmediate(AObject Target);

	bool8 IsDestroyed(AObject Target);
	AString Format(const char16 Format[], AList Arguments);


	template<typename T = Object>
	TRef<T> Instantiate(AType Type)
	{
		auto object = Instantiate(Type);
		if (object.IsNull())
			return TRef<T>::Null();

		return object.Cast<T>();
	}

	template<typename T = Object>
	TRef<T> Instantiate(const char16 TypeName[])
	{
		return Instantiate<T>(GetType(TypeName));
	}

	class GC
	{
	public:
	};


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

		virtual void OnKeyPress(EKeyCode KeyCode) override;
		virtual void OnKeyRelease(EKeyCode KeyCode) override;
		virtual void OnTouchPress(uint8 Finger, float32 X, float32 Y) override;
		virtual void OnTouchDrag(uint8 Finger, float32 X, float32 Y, float32 DeltaMoveX, float32 DeltaMoveY) override;
		virtual void OnTouchRelease(uint8 Finger, float32 X, float32 Y) override;
	};
}