#include <iostream>
using namespace std;

int BUFFER[12];
int INPUT_BUFFER[12];

void Print_Buffer(int R) {
	for (int i = 0; i < R; i++) {
		cout << INPUT_BUFFER[BUFFER[i]] << " ";
	}
	cout << endl;
}

void Combination(int depth, int N, int R, int idx) {
	if (depth == R) {
		Print_Buffer(R);
		return;
	}

	if (idx == N) return;

	BUFFER[depth] = idx;

	Combination(depth + 1, N, R, idx + 1);
	Combination(depth, N, R, idx + 1);
}

int main() {

	while (true) {
		int N;
		cin >> N;

		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			cin >> INPUT_BUFFER[i];
		}
		Combination(0, N, 6, 0);
		cout << endl;
	}

	return 0;
}