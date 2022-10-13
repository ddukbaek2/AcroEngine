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
				m_Name = AcroCore::GetTypeName<Object>();
			}

			virtual bool8 IsParent(AType Type) override
			{
				return false;
			}

			virtual bool8 IsChildren(AType Type) override
			{
				return false;
			}

			virtual pointer CreateInstance() override
			{
				return new Object();
			}
		};

		class BooleanType : public Type
		{
		public:
			BooleanType() : Type()
			{
				m_Name = AcroCore::GetTypeName<Boolean>();
			}

			virtual bool8 IsParent(AType Type) override
			{
				return false;
			}

			virtual bool8 IsChildren(AType Type) override
			{
				return false;
			}

			virtual pointer CreateInstance() override
			{
				return new Boolean();
			}
		};
	}

	class AcroEngineAssembly : public IAssembly
	{
	public:
		virtual void Assemble() override
		{
			AcroEngine::LoadType(new Generated::ObjectType());
			AcroEngine::LoadType(new Generated::BooleanType());
		}
	};
}