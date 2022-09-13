#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 전방선언.
	/////////////////////////////////////////////////////////////////////////////
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
		const AObject* GetPointer();
		const AObject& GetReference();

		template<typename T = AObject> const T* GetPointerT()
		{
			return (T*)m_Target;
		}

		void operator = (AObject* target);

	};
}