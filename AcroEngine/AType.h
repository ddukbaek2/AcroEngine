#pragma once

#include "AcroEngine.h"
#include "AString.h"
#include "ADictionary.h"

namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 클래스 정보.
	/////////////////////////////////////////////////////////////////////////////
	class IType
	{
	private:
		AString	m_Name;
		ADictionary m_Variables;
		ADictionary m_Methods;

	public:
		IType();
		virtual ~IType();

		virtual XPlatform::BOOL8 IsParent(AType Class);
		virtual XPlatform::BOOL8 IsChildren(AType Class);
		virtual AString GetName();
		virtual ADictionary GetVariables();
		virtual ADictionary GetMethods();

		friend AType GetType(const XPlatform::CHAR16 ClassName[]);
	};
}