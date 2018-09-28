#include <iostream>
//#pragma warning(disable:4996)
using namespace std;

int VISIT[100][100];
int ROOM[100][100];

int N;
int M;

int MIN_COUNT = INT32_MAX;

void GO(int _N, int _M, int count) {
	VISIT[_N][_M] = count;

	if (_N + 1 == N && _M + 1 == M) {
		MIN_COUNT = MIN_COUNT > count ? count : MIN_COUNT;
		return;
	}

	if (_N + 1 < N && VISIT[_N + 1][_M] > ROOM[_N + 1][_M] + count) {
		GO(_N + 1, _M, ROOM[_N + 1][_M] + count);
	}
	if (_M + 1 < M && VISIT[_N][_M + 1] > ROOM[_N][_M + 1] + count) {
		GO(_N, _M + 1, ROOM[_N][_M + 1] + count);
	}
	if (_N - 1 >= 0 && VISIT[_N - 1][_M] > ROOM[_N - 1][_M] + count) {
		GO(_N - 1, _M, ROOM[_N - 1][_M] + count);
	}
	if (_M - 1 >= 0 && VISIT[_N][_M - 1] > ROOM[_N][_M - 1] + count) {
		GO(_N, _M - 1, ROOM[_N][_M - 1] + count);
	}
}

int main() {

	//freopen("input01.txt", "r", stdin);

	cin >> M >> N;

	for (int i = 0; i < 100; i++) {
		fill_n(VISIT[i], 100, INT32_MAX);
	}

	for (int i = 0; i < N; i++) {
		char* pStr = new char[101];
		cin >> pStr;
		for (int j = 0; j < M; j++) {
			ROOM[i][j] = pStr[j] - '0';
		}
		delete pStr;
	}

	GO(0, 0, 0);

	cout << MIN_COUNT << endl;

	return 0;
}