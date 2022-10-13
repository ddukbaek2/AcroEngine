// Generate by AcroTypeTool (2022/10/10 01:07:00).
#include "AcroEngine.h"
#include "IAssembly.h"
#include "AType.h"
#include "TTypeDef.h"

#include "AObject.h"
#include "ADelegate.h"

#include "ADictionary.h"
#include "AList.h"
#include "AQueue.h"
#include "ASet.h"
#include "AStack.h"
#include "AJson.h"
#include "ABoolean.h"
#include "AString.h"
#include "ADouble.h"
#include "AFloat.h"
#include "AInt.h"
#include "AShort.h"
#include "AUInt.h"
#include "AUShort.h"
#include "AVariable.h"
#include "AVector2.h"
#include "AVector3.h"
#include "AVector4.h"
#include "AAsset.h"

namespace AcroEngine
{
	class AcroEngineAssembly : public IAssembly
	{
	public:
		virtual void Assemble() override
		{
			AcroEngine::LoadType(new TTypeDef<Object>());
			AcroEngine::LoadType(new TTypeDef<Delegate>());
			AcroEngine::LoadType(new TTypeDef<Dictionary>());
			AcroEngine::LoadType(new TTypeDef<List>());
			AcroEngine::LoadType(new TTypeDef<Queue>());
			AcroEngine::LoadType(new TTypeDef<Set>());
			AcroEngine::LoadType(new TTypeDef<Stack>());
			AcroEngine::LoadType(new TTypeDef<Json>());
			AcroEngine::LoadType(new TTypeDef<Boolean>());
			AcroEngine::LoadType(new TTypeDef<String>());
			AcroEngine::LoadType(new TTypeDef<Double>());
			AcroEngine::LoadType(new TTypeDef<Float>());
			AcroEngine::LoadType(new TTypeDef<Int>());
			AcroEngine::LoadType(new TTypeDef<Short>());
			AcroEngine::LoadType(new TTypeDef<UInt>());
			AcroEngine::LoadType(new TTypeDef<UShort>());
			AcroEngine::LoadType(new TTypeDef<Variable>());
			AcroEngine::LoadType(new TTypeDef<Vector2>());
			AcroEngine::LoadType(new TTypeDef<Vector3>());
			AcroEngine::LoadType(new TTypeDef<Vector4>());
			AcroEngine::LoadType(new TTypeDef<Asset>());
		}
	};
}