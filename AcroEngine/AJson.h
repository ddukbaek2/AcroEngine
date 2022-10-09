#pragma once

#include "AcroEngine.h"
#include "AObject.h"
#include "AString.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ JSON ตฅภฬลอ.
	/////////////////////////////////////////////////////////////////////////////
	class Json : public Object
	{
	private:

	public:
		Json() {}
		virtual ~Json() {}

		AObject Deserialize(AString String);
		AString Serialize(AObject Object);
	};
}