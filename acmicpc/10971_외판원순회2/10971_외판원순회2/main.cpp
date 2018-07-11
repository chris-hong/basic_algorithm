#include <iostream>
using namespace std;

int idxBuffer[10];
int weight[10][10];
int finalMinCost = INT32_MAX;

int MIN(int a, int b) {
	if (a > b) return b;
	else return a;
}

void Right_Rotate(int start, int end) {
	int last = idxBuffer[end];
	for (int i = end; i > start; i--) {
		idxBuffer[i] = idxBuffer[i - 1];
	}
	idxBuffer[start] = last;
}

void Left_Rotate(int start, int end) {
	int first = idxBuffer[start];
	for (int i = start; i < end; i++) {
		idxBuffer[i] = idxBuffer[i + 1];
	}
	idxBuffer[end] = first;
}

void Print_Buffer(int N) {
	for (int i = 0; i < N; i++) {
		cout << idxBuffer[i] << " ";
	}
	cout << endl;
}

void Permutation(int depth, int N) {
	if (depth == N) {
		// Check Distance
		int totalDistance = 0;
		int startPoint = idxBuffer[0];
		int endPoint = idxBuffer[N - 1];
		for (int i = 1; i < N; i++) {
			int from = idxBuffer[i - 1];
			int to = idxBuffer[i];
			int dist1 = weight[from][to];
			if (dist1 > 0) {
				totalDistance += dist1;
			}
			else {
				return;
			}
		}
		int dist2 = weight[endPoint][startPoint];
		if (dist2 > 0) {
			totalDistance += dist2;
		}
		else {
			return;
		}

		/*if (finalMinCost > distance) {
			finalMinCost = MIN(finalMinCost, distance);
			Print_Buffer(N);
		}*/
		finalMinCost = MIN(finalMinCost, totalDistance);
	}

	for (int i = depth; i < N; i++) {
		Right_Rotate(depth, i);
		Permutation(depth + 1, N);
		Left_Rotate(depth, i);
	}
}

int main() {
	int N;
	cin >> N;

	// Weight값 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> weight[i][j];
		}
	}

	// 순열 초기화
	for (int i = 0; i < N; i++) {
		idxBuffer[i] = i;
	}

	Permutation(0, N);

	cout << finalMinCost << endl;
	return 0;
}