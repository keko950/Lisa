#include "lspch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

#include "File.h"

#include <glad/glad.h>

#include "Input.h"

namespace Lisa {

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

		float vertices[3 * 6] =
		{
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.2f,
			0.5f, -0.5f, 0.0f, 0.2f, 0.8f, 0.2f,
			0.f, 0.5f, 0.f,    0.2f, 0.2f, 0.8f
		};

		m_Va.reset(VertexArray::Create(1));
		m_Va->Bind();

		m_Vb.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
		m_Vb->Bind();

		{
			BufferLayout layout = {
				{ShaderDataType::Float3, "a_Position", true},
				{ShaderDataType::Float3, "a_Color", true}
			};

			m_Vb->SetLayout(layout);
		}

		m_Va->AddVertexBuffer(m_Vb);

		m_Shader.reset(Shader::Create(File::Read("C:/Users/Gibe/Desktop/vertex.shader"), File::Read("C:/Users/Gibe/Desktop/fragment.shader")));
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