#include <iostream>

using namespace std;

/*
일단.. 3xN 모양에 1x2, 2x1 모양으로 타일을 채우는 경우는 N이 홀수인 경우는 방법의 수가 0이다..
즉.. 0이 되는 경우도 있다.
N번째 모양은 아래와 같이 8개의 경우 중 하나이고, N-1번째를 생각해보면 아래와 같다.
_________N_____N-1
TYPE 0: 000 => TYPE7
TYPE 1: 100 => TYPE6
TYPE 2: 010 => TYPE5
TYPE 3: 110 => TYPE7 + TYPE4
TYPE 4: 001 => TYPE3
TYPE 5: 101 => TYPE2
TYPE 6: 011 => TYPE7 + TYPE1
TYPE 7: 111 => TYPE0 + TYPE3 + TYPE6

따라서 점화식을 새워보면..
D[N][0] = D[N-1][7]
D[N][1] = D[N-1][6]
D[N][2] = D[N-1][5]
D[N][3] = D[N-1][7] + D[N-1][4]
D[N][4] = D[N-1][3]
D[N][5] = D[N-1][2]
D[N][6] = D[N-1][7] + D[N-1][1]
D[N][7] = D[N-1][0] + D[N-1][3] + D[N-1][6]
*/


int main() {
	int D[31][8] = {};

	int N;
	cin >> N; cin.get();

	D[0][7] = 1;	// D[0]의 경우는 TYPE7로 하나
	for (int i = 1; i <= N; i++) {
		D[i][0] = D[i - 1][7];
		D[i][1] = D[i - 1][6];
		D[i][2] = D[i - 1][5];
		D[i][3] = D[i - 1][7] + D[i - 1][4];
		D[i][4] = D[i - 1][3];
		D[i][5] = D[i - 1][2];
		D[i][6] = D[i - 1][7] + D[i - 1][1];
		D[i][7] = D[i - 1][0] + D[i - 1][3] + D[i - 1][6];
	}

	cout << "=> " << D[N][7] << endl;	// 3*N 모양을 가득 채우는 경우(TYPE7) 

	getchar();
	return 0;
}