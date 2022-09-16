#pragma once

#define XPLATFORM_WINDOWS
#include "../XPlatform/XPlatform.h"
#include "../XPlatform/TAllocator.h"


//namespace AcroEngine
//{
	#define A_INSTANTIATE(Class) Instantiate(A_TYPEOF(Class))
	#define A_TYPEOF(Class) GetType(L#Class)
	#define A_DESTROY(Object) if (Object != nullptr) { Destroy(Object); Object = nullptr; }
	/*
		템플릿없음.
		초단순구조.
		초경량.
		모든객체 매니지드.
		C++을 C# 레벨로 변화.
		멀티플랫폼지원.
		실시간타입정보지원.
		모든오브젝트 시리얼라이즈 가능.
	*/

	//class AAudio {};
	//class AVideo {};
	//class AAppication {};
	//class AFile {};
	//class ANetwork {};
	//class AInput {};
	//class AUI {};
	//class AData {};
	//class ASerializer {};

	//template<typename T = class AObject> class Json
	//{
	//public:
	//	static AString Serialize(const T* object) {}
	//	static T Deserialize(const AString& string) {}
	//};

	//class AScript {};


	/////////////////////////////////////////////////////////////////////////////
	// @ 클래스 전방선언 목록.
	/////////////////////////////////////////////////////////////////////////////
	//class IObject;
	//class IType;
	//class IOwner;
	//class IJson;
	//class IProperty;
	//class IDelegate;
	//class IVariable;
	//class IBoolean;
	//class IShort;
	//class IUShort;
	//class IInt;
	//class IUInt;
	//class IFloat;
	//class IDouble;
	//class IString;
	//class IVector2;
	//class IVector3;
	//class IVector4;
	//class IArray;
	//class IList;
	//class IQueue;
	//class IStack;
	//class ISet;
	//class IDictionary;


	/////////////////////////////////////////////////////////////////////////////
	// @ 클래스포인터 전방선언 목록.
	/////////////////////////////////////////////////////////////////////////////
	typedef XPlatform::VOID* AUnknownObject;
	typedef class IObject* AObject;
	typedef class IType* AType;
	typedef class IOwner* AOwner;
	typedef class IJson* AJson;
	typedef class IProperty* AProperty;
	typedef class IDelegate* ADelegate;
	typedef class IVariable* AVariable;
	typedef class IBoolean* ABoolean;
	typedef class IShort* AShort;
	typedef class IUShort* AUShort;
	typedef class IInt* AInt;
	typedef class IUInt* AUInt;
	typedef class IFloat* AFloat;
	typedef class IDouble* ADouble;
	typedef class IString* AString;
	typedef class IVector2* AVector2;
	typedef class IVector3* AVector3;
	typedef class IVector4* AVector4;
	typedef class IArray* AArray;
	typedef class IList* AList;
	typedef class IQueue* AQueue;
	typedef class IStack* AStack;
	typedef class ISet* ASet;
	typedef class IDictionary* ADictionary;
	
	//class AFlag;
	//class AEnum;
	//class ACollection;


	/////////////////////////////////////////////////////////////////////////////
	// @ 함수 목록.
	/////////////////////////////////////////////////////////////////////////////
	AType GetType(const XPlatform::CHAR16 ClassName[]);
	AObject Instantiate(AType Type);
	XPlatform::VOID Destroy(AObject Object);
	XPlatform::VOID DestroyImmediate(AObject Object);
	XPlatform::BOOL8 IsDestroyed(AObject Object);
	AString Format(const XPlatform::CHAR16 Format[], AArray Arguments);
//}