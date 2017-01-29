#pragma once

#include <vector>
namespace Piston {

	class IOManager
	{
	public:
		static bool readFileBuffer(std::string filePath, std::vector<unsigned char>& buffer);
	};
}
