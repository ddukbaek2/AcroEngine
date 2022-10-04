#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 정수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IInt : public IVariable
	{
	private:
		INT32 m_Value;

	public:
		IInt() : IVariable(), m_Value(0)
		{
		}

		virtual ~IInt()
		{
		}

		VOID operator = (INT32& Value)
		{
			m_Value = Value;
		}

		operator INT32& ()
		{
			return m_Value;
		}

		INT32 ToInt()
		{
			return m_Value;
		}
	};
}