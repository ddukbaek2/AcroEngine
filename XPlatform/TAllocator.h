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
		T* m_Begin;
		INT32 m_Size;

	public:
		TAllocator();
		virtual ~TAllocator();

		VOID Reset();
		VOID Resize(INT32 size);
		INT32 GetSize();

		// -1
		VOID Increase(INT32 Index = -1);

		// +1
		VOID Decrease(INT32 Index = -1);

		BOOL8 SetValue(INT32 Index, T Object);
		T GetValue(INT32 Index);

		inline T* Begin() { return m_Begin; }
		inline T* End() { return m_Begin + m_Size; }
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
		if (m_Begin != nullptr)
		{
			delete[] m_Begin;
			m_Begin = nullptr;
		}
	}

	template<typename T>
	inline void TAllocator<T>::Reset()
	{
		INT32 elementSize = sizeof(T);

		UINT8* temp = (UINT8*)m_Begin;
		for (INT32 i = 0; i < elementSize * m_Size; ++i)
			temp[i] = 0;
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

		m_Size = size;
	}

	template<typename T>
	inline INT32 TAllocator<T>::GetSize()
	{
		return m_Size;
	}


	template<typename T>
	inline void TAllocator<T>::Increase(INT32 Index)
	{
		// back.
		if (Index < 0 || Index >= m_Size)
		{
		}

		++m_Size;
	}

	template<typename T>
	inline void TAllocator<T>::Decrease(INT32 Index)
	{
		if (m_Size <= 0)
			return;

		// back.
		if (Index < 0 || Index >= m_Size)
		{

		}

		--m_Size;
	}

	template<typename T>
	inline bool TAllocator<T>::SetValue(INT32 Index, T Object)
	{
		if (Index < 0 || Index >= m_Size)
			return false;

		m_Begin[Index] = Object;
		return true;
	}


	template<typename T>
	inline T TAllocator<T>::GetValue(INT32 Index)
	{
		if (Index < 0 || Index >= m_Size)
			return nullptr;

		return m_Begin[Index];
	}
}