#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 정적배열 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IArray : public IVariable
	{
	private:
		BOOL8 m_Value;

	public:
		IArray() : IVariable()
		{
			m_Value = false;
		}

		virtual ~IArray()
		{
		}

		VOID operator = (BOOL8& Value)
		{
			m_Value = Value;
		}

		operator BOOL8& ()
		{
			return m_Value;
		}
	};
}