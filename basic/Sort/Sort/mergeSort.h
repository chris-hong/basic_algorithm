#pragma once

void Merge(int buf[], int start, int mid, int end, int _N) {
	int* temp = new int[_N];	// 임시 버퍼 생성
	int s = start;				// 앞단 인덱스
	int m = mid + 1;			// 뒷단 인덱스
	int idx = start;			// 임시 버퍼 복사 인덱스

	/* 앞단, 뒷단 순차적으로 비교해가며 작은 숫자가 발견되면 임시버퍼에 복사 */
	while (s <= mid && m <= end) {
		if (buf[s] < buf[m]) temp[idx++] = buf[s++];
		else temp[idx++] = buf[m++];
	}

	/* 잔여 내역 임시버퍼에 복사 */
	while (s <= mid) temp[idx++] = buf[s++];
	while (m <= end) temp[idx++] = buf[m++];

	/* 정렬된 임시버퍼 내용을 ORIGIN에 다시 복사 */
	for (int i = start; i <= end; i++) buf[i] = temp[i];
	delete temp;
}

void MergeSort(int buf[], int start, int end, int _N) {

	if (start < end) {
		int mid = (start + end) / 2;
		MergeSort(buf, start, mid, _N);
		MergeSort(buf, mid + 1, end, _N);
		Merge(buf, start, mid, end, _N);
	}
}
