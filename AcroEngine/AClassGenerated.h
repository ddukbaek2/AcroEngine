#pragma once
// Generate by AcroPreBuildTool.
#include "AObject.h"


#define CLASSHASH(Class)

namespace AcroEngine
{
	class CRC32
	{
	public:
		static void CreateTable(XPlatform::UINT32(&table)[256])
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

		static XPlatform::UINT32 ComputeHash(XPlatform::UINT32(&table)[256], XPlatform::UINT32 initial, const void* buf, XPlatform::UINT32 len)
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

	// usage: the following code generates crc for 2 pieces of data
	// uint32_t table[256];
	// crc32::generate_table(table);
	// uint32_t crc = crc32::update(table, 0, data_piece1, len1);
	// crc = crc32::update(table, crc, data_piece2, len2);
	// output(crc);

	class AClassGenerated
	{
	public:

		inline const wchar_t* GetClassName()
		{
			//DECLARE_ACLASSGENERATED(AObject)
			//DECLARE_ACLASSGENERATED(AString)
			//DECLARE_ACLASSGENERATED(AInt)
			//DECLARE_ACLASSGENERATED(AInt)
		}
	};
}