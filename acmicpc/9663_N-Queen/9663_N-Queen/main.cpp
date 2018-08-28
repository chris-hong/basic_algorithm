#include <iostream>
using namespace std;

bool* SELECT;			// 이미 선택한 INDEX 기록
bool* CROSS_RIGHT_UP;	// 이미 선택된 右上 대각선 INDEX 기록
bool* CROSS_RIGHT_DOWN;	// 이미 선택된 右下 대각선 INDEX 기록
int totalCount = 0;

int ABS(int num) {
	return num > 0 ? num : -num;
}

void N_Queen(int depth, int _N) {
	if (depth == _N) {
		totalCount += 1;
		return;
	}

	// 규칙성을 발견해보자
	// RIGHT_UP : depth + idx 의 값이 모두 같음
	// RIGHT_DOWN : depth - idx 의 값이 모두 같음 => 음수를 피하기 위하여 (N - 1) - (depth - idx)
	for (int idx = 0; idx < _N; idx++) {
		int rightUp = depth + idx;
		int rightDown = _N - 1 + depth - idx;
		if (SELECT[idx]) continue;
		if (CROSS_RIGHT_UP[rightUp]) continue;
		if (CROSS_RIGHT_DOWN[rightDown]) continue;	

		// 체크하고 DFS
		SELECT[idx] = true;
		CROSS_RIGHT_UP[rightUp] = true;
		CROSS_RIGHT_DOWN[rightDown] = true;

		N_Queen(depth + 1, _N);

		// 언체크 원복(Back-Tracking)
		SELECT[idx] = false;
		CROSS_RIGHT_UP[rightUp] = false;
		CROSS_RIGHT_DOWN[rightDown] = false;
	}
}

int main() {
	int N;
	cin >> N;

	SELECT = new bool[N];
	CROSS_RIGHT_UP = new bool[2 * N - 1];
	CROSS_RIGHT_DOWN = new bool[2 * N - 1];

	fill_n(SELECT, N, false);
	fill_n(CROSS_RIGHT_UP, 2 * N - 1, false);
	fill_n(CROSS_RIGHT_DOWN, 2 * N - 1, false);

	N_Queen(0, N);

	cout << totalCount << endl;

	delete SELECT;
	delete CROSS_RIGHT_UP;
	delete CROSS_RIGHT_DOWN;

	return 0;
}