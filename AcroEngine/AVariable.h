﻿#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	class AFlag : public AObject
	{
	};

	class AEnum : public AObject
	{
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AVariable : public AObject
	{
		GENERATE_BASE(AObject)
		GENERATE_TYPE(AObject)

	private:
	protected:
	public:
		AVariable() : Base()
		{
		}

		void Foo() {}
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 논리형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class ABoolean : public AVariable
	{
		GENERATE_BASE(AVariable)
		GENERATE_TYPE(AVariable)

	private:
		XPlatform::BOOL m_Value;

	public:
		ABoolean()
		{
			Base::Foo();
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
		void operator = (XPlatform::INT32 value)
		{
			m_Value = value;
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
		void operator = (XPlatform::UINT32 value)
		{
			m_Value = value;
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 문자열형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AString : public AVariable
	{
	private:
	public:
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 실수형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AFloat : public AVariable
	{
	private:
		XPlatform::FLOAT64 m_Value;

	public:
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 문자열형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class AVector2 : public AVariable
	{
	private:
		XPlatform::FLOAT64 m_Values[2];

	public:
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 자료구조형 변수.
	/////////////////////////////////////////////////////////////////////////////
	class ACollection : public AVariable//, ICollection, IEnumerator, IEnumerable
	{
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