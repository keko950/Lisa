#pragma once
#include "lspch.h"

#include <Lisa/Core.h>
#include <Lisa/Events/Event.h>

namespace Lisa
{
	struct WindowProps 
	{
		unsigned int Width, Height;
		std::string Title;

		WindowProps(unsigned int width = 1280, unsigned int height = 720,
			std::string title = "Lisa Engine") : Width(width), Height(height),
			Title(title) {};
	};

	class LISA_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {};
		
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}