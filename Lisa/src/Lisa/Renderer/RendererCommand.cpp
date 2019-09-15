#include "lspch.h"
#include "RendererCommand.h"

#include "Platform\OpenGL\OpenGLRendererAPI.h"

namespace Lisa
{
	RendererAPI* RendererCommand::s_RendererAPI = new OpenGLRendererAPI;
}