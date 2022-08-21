#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 전방선언.
	/////////////////////////////////////////////////////////////////////////////
	class AObject;


	/////////////////////////////////////////////////////////////////////////////
	// @ 포인터.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T = AObject> class APtr
	{
	private:
		T* m_Target;

	public:
		APtr()
		{
			m_Target = nullptr;
		}

		APtr()
		{
			m_Target = nullptr;
		}

		APtr(T* target)
		{
			m_Target = nullptr;
			Set(target);
		}

		APtr(APtr<T> target)
		{
			m_Target = nullptr;
			Set(target);
		}

		virtual ~APtr()
		{
			Set(nullptr);
		}

		void Set(const T* target)
		{
			if (m_Target != nullptr)
			{
				m_Target->DecreaseReference();
				m_Target = nullptr;
			}

			if (target != nullptr)
			{
				m_Target = target;
				m_Target->IncreaseReference();
			}
		}

		const T* GetPtr()
		{
			return m_Target;
		}

		const T& GetRef()
		{
			return *m_Target;
		}

		void operator = (T* target)
		{
			Set(target);
		}

		T* operator -> (APtr<T> self)
		{
			return self.Get();
		}
	};
}