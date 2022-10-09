#include "AcroEngine.h"
#include "AObject.h"
#include "ADelegate.h"
#include "AcroEngineGenerated.cpp"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 오브젝트 파괴자.
	/////////////////////////////////////////////////////////////////////////////
	struct ObjectDestroyer
	{
		void operator () (ARef<Object> Object)
		{
			Destroy(Object);
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 해시.
	/////////////////////////////////////////////////////////////////////////////
	class CRC32
	{
	public:
		VOID CreateTable(UINT32(&table)[256])
		{
			UINT32 polynomial = 0xEDB88320;
			for (UINT32 i = 0; i < 256; i++)
			{
				UINT32 c = i;
				for (UINT32 j = 0; j < 8; j++)
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

		UINT32 ComputeHash(UINT32(&table)[256], UINT32 initial, const POINTER buf, UINT32 len)
		{
			UINT32 c = initial ^ 0xFFFFFFFF;
			const UINT8* u = static_cast<const UINT8*>(buf);
			for (UINT32 i = 0; i < len; ++i)
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
		std::map<INT32, std::shared_ptr<Object>> m_Objects;
		
	public:
		ObjectManager()
		{
		}

		virtual ~ObjectManager()
		{
			RemoveAllObjects();
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ 등록.
		/////////////////////////////////////////////////////////////////////////////
		void Add(std::shared_ptr<Object> Object)
		{
			auto objectID = Object->GetObjectID();
			m_Objects.insert(std::make_pair(objectID, Object));
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ 제거.
		/////////////////////////////////////////////////////////////////////////////
		void Remove(INT32 ObjectID)
		{
			m_Objects.erase(ObjectID);
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ 모든 오브젝트 제거.
		/////////////////////////////////////////////////////////////////////////////
		void RemoveAllObjects()
		{
			std::vector<INT32> temp;
			for (auto& pair : m_Objects)
				temp.push_back(pair.first);

			for (auto objectID : temp)
				Remove(objectID);
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ 참조되지 않는 모든 오브젝트 제거.
		/////////////////////////////////////////////////////////////////////////////
		void RemoveAllUnusedObjects()
		{
			std::vector<INT32> temp;
			for (auto& pair : m_Objects)
			{
				auto objectReferenceCount = pair.second.use_count();
				if (objectReferenceCount == 1)
					temp.push_back(pair.first);
			}

			for (auto objectID : temp)
				Remove(objectID);
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ 객체 반환.
		/////////////////////////////////////////////////////////////////////////////
		std::weak_ptr<Object> GetObject(INT32 ObjectID)
		{
			auto it = m_Objects.find(ObjectID);
			if (it == m_Objects.end())
				return std::weak_ptr<Object>();
			return std::weak_ptr<Object>(it->second);
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ 참조카운트 반환.
		/////////////////////////////////////////////////////////////////////////////
		INT64 GetReferenceCount(INT32 ObjectID)
		{
			auto object = GetObject(ObjectID);
			if (object.expired())
				return 0;

			return object.use_count();
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 타입관리자.
	/////////////////////////////////////////////////////////////////////////////
	class TypeManager
	{
	private:
		std::map<std::wstring, std::shared_ptr<Type>> m_Types;
		//std::map<std::wstring, UINT32> m_CachedTypeIndices;

	public:
		TypeManager()
		{
		}

		virtual ~TypeManager()
		{
			RemoveAllTypes();
		}

		VOID Add(std::shared_ptr<Type> Type)
		{
			std::wstring typeName = Type->GetName();
			m_Types.insert(std::make_pair(typeName,Type));
		}

		VOID Remove(const std::wstring& TypeName)
		{
			m_Types.erase(TypeName);
		}

		VOID RemoveAllTypes()
		{
			m_Types.clear();
		}

		AType GetType(const std::wstring& TypeName)
		{
			auto it = m_Types.find(TypeName);
			if (it == m_Types.end())
				return AType::Null();
			return AType(it->second);
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 내부 전역 변수.
	/////////////////////////////////////////////////////////////////////////////
	static ObjectManager g_ObjectManager;
	static TypeManager g_TypeManager;
	static CRC32 g_CRC32;


	/////////////////////////////////////////////////////////////////////////////
	// @ 타입 로드.
	/////////////////////////////////////////////////////////////////////////////
	AType LoadType(Type* Target)
	{
		if (Target == nullptr)
			return AType::Null();

		std::shared_ptr<Type> object(Target);
		g_TypeManager.Add(object);
		return g_TypeManager.GetType(Target->GetName());
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 타입 언로드.
	/////////////////////////////////////////////////////////////////////////////
	VOID UnloadType(AType Type)
	{
		const std::wstring& typeName = Type->GetName();
		g_TypeManager.Remove(typeName);
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 클래스이름을 통해 타입 반환.
	/////////////////////////////////////////////////////////////////////////////
	AType GetType(const CHAR16 ClassName[])
	{
		return g_TypeManager.GetType(std::wstring(ClassName));
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 생성.
	/////////////////////////////////////////////////////////////////////////////
	AObject Instantiate(AType Type)
	{
		//CRC32::CreateTable();
		Object* instance = (Object*)Type->CreateInstance();
		instance->m_ObjectID = 1;
		instance->m_IsDestroying = false;
		std::shared_ptr<Object> object(instance);
		g_ObjectManager.Add(object);
		return AObject(object);
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 파괴.
	/////////////////////////////////////////////////////////////////////////////
	VOID Destroy(AObject Target)
	{
		if (AObject::IsNull(Target))
			return;

		Object* object = *Target;
		INT32 objectID = object->GetObjectID();
		if (!object->m_IsDestroying)
		{
			object->m_IsDestroying = true;
		}
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 즉시 파괴.
	/////////////////////////////////////////////////////////////////////////////
	VOID DestroyImmediate(AObject Target)
	{
		if (AObject::IsNull(Target))
			return;

		auto object = *Target;
		auto objectID = object->GetObjectID();
		g_ObjectManager.Remove(objectID);
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 파괴 여부.
	/////////////////////////////////////////////////////////////////////////////
	BOOL8 IsDestroyed(AObject Target)
	{
		if (AObject::IsNull(Target))
			return true;

		auto object = *Target;
		auto objectID = object->GetObjectID();
		auto referenceCount = g_ObjectManager.GetReferenceCount(objectID);
		return referenceCount > 0;
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 문자열 포맷.
	/////////////////////////////////////////////////////////////////////////////
	AString Format(const CHAR16 Format[], AList Arguments)
	{
		return AString::Null();
	}
	

	VOID Application::OnCreate()
	{
		Generated::Assemble();
	}

	VOID Application::OnDestroy()
	{
	}

	VOID Application::OnPause()
	{
	}

	VOID Application::OnResume()
	{
	}

	VOID Application::OnUpdate(FLOAT32 DeltaTime)
	{
	}

	VOID Application::OnDraw(AcroCore::XGL GL)
	{
	}

	VOID Application::OnResize(UINT32 Width, UINT32 Height)
	{
	}
}