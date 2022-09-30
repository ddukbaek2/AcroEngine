#ifdef WIN32

#include "XPlatform.h"

#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

//#include <stdlib.h>
//#include <malloc.h>
//#include <memory.h>
//#include <tchar.h>


namespace XPlatform
{
    /////////////////////////////////////////////////////////////////////////////
    // @ 전역변수.
    /////////////////////////////////////////////////////////////////////////////
    HINSTANCE g_Instance; // 현재 인스턴스.
    HWND g_WindowHandle;
    XApplicationState g_ApplicationState = XApplicationState::Invalid;
    IOpenGL* g_OpenGL = nullptr;
    wchar_t g_szTitle[128] = TEXT(""); // 제목 표시줄 텍스트입니다.
    wchar_t g_szWindowClass[128] = TEXT("WINDOW");             // 기본 창 클래스 이름입니다.

    /////////////////////////////////////////////////////////////////////////////
    // @ 함수 전방선언
    /////////////////////////////////////////////////////////////////////////////
    long __stdcall WindowProcess(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);

    //INT32 __stdcall wWinMain(HINSTANCE Instance, HINSTANCE PrevInstance, wchar_t Argv[], _In_ INT32 ShowCommand)
    //{
    //    UNREFERENCED_PARAMETER(PrevInstance);
    //    UNREFERENCED_PARAMETER(Argv);

    //    // 전역 문자열을 초기화합니다.
    //    //LoadStringW(Instance, IDS_APP_TITLE, g_szTitle, MAX_LOADSTRING);
    //    //LoadStringW(Instance, IDC_ACROEDITOR, g_szWindowClass, MAX_LOADSTRING);
    //    WNDCLASSEXW wcex;
    //    wcex.cbSize = sizeof(WNDCLASSEX);
    //    wcex.style = CS_HREDRAW | CS_VREDRAW;
    //    wcex.lpfnWndProc = WindowProcess;
    //    wcex.cbClsExtra = 0;
    //    wcex.cbWndExtra = 0;
    //    wcex.hInstance = Instance;
    //    wcex.hIcon = 0;// LoadIconW(Instance, MAKEINTRESOURCE(IDI_ACROEDITOR));
    //    wcex.hCursor = 0; // LoadCursor(nullptr, IDC_ARROW);
    //    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    //    wcex.lpszMenuName = 0;// MAKEINTRESOURCEW(IDC_ACROEDITOR);
    //    wcex.lpszClassName = g_szWindowClass;
    //    wcex.hIconSm = 0;// LoadIcon(Instance, MAKEINTRESOURCE(IDI_SMALL));
    //    RegisterClassExW(&wcex);

    //    g_Instance = Instance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    //    HWND windowHandle = CreateWindowExW(0L, g_szWindowClass, g_szTitle, WS_OVERLAPPEDWINDOW,
    //        CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, nullptr, nullptr, Instance, nullptr);

    //    if (!windowHandle)
    //    {
    //        return FALSE;
    //    }

    //    ShowWindow(windowHandle, ShowCommand);
    //    UpdateWindow(windowHandle);

    //    return TRUE;

    //    HACCEL hAccelTable = nullptr;// LoadAccelerators(Instance, MAKEINTRESOURCE(IDC_ACROEDITOR));
    //    MSG msg;

    //    // 기본 메시지 루프입니다:
    //    //while (GetMessage(&msg, nullptr, 0, 0))
    //    //{
    //    //    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
    //    //    {
    //    //        TranslateMessage(&msg);
    //    //        DispatchMessage(&msg);
    //    //    }
    //    //}

    //    BOOL8 isApplicationQuit = false;
    //    while (!isApplicationQuit)
    //    {
    //        if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
    //        {
    //            if (msg.message == WM_QUIT)
    //            {
    //                isApplicationQuit = true;
    //            }
    //            else
    //            {
    //                TranslateMessage(&msg);
    //                DispatchMessageW(&msg);
    //            }
    //        }
    //        else
    //        {
    //            //
    //        }
    //    }

    //    return (INT32)msg.wParam;
    //}

    /////////////////////////////////////////////////////////////////////////////
    // @ OpenGLWin32.
    /////////////////////////////////////////////////////////////////////////////
    class OpenGLWin32 : public IOpenGL
    {
    public:
        virtual VOID Clear(EAttribMask AttribMask) override { glClear((UINT32)AttribMask); }
        virtual VOID ClearColor(FLOAT32 R, FLOAT32 G, FLOAT32 B, FLOAT32 A) override { glClearColor(R, G, B, A); }
        virtual VOID PushMatrix() override { glPushMatrix(); }
        virtual VOID MatrixMode(EMatrixMode MatrixMode) override { glMatrixMode((UINT16)MatrixMode); }
        virtual VOID Translate(FLOAT32 X, FLOAT32 Y, FLOAT32 Z) override { glTranslatef(X, Y, Z); }
        virtual VOID Rotate(FLOAT32 Angle, FLOAT32 X, FLOAT32 Y, FLOAT32 Z) override { glRotatef(Angle, X, Y, Z); }
        virtual VOID PopMatrix() override { glPopMatrix(); }
        virtual VOID LoadIdentity() override { glLoadIdentity(); }
        virtual VOID Begin(EBeginMode BeginMode) override { glBegin((UINT16)BeginMode); }
        virtual VOID Color4F(FLOAT32 R, FLOAT32 G, FLOAT32 B, FLOAT32 A) override { glColor4f(R, G, B, A); }
        virtual VOID Vertex3F(FLOAT32 X, FLOAT32 Y, FLOAT32 Z) override { glVertex3f(X, Y, Z); }
        virtual VOID End() override { glEnd(); }
        virtual VOID Flush() override { glFlush(); }
    };


