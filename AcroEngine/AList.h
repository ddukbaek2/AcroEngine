#pragma once

#include "AcroEngine.h"
#include "AInt.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 색인배열 형.
	/////////////////////////////////////////////////////////////////////////////
	class IList : public IVariable
	{
		GENERATE_BASE(IList, IVariable)
		GENERATE_TYPE(IList)

	private:
		XPlatform::TAllocator<AObject> m_Allocator;
		XPlatform::INT32 m_Count;

	public:
		IList() : Base()
		{
			m_Allocator.Clear();
			m_Count = 0;
		}

		IList(AInt Capacity) : This()
		{
			m_Allocator.Resize(Capacity->ToInt());
		}

		void Add(AObject Object)
		{
			auto size = m_Allocator.GetSize();
			if (size == 0)
			{
				m_Allocator.Resize(2);
			}
			else if (m_Count + 1 >= size)
			{
				size = size * 2;
				m_Allocator.Resize(size * 2);
			}

			++m_Count;
			m_Allocator.SetValue(m_Count++, Object);
		}

		void Insert(AInt Index, AObject Object)
		{
		}

		void Remove(AObject Object)
		{
		}

		void RemoveAt(XPlatform::INT32 Index)
		{
			//m_Allocator.SetValue(Index, nullptr);
			m_Allocator.Decrease(Index);
		}

		bool Contains()
		{
			return false;
		}

		XPlatform::INT32 GetCount()
		{
			return m_Count;
		}
	};
}