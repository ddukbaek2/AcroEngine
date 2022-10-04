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
		INT32 m_Identifier;
		INT32 m_ReferenceCount;
		BOOL8 m_IsDestroyed;

	public:
		IObject();
		virtual ~IObject();
		virtual AString ToString();
		virtual BOOL8 Equals(AObject Object);
		virtual INT32 GetHashCode();

		friend AObject Instantiate(AType Type);
		friend VOID Destroy(AObject Object);
		friend VOID DestroyImmediate(AObject Object);
		friend BOOL8 IsDestroyed(AObject Object);
		friend VOID IncreaseReference(AObject Object);
		friend VOID DecreaseReference(AObject Object);
	};
}