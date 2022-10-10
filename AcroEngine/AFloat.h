#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 실수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class Float : public Variable
	{
	private:
		float32 m_Value;

	public:
		void operator = (float32& Value)
		{
			m_Value = Value;
		}

		operator float32& ()
		{
			return m_Value;
		}
	};
}