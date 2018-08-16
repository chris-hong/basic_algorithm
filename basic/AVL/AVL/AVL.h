#pragma once

#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T v;
	struct Node* pLeft;
	struct Node* pRight;
};

template <typename T>
class AVL {
public:
	AVL();
	~AVL();
	void Insert(T _v);
	void Remove(T _v);
	bool IsExist(T _v);
	void Print();
	int GetSize();

private:
	int mSize;
	struct Node<T>* pHead;

	struct Node<T>* _Insert(struct Node<T>* pNode, T _v);
	struct Node<T>* _Remove(struct Node<T>* pParent, struct Node<T>* pNode, T _v);
	bool _IsExist(struct Node<T>* pNode, T _v);
	void _Print(struct Node<T>* pNode, int depth);

	int _Height(struct Node<T>* pNode);
	int _Difference(struct Node<T>* pNode);
	struct Node<T>* _LL(struct Node<T>* pNode);
	struct Node<T>* _RR(struct Node<T>* pNode);
	struct Node<T>* _LR(struct Node<T>* pNode);
	struct Node<T>* _RL(struct Node<T>* pNode);
	T _Max(struct Node<T>* pNode);
	T _Min(struct Node<T>* pNode);
	struct Node<T>* _Balance(struct Node<T>* pNode);
};

template <typename T>
AVL<T>::AVL() {
	mSize = 0;
	pHead = NULL;
}

template <typename T>
AVL<T>::~AVL() {
	while (pHead) Remove(pHead->v);
}

template <typename T>
void AVL<T>::Insert(T _v) {
	pHead = _Insert(pHead, _v);
}

template <typename T>
void AVL<T>::Remove(T _v) {
	pHead = _Remove(pHead, pHead, _v);
}

template <typename T>
bool AVL<T>::IsExist(T _v) {
	return _IsExist(pHead, _v);
}

template <typename T>
void AVL<T>::Print() {
	_Print(pHead, 1);
	cout << endl << endl;
}

template <typename T>
int AVL<T>::GetSize() {
	return mSize;
}

template <typename T>
struct Node<T>* AVL<T>::_Insert(struct Node<T>* pNode, T _v) {
	if (!pNode) {
		struct Node<T>* pNew = new Node<T>();
		pNew->v = _v;
		pNew->pLeft = NULL;
		pNew->pRight = NULL;
		mSize += 1;
		return pNew;
	}
	else {
		if (_v < pNode->v) pNode->pLeft = _Insert(pNode->pLeft, _v);
		else if (_v > pNode->v) pNode->pRight = _Insert(pNode->pRight, _v);
		return _Balance(pNode);
	}
}

template <typename T>
struct Node<T>* AVL<T>::_Remove(struct Node<T>* pParent, struct Node<T>* pNode, T _v) {
	if (!pNode) return NULL;

	if (_v < pNode->v) pNode->pLeft = _Remove(pNode, pNode->pLeft, _v);
	else if (_v > pNode->v) pNode->pRight = _Remove(pNode, pNode->pRight, _v);
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
	return _Balance(pNode);
}

template <typename T>
bool AVL<T>::_IsExist(struct Node<T>* pNode, T _v) {
	if (!pNode) return false;
	if (_v < pNode->v) return _IsExist(pNode->pLeft, _v);
	else if (_v > pNode->v) return _IsExist(pNode->pRight, _v);
	else return true;
}

template <typename T>
void AVL<T>::_Print(struct Node<T>* pNode, int depth) {
	if (!pNode) return;

	_Print(pNode->pRight, depth + 1);
	cout << endl;

	if (pNode == pHead) cout << "HEAD(" << mSize << ")-> ";
	else {
		for (int i = 0; i < depth; i++) cout << "\t";
	}
	cout << pNode->v;
	_Print(pNode->pLeft, depth + 1);
}

template <typename T>
int AVL<T>::_Height(struct Node<T>* pNode) {
	if (!pNode) return 0;
	int left = _Height(pNode->pLeft);
	int right = _Height(pNode->pRight);
	int height = left > right ? left : right;
	return height + 1;
}

template <typename T>
int AVL<T>::_Difference(struct Node<T>* pNode) {
	if (!pNode) return 0;
	int left = _Height(pNode->pLeft);
	int right = _Height(pNode->pRight);
	return left - right;
}

template <typename T>
struct Node<T>* AVL<T>::_LL(struct Node<T>* pNode) {
	struct Node<T>* pTemp = pNode->pLeft;
	pNode->pLeft = pTemp->pRight;
	pTemp->pRight = pNode;
	return pTemp;
}

template <typename T>
struct Node<T>* AVL<T>::_RR(struct Node<T>* pNode) {
	struct Node<T>* pTemp = pNode->pRight;
	pNode->pRight = pTemp->pLeft;
	pTemp->pLeft = pNode;
	return pTemp;
}

template <typename T>
struct Node<T>* AVL<T>::_LR(struct Node<T>* pNode) {
	struct Node<T>* pTemp = pNode->pLeft;
	pNode->pLeft = _RR(pTemp);
	return _LL(pNode);
}

template <typename T>
struct Node<T>* AVL<T>::_RL(struct Node<T>* pNode) {
	struct Node<T>* pTemp = pNode->pRight;
	pNode->pRight = _LL(pTemp);
	return _RR(pNode);
}

template <typename T>
T AVL<T>::_Max(struct Node<T>* pNode) {
	if (pNode->pRight) return _Max(pNode->pRight);
	else return pNode->v;
}

template <typename T>
T AVL<T>::_Min(struct Node<T>* pNode) {
	if (pNode->pLeft) return _Min(pNode->pLeft);
	else return pNode->v;
}

template <typename T>
struct Node<T>* AVL<T>::_Balance(struct Node<T>* pNode) {
	int diff = _Difference(pNode);
	if (diff > 1) {
		if (_Difference(pNode->pLeft) > 0) return _LL(pNode);
		else return _LR(pNode);
	}
	else if (diff < -1) {
		if (_Difference(pNode->pRight) < 0) return _RR(pNode);
		else return _RL(pNode);
	}
	return pNode;
}