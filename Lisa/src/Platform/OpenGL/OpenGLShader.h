#pragma once

#include "Lisa/Renderer/Shader.h"

namespace Lisa {
	class LISA_API OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string vertexPath, const std::string fragmentPath);
		~OpenGLShader();

		void Bind() const override;
		void UnBind() const override;
	private:

	protected:
	};
}