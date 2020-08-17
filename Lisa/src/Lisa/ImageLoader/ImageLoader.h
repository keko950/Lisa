#pragma once
#include "Lisa/Core.h"

namespace Lisa {
	class LISA_API ImageLoader {
	public:
		static unsigned char* load(std::string imageName, int width, int height, int channels) {
			unsigned char* data = stbi_load(imageName.c_str(), &width, &height, &channels, 0);
			return data;
		}
	};
}

