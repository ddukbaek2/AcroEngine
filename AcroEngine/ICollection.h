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

		virtual VOID Add(AObject Object) = 0;
		virtual VOID Remove(AObject Object) = 0;
		virtual VOID Clear() = 0;

		virtual BOOL8 Contains(AObject Object) = 0;
		virtual VOID CopyTo(AObject Array, AInt Index) = 0;
	};
}