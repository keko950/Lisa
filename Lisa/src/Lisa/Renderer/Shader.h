#pragma once

#include <string>

#include "Lisa/Core.h"

namespace Lisa
{
	class LISA_API Shader
	{
	public:
		Shader(const std::string vertexPath, const std::string fragmentPath);
		~Shader();

		// use/activate the shader
		virtual void Bind() const;
		virtual void Unbind() const;

	private:
		uint32_t m_RenderId;
	};
}