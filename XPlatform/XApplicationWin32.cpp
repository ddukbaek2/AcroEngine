#ifdef WIN32

#include "XPlatform.h"

#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")


namespace XPlatform
{
    /////////////////////////////////////////////////////////////////////////////
    // @ 전역변수.
    /////////////////////////////////////////////////////////////////////////////
    wchar_t g_szTitle[128] = TEXT(""); // 제목 표시줄 텍스트입니다.
    wchar_t g_szWindowClass[128] = TEXT("WINDOW"); // 기본 창 클래스 이름입니다.


    /////////////////////////////////////////////////////////////////////////////
    // @ 그래픽.
    /////////////////////////////////////////////////////////////////////////////
    class Win32GL : public IGL
    {
    public:
        virtual VOID Clear(EAttribMask AttribMask) override { glClear((UINT32)AttribMask); }
        virtual VOID ClearColor(FLOAT32 R, FLOAT32 G, FLOAT32 B, FLOAT32 A) override { glClearColor(R, G, B, A); }
        virtual VOID PushMatrix() override { glPushMatrix(); }
        virtual VOID MatrixMode(EMatrixMode MatrixMode) override { glMatrixMode((UINT16)MatrixMode); }
        virtual VOID Translate(FLOAT32 X, FLOAT32 Y, FLOAT32 Z) override { glTranslatef(X, Y, Z); }
        virtual VOID Scale(FLOAT32 X, FLOAT32 Y, FLOAT32 Z) override { glScalef(X, Y, Z); }
        virtual VOID Rotate(FLOAT32 Angle, FLOAT32 X, FLOAT32 Y, FLOAT32 Z) override { glRotatef(Angle, X, Y, Z); }
        virtual VOID PopMatrix() override { glPopMatrix(); }
        virtual VOID LoadIdentity() override { glLoadIdentity(); }
        virtual VOID Begin(EBeginMode BeginMode) override { glBegin((UINT16)BeginMode); }
        virtual VOID Color4(FLOAT32 R, FLOAT32 G, FLOAT32 B, FLOAT32 A) override { glColor4f(R, G, B, A); }
        virtual VOID Vertex3(FLOAT32 X, FLOAT32 Y, FLOAT32 Z) override { glVertex3f(X, Y, Z); }
        virtual VOID TexCoord2(FLOAT32 U, FLOAT32 V) override { glTexCoord2f(U, V); }
        virtual VOID End() override { glEnd(); }
        virtual VOID Flush() override { glFlush(); }
        virtual VOID Viewport(INT32 X, INT32 Y, INT32 Width, INT32 Height) override { glViewport(X, Y, Width, Height); }

        virtual VOID Enable() { glEnable(GL_TEXTURE_2D); }
        virtual VOID GenTextures()
        {
            UINT32 textures = 0;
            glGenTextures(1, &textures);
        }

        virtual void DeleteTexture()
        {
            UINT32 textures = 0;
            glDeleteTextures(1, &textures);
        }

        virtual VOID BindTexture(UINT32 Texture) { glBindTexture(GL_TEXTURE_2D, Texture); }


        virtual VOID TexParameteri()
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        }

