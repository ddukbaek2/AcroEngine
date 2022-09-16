#include "../AcroEngine/AcroEngine.h"
#include "../AcroEngine/ABoolean.h"


namespace AcroEngine
{
    int main()
    {
        ABoolean Boolean = (ABoolean)Instantiate(A_TYPEOF(ABoolean));

        DestroyImmediate(Boolean);

        return 0;
    }
}