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

		XPlatform::VOID SetOwner(AObject target);
		XPlatform::VOID UnsetOwner();
		AObject GetObject();
		XPlatform::VOID operator = (AObject target);
		AObject operator -> ();
		XPlatform::BOOL8 IsValid();
	};
}