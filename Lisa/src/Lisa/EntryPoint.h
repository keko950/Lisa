#pragma once

#ifdef LS_PLATFORM_WINDOWS

extern Lisa::Application* Lisa::CreateApplication();

int main(int argc, char** argv)
{
	Lisa::Log::Init();
	LS_CORE_WARN("Initialized Log!");

	auto app = Lisa::CreateApplication();
	app->Run();
		
	delete app;
}

#else 
	#error Lisa only support windows
#endif
