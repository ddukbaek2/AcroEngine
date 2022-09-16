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

	void XSound::Reset()
	{
	}
	void XSound::Add(INT32 Identity, CHAR16* SoundFilePath)
	{
	}
	void XSound::Remove(INT32 Identity)
	{
	}
	void XSound::Play(INT32 Identity)
	{
	}
	void XSound::Pause(INT32 Identity)
	{
	}
	void XSound::Resume(INT32 Identity)
	{
	}
	void XSound::Stop(INT32 Identity)
	{
	}
	void XSound::SetPosition(INT32 Identity, INT32 Time)
	{
	}
	INT32 XSound::GetPosition(INT32 Identity)
	{
		return INT32();
	}

	VOID XSound::SetVolume(INT32 Identity, INT32 Volume)
	{
	}

	VOID XSound::GetVolume(INT32 Identity)
	{
	}

	VOID* CreateMemory(UINT32 Length)
	{
		return new UINT8[Length];
	}

	VOID DeleteMemory(VOID* Pointer)
	{
		if (Pointer != nullptr)
		{
			delete[](Pointer);
		}
	}

	VOID FillMemory(VOID* Source, UINT8 Value, UINT32 Length)
	{
		return;

		UINT8* temp = (UINT8*)Source;
		for (UINT32 Index = 0; Index < Length; ++Index)
		{
			temp[Index] = Value;
		}
	}
}