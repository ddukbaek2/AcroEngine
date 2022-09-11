#include "AOwner.h"

#include "AObject.h"


AcroEngine::AOwner::AOwner()
{
	m_Target = nullptr;
}

AcroEngine::AOwner::AOwner(AcroEngine::AObject* target)
{
	m_Target = nullptr;
	SetOwner(target);
}

AcroEngine::AOwner::AOwner(const AcroEngine::AOwner* Owner)
{
	m_Target = nullptr;
	SetOwner(Owner->m_Target);
}

AcroEngine::AOwner::~AOwner()
{
	SetOwner(nullptr);
}

void AcroEngine::AOwner::SetOwner(const AObject* target)
{
	UnsetOwner();

	if (target != nullptr)
	{
		m_Target = const_cast<AObject*>(target);
		AObject::IncreaseReference(m_Target);
	}
}

void AcroEngine::AOwner::UnsetOwner()
{
	if (m_Target != nullptr)
	{
		AObject::DecreaseReference(m_Target);
		m_Target = nullptr;
	}
}

const AcroEngine::AObject* AcroEngine::AOwner::GetPtr()
{
	return m_Target;
}

const AcroEngine::AObject& AcroEngine::AOwner::GetRef()
{
	return *m_Target;
}

void AcroEngine::AOwner::operator = (AcroEngine::AObject* target)
{
	SetOwner(target);
}