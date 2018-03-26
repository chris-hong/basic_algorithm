#pragma once
#include <vector>

void Swap(std::vector<int>& buf, int i, int j) {
	int temp = buf[i];
	buf[i] = buf[j];
	buf[j] = temp;
}

void BubbleSort(std::vector<int>& buf, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (buf[j] > buf[j + 1]) {
				Swap(buf, j, j + 1);
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
		Swap(buf, min, i);
	}
}

void InsertSort(std::vector<int>& buf, int size) {
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


void Merge(std::vector<int>& buf, int start, int mid, int end) {
	std::vector<int> tempBuf;
	
	int s = start;
	int m = mid + 1;

	while (s <= mid && m <= end) {
		if (buf[s] < buf[m]) {
			tempBuf.push_back(buf[s]);
			s++;
		}
		else {
			tempBuf.push_back(buf[m]);
			m++;
		}
	}

	for (int i = s; i <= mid; i++) {
		tempBuf.push_back(buf[i]);
	}

	for (int i = m; i <= end; i++) {
		tempBuf.push_back(buf[i]);
	}

	for (int i = start; i <= end; i++) {
		buf[i] = tempBuf[i - start];
	}
}

void MergeSort(std::vector<int>& buf, int start, int end) {

	if (start < end) {
		int mid = (start + end) / 2;

		MergeSort(buf, start, mid);
		MergeSort(buf, mid + 1, end);
		Merge(buf, start, mid, end);
	}
}

void QuickSort(std::vector<int>& buf, int left, int right) {
	int pivot = left;
	int j = pivot;
	int i = left + 1;

	if (left < right) {
		for (; i <= right; i++) {
			if (buf[i] < buf[pivot]) {
				j++;
				Swap(buf, i, j);
			}
		}
		Swap(buf, j, pivot);
		pivot = j;

		QuickSort(buf, left, pivot - 1);
		QuickSort(buf, pivot + 1, right);
	}
}

