#pragma once

#include <stdint.h>
#include "Lisa/Renderer/Buffer.h"

namespace Lisa
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();
		
		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual const BufferLayout& GetLayout() const override { return m_Layout; }
		virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }
		
	private:
		uint32_t m_RendererId;
		BufferLayout m_Layout;
		float* m_Vertices;
		uint32_t m_Size;

	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t indexes, uint32_t size);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;
	private:
		uint32_t m_RendererId;
		uint32_t m_Indexes;
		uint32_t m_Size;
		
	};
}