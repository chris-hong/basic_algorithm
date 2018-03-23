#pragma once
#include <vector>

void BubbleSort(std::vector<int>& buf, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (buf[j] > buf[j + 1]) {
				int temp = buf[j];
				buf[j] = buf[j + 1];
				buf[j + 1] = temp;
			}
		}
	}
}

void SelectSort(std::vector<int>& buf, int size) {
	
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (buf[j] < buf[min]) {
				min = j;
			}
		}
		int temp = buf[min];
		buf[min] = buf[i];
		buf[i] = temp;
	}
}
