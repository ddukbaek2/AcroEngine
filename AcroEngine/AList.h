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
		AcroCore::XAllocator<AObject> m_Allocator;
		AcroCore::UINT32 m_Count;

	public:
		IList() : IVariable()
		{
			m_Allocator.Clear();
			m_Count = 0;
		}

		IList(AInt Capacity) : IList()
		{
			m_Allocator.Resize(Capacity->ToInt());
		}

		AcroCore::VOID Add(AObject Object)
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

		AcroCore::VOID Insert(AInt Index, AObject Object)
		{
		}

		AcroCore::VOID Clear()
		{
			m_Allocator.Clear();
		}

		AcroCore::BOOL8 Remove(AObject Object)
		{
			AcroCore::INT32 Index = Find(Object);
			if (Index == -1)
				return false;

			m_Allocator.RemoveAt(Index);
			return true;
		}

		AcroCore::BOOL8 RemoveAt(AcroCore::UINT32 Index)
		{
			if (Index < 0 || Index >= m_Allocator.GetSize())
				return false;

			m_Allocator.RemoveAt(Index);
			return true;
		}

		AcroCore::INT32 Find(AObject Object)
		{
			for (AcroCore::UINT32 Index = 0; Index < m_Allocator.GetSize(); ++Index)
			{
				AObject Current = m_Allocator.GetValue(Index);
				if (Current->Equals(Object))
					return Index;
			}

			return -1;
		}

		AObject Find(AcroCore::UINT32 Index)
		{
			return m_Allocator.GetValue(Index);
		}

		AcroCore::BOOL8 Contains(AObject Object)
		{
			return Find(Object) != -1;
		}

		AcroCore::INT32 GetCount()
		{
			return m_Count;
		}
	};
}