#pragma once

#include "utils.h"

void BubbleSort(int buf[], int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (buf[j] > buf[j + 1]) {
				Swap(buf, j, j + 1);
			}
		}
	}
}