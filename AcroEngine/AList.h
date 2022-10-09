#pragma once

#include "AcroEngine.h"
#include "AVariable.h"
#include "AUInt.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 색인배열 형.
	/////////////////////////////////////////////////////////////////////////////
	class List : public Variable
	{
	private:
		std::vector<AObject> m_Data;

	public:
		List() : Variable()
		{
			m_Data.clear();
		}

		List(UInt Capacity) : List()
		{
			m_Data.resize(Capacity);
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
			INT32 Index = GetObject(Object);
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

		INT32 GetObject(AObject Object)
		{
			for (UINT32 Index = 0; Index < m_Data.size(); ++Index)
			{
				//ARef Current = m_Allocator.GetValue(Index);
				//if (Current->Equals(Object))
				//	return Index;
			}

			return -1;
		}

		AObject GetObject(UINT32 Index)
		{
			return AObject::Null();
			//return m_Allocator.GetValue(Index);
		}

		BOOL8 Contains(AObject Object)
		{
			return GetObject(Object) != -1;
		}

		UINT32 GetCount()
		{
			return m_Data.size();
		}
	};
}