#pragma once
void SWAP(int buf[], int i, int j) {
	int temp = buf[i];
	buf[i] = buf[j];
	buf[j] = temp;
}

int Partition(int buf[], int start, int end) {
	int front = start + 1;
	int back = start;
	int pivot = start;

	for (; front <= end; front++) {
		if (buf[front] > buf[pivot]) {
			back += 1;
			SWAP(buf, front, back);
		}
	}
	SWAP(buf, pivot, back);
	return back;
}

void QuickSort(int buf[], int start, int end) {
	if (start < end) {
		int pivot = Partition(buf, start, end);
		QuickSort(buf, start, pivot - 1);
		QuickSort(buf, pivot + 1, end);
	}
}