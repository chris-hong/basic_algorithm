#include <iostream>
using namespace std;

bool CHECK[10000];
int PARENT[10000];
char OP_MAP[10000];

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
	while (GetSize()) {
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
	if (!pTop) return INT32_MIN;

	int ret = pTop->num;
	struct Node* pTemp = pTop;
	pTop = pTop->pNext;
	delete pTemp;

	mSize -= 1;

	return ret;
}

int Stack::GetSize() {
	return mSize;
}

class Queue {
public:
	Queue();
	~Queue();
	void Push(int num);
	int Pop();
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
	while (GetSize()) {
		Pop();
	}
}

void Queue::Push(int num) {
	struct Node* pNode = new Node();
	pNode->num = num;
	pNode->pNext = NULL;

	if (!pFirst) pFirst = pNode;
	if (pLast) pLast->pNext = pNode;
	pLast = pNode;
	mSize += 1;
}

int Queue::Pop() {
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

int OP_D(int num) {
	return (2 * num) % 10000;
}

int OP_S(int num) {
	if (num == 0) return 9999;
	int ret = num - 1;
	return ret;
}

int OP_L(int num) {
	int j1000 = num / 1000;
	int j100 = (num % 1000) / 100;
	int j10 = (num % 100) / 10;
	int j1 = num % 10;
	return (j100 * 1000) + (j10 * 100) + (j1 * 10) + j1000;
}

int OP_R(int num) {
	int j1000 = num / 1000;
	int j100 = (num % 1000) / 100;
	int j10 = (num % 100) / 10;
	int j1 = num % 10;
	return (j1 * 1000) + (j1000 * 100) + (j100 * 10) + j10;
}

void DFS_DSLR(int start, int end) {
	Queue queue;
	queue.Push(start);
	PARENT[start] = INT32_MIN;
	CHECK[start] = true;

	while (queue.GetSize()) {

		int current = queue.Pop();

		// 종료조건
		if (current == end) {
			Stack stack;
			int backTrace = current;
			while (backTrace != INT32_MIN) {
				stack.Push(backTrace);
				backTrace = PARENT[backTrace];
			}

			while (stack.GetSize())	{
				char dp = OP_MAP[stack.Pop()];
				if (dp) cout << dp;
			}
			cout << endl;
			
			break;
		}

		// 검사
		int RES_D = OP_D(current);
		if (!CHECK[RES_D]) {
			queue.Push(RES_D);
			OP_MAP[RES_D] = 'D';
			PARENT[RES_D] = current;
			CHECK[RES_D] = true;
		}

		int RES_S = OP_S(current);
		if (!CHECK[RES_S]) {
			queue.Push(RES_S);
			OP_MAP[RES_S] = 'S';
			PARENT[RES_S] = current;
			CHECK[RES_S] = true;
		}

		int RES_L = OP_L(current);
		if (!CHECK[RES_L]) {
			queue.Push(RES_L);
			OP_MAP[RES_L] = 'L';
			PARENT[RES_L] = current;
			CHECK[RES_L] = true;
		}

		int RES_R = OP_R(current);
		if (!CHECK[RES_R]) {
			queue.Push(RES_R);
			OP_MAP[RES_R] = 'R';
			PARENT[RES_R] = current;
			CHECK[RES_R] = true;
		}
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		fill_n(CHECK, 10000, false);
		fill_n(PARENT, 10000, 0);
		fill_n(OP_MAP, 10000, 0);
		int start, end;
		cin >> start >> end;
		DFS_DSLR(start, end);
	}

	return 0;
}
