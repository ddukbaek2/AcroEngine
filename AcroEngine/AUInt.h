#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 정수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class UInt : public Variable
	{
	private:
		uint32 m_Value;

	public:
		UInt() : Variable(), m_Value(0)
		{
		}

		virtual ~UInt()
		{
		}

		void operator = (uint32& Value)
		{
			m_Value = Value;
		}

		operator uint32& ()
		{
			return m_Value;
		}

		uint32 ToUInt()
		{
			return m_Value;
		}
	};
}