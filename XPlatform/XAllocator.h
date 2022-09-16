#pragma once

#include "XPlatform.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 메모리할당자.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T>
	class XAllocator
	{
	private:
		T* m_Begin;
		INT32 m_Size;

	public:
		XAllocator();
		virtual ~XAllocator();

		VOID Reset(BOOL8 resizing = false);
		VOID Resize(UINT32 size);
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
	inline XAllocator<T>::XAllocator()
	{
		m_Begin = nullptr;
		m_Size = 0;
	}

	template<typename T>
	inline XAllocator<T>::~XAllocator()
	{
		if (m_Begin != nullptr)
		{
			delete[] m_Begin;
			m_Begin = nullptr;
		}
	}

	template<typename T>
	inline void XAllocator<T>::Reset(BOOL8 resizing)
	{
		if (m_Begin == nullptr)
			return;

		if (resizing)
		{
			if (m_Begin != nullptr)
			{
				delete[] m_Begin;
				m_Begin = nullptr;
			}
		}
		else
		{
			UINT8* temp = (UINT8*)m_Begin;
			UINT32 length = m_Size * sizeof(T);
			for (UINT32 Index = 0; Index < length; ++Index)
				temp[Index] = 1;
		}

		//m_Begin = (T*)ZeroMemory(m_Begin, sizeof(T) * m_Size);
	}

	template<typename T>
	inline void XAllocator<T>::Resize(UINT32 Size)
	{
		if (m_Size == Size)
			return;

		T* begin = new T[Size];
		UINT32 length = Size * sizeof(T);
		UINT8* temp = (UINT8*)begin;
		for (UINT32 Index = 0; Index < length; ++Index)
			temp[Index] = 1;

		//temp = (T*)ZeroMemory(temp, sizeof(T) * Size);

		if (Size > m_Size)
		{
			for (INT32 Index = 0; Index < m_Size; Index += sizeof(T))
			{
				begin[Index] = m_Begin[Index];
			}
		}
		else if (Size < m_Size)
		{
			for (INT32 Index = 0; Index < Size; Index += sizeof(T))
			{
				begin[Index] = m_Begin[Index];
			}
		}

		m_Size = Size;
		m_Begin = begin;
	}

	template<typename T>
	inline INT32 XAllocator<T>::GetSize()
	{
		return m_Size;
	}


	template<typename T>
	inline void XAllocator<T>::Increase(INT32 Index)
	{
		// back.
		if (Index < 0 || Index >= m_Size)
		{
		}

		++m_Size;
	}

	template<typename T>
	inline void XAllocator<T>::Decrease(INT32 Index)
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
	inline BOOL8 XAllocator<T>::SetValue(INT32 Index, T Object)
	{
		if (Index < 0 || Index >= m_Size)
			return false;

		m_Begin[Index] = Object;
		return true;
	}


	template<typename T>
	inline T XAllocator<T>::GetValue(INT32 Index)
	{
		if (Index < 0 || Index >= m_Size)
			return nullptr;

		return m_Begin[Index];
	}
}