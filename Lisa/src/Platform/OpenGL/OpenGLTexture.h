#pragma once
#include "Lisa/Core.h"
#include "Lisa/Renderer/Texture.h"

namespace Lisa {

	class LISA_API OpenGLTexture : public Texture {
	public:
		OpenGLTexture();

		virtual void Bind(TextureType type = TextureType::TEXTURE_2D) override;
		virtual void TextureFromImage(unsigned char* data, int width, int height, TextureType type, bool mipmap) override;
		virtual void TextureWrap(TextureType type, TextureWrapType wrap1, TextureWrapType wrap2) override;
		virtual void TextureFilter(TextureType type, TextureFilteringType filter1, TextureFilteringType filter2) override;
		virtual void TextureMipmap(TextureType type, MipmapType mipmap1, MipmapType mipmap2) override;

	private:
		unsigned int m_TextureId;




	};
}