#include <iostream>
using namespace std;

bool* SELECT;			// �̹� ������ INDEX ���
bool* CROSS_RIGHT_UP;	// �̹� ���õ� ��߾ �밢�� INDEX ���
bool* CROSS_RIGHT_DOWN;	// �̹� ���õ� ���� �밢�� INDEX ���
int totalCount = 0;

int ABS(int num) {
	return num > 0 ? num : -num;
}

void N_Queen(int depth, int _N) {
	if (depth == _N) {
		totalCount += 1;
		return;
	}

	// ��Ģ���� �߰��غ���
	// RIGHT_UP : depth + idx �� ���� ��� ����
	// RIGHT_DOWN : depth - idx �� ���� ��� ���� => ������ ���ϱ� ���Ͽ� (N - 1) - (depth - idx)
	for (int idx = 0; idx < _N; idx++) {
		int rightUp = depth + idx;
		int rightDown = _N - 1 + depth - idx;
		if (SELECT[idx]) continue;
		if (CROSS_RIGHT_UP[rightUp]) continue;
		if (CROSS_RIGHT_DOWN[rightDown]) continue;	

		// üũ�ϰ� DFS
		SELECT[idx] = true;
		CROSS_RIGHT_UP[rightUp] = true;
		CROSS_RIGHT_DOWN[rightDown] = true;

		N_Queen(depth + 1, _N);

		// ��üũ ����(Back-Tracking)
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