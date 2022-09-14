#include "AcroEngine.h"
#include "AObject.h"
#include "ADelegate.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 해시.
	/////////////////////////////////////////////////////////////////////////////
	class CRC32
	{
	public:
		static XPlatform::VOID CreateTable(XPlatform::UINT32(&table)[256])
		{
			XPlatform::UINT32 polynomial = 0xEDB88320;
			for (XPlatform::UINT32 i = 0; i < 256; i++)
			{
				XPlatform::UINT32 c = i;
				for (XPlatform::UINT32 j = 0; j < 8; j++)
				{
					if (c & 1) {
						c = polynomial ^ (c >> 1);
					}
					else {
						c >>= 1;
					}
				}
				table[i] = c;
			}
		}

		static XPlatform::UINT32 ComputeHash(XPlatform::UINT32(&table)[256], XPlatform::UINT32 initial, const XPlatform::VOID* buf, XPlatform::UINT32 len)
		{
			XPlatform::UINT32 c = initial ^ 0xFFFFFFFF;
			const XPlatform::UINT8* u = static_cast<const XPlatform::UINT8*>(buf);
			for (XPlatform::UINT32 i = 0; i < len; ++i)
			{
				c = table[(c ^ u[i]) & 0xFF] ^ (c >> 8);
			}
			return c ^ 0xFFFFFFFF;
		}
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 객체관리자.
	/////////////////////////////////////////////////////////////////////////////
	class ObjectManager
	{
	private:
		XPlatform::TAllocator<AObject> m_Objects;

	public:
		ObjectManager()
		{
			m_Objects.Resize(4096);
		}

		void Add(AObject Object)
		{
			m_Objects.SetValue(0, Object);
		}

		void Remove(AObject Object)
		{
			m_Objects.SetValue(0, nullptr);
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 내부 전역 변수.
	/////////////////////////////////////////////////////////////////////////////
	static ObjectManager g_ObjectManager;
	static CRC32 g_CRC32;


	/////////////////////////////////////////////////////////////////////////////
	// @ 생성.
	/////////////////////////////////////////////////////////////////////////////
	AObject Instantiate(AType Type)
	{
		//CRC32::CreateTable();
		AObject Object = new IObject();
		Object->m_ID = 1;
		Object->m_IsDestroyed = false;
		Object->m_ReferenceCount = 1;
		g_ObjectManager.Add(Object);
		return Object;
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 파괴.
	/////////////////////////////////////////////////////////////////////////////
	XPlatform::VOID Destroy(AObject Object)
	{
		if (Object != nullptr && !Object->m_IsDestroyed)
		{
			Object->m_ReferenceCount = 0;
			Object->m_IsDestroyed = true;
		}
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 즉시 파괴.
	/////////////////////////////////////////////////////////////////////////////
	XPlatform::VOID DestroyImmediate(AObject Object)
	{
		if (Object != nullptr)
		{
			delete Object;
			Object = nullptr;
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 파괴 여부.
	/////////////////////////////////////////////////////////////////////////////
	XPlatform::BOOL8 IsDestroyed(AObject Object)
	{
		return Object == nullptr || Object->m_IsDestroyed;
	}
}