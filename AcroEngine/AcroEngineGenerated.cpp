// Generate by AcroTypeTool.
#include "AcroEngine.h"
#include "AType.h"
#include "AObject.h"
#include "ABoolean.h"
#include "IAssemble.h"


namespace AcroEngine
{
	namespace Generated
	{
		class ObjectType : public Type
		{
		public:
			ObjectType() : Type()
			{
				m_Name = TEXT("Object");
			}

			virtual BOOL8 IsParent(AType Type) override
			{
				return false;
			}

			virtual BOOL8 IsChildren(AType Type) override
			{
				return false;
			}

			virtual POINTER CreateInstance() override
			{
				return new Object();
			}
		};

		class BooleanType : public Type
		{
		public:
			BooleanType() : Type()
			{
				m_Name = TEXT("Boolean");
			}

			virtual BOOL8 IsParent(AType Type) override
			{
				return false;
			}

			virtual BOOL8 IsChildren(AType Type) override
			{
				return false;
			}

			virtual POINTER CreateInstance() override
			{
				return new Boolean();
			}
		};

		class AcroEngineGeneratedAssemble : IAssemble
		{
		public:
		};


		void Assemble()
		{
			AcroEngine::LoadType(new Generated::ObjectType());
			AcroEngine::LoadType(new Generated::BooleanType());
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
	//		//DECLARE_ACLASSGENERATED(ARef)
	//		//DECLARE_ACLASSGENERATED(String)
	//		//DECLARE_ACLASSGENERATED(Int)
	//		//DECLARE_ACLASSGENERATED(Int)
	//	}
	//};
}