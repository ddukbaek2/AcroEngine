#include "AOwner.h"


AcroEngine::IOwner::IOwner()
{
	m_Target = nullptr;
}

AcroEngine::IOwner::IOwner(AcroEngine::AObject target)
{
	m_Target = nullptr;
	SetOwner(target);
}

AcroEngine::IOwner::IOwner(AcroEngine::AOwner Owner)
{
	m_Target = nullptr;
	SetOwner(Owner->m_Target);
}

AcroEngine::IOwner::~IOwner()
{
	UnsetOwner();
}

void AcroEngine::IOwner::SetOwner(AObject target)
{
	UnsetOwner();

	if (target != nullptr)
	{
		m_Target = const_cast<AObject>(target);
		IObject::IncreaseReference(m_Target);
	}
}

void AcroEngine::IOwner::UnsetOwner()
{
	if (m_Target != nullptr)
	{
		IObject::DecreaseReference(m_Target);
		m_Target = nullptr;
	}
}

AcroEngine::AObject AcroEngine::IOwner::GetObject()
{
	return m_Target;
}

void AcroEngine::IOwner::operator = (AcroEngine::AObject target)
{
	SetOwner(target);
}

AcroEngine::IOwner::operator AObject()
{
	return m_Target;
}

bool AcroEngine::IOwner::IsValid()
{
	return m_Target != nullptr;
}
