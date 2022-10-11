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
		AType m_Type;

	public:
		Object();
		virtual ~Object();
		virtual AString ToString();
		virtual bool8 Equals(AObject Target);
		virtual unit64 GetObjectID();
		virtual AType GetType();

		friend AObject Instantiate(AType Type);
		friend void Destroy(AObject Target);
		friend void DestroyImmediate(AObject Target);
		friend bool8 IsDestroyed(AObject Target);
	};
}