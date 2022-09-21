#pragma once
// Generate by AcroPreBuildTool.
#include "AObject.h"


namespace AcroEngine
{
	// usage: the following code generates crc for 2 pieces of data
	// uint32_t table[256];
	// crc32::generate_table(table);
	// uint32_t crc = crc32::update(table, 0, data_piece1, len1);
	// crc = crc32::update(table, crc, data_piece2, len2);
	// output(crc);

	class IAssemble
	{
	public:
	};

	class IEngineAssemble : IAssemble
	{
	public:

		inline const wchar_t* GetName()
		{
			//DECLARE_ACLASSGENERATED(AObject)
			//DECLARE_ACLASSGENERATED(AString)
			//DECLARE_ACLASSGENERATED(AInt)
			//DECLARE_ACLASSGENERATED(AInt)
		}
	};
}