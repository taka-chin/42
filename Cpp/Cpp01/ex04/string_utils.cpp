#include "string_utils.hpp"
#include <string>
#include <cstddef>
#include <iostream>

bool replaceAndOutput(std::string& content, const std::string& s1, const std::string& s2, std::ofstream& outputFile) {
    std::size_t pos = 0;
    while (true) {
        std::size_t tmpPos = content.find(s1, pos);
        if (tmpPos == std::string::npos) {
            outputFile << content.substr(pos);
						if (outputFile.fail()) {
                std::cerr << "Error: writing to file failed" << std::endl;
                return false;
            }
            break;
        }
        outputFile << content.substr(pos, tmpPos - pos) << s2;
				            if (outputFile.fail()) {
                std::cerr << "Error: writing to file failed" << std::endl;
                return false;
            }
        pos = tmpPos + s1.length();
				
    }
		return true;
}

