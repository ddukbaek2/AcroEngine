#include "AcroCore.h"


#ifdef ACROCORE_WINDOWS

//#include <SDKDDKVer.h>
//#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl/GL.h>
//#include <gl/GLU.h>

#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glu32.lib")


namespace AcroCore
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 그래픽.
	/////////////////////////////////////////////////////////////////////////////
	class Win32GL : public IGL
	{
	public:
		virtual void Clear(EAttribMask AttribMask) override { glClear((uint32)AttribMask); }
		virtual void ClearColor(float32 R, float32 G, float32 B, float32 A) override { glClearColor(R, G, B, A); }
		virtual void PushMatrix() override { glPushMatrix(); }
		virtual void MatrixMode(EMatrixMode MatrixMode) override { glMatrixMode((uint16)MatrixMode); }
		virtual void Translate(float32 X, float32 Y, float32 Z) override { glTranslatef(X, Y, Z); }
		virtual void Scale(float32 X, float32 Y, float32 Z) override { glScalef(X, Y, Z); }
		virtual void Rotate(float32 Angle, float32 X, float32 Y, float32 Z) override { glRotatef(Angle, X, Y, Z); }
		virtual void PopMatrix() override { glPopMatrix(); }
		virtual void LoadIdentity() override { glLoadIdentity(); }
		virtual void Begin(EBeginMode BeginMode) override { glBegin((uint16)BeginMode); }
		virtual void Color4(float32 R, float32 G, float32 B, float32 A) override { glColor4f(R, G, B, A); }
		virtual void Vertex3(float32 X, float32 Y, float32 Z) override { glVertex3f(X, Y, Z); }
		virtual void TexCoord2(float32 U, float32 TDest) override { glTexCoord2f(U, TDest); }
		virtual void End() override { glEnd(); }
		virtual void Flush() override { glFlush(); }
		virtual void Viewport(int32 X, int32 Y, int32 Width, int32 Height) override { glViewport(X, Y, Width, Height); }

		virtual void Enable() { glEnable(GL_TEXTURE_2D); }
		virtual void GenTextures()
		{
			uint32 textures = 0;
			glGenTextures(1, &textures);
		}

		virtual void DeleteTexture()
		{
			uint32 textures = 0;
			glDeleteTextures(1, &textures);
		}

		virtual void BindTexture(uint32 Texture) { glBindTexture(GL_TEXTURE_2D, Texture); }


		virtual void TexParameteri()
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}

		virtual void TexImage2D()
		{
			glTexImage2D(0, 0, 0, 0, 0, 0, 0, 0, 0);
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션.
	/////////////////////////////////////////////////////////////////////////////
	class Win32Application
	{
	public:
		static Win32Application* Instance;
		static ApplicationProfile Profile;

	private:
		HWND m_WindowHandle; // 현재 윈도우 핸들.
		XGL m_GL; // 현재 OpenGL.
		XApplication m_Application;
		HCURSOR m_Cursor;
		HICON m_Icon;

	private:
		/////////////////////////////////////////////////////////////////////////////
		// @ 어플리케이션 프로시저.
		/////////////////////////////////////////////////////////////////////////////
		static long __stdcall WindowProcess(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
		{
			switch (message)
			{
			case WM_CREATE:
				{
					if (Instance != nullptr && Instance->m_Application != nullptr)
					{
						Instance->m_Application->OnCreate();
						SetCursor(Instance->m_Cursor);
						//SendMessage(windowHandle, WM_SETICON, ICON_BIG, (LPARAM)Instance->m_Icon);
						//SendMessage(windowHandle, WM_SETICON, ICON_SMALL, (LPARAM)Instance->m_Icon);
					}
					break;
				}

			case WM_SETFOCUS:
				{
					if (Instance != nullptr && Instance->m_Application != nullptr)
					{
						Instance->m_Application->OnResume();
						//SetCursor(Instance->m_Cursor);
						//SendMessage(windowHandle, WM_SETICON, ICON_BIG, (LPARAM)Instance->m_Icon);
						//SendMessage(windowHandle, WM_SETICON, ICON_SMALL, (LPARAM)Instance->m_Icon);
					}
					break;
				}

			case WM_KILLFOCUS:
				{
					if (Instance != nullptr && Instance->m_Application != nullptr)
						Instance->m_Application->OnPause();
					break;
				}

			case WM_SIZE:
				{
					uint16 width = LOWORD(lParam); // minwindef.h
					uint16 height = HIWORD(lParam); // minwindef.h
					if (Instance != nullptr)
					{
						if (Instance->m_Application != nullptr)
						{
							Instance->m_Application->OnResize(width, height);
						}

						XGL gl = Instance->GetGL();
						if (gl != nullptr)
						{
							//gl->Viewport(0, 0, width, height);
							gl->Viewport(0, 0, Profile.Width, Profile.Height);
						}
					}
					break;
				}

			case WM_KEYDOWN:
				{
					if (Instance != nullptr && Instance->m_Application != nullptr)
					{
						switch (wParam)
						{
						case VK_ESCAPE:
							Instance->m_Application->OnKeyPress(IApplication::EKeyCode::Escape);
						case VK_LEFT:
							break;
						case VK_RIGHT:
							break;
						case VK_UP:
							break;
						case VK_DOWN:
							break;
						}
					};
					break;
				}

			case WM_KEYUP:
				{
					if (Instance != nullptr && Instance->m_Application != nullptr)
					{
						switch (wParam)
						{
						case VK_ESCAPE:
							Instance->m_Application->OnKeyRelease(IApplication::EKeyCode::Escape);
						case VK_LEFT:
							break;
						case VK_RIGHT:
							break;
						case VK_UP:
							break;
						case VK_DOWN:
							break;
						}
					}
					break;
				}
			//case WM_CLOSE:
			//	{
			//		DestroyWindow(windowHandle); // ==> WM_DESTROY // winuser.h
			//		//SendMessageW(windowHandle, WM_DESTROY, 0, 0);
			//		return 0;
			//	}

			//case WM_DESTROY:
			//	{
			//		if (Instance != nullptr && Instance->m_Application != nullptr)
			//			Instance->m_Application->OnDestroy();

			//		PostQuitMessage(0); // ==> WM_QUIT // winuser.h
			//		return 0;
			//	}
			}

			return DefWindowProcW(windowHandle, message, wParam, lParam); // winuser.h
		}

	public:
		Win32Application(XApplication Application)
		{
			m_WindowHandle = NULL;
			m_GL = nullptr;
			m_Application = Application;
			m_Cursor = NULL;
			m_Icon = NULL;
		}

		virtual ~Win32Application()
		{
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ 어플리케이션 실행.
		/////////////////////////////////////////////////////////////////////////////
		virtual void Run()
		{
			HINSTANCE instance = GetModuleHandleW(NULL); // libloaderapi.h
			m_Icon = LoadIconW(NULL, IDI_APPLICATION); // winuser.h
			m_Cursor = LoadCursorW(NULL, IDC_ARROW); // winuser.h

			WNDCLASSEXW windowClassEx;
			memset(&windowClassEx, 0, sizeof(WNDCLASSEX));
			windowClassEx.cbSize = sizeof(WNDCLASSEX);
			windowClassEx.lpfnWndProc = &Win32Application::WindowProcess;
			windowClassEx.hInstance = instance;
			windowClassEx.hIcon = m_Icon;
			windowClassEx.hCursor = m_Cursor;
			windowClassEx.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(191, 191, 191)); // wingdi.h
			windowClassEx.lpszClassName = Win32Application::Profile.Name;
			windowClassEx.hIconSm = m_Icon;
			RegisterClassExW(&windowClassEx); // winuser.h

			m_WindowHandle = CreateWindowExW(0L, Win32Application::Profile.Name, Win32Application::Profile.Name,
				WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
				nullptr, nullptr, instance, nullptr); // winuser.h

			if (!m_WindowHandle)
			{
				return;
			}

			// 렌더러 초기화.
			HDC deviceContext = GetDC(m_WindowHandle); // winuser.h
			PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
			memset(&pixelFormatDescriptor, 0, sizeof(PIXELFORMATDESCRIPTOR));
			pixelFormatDescriptor.nSize = sizeof(pixelFormatDescriptor);
			pixelFormatDescriptor.nVersion = 1;
			pixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
			pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
			pixelFormatDescriptor.cColorBits = 32;

			int32 pixelFormat = ChoosePixelFormat(deviceContext, &pixelFormatDescriptor); // wingdi.h
			if (pixelFormat == 0)
			{
				return;
			}

			if (!SetPixelFormat(deviceContext, pixelFormat, &pixelFormatDescriptor)) // wingdi.h
			{
				return;
			}

			DescribePixelFormat(deviceContext, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pixelFormatDescriptor); // wingdi.h
			//ReleaseDC(m_WindowHandle, deviceContext);
			//deviceContext = GetDC(m_WindowHandle);
			HGLRC renderingContext = wglCreateContext(deviceContext); // wingdi.h
			wglMakeCurrent(deviceContext, renderingContext); // wingdi.h

			m_GL = new Win32GL();
			m_GL->ClearColor(0.72f, 0.72f, 0.72f, 1.0f);

			ShowWindow(m_WindowHandle, /*SW_SHOW*/SW_SHOWMAXIMIZED); // winuser.h
			UpdateWindow(m_WindowHandle); // winuser.h

			// 메시지 루프.
			MSG msg;
			memset(&msg, 0, sizeof(MSG));
			msg.message = WM_NULL;

			while (msg.message != WM_QUIT)
			{
				if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessageW(&msg);
				}
				else
				{
					if (m_Application != nullptr)
					{
						m_Application->OnUpdate(0.0f);
						m_Application->OnDraw(m_GL);
					}
				}
			}

			//wglMakeCurrent(NULL, NULL); // wingdi.h
			//wglDeleteContext(renderingContext); // wingdi.h
			//renderingContext = nullptr;
			ReleaseDC(m_WindowHandle, deviceContext); // winuser.h

			SAFE_DELETE(m_GL);

			if (m_Application != nullptr)
				m_Application->OnDestroy();

			//return (int32)msg.wParam;
		}

	public:
		/////////////////////////////////////////////////////////////////////////////
		// @ 어플리케이션 종료.
		/////////////////////////////////////////////////////////////////////////////
		void Quit()
		{
			//CloseWindow(m_WindowHandle); // winuser.h
			//DestroyWindow(m_WindowHandle); // ==> WM_DESTROY // winuser.h
			//m_WindowHandle = 0;

			//SendMessageW(m_WindowHandle, WM_CLOSE, 0, 0);
			PostQuitMessage(0);
		}

		/////////////////////////////////////////////////////////////////////////////
		// @ OpenGL 반환.
		/////////////////////////////////////////////////////////////////////////////
		XGL GetGL()
		{
			return m_GL;
		}
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 전역 변수.
	/////////////////////////////////////////////////////////////////////////////
	Win32Application* Win32Application::Instance = nullptr;
	ApplicationProfile Win32Application::Profile;


	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 실행.
	/////////////////////////////////////////////////////////////////////////////
	void RunApplication(XApplication Application)
	{
		if (Win32Application::Instance == nullptr)
			Win32Application::Instance = new Win32Application(Application);

		Win32Application::Instance->Run();

		SAFE_DELETE(Win32Application::Instance);
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 설정.
	/////////////////////////////////////////////////////////////////////////////
	void SetApplication(const ApplicationProfile& Profile)
	{
		Win32Application::Profile = Profile;
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 종료.
	/////////////////////////////////////////////////////////////////////////////
	void QuitApplication()
	{
		if (Win32Application::Instance != nullptr)
		{
			Win32Application::Instance->Quit();
		}
	}
}

#endif