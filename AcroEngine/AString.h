#pragma once

#include "AcroEngine.h"
#include "AVariable.h"
#include "AInt.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 문자열형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class String : public Variable
	{
	private:
		std::wstring m_Data;

	public:
		String()
		{
			m_Data.clear();
		}

		String(CHAR16* Value)
		{
			m_Data += Value;
		}

		virtual ~String()
		{
			m_Data.clear();
		}
	};
}