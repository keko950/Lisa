#pragma once

#include "Lisa\Core.h"
#include "Lisa\Renderer\Buffer.h"

namespace Lisa
{
	class LISA_API VertexArray
	{
	public:
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void AddVertexBuffer(std::shared_ptr<VertexBuffer> vb) = 0;
		virtual void AddIndexBuffer(std::shared_ptr<IndexBuffer> ib) = 0;

		virtual std::shared_ptr<IndexBuffer> GetIndexBuffer() const = 0;
		virtual std::vector<std::shared_ptr<VertexBuffer>> GetVertexBuffers() const = 0;

		static VertexArray* Create();
	};
}