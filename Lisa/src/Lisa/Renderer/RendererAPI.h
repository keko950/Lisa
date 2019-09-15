#pragma once

#include "Lisa\Core.h"
#include "Lisa\Renderer\VertexArray.h"

#include <glm/glm.hpp>

namespace Lisa
{
	class LISA_API RendererAPI
	{
	public:
		enum class API
		{
			None = 0,
			OpenGL = 1
		};

		virtual void SetClearColor(glm::vec4 color) const = 0;
		virtual void Clear() const = 0;

		virtual void DrawIndexed(std::shared_ptr<VertexArray> VAO) const = 0;
		virtual void Draw(std::shared_ptr<VertexArray> VAO) const = 0;

		static const inline API GetAPI()
		{
			return s_RendererAPI;
		}


	private:
		static API s_RendererAPI;
	};

}