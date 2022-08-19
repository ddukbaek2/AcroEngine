#pragma once

#include "AcroEngine.h"

namespace AcroEngine
{
	////////////////////////////////////////////////////////////////////////
	// @ 클래스 전방선언.
	////////////////////////////////////////////////////////////////////////
	class AInt;
	class AString;
	class AObjectManagedSystem;


	////////////////////////////////////////////////////////////////////////
	// @ 클래스 정보.
	////////////////////////////////////////////////////////////////////////
	class AClass
	{
	private:
		
	public:
		AClass(const wchar_t* className)
		{

		}

		virtual ~AClass()
		{
		}

		inline bool IsParent(AClass* Class)
		{
			return false;
		}

		inline bool IsChildren(AClass* Class)
		{
			return false;
		}
	};


	////////////////////////////////////////////////////////////////////////
	// @ 기본 오브젝트 클래스.
	////////////////////////////////////////////////////////////////////////
	class AObject
	{
	private:
		XPlatform::sint32 m_ID;
		XPlatform::sint32 m_ReferenceCount;

	private:
		void IncreaseReference()
		{
			++m_ReferenceCount;
		}

		void DecreaseReference()
		{
			--m_ReferenceCount;
			if (m_ReferenceCount <= 0)
			{
				delete this;
			}
		}
	public:
		AObject()
		{
		}

		virtual ~AObject()
		{
		}

		virtual AString ToString();


		static AObject* CreateObject(AClass* Class);

		static void DestroyObject(AObject* Object);

		static AClass* GetClass();

		friend class AObjectManagedSystem;
		friend class APtr;
	};
}