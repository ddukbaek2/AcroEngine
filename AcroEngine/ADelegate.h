#pragma once

#include "AcroEngine.h"
#include "AList.h"
#include "AObject.h"

#define DELEGATE_INVOKE(...) AcroEngine::Delegate::Invoke(__VA_ARGS__)

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
		Delegate()
		{
		}

		virtual ~Delegate()
		{
		}

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

		static AObject Invoke(...)
		{
		
			//for (auto delegate : m_Delegates)
			{

			}
		}
	};
}