#pragma once

#include "AcroEngine.h"
#include "AObject.h"


namespace AcroEngine
{
	class AVariable : public AObject
	{
	private:
	protected:
	public:

	};


	class ABoolean : public AVariable
	{
	private:
	public:
	};

	class AInt : public AVariable
	{
	private:
		XPlatform::sint32 m_Value;

	public:
		void operator = (XPlatform::sint32 value)
		{
			m_Value = value;
		}

		static AInt ToInt(const AString& String)
		{
		}
	};


	class AString : public AVariable
	{
	private:
	public:
		static AString ToString(const AInt& Int)
		{
		}
	};

	class AContainer : public AVariable
	{
	private:

	public:
		
	};

	template<typename T> class AList : public AContainer
	{
	};

	template<typename T> class ADictionary : public AContainer
	{
	};

	template<typename T> class AQueue : public AContainer
	{
	};

	template<typename T> class AStack : public AContainer
	{
	};
}