#pragma once

#include <string>

#include "Lisa/Core.h"

namespace Lisa
{
	class LISA_API Shader
	{
	public:
		~Shader() = default;

		// use/activate the shader
		virtual void Bind() const {};
		virtual void UnBind() const {};

		static Shader* Create(const std::string vertexSrc, const std::string fragmentSrc);

	protected:
		uint32_t m_RenderId;
	};
}