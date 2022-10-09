#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 기본 오브젝트 클래스.
	/////////////////////////////////////////////////////////////////////////////
	class Object
	{
	private:
		INT32 m_ObjectID;
		BOOL8 m_IsDestroying;

	public:
		Object();
		virtual ~Object();
		virtual AString ToString();
		virtual BOOL8 Equals(AObject Object);
		virtual INT32 GetObjectID();

		friend AObject Instantiate(AType Type);
		friend VOID Destroy(AObject Object);
		friend VOID DestroyImmediate(AObject Object);
		friend BOOL8 IsDestroyed(AObject Object);
	};
}