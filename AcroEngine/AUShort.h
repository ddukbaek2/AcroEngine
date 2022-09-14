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
		GENERATE_TYPE(IUShort)

	private:
		XPlatform::UINT16 m_Value;

	public:
		IUShort() : IVariable(), m_Value(0)
		{
		}

		virtual ~IUShort()
		{
		}

		XPlatform::VOID operator = (XPlatform::UINT16& Value)
		{
			m_Value = Value;
		}

		operator XPlatform::UINT16& ()
		{
			return m_Value;
		}
	};
}