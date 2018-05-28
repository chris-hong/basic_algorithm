#include <iostream>
#include "quickSort.h"
using namespace std;

/*
<< �˰��� >>
�ڿ��� ���� �������� Ž���Ͽ� K�� K-1�� ���� ���Ͽ� K-1�� ���� K���� ���� K�� ���Ѵ�.(�����)
LEFT : K-1
RIGHT : K

�ڿ��� ���� �������� Ž���Ͽ� Left�� ������ ū ù��° ���� Left�� ���� ���� �ٲ۴�. (SWAP)

RIGHT ~ N �� ������ ���Ͽ� �������� ������ �Ѵ�. (����)

*/

int main() {
	ios::sync_with_stdio(false);

	int N;
	int buf[10001];
	int left = -1, right = -1;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> buf[i];
	}

	// left, right ����
	for (int i = N; i >= 1 + 1; i--) {
		if (buf[i - 1] < buf[i]) {
			left = i - 1;
			right = i;
			break;
		}
	}

	if (left == -1 && right == -1) {
		cout << -1 << endl;
		return 0;
	}

	// �� ���Ͽ� SWAP
	for (int i = N; i >= right; i--) {
		if (buf[left] < buf[i]) {
			SWAP(buf, left, i);
			break;
		}
	}

	// right ���� �κп� ���� ����
	QuickSort(buf, right, N);

	// ���
	for (int i = 1; i <= N; i++) {
		cout << buf[i] << " ";
	}
	cout << endl;

	return 0;
}