#include "AType.h"


namespace AcroEngine
{
	IType::IType()
	{
		m_Name = A_INSTANTIATE(AString);
		m_Variables = A_INSTANTIATE(ADictionary);
		m_Methods = A_INSTANTIATE(ADictionary);
	}

	IType::~IType()
	{
		A_DESTROYIMMEDIATE(m_Name);
		A_DESTROYIMMEDIATE(m_Variables);
		A_DESTROYIMMEDIATE(m_Methods);
	}

	BOOL8 IType::IsParent(AType Class)
	{
		return false;
	}

	BOOL8 IType::IsChildren(AType Class)
	{
		return false;
	}

	AString IType::GetName()
	{
		return m_Name;
	}

	ADictionary IType::GetVariables()
	{
		return m_Variables;
	}

	ADictionary IType::GetMethods()
	{
		return m_Methods;
	}
}