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

		VOID SetOwner(AObject target);
		VOID UnsetOwner();
		AObject GetObject();
		VOID operator = (AObject target);
		AObject operator -> ();
		BOOL8 IsValid();
	};
}