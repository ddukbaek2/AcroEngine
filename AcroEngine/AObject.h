#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 전방선언.
	/////////////////////////////////////////////////////////////////////////////
	class AInt;
	class AString;
	class AObjectManagedSystem;


	/////////////////////////////////////////////////////////////////////////////
	// @ 기본 오브젝트 클래스.
	/////////////////////////////////////////////////////////////////////////////
	class AObject
	{
	private:
		XPlatform::sint32 m_ID;
		XPlatform::sint32 m_ReferenceCount;

	protected:
		static void IncreaseReference(const AObject* Object);
		static void DecreaseReference(AObject** Object);

		AObject();
		virtual ~AObject();

	public:
		virtual AString ToString();

		static AObject* CreateObject(AType* Type);
		static void Destroy(AObject** Object);
		static void DestroyImmediate(AObject** Object);
		static bool IsDeadlyObject();

		static AType* GetType();
	};
}