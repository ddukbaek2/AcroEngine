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
		void* m_Pointer;
		XPlatform::sint32 m_Size;

	public:
		void Resize(XPlatform::sint32 size);
		template<typename T> T* GetPointer() { return (T*)m_Pointer; }
		XPlatform::sint32 GetSize();
	};
}