#pragma once

#include "AcroCore.h"


namespace AcroCore
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 메모리할당 클래스.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T> class XAllocator
	{
	private:
		UINT8* m_Memory;
		UINT32 m_Size;

	public:
		XAllocator()
		{
			m_Memory = nullptr;
			m_Size = 0;
		}

		XAllocator(UINT32 Size)
		{
			m_Memory = nullptr;
			m_Size = 0;

			Resize(Size);
		}

		virtual ~XAllocator()
		{
			Clear(true);
		}

		VOID Clear(BOOL8 Resizing = false)
		{
			if (m_Memory == nullptr)
				return;

			if (Resizing)
			{
				XMemoryFree((POINTER)m_Memory);
				m_Memory = nullptr;
				m_Size = 0;
			}
			else
			{
				XMemorySet((POINTER)m_Memory, 0, m_Size * sizeof(T));
			}
		}

		VOID Resize(UINT32 Size)
		{
			if (m_Size == Size)
				return;

			UINT32 typeSize = sizeof(T);
			UINT8* memory = (UINT8*)XMemoryAllocate(Size * typeSize);
			XMemorySet((POINTER)memory, 0, Size * typeSize);

			if (Size > m_Size)
			{
				for (UINT32 Index = 0; Index < sizeof(T) * m_Size; ++Index)
				{
					((T*)memory)[Index] = ((T*)m_Memory)[Index];
				}
			}
			else if (Size < m_Size)
			{
				for (UINT32 Index = 0; Index < sizeof(T) * Size; ++Index)
				{
					((T*)memory)[Index] = ((T*)m_Memory)[Index];
				}
			}

			m_Size = Size;
			XMemoryFree((VOID*)m_Memory);
			m_Memory = memory;
		}

		UINT32 GetSize()
		{
			return m_Size;
		}

		// -1
		VOID Insert(UINT32 Index)
		{
			// back.
			if (Index >= m_Size)
			{
			}

			++m_Size;
		}

		// +1
		VOID RemoveAt(UINT32 Index)
		{
			if (m_Size <= 0)
				return;

			// back.
			if (Index >= m_Size)
			{

			}

			--m_Size;
		}

		BOOL8 SetValue(UINT32 Index, T Object)
		{
			if (Index >= m_Size)
				return false;

			((T*)m_Memory)[Index] = Object;
			return true;
		}

		T GetValue(UINT32 Index)
		{
			if (Index >= m_Size)
				return nullptr;

			return ((T*)m_Memory)[Index];
		}

		T* Begin()
		{
			return (T*)m_Memory;
		}

		T& Front()
		{
			return m_Memory[0];
		}

		T& Back()
		{
			return m_Memory[m_Size - 1];
		}

		T* End()
		{
			return ((T*)m_Memory) + m_Size;
		}
	};
}