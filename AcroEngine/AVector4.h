#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 사차원 벡터 변수.
	/////////////////////////////////////////////////////////////////////////////
	class IVector4 : public IVariable
	{
	private:
		XPlatform::FLOAT64 m_Values[4];

	public:
	};
}