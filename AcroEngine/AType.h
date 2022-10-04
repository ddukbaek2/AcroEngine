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

		virtual BOOL8 IsParent(AType Class);
		virtual BOOL8 IsChildren(AType Class);
		virtual AString GetName();
		virtual ADictionary GetVariables();
		virtual ADictionary GetMethods();

		friend AType GetType(const CHAR16 ClassName[]);
	};
}