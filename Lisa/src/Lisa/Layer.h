#pragma once

#include "Lisa\Core.h"
#include "Lisa\Events\Event.h"

namespace Lisa
{
	class LISA_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}
		virtual void OnImGuiRender() {}

		inline const std::string GetName() { return m_DebugName; }
	protected:
		std::string m_DebugName;
	
	};
}