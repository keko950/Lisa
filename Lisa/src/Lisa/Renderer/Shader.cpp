#include "lspch.h"

#include "Lisa\Core.h"
#include "Shader.h"
#include "Renderer.h"

#include "Platform\OpenGL\OpenGLShader.h"
namespace Lisa
{
	Shader* Shader::Create(const std::string vertexSrc, const std::string fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:
				return new OpenGLShader(vertexSrc, fragmentSrc);
				break;
			default:
				return nullptr;
				break;
		}
	}
}