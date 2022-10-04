// defined WIN32
#include "../AcroEngine/AcroEngine.h"
#include "../AcroEngine/ABoolean.h"

using namespace AcroCore;
using namespace AcroEngine;


/////////////////////////////////////////////////////////////////////////////
// @ 샘플 어플리케이션.
/////////////////////////////////////////////////////////////////////////////
class Application : public IApplication
{
protected:
    virtual VOID OnCreate() override { }
    virtual VOID OnDestroy() override { }
    virtual VOID OnPause() override { }
    virtual VOID OnResume() override { }

    virtual VOID OnUpdate(FLOAT32 DeltaTime) override
    {
    }

    virtual VOID OnDraw(XGL GL) override
    {
        GL->Clear(IGL::EAttribMask::GL_COLOR_BUFFER_BIT);
        {
            GL->LoadIdentity();
            GL->Begin(IGL::EBeginMode::GL_QUADS);
            GL->Vertex3(-0.5f, -0.5f, 0.0f); // 좌하.
            GL->Color4(1.0f, 0.0f, 0.0f, 1.0f);
            GL->Vertex3(0.5f, -0.5f, 0.0f); // 우하.
            GL->Color4(1.0f, 0.0f, 1.0f, 1.0f);
            GL->Vertex3(0.5f, 0.5f, 0.0f); // 우상.
            GL->Color4(1.0f, 0.0f, 0.0f, 1.0f);
            GL->Vertex3(-0.5f, 0.5f, 0.0f); // 좌상.
            GL->Color4(1.0f, 1.0f, 0.0f, 1.0f);
            GL->End();
        }
        GL->Flush();
    }

    virtual VOID OnResize(UINT32 Width, UINT32 Height) override
    {
        int a = 0;
    }
};


/////////////////////////////////////////////////////////////////////////////
// @ 진입점.
/////////////////////////////////////////////////////////////////////////////
int main()
{
    AcroEngine::LoadType(nullptr);

    // 생성.
    ABoolean Boolean = (ABoolean)AcroEngine::Instantiate(A_TYPEOF(ABoolean));

    // 에러 : 아직 Type 추론 작업이 되지 않아 기본형인 AObject로 생성함.
    //*Boolean = false;

    // 파괴.
    AcroEngine::DestroyImmediate(Boolean);
    
    // 어플리케이션 실행.
    Application application;
    AcroCore::RunApplication(&application);
    return 0;
}