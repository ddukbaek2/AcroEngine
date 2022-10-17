#pragma once

#include "AcroEngine.h"
#include "AVariable.h"
#include "AUInt.h"
#include "IEnumerable.h"

namespace AcroEngine
{

	class Collection : public Variable, public IEnumerable
	{
	private:

	public:

	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 색인배열 형.
	/////////////////////////////////////////////////////////////////////////////
	class List : public Variable, public IEnumerable
	{
	private:
		class Enumerator : public IEnumerator
		{
		private:
			std::vector<AObject> m_Data;
			AObject m_Current;
			uint32 m_Count;
			uint32 m_Index;

		public:
			Enumerator(std::vector<AObject> data) : IEnumerator()
			{
				m_Data = data; // 얕은복사.
				m_Count = m_Data.size();
				
				Clear();
			}

			virtual void Clear() override
			{
				m_Index = 0;
				m_Current = AObject::Null();
			}

			virtual bool8 MoveNext() override
			{
				if (m_Index + 1 >= m_Count)
				{
					m_Index = m_Data.size();
					m_Current = AObject::Null();
					return false;
				}

				m_Current = m_Data[m_Index++];
				return true;
			}

			virtual AObject GetCurrent() override
			{
				return m_Current;
			}
		};


	private:
		std::vector<AObject> m_Data;

	public:

	public:
		List() : Variable()
		{
			m_Data.clear();
		}

		List(UInt Capacity) : List()
		{
			m_Data.resize(Capacity);
		}

		List(std::initializer_list<AObject> list)
		{
			for (auto elem : list)
				Add(elem);
		}

		void Clear()
		{
			m_Data.clear();
		}

		void Add(AObject Object)
		{
			m_Data.push_back(Object);
		}

		void Insert(uint32 Index, AObject Object)
		{
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
				//TRef Current = m_Allocator.Get(Index);
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

		virtual const AEnumerator GetEnumerator() override
		{
			return new Enumerator(m_Data);
		}
	};
}