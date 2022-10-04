#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 논리형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IBoolean : public IVariable
	{
	private:
		BOOL8 m_Value;

	public:
		IBoolean() : IVariable()
		{
			m_Value = false;
		}

		virtual ~IBoolean()
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