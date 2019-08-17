#pragma once

#include "Event.h"

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

		EVENT_CLASS_TYPE(WindowResized)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height;
	};

	class LISA_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowCloseEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowClosed)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class LISA_API WindowFocus : public Event
	{
	public:
		WindowFocus() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowFocus";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class LISA_API WindowLostFocus : public Event
	{
	public:
		WindowLostFocus() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowLostFocus";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowLostFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class LISA_API WindowMoved : public Event
	{
	public:
		WindowMoved() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMoved";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}