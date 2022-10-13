#pragma once

#include "AcroEngine.h"
#include "AString.h"
#include "ADictionary.h"

namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 변수 정보.
	/////////////////////////////////////////////////////////////////////////////
	class FieldInfo : public Object
	{
	protected:
		std::wstring m_Name;

	public:
		void SetValue(AObject Object, int32 Value)
		{
		}

		int32 Get(AObject Object)
		{
			return 0;
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 함수 정보.
	/////////////////////////////////////////////////////////////////////////////
	class MethodInfo : public Object
	{
	protected:
		std::wstring m_Name;

	public:
		void Invoke(TRef<Object> Object)
		{
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 클래스 정보.
	/////////////////////////////////////////////////////////////////////////////
	class Type : public Object
	{
	protected:
		std::wstring m_Name;
		std::vector<FieldInfo> m_Fields;
		std::vector<MethodInfo> m_Methods;
		std::set<std::wstring> m_Parents;
		std::set<std::wstring> m_Children;

	public:
		Type() {}
		Type(const std::wstring& name) { m_Name = name; }
		virtual ~Type() {}
		virtual bool8 IsParent(AType Type) { return m_Parents.find(Type->GetName()) != m_Parents.end(); }
		virtual bool8 IsChildren(AType Type) { return m_Children.find(Type->GetName()) != m_Children.end(); }
		virtual pointer CreateInstance() { return nullptr; }

		const std::wstring& GetName() { return m_Name; }
		const std::vector<FieldInfo>& GetFields() { return m_Fields; }
		const std::vector<MethodInfo>& GetMethods() { return m_Methods; }			

		friend AType GetType(const char16 ClassName[]);
	};
}