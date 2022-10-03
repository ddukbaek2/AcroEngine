#pragma once


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 플랫폼 목록.
	/////////////////////////////////////////////////////////////////////////////
#if defined(WIN32) // WINDOWS
	#define XPLATFORM_WINDOWS
#elif defined(__linux__) // LINUX
	#define XPLATFORM_LINUX
#elif defined(TARGET_OS_OSX) // MACOSX
	#define XPLATFORM_OSX
#elif defined(__ANDROID__) // ANDROID
	#define XPLATFORM_ANDROID
#elif defined(TARGET_OS_IOS) // IOS
	#define XPLATFORM_IOS
#elif defined(__SWITCH__)
	#define XPLATFORM_SWITCH
#elif defined(__PLAYSTATION5__)
	#define XPLATFORM_PS5
#elif defined(__XBOXSX__)
	#define XPLATFORM_XBOXSX
#endif

	/////////////////////////////////////////////////////////////////////////////
	// @ 변수 재선언 목록.
	/////////////////////////////////////////////////////////////////////////////
	typedef void VOID;
	typedef void* POINTER;
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed short INT16;
	typedef unsigned short UINT16;
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef signed long long INT64;
	typedef unsigned long long UINT64;
	typedef bool BOOL8;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;


	/////////////////////////////////////////////////////////////////////////////
	// @ 매크로 목록.
	/////////////////////////////////////////////////////////////////////////////
	#define INVALID -1
	#undef TEXT
	#define TEXT(Text) L#Text

	#define ACTION(Name) typedef VOID(*Name)(VOID)
	#define ACTION_WITH_PARAM(Name, Params) typedef VOID(*Name)(Params)
	#define FUNC(Name, Return) typedef Return(*Name)(VOID)
	#define FUNC_WITH_PARAM(Name, Return, Params) typedef Return(*Name)(Params)


	/////////////////////////////////////////////////////////////////////////////
	// @ 클래스 전방선언 목록.
	/////////////////////////////////////////////////////////////////////////////
	class IApplication;
	class IGL;


	/////////////////////////////////////////////////////////////////////////////
	// @ 클래스 포인터 전방선언 목록.
	/////////////////////////////////////////////////////////////////////////////
	typedef IApplication* XApplication;
	typedef IGL* XGL;


	/////////////////////////////////////////////////////////////////////////////
	// @ 기본 함수포인터.
	/////////////////////////////////////////////////////////////////////////////
	ACTION(FOnAction);
	FUNC(FOnFunc, BOOL8);


	/////////////////////////////////////////////////////////////////////////////
	// @ 메모리 함수 목록.
	/////////////////////////////////////////////////////////////////////////////
	POINTER XMemoryAllocate(UINT32 Length);
	VOID XMemoryFree(POINTER Pointer);
	VOID XMemorySet(POINTER Source, UINT8 Value, UINT32 Length);


	/////////////////////////////////////////////////////////////////////////////
	// @ 그래픽.
	/////////////////////////////////////////////////////////////////////////////
	class IGL
	{
	public:
		enum class EAttribMask : UINT32
		{
			CURRENT_BIT = 0x00000001,
			POINT_BIT = 0x00000002,
			LINE_BIT = 0x00000004,
			POLYGON_BIT = 0x00000008,
			POLYGON_STIPPLE_BIT = 0x00000010,
			PIXEL_MODE_BIT = 0x00000020,
			LIGHTING_BIT = 0x00000040,
			FOG_BIT = 0x00000080,
			DEPTH_BUFFER_BIT = 0x00000100,
			ACCUM_BUFFER_BIT = 0x00000200,
			STENCIL_BUFFER_BIT = 0x00000400,
			VIEWPORT_BIT = 0x00000800,
			TRANSFORM_BIT = 0x00001000,
			ENABLE_BIT = 0x00002000,
			COLOR_BUFFER_BIT = 0x00004000,
			HINT_BIT = 0x00008000,
			EVAL_BIT = 0x00010000,
			LIST_BIT = 0x00020000,
			TEXTURE_BIT = 0x00040000,
			SCISSOR_BIT = 0x00080000,
			ALL_ATTRIB_BITS = 0x000fffff,
		};

		enum class EBeginMode : UINT16
		{
			POINTS = 0x0000,
			LINES = 0x0001,
			LINE_LOOP = 0x0002,
			LINE_STRIP = 0x0003,
			TRIANGLES = 0x0004,
			TRIANGLE_STRIP = 0x0005,
			TRIANGLE_FAN = 0x0006,
			QUADS = 0x0007,
			QUAD_STRIP = 0x0008,
			POLYGON = 0x0009,
		};

		enum class EMatrixMode : UINT16
		{
			MODELVIEW = 0x1700,
			PROJECTION = 0x1701,
			TEXTURE = 0x1702,
		};

	public:
		virtual VOID Clear(EAttribMask AttribMask) = 0;
		virtual VOID ClearColor(FLOAT32 R, FLOAT32 G, FLOAT32 B, FLOAT32 A) = 0;
		virtual VOID PushMatrix() = 0;
		virtual VOID MatrixMode(EMatrixMode MatrixMode) = 0;
		virtual VOID Translate(FLOAT32 X, FLOAT32 Y, FLOAT32 Z) = 0;
		virtual VOID Scale(FLOAT32 X, FLOAT32 Y, FLOAT32 Z) = 0;
		virtual VOID Rotate(FLOAT32 X, FLOAT32 Y, FLOAT32 Z, FLOAT32 W) = 0;
		virtual VOID PopMatrix() = 0;
		virtual VOID LoadIdentity() = 0;
		virtual VOID Begin(EBeginMode BeginMode) = 0;
		virtual VOID Color4(FLOAT32 R, FLOAT32 G, FLOAT32 B, FLOAT32 A) = 0;
		virtual VOID Vertex3(FLOAT32 X, FLOAT32 Y, FLOAT32 Z) = 0;
		virtual VOID TexCoord2(FLOAT32 U, FLOAT32 V) = 0;
		virtual VOID End() = 0;
		virtual VOID Flush() = 0;
		virtual VOID Viewport(INT32 X, INT32 Y, INT32 Width, INT32 Height) = 0;
	};

	// FILE
	// NETWORK
	// INPUT
	// SOUND
	// MISC


	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션.
	/////////////////////////////////////////////////////////////////////////////
	class IApplication
	{
	public:
		ACTION_WITH_PARAM(FOnApplicationUpdate, XApplication);

		/////////////////////////////////////////////////////////////////////////////
		// @ 어플리케이션 상태.
		/////////////////////////////////////////////////////////////////////////////
		enum class EState
		{
			Invalid = -1,
			OnCreate,
			OnResume,
			OnPause,
			OnDestroy,
		};

	public:
		virtual VOID Run(FOnApplicationUpdate OnAction) = 0;
		virtual EState GeState() = 0;
		virtual VOID Quit() = 0;
		virtual XGL GetGL() = 0;
	};


	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 실행.
	/////////////////////////////////////////////////////////////////////////////
	VOID RunApplication(IApplication::FOnApplicationUpdate OnApplicationUpdate);
}