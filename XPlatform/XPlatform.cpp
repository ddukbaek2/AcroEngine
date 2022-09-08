#include "XPlatform.h"

#include "C:\\Users\\dagraac\\AppData\\Local\\Android\\Sdk\\ndk\\21.4.7075529\\sources\\android\\"

namespace XPlatform
{
#if defined(XPLATFORM_WINDOWS)
#elif defined(XPLATFORM_ANDROID)
#elif defined(XPLATFORM_IOS)
#else
#endif

#if defined(XPLATFORM_WINDOWS)
#elif defined(XPLATFORM_ANDROID)
#include <EGL/egl.h>
#include <GLES/gl.h>
	void android_main(struct android_app* state)
	{

	}
#elif defined(XPLATFORM_IOS)
#else
#endif

	void XSound::Clear()
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
	void XSound::SetVolume(INT32 Identity, INT32 Volume)
	{
	}
	void XSound::GetVolume(INT32 Identity)
	{
	}
}