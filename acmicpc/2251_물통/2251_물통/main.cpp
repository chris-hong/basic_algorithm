#include <iostream>
using namespace std;

class Set {
public:
	Set();
	~Set();
	void Insert(int num);
	void Sort();
	void Print();
private:
	int mCapacity;
	int mSize;
	int* pBuffer;
	void Resize();
	bool IsExist(int num);
	void MergeSort(int start, int end);
	void Merge(int start, int mid, int end);
};

Set::Set() {
	mCapacity = 10;
	mSize = 0;
	pBuffer = new int[mCapacity];
}

Set::~Set() {
	delete pBuffer;
	pBuffer = NULL;
}

void Set::Insert(int num) {
	if (IsExist(num)) return;
	if (mCapacity == mSize) Resize();

	pBuffer[mSize++] = num;
}

void Set::Sort() {
	MergeSort(0, mSize - 1);
}

void Set::Print() {
	Sort();

	for (int i = 0; i < mSize; i++) cout << pBuffer[i] << " ";
	cout << endl;
}

void Set::MergeSort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		MergeSort(start, mid);
		MergeSort(mid + 1, end);
		Merge(start, mid, end);
	}
}

void Set::Merge(int start, int mid, int end) {
	int* temp = new int[mSize];
	
	int s = start;
	int m = mid + 1;
	int idx = start;

	while (s <= mid && m <= end) {
		if (pBuffer[s] < pBuffer[m]) temp[idx++] = pBuffer[s++];
		else temp[idx++] = pBuffer[m++];
	}

	while (s <= mid) temp[idx++] = pBuffer[s++];
	while (m <= end) temp[idx++] = pBuffer[m++];

	for (int i = start; i <= end; i++) pBuffer[i] = temp[i];
	delete temp;
}

void Set::Resize() {
	int nextCapacity = mCapacity * 2;
	int* pTempBuffer = new int[nextCapacity];

	for (int i = 0; i < mCapacity; i++) pTempBuffer[i] = pBuffer[i];
	delete pBuffer;
	pBuffer = pTempBuffer;
	mCapacity = nextCapacity;
}

bool Set::IsExist(int num) {
	for (int i = 0; i < mSize; i++) {
		if (pBuffer[i] == num) return true;
	}
	return false;
}

struct Node {
	int num;
	struct Node* pNext;
};

class HashTable {
public:
	HashTable(int hashCount);
	~HashTable();
	void Insert(int num);
	bool IsExist(int num);
private:
	int mHashCount;
	struct Node** ppHead;
};

HashTable::HashTable(int hashCount) {
	mHashCount = hashCount;
	ppHead = new struct Node*[mHashCount];
	for (int i = 0; i < mHashCount; i++) ppHead[i] = NULL;
}

HashTable::~HashTable() {
	for (int i = 0; i < mHashCount; i++) {
		while (ppHead[i]) {
			struct Node* pTemp = ppHead[i];
			ppHead[i] = ppHead[i]->pNext;
			delete pTemp;
		}
	}

	delete ppHead;
}

void HashTable::Insert(int num) {
	int hash = num % mHashCount;

	struct Node* pNode = new Node();
	pNode->num = num;
	pNode->pNext = ppHead[hash];

	ppHead[hash] = pNode;
}

bool HashTable::IsExist(int num) {
	int hash = num % mHashCount;
	struct Node* pIndicator = ppHead[hash];
	while (pIndicator) {
		if (pIndicator->num == num) return true;
		pIndicator = pIndicator->pNext;
	}
	return false;
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

	if (pLast) pLast->pNext = pNode;
	pLast = pNode;

	if (!pFirst) pFirst = pNode;

	mSize += 1;
}

int Queue::Pop() {
	if (!pFirst) return INT32_MIN;
	int ret = pFirst->num;
	struct Node* pNode = pFirst;
	if (pFirst == pLast) pLast = NULL;
	pFirst = pFirst->pNext;
	delete pNode;

	mSize -= 1;
	return ret;
}

int Queue::GetSize() {
	return mSize;
}

int CAPACITY[3] = { 0, 0, 0 };
int WATER[3] = { 0, 0, 0 };

int main() {
	for (int i = 0; i < 3; i++) cin >> CAPACITY[i];
	
	WATER[2] = CAPACITY[2];
	
	int initial = 0;
	for (int i = 0; i < 3; i++) {
		initial = (initial << 8) + WATER[i];
	}

	Queue queue;
	HashTable hashTable(10);
	Set set;
	queue.Push(initial);
	hashTable.Insert(initial);
	
	if (WATER[0] == 0) {
		set.Insert(WATER[2]);
	}

	while (queue.GetSize()) {
		int current = queue.Pop();
		
		for (int from = 0; from < 3; from++) {
			for (int to = 0; to < 3; to++) {
				if (from == to) continue;

				for (int i = 0; i < 3; i++) {
					WATER[2 - i] = (current >> (i * 8)) & 255;
				}

				if (WATER[from] == 0) continue;

				if (WATER[from] + WATER[to] > CAPACITY[to]) {
					WATER[from] = WATER[from] + WATER[to] - CAPACITY[to];
					WATER[to] = CAPACITY[to];
				}
				else {
					WATER[to] = WATER[from] + WATER[to];
					WATER[from] = 0;
				}

				int next = 0;
				for (int i = 0; i < 3; i++) {
					next = (next << 8) + WATER[i];
				}

				if (!hashTable.IsExist(next)) {
					queue.Push(next);
					hashTable.Insert(next);
					if (WATER[0] == 0) {
						set.Insert(WATER[2]);
					}
				}
			}
		}
	}

	set.Print();
	return 0;
}