#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 실수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IUShort : public IVariable
	{
	private:
		UINT16 m_Value;

	public:
		IUShort() : IVariable(), m_Value(0)
		{
		}

		virtual ~IUShort()
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