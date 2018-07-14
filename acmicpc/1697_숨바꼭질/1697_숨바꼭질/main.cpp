#include <iostream>
using namespace std;

struct Node {
	int num;
	struct Node* pNext;
};

class Queue {
public:
	Queue();
	~Queue();
	int getSize();
	void Push(int num);
	int Pop();

private:
	int mSize;
	struct Node* pFirst;
	struct Node* pLast;
};

Queue::Queue() {
	mSize = 0;
}

Queue::~Queue() {
	int size = getSize();
	for (int i = 0; i < size; i++) {
		Pop();
	}
}

int Queue::getSize() {
	return mSize;
}

void Queue::Push(int num) {
	struct Node* pNode = new Node();
	pNode->num = num;

	if (mSize == 0) {
		pFirst = pNode;
		pLast = pNode;
	}
	else {
		pLast->pNext = pNode;
		pLast = pNode;
	}

	mSize += 1;
}

int Queue::Pop() {
	if (mSize == 0) return -1;

	int ret = pFirst->num;
	struct Node* pTemp = pFirst;
	pFirst = pFirst->pNext;
	delete pTemp;

	mSize -= 1;

	return ret;
}

int N, K;
int DEPTH[100001];		// 생성되는 숫자의 Depth를 저장하는 공간 
bool bVISIT[100001];	// 체크여부 저장 공간

bool CheckAvailable(int num) {
	if (bVISIT[num]) return false;
	if (num < 0) return false;
	if (num > 100000) return false;
	return true;
}

int MIN(int a, int b) {
	if (a > b) return b;
	return a;
}

int main() {
	cin >> N >> K;

	Queue queue;
	fill_n(bVISIT, 100001, false);
	fill_n(DEPTH, 100001, -1);

	queue.Push(N);
	DEPTH[N] = 0;

	while(queue.getSize() > 0) {
		
		int number = queue.Pop();

		bVISIT[number] = true;
		
		int depth = DEPTH[number];

		if (number == K) {
			cout << depth << endl;
			break;
		}

		int plus = number + 1;
		if (CheckAvailable(plus)) {
			queue.Push(plus);
			DEPTH[plus] = DEPTH[plus] == -1 ? depth + 1 : MIN(DEPTH[plus], depth + 1);
		}

		int minus = number - 1;
		if (CheckAvailable(minus)) {
			queue.Push(minus);
			DEPTH[minus] = DEPTH[minus] == -1 ? depth + 1 : MIN(DEPTH[minus], depth + 1);
		}
		
		int twice = number * 2;
		if (CheckAvailable(twice)) {
			queue.Push(twice);
			DEPTH[twice] = DEPTH[twice] == -1 ? depth + 1 : MIN(DEPTH[twice], depth + 1);
		}
	}

	return 0;
}