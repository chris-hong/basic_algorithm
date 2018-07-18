#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

/*
<5x5 예시>
01010
10001
00010
10100
01000
*/

int** MakeAdjacencyMatrix(int N) {
	int TEMP[5][5] = { {0,1,0,1,0}, {1,0,0,0,1}, {0,0,0,1,0}, {1,0,1,0,0}, {0,1,0,0,0} };
	
	// 저장공간 할당
	int** adjMatrix = new int*[N];
	for (int i = 0; i < N; i++) {
		adjMatrix[i] = new int[N];
	}

	// 인접행렬 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cin >> adjMatrix[i][j];
			adjMatrix[i][j] = TEMP[i][j];
		}
	}
	return adjMatrix;
}

void DFS_Stack(int** ppA, bool* pbVisit, int from, int N) {
	Stack stack;
	stack.Push(from);
	pbVisit[from] = true;
	cout << "[DFS_Stack] Visit: " << from << endl;

	while (stack.getSize() > 0) {
		int current = stack.Peek();
		bool isPushed = false;

		for (int next = 0; next < N; next++) {
			if (!pbVisit[next] && ppA[current][next]) {
				stack.Push(next);
				pbVisit[next] = true;
				cout << "[DFS_Stack] Visit: " << next << endl;
				isPushed = true;
				break;
			}
		}

		if (!isPushed) stack.Pop();
	}
}

void DFS_Recursion(int** ppA, bool* pbVisit, int from, int N) {
	pbVisit[from] = true;
	cout << "[DFS_Recursion] Visit[" << from << "]" << endl;

	for (int next = 0; next < N; next++) {
		if (!pbVisit[next] && ppA[from][next]) {
			DFS_Recursion(ppA, pbVisit, next, N);
		}
	}
}

void BFS(int** ppA, bool* pbVisit, int from, int N) {
	Queue queue;
	queue.Enqueue(from);
	pbVisit[from] = true;

	while (queue.getSize() > 0) {
		int current = queue.Dequeue();
		cout << "[BFS] Visit[" << current << "]" << endl;

		for (int i = 0; i < N; i++) {
			if (!pbVisit[i] && ppA[current][i]) {
				queue.Enqueue(i);
				pbVisit[i] = true;
			}
		}
	}
}

int main() {
	int N;
	//cin >> N;
	N = 5;

	int** adjacencyMatrix = MakeAdjacencyMatrix(N);
	bool* isVisit = new bool[N];
	
	fill_n(isVisit, N, false);
	DFS_Stack(adjacencyMatrix, isVisit, 0, N);

	fill_n(isVisit, N, false);
	DFS_Recursion(adjacencyMatrix, isVisit, 0, N);

	fill_n(isVisit, N, false);
	BFS(adjacencyMatrix, isVisit, 0, N);

	return 0;
}