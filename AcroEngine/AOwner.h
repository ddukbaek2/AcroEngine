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

		AcroCore::VOID SetOwner(AObject target);
		AcroCore::VOID UnsetOwner();
		AObject GetObject();
		AcroCore::VOID operator = (AObject target);
		AObject operator -> ();
		AcroCore::BOOL8 IsValid();
	};
}