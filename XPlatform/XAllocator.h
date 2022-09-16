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
		UINT8* m_Memory;
		UINT32 m_Size;

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

		inline T* Begin() { return (T*)m_Memory; }
		inline T* End() { return ((T*)m_Memory) + m_Size; }
	};

	template<typename T>
	inline XAllocator<T>::XAllocator()
	{
		m_Memory = nullptr;
		m_Size = 0;
	}

	template<typename T>
	inline XAllocator<T>::~XAllocator()
	{
		DeleteMemory((VOID*)m_Memory);
		m_Memory = nullptr;
		m_Size = 0;
	}

	template<typename T>
	inline void XAllocator<T>::Reset(BOOL8 resizing)
	{
		if (m_Memory == nullptr)
			return;

		if (resizing)
		{
			DeleteMemory((VOID*)m_Memory);
			m_Memory = nullptr;
			m_Size = 0;
		}
		else
		{
			FillMemory((VOID*)m_Memory, 1, m_Size * sizeof(T));
		}
	}

	template<typename T>
	inline void XAllocator<T>::Resize(UINT32 Size)
	{
		if (m_Size == Size)
			return; 

		int a[32];
		FillMemory((VOID*)a, 1, 4 * 32);

		UINT32 typeSize = sizeof(T);
		UINT8* memory = (UINT8*)CreateMemory(Size * typeSize);
		FillMemory((VOID*)memory, 1, Size * typeSize);

		//temp = (T*)FillMemory(temp, sizeof(T) * Size);

		if (Size > m_Size)
		{
			for (INT32 Index = 0; Index < sizeof(T) * m_Size; ++Index)
			{
				((T*)memory)[Index] = ((T*)m_Memory)[Index];
			}
		}
		else if (Size < m_Size)
		{
			for (INT32 Index = 0; Index < sizeof(T) * Size; ++Index)
			{
				((T*)memory)[Index] = ((T*)m_Memory)[Index];
			}
		}

		m_Size = Size;
		DeleteMemory((VOID*)m_Memory);
		m_Memory = memory;
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

		((T*)m_Memory)[Index] = Object;
		return true;
	}


	template<typename T>
	inline T XAllocator<T>::GetValue(INT32 Index)
	{
		if (Index < 0 || Index >= m_Size)
			return nullptr;

		 return ((T*)m_Memory)[Index];
	}
}