// Generate by AcroTypeTool.
#include "AType.h"
#include "AObject.h"
#include "IAssemble.h"


namespace AcroEngine
{
	namespace Generated
	{
		class IObjectType : public IType
		{

		};

		class IAcroEngineGeneratedAssemble : IAssemble
		{
		public:
		};
		void Assemble()
		{
			//AcroEngine::LoadType(TEXT("IObjectType"));
		}
	}
	// usage: the following code generates crc for 2 pieces of data
	// uint32_t table[256];
	// crc32::generate_table(table);
	// uint32_t crc = crc32::update(table, 0, data_piece1, len1);
	// crc = crc32::update(table, crc, data_piece2, len2);
	// output(crc);

	//class IEngineAssemble : IAssemble
	//{
	//public:

	//	inline const wchar_t* GetName()
	//	{
	//		//DECLARE_ACLASSGENERATED(AObject)
	//		//DECLARE_ACLASSGENERATED(AString)
	//		//DECLARE_ACLASSGENERATED(AInt)
	//		//DECLARE_ACLASSGENERATED(AInt)
	//	}
	//};
}