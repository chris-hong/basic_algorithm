#pragma once
#include "Common.h"

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