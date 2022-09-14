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

		static AObject Deserialize(AString String);
		static AString Serialize(AObject IObject);
	};
}