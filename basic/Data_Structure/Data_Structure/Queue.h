#pragma once
#include "Common.h"

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
