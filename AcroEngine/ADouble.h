#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 실수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IDouble : public IVariable
	{
	private:
		XPlatform::FLOAT64 m_Value;

	public:
		void operator = (XPlatform::FLOAT64& Value)
		{
			m_Value = Value;
		}

		operator XPlatform::FLOAT64& ()
		{
			return m_Value;
		}
	};
}