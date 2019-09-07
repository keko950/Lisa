#pragma once

#include "Lisa\Core.h"

namespace Lisa
{
	enum class RendererAPI
	{
		None = 0, 
		OpenGL = 1
	};

	class LISA_API Renderer
	{
	public:
		inline static void SetAPI(RendererAPI api)
		{
			s_RendererAPI = api;
		};
		inline static RendererAPI GetAPI()
		{
			return s_RendererAPI;
		};
	private:
		static RendererAPI s_RendererAPI;
	};
}