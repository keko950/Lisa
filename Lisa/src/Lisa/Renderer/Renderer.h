#pragma once

#include "Lisa\Core.h"
#include "RendererAPI.h"

namespace Lisa
{

	class LISA_API Renderer
	{
	public:

		static void Init();

		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API GetAPI()
		{
			return RendererAPI::GetAPI();
		};
	};
}