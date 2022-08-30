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
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef bool BOOL;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;

#elif defined(XPLATFORM_ANDROID)
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef bool BOOL;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;

#elif defined(XPLATFORM_IOS)
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef signed int INT32;
	typedef unsigned int UINT32;
	typedef bool BOOL;
	typedef float FLOAT32;
	typedef double FLOAT64;
	typedef wchar_t CHAR16;

#endif

	class XPlatform
	{
	public:
	};

	class XFile {};
	class XNetwork {};
	class XInput {};
	class XVideo {};
	class XAudio {};
	class XMemory {};
	class XApplication {};
	class XUI {};
	class XCache {};
}