        virtual VOID TexImage2D()
        {
            glTexImage2D(0, 0, 0, 0, 0, 0, 0, 0, 0);
        }
    };


    /////////////////////////////////////////////////////////////////////////////
    // @ 어플리케이션.
    /////////////////////////////////////////////////////////////////////////////
    class Win32Application : public IApplication
    {
    public:
        static Win32Application* Instance;

    private:
        HWND m_WindowHandle; // 현재 윈도우 핸들.
        XApplicationState m_State; // 현재 상태.
        XGL m_GL; // 현재 OpenGL.

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
                Instance->SetState(XApplicationState::OnCreate);
                break;
            }

            case WM_SETFOCUS:
            {
                Instance->SetState(XApplicationState::OnResume);
                break;
            }

            case WM_KILLFOCUS:
            {
                Instance->SetState(XApplicationState::OnPause);
                break;
            }

            case WM_SIZE:
            {
                XGL gl = Instance->GetGL();
                if (gl != nullptr)
                    gl->Viewport(0, 0, LOWORD(lParam), HIWORD(lParam));
                break;
            }

            case WM_CLOSE:
            {
                DestroyWindow(windowHandle); // WM_DESTROY // winuser.h
                break;
            }

            case WM_DESTROY:
            {
                Instance->SetState(XApplicationState::OnDestroy);
                PostQuitMessage(0); // WM_QUIT // winuser.h
                break;
            }
            }

            return DefWindowProcW(windowHandle, message, wParam, lParam); // winuser.h
        }

    public:
        Win32Application()
        {
            m_WindowHandle = 0;
            m_State = XApplicationState::Invalid;
            m_GL = nullptr;
        }

        virtual ~Win32Application()
        {
        }

        /////////////////////////////////////////////////////////////////////////////
        // @ 어플리케이션 실행.
        /////////////////////////////////////////////////////////////////////////////
        virtual VOID Run(IApplication::FOnApplicationUpdate OnApplicationUpdate) override
        {
            HINSTANCE instance = GetModuleHandle(NULL);

            // 전역 문자열을 초기화합니다.
            //LoadStringW(Instance, IDS_APP_TITLE, g_szTitle, MAX_LOADSTRING);
            //LoadStringW(Instance, IDC_ACROEDITOR, g_szWindowClass, MAX_LOADSTRING);
            WNDCLASSEXW wcex;
            wcex.cbSize = sizeof(WNDCLASSEX);
            wcex.style = CS_HREDRAW | CS_VREDRAW;
            wcex.lpfnWndProc = &Win32Application::WindowProcess;
            wcex.cbClsExtra = 0;
            wcex.cbWndExtra = 0;
            wcex.hInstance = instance;
            wcex.hIcon = 0;// LoadIconW(Instance, MAKEINTRESOURCE(IDI_ACROEDITOR));
            wcex.hCursor = 0; // LoadCursor(nullptr, IDC_ARROW);
            wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
            wcex.lpszMenuName = 0;// MAKEINTRESOURCEW(IDC_ACROEDITOR);
            wcex.lpszClassName = g_szWindowClass;
            wcex.hIconSm = 0;// LoadIcon(Instance, MAKEINTRESOURCE(IDI_SMALL));
            RegisterClassExW(&wcex); // winuser.h

            m_WindowHandle = CreateWindowExW(0L, g_szWindowClass, g_szTitle,
                WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP | WS_MAXIMIZE,
                CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                nullptr, nullptr, instance, nullptr); // winuser.h

            if (!m_WindowHandle)
            {
                //return FALSE;
                return;
            }

            // 렌더러 초기화.
            HDC deviceContext = GetDC(m_WindowHandle); // winuser.h

            PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
            memset(&pixelFormatDescriptor, 0, sizeof(pixelFormatDescriptor));
            pixelFormatDescriptor.nSize = sizeof(pixelFormatDescriptor);
            pixelFormatDescriptor.nVersion = 1;
            pixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
            pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
            pixelFormatDescriptor.cColorBits = 32;

            INT32 pixelFormat = ChoosePixelFormat(deviceContext, &pixelFormatDescriptor); // wingdi.h
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

            ShowWindow(m_WindowHandle, SW_SHOW); // winuser.h
            UpdateWindow(m_WindowHandle); // winuser.h

            // 메시지 루프.
            MSG msg;
            BOOL8 isApplicationQuit = false;
            while (!isApplicationQuit)
            {
                if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
                {
                    if (msg.message == WM_QUIT)
                    {
                        isApplicationQuit = true;
                    }
                    else
                    {
                        TranslateMessage(&msg);
                        DispatchMessageW(&msg);
                    }
                }
                else
                {
                    if (OnApplicationUpdate != nullptr)
                        OnApplicationUpdate(this);
                }
            }

            wglMakeCurrent(NULL, NULL); // wingdi.h
            ReleaseDC(m_WindowHandle, deviceContext); // winuser.h
            wglDeleteContext(renderingContext); // wingdi.h

            if (m_GL != nullptr)
            {
                delete m_GL;
                m_GL = nullptr;
            }

            //return (INT32)msg.wParam;
        }

    private:
        /////////////////////////////////////////////////////////////////////////////
        // @ 어플리케이션 상태.
        /////////////////////////////////////////////////////////////////////////////
        VOID SetState(XApplicationState State)
        {
            m_State = State;
        }
    public:
        /////////////////////////////////////////////////////////////////////////////
        // @ 어플리케이션 상태.
        /////////////////////////////////////////////////////////////////////////////
        virtual XApplicationState GeState() override
        {
            return m_State;
        }

        /////////////////////////////////////////////////////////////////////////////
        // @ 어플리케이션 종료.
        /////////////////////////////////////////////////////////////////////////////
        virtual VOID Quit() override
        {
            if (m_WindowHandle != 0)
            {
                CloseWindow(m_WindowHandle); // winuser.h
                m_WindowHandle = 0;
            }
        }

        /////////////////////////////////////////////////////////////////////////////
        // @ OpenGL 반환.
        /////////////////////////////////////////////////////////////////////////////
        virtual XGL GetGL() override
        {
            return m_GL;
        }
    };

    Win32Application* Win32Application::Instance = nullptr;


    VOID RunApplication(IApplication::FOnApplicationUpdate OnApplicationUpdate)
    {
        if (Win32Application::Instance == nullptr)
            Win32Application::Instance = new Win32Application();

        Win32Application::Instance->Run(OnApplicationUpdate);
        //Win32Application::Instance->Quit();

        if (Win32Application::Instance != nullptr)
        {
            delete Win32Application::Instance;
            Win32Application::Instance = nullptr;
        }
    }
}

#endif