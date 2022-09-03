#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 프로퍼티.
	/////////////////////////////////////////////////////////////////////////////
	class AProperty : public AObject
	{
	private:
		ADelegate m_Get;
		ADelegate m_Set;

	public:
		AProperty() {}
		virtual ~AProperty() {}

		void operator += (ADelegate Delegate)
		{
			//m_Get.Add
		}
	};
}