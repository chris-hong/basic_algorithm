#include <iostream>
#include <cmath>
//#include <Windows.h>
using namespace std;

bool IS_COMPOSITE[4000001];
int PRIMES[300000];

//LARGE_INTEGER Frequency;
//LARGE_INTEGER BeginTime;
//LARGE_INTEGER EndTime;

int main() {
	/*QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&BeginTime);*/

	int N;
	cin >> N;

	int TotalPrimeCount = 0;

	for (int i = 2; i <= sqrt(N); i++) {
		if (IS_COMPOSITE[i]) continue;
		for (int j = i + i; j <= N; j += i) {
			IS_COMPOSITE[j] = true;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (!IS_COMPOSITE[i]) {
			PRIMES[TotalPrimeCount++] = i;
		}
	}

	int COUNT = 0;
	int LEFT = 0;
	int RIGHT = 0;
	int sum = PRIMES[RIGHT++];

	while (RIGHT <= TotalPrimeCount && LEFT < RIGHT) {

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

	/*QueryPerformanceCounter(&EndTime);
	long long elapsed = EndTime.QuadPart - BeginTime.QuadPart;
	double duringTime = (double)elapsed / (double)Frequency.QuadPart;*/
	
	cout << COUNT << endl;
	//cout << duringTime << endl;

	return 0;
}