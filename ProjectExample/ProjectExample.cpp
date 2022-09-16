#define XPLATFORM_WINDOWS
#include "../AcroEngine/AcroEngine.h"
#include "../AcroEngine/ABoolean.h"
using namespace XPlatform;
using namespace AcroEngine;


int main()
{
    ABoolean Boolean = (ABoolean)Instantiate(A_TYPEOF(ABoolean));

    *Boolean = false;

    DestroyImmediate(Boolean);
    
    return 0;
}