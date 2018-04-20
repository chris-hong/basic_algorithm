#pragma once

#include "utils.h"

void SelectSort(int buf[], int size) {

	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (buf[j] < buf[min]) {
				min = j;
			}
		}
		Swap(buf, min, i);
	}
}
