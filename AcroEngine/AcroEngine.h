#pragma once

#define XPLATFORM_WINDOWS
#include "../XPlatform/XPlatform.h"


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

	static void LoadAssembly();
	static void UnloadAssembly();
}