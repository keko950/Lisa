#pragma once

#include "Lisa/Core.h"

#include <fstream>

namespace Lisa
{
	namespace File
	{
		std::string Read(const std::string path)
		{
			std::ifstream ifs(path);
			std::string content((std::istreambuf_iterator<char>(ifs)),
				(std::istreambuf_iterator<char>()));
			return content;
		}
	}
}

