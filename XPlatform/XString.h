#pragma once

#include "XPlatform.h"
#include "TAllocator.h"

#define TEXT(Text) L#Text


namespace XPlatform
{
	class XString
	{
	private:
		TAllocator<CHAR16> m_Data;

	public:
		XString()
		{
			Clear();
		}

		XString(CHAR16 text[])
		{
			Clear();
			Set(text);
		}

		XString(XString& string)
		{
			Clear();
			Set(string.m_Data.Begin());
		}

		virtual ~XString()
		{
		}

		void Clear()
		{
			m_Data.Resize(32);
			for (INT32 i = 0; i < m_Data.GetSize(); ++i)
			{
				m_Data.SetValue(i, 0x0000);
			}
		}

		void Set(CHAR16 text[])
		{
			INT32 size = sizeof(text);
			m_Data.Resize(size);
			for (INT32 i = 0; i < m_Data.GetSize(); ++i)
			{
				m_Data.SetValue(i, text[i]);
			}
		}

		void At(CHAR16 text[])
		{
			INT32 size = sizeof(text);
			m_Data.Resize(size);
			for (INT32 i = 0; i < m_Data.GetSize(); ++i)
			{
				m_Data.SetValue(i, text[i]);
			}
		}

		const CHAR16* ToString()
		{
			return m_Data.Begin();
		}
	};
}