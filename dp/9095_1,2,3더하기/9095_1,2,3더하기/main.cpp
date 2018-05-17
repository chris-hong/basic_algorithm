#include <iostream>

using namespace std;

int main() {
	int DP[11];

	int N;
	cin >> N; cin.get();

	//DP[0] = 0;	// 이건 표현될 수 없음. 1, 2, 3 더하기므로.. 성립불가.. 게다가 계산도 안맞음.
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	
	for (int i = 4; i <= N; i++) {
		DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1];
	}

	cout << "=> " << DP[N] << endl;

	getchar();
	return 0;
}