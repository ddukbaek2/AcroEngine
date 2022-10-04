#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 기본 오브젝트 클래스.
	/////////////////////////////////////////////////////////////////////////////
	class IObject
	{
	private:
		AcroCore::INT32 m_Identifier;
		AcroCore::INT32 m_ReferenceCount;
		AcroCore::BOOL8 m_IsDestroyed;

	public:
		IObject();
		virtual ~IObject();
		virtual AString ToString();
		virtual AcroCore::BOOL8 Equals(AObject Object);
		virtual AcroCore::INT32 GetHashCode();

		friend AObject Instantiate(AType Type);
		friend AcroCore::VOID Destroy(AObject Object);
		friend AcroCore::VOID DestroyImmediate(AObject Object);
		friend AcroCore::BOOL8 IsDestroyed(AObject Object);
		friend AcroCore::VOID IncreaseReference(AObject Object);
		friend AcroCore::VOID DecreaseReference(AObject Object);
	};
}