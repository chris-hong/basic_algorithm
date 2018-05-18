#include <iostream>

using namespace std;

//int main() {
//	long long DP[91] = {};
//
//	int N;
//	cin >> N; cin.get();
//
//	DP[0] = 0;
//	DP[1] = 1;
//
//	for (int i = 2; i <= N; i++) {
//		DP[i] = DP[i - 1] + DP[i - 2];
//	}
//
//	cout << "=> " << DP[N] << endl;
//
//	getchar();
//	return 0;
//}

int main() {
	// DP[x][0] : 끝자리가 0으로 끝나는 경우
	// DP[x][1] : 끝자리가 1로 끝나는 경우
	long long DP[91][2] = {};	

	int N;
	cin >> N; cin.get();
	
	DP[1][0] = 0;
	DP[1][1] = 1;

	for (int i = 2; i <= N; i++) {
		DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
		DP[i][1] = DP[i - 1][0];
	}

	cout << "=> " << DP[N][0] + DP[N][1] << endl;

	getchar();
	return 0;
}