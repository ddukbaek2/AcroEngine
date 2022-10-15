#pragma once

#include "AcroEngine.h"
#include "AObject.h"
#include "AString.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ JSON °´Ã¼.
	/////////////////////////////////////////////////////////////////////////////
	class Json : public Object
	{
	public:
		enum class EType
		{
			Text,
			Number,
			Real,
			Boolean,
			Array,
			Object,
		};

	private:
		AObject m_Value;
		EType m_Type;

	public:
		Json() {}
		virtual ~Json() {}

		static AObject Deserialize(AString String);
		static AString Serialize(AObject Object);
	};
}