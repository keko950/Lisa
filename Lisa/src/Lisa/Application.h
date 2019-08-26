#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events\ApplicationEvent.h"
#include "Lisa/LayerStack.h"
#include "Lisa/ImGui/ImGuiLayer.h"

namespace Lisa 
{

	class LISA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetNativeWindow()
		{
			return *m_Window;
		}

		static inline Application& Get()
		{
			return *s_Instance;
		}

	private:
		ImGuiLayer* m_ImGuiLayer;
		bool OnCloseEvent(WindowCloseEvent &event);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	//to be defined in client
	Application* CreateApplication();

}

