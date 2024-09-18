#include "file_utils.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstddef>

bool readFile(const std::string &fileName ,std::string& content)
{
	std::ifstream ifs(fileName.c_str(), std::ios::binary);
	if (!ifs) {
		std::cerr << "Error: file not found" << std::endl;
		return false;
	}
	std::stringstream ss;
	ss << ifs.rdbuf();
	content = ss.str();
	return true;
}
