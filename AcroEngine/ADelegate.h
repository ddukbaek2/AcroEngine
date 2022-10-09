#pragma once

#include "AcroEngine.h"
#include "AList.h"
#include "AObject.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 함수대리자.
	/////////////////////////////////////////////////////////////////////////////
	class Delegate : public Object
	{
	private:
		List m_Delegates;

	public:
		//static Delegate* CreateDelegate()
		//{
		//	return nullptr;
		//}

		VOID Add(Delegate Delegate)
		{
		}

		VOID Remove(Delegate Delegate)
		{
		}

		VOID Clear()
		{
			//m_Delegates.
		}

		//ARef* Invoke(...)
		//{
		//	//for (auto delegate : m_Delegates)
		//	{

		//	}
		//}
	};
}