#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 전방선언.
	/////////////////////////////////////////////////////////////////////////////
	class AType;
	//class AInt;
	class AString;


	/////////////////////////////////////////////////////////////////////////////
	// @ 기본 오브젝트 클래스.
	/////////////////////////////////////////////////////////////////////////////
	class AObject
	{
		GENERATE_TYPE(AObject)

	private:
		XPlatform::INT32 m_ID;
		XPlatform::INT32 m_ReferenceCount;
		XPlatform::BOOL m_IsDestroyed;

	public:
		AObject();
		virtual ~AObject();
		virtual AString ToString();

		static void IncreaseReference(AObject* Object);
		static void DecreaseReference(AObject* Object);
		static AObject* Instantiate(AType* Type);
		static void Destroy(AObject* Object);
		static void DestroyImmediate(AObject* Object);
		//static bool IsDeadlyObject();
		//static AType* GetType();
	};

	DECLARE_POINTER(AObject)
}