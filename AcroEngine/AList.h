#pragma once

#include "AcroEngine.h"
#include "AVariable.h"
#include "AUInt.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 색인배열 형.
	/////////////////////////////////////////////////////////////////////////////
	class IList : public IVariable
	{
	private:
		std::vector<AObject> m_Data;

	public:
		IList() : IVariable()
		{
			m_Data.clear();
		}

		IList(AUInt Capacity) : IList()
		{

			m_Data.resize(Capacity->ToUInt());
		}

		VOID Add(AObject Object)
		{
			m_Data.push_back(Object);
		}

		VOID Insert(AInt Index, AObject Object)
		{
		}

		VOID Clear()
		{
			m_Data.clear();
		}

		BOOL8 Remove(AObject Object)
		{
			INT32 Index = Find(Object);
			if (Index == -1)
				return false;

			//m_Allocator.RemoveAt(Index);
			//
			return true;
		}

		BOOL8 RemoveAt(UINT32 Index)
		{
			if (Index < 0 || Index >= m_Data.size())
				return false;

			//m_Allocator.RemoveAt(Index);
			return true;
		}

		INT32 Find(AObject Object)
		{
			for (UINT32 Index = 0; Index < m_Data.size(); ++Index)
			{
				//AObject Current = m_Allocator.GetValue(Index);
				//if (Current->Equals(Object))
				//	return Index;
			}

			return -1;
		}

		AObject Find(UINT32 Index)
		{
			return nullptr;
			//return m_Allocator.GetValue(Index);
		}

		BOOL8 Contains(AObject Object)
		{
			return Find(Object) != -1;
		}

		UINT32 GetCount()
		{
			return m_Data.size();
		}
	};
}