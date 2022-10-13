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
	private:
	public:
		static AAsset Load()
		{
			return AAsset::Null();
		}

		static void Unload(AAsset Target)
		{
		}
	};

	class Texture : public Asset
	{
	private:
		int32 m_OpenGLTextureID;

	public:
	};
}