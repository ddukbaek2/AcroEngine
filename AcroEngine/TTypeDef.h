#pragma once


#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 타입 정의.
	//	- Object를 상속받은 모든 클래스가 대상이 된다.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T = Object> class TTypeDef : public Type
	{
	public:
		TTypeDef() : Type(AcroCore::GetTypeName<T>())
		{
			// m_Fields
			// m_Methods
			// m_Parents
			// m_Children
		}

		virtual pointer CreateInstance() override { return new T(); }
	};
}