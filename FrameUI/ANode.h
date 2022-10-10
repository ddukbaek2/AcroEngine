#pragma once

#include "FrameUI.h"
#include "AComponent.h"


namespace FrameUI
{
	/////////////////////////////////////////////////////////////////////////////
	// @ °èÃþ±¸Á¶.
	/////////////////////////////////////////////////////////////////////////////
	class Node : public AcroEngine::Object
	{
	protected:
		AcroEngine::AVector2 m_Anchor;
		AcroEngine::AVector2 m_Offset;
		AcroEngine::AVector2 m_Position;
		AcroEngine::AVector2 m_Size;
		AcroEngine::AFloat m_Rotation;
		ANode m_Parent;
		AcroEngine::AList m_Childs;
		AcroEngine::AList m_Components;

	public:
		Node() : AcroEngine::Object()
		{
			m_Anchor = AcroEngine::Instantiate<AcroEngine::Vector2>(TEXT("Vector2"));
			m_Offset = AcroEngine::Instantiate<AcroEngine::Vector2>(TEXT("Vector2"));
			m_Position = AcroEngine::Instantiate<AcroEngine::Vector2>(TEXT("Vector2"));
			m_Size = AcroEngine::Instantiate<AcroEngine::Vector2>(TEXT("Vector2"));
			m_Rotation = AcroEngine::Instantiate<AcroEngine::Float>(TEXT("Float"));
			
			m_Parent.Empty();
			m_Childs = AcroEngine::Instantiate<AcroEngine::List>(TEXT("List"));
			m_Components = AcroEngine::Instantiate<AcroEngine::List>(TEXT("List"));
		}

		virtual ~Node()
		{
			A_DESTROY(m_Components);
			A_DESTROY(m_Anchor);
			A_DESTROY(m_Offset);
			A_DESTROY(m_Position);
			A_DESTROY(m_Size);
			A_DESTROY(m_Rotation);
			A_DESTROY(m_Childs);
		}

		template<typename T = Component> void AddComponent(AcroEngine::ARef<T> Component)
		{
			if (m_Components.IsNull())
				return;

			m_Components->Add(Component.Cast<Object>());
		}

		template<typename T = Component> void RemoveComponent(AcroEngine::ARef<T> Component)
		{
			if (m_Components.IsNull())
				return;

			m_Components->Remove(Component.Cast<Object>();
			AcroEngine::Destroy(Component);
		}

		template<typename T = Component> T GetComponent()
		{
			if (m_Components.IsNull())
				return AcroEngine::ARef<T>::Null();

			//AcroEngine::GetType(T);
			//m_Components->GetObject()
			return (AComponent)m_Components->Find(Index);
		}

		void SetParent(ANode Parent)
		{
			if (!m_Parent.IsNull())
			{

			}

			m_Parent = Parent;

			if (!m_Parent.IsNull())
			{

			}
		}
	};
}