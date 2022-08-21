#include "AAllocator.h"

void AcroEngine::AAllocator::Resize(XPlatform::sint32 size)
{
	// 추가.
	if (m_Size < size)
	{
	}
	// 감소.
	else if (m_Size > size)
	{
	}
}

XPlatform::sint32 AcroEngine::AAllocator::GetSize()
{
	return m_Size;
}
