#pragma once

#include "Event.h"
#include "../Core.h"

#include <sstream>

namespace Lisa
{
	class LISA_API KeyEvent : public Event 
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {}
	
		int m_KeyCode;
	};

	class LISA_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}
		
		EVENT_CLASS_TYPE(KeyPressed)

		inline int GetRepeatCount() const { return m_RepeatCount;  }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "( repeated: " << m_RepeatCount << " )";
			return ss.str();
		}

	private:
		int m_RepeatCount;

	};

	class LISA_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {};
		
		EVENT_CLASS_TYPE(KeyReleased);

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

	};
}