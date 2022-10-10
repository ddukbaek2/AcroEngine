#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 실수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class Short : public Variable
	{
	private:
		int16 m_Value;

	public:
		Short() : Variable(), m_Value(0)
		{
		}

		virtual ~Short()
		{
		}

		void operator = (int16& Value)
		{
			m_Value = Value;
		}

		operator int16& ()
		{
			return m_Value;
		}
	};
}