#include "lspch.h"
#include "OpenGLRendererAPI.h"

#include <glad\glad.h>

namespace Lisa
{
	void OpenGLRendererAPI::SetClearColor(glm::vec4 color) const
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1);
	}

	void OpenGLRendererAPI::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::DrawIndexed(std::shared_ptr<VertexArray> VAO) const
	{
		VAO->Bind();
		glDrawElements(GL_TRIANGLES, VAO->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void OpenGLRendererAPI::Draw(std::shared_ptr<VertexArray> VAO) const
	{
		VAO->Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);	
	}
}

