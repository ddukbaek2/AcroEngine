#pragma once

#include "AcroEngine.h"
#include "AObject.h"


namespace AcroEngine
{
	class AObjectManagedSystem
	{
	private:

	public:
		static void Manage(AObject& Object)
		{
			Object.m_ID = 1;
			Object.m_ReferenceCount = 1;

			//if (Object.Valid())
			//	Object->Initialize();
		}
	};
}