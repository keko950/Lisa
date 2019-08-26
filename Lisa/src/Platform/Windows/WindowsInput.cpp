#include "lspch.h"
#include "WindowsInput.h"

#include <GLFW\glfw3.h>
#include "Lisa\Application.h"


namespace Lisa {

	Input* Input::s_Instance = new WindowsInput();

	WindowsInput::WindowsInput()
	{
	}

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		GLFWwindow* m_Window = static_cast<GLFWwindow*>(Application::Get().GetNativeWindow().GetNativeWindow());
		int state = glfwGetKey(m_Window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	float WindowsInput::GetMouseXImpl()
	{
		GLFWwindow* m_Window = static_cast<GLFWwindow*>(Application::Get().GetNativeWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(m_Window, &x, &y);
		return (float)x;
	}

	float WindowsInput::GetMouseYImpl()
	{
		GLFWwindow* m_Window = static_cast<GLFWwindow*>(Application::Get().GetNativeWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(m_Window, &x, &y);
		return (float)y;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int keyCode)
	{
		GLFWwindow* m_Window = static_cast<GLFWwindow*>(Application::Get().GetNativeWindow().GetNativeWindow());
		int state = glfwGetMouseButton(m_Window, keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		GLFWwindow* m_Window = static_cast<GLFWwindow*>(Application::Get().GetNativeWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(m_Window, &x, &y);
		return std::pair<float, float>(x, y);
	}

}

