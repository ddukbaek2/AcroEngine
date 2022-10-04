#pragma once

#include "FrameUI.h"
#include "FComponent.h"


namespace FrameUI
{
	/////////////////////////////////////////////////////////////////////////////
	// @ °èÃþ±¸Á¶.
	/////////////////////////////////////////////////////////////////////////////
	class INode : public AcroEngine::IObject
	{
	private:
		AcroEngine::AVector2 m_Anchor;
		AcroEngine::AVector2 m_Offset;
		AcroEngine::AVector2 m_Position;
		AcroEngine::AVector2 m_Size;
		AcroEngine::AFloat m_Rotation;

		FNode m_Parent;
		AcroEngine::AList m_Childs;
		AcroEngine::AList m_Components;

	public:
		INode() : AcroEngine::IObject()
		{
			m_Components = A_INSTANTIATE(AcroEngine::AList);
			m_Anchor = A_INSTANTIATE(AcroEngine::AVector2);
			m_Offset = A_INSTANTIATE(AcroEngine::AVector2);
			m_Position = A_INSTANTIATE(AcroEngine::AVector2);
			m_Size = A_INSTANTIATE(AcroEngine::AVector2);
			m_Rotation = A_INSTANTIATE(AcroEngine::AFloat);
			
			m_Parent = nullptr;
			m_Childs = A_INSTANTIATE(AcroEngine::AList);
		}

		virtual ~INode()
		{
			A_DESTROYIMMEDIATE(m_Components);
			A_DESTROYIMMEDIATE(m_Anchor);
			A_DESTROYIMMEDIATE(m_Offset);
			A_DESTROYIMMEDIATE(m_Position);
			A_DESTROYIMMEDIATE(m_Size);
			A_DESTROYIMMEDIATE(m_Rotation);
			A_DESTROYIMMEDIATE(m_Childs);
		}

		void AddComponent(FComponent Component)
		{
			m_Components->Add(Component);
		}

		void RemoveComponent(FComponent Component)
		{
			m_Components->Remove(Component);
			AcroEngine::Destroy(Component);
		}

		FComponent GetComponent(AcroCore::UINT32 Index)
		{
			return (FComponent)m_Components->Find(Index);
		}

		void SetParent(FNode Parent)
		{
			if (m_Parent != nullptr)
			{

			}

			m_Parent = Parent;

			if (m_Parent != nullptr)
			{

			}
		}
	};
}