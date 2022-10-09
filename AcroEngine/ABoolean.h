#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 논리형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class Boolean : public Variable
	{
	private:
		BOOL8 m_Value;

	public:
		Boolean() : Variable()
		{
			m_Value = false;
		}

		virtual ~Boolean()
		{

		}

		VOID operator = (BOOL8 Value)
		{
			m_Value = Value;
		}

		operator BOOL8 ()
		{
			return m_Value;
		}
	};
}