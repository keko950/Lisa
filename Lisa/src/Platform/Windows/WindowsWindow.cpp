#include "lspch.h"

#include "Lisa\Log.h"
#include "WindowsWindow.h"
#include "Lisa\Events\ApplicationEvent.h"
#include "Lisa/Events/KeyEvent.h"
#include "Lisa/Events/MouseEvent.h"
#include "WindowsInput.h"

#include <GLFW/glfw3.h>

#include "Platform\OpenGL\OpenGLContext.h"

namespace Lisa
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		LS_CORE_INFO("Creating Window {0} ({1},{2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized) 
		{
			int success = glfwInit();
			LS_CORE_ASSERT(success, "Could not initialize GLFW!");		
			glfwSetErrorCallback([](int errorCode, const char* errorMsg)
			{
				LS_CORE_ERROR("Error code {0} : {1}", errorCode, errorMsg);
			});
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		m_Context = new OpenGLContext(m_Window);
		m_Context->Init();

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		//Set GLFW Callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Height = height;
			data.Width = width;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) 
		{
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int iconified)
		{
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowFocus event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int keyCode, int scanCode, int action, int modifier) 
		{
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			if (action == GLFW_PRESS)
			{
				KeyPressedEvent event(keyCode, 0);
				data.EventCallback(event);
			}
			else if (action == GLFW_RELEASE)
			{
				KeyReleasedEvent event(keyCode);
				data.EventCallback(event);
			}
			else if (action == GLFW_REPEAT) 
			{
				KeyPressedEvent event(keyCode, 1);
				data.EventCallback(event);
			}
			
		});


		glfwSetCharCallback(m_Window, [](GLFWwindow *window, unsigned int keyCode)
		{
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			int key = int(keyCode);
			KeyTypedEvent event(key);
			data.EventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mode)
		{
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			if (action == GLFW_PRESS)
			{
				MouseButtonPressedEvent event(button);
				data.EventCallback(event);
			}
			else if (action == GLFW_RELEASE)
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double offset_x, double offset_y) 
		{
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)offset_x, (float)offset_y);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y)
		{
			WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((float)x, (float)y);
			data.EventCallback(event);

		});

	}


	void WindowsWindow::Shutdown()
	{
		glfwPollEvents();
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	inline bool WindowsWindow::IsVSync() const { return m_Data.VSync; }

}
