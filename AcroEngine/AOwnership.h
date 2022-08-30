#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 소유권자.
	/////////////////////////////////////////////////////////////////////////////
	class AOwner
	{
	private:
		AObject* m_Target;

	public:
		AOwner()
		{
			m_Target = nullptr;
		}

		AOwner()
		{
			m_Target = nullptr;
		}

		AOwner(AObject* target)
		{
			m_Target = nullptr;
			SetOwner(target);
		}

		AOwner(const AOwner* Owner)
		{
			m_Target = nullptr;
			SetOwner(Owner->m_Target);
		}

		virtual ~AOwner()
		{
			SetOwner(nullptr);
		}

		void SetOwner(const AObject* target)
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

		const AObject* GetPtr()
		{
			return m_Target;
		}

		const AObject& GetRef()
		{
			return *m_Target;
		}

		void operator = (AObject* target)
		{
			SetOwner(target);
		}
	};
}