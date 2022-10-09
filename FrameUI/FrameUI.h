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
		virtual void OnTouchPress(AcroEngine::Vector2 Position) = 0;
		virtual void OnTouchDrag(AcroEngine::Vector2 Position, AcroEngine::Vector2 MoveDelta) = 0;
		virtual void OnTouchRelease(AcroEngine::Vector2 Position) = 0;
	};

	struct IReactable
	{
		virtual void Foo() = 0;
	};

	struct IInputable
	{
		virtual void OnKeyPress(AcroEngine::Int KeyCode) = 0;
		virtual void OnKeyPressing(AcroEngine::Int KeyCode) = 0;
		virtual void OnKeyRelease(AcroEngine::Int KeyCode) = 0;
	};

	struct IDrawable
	{
		virtual void Begin() = 0;
		virtual void End() = 0;
	};

	struct IMeshModel
	{
		virtual void SetVertices(AcroEngine::Vector3 Vertices[]) = 0;
		virtual void SetIndices(AcroEngine::Int Indices[]) = 0;
		virtual void SetTexture(AcroEngine::Int Index, AcroEngine::AUnknownObject Texture) = 0;
		virtual void SetTextureCoords(AcroEngine::Vector2 TextureCoords[]) = 0;
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

	class FrameUI : public AcroCore::IModule
	{
	public:

	};
}