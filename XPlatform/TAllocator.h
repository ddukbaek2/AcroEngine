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

		void Clear();
		void Resize(INT32 size);
		INT32 GetSize();

		// -1
		void Increase(INT32 Index = -1);

		// +1
		void Decrease(INT32 Index = -1);

		BOOL SetValue(INT32 Index, T Object);
		BOOL SetValueReference(INT32 Index, T& Object);
		BOOL SetValuePointer(INT32 Index, T* Object);
		T* GetValue(INT32 Index);

		T* Begin() { return m_Begin; }
		T* End() { return m_Begin + m_Size; }
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
	inline void TAllocator<T>::Clear()
	{
		for (INT32 i = 0; i < m_Size; ++i)
		{
			//m_Begin[i] = 0;
		}
	}

	template<typename T>
	inline void TAllocator<T>::Resize(INT32 size)
	{
		if (m_TotalSize == size)
			return;

		if (size > m_TotalSize)
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
		if (Index < 0 || Index >= m_TotalSize)
		{
		}

		++m_TotalSize;
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
	inline bool TAllocator<T>::SetValueReference(INT32 Index, T& Object)
	{
		if (Index < 0 || Index >= m_Size)
			return false;

		m_Begin[Index] = Object;
		return true;
	}

	template<typename T>
	inline bool TAllocator<T>::SetValuePointer(INT32 Index, T* Object)
	{
		if (Index < 0 || Index >= m_Size)
			return false;

		m_Begin[Index] = Object;
		return true;
	}

	template<typename T>
	inline T* TAllocator<T>::GetValue(INT32 Index)
	{
		if (Index < 0 || Index >= m_Size)
			return nullptr;

		return m_Begin[Index];
	}
}