#pragma once

#include "AcroEngine.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ ¾×¼Ç.
	/////////////////////////////////////////////////////////////////////////////
	template<typename TObject> class TAction
	{
	public:
		ACTION(FOnAction, const TObject*);

	private:
		TObject* m_Instance;
		OnAction m_OnAction;

	public:
		TAction(TObject* Instance, FOnAction OnAction)
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
				(m_Instance->*OnAction)(m_Instance);
		}
	};
}