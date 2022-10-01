// defined WIN32
#include "../AcroEngine/AcroEngine.h"
#include "../AcroEngine/ABoolean.h"

using namespace XPlatform;
using namespace AcroEngine;


void OnApplicationUpdate(XApplication Application)
{
    XGL GL = Application->GetGL();

    GL->Clear(IGL::EAttribMask::COLOR_BUFFER_BIT);
    GL->Flush();
    //GL->ClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    //GL->Clear(XPlatform::IGL::EAttribMask::COLOR_BUFFER_BIT);
    //GL->Flush();
}

int main()
{
    AcroEngine::LoadType(nullptr);

    // 생성.
    ABoolean Boolean = (ABoolean)AcroEngine::Instantiate(A_TYPEOF(ABoolean));

    // 에러 : 아직 Type 추론 작업이 되지 않아 기본형인 AObject로 생성함.
    //*Boolean = false;

    // 파괴.
    DestroyImmediate(Boolean);
    
    XPlatform::RunApplication(OnApplicationUpdate);
    return 0;
}