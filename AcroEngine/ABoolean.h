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
		bool8 m_Value;

	public:
		Boolean() : Variable()
		{
			m_Value = false;
		}

		virtual ~Boolean()
		{

		}

		void operator = (bool8 Value)
		{
			m_Value = Value;
		}

		operator bool8 ()
		{
			return m_Value;
		}
	};
}