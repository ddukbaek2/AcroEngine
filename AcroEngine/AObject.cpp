#include "AObject.h"
#include "AVariable.h"


namespace AcroEngine
{
    AString AObject::ToString()
    {
        return AString();
    }
    AObject* AObject::CreateObject(AClass* Class)
    {
        return nullptr;
    }

    void AObject::DestroyObject(AObject* Object)
    {

    }

    AClass* AObject::GetClass()
    {
        return nullptr;
    }
}