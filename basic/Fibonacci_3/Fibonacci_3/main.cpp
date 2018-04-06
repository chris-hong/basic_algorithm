#include <iostream>
#include <vector>

using namespace std;

long long fibo_recursion(int _N) {
	if (_N == 0) return 0;
	if (_N == 1) return 1;

	return fibo_recursion(_N - 1) + fibo_recursion(_N - 2);
}

long long fibo_dynamic(vector<long long>& buffer, int _N) {
	if (buffer[_N] != -1) {
		return buffer[_N];
	}

	buffer[_N] = fibo_dynamic(buffer, _N - 1) + fibo_dynamic(buffer, _N - 2);
	return buffer[_N];
}

long long fibo_iteration(vector<long long>& buffer, int _N) {
	for (int i = 2; i <= _N; i++) {
		buffer[i] = buffer[i - 1] + buffer[i - 2];
	}
	return buffer[_N];
}

int main() {
	int N;
	cout << "N: ";
	cin >> N; cin.get();

	//cout << "Fibonacci Recursion[" << N << "]: " << fibo_recursion(N) << endl;

	vector<long long> buffer(N + 1, -1);
	buffer[0] = 0;
	buffer[1] = 1;
	//cout << "Fibonacci Dynamic[" << N << "]: " << fibo_dynamic(buffer, N) << endl;

	cout << "Finonacci Iteration[" << N << "]: " << fibo_iteration(buffer, N) << endl;

	getchar();
	return 0;
}