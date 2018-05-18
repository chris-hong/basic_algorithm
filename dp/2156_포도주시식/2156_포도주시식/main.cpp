#include <iostream>

using namespace std;

/*
1차원배열 이용 방법
A[N] : N번째 컵의 포도주 양
D[N] : 1 ~ N 잔까지 규칙을 지키며 포도주를 먹었을때 가능한 최대량
=> N잔에서 3가지 경우 가능하고 그때의 값은 아래와 같다.
1) 안마신다 : D[N-1] 
2) 첫잔 : D[N-2] + A[N]
3) 두번째잔 : D[N-3] + A[N-1] + A[N]
=> 최대량이므로 MAX(1,2,3)
*/

int Max(int a, int b, int c) {
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	return max;
}

int main() {
	int A[10001] = {};
	int D[10001] = {};
	
	int N;
	cin >> N; cin.get();
	
	for (int i = 1; i <= N; i++) {
		cin >> A[i]; cin.get();
	}

	D[1] = A[1];
	D[2] = A[1] + A[2];

	for (int i = 3; i <= N; i++) {
		D[i] = Max(D[i - 1],
				D[i - 2] + A[i],
				D[i - 3] + A[i - 1] + A[i]);
	}

	cout << "=> " << D[N] << endl;

	getchar();
	return 0;
}