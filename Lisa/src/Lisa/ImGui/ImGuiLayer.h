#pragma once

#include "Lisa/Layer.h"

#include "Lisa/Events/ApplicationEvent.h"
#include "Lisa/Events/KeyEvent.h"
#include "Lisa/Events/MouseEvent.h"

struct GLFWwindow;

namespace Lisa
{
	class LISA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		void Begin();
		void End();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnImGuiRender() override;

	private:
		float m_Time = 0.0f;
	};
}