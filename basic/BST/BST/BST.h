#pragma once
#include <iostream>
using namespace std;

struct Node {
	int v;
	struct Node* pLeft;
	struct Node* pRight;
};

class BST {
public:
	BST();
	~BST();
	void Insert(int num);
	void Remove(int num);
	bool IsExist(int num);
	void Print();
private:
	int mSize;
	struct Node* pHead;
	struct Node* _Insert(struct Node* pNode, int num);
	struct Node* _Remove(struct Node* pParent, struct Node* pNode, int num);
	bool _IsExist(struct Node* pNode, int num);
	int _Max(struct Node* pNode);
	int _Min(struct Node* pNode);
	void _Print(struct Node* pNode, int depth);
};

BST::BST() {
	mSize = 0;
	pHead = NULL;
}

BST::~BST() {
	while (pHead) {
		Remove(pHead->v);
	}
}

void BST::Insert(int num) {
	pHead = _Insert(pHead, num);
}

void BST::Remove(int num) {
	pHead = _Remove(pHead, pHead, num);
}

bool BST::IsExist(int num) {
	return _IsExist(pHead, num);
}

void BST::Print() {
	_Print(pHead, 1);
	cout << endl;
}

struct Node* BST::_Insert(struct Node* pNode, int num) {
	// 중복은 허용하지 않음
	if (!pNode) {
		struct Node* pNew = new Node();
		pNew->v = num;
		pNew->pLeft = NULL;
		pNew->pRight = NULL;
		mSize += 1;
		return pNew;
	}
	else {
		if (num < pNode->v) pNode->pLeft = _Insert(pNode->pLeft, num);
		else if (num > pNode->v) pNode->pRight = _Insert(pNode->pRight, num);
		return pNode;
	}
}

struct Node* BST::_Remove(struct Node* pParent, struct Node* pNode, int num) {
	if (!pNode) return NULL;

	if (num < pNode->v) pNode->pLeft = _Remove(pNode, pNode->pLeft, num);
	else if (num > pNode->v) pNode->pRight = _Remove(pNode, pNode->pRight, num);
	else {
		if (pNode->pLeft || pNode->pRight) {
			if (pNode->pLeft) {
				pNode->v = _Max(pNode->pLeft);
				pNode->pLeft = _Remove(pNode, pNode->pLeft, pNode->v);
			}
			else {
				pNode->v = _Min(pNode->pRight);
				pNode->pRight = _Remove(pNode, pNode->pRight, pNode->v);
			}
		}
		else {
			if (pParent->pLeft == pNode) pParent->pLeft = NULL;
			else if (pParent->pRight == pNode) pParent->pRight = NULL;
			delete pNode;
			mSize -= 1;
			return NULL;
		}
	}
	return pNode;
}

bool BST::_IsExist(struct Node* pNode, int num) {
	if (!pNode) return false;

	if (num < pNode->v) return _IsExist(pNode->pLeft, num);
	else if (num > pNode->v) return _IsExist(pNode->pRight, num);
	else return true;
}

int BST::_Max(struct Node* pNode) {
	if (pNode->pRight) return _Max(pNode->pRight);
	else return pNode->v;
}

int BST::_Min(struct Node* pNode) {
	if (pNode->pLeft) return _Min(pNode->pLeft);
	else return pNode->v;
}

void BST::_Print(struct Node* pNode, int depth) {
	if (!pNode) return;

	_Print(pNode->pRight, depth + 1);
	cout << endl;
	if (pNode == pHead) cout << "HEAD -> ";
	else {
		for (int i = 0; i < depth; i++) cout << "\t";
	}
	cout << pNode->v;
	_Print(pNode->pLeft, depth + 1);
}