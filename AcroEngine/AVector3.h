#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ ������ ���� ����.
	/////////////////////////////////////////////////////////////////////////////
	class IVector3 : public IVariable
	{
	private:
		XPlatform::FLOAT64 m_Values[3];

	public:
	};
}