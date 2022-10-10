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
    virtual void OnCreate() override
    {
        Application::OnCreate();

        // 생성.
        auto object = AcroEngine::Instantiate(TEXT("Boolean"));
        auto value = object.Get<Boolean>();
        *value = true;
        //value.SetValue(true);
         
        // 파괴.
        AcroEngine::DestroyImmediate(object);
    }

    virtual void OnUpdate(float32 DeltaTime) override
    {
        Application::OnUpdate(DeltaTime);
    }

    virtual void OnDraw(AcroCore::XGL GL) override
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

    virtual void OnResize(uint32 Width, uint32 Height) override
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