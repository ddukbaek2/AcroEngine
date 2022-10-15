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

		virtual void Add(AObject Object) = 0;
		virtual void Remove(AObject Object) = 0;
		virtual void Clear() = 0;

		virtual bool8 Contains(AObject Object) = 0;
		virtual void CopyTo(AObject Array, Int Index) = 0;
	};
}