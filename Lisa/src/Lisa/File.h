#pragma once

#include "Lisa/Core.h"

#include <fstream>

namespace Lisa
{
	class LISA_API File
	{
	public:
		File();
		~File();

		static std::string Read(const std::string path);

	};
}