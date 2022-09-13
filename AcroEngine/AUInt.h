#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 정수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IUInt : public IVariable
	{
		GENERATE_TYPE(IUInt)

	private:
		XPlatform::UINT32 m_Value;

	public:
		IUInt() : IVariable(), m_Value(0)
		{
		}

		virtual ~IUInt()
		{
		}

		void operator = (XPlatform::UINT32& Value)
		{
			m_Value = Value;
		}

		operator XPlatform::UINT32& ()
		{
			return m_Value;
		}
	};
}