#pragma once
#include "Lisa/Core.h"

namespace Lisa {

	enum class TextureType
	{
		TEXTURE_2D = 0, TEXTURE_3D
	};

	enum class TextureWrapType
	{
		REPEAT = 0, MIRROR, CLAMP_EDGE, CLAMP_BORDER
	};

	enum class TextureFilteringType
	{
		NEAREST = 0, LINEAR
	};

	enum class MipmapType
	{
		NEAREST_NEAREST = 0, LINEAR_NEAREST, NEAREST_LINEAR, LINEAR_LINEAR
	};

	class LISA_API Texture {
	public:
		Texture* Create();

		virtual void Bind(TextureType type = TextureType::TEXTURE_2D) = 0;
		virtual void TextureWrap(TextureType type, TextureWrapType wrap1, TextureWrapType wrap2) = 0;
		virtual void TextureFilter(TextureType type, TextureFilteringType filter1, TextureFilteringType filter2) = 0;
		virtual void TextureMipmap(TextureType type, MipmapType mipmap1, MipmapType mipmap2) = 0;
		virtual void TextureFromImage(unsigned char* data, int width, int height, TextureType type, bool mipmap) = 0;

	private:
		Texture* m_Instance;
	};

}