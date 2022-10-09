// Generate by AcroTypeTool (2022/10/10 01:07:00).
#include "AcroEngine.h"
#include "IAssembly.h"
#include "AType.h"
#include "AObject.h"
#include "ABoolean.h"


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
	}

	class AcroEngineAssembly : public IAssembly
	{
	public:
		virtual VOID Assemble() override
		{
			AcroEngine::LoadType(new Generated::ObjectType());
			AcroEngine::LoadType(new Generated::BooleanType());
		}
	};
}