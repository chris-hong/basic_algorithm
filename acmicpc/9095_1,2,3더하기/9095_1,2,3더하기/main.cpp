#include <iostream>
using namespace std;

int main() {
	int T[11];
	fill_n(T, 11, 0);

	T[1] = 1;
	T[2] = 2;
	T[3] = 4;
	
	for (int i = 4; i < 11; i++) {
		T[i] = T[i-1] + T[i-2] + T[i-3];
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int ans;
		cin >> ans;
		cout << T[ans] << endl;
	}

	return 0;
}