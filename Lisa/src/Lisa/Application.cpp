#include "lspch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

#include "Lisa/Renderer/Shader.h"

#include <glad/glad.h>

#include "Input.h"

namespace Lisa{

#define BIND_EVENT_FN(x) (std::bind(&x, this, std::placeholders::_1))

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		LS_CORE_ASSERT(!s_Instance, "Application Already Exists!")
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		m_LayerStack.PushOverlay(m_ImGuiLayer);

		std::string vertexShader = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

// out vec3 ourColor;
out vec3 ourPosition;

void main()
{
    gl_Position = vec4(aPos, 1.0); 
    // ourColor = aColor;
    ourPosition = aPos;
}

)";

		std::string fragmentShader = R"(
#version 330 core
out vec4 FragColor;
// in vec3 ourColor;
in vec3 ourPosition;

void main()
{
    FragColor = vec4(ourPosition, 1.0);    // note how the position value is linearly interpolated to get all the different colors
}
)";
		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);

		glGenBuffers(1, &m_VertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

		float vertices[3 * 6] =
		{
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
			0.f, 0.5f, 0.f,    0.0f, 0.0f, 1.0f
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, sizeof(float) * 6, (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, sizeof(float) * 6, (void *) (sizeof(float) * 3));
		glEnableVertexAttribArray(1);

		m_Shader = std::make_unique<Shader>(vertexShader, fragmentShader);
	}


	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher ed(e);
		//ed.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& e) { Application::OnCloseEvent(e); return true; });
		ed.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnCloseEvent));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
		//ed.EventFn(OnCloseEvent);
		//ed.Dispatch(EventFn(OnCloseEvent));
		LS_CORE_TRACE("{0}",e);
	}

	bool Application::OnCloseEvent(WindowCloseEvent &event) 
	{
		m_Running = false;
		return true;
	}

	void Application::PushLayer(Layer* layer) 
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer) 
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::Run() 
	{
		while(m_Running) 
		{
			glClearColor(0.1f, 0.1f, 0.1f, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Shader->Bind();
			glBindVertexArray(m_VertexArray);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

 			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();

			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	
	}

}