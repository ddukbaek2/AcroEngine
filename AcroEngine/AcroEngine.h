#pragma once

#define XPLATFORM_WINDOWS
#include "../XPlatform/XPlatform.h"
#include "../XPlatform/TAllocator.h"


#define AINHERIT(Class) public Class
#define GENERATE_BASE(ThisClass, ParentClass)\
typedef ParentClass Base;\
typedef ThisClass This;

#define GENERATE_TYPE(Class) public: inline AcroEngine::AType GetType() { return AcroEngine::IType::GetType(L#Class); }
//#define DECLARE_GETCLASSNAME(Class) public: static const wchar_t* GetTypeName(){ return L#Class; }

#define CREATE_OBJECT(Class)
#define DESTROY_OBJECT(Object) if (Object != nullptr) { AObject::Destroy(Object); Object = nullptr; }


namespace AcroEngine
{
	/*
		특징: 템플릿없음. 초단순구조. 초경량. 완벽한매니지드. C++을 C# 레벨로 변화. 멀티플랫폼지원. 실시간타입정보지원. 모든오브젝트 시리얼라이즈 가능.
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
	typedef IObject* AObject;
	typedef IType* AType;
	typedef IOwner* AOwner;
	typedef IJson* AJson;
	typedef IProperty* AProperty;
	typedef IDelegate* ADelegate;
	typedef IVariable* AVariable;
	typedef IBoolean* ABoolean;
	typedef IShort* AShort;
	typedef IUShort* AUShort;
	typedef IInt* AInt;
	typedef IUInt* AUInt;
	typedef IFloat* AFloat;
	typedef IDouble* ADouble;
	typedef IString* AString;
	typedef IVector2* AVector2;
	typedef IVector3* AVector3;
	typedef IVector4* AVector4;
	typedef IArray* AArray;
	typedef IList* AList;
	typedef IQueue* AQueue;
	typedef IStack* AStack;
	typedef ISet* ASet;
	typedef IDictionary* ADictionary;
	
	//class AFlag;
	//class AEnum;
	//class ACollection;


	/////////////////////////////////////////////////////////////////////////////
	// @ 함수 목록.
	/////////////////////////////////////////////////////////////////////////////
	static AObject Instantiate(AType Type);
	static XPlatform::VOID Destroy(AObject Object);
	static XPlatform::VOID DestroyImmediate(AObject Object);
	static XPlatform::BOOL8 IsDestroyed(AObject Object);
	static AString Format(const XPlatform::CHAR16 Format[], AArray Arguments);
}