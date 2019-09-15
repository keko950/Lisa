#pragma once
#include "lspch.h"
#include "RendererAPI.h"

#include "Renderer.h"
#include "Platform\OpenGL\OpenGLRendererAPI.h"

namespace Lisa
{
	RendererAPI::API RendererAPI::s_RendererAPI = RendererAPI::API::OpenGL;
}

