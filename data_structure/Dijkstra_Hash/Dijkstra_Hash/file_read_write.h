#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void File_Read_Write_Test() {
	std::string filePath = "test.txt";

	// write File
	std::ofstream writeFile(filePath);
	if (writeFile.is_open()) {
		writeFile << "Hello World!!" << std::endl;
		writeFile << "This is C++ File Contents" << std::endl;
		writeFile.close();
	}
	
	// read File
	std::ifstream openFile(filePath);
	if (openFile.is_open()) {
		std::string line;
		while (std::getline(openFile, line)) {
			std::cout << "Full line: " << line << std::endl;
			std::istringstream iss(line);
			std::string chunk;
			while (std::getline(iss, chunk, ' ')) {
				std::cout << chunk << std::endl;
			}
		}
		openFile.close();
	}
}