#pragma once
#include <iostream>
#include <vector>

int PRINT_COUNT = 0;

void Print_Buffer(std::vector<int>& buf, int length) {
	std::cout << "[" << ++PRINT_COUNT << "] ";
	for (int i = 0; i < length; i++) {
		std::cout << buf[i];
	}
	std::cout << std::endl;

}
