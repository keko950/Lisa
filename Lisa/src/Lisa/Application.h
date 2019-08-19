#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events\ApplicationEvent.h"

namespace Lisa 
{

	class LISA_API Application
	{
	public:
		Application();
		virtual ~Application();\

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnCloseEvent(WindowCloseEvent &event);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//to be defined in client
	Application* CreateApplication();

}

