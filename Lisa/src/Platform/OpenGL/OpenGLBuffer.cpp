#pragma once

#include "lspch.h"
#include "OpenGLBuffer.h"

#include <glad\glad.h>


namespace Lisa
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(float * vertices, uint32_t size) : m_Vertices(vertices), m_Size(size), m_Layout({})
	{
		glGenBuffers(1, &m_RendererId);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_RendererId);

	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
		glBufferData(GL_ARRAY_BUFFER, m_Size, m_Vertices, GL_STATIC_DRAW);
	}

	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	/////////////////INDEX BUFFER/////////////////////////

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indexes, uint32_t size) : m_Indexes(indexes), m_Size(size)
	{
		glGenBuffers(1, &m_RendererId);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &m_RendererId);

	}

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Size, &m_Indexes, GL_STATIC_DRAW);
	}

	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}
