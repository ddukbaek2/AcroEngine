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

		void Add(AObject Object)
		{
			m_Data.push_back(Object);
		}

		void Insert(AInt Index, AObject Object)
		{
		}

		void Clear()
		{
			m_Data.clear();
		}

		bool8 Remove(AObject Object)
		{
			int32 Index = GetObject(Object);
			if (Index == -1)
				return false;

			//m_Allocator.RemoveAt(Index);
			//
			return true;
		}

		bool8 RemoveAt(uint32 Index)
		{
			if (Index < 0 || Index >= m_Data.size())
				return false;

			//m_Allocator.RemoveAt(Index);
			return true;
		}

		int32 GetObject(AObject Object)
		{
			for (uint32 Index = 0; Index < m_Data.size(); ++Index)
			{
				//ARef Current = m_Allocator.Get(Index);
				//if (Current->Equals(Object))
				//	return Index;
			}

			return -1;
		}

		AObject GetObject(uint32 Index)
		{
			return AObject::Null();
			//return m_Allocator.Get(Index);
		}

		bool8 Contains(AObject Object)
		{
			return GetObject(Object) != -1;
		}

		uint32 GetCount()
		{
			return m_Data.size();
		}
	};
}