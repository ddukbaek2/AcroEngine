#pragma once

#include "AcroEngine.h"
#include "AObject.h"


namespace AcroEngine
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 자원.
	//	INSTANTIATE() ==> LOAD() ==> UNLOAD() ==> DESTROY()
	/////////////////////////////////////////////////////////////////////////////
	class Asset : public Object
	{
	public:
		struct AsyncOperation
		{
			
		};


	private:
	public:
		static AAsset Load()
		{
			return AAsset::Null();
		}

		static AsyncOperation LoadAsync()
		{
			return AsyncOperation();
		}

		static void Unload(AAsset Target)
		{
		}
	};

	class TextureAsset : public Asset
	{
	private:
		int32 m_OpenGLTextureID;

	public:

	};

	class SoundAsset : public Asset
	{
	private:
	public:
	};

	class TextAsset : public Asset
	{
	private:
	public:
	};
}