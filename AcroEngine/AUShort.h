#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 실수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class UShort : public Variable
	{
	private:
		uint16 m_Value;

	public:
		UShort() : Variable(), m_Value(0)
		{
		}

		virtual ~UShort()
		{
		}

		void operator = (uint16& Value)
		{
			m_Value = Value;
		}

		operator uint16& ()
		{
			return m_Value;
		}
	};
}