    /////////////////////////////////////////////////////////////////////////////
    // @ 어플리케이션 프로시저.
    /////////////////////////////////////////////////////////////////////////////
    long __stdcall WindowProcess(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message)
        {
        case WM_CREATE:
        {
            g_ApplicationState = XApplicationState::OnCreate;
            break;
        }

        case WM_SETFOCUS:
        {
            g_ApplicationState = XApplicationState::OnResume;
            break;
        }

        case WM_KILLFOCUS:
        {
            g_ApplicationState = XApplicationState::OnPause;
            break;
        }

        case WM_SIZE:
        {
            glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
            break;
        }

        case WM_CLOSE:
        {
            DestroyWindow(windowHandle); // WM_DESTROY
            break;
        }

        case WM_DESTROY:
        {
            g_ApplicationState = XApplicationState::OnDestroy;
            PostQuitMessage(0); // WM_QUIT
            break;
        }
        }

        return DefWindowProcW(windowHandle, message, wParam, lParam);
    }

    /////////////////////////////////////////////////////////////////////////////
    // @ 어플리케이션 실행.
    /////////////////////////////////////////////////////////////////////////////
    VOID XApplicationRun(FOnAction OnAction)
    {
        g_Instance = GetModuleHandle(NULL);

        // 전역 문자열을 초기화합니다.
        //LoadStringW(Instance, IDS_APP_TITLE, g_szTitle, MAX_LOADSTRING);
        //LoadStringW(Instance, IDC_ACROEDITOR, g_szWindowClass, MAX_LOADSTRING);
        WNDCLASSEXW wcex;
        wcex.cbSize = sizeof(WNDCLASSEX);
        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = WindowProcess;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = g_Instance;
        wcex.hIcon = 0;// LoadIconW(Instance, MAKEINTRESOURCE(IDI_ACROEDITOR));
        wcex.hCursor = 0; // LoadCursor(nullptr, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszMenuName = 0;// MAKEINTRESOURCEW(IDC_ACROEDITOR);
        wcex.lpszClassName = g_szWindowClass;
        wcex.hIconSm = 0;// LoadIcon(Instance, MAKEINTRESOURCE(IDI_SMALL));
        RegisterClassExW(&wcex);

        g_WindowHandle = CreateWindowExW(0L, g_szWindowClass, g_szTitle,
            WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP | WS_MAXIMIZE,
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, g_Instance, nullptr);

        if (!g_WindowHandle)
        {
            //return FALSE;
            return;
        }

        // 렌더러 초기화.
        HDC deviceContext = GetDC(g_WindowHandle);

        PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
        memset(&pixelFormatDescriptor, 0, sizeof(pixelFormatDescriptor));
        pixelFormatDescriptor.nSize = sizeof(pixelFormatDescriptor);
        pixelFormatDescriptor.nVersion = 1;
        pixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
        pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
        pixelFormatDescriptor.cColorBits = 32;

        INT32 pixelFormat = ChoosePixelFormat(deviceContext, &pixelFormatDescriptor);
        if (pixelFormat == 0)
        {
            return;
        }

        if (!SetPixelFormat(deviceContext, pixelFormat, &pixelFormatDescriptor))
        {
            return;
        }

        DescribePixelFormat(deviceContext, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pixelFormatDescriptor);
        //ReleaseDC(g_WindowHandle, deviceContext);
        //deviceContext = GetDC(g_WindowHandle);
        HGLRC renderingContext = wglCreateContext(deviceContext);
        wglMakeCurrent(deviceContext, renderingContext);

        g_OpenGL = new OpenGLWin32();

        g_OpenGL->ClearColor(0.72f, 0.72f, 0.72f, 1.0f);

        ShowWindow(g_WindowHandle, SW_SHOW);
        UpdateWindow(g_WindowHandle);

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
                g_OpenGL->Clear(IOpenGL::EAttribMask::COLOR_BUFFER_BIT);
                g_OpenGL->Flush();

                if (OnAction != nullptr)
                    OnAction();
            }
        }

        wglMakeCurrent(NULL, NULL);
        ReleaseDC(g_WindowHandle, deviceContext);
        wglDeleteContext(renderingContext);

        if (g_OpenGL != nullptr)
        {
            delete g_OpenGL;
            g_OpenGL = nullptr;
        }

        //return (INT32)msg.wParam;
    }


    /////////////////////////////////////////////////////////////////////////////
    // @ 어플리케이션 상태.
    /////////////////////////////////////////////////////////////////////////////
    XApplicationState XGetApplicationState()
    {
        return g_ApplicationState;
    }

    /////////////////////////////////////////////////////////////////////////////
    // @ 어플리케이션 종료.
    /////////////////////////////////////////////////////////////////////////////
    VOID XApplicationQuit()
    {
        if (g_WindowHandle != 0)
            CloseWindow(g_WindowHandle);
    }

    /////////////////////////////////////////////////////////////////////////////
    // @ OpenGL 반환.
    /////////////////////////////////////////////////////////////////////////////
    IOpenGL* XGetOpenGL()
    {
        return g_OpenGL;
    }
}

#endif