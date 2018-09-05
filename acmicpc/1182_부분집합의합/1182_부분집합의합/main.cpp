#include <iostream>
//#pragma warning(disable:4996)
using namespace std;

int COUNT = 0;
int N, S;
int* pInputBuffer = NULL;
int* pBuf = NULL;

void PrintBuffer(int _R) {
	int sum = 0;
	for (int i = 0; i < _R; i++) {
		sum += pInputBuffer[pBuf[i]];
	}

	if (sum == S) COUNT += 1;
}

void Combination(int depth, int _N, int _R, int index) {
	if (depth == _R) {
		PrintBuffer(_R);
		return;
	}

	if (_N == index) return;

	pBuf[depth] = index;

	Combination(depth + 1, _N, _R, index + 1);
	Combination(depth, _N, _R, index + 1);
}


int main() {
	//freopen("input.txt", "r", stdin);

	cin >> N >> S;

	pInputBuffer = new int[N];
	pBuf = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> pInputBuffer[i];
	}

	for (int i = 1; i <= N; i++) {
		Combination(0, N, i, 0);
	}

	cout << COUNT << endl;

	delete pInputBuffer;
	delete pBuf;
	return 0;
}	