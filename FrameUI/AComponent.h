#pragma once

#include "FrameUI.h"


namespace FrameUI
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 각 계층에서 사용될 기본요소.
	/////////////////////////////////////////////////////////////////////////////
	class Component : public AcroEngine::Object
	{
	private:
	protected:
		virtual void OnAttached() = 0;
		virtual void OnDettached() = 0;
		virtual void OnUpdate(AcroEngine::Float deltaTime) = 0;
	public:

	};
}