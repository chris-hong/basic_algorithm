#include <iostream>

using namespace std;

/*
파도반수열만 보면..
1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12 ....
P[N] = P[N-2] + P[N-3]을 알수 있다.
그러나..
그림으로 보면..
P[N] = P[N-1] + P[N-5] 이다.
*/

int main() {
	int P[101] = {};

	int N;
	cin >> N; cin.get();

	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;

	for (int i = 6; i <= N; i++) {
		P[i] = P[i - 1] + P[i - 5];
	}

	cout << "=> " << P[N] << endl;

	getchar();
	return 0;
}