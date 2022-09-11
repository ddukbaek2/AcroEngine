#pragma once

// Desktop.
//#define XPLATFORM_WINDOWS // Base WindowsAPI
//#define XPLATFORM_MAC // Base CocoaFramework

// Mobile.
//#define XPLATFORM_ANDROID // Base AndroidNDK
//#define XPLATFORM_IOS // Base CocoaFramework

// Console.
//#define XPLATFORM_SWITCH
//#define XPLATFORM_PS5
//#define XPLATFORM_XBOXSX

namespace XPlatform
{
#if defined(XPLATFORM_WINDOWS)
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed short INT16;
	typedef unsigned short UINT16;
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef bool BOOL;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;

#elif defined(XPLATFORM_ANDROID)
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed short INT16;
	typedef unsigned short UINT16;
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef bool BOOL;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;

#elif defined(XPLATFORM_IOS)
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed short INT16;
	typedef unsigned short UINT16;
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef bool BOOL;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;

#else // ENGINE
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed short INT16;
	typedef unsigned short UINT16;
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef bool BOOL;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;

#endif

	struct XMemory
	{
	};

	struct XFile
	{
	};

	struct XNetwork
	{
	};

	struct XInput
	{
	};

	struct XSound
	{
		static void Clear();
		static void Add(INT32 Identity, CHAR16* SoundFilePath);
		static void Remove(INT32 Identity);
		static void Play(INT32 Identity);
		static void Pause(INT32 Identity);
		static void Resume(INT32 Identity);
		static void Stop(INT32 Identity);
		static void SetPosition(INT32 Identity, INT32 Time);
		static INT32 GetPosition(INT32 Identity);
		static void SetVolume(INT32 Identity, INT32 Volume);
		static void GetVolume(INT32 Identity);
	};

	struct XVideo
	{
	};



	struct XApplication
	{
	};

	struct XCache
	{
	};
}