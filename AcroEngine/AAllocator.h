#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 메모리할당자.
	/////////////////////////////////////////////////////////////////////////////
	class AAllocator
	{
	private:
		AUnknownObject m_Pointer;
		XPlatform::INT32 m_Size;

	public:
		void Resize(XPlatform::INT32 size);
		XPlatform::INT32 GetSize();
	};
}