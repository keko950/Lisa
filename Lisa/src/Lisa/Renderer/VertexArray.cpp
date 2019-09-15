#include "lspch.h"

#include "VertexArray.h"
#include "Lisa\Renderer\Renderer.h"
#include "Platform\OpenGL\OpenGLVertexArray.h"


namespace Lisa
{
	VertexArray * Lisa::VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLVertexArray();
		default:
			return nullptr;
		}
		
	}
}

