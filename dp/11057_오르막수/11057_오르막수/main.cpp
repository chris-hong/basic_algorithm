#include <iostream>

using namespace std;

#define MOD 10007

/*
N | 1  2  3   4   5 ... (자릿수)
--+-----------------
0 | 1  1  1   1   1
1 | 1  2  3   4   5
2 | 1  3  6  10  15
3 | 1  4 10  20  35
4 | 1  5 15  35  70
5 | 1  6 21  56 126
6 | 1  7 28  84 210
7 | 1  8 36 120 330
8 | 1  9 45 165 495
9 | 1 10 55 220 715  

=> 즉.. 세로로 다 더한 숫자가 해당 자릿수의 오르막 수의 총 갯수
*/

int main() {
	int DP[1001][10] = {};

	int N;
	cin >> N; cin.get();

	for (int i = 0; i < 10; i++) {
		DP[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		DP[i][0] = 1;

		for (int j = 1; j < 10; j++) {
			DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % MOD;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + DP[N][i]) % MOD;
	}

	cout << "=> " << sum << endl;

	getchar();
	return 0;
}