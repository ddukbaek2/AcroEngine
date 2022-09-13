#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 실수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IFloat : public IVariable
	{
	private:
		XPlatform::FLOAT32 m_Value;

	public:
		void operator = (XPlatform::FLOAT32& Value)
		{
			m_Value = Value;
		}

		operator XPlatform::FLOAT32& ()
		{
			return m_Value;
		}
	};
}