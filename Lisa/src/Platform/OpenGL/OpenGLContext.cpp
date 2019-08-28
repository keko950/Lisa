#include "lspch.h"
#include "OpenGLContext.h"

#include <GLFW\glfw3.h>
#include <glad\glad.h>
#include <gl\GL.h>

namespace Lisa
{
	OpenGLContext::OpenGLContext(GLFWwindow * window) : m_Window(window)
	{
		LS_CORE_ASSERT(window, "Failed to init Window");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		LS_CORE_ASSERT(status, "Failed to init Glad!");
	}

	void OpenGLContext::SwapBuffers()
	{
		glBegin(GL_TRIANGLES);
		glEnd();
		glfwSwapBuffers(m_Window);
	}
}

