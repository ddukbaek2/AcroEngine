#pragma once

#include "XPlatform.h"
#include "XAllocator.h"


namespace XPlatform
{
	class XString
	{
	private:
		XAllocator<CHAR16> m_Data;

	public:
		XString()
		{
			Reset();
		}

		XString(CHAR16 text[])
		{
			Reset();
			Set(text);
		}

		XString(XString& string)
		{
			Reset();
			Set(string.m_Data.Begin());
		}

		virtual ~XString()
		{
			m_Data.Reset();
		}

		void Reset()
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