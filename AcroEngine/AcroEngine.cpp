#include "AcroEngine.h"
#include "AObject.h"
#include "ADelegate.h"
#include "AcroEngineGenerated.cpp"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 오브젝트 파괴자.
	/////////////////////////////////////////////////////////////////////////////
	//struct ObjectDestroyer
	//{
	//	void operator () (ARef<Object> Object)
	//	{
	//		Destroy(Object);
	//	}
	//};


	/////////////////////////////////////////////////////////////////////////////
	// @ 해시.
	/////////////////////////////////////////////////////////////////////////////
	class CRC32
	{
	public:
		void CreateTable(uint32(&table)[256])
		{
			uint32 polynomial = 0xEDB88320;
			for (uint32 i = 0; i < 256; i++)
			{
				uint32 c = i;
				for (uint32 j = 0; j < 8; j++)
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

		uint32 ComputeHash(uint32(&table)[256], uint32 initial, const pointer buf, uint32 len)
		{
			uint32 c = initial ^ 0xFFFFFFFF;
			const uint8* u = static_cast<const uint8*>(buf);
			for (uint32 i = 0; i < len; ++i)
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
		std::map<unit64, std::shared_ptr<Object>> m_Objects;
		
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
			unit64 objectID = Object->GetObjectID();
			m_Objects.insert(std::make_pair(objectID, Object));
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ 제거.
		/////////////////////////////////////////////////////////////////////////////
		void Remove(unit64 ObjectID)
		{
			m_Objects.erase(ObjectID);
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ 모든 오브젝트 제거.
		/////////////////////////////////////////////////////////////////////////////
		void RemoveAllObjects()
		{
			std::vector<unit64> temp;
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
			std::vector<unit64> temp;
			for (auto& pair : m_Objects)
			{
				auto objectReferenceCount = pair.second.use_count() - 1;
				if (objectReferenceCount <= 1)
					temp.push_back(pair.first);
			}

			for (auto objectID : temp)
				Remove(objectID);
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ 객체 반환.
		/////////////////////////////////////////////////////////////////////////////
		std::weak_ptr<Object> GetObject(unit64 ObjectID)
		{
			auto it = m_Objects.find(ObjectID);
			if (it == m_Objects.end())
				return std::weak_ptr<Object>();
			return std::weak_ptr<Object>(it->second);
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ 참조카운트 반환.
		/////////////////////////////////////////////////////////////////////////////
		int64 GetReferenceCount(unit64 ObjectID)
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
		//std::map<std::wstring, unit64> m_CachedTypeIndices;

	public:
		TypeManager()
		{
		}

		virtual ~TypeManager()
		{
			RemoveAllTypes();
		}

		void Add(std::shared_ptr<Type> Type)
		{
			std::wstring typeName = Type->GetName();
			m_Types.insert(std::make_pair(typeName,Type));
		}

		void Remove(const std::wstring& TypeName)
		{
			m_Types.erase(TypeName);
		}

		void RemoveAllTypes()
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
	static uint32 g_CRC32Table[256] = { 0, };
	static unit64 g_IncreaseObjectID = 0;


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
	void UnloadType(AType Type)
	{
		const std::wstring& typeName = Type->GetName();
		g_TypeManager.Remove(typeName);
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 클래스이름을 통해 타입 반환.
	/////////////////////////////////////////////////////////////////////////////
	AType GetType(const char16 ClassName[])
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
		instance->m_ObjectID = ++g_IncreaseObjectID;
		instance->m_IsDestroying = false;
		std::shared_ptr<Object> object(instance);
		g_ObjectManager.Add(object);
		return AObject(object);
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 생성.
	/////////////////////////////////////////////////////////////////////////////
	AObject Instantiate(const char16 ClassName[])
	{
		AType type = GetType(ClassName);
		if (AType::IsNull(type))
			return AObject::Null();
		
		return Instantiate(type);
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 파괴.
	/////////////////////////////////////////////////////////////////////////////
	void Destroy(AObject Target)
	{
		if (AObject::IsNull(Target))
			return;

		Object* object = *Target;
		unit64 objectID = object->GetObjectID();
		if (!object->m_IsDestroying)
		{
			object->m_IsDestroying = true;
		}
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 즉시 파괴.
	/////////////////////////////////////////////////////////////////////////////
	void DestroyImmediate(AObject Target)
	{
		if (AObject::IsNull(Target))
			return;

		Object* object = *Target;
		unit64 objectID = object->GetObjectID();
		g_ObjectManager.Remove(objectID);
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 파괴 여부.
	/////////////////////////////////////////////////////////////////////////////
	bool8 IsDestroyed(AObject Target)
	{
		if (AObject::IsNull(Target))
			return true;

		Object* object = *Target;
		unit64 objectID = object->GetObjectID();
		int64 referenceCount = g_ObjectManager.GetReferenceCount(objectID);
		return referenceCount > 0;
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 문자열 포맷.
	/////////////////////////////////////////////////////////////////////////////
	AString Format(const char16 Format[], AList Arguments)
	{
		return AString::Null();
	}
	

	void Application::OnCreate()
	{
		auto assembly = new AcroEngineAssembly();
		assembly->Assemble();
		delete assembly;

		g_CRC32.CreateTable(g_CRC32Table);
		uint32 objectID = g_CRC32.ComputeHash(g_CRC32Table, 0, 0, 0);

		// usage: the following code generates crc for 2 pieces of data
		// uint32_t table[256];
		// crc32::generate_table(table);
		// uint32_t crc = crc32::update(table, 0, data_piece1, len1);
		// crc = crc32::update(table, crc, data_piece2, len2);
		// output(crc);
	}

	void Application::OnDestroy()
	{
	}

	void Application::OnPause()
	{
	}

	void Application::OnResume()
	{
	}

	void Application::OnUpdate(float32 DeltaTime)
	{
	}

	void Application::OnDraw(AcroCore::XGL GL)
	{
	}

	void Application::OnResize(uint32 Width, uint32 Height)
	{
	}
}