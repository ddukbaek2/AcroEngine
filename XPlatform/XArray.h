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
		XAllocator<T> m_Instance;
		UINT32 m_Count;

	public:
		XArray()
		{
			Clear();
		}

		virtual ~XArray()
		{
			m_Instance.Clear();
			m_Count = 0;
		}

		VOID Clear()
		{
			m_Instance.Clear(true);
		}

		VOID Add(const T& Value)
		{
			++m_Count;
			if (m_Count > m_Instance.GetSize())
			{
				m_Instance.Resize(m_Instance.GetSize() * 2);
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
			m_Instance.RemoveAt(Index);
		}

		UINT32 GetCount()
		{
			return m_Count;
		}
	};
}