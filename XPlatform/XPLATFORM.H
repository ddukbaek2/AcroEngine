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

#define INVALID -1

namespace XPlatform
{
#if defined(XPLATFORM_WINDOWS) // WINDOWS
	typedef void VOID;
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed short INT16;
	typedef unsigned short UINT16;
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef bool BOOL8;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;
	
#elif defined(XPLATFORM_MAC) // MAC
	typedef void VOID;
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed short INT16;
	typedef unsigned short UINT16;
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef bool BOOL8;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;

#elif defined(XPLATFORM_ANDROID) // ANDORID
	typedef void VOID;
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed short INT16;
	typedef unsigned short UINT16;
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef bool BOOL8;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;

#elif defined(XPLATFORM_IOS) // IOS
	typedef void VOID;
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed short INT16;
	typedef unsigned short UINT16;
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef bool BOOL8;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;

#else // EDITOR
	typedef void VOID;
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed short INT16;
	typedef unsigned short UINT16;
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef bool BOOL8;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;

#endif

	VOID* ZeroMemory(VOID* Source, INT32 Size);

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
		void Reset();
		void Add(INT32 Identity, CHAR16* SoundFilePath);
		void Remove(INT32 Identity);
		void Play(INT32 Identity);
		void Pause(INT32 Identity);
		void Resume(INT32 Identity);
		void Stop(INT32 Identity);
		void SetPosition(INT32 Identity, INT32 Time);
		INT32 GetPosition(INT32 Identity);
		void SetVolume(INT32 Identity, INT32 Volume);
		void GetVolume(INT32 Identity);
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