#pragma once

#include "Lisa/Layer.h"

#include "Lisa/Events/ApplicationEvent.h"
#include "Lisa/Events/KeyEvent.h"
#include "Lisa/Events/MouseEvent.h"

#include <Lisa\Application.h>
struct GLFWwindow;

namespace Lisa
{
	class LISA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event &e);
		
	private:
		bool OnKeyPressedEvent(Event& e);
		bool OnKeyReleasedEvent(Event& e);
		bool OnKeyTypedEvent(Event& e);
		bool OnMouseButtonPressedEvent(Event& e);
		bool OnMouseButtonReleasedEvent(Event& e);
		bool OnMouseScrolledEvent(Event& e);
		bool OnMouseMovedEvent(Event& e);
		bool OnWindowResizedEvent(Event& e);

	private:
		float m_Time = 0.0f;
		bool m_AnotherWindow = true;
		GLFWwindow* m_Window;
		bool m_Resize = true;
		bool m_MouseButtons [5] = { false, false, false, false, false };
	};
}