#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	class AObject;


	/////////////////////////////////////////////////////////////////////////////
	// @ 소유권자.
	/////////////////////////////////////////////////////////////////////////////
	class AOwner
	{
	private:
		AObject* m_Target;

	public:
		AOwner();
		AOwner(AObject* target);
		AOwner(const AOwner* Owner);
		virtual ~AOwner();
		void SetOwner(const AObject* target);
		void UnsetOwner();
		const AObject* GetPtr();
		const AObject& GetRef();
		void operator = (AObject* target);
	};
}