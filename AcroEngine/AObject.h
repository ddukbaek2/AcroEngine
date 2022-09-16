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

		static XPlatform::VOID IncreaseReference(AObject Object);
		static XPlatform::VOID DecreaseReference(AObject Object);

		friend static AObject Instantiate(AType Type);
		friend static XPlatform::VOID Destroy(AObject Object);
		friend static XPlatform::VOID DestroyImmediate(AObject Object);
		friend static XPlatform::BOOL8 IsDestroyed(AObject Object);
	};
}