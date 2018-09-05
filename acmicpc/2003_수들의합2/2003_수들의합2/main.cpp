#include <iostream>
//#pragma warning(disable:4996)
using namespace std;

int main() {
	//freopen("input01.txt", "r", stdin);
	
	int COUNT = 0;
	int N, M;
	cin >> N >> M;


	int* pInputBuffer = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> pInputBuffer[i];
	}

	for (int start = 0; start < N; start++) {
		int sum = 0;
		for (int i = start; i < N; i++) {
			sum += pInputBuffer[i];
			//if (i - start >= M) break;	있으나 마나???

			if (sum == M) {
				COUNT += 1;
				break;
			}
		}
	}

	cout << COUNT << endl;

	return 0;
}