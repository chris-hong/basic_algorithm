#include <iostream>

using namespace std;

int Max3(int a, int b, int c) {
	int max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	return max;
}

int Max2(int a, int b) {
	if (a > b) return a;
	else return b;
}

int D[1001][1001];
int C[1001][1001];

//int main() {
//	int N, M;
//	cin >> N; cin.get();
//	cin >> M; cin.get();
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cin >> C[i][j]; cin.get();
//		}
//	}
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			// D[i][j] = Max3(D[i - 1][j - 1], D[i - 1][j], D[i][j - 1]) + C[i][j];
//			
//			/*
//			최대값을 구하는 이 문제에서..
//			N[N][M] -> [N+1][M+1] 
//			즉 대각선 이동은 생각하지 않아도 된다.
//			왜냐하면..
//			대각선 이동값은 → + ↓ or ↓ + → 값보다 작거나 같기 때문이다.
//			*/
//			D[i][j] = Max2(D[i - 1][j], D[i][j - 1]) + C[i][j];
//		}
//	}
//
//	cout << "=> " << D[N][M] << endl;
//
//	getchar();
//	return 0;
//
//}

// TOP-DOWN(재귀를 통한 풀이)
int MoreCandy(int i, int j) {
	if (i == 1 && j == 1) {
		return C[1][1];
	}
	if (i < 1 || j < 1) {
		return 0;
	}
	if (D[i][j] > 0) {
		return D[i][j];
	}
	
	D[i][j] = Max2(MoreCandy(i - 1, j), MoreCandy(i, j - 1)) + C[i][j];
	return D[i][j];
}

int main() {
	int N, M;
	cin >> N; cin.get();
	cin >> M; cin.get();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> C[i][j]; cin.get();
		}
	}

	cout << "=> " << MoreCandy(N, M) << endl;

	getchar();
	return 0;
}