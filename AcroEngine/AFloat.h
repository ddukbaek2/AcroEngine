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
		FLOAT32 m_Value;

	public:
		VOID operator = (FLOAT32& Value)
		{
			m_Value = Value;
		}

		operator FLOAT32& ()
		{
			return m_Value;
		}
	};
}