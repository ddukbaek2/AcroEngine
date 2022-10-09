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
		UINT16 m_Value;

	public:
		UShort() : Variable(), m_Value(0)
		{
		}

		virtual ~UShort()
		{
		}

		VOID operator = (UINT16& Value)
		{
			m_Value = Value;
		}

		operator UINT16& ()
		{
			return m_Value;
		}
	};
}