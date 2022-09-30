#pragma once

#include "XPlatform.h"
#include "XAllocator.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 문자열 클래스.
	/////////////////////////////////////////////////////////////////////////////
	class XString
	{
	private:
		XAllocator<CHAR16> m_Instance;

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
			Set(string.m_Instance.Begin());
		}

		virtual ~XString()
		{
			m_Instance.Clear();
		}

		void Clear()
		{
			m_Instance.Resize(32);
			for (UINT32 i = 0; i < m_Instance.GetSize(); ++i)
			{
				m_Instance.SetValue(i, 0x0000);
			}
		}

		void Set(CHAR16 text[])
		{
			UINT32 size = sizeof(text);
			m_Instance.Resize(size);
			for (UINT32 i = 0; i < m_Instance.GetSize(); ++i)
			{
				m_Instance.SetValue(i, text[i]);
			}
		}

		void At(CHAR16 text[])
		{
			UINT32 size = sizeof(text);
			m_Instance.Resize(size);
			for (UINT32 i = 0; i < m_Instance.GetSize(); ++i)
			{
				m_Instance.SetValue(i, text[i]);
			}
		}

		const CHAR16* ToString()
		{
			return m_Instance.Begin();
		}
	};
}