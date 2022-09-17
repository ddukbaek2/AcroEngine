#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ ¹Ýº¹ÀÚ.
	/////////////////////////////////////////////////////////////////////////////
	class IEnumerator
	{
	public:
		virtual XPlatform::VOID Clear() = 0;
		virtual XPlatform::BOOL8 MoveNext() = 0;
		virtual AObject GetCurrent() = 0;
	};
}