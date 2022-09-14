#pragma once

#include "AcroEngine.h"
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

		//void Add()
		//{
		//}

		//void Remove()
		//{
		//}

		//void Clear()
		//{
		//}

		//AObject* Invoke(...)
		//{
		//	//for (auto delegate : m_Delegates)
		//	{

		//	}
		//}
	};
}