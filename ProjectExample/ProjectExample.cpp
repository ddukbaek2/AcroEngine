// defined WIN32
#include "../AcroEngine/AcroEngine.h"
#include "../AcroEngine/ABoolean.h"

using namespace AcroEngine;


/////////////////////////////////////////////////////////////////////////////
// @ 샘플 어플리케이션.
/////////////////////////////////////////////////////////////////////////////
class ProjectExampleApplication : public Application
{
protected:
    virtual VOID OnCreate() override
    {
        Application::OnCreate();

        // 생성.
        auto type = A_TYPEOF(Boolean);
        auto object = AcroEngine::Instantiate(type);
        auto value = AcroEngine::Cast<Object, Boolean>(object);

        // 에러 : 아직 Type 추론 작업이 되지 않아 기본형인 AObject로 생성함.
        //*Boolean = false;

        // 파괴.
        AcroEngine::DestroyImmediate(AcroEngine::Cast<Boolean, Object>(value));
    }

    virtual VOID OnUpdate(FLOAT32 DeltaTime) override
    {
        Application::OnUpdate(DeltaTime);
    }

    virtual VOID OnDraw(AcroCore::XGL GL) override
    {
        Application::OnDraw(GL);

        GL->Clear(AcroCore::IGL::EAttribMask::GL_COLOR_BUFFER_BIT);
        {
            GL->LoadIdentity();
            GL->Begin(AcroCore::IGL::EBeginMode::GL_QUADS);
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
        Application::OnResize(Width, Height);
    }
};


/////////////////////////////////////////////////////////////////////////////
// @ 진입점.
/////////////////////////////////////////////////////////////////////////////
int main()
{    
    // 어플리케이션 실행.
    ProjectExampleApplication application;
    AcroCore::RunApplication(&application);
    return 0;
}