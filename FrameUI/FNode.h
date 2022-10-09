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
		AcroEngine::Vector2 m_Anchor;
		AcroEngine::Vector2 m_Offset;
		AcroEngine::Vector2 m_Position;
		AcroEngine::Vector2 m_Size;
		AcroEngine::Float m_Rotation;

		FNode m_Parent;
		AcroEngine::List m_Childs;
		AcroEngine::List m_Components;

	public:
		INode() : AcroEngine::IObject()
		{
			m_Components = A_INSTANTIATE(AcroEngine::List);
			m_Anchor = A_INSTANTIATE(AcroEngine::Vector2);
			m_Offset = A_INSTANTIATE(AcroEngine::Vector2);
			m_Position = A_INSTANTIATE(AcroEngine::Vector2);
			m_Size = A_INSTANTIATE(AcroEngine::Vector2);
			m_Rotation = A_INSTANTIATE(AcroEngine::Float);
			
			m_Parent = nullptr;
			m_Childs = A_INSTANTIATE(AcroEngine::List);
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