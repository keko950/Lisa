#pragma once

#include "Lisa\Core.h"

#include "Lisa\Renderer\VertexArray.h"

namespace Lisa
{
	class LISA_API OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();

		 void Bind() const override;
		 void UnBind() const override;

		 void AddVertexBuffer(std::shared_ptr<VertexBuffer> vb) override;
		 void AddIndexBuffer(std::shared_ptr<IndexBuffer> ib) override;


		 virtual inline std::vector<std::shared_ptr<VertexBuffer>> GetVertexBuffers() const override
		 {
			 return m_VertexBuffers;
		 };

		 virtual inline std::shared_ptr<IndexBuffer> GetIndexBuffer() const override
		 {
			 return m_IndexBuffer;
		 };

	private:
		unsigned int m_VertexArrayID;
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	};
}