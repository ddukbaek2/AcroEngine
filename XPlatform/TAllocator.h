#pragma once

#include "XPlatform.h"


namespace XPlatform
{
	#define SAFE_DELETE_ARRAY(ptr) if (ptr != nullptr) { delete[] ptr; ptr = nullptr; }

	/////////////////////////////////////////////////////////////////////////////
	// @ 메모리할당자.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T>
	class TAllocator
	{
	private:
		T* m_Begin;
		INT32 m_Size;

	public:
		TAllocator();
		virtual ~TAllocator();

		void Clear();
		void Resize(INT32 size);
		INT32 GetSize();

		// -1
		void Pull(INT32 Index);

		// +1
		void Push(INT32 Index);

		void SetValue(INT32 Index, T* Object);
		T* GetValue(INT32 Index);
	};

	template<typename T>
	inline TAllocator<T>::TAllocator()
	{
		m_Begin = nullptr;
		m_Size = 0;
	}

	template<typename T>
	inline TAllocator<T>::~TAllocator()
	{
		SAFE_DELETE_ARRAY(m_Begin);
	}

	template<typename T>
	inline void TAllocator<T>::Clear()
	{
		for (INT32 i = 0; i < m_Size; ++i)
		{
			m_Begin[i] = 0;
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

	template<typename T>
	inline void TAllocator<T>::SetValue(INT32 Index, T* Object)
	{
		if (Index < 0 || Index >= m_Size)
			return;

		m_Begin[index] = Object;
	}

	template<typename T>
	inline T* TAllocator<T>::GetValue(INT32 Index);
	{
		if (Index < 0 || Index >= m_Size)
			return nullptr;

		return m_Begin[index];
	}
}