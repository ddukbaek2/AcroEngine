// defined WIN32
#include "../AcroEngine/AcroEngine.h"
#include "../AcroEngine/ABoolean.h"

using namespace AcroEngine;

class Player : public Object
{
public:
};

class LazyLoader : public Object
{
public:
};


/////////////////////////////////////////////////////////////////////////////
// @ 샘플 어플리케이션.
/////////////////////////////////////////////////////////////////////////////
class ProjectExampleApplication : public Application
{
protected:
	//DECLARE_PROPERTY(int32)
	class CountProperty : public TProperty<int32> {
	public:
		virtual int32& Get() override {
			return m_Value;
		}
	};

	CountProperty m_Count;

protected:
	virtual void OnCreate() override
	{
		Application::OnCreate();

		m_Count.Get();
		m_Count.Set(5);

		// 생성.
		/*auto object = AcroEngine::Instantiate(XTEXT("Boolean"));*/
		auto object = AcroEngine::Instantiate<Boolean>();
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

	virtual void OnKeyPress(AcroCore::IApplication::EKeyCode KeyCode)
	{
		Application::OnKeyPress(KeyCode);

		if (KeyCode == AcroCore::IApplication::EKeyCode::Escape)
		{
			AcroCore::QuitApplication();
		}
	}
};


/////////////////////////////////////////////////////////////////////////////
// @ 진입점.
/////////////////////////////////////////////////////////////////////////////
#ifdef WIN32
#include <Windows.h> // SUBSYSTEM:WINDOWS
int __stdcall wWinMain(HINSTANCE, HINSTANCE, char16*, int32)
#else
int main() // SUBSYSTEM:CONSOLE
#endif
{    
	// 어플리케이션 실행.
	ProjectExampleApplication application;
	AcroCore::RunApplication(&application);
	return 0;
}