#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 클래스 정보.
	/////////////////////////////////////////////////////////////////////////////
	class AJson : public AObject
	{
	private:

	public:
		AJson() {}
		virtual ~AJson() {}

		static AObject* Deserialize(AString* String);
		static AString Serialize(AObject* Object);
	};
}