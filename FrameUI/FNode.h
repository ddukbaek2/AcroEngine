#pragma once

#include "FrameUI.h"
#include "FComponent.h"


namespace FrameUI
{
	/////////////////////////////////////////////////////////////////////////////
	// @ °èÃþ±¸Á¶.
	/////////////////////////////////////////////////////////////////////////////
	class FNode : public AObject
	{
	private:
		AVector2 m_Anchor;
		AVector2 m_Offset;
		AVector2 m_LocalPosition;
		AVector2 m_Size;
		AFloat m_Rotation;

		FNode* m_ParentNode;
		AList m_ChildNodes;

		AList m_Components;

	public:
		template<typename T = FComponent>
		T* Attach()
		{
			auto component = new T();
			m_Components.Add(component);
			return component;
		}

		void Dettach(FComponent* component)
		{
			m_Components.Remove(component);
			Destroy((AObject*)component);
		}

		inline void SetParent(const FNode* ParentNode)
		{
			if (ParentNode == nullptr)
				return;

			if (m_ParentNode != nullptr)
			{

			}

			m_ParentNode = const_cast<FNode*>(ParentNode);

			if (m_ParentNode != nullptr)
			{

			}
		}
	};
}