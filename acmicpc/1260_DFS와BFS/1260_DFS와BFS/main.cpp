#include <iostream>
using namespace std;

struct Node {
	int num;
	struct Node* pNext;
};

class Stack {
public:
	Stack();
	~Stack();
	void Push(int num);
	int Pop();
	int Peek();
	int GetSize();
private:
	int mSize;
	struct Node* pTop;
};

Stack::Stack() {
	mSize = 0;
	pTop = NULL;
}

Stack::~Stack() {
	while (GetSize() > 0) {
		Pop();
	}
}

void Stack::Push(int num) {
	struct Node* pNode = new Node();
	pNode->num = num;
	pNode->pNext = NULL;

	if (pTop) pNode->pNext = pTop;
	pTop = pNode;

	mSize += 1;
}

int Stack::Pop() {
	if (!mSize && !pTop) return INT32_MIN;
	int ret = pTop->num;

	struct Node* pTemp = pTop;
	pTop = pTop->pNext;
	delete pTemp;

	mSize -= 1;

	return ret;
}

int Stack::Peek() {
	if (!mSize && !pTop) return INT32_MIN;
	return pTop->num;
}

int Stack::GetSize() {
	return mSize;
}

class Queue {
public:
	Queue();
	~Queue();
	void Enqueue(int num);
	int Dequeue();
	int GetSize();
private:
	int mSize;
	struct Node* pFirst;
	struct Node* pLast;
};

Queue::Queue() {
	mSize = 0;
	pFirst = NULL;
	pLast = NULL;
}

Queue::~Queue() {
	while (GetSize() > 0) {
		Dequeue();
	}
}

void Queue::Enqueue(int num) {
	struct Node* pNode = new Node();
	pNode->num = num;
	pNode->pNext = NULL;

	if (!pFirst) pFirst = pNode;
	if (pLast) pLast->pNext = pNode;
	pLast = pNode;
	mSize += 1;
}

int Queue::Dequeue() {
	if (!pFirst) return INT32_MIN;
	int ret = pFirst->num;

	struct Node* pTemp = pFirst;
	pFirst = pFirst->pNext;
	delete pTemp;
	mSize -= 1;

	if (!pFirst) pLast = NULL;

	return ret;
}

int Queue::GetSize() {
	return mSize;
}

void DFS_Stack(int** A, bool* bVisit, int start, int N) {
	Stack stack;
	stack.Push(start);
	cout << start << " ";
	bVisit[start] = true;

	while (stack.GetSize() > 0) {
		int from = stack.Peek();
		bool bPush = false;

		for (int next = 1; next <= N; next++) {
			if (A[from][next] && !bVisit[next]) {
				stack.Push(next);
				cout << next << " ";
				bVisit[next] = true;
				bPush = true;
				break;
			}
		}

		if (!bPush) {
			stack.Pop();
		}
	}
	cout << endl;
}

void BFS(int** A, bool* bVisit, int start, int N) {
	Queue Q;
	Q.Enqueue(start);
	bVisit[start] = true;

	while (Q.GetSize() > 0) {
		int from = Q.Dequeue();
		cout << from << " ";
		
		for (int next = 1; next <= N; next++) {
			if (A[from][next] && !bVisit[next]) {
				Q.Enqueue(next);
				bVisit[next] = true;
			}
		}
	}
	cout << endl;
}

int** makeAdjencyMatrix(int N) {
	int** A = new int*[N];
	for (int i = 0; i < N; i++) {
		A[i] = new int[N];
		fill_n(A[i], N, 0);
	}

	return A;
}

void clearAdjencyMatrix(int** A, int N) {
	for (int i = 0; i < N; i++) {
		delete A[i];
	}
	delete A;
}

int main() {
	int N;
	cin >> N;

	int M;
	cin >> M;

	int F;
	cin >> F;

	int** A = makeAdjencyMatrix(N + 1);
	bool* bVisit = new bool[N + 1];

	for (int i = 0; i < M; i++) {
		int S; cin >> S;
		int E; cin >> E;
		A[S][E] = 1;
		A[E][S] = 1;
	}

	fill_n(bVisit, N + 1, false);
	DFS_Stack(A, bVisit, F, N);

	fill_n(bVisit, N + 1, false);
	BFS(A, bVisit, F, N);

	clearAdjencyMatrix(A, N + 1);
	delete bVisit;

	return 0;
}