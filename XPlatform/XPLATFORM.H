#pragma once

// Desktop.
//#define XPLATFORM_WINDOWS // Base WindowsAPI
//#define XPLATFORM_MAC // Base CocoaFramework

// Mobile.
//#define XPLATFORM_ANDROID // Base AndroidNDK
//#define XPLATFORM_IOS // Base 

// Console.
//#define XPLATFORM_SWITCH
//#define XPLATFORM_PS5
//#define XPLATFORM_XBOXSX

namespace XPlatform
{
#if defined(XPLATFORM_WINDOWS)
	typedef signed int sint32;
	typedef unsigned int uint32;
	typedef bool boolean;
#elif defined(XPLATFORM_ANDROID)
	typedef signed int sint32;
	typedef unsigned int uint32;
	typedef bool boolean;
#elif defined(XPLATFORM_IOS)
	typedef signed int sint32;
	typedef unsigned int uint32;
	typedef bool boolean;
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