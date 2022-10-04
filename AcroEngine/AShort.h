#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 실수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IShort : public IVariable
	{
	private:
		AcroCore::INT16 m_Value;

	public:
		IShort() : IVariable(), m_Value(0)
		{
		}

		virtual ~IShort()
		{
		}

		AcroCore::VOID operator = (AcroCore::INT16& Value)
		{
			m_Value = Value;
		}

		operator AcroCore::INT16& ()
		{
			return m_Value;
		}
	};
}