#pragma once

#include "XPlatform.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 메모리할당자.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T>
	class TAllocator
	{
	private:
		T* m_Pointer;
		INT32 m_Size;

	public:
		TAllocator();
		virtual ~TAllocator();

		void Clear();
		void Resize(INT32 size);
		INT32 GetSize();
	};

	template<typename T>
	inline TAllocator<T>::TAllocator()
	{
		m_Pointer = nullptr;
		m_Size = 0;
	}

	template<typename T>
	inline TAllocator<T>::~TAllocator()
	{
	}

	template<typename T>
	inline void TAllocator<T>::Clear()
	{
		for (INT32 i = 0; i < m_Size; ++i)
		{
			m_Pointer[i] = 0;
		}
	}

	template<typename T>
	inline void TAllocator<T>::Resize(INT32 size)
	{
		if (m_Size == size)
			return;

		if (size > m_Size)
		{

		}
		else if (size < m_Size)
		{

		}
	}

	template<typename T>
	inline INT32 TAllocator<T>::GetSize()
	{
		return m_Size;
	}
}