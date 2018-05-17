#include <iostream>

using namespace std;

int Max(int a, int b) {
	if (a > b) return a;
	else return b;
}

/*
D[N] = MAX(D[N-1]+P[1], D[N-2]+P[2], D[N-3]+P[3] .... + D[N-i]+P[i])
*/

int main() {
	int N;
	cin >> N; cin.get();

	int P[1001] = {};
	int DP[1001] = {};

	for (int i = 1; i <= N; i++) {
		cin >> P[i]; cin.get();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			DP[i] = Max(DP[i], DP[i - j] + P[j]);
		}
	}

	cout << "=> " << DP[N] << endl;

	getchar();
	return 0;
}