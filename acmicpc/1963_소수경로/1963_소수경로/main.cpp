#include <iostream>
using namespace std;

int MEMO[10000];

bool IsPrimeNumber(int num) {
	int last = num / 2;

	for (int div = 2; div <= last; div++) {
		if (num % div == 0) return false;
	}

	return true;
}

struct Node {
	int num;
	struct Node* pNext;
};

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

void FindPrime(int start, int end) {
	Queue queue;
	queue.Enqueue(start);
	MEMO[start] = 0;

	while (queue.GetSize()) {
		int target = queue.Dequeue();

		if (target == end) {
			cout << MEMO[target] << endl;
			break;
		}

		// 1000
		for (int i = 1; i < 10; i++) {
			int T1000 = (target % 1000) + (1000 * i);
			if (MEMO[T1000] < 0 && IsPrimeNumber(T1000)) {
				MEMO[T1000] = MEMO[target] + 1;
				queue.Enqueue(T1000);
			}
		}

		// 100
		for (int i = 0; i < 10; i++) {
			int T100 = (target / 1000) * 1000 + (target % 100) + (100 * i);
			if (MEMO[T100] < 0 && IsPrimeNumber(T100)) {
				MEMO[T100] = MEMO[target] + 1;
				queue.Enqueue(T100);
			}
		}

		// 10
		for (int i = 0; i < 10; i++) {
			int T10 = (target / 100) * 100 + (target % 10) + (10 * i);
			if (MEMO[T10] < 0 && IsPrimeNumber(T10)) {
				MEMO[T10] = MEMO[target] + 1;
				queue.Enqueue(T10);
			}
		}

		// 1
		for (int i = 0; i < 10; i++) {
			int T1 = (target / 10) * 10 + i;
			if (MEMO[T1] < 0 && IsPrimeNumber(T1)) {
				MEMO[T1] = MEMO[target] + 1;
				queue.Enqueue(T1);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		fill_n(MEMO, 10000, -1);
		
		int start, end;
		cin >> start >> end;

		FindPrime(start, end);
	}

	return 0;
}