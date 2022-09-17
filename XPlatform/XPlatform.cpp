#include "XPlatform.h"

//#include "C:\\Users\\dagraac\\AppData\\Local\\Android\\Sdk\\ndk\\21.4.7075529\\sources\\android\\"

namespace XPlatform
{
#if defined(XPLATFORM_WINDOWS)
#elif defined(XPLATFORM_ANDROID)
#elif defined(XPLATFORM_IOS)
#else // ENGINE
#endif

// APPLICATION MAIN.
#if defined(XPLATFORM_WINDOWS)
	void main(wchar_t argv[], int argc)
	{

	}
#elif defined(XPLATFORM_ANDROID)
#include <EGL/egl.h>
#include <GLES/gl.h>
	void android_main(android_app* state)
	{

	}
#elif defined(XPLATFORM_IOS)
#else // ENGINE
#endif



	/////////////////////////////////////////////////////////////////////////////
	// @ 메모리 생성.
	/////////////////////////////////////////////////////////////////////////////
	VOID* XMemoryCreate(UINT32 Length)
	{
		return new UINT8[Length];
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 메모리 삭제.
	/////////////////////////////////////////////////////////////////////////////
	VOID XMemoryDelete(VOID* Pointer)
	{
		if (Pointer != nullptr)
		{
			delete[](Pointer);
		}
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 메모리 값 채우기.
	/////////////////////////////////////////////////////////////////////////////
	VOID XMemoryFill(VOID* Source, UINT8 Value, UINT32 Length)
	{
		return;

		UINT8* temp = (UINT8*)Source;
		for (UINT32 Index = 0; Index < Length; ++Index)
		{
			temp[Index] = Value;
		}
	}
}