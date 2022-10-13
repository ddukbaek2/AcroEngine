#pragma once


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 전방선언.
	/////////////////////////////////////////////////////////////////////////////
	class Object;


	/////////////////////////////////////////////////////////////////////////////
	// @ 참조 오브젝트.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T = Object> class TRef
	{
	private:
		std::weak_ptr<T> m_WeakPtr;

	public:
		TRef()
		{
			m_WeakPtr = std::weak_ptr<T>();
		}

		TRef(std::shared_ptr<T> Object)
		{
			m_WeakPtr = std::weak_ptr<T>(Object);
		}

		virtual ~TRef()
		{
		}

		T* operator ->()
		{
			return Get();
		}

		operator TRef<Object>()
		{
			return Cast<Object>();
		}

		operator T()
		{
			return Get<T>();
		}

		//operator TRef<T>()
		//{
		//	return Cast<T>();
		//}

		T* operator *()
		{
			return Get();
		}

		std::shared_ptr<Object> GetSharedPointer()
		{
			if (IsNull(*this))
				return std::shared_ptr<Object>();

			return m_WeakPtr.lock();
		}

		T* Get()
		{
			if (IsNull())
				return nullptr;

			auto object = m_WeakPtr.lock();
			return (T*)object.get();
		}

		bool8 IsNull()
		{
			if (m_WeakPtr.expired())
				return true;

			return false;
		}

		void SetNull()
		{
			m_WeakPtr.reset();
		}

		template<typename TDest = Object> TDest* Get()
		{
			if (IsNull())
				return nullptr;

			auto object = Get();
			return (TDest*)object;
		}

		template<typename TDest = Object> TRef<TDest> Cast()
		{
			if (IsNull())
				return TRef<TDest>();

			auto object = GetSharedPointer();
			return TRef<TDest>(std::dynamic_pointer_cast<TDest>(object));
		}

		static bool8 IsNull(TRef<T> Target)
		{
			return Target.IsNull();
		}

		static TRef<T> Null()
		{
			return TRef<T>();
		}
	};

	template<typename T = Object, typename TDest = Object> TRef<TDest> Cast(TRef<T> Target)
	{
		return Target.Cast<TDest>();
	};

	//template<typename TDest = Object> TRef<TDest> Cast(AObject Target)
	//{
	//	return Target.Cast<TDest>();
	//}
}