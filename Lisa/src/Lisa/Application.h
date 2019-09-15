#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Lisa/LayerStack.h"
#include "Lisa/ImGui/ImGuiLayer.h"
#include "Lisa/Renderer/Buffer.h"
#include "Lisa/Renderer/VertexArray.h"
#include "Lisa/Renderer/RendererAPI.h"
#include "Lisa/Renderer/Renderer.h"

#include "Lisa/Renderer/Shader.h"

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
		std::shared_ptr<VertexBuffer> m_Vb;
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_Va;
		std::unique_ptr<Window> m_Window;

		bool OnCloseEvent(WindowCloseEvent &event);
		bool m_Running = true;

		LayerStack m_LayerStack;
		
		static Application* s_Instance;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	};

	//to be defined in client
	Application* CreateApplication();

}

