#pragma once

void InsertSort(int buf[], int size) {
	int tmp;

	for (int i = 1; i < size; i++) {
		tmp = buf[i];
		int idx = i;

		while (idx > 0 && buf[idx - 1] > tmp) {
			buf[idx] = buf[idx - 1];
			idx--;
		}
		buf[idx] = tmp;
	}
}