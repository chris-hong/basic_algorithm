#include <iostream>
#include "quickSort.h"
using namespace std;

/*
<< 알고리즘 >>
뒤에서 앞의 방향으로 탐색하여 K와 K-1의 값을 비교하여 K-1의 값이 K보다 큰 K를 구한다.(경계점)
LEFT : K-1
RIGHT : K

뒤에서 앞의 방향으로 탐색하여 Left의 값보다 작은 첫번째 값과 Left의 값을 서로 바꾼다. (SWAP)

RIGHT ~ N 의 영역에 대하여 내림차순 정렬을 한다. (정렬)

*/

int main() {
	ios::sync_with_stdio(false);

	int buf[10001];
	int N;
	int left = -1, right = -1;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> buf[i];
	}

	for (int i = N; i >= 1 + 1; i--) {
		if (buf[i - 1] > buf[i]) {
			left = i - 1;
			right = i;
			break;
		}
	}

	if (left == -1 && right == -1) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = N; i >= right; i--) {
		if (buf[left] > buf[i]) {
			SWAP(buf, left, i);
			break;
		}
	}

	QuickSort(buf, right, N);

	for (int i = 1; i <= N; i++) {
		cout << buf[i] << " ";
	}
	cout << endl;

	return 0;
}