#pragma once

#include "Core.h"

namespace Lisa {

	class LISA_API Application
	{
	public:
		Application();
		virtual ~Application();\

		void Run();
	};

	//to be defined in client
	Application* CreateApplication();

}

