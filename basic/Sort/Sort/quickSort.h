#pragma once

#include "utils.h"

int Partition(int buf[], int low, int high) {
	int left = low;
	int right = high;
	int pivot = buf[low];

	while (left < right) {
		while (buf[left] <= pivot) {
			left += 1;
		}
		while (buf[right] > pivot) {
			right -= 1;
		}
		if (left < right) {
			Swap(buf, left, right);
		}
	}

	buf[low] = buf[right];
	buf[right] = pivot;
	return right;
}

void QuickSort(int buf[], int low, int high) {
	if (low < high) {
		int pivot = Partition(buf, low, high);
		QuickSort(buf, low, pivot);
		QuickSort(buf, pivot + 1, high);
	}
}