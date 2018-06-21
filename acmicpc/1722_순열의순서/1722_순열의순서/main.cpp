#include <iostream>
using namespace std;

long long int factorial[21] = { 1 };
bool checked[21] = { false };

int main() {
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int O;
	cin >> O;

	for (int i = 1; i <= N; i++) {
		factorial[i] = factorial[i - 1] * i;
	}

	if (O == 1) {
		long long K;
		cin >> K;
		int answer[20];

		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				if (checked[j]) continue;

				if (factorial[N - i - 1] < K) {
					K -= factorial[N - i - 1];
				}
				else {
					answer[i] = j;
					checked[j] = true;
					break;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			cout << answer[i] << ' ';
		}
		cout << endl;
	}
	else {
		int input[20];

		for (int i = 0; i < N; i++) {
			cin >> input[i];
		}

		long long sum = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 1; j < input[i]; j++) {
				if (checked[j]) continue;

				sum += factorial[N - i - 1];
			}
			checked[input[i]] = true;
		}
		
		cout << sum + 1 << endl;
	}

	return 0;
}