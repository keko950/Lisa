#pragma once

#include "Lisa/Core.h"
#include "Lisa/Renderer/VertexArray.h"
#include "Lisa/Renderer/RendererAPI.h"

namespace Lisa
{
	class LISA_API RendererCommand
	{
	public:
		inline static void SetClearColor(const glm::vec4& color)
		{
			s_RendererAPI->SetClearColor(color);
		}

		inline static void Clear()
		{
			s_RendererAPI->Clear();
		}

		inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndexed(vertexArray);
		}

		inline static void Draw(const std::shared_ptr<VertexArray>& vertexArray)
		{
			s_RendererAPI->Draw(vertexArray);
		}
	private:
		static RendererAPI* s_RendererAPI;
	};
}