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
			UnsetOwner();

			if (target != nullptr)
			{
				m_Target = const_cast<AObject*>(target);
				AObject::IncreaseReference(m_Target);
			}
		}

		void UnsetOwner()
		{
			if (m_Target != nullptr)
			{
				AObject::DecreaseReference(&m_Target);
				m_Target = nullptr;
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