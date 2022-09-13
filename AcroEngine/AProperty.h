#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 프로퍼티.
	/////////////////////////////////////////////////////////////////////////////
	class IProperty
	{
	private:
		ADelegate m_Get;
		ADelegate m_Set;

	public:
		IProperty() {}
		virtual ~IProperty() {}

		void operator += (ADelegate Delegate)
		{
			//m_Get.Add
		}
	};
}