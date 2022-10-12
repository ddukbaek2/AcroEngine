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
		AList m_Delegates;

	public:
		void Add(Delegate Delegate)
		{
		}

		void Remove(Delegate Delegate)
		{
		}

		void Clear()
		{
			m_Delegates->Clear();
		}

		//TRef* Invoke(...)
		//{
		//	//for (auto delegate : m_Delegates)
		//	{

		//	}
		//}
	};
}