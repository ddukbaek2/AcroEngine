#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 기본 오브젝트 클래스.
	/////////////////////////////////////////////////////////////////////////////
	class AObject
	{
		DECLARE_GETCLASSNAME(AObject)

	private:
		XPlatform::INT32 m_ID;
		XPlatform::INT32 m_ReferenceCount;

	protected:

		AObject();
		virtual ~AObject();

	public:
		virtual AString ToString();

		static AObject* Instantiate(AType* Type);
		static void Destroy(AObject** Object);
		static void DestroyImmediate(AObject** Object);
		static bool IsDeadlyObject();
		static void IncreaseReference(const AObject* Object);
		static void DecreaseReference(AObject** Object);
		static AType* GetType();
	};

	DECLARE_POINTER(AObject)
}