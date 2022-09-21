#pragma once

#include "../XPlatform/XPlatform.h"
#include "../XPlatform/XAllocator.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 디파인 매크로 목록.
	/////////////////////////////////////////////////////////////////////////////
	#define A_TYPEOF(Class) AcroEngine::GetType(L#Class)
	#define A_INSTANTIATE(Class) (Class)AcroEngine::Instantiate(A_TYPEOF(Class))
	#define A_DESTROY(Object) if (Object != nullptr) { AcroEngine::Destroy(Object); Object = nullptr; }
	#define A_DESTROYIMMEDIATE(Object) if (Object != nullptr) { AcroEngine::DestroyImmediate(Object); Object = nullptr; }


	/////////////////////////////////////////////////////////////////////////////
	// @ 클래스 전방선언 목록.
	/////////////////////////////////////////////////////////////////////////////
	class IObject;
	class IType;
	class IOwner;
	class IJson;
	class IProperty;
	class IDelegate;
	class IVariable;
	class IBoolean;
	class IShort;
	class IUShort;
	class IInt;
	class IUInt;
	class IFloat;
	class IDouble;
	class IString;
	class IVector2;
	class IVector3;
	class IVector4;
	class IArray;
	class IList;
	class IQueue;
	class IStack;
	class ISet;
	class IDictionary;


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
	//class AAction


	/////////////////////////////////////////////////////////////////////////////
	// @ 함수 목록.
	/////////////////////////////////////////////////////////////////////////////
	XPlatform::VOID LoadType(AType Type);
	XPlatform::VOID UnloadType(AType Type);
	XPlatform::VOID IncreaseReference(AObject Object);
	XPlatform::VOID DecreaseReference(AObject Object);
	AType GetType(const XPlatform::CHAR16 ClassName[]);
	AObject Instantiate(AType Type);
	XPlatform::VOID Destroy(AObject Object);
	XPlatform::VOID DestroyImmediate(AObject Object);
	XPlatform::BOOL8 IsDestroyed(AObject Object);
	AString Format(const XPlatform::CHAR16 Format[], AArray Arguments);
}