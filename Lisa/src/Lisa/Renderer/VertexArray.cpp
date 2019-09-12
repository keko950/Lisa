#include "lspch.h"

#include "VertexArray.h"
#include "Lisa\Renderer\Renderer.h"
#include "Platform\OpenGL\OpenGLVertexArray.h"


namespace Lisa
{
	VertexArray * Lisa::VertexArray::Create(unsigned int size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexArray(size);
		default:
			return nullptr;
		}
		
	}
}

