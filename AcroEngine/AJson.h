#pragma once

#include "AcroEngine.h"
#include "AObject.h"
#include "AString.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ JSON ตฅภฬลอ.
	/////////////////////////////////////////////////////////////////////////////
	class IJson : public IObject
	{
	private:

	public:
		IJson() {}
		virtual ~IJson() {}

		AObject Deserialize(AString String);
		AString Serialize(AObject IObject);
	};
}