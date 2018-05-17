#include <iostream>

using namespace std;

#define MOD 1000000000

/*
N | 1 2 3 4 5 ... (자릿수)
--+--------------
0 | 0 1 1 3 4
1 | 1 1 3 4 10
2 | 1 2 3 7 11
3 | 1 2 4 7 15
4 | 1 2 4 8 15
5 | 1 2 4 8 16
6 | 1 2 4 8 15
7 | 1 2 4 7 14
8 | 1 2 3 6 10
9 | 1 1 2 3 6
(끝자리에 등장할 수 있는 숫자)
=> 즉.. 세로로 다 더한 숫자가 그 자릿수의 계단수의 갯수
*/

int main() {
	int N;
	int DP[101][10] = {};
	
	cin >> N; cin.get();

	for (int i = 1; i < 10; i++) {
		DP[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				DP[i][j] = DP[i - 1][j + 1] % MOD;
			}
			else if (j == 9) {
				DP[i][j] = DP[i - 1][j - 1] % MOD;
			}
			else {
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
			}
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