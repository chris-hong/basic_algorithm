#include <iostream>
using namespace std;

void Merge(char* pBuffer, int start, int mid, int end, int length) {
	int s = start;
	int m = mid + 1;
	int idx = start;

	char* pTemp = new char[length];

	while (s <= mid && m <= end) {
		if (pBuffer[s] < pBuffer[m]) {
			pTemp[idx] = pBuffer[s];
			s += 1;
			idx += 1;
		}
		else {
			pTemp[idx] = pBuffer[m];
			m += 1;
			idx += 1;
		}
	}

	while (s <= mid) {
		pTemp[idx] = pBuffer[s];
		s += 1;
		idx += 1;
	}

	while (m <= end) {
		pTemp[idx] = pBuffer[m];
		m += 1;
		idx += 1;
	}

	for (int i = start; i <= end; i++) {
		pBuffer[i] = pTemp[i];
	}

	delete pTemp;
}

void MergeSort(char* pBuffer, int start, int end, int length) {
	if (start < end) {
		int mid = (start + end) / 2;
		MergeSort(pBuffer, start, mid, length);
		MergeSort(pBuffer, mid + 1, end, length);
		Merge(pBuffer, start, mid, end, length);
	}
}

// 자음: typeA
// 모음: typeB

char TYPE_B[5] = {'a', 'e', 'i', 'o', 'u'};

bool IsTypeB(char ch) {
	for (int i = 0; i < 5; i++) {
		if (ch == TYPE_B[i]) 
			return true;
	}
	return false;
}

bool IsValidKey(char* pTemp, int L) {
	int typeA = 0;
	int typeB = 0;

	for (int i = 0; i < L; i++) {
		if (IsTypeB(pTemp[i])) {
			typeB += 1;
		}
		else {
			typeA += 1;
		}
	}

	if (typeA >= 2 && typeB >= 1)
		return true;

	return false;
}

void Trace(char* pBuffer, char* pTemp, int depth, int L, int C) {
	if (depth == L - 1) {
		if (IsValidKey(pTemp, L)) {
			for (int i = 0; i < L; i++) {
				cout << pTemp[i];
			}
			cout << endl;
		}
		return;
	}

	for (int i = 0; i < C; i++) {
		if (pTemp[depth] < pBuffer[i]) {
			pTemp[depth + 1] = pBuffer[i];
			Trace(pBuffer, pTemp, depth + 1, L, C);
		}
	}
}

int main() {
	int L, C;

	cin >> L;
	cin >> C;

	char* pBuffer = new char[C];

	for (int i = 0; i < C; i++) {
		cin >> pBuffer[i];
	}

	MergeSort(pBuffer, 0, C - 1, C);

	char* pTemp = new char[L];
	for (int i = 0; i < C; i++) {
		pTemp[0] = pBuffer[i];
		Trace(pBuffer, pTemp, 0, L, C);
	}

	delete pTemp;
	delete pBuffer;
	return 0;
}