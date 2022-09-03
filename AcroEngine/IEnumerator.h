#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 전방선언.
	/////////////////////////////////////////////////////////////////////////////
	class AObject;


	/////////////////////////////////////////////////////////////////////////////
	// @ 반복자.
	/////////////////////////////////////////////////////////////////////////////
	class IEnumerator
	{
	public:
		virtual void Reset() = 0;
		virtual bool MoveNext() = 0;
		virtual AObject* GetCurrent() = 0;
	};

	DECLARE_POINTER(IEnumerator)
}