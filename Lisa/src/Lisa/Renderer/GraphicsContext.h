#pragma once

#include "Lisa\Core.h"

namespace Lisa
{
	class LISA_API GraphicsContext
	{
	public:
		virtual void Init() {};
		virtual void SwapBuffers() {};
	};
}