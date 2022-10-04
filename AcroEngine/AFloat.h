#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 실수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IFloat : public IVariable
	{
	private:
		AcroCore::FLOAT32 m_Value;

	public:
		AcroCore::VOID operator = (AcroCore::FLOAT32& Value)
		{
			m_Value = Value;
		}

		operator AcroCore::FLOAT32& ()
		{
			return m_Value;
		}
	};
}