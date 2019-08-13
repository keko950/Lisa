#pragma once

#include "Event.h"
#include "../Core.h"

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
		EVENT_CLASS_TYPE(KeyPressed)
	};
}