#include <iostream>
//#pragma warning(disable:4996)
using namespace std;

int N, S;
int INPUT[100000];
int MIN_COUNT = INT32_MAX;

int main() {
	//freopen("input02.txt", "r", stdin);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> INPUT[i];
	}

	int left = 0;
	int right = 0;
	
	int sum = INPUT[0];

	while (left <= right && right < N) {
		if (sum >= S) {
			int range = right - left + 1;
			MIN_COUNT = MIN_COUNT > range ? range : MIN_COUNT;
			sum -= INPUT[left];
			left += 1;
		}
		else {
			right += 1;
			sum += INPUT[right];
		}
	}

	if (MIN_COUNT == INT32_MAX) MIN_COUNT = 0;

	cout << MIN_COUNT << endl;

	return 0;
}