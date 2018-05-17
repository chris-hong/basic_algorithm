#include <iostream>

using namespace std;

int Min(int a, int b) {
	if (a < b) return a;
	else return b;
}

int DP[1000001];

int main() {
	int N;
	cin >> N; cin.get();

	DP[1] = 0;

	for (int i = 2; i <= N; i++) {
		DP[i] = DP[i - 1] + 1;
		
		if (i % 2 == 0) {
			DP[i] = Min(DP[i], DP[i / 2] + 1);
		}
		if (i % 3 == 0) {
			DP[i] = Min(DP[i], DP[i / 3] + 1);
		}
	}

	cout << "Minimum: " << DP[N] << endl;

	getchar();
	return 0;
}
