#pragma once
#include "lspch.h"

#include "Buffer.h"
#include "Renderer.h"
#include "Platform\OpenGL\OpenGLBuffer.h"


namespace Lisa
{
	VertexBuffer* VertexBuffer::Create(float * vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::OpenGL:
				return new OpenGLVertexBuffer(vertices, size);
				break;
			default:
				return nullptr;
				break;
		}
	}

	IndexBuffer* IndexBuffer::Create(uint32_t * indices, uint32_t size)
	{
		return nullptr;
	}

}
