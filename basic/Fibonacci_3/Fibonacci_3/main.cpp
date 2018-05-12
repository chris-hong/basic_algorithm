#include <iostream>

using namespace std;

long long Fibonacci_Recursion(int _N) {
	if (_N == 0) return 0;
	if (_N == 1) return 1;

	return Fibonacci_Recursion(_N - 1) + Fibonacci_Recursion(_N - 2);
}

long long Fibonacci_Dynamic(long long buf[], int _N) {
	// 값을 알고 있으면 바로 그 값 리턴
	if (buf[_N] != -1) return buf[_N];

	buf[_N] = Fibonacci_Dynamic(buf, _N - 1) + Fibonacci_Dynamic(buf, _N - 2);
	
	return buf[_N];
}

long long Fibonacci_Loop(long long buf[], int _N) {
	for (int idx = 2; idx <= _N; idx++) {
		buf[idx] = buf[idx - 1] + buf[idx - 2];
	}
	return buf[_N];
}

int main() {
	int N;
	cout << "FIBONACCI N: ";
	cin >> N; cin.get();

	long long* buffer = new long long[N + 1];
	for (int i = 0; i < N + 1; i++) buffer[i] = -1;
	buffer[0] = 0;
	buffer[1] = 1;
	
	cout << "FIBONACCI Recursion: " << Fibonacci_Recursion(N) << endl;
	cout << "FIBONACCI Dynamic: " << Fibonacci_Dynamic(buffer, N) << endl;
	cout << "FIBONACCI Loop: " << Fibonacci_Loop(buffer, N) << endl;

	delete buffer;

	getchar();
	return 0;
}