#pragma once

#include "Lisa/Core.h"
#include "Lisa/Renderer/RendererAPI.h"


namespace Lisa
{
	class OpenGLRendererAPI : public RendererAPI
	{
		// Inherited via RendererAPI
		virtual void SetClearColor(glm::vec4 color) const override;
		virtual void Clear() const override;
		virtual void DrawIndexed(std::shared_ptr<VertexArray> VAO) const override;
		virtual void Draw(std::shared_ptr<VertexArray> VAO) const override;
	};
}