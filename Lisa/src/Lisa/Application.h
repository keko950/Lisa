#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events\ApplicationEvent.h"
#include "Lisa/LayerStack.h"
#include "Lisa/ImGui/ImGuiLayer.h"
#include "Lisa/Renderer/Buffer.h"

#include <Lisa\Renderer\Shader.h>

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
		VertexBuffer* m_Vb;
		bool OnCloseEvent(WindowCloseEvent &event);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		Shader* m_Shader;
		static Application* s_Instance;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	};

	//to be defined in client
	Application* CreateApplication();

}

