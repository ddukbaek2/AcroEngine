﻿#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 메모리할당자.
	/////////////////////////////////////////////////////////////////////////////
	class AAllocator
	{
	private:
		AUnknownObject* m_Pointer;
		XPlatform::sint32 m_Size;

	public:
		void Resize(XPlatform::sint32 size);
		XPlatform::sint32 GetSize();
	};
}