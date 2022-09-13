#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 논리형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IBoolean : public IVariable
	{
		GENERATE_TYPE(IBoolean)

	private:
		XPlatform::BOOL m_Value;

	public:
		IBoolean() : IVariable(), m_Value(false)
		{
		}

		virtual ~IBoolean()
		{
		}

		void operator = (XPlatform::BOOL& Value)
		{
			m_Value = Value;
		}

		operator XPlatform::BOOL& ()
		{
			return m_Value;
		}
	};
}