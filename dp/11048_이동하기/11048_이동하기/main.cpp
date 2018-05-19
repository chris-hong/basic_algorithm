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
//			�ִ밪�� ���ϴ� �� ��������..
//			N[N][M] -> [N+1][M+1] 
//			�� �밢�� �̵��� �������� �ʾƵ� �ȴ�.
//			�ֳ��ϸ�..
//			�밢�� �̵����� �� + �� or �� + �� ������ �۰ų� ���� �����̴�.
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

// TOP-DOWN(��͸� ���� Ǯ��)
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