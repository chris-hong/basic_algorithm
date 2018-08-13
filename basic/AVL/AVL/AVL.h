#pragma once

#include <iostream>
using namespace std;

struct Node {
	int v;
	struct Node* pLeft;
	struct Node* pRight;
};

class AVL {
public:
	AVL();
	~AVL();

	void Insert(int num);
	void Remove(int num);
	bool IsExist(int num);
	int GetSize();
	void Print();
private:
	int mSize;
	struct Node* pHead;

	int _Height(struct Node* pNode);
	int _Difference(struct Node* pNode);
	struct Node* _LL(struct Node* pNode);
	struct Node* _RR(struct Node* pNode);
	struct Node* _LR(struct Node* pNode);
	struct Node* _RL(struct Node* pNode);
	struct Node* _Balance(struct Node* pNode);

	struct Node* _Insert(struct Node* pNode, int num);
	struct Node* _Remove(struct Node* pParent, struct Node* pNode, int num);
	int _Max(struct Node* pNode);
	int _Min(struct Node* pNode);
	bool _IsExist(struct Node* pNode, int num);
	void _Print(struct Node* pNode, int depth);
};

AVL::AVL() {
	mSize = 0;
	pHead = NULL;
}

AVL:: ~AVL() {
	while (pHead) {
		Remove(pHead->v);
	}
}

void AVL::Insert(int num) {
	pHead = _Insert(pHead, num);
}

void AVL::Remove(int num) {
	pHead = _Remove(pHead, pHead, num);
}

bool AVL::IsExist(int num) {
	return _IsExist(pHead, num);
}

int AVL::GetSize() {
	return mSize;
}

void AVL::Print() {
	_Print(pHead, 1);
	cout << endl;
}

int AVL::_Height(struct Node* pNode) {
	if (!pNode) return 0;
	int left = _Height(pNode->pLeft);
	int right = _Height(pNode->pRight);
	int height = left > right ? left : right;
	height += 1;
	return height;
}

int AVL::_Difference(struct Node* pNode) {
	if (!pNode) return 0;
	int left = _Height(pNode->pLeft);
	int right = _Height(pNode->pRight);
	return left - right;
}

struct Node* AVL::_LL(struct Node* pNode) {
	if (!pNode) return NULL;
	struct Node* pTemp = pNode->pLeft;
	pNode->pLeft = pTemp->pRight;
	pTemp->pRight = pNode;
	return pTemp;
}

struct Node* AVL::_RR(struct Node* pNode) {
	if (!pNode) return NULL;
	struct Node* pTemp = pNode->pRight;
	pNode->pRight = pTemp->pLeft;
	pTemp->pLeft = pNode;
	return pTemp;
}

struct Node* AVL::_LR(struct Node* pNode) {
	if (!pNode) return NULL;
	struct Node* pTemp = pNode->pLeft;
	pNode->pLeft = _RR(pTemp);
	return _LL(pNode);
}

struct Node* AVL::_RL(struct Node* pNode) {
	if (!pNode) return NULL;
	struct Node* pTemp = pNode->pRight;
	pNode->pRight = _LL(pTemp);
	return _RR(pNode);
}

struct Node* AVL::_Balance(struct Node* pNode) {
	int diff = _Difference(pNode);
	if (diff > 1) {
		if (_Difference(pNode->pLeft) > 0) pNode = _LL(pNode);
		else pNode = _LR(pNode);
	}
	else if (diff < -1) {
		if (_Difference(pNode->pRight) < 0) pNode = _RR(pNode);
		else pNode = _RL(pNode);
	}
	return pNode;
}

struct Node* AVL::_Insert(struct Node* pNode, int num) {
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
		return _Balance(pNode);
	}
}

struct Node* AVL::_Remove(struct Node* pParent, struct Node* pNode, int num) {
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
			mSize -= 1;
			delete pNode;
			return NULL;
		}
	}

	return _Balance(pNode);
}

int AVL::_Max(struct Node* pNode) {
	if (pNode->pRight) return _Max(pNode->pRight);
	else return pNode->v;
}

int AVL::_Min(struct Node* pNode) {
	if (pNode->pLeft) return _Min(pNode->pLeft);
	else return pNode->v;
}

bool AVL::_IsExist(struct Node* pNode, int num) {
	if (!pNode) return false;

	if (num < pNode->v) return _IsExist(pNode->pLeft, num);
	else if (num > pNode->v) return _IsExist(pNode->pRight, num);
	else return true;
}

void AVL::_Print(struct Node* pNode, int depth) {
	if (!pNode) return;

	_Print(pNode->pRight, depth + 1);
	cout << endl;
	
	if (pNode == pHead) cout << "HEAD -> ";
	else {
		for (int i = 0; i < depth; i++) {
			cout << "\t";
		}
	}
	cout << pNode->v << "(" <<  depth << ")";
	_Print(pNode->pLeft, depth + 1);
}