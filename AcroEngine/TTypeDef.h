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
			// m_Fields // 변수목록.
			// m_Methods // 함수목록.
			// m_Parents // 부모객체목록.
			// m_Children // 자식객체목록.
		}

		virtual pointer CreateInstance() override { return new T(); }
	};
}