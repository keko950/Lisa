#include "Application.h"
#include <stdio.h>
#include "Events\ApplicationEvent.h"
#include "Log.h"
#include <iostream>

namespace Lisa{

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		LS_TRACE(e);
	
	}

}