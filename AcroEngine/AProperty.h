#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 프로퍼티.
	/////////////////////////////////////////////////////////////////////////////
	class Property : public Object
	{
	private:
		ADelegate m_Get;
		ADelegate m_Set;

	public:
		Property() {}
		virtual ~Property() {}

		VOID operator += (ADelegate Delegate)
		{
			//m_Get.Add
		}
	};
}