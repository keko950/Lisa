#include "lspch.h"

#include "Application.h"
#include "Events\ApplicationEvent.h"
#include "Log.h"

#include <GLFW\glfw3.h>


namespace Lisa{

#define BIND_EVENT_FN(x) (std::bind(&x, this, std::placeholders::_1))

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
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
			if (e.Handled)
				break;
			(*--it)->OnEvent(e);
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
			glClearColor(1, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	
	}

}