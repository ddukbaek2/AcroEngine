#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 실수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IDouble : public IVariable
	{
	private:
		FLOAT64 m_Value;

	public:
		VOID operator = (FLOAT64& Value)
		{
			m_Value = Value;
		}

		operator FLOAT64& ()
		{
			return m_Value;
		}
	};
}