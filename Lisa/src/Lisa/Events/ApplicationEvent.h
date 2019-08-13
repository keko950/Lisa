#pragma once

#include "../Core.h"
#include "Event.h"

#include <sstream>

namespace Lisa
{
	class LISA_API WindowResizeEvent : public Event 
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() { return m_Width; }
		inline unsigned int GetHeight() { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << "," << m_Height;
			return ss.str();
		}

		EventType GetEventType() const override
		{
			return EventType::WindowResized;
		}

		const char* GetName() const override 
		{
			return "WindowResizeEvent";
		}

		EVENT_CLASS_TYPE(WindowResized);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	private:
		unsigned int m_Width, m_Height;
	};
}