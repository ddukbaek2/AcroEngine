#pragma once

#include "AcroEngine.h"
#include "AVariable.h"
#include "AInt.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 색인배열 형.
	/////////////////////////////////////////////////////////////////////////////
	class IList : public IVariable
	{
	private:
		XPlatform::TAllocator<AObject> m_Allocator;
		XPlatform::INT32 m_Count;

	public:
		IList() : IVariable()
		{
			m_Allocator.Reset();
			m_Count = 0;
		}

		IList(AInt Capacity) : IList()
		{
			m_Allocator.Resize(Capacity->ToInt());
		}

		XPlatform::VOID Add(AObject Object)
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

		XPlatform::VOID Insert(AInt Index, AObject Object)
		{
		}

		XPlatform::VOID Reset()
		{
			m_Allocator.Reset();
		}

		XPlatform::BOOL8 Remove(AObject Object)
		{
			XPlatform::INT32 Index = Find(Object);
			if (Index == -1)
				return false;

			m_Allocator.Decrease(Index);
			return true;
		}

		XPlatform::BOOL8 RemoveAt(XPlatform::INT32 Index)
		{
			if (Index < 0 || Index >= m_Allocator.GetSize())
				return false;

			m_Allocator.Decrease(Index);
			return true;
		}

		XPlatform::INT32 Find(AObject Object)
		{
			for (XPlatform::INT32 Index = 0; Index < m_Allocator.GetSize(); ++Index)
			{
				AObject Current = m_Allocator.GetValue(Index);
				if (Current->Equals(Object))
					return Index;
			}

			return -1;
		}

		XPlatform::BOOL8 Contains(AObject Object)
		{
			return Find(Object) != -1;
		}

		XPlatform::INT32 GetCount()
		{
			return m_Count;
		}
	};
}