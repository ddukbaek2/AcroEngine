#pragma once

#include "AcroEngine.h"
#include "AVariable.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 정수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class Int : public Variable
	{
	private:
		int32 m_Value;

	public:
		Int() : Variable(), m_Value(0)
		{
		}

		virtual ~Int()
		{
		}

		void operator = (int32& Value)
		{
			m_Value = Value;
		}

		operator int32& ()
		{
			return m_Value;
		}

		int32 ToInt()
		{
			return m_Value;
		}
	};
}