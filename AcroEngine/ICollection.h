#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 기본 자료구조.
	/////////////////////////////////////////////////////////////////////////////
	class ICollection
	{
	public:
		virtual int GetCount() = 0;

		virtual VOID Add(ARef Object) = 0;
		virtual VOID Remove(ARef Object) = 0;
		virtual VOID Clear() = 0;

		virtual BOOL8 Contains(ARef Object) = 0;
		virtual VOID CopyTo(ARef Array, Int Index) = 0;
	};
}