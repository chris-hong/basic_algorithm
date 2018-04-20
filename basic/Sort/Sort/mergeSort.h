#pragma once

void Merge(int buf[], int start, int mid, int end, int _N) {
	int* tempBuf = new int[_N];

	int s = start;
	int m = mid + 1;
	int idx = 0;

	while (s <= mid && m <= end) {
		if (buf[s] < buf[m]) {
			tempBuf[idx] = buf[s];
			idx++;
			s++;
		}
		else {
			tempBuf[idx] = buf[m];
			idx++;
			m++;
		}
	}

	for (int i = s; i <= mid; i++) {
		tempBuf[idx] = buf[i];
		idx++;
	}

	for (int i = m; i <= end; i++) {
		tempBuf[idx] = buf[i];
		idx++;
	}

	for (int i = start; i <= end; i++) {
		buf[i] = tempBuf[i - start];
	}

	delete tempBuf;
}

void MergeSort(int buf[], int start, int end, int _N) {

	if (start < end) {
		int mid = (start + end) / 2;

		MergeSort(buf, start, mid, _N);
		MergeSort(buf, mid + 1, end, _N);
		Merge(buf, start, mid, end, _N);
	}
}
