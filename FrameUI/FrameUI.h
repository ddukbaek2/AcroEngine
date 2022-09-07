#pragma once

#include "../AcroEngine/AcroEngine.h"


namespace FrameUI
{
	using namespace AcroEngine;

	struct ITouchable
	{
		virtual void OnTouchPress(AVector2 Position) = 0;
		virtual void OnTouchDrag(AVector2 Position, AVector2 MoveDelta) = 0;
		virtual void OnTouchRelease(AVector2 Position) = 0;
	};

	struct IReactable
	{
		virtual void Foo() = 0;
	};

	struct IInputable
	{
		virtual void OnKeyPress(AInt KeyCode);
		virtual void OnKeyPressing(AInt KeyCode);
		virtual void OnKeyRelease(AInt KeyCode);
	};

	struct IDrawable
	{
		virtual void Begin() = 0;
		virtual void End() = 0;
	};

	struct IMeshModel
	{
		virtual void SetVertices(AVector3 Vertices[]) = 0;
		virtual void SetIndices(AInt Indices[]) = 0;
		virtual void SetTexture(AInt Index, AUnknownObject* Texture) = 0;
		virtual void SetTextureCoords(AVector2 TextureCoords[]) = 0;
	};

	struct IRenderPipeline
	{

	};

	struct IShader
	{

	};

	struct IMaterial
	{

	};

	struct ITexture
	{

	};

	struct ITransform
	{

	};
}