#pragma once

#include "AcroEngine.h"
#include "AVariable.h"
#include "AInt.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 문자열형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IString : public IVariable
	{
	private:
		XPlatform::XAllocator<XPlatform::CHAR16> m_Value;

	public:
		IString()
		{
			m_Value.Clear();
		}

		IString(XPlatform::CHAR16* Value)
		{
			m_Value.Clear();
			m_Value.Resize(sizeof(Value));
			for (XPlatform::INT32 i = 0; i < m_Value.GetSize(); ++i)
			{
				m_Value.SetValue(i, Value[i]);
			}
		}

		virtual ~IString()
		{
			m_Value.Clear();
		}
	};
}