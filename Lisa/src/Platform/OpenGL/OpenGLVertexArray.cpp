#include "lspch.h"

#include "OpenGLVertexArray.h"
#include <glad\glad.h>

namespace Lisa
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Float:		return GL_FLOAT;
		case ShaderDataType::Float2:	return GL_FLOAT;
		case ShaderDataType::Float3:	return GL_FLOAT;
		case ShaderDataType::Float4:	return GL_FLOAT;
		case ShaderDataType::Mat3:		return GL_FLOAT;
		case ShaderDataType::Mat4:		return GL_FLOAT;
		case ShaderDataType::Int:		return GL_INT;
		case ShaderDataType::Int2:		return GL_INT;
		case ShaderDataType::Int3:		return GL_INT;
		case ShaderDataType::Int4:		return GL_INT;
		case ShaderDataType::Bool:		return GL_BOOL;
		}

		LS_CORE_ASSERT(false, "Unknown shader type");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray(unsigned int size)
	{
		glGenVertexArrays(size, &m_VertexArrayID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_VertexArrayID);
	}

	void OpenGLVertexArray::UnBind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(std::shared_ptr<VertexBuffer> vb)
	{
		m_VertexBuffers.push_back(vb);
		int index = 0;
		const auto& layout = vb->GetLayout();
		for (const auto& element : layout)
		{
			glVertexAttribPointer(index, element.GetElementCount(), ShaderDataTypeToOpenGLBaseType(element.Type), element.Normalized ? GL_TRUE : GL_FALSE, layout.GetStride(), (const void*)element.Offset);
			glEnableVertexAttribArray(index);
			index++;
		}

	}

	void OpenGLVertexArray::AddIndexBuffer(std::shared_ptr<IndexBuffer> ib)
	{
		m_IndexBuffer = ib;
	}

}
