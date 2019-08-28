#pragma once

#include "Lisa/Core.h"
#include "Lisa/Renderer/GraphicsContext.h"
#include "Lisa/Log.h"

struct GLFWwindow;

namespace Lisa
{
	class LISA_API OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* window);
		~OpenGLContext();

		void Init() override;
		void SwapBuffers() override;

	private:

		GLFWwindow * m_Window;
	};
}