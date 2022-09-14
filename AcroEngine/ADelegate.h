#pragma once

#include "AcroEngine.h"
#include "AList.h"
#include "AObject.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 함수대리자.
	/////////////////////////////////////////////////////////////////////////////
	class IDelegate : public IObject
	{
	private:
		AList m_Delegates;

	public:
		//static ADelegate* CreateDelegate()
		//{
		//	return nullptr;
		//}

		XPlatform::VOID Add(ADelegate Delegate)
		{
		}

		XPlatform::VOID Remove(ADelegate Delegate)
		{
		}

		XPlatform::VOID Reset()
		{
			//m_Delegates.
		}

		//AObject* Invoke(...)
		//{
		//	//for (auto delegate : m_Delegates)
		//	{

		//	}
		//}
	};
}