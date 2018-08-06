#include <iostream>
using namespace std;

struct Node {
	long long num;
	struct Node* pNext;
};

class Queue {
public:
	Queue();
	~Queue();
	void Push(long long num);
	long long Pop();
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

void Queue::Push(long long num) {
	struct Node* pTemp = new Node();
	pTemp->num = num;
	pTemp->pNext = NULL;

	if (pLast) pLast->pNext = pTemp;
	pLast = pTemp;
	
	if (!pFirst) pFirst = pLast;

	mSize += 1;
}

long long Queue::Pop() {
	if (!pFirst) return INT64_MIN;
	
	long long ret = pFirst->num;
	if (pFirst == pLast) pLast = NULL;
	
	struct Node* pTemp = pFirst;
	pFirst = pFirst->pNext;
	delete pTemp;

	mSize -= 1;

	return ret;
}

int Queue::GetSize() {
	return mSize;
}

class HashTable {
public:
	HashTable();
	~HashTable();
	bool IsExist(long long num);
	void Insert(long long num);
private:
	struct Node* pHead[200000];
};

HashTable::HashTable() {
	for (int i = 0; i < 200000; i++) {
		pHead[i] = NULL;
	}
}

HashTable::~HashTable() {
	for (int i = 0; i < 200000; i++) {
		while (pHead[i]) {
			struct Node* pTemp = pHead[i];
			pHead[i] = pHead[i]->pNext;
			delete pTemp;
		}
	}
}

bool HashTable::IsExist(long long num) {
	int tok = num % 200000;
	bool ret = false;

	struct Node* pIterator = pHead[tok];
	while (pIterator) {
		if (pIterator->num == num) return true;
		pIterator = pIterator->pNext;
	}

	return ret;
}

void HashTable::Insert(long long num) {
	int tok = num % 200000;

	struct Node* pNode = new Node();
	pNode->num = num;
	pNode->pNext = NULL;

	if (pHead[tok]) pNode->pNext = pHead[tok];
	pHead[tok] = pNode;
}

int main() {
	long long input = 0;
	long long target = 0;

	for (int i = 0; i < 9; i++) {
		long long K; 
		cin >> K;
		input += K << (4 * i);
	}

	for (long long i = 0; i < 8; i++) {
		target += (i + 1) << (4 * i);
	}

	int sArray[4] = {12, -12, 4, -4};
	int rArray[4] = {-1, 1, 0, 0};
	int cArray[4] = {0, 0, -1, 1};

	Queue queue;
	HashTable hashTable;

	queue.Push(input);
	hashTable.Insert(input);

	int result = 0;

	while (queue.GetSize()) {
		int size = queue.GetSize();

		for (int i = 0; i < size; i++) {
			long long current = queue.Pop();

			if (current == target) {
				cout << result << endl;
				return 0;
			}

			int pos0 = 0;
			for (; current & 15LL << (pos0 * 4); pos0++);

			int r = pos0 / 3;
			int c = pos0 % 3;

			for (int i = 0; i < 4; i++) {
				int op_r = r + rArray[i];
				int op_c = c + cArray[i];

				if (op_r < 0 || op_r > 2 || op_c < 0 || op_c > 2) continue;

				int tPos = op_r * 3 + op_c;

				long long offset = 15LL << (tPos * 4);

				long long chunk = current & offset;

				long long mid = current - chunk;

				if (sArray[i] > 0) chunk <<= sArray[i];
				else chunk >>= -sArray[i];
				mid += chunk;

				if (!hashTable.IsExist(mid)) {
					queue.Push(mid);
					hashTable.Insert(mid);
				}
			}
		}
		result += 1;
	}
	
	cout << -1 << endl;
	return 0;
}