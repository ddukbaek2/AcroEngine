#pragma once

#include "AcroEngine.h"
#include "AType.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 기본 오브젝트 클래스.
	/////////////////////////////////////////////////////////////////////////////
	class IObject
	{
		GENERATE_TYPE(IObject)

	private:
		XPlatform::INT32 m_ID;
		XPlatform::INT32 m_ReferenceCount;
		XPlatform::BOOL m_IsDestroyed;

	public:
		IObject();
		virtual ~IObject();
		virtual AString ToString();

		static void IncreaseReference(AObject Object);
		static void DecreaseReference(AObject Object);
		static AObject Instantiate(AType Type);
		static void Destroy(AObject Object);
		static void DestroyImmediate(AObject Object);
		//static bool IsDeadlyObject();
		//static AType* GetType();
	};
}