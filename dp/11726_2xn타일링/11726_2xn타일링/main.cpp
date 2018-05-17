#include <iostream>

using namespace std;

int main() {
	int DP[1000];
	int N;
	cin >> N; cin.get();

	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= N; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	}

	cout << "=> " << DP[N] % 10007 << endl;

	getchar();
	return 0;
}