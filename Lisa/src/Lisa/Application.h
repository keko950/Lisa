#pragma once

#include "Core.h"
#include "Window.h"

namespace Lisa 
{

	class LISA_API Application
	{
	public:
		Application();
		virtual ~Application();\

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//to be defined in client
	Application* CreateApplication();

}

