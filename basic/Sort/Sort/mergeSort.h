#pragma once

void Merge(int buf[], int start, int mid, int end, int _N) {
	int* temp = new int[_N];	// �ӽ� ���� ����
	int s = start;				// �մ� �ε���
	int m = mid + 1;			// �޴� �ε���
	int idx = start;			// �ӽ� ���� ���� �ε���

	/* �մ�, �޴� ���������� ���ذ��� ���� ���ڰ� �߰ߵǸ� �ӽù��ۿ� ���� */
	while (s <= mid && m <= end) {
		if (buf[s] < buf[m]) temp[idx++] = buf[s++];
		else temp[idx++] = buf[m++];
	}

	/* �ܿ� ���� �ӽù��ۿ� ���� */
	while (s <= mid) temp[idx++] = buf[s++];
	while (m <= end) temp[idx++] = buf[m++];

	/* ���ĵ� �ӽù��� ������ ORIGIN�� �ٽ� ���� */
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
