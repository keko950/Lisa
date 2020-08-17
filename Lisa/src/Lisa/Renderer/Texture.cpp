#include "Texture.h"
#include "lspch.h"
#include "Lisa/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Lisa
{
	Texture* Lisa::Texture::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLTexture();
		default:
			return nullptr;
		}

	}
}
