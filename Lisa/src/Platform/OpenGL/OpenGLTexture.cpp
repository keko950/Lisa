#include "lspch.h"
#include "OpenGLTexture.h"
#include "GLFW/glfw3.h"
#include <glad\glad.h>
#include "Lisa.h"
#include <optional>

namespace Lisa {

	static GLenum TextureWrapDataTypeToGL(TextureWrapType type)
	{
		switch (type)
		{
		case TextureWrapType::CLAMP_BORDER:	return GL_CLAMP_TO_BORDER;
		case TextureWrapType::CLAMP_EDGE:	return GL_CLAMP_TO_EDGE;
		case TextureWrapType::REPEAT:		return GL_REPEAT;
		case TextureWrapType::MIRROR:		return GL_MIRRORED_REPEAT;
		}

		LS_CORE_ASSERT(false, "Unknown wrapper type");
		return 0;
	}

	static GLenum TextureFilterDataTypeToGL(TextureFilteringType type)
	{
		switch (type)
		{
		case TextureFilteringType::LINEAR:	return GL_LINEAR;
		case TextureFilteringType::NEAREST:	return GL_NEAREST;
		}

		LS_CORE_ASSERT(false, "Unknown filter type");
		return 0;
	}

	static GLenum TextureTypeToGL(TextureType type)
	{
		switch (type)
		{
		case TextureType::TEXTURE_2D:	return GL_TEXTURE_2D;
		case TextureType::TEXTURE_3D:	return GL_TEXTURE_3D;
		}

		LS_CORE_ASSERT(false, "Unknown texture type");
		return 0;
	}

	static GLenum TextureMipmapDataTypeToGL(MipmapType type)
	{
		switch (type)
		{
		case MipmapType::LINEAR_LINEAR:		return GL_LINEAR_MIPMAP_LINEAR;
		case MipmapType::NEAREST_LINEAR:	return GL_NEAREST_MIPMAP_LINEAR;
		case MipmapType::LINEAR_NEAREST:	return GL_LINEAR_MIPMAP_NEAREST;
		case MipmapType::NEAREST_NEAREST:	return GL_NEAREST_MIPMAP_NEAREST;
		}

		LS_CORE_ASSERT(false, "Unknown mipmap type");
		return 0;
	}

	OpenGLTexture::OpenGLTexture()
	{
		glGenTextures(1, &m_TextureId);
	}

	void OpenGLTexture::Bind(TextureType type)
	{
		switch (type)
		{
		case TextureType::TEXTURE_2D:
			glBindTexture(GL_TEXTURE_2D, m_TextureId);
			break;
		case TextureType::TEXTURE_3D:
			glBindTexture(GL_TEXTURE_3D, m_TextureId);
			break;
		default:
			LS_CORE_ASSERT(false, "Unsupported texture type supplied");
			break;
		}
	}

	void OpenGLTexture::TextureWrap(TextureType type, TextureWrapType wrap1, TextureWrapType wrap2)
	{
		glTexParameteri(TextureTypeToGL(type), GL_TEXTURE_WRAP_S, TextureWrapDataTypeToGL(wrap1));
		glTexParameteri(TextureTypeToGL(type), GL_TEXTURE_WRAP_T, TextureWrapDataTypeToGL(wrap2));
	}

	void OpenGLTexture::TextureFilter(TextureType type, TextureFilteringType filter1, TextureFilteringType filter2)
	{
		glTexParameteri(TextureTypeToGL(type), GL_TEXTURE_MIN_FILTER, TextureFilterDataTypeToGL(filter1));
		glTexParameteri(TextureTypeToGL(type), GL_TEXTURE_MAG_FILTER, TextureFilterDataTypeToGL(filter2));
	}

	void OpenGLTexture::TextureMipmap(TextureType type, MipmapType mipmap1, MipmapType mipmap2)
	{
		glTexParameteri(TextureTypeToGL(type), GL_TEXTURE_MIN_FILTER, TextureMipmapDataTypeToGL(mipmap1));
		glTexParameteri(TextureTypeToGL(type), GL_TEXTURE_MAG_FILTER, TextureMipmapDataTypeToGL(mipmap2));
	}

	void OpenGLTexture::TextureFromImage(unsigned char* data, int width, int height, TextureType type, bool mipmap)
	{
	}

	//TODO:
	//glTextParameterFV for bordercolor
}


