#pragma once

#include "XPlatform.h"
#include "XAllocator.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 배열 클래스.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T> class XArray 
	{
	private:
		XAllocator<T> m_Data;
		UINT32 m_Count;

	public:
		XArray()
		{
			Clear();
		}

		virtual ~XArray()
		{
			m_Data.Clear();
			m_Count = 0;
		}

		VOID Clear()
		{
			m_Data.Clear(true);
		}

		VOID Add(const T& Value)
		{
			++m_Count;
			if (m_Count > m_Data.GetSize())
			{
				m_Data.Resize(m_Data.GetSize() * 2);
			}
		}

		VOID Insert(UINT32 Index, const T& Value)
		{
			if (Index < m_Count)
			{

			}
			else
			{
				Add(Value);
			}
		}

		VOID RemoveAt(UINT32 Index)
		{
			m_Data.RemoveAt(Index);
		}

		UINT32 GetCount()
		{
			return m_Count;
		}
	};
}