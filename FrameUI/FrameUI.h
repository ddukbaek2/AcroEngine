#pragma once

#include "../AcroEngine/AcroEngine.h"
#include "../AcroEngine/AObject.h"
#include "../AcroEngine/AList.h"

namespace FrameUI
{
	class INode;
	class IComponent;
	class IImageComponent;
	class ITextComponent;
	class IButtonComponent;

	typedef class INode* FNode;
	typedef class IComponent* FComponent;
	typedef class IImageComponent* FImageComponent;
	typedef class ITextComponent* FTextComponent;
	typedef class IButtonComponent* FButtonComponent;

	struct ITouchable
	{
		virtual void OnTouchPress(AcroEngine::AVector2 Position) = 0;
		virtual void OnTouchDrag(AcroEngine::AVector2 Position, AcroEngine::AVector2 MoveDelta) = 0;
		virtual void OnTouchRelease(AcroEngine::AVector2 Position) = 0;
	};

	struct IReactable
	{
		virtual void Foo() = 0;
	};

	struct IInputable
	{
		virtual void OnKeyPress(AcroEngine::AInt KeyCode);
		virtual void OnKeyPressing(AcroEngine::AInt KeyCode);
		virtual void OnKeyRelease(AcroEngine::AInt KeyCode);
	};

	struct IDrawable
	{
		virtual void Begin() = 0;
		virtual void End() = 0;
	};

	struct IMeshModel
	{
		virtual void SetVertices(AcroEngine::AVector3 Vertices[]) = 0;
		virtual void SetIndices(AcroEngine::AInt Indices[]) = 0;
		virtual void SetTexture(AcroEngine::AInt Index, AcroEngine::AUnknownObject Texture) = 0;
		virtual void SetTextureCoords(AcroEngine::AVector2 TextureCoords[]) = 0;
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