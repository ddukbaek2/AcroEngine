#pragma once

#include "AcroEngine.h"
#include "AObject.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 전방선언.
	/////////////////////////////////////////////////////////////////////////////
	class AType;
	class AObject;
	class AInt;
	class AString;

	//class AFlag : public AObject
	//{
	//};

	//class AEnum : public AObject
	//{
	//};

	/////////////////////////////////////////////////////////////////////////////
	// @ 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AVariable : public AObject
	{
		GENERATE_BASE(AVariable, AObject)
		GENERATE_TYPE(AVariable)

	private:
	protected:
	public:
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 정수.
	/////////////////////////////////////////////////////////////////////////////
	class Number : public AVariable
	{
	public:

	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 논리형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class ABoolean : public AVariable
	{
		GENERATE_BASE(ABoolean, AVariable)
		GENERATE_TYPE(ABoolean)

	private:
		XPlatform::BOOL m_Value;

	public:
		ABoolean() : Base()
		{
			m_Value = false;
		}

		void operator = (XPlatform::BOOL& Value)
		{
			m_Value = Value;
		}

		operator XPlatform::BOOL& ()
		{
			return m_Value;
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 정수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AInt : public AVariable
	{
	private:
		XPlatform::INT32 m_Value;

	public:
		void operator = (XPlatform::INT32& Value)
		{
			m_Value = Value;
		}

		operator XPlatform::INT32& ()
		{
			return m_Value;
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 정수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AUInt : public AVariable
	{
	private:
		XPlatform::UINT32 m_Value;

	public:
		void operator = (XPlatform::UINT32& Value)
		{
			m_Value = Value;
		}

		operator XPlatform::UINT32& ()
		{
			return m_Value;
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 정수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AShort : public AVariable
	{
	private:
		XPlatform::INT16 m_Value;

	public:
		void operator = (XPlatform::INT16& Value)
		{
			m_Value = Value;
		}

		operator XPlatform::INT16& ()
		{
			return m_Value;
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 문자열형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AString : public AVariable
	{
	private:
		XPlatform::TAllocator<XPlatform::CHAR16> m_Value;

	public:
		AString()
		{
			m_Value.Clear();
		}

		AString(XPlatform::CHAR16* Value)
		{
			m_Value.Clear();
			m_Value.Resize(sizeof(Value));
			for (XPlatform::INT32 i = 0; i < m_Value.GetSize(); ++i)
			{
				m_Value.SetValue(i, Value[i]);
			}
		}

		~AString()
		{
			m_Value.Clear();
		}

	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 실수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AFloat : public AVariable
	{
	private:
		XPlatform::FLOAT32 m_Value;

	public:
		void operator = (XPlatform::FLOAT32& Value)
		{
			m_Value = Value;
		}

		operator XPlatform::FLOAT32& ()
		{
			return m_Value;
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 실수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class ADouble : public AVariable
	{
	private:
		XPlatform::FLOAT64 m_Value;

	public:
		void operator = (XPlatform::FLOAT64& Value)
		{
			m_Value = Value;
		}

		operator XPlatform::FLOAT64& ()
		{
			return m_Value;
		}
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 이차원 벡터 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AVector2 : public AVariable
	{
	private:
		XPlatform::FLOAT64 m_Values[2];

	public:
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 삼차원 벡터 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AVector3 : public AVariable
	{
	private:
		XPlatform::FLOAT64 m_Values[3];

	public:
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 사차원 벡터 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AVector4 : public AVariable
	{
	private:
		XPlatform::FLOAT64 m_Values[4];

	public:
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 사차원 벡터 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AVector4 : public AVariable
	{
	private:
		XPlatform::FLOAT64 m_Values[4];

	public:
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 자료구조형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class ACollection : public AVariable//, ICollection, IEnumerator, IEnumerable
	{
		GENERATE_BASE(ACollection, AVariable)
	private:
	public:
		//virtual void Reset() override
		//{

		//}

		//virtual bool MoveNext() override
		//{
		//	return true;
		//}

		//virtual const AObject* GetCurrent() override
		//{
		//	return nullptr;
		//}

		//virtual const IEnumerator* GetEnumerator() override
		//{
		//	return nullptr;
		//}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 리스트 형.
	/////////////////////////////////////////////////////////////////////////////
	class AList : public ACollection
	{
		GENERATE_BASE(AList, ACollection)

	private:
		XPlatform::TAllocator<AObject> m_Allocator;
		XPlatform::INT32 m_Count;

	public:
		AList() : Base()
		{
			m_Allocator.Clear();
			m_Count = 0;
		}

		AList(AInt& Capacity) : This()
		{
			m_Allocator.Resize(Capacity);
		}

		void Add(AObject* Object)
		{			
			auto size = m_Allocator.GetSize();
			if (size == 0)
			{
				m_Allocator.Resize(2);
			}
			else if (m_Count + 1 >= size)
			{
				size = size * 2;
				m_Allocator.Resize(size * 2);
			}

			++m_Count;
			m_Allocator.SetValuePointer(m_Count++, Object);
		}

		void Insert(AInt Index, AObject* Object)
		{
		}

		void Remove(AObject* Object)
		{

		}



		void RemoveAt(XPlatform::INT32 Index)
		{
			//m_Allocator.SetValue(Index, nullptr);
			m_Allocator.Decrease(Index);
		}

		bool Contains()
		{
			return false;
		}

		XPlatform::INT32 GetCount()
		{
			return m_Count;
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 딕셔너리 형.
	/////////////////////////////////////////////////////////////////////////////
	class ADictionary : public ACollection
	{
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 큐 형.
	/////////////////////////////////////////////////////////////////////////////
	class AQueue : public ACollection
	{
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 스택 형.
	/////////////////////////////////////////////////////////////////////////////
	class AStack : public ACollection
	{
	};

	class ASet : public ACollection
	{
	};
}