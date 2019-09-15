#pragma once
#include "lspch.h"
#include "Renderer.h"

#include "RendererCommand.h"

namespace Lisa
{
	void Renderer::Init()
	{
	}

	void Renderer::BeginScene()
	{

	};

	void Renderer::EndScene()
	{

	};

	void Renderer::Submit(const std::shared_ptr<VertexArray>& VAO)
	{
		VAO->Bind();
		RendererCommand::Draw(VAO);
	}
}