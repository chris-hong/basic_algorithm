#include <iostream>
using namespace std;

bool IS_PRIME[4000001];
int PRIMES[300000];

int main() {

	int N;
	cin >> N;

	int TotalPrimeCount = 0;

	for (int i = 2; i <= 4000000; i++) {
		if (IS_PRIME[i]) continue;
		for (int j = i + i; j <= 4000000; j += i) {
			IS_PRIME[j] = true;
		}
	}

	for (int i = 2; i <= 4000000; i++) {
		if (!IS_PRIME[i]) {
			PRIMES[TotalPrimeCount++] = i;
		}
	}

	int COUNT = 0;
	int LEFT = 0;
	int RIGHT = 0;
	int sum = PRIMES[RIGHT++];

	while (RIGHT < TotalPrimeCount && LEFT < RIGHT) {

		if (sum < N) {
			sum += PRIMES[RIGHT++];
		}
		else if (sum > N) {
			sum -= PRIMES[LEFT++];
		}
		else {
			COUNT += 1;
			sum += PRIMES[RIGHT++];
			sum -= PRIMES[LEFT++];
		}
	}

	cout << COUNT << endl;

	return 0;
}