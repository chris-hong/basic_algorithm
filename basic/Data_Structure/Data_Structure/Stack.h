#pragma once

struct StackNode {
	int num;
	struct StackNode* pPrev;
};

class Stack {
public:
	Stack();
	~Stack();
	void Push(int num);
	int Pop();
	int getSize();

private:
	int mSize;
	struct StackNode* pTop;
};

Stack::Stack() {
	mSize = 0;
}

Stack::~Stack() {
	for (int i = 0; i < mSize; i++) {
		Pop();
	}
}

void Stack::Push(int num) {
	struct StackNode* pNode = new StackNode();
	pNode->num = num;
	pNode->pPrev = NULL;

	if (!mSize || !pTop) pTop = pNode;
	else {
		pNode->pPrev = pTop;
		pTop = pNode;
	}

	mSize += 1;
}

int Stack::Pop() {
	if (!mSize || !pTop) return INT32_MIN;

	int ret = pTop->num;
	
	struct StackNode* pTemp = pTop;
	pTop = pTop->pPrev;
	delete pTemp;

	mSize -= 1;
	return ret;
}

int Stack::getSize() {
	return mSize;
}