#include "lspch.h"
#include "File.h"

#include <sstream>
#include <string>

Lisa::File::File()
{
}

Lisa::File::~File()
{
}

std::string Lisa::File::Read(const std::string path)
{
	std::ifstream ifs(path);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	return content;
}
