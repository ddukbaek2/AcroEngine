#include "AcroEngine.h"
#include "AObject.h"
#include "ADelegate.h"
#include "AcroEngineGenerated.cpp"
#define ACRO_INTERNAL


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 문자열 분리.
	/////////////////////////////////////////////////////////////////////////////
	std::vector<std::wstring> StringSplit(std::wstring text, const std::wstring& seperator)
	{
		int32 previous = 0;
		int32 current = 0;
		std::vector<std::wstring> list;
		current = text.find(seperator);
		//find는 찾을게 없으면 npos를 리턴함
		while (current != std::wstring::npos)
		{
			std::wstring substring = text.substr(previous, current - previous);
			list.push_back(substring);
			previous = current + 1;
			current = text.find(seperator, previous);
		}

		list.push_back(text.substr(previous, current - previous));
		return list;
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 오브젝트 파괴자.
	/////////////////////////////////////////////////////////////////////////////
	//struct ObjectDestroyer
	//{
	//	void operator () (TRef<Object> Object)
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
	// @ 객체 관리자.
	//	- shared_ptr을 사용하지만 실제로는 weak_ptr만 외부로 내보낸다.
	//  - 즉, 레퍼런스카운트는 내부용이다.
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
		// @ 모든 파괴된 오브젝트 제거.
		/////////////////////////////////////////////////////////////////////////////
		void RemoveAllDestroyedObject()
		{
			std::vector<unit64> temp;
			for (auto& pair : m_Objects)
			{
				if (IsDestroyed(pair.second))
					temp.push_back(pair.first);
			}

			for (auto objectID : temp)
				Remove(objectID);
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ 모든 참조되지 않는 오브젝트 제거.
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
	// @ 타입 관리자.
	//  - AcroTypeTool을 통해 자동생성된 cpp를 포함하고 이를 사용해 오브젝트의 타입을 등록한다.
	//  - 등록된 타입을 통해 RTTI 기능의 일부를 구현한다.
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
	// @ 스케쥴 관리자.
	/////////////////////////////////////////////////////////////////////////////
	class ScheduleManager
	{
	private:
		struct ScheduleInfo
		{
			AObject Target;
			std::function<void(Object*)> Event;
		};
		std::vector<ScheduleInfo> m_Schedules;

	public:
		ScheduleManager()
		{
		}

		virtual ~ScheduleManager()
		{
			m_Schedules.clear();
		}

		void Schedule(AObject Target, std::function<void(Object*)>& Event)
		{
			ScheduleInfo scheduleInfo;
			scheduleInfo.Target = Target;
			scheduleInfo.Event = Event;
			m_Schedules.push_back(scheduleInfo);
		}

		void Unschedule(std::function<void(Object*)> Event)
		{
			//std::remove(m_Schedules.begin(), m_Schedules.end(), Event);
		}

		void Update()
		{
			for (ScheduleInfo& scheduleInfo : m_Schedules)
			{
				if (AObject::IsNull(scheduleInfo.Target))
					continue;

				auto target = scheduleInfo.Target.Get();
				scheduleInfo.Event(target);
			}
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 내부 전역 변수.
	/////////////////////////////////////////////////////////////////////////////
	static ObjectManager g_ObjectManager;
	static TypeManager g_TypeManager;
	static ScheduleManager g_ScheduleManager;
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
	AType GetType(const char16 TypeName[])
	{
		//std::wstring typeName(TypeName);
		//auto list = StringSplit(TypeName, XTEXT("::"));
		//if (list.empty())
		//	return AType::Null();

		//
		//return g_TypeManager.GetType(list.back());
		return g_TypeManager.GetType(TypeName);
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 생성.
	/////////////////////////////////////////////////////////////////////////////
	AObject Instantiate(AType Type)
	{
		if (AType::IsNull(Type))
			return AObject::Null();

		Object* instance = (Object*)Type->CreateInstance();
		instance->m_ObjectID = ++g_IncreaseObjectID;
		instance->m_IsDestroying = false;
		instance->m_Type = Type;
		std::shared_ptr<Object> object(instance);
		g_ObjectManager.Add(object);
		return AObject(object);
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 생성.
	/////////////////////////////////////////////////////////////////////////////
	AObject Instantiate(const char16 ClassName[])
	{
		return Instantiate(GetType(ClassName));
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
	

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 생성.
	/////////////////////////////////////////////////////////////////////////////
	void Application::OnCreate()
	{
		auto assembly = new AcroEngineAssembly();
		assembly->Assemble();
		delete assembly;

		g_CRC32.CreateTable(g_CRC32Table);
		//uint32 objectID = g_CRC32.ComputeHash(g_CRC32Table, 0, 0, 0);

		// usage: the following code generates crc for 2 pieces of data
		// uint32_t table[256];
		// crc32::generate_table(table);
		// uint32_t crc = crc32::update(table, 0, data_piece1, len1);
		// crc = crc32::update(table, crc, data_piece2, len2);
		// output(crc);
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 파괴.
	/////////////////////////////////////////////////////////////////////////////
	void Application::OnDestroy()
	{
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 일시정지.
	/////////////////////////////////////////////////////////////////////////////
	void Application::OnPause()
	{
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 재개.
	/////////////////////////////////////////////////////////////////////////////
	void Application::OnResume()
	{
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 업데이트 시작.
	/////////////////////////////////////////////////////////////////////////////
	void Application::OnBeginUpdate()
	{
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 업데이트.
	/////////////////////////////////////////////////////////////////////////////
	void Application::OnUpdate(float32 DeltaTime)
	{
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 업데이트 종료.
	/////////////////////////////////////////////////////////////////////////////
	void Application::OnEndUpdate()
	{
		// 스케쥴 매니저 업데이트.
		g_ScheduleManager.Update();

		// 오브젝트 매니저에서 파괴된 오브젝트 제거.
		g_ObjectManager.RemoveAllDestroyedObject();
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 출력.
	/////////////////////////////////////////////////////////////////////////////
	void Application::OnDraw(AcroCore::XGL GL)
	{
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 크기 변경.
	/////////////////////////////////////////////////////////////////////////////
	void Application::OnResize(uint32 Width, uint32 Height)
	{
	}

	void Application::OnKeyPress(EKeyCode KeyCode)
	{
	}

	void Application::OnKeyRelease(EKeyCode KeyCode)
	{
	}

	void Application::OnTouchPress(uint8 Finger, float32 X, float32 Y)
	{
	}

	void Application::OnTouchDrag(uint8 Finger, float32 X, float32 Y, float32 DeltaMoveX, float32 DeltaMoveY)
	{
	}

	void Application::OnTouchRelease(uint8 Finger, float32 X, float32 Y)
	{
	}
}