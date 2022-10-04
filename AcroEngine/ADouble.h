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
		AcroCore::FLOAT64 m_Value;

	public:
		AcroCore::VOID operator = (AcroCore::FLOAT64& Value)
		{
			m_Value = Value;
		}

		operator AcroCore::FLOAT64& ()
		{
			return m_Value;
		}
	};
}