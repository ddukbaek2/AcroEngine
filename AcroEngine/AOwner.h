#pragma once

#include "AcroEngine.h"
#include "AObject.h"

namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 소유권자.
	/////////////////////////////////////////////////////////////////////////////
	class IOwner
	{
	private:
		AObject m_Target;

	public:
		IOwner();
		IOwner(AObject target);
		IOwner(AOwner Owner);
		virtual ~IOwner();
		void SetOwner(AObject target);
		void UnsetOwner();
		AObject GetObject();
		void operator = (AObject target);
	};
}