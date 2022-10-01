// defined WIN32
#include "../AcroEngine/AcroEngine.h"
#include "../AcroEngine/ABoolean.h"

using namespace XPlatform;
using namespace AcroEngine;

/////////////////////////////////////////////////////////////////////////////
// @ 어플리케이션 업데이트.
/////////////////////////////////////////////////////////////////////////////
void OnApplicationUpdate(XApplication Application)
{
    XGL GL = Application->GetGL();
    GL->Clear(IGL::EAttribMask::COLOR_BUFFER_BIT);
    GL->Flush();
}


/////////////////////////////////////////////////////////////////////////////
// @ 윈도우 메인.
/////////////////////////////////////////////////////////////////////////////
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