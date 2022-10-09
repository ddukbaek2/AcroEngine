﻿#include "AObject.h"
#include "AType.h"
#include "AVariable.h"


namespace AcroEngine
{
    /////////////////////////////////////////////////////////////////////////////
    // @ 생성.
    /////////////////////////////////////////////////////////////////////////////
    Object::Object()
    {
        m_ObjectID = 0;
        m_IsDestroying = false;
    }

    /////////////////////////////////////////////////////////////////////////////
    // @ 소멸.
    /////////////////////////////////////////////////////////////////////////////
    Object::~Object()
    {

    }

    /////////////////////////////////////////////////////////////////////////////
    // @
    /////////////////////////////////////////////////////////////////////////////
    AString Object::ToString()
    {
        return A_INSTANTIATE(String);
    }

    /////////////////////////////////////////////////////////////////////////////
    // @
    /////////////////////////////////////////////////////////////////////////////
    BOOL8 Object::Equals(AObject Object)
    {
        if (AObject::IsNull(Object))
            return false;

        return m_ObjectID == Object->m_ObjectID;
    }

    /////////////////////////////////////////////////////////////////////////////
    // @
    /////////////////////////////////////////////////////////////////////////////
    INT32 Object::GetObjectID()
    {
        return m_ObjectID;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //// @
    ///////////////////////////////////////////////////////////////////////////////
    //Type* Object::GetType()
    //{
    //    //AClassGenerated::GetName();
    //    return nullptr;
    //}
}