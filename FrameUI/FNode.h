#pragma once

#include "FrameUI.h"


namespace FrameUI
{
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

	public:
		void SetParent(const FNode* ParentNode)
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