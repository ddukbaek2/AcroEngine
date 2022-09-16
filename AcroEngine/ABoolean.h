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
		XPlatform::BOOL8 m_Value;

	public:
		IBoolean() : IVariable(), m_Value(false)
		{
		}

		virtual ~IBoolean()
		{
		}

		XPlatform::VOID operator = (const XPlatform::BOOL8& Value)
		{
			m_Value = Value;
		}

		operator XPlatform::BOOL8& ()
		{
			return m_Value;
		}
	};
}