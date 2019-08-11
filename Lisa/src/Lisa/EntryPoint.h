#pragma once

#ifdef LS_PLATFORM_WINDOWS

extern Lisa::Application* Lisa::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lisa::CreateApplication();
	app->Run();
	delete app;
}

#else 
	#error Lisa only support windows
#endif
