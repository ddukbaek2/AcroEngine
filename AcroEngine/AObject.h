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
		unit64 m_ObjectID;
		bool8 m_IsDestroying;

	public:
		Object();
		virtual ~Object();
		virtual AString ToString();
		virtual bool8 Equals(AObject Object);
		virtual unit64 GetObjectID();

		friend AObject Instantiate(AType Type);
		friend void Destroy(AObject Object);
		friend void DestroyImmediate(AObject Object);
		friend bool8 IsDestroyed(AObject Object);
	};
}