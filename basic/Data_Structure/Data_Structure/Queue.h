#pragma once

struct QueueNode {
	int num;
	struct QueueNode* pNext;
};

struct Queue {
public:
	Queue();
	~Queue();
	void Enqueue(int num);
	int Dequeue();
	int getSize();
private:
	int mSize;
	struct QueueNode* pFirst;
	struct QueueNode* pLast;
};

Queue::Queue() {
	mSize = 0;
}

Queue::~Queue() {
	for (int i = 0; i < mSize; i++) {
		Dequeue();
	}
}

void Queue::Enqueue(int num) {
	struct QueueNode* pNode = new QueueNode();
	pNode->num = num;
	pNode->pNext = NULL;

	if (!mSize || (!pFirst && !pLast)) {
		pFirst = pNode;
		pLast = pNode;
	}
	else {
		pLast->pNext = pNode;
		pLast = pNode;
	}

	mSize += 1;
}

int Queue::Dequeue() {
	if (!mSize || (!pFirst && !pLast)) return INT32_MIN;

	int ret = pFirst->num;
	
	struct QueueNode* pTemp = pFirst;
	if (mSize == 1 && (pFirst == pLast)) pLast = pFirst->pNext;
	pFirst = pFirst->pNext;
	delete pTemp;

	mSize -= 1;
	return ret;
}

int Queue::getSize() {
	return mSize;
}
