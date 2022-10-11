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

		virtual void Add(TRef Object) = 0;
		virtual void Remove(TRef Object) = 0;
		virtual void Clear() = 0;

		virtual bool8 Contains(TRef Object) = 0;
		virtual void CopyTo(TRef Array, Int Index) = 0;
	};
}