#pragma once
#include <Lisa\Input.h>

namespace Lisa
{
	class WindowsInput : public Input
	{
	public:
		WindowsInput();

	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
		virtual bool IsMouseButtonPressedImpl(int keyCode) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;

	};
}