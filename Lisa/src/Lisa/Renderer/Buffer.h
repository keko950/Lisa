#pragma once

#include <stdint.h>
#include "Lisa\Core.h"

namespace Lisa
{
	class LISA_API VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {};
		
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static VertexBuffer* Create(float* vertices, uint32_t size);

	};

	class LISA_API IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {};

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static IndexBuffer* Create(uint32_t* indices, uint32_t size);
	};
}