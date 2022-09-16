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
	private:
		XPlatform::INT32 m_ID;
		XPlatform::INT32 m_ReferenceCount;
		XPlatform::BOOL8 m_IsDestroyed;

	public:
		IObject();
		virtual ~IObject();
		virtual AString ToString();
		virtual XPlatform::BOOL8 Equals(AObject Object);
		virtual XPlatform::INT32 GetHashCode();

		friend XPlatform::VOID IncreaseReference(AObject Object);
		friend XPlatform::VOID DecreaseReference(AObject Object);

		friend AObject Instantiate(AType Type);
		friend XPlatform::VOID Destroy(AObject Object);
		friend XPlatform::VOID DestroyImmediate(AObject Object);
		friend XPlatform::BOOL8 IsDestroyed(AObject Object);
	};
}