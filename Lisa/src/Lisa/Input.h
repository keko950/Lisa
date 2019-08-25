#pragma once

#include <Lisa\Core.h>

namespace Lisa
{
	class LISA_API Input
	{
	public:
		static bool IsKeyPressed(int keyCode) 
		{
			return s_Instance->IsKeyPressedImpl(keyCode);
		};
		inline static bool IsMouseButtonPressed(int keyCode) { return s_Instance->IsMouseButtonPressedImpl(keyCode); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keyCode) = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual bool IsMouseButtonPressedImpl(int keyCode) = 0;
		virtual std::pair<float,float> GetMousePositionImpl() = 0;
	
	private:
		static Input* s_Instance;
	};
}