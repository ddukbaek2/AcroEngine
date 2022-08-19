#pragma once

#include "AcroEngine.h"

class AObject;


template<typename T = AObject> class APtr
{
private:
	T* m_Target;
public:
	APtr()
	{
		m_Target = nullptr;
	}

	APtr(T* target)
	{
		m_Target = nullptr;
		Set(target);
	}

	virtual ~APtr()
	{
		Set(nullptr);
	}

	void Set(T* target)
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

	void operator = (T* target)
	{
		Set(target);
	}
};