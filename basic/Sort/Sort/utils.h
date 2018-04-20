#pragma once

void Swap(int buf[], int i, int j) {
	int temp = buf[i];
	buf[i] = buf[j];
	buf[j] = temp;
}
