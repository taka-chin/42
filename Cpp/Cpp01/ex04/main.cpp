#include "file_utils.hpp"
#include "string_utils.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cerr << "Invailed args" << std::endl;
		return(1);
	}
	std::string s1 = argv[1];
	std::string s2 = argv[2];
	if(s1.empty())
	{
		std::cerr << "Error: empty not allow" << std::endl;
		return(1);
	}
	const std::string fileName = argv[3];
	std::string inputStr;

	if(!readFile(fileName,inputStr))
		return(1);

	const std::string newFileName = fileName + ".replace";
	std::ofstream outputFile(newFileName.c_str());
	if (!outputFile) {
		std::cerr << "Error: file not found" << std::endl;
		return(1);
	}
	if(!replaceAndOutput(inputStr,s1,s2,outputFile))
	{
		outputFile.close();
		std::remove(newFileName.c_str());
		return(1);
	}

	return(0);
}
