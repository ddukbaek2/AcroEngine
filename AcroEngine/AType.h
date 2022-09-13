#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 클래스 정보.
	/////////////////////////////////////////////////////////////////////////////
	class IType
	{
	private:
	public:
		IType(const XPlatform::CHAR16 ClassName[]) {}
		virtual ~IType() {}

		virtual bool IsParent(AType Class) { return false; }
		virtual bool IsChildren(AType Class) { return false; }
		virtual AString GetTypeName() { return nullptr; }
		virtual ADictionary GetVariables() { return nullptr; }
		virtual ADictionary GetMethods() { return nullptr; }

		static AType GetType(const XPlatform::CHAR16 ClassName[]);
	};
}