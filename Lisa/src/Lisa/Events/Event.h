#pragma once


#include "../Core.h"
#include <string>

namespace Lisa 
{

	enum class EventType
	{
		None = 0,
		WindowResized, WindowClosed, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppRender, AppUpdate,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)  virtual int GetCategoryFlags() const override { return category; }


	class LISA_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return category & GetCategoryFlags();
		}

	protected:
		bool m_handled = false;

	};

	class EventDispatcher
	{

	};

}

