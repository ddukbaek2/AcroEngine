#pragma once


//#include "../AcroCore/AcroCore.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ ¾×¼Ç.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T> class TAction
	{
	public:
		ACTION_WITH_PARAM(FOnAction, const T*);

	private:
		T* m_Instance;
		FOnAction m_OnAction;

	public:
		TAction(T* Instance, FOnAction OnAction)
		{
			m_Instance = Instance;
			m_OnAction = OnAction;
		}

		virtual ~TAction()
		{
		}

		void Execute()
		{
			if (m_Instance != nullptr)
				(m_Instance->*m_OnAction)(m_Instance);
		}
	};
}