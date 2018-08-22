#include <iostream>
using namespace std;

int CAPACITY[3] = { 0,0,0 };
int WATER[3] = { 0,0,0 };

template <typename T>
struct tNode {
	T v;
	struct tNode<T>* pLeft;
	struct tNode<T>* pRight;
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
	void InOrder();

private:
	int mSize;
	struct tNode<T>* pHead;

	struct tNode<T>* _Insert(struct tNode<T>* pNode, T _v);
	struct tNode<T>* _Remove(struct tNode<T>* pParent, struct tNode<T>* pNode, T _v);
	bool _IsExist(struct tNode<T>* pNode, T _v);
	void _Print(struct tNode<T>* pNode, int depth);

	T _Max(struct tNode<T>* pNode);
	T _Min(struct tNode<T>* pNode);

	struct tNode<T>* _LL(struct tNode<T>* pNode);
	struct tNode<T>* _RR(struct tNode<T>* pNode);
	struct tNode<T>* _LR(struct tNode<T>* pNode);
	struct tNode<T>* _RL(struct tNode<T>* pNode);
	int _Height(struct tNode<T>* pNode);
	int _Difference(struct tNode<T>* pNode);
	struct tNode<T>* _Balance(struct tNode<T>* pNode);
	void _InOrder(struct tNode<T>* pNode);
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
	cout << endl;
}

template <typename T>
void AVL<T>::InOrder() {
	_InOrder(pHead);
}

template <typename T>
struct tNode<T>* AVL<T>::_Insert(struct tNode<T>* pNode, T _v) {
	if (!pNode) {
		struct tNode<T>* pNew = new tNode<T>();
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
struct tNode<T>* AVL<T>::_Remove(struct tNode<T>* pParent, struct tNode<T>* pNode, T _v) {
	if (!pNode) return NULL;

	if (_v < pNode->v) pNode->pLeft = _Remove(pNode, pNode->pLeft, _v);
	else if (_v > pNode->v) pNode->pRight = _Remove(pNode, pNode->pRight, _v);
	else {
		if (pNode->pLeft || pNode->pRight) {
			if (pNode->pLeft) {
				pNode->v = _Max(pNode->pLeft);
				pNode->pLeft = _Remove(pNode, pNode->pLeft, pNode->v);
			}
			else if (pNode->pRight) {
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
bool AVL<T>::_IsExist(struct tNode<T>* pNode, T _v) {
	if (!pNode) return false;
	else {
		if (_v < pNode->v) return _IsExist(pNode->pLeft, _v);
		else if (_v > pNode->v) return _IsExist(pNode->pRight, _v);
		else return true;
	}
}

template <typename T>
void AVL<T>::_Print(struct tNode<T>* pNode, int depth) {
	if (!pNode) return;

	_Print(pNode->pRight, depth + 1);
	cout << endl;

	if (pNode == pHead) cout << "HEAD -> ";
	else for (int i = 0; i < depth; i++) cout << "\t";

	cout << pNode->v;
	_Print(pNode->pLeft, depth + 1);
}

template <typename T>
T AVL<T>::_Max(struct tNode<T>* pNode) {
	if (pNode->pRight) return _Max(pNode->pRight);
	else return pNode->v;
}

template <typename T>
T AVL<T>::_Min(struct tNode<T>* pNode) {
	if (pNode->pLeft) return _Min(pNode->pLeft);
	else return pNode->v;
}

template <typename T>
struct tNode<T>* AVL<T>::_LL(struct tNode<T>* pNode) {
	struct tNode<T>* pTemp = pNode->pLeft;
	pNode->pLeft = pTemp->pRight;
	pTemp->pRight = pNode;
	return pTemp;
}

template <typename T>
struct tNode<T>* AVL<T>::_RR(struct tNode<T>* pNode) {
	struct tNode<T>* pTemp = pNode->pRight;
	pNode->pRight = pTemp->pLeft;
	pTemp->pLeft = pNode;
	return pTemp;
}

template <typename T>
struct tNode<T>* AVL<T>::_LR(struct tNode<T>* pNode) {
	struct tNode<T>* pTemp = pNode->pLeft;
	pNode->pLeft = _RR(pTemp);
	return _LL(pNode);
}

template <typename T>
struct tNode<T>* AVL<T>::_RL(struct tNode<T>* pNode) {
	struct tNode<T>* pTemp = pNode->pRight;
	pNode->pRight = _LL(pTemp);
	return _RR(pNode);
}

template <typename T>
int AVL<T>::_Height(struct tNode<T>* pNode) {
	if (!pNode) return 0;

	int left = _Height(pNode->pLeft) + 1;
	int right = _Height(pNode->pRight) + 1;
	return left > right ? left : right;
}

template <typename T>
int AVL<T>::_Difference(struct tNode<T>* pNode) {
	if (!pNode) return 0;

	int left = _Height(pNode->pLeft);
	int right = _Height(pNode->pRight);
	return left - right;
}

template <typename T>
struct tNode<T>* AVL<T>::_Balance(struct tNode<T>* pNode) {
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

template <typename T>
void AVL<T>::_InOrder(struct tNode<T>* pNode) {
	if (!pNode) return;

	_InOrder(pNode->pLeft);
	cout << pNode->v << " ";
	_InOrder(pNode->pRight);
}

template <typename Q>
struct qNode {
	Q v;
	struct qNode<Q>* pNext;
};

template <typename Q>
class Queue {
public:
	Queue();
	~Queue();
	void Push(Q _v);
	Q Pop();
	int GetSize();
private:
	int mSize;
	struct qNode<Q>* pFirst;
	struct qNode<Q>* pLast;
};

template <typename Q>
Queue<Q>::Queue() {
	mSize = 0;
	pFirst = NULL;
	pLast = NULL;
}

template <typename Q>
Queue<Q>::~Queue() {
	while (GetSize()) Pop();
}

template <typename Q>
void Queue<Q>::Push(Q _v) {
	struct qNode<Q>* pTemp = new qNode<Q>();
	pTemp->v = _v;
	pTemp->pNext = NULL;

	if (pLast) pLast->pNext = pTemp;
	pLast = pTemp;

	if (!pFirst) pFirst = pTemp;

	mSize += 1;
}

template <typename Q>
Q Queue<Q>::Pop() {
	if (!pFirst) return NULL;

	Q ret = pFirst->v;
	struct qNode<Q>* pTemp = pFirst;

	if (pFirst == pLast) pLast = NULL;

	pFirst = pFirst->pNext;
	delete pTemp;
	mSize -= 1;

	return ret;
}

template <typename Q>
int Queue<Q>::GetSize() {
	return mSize;
}

int main() {

	AVL<int> result;
	AVL<int> status;
	Queue<int> queue;

	for (int i = 0; i < 3; i++) cin >> CAPACITY[i];

	WATER[2] = CAPACITY[2];

	int bit = 0;
	for (int i = 0; i < 3; i++) {
		bit = (bit << 8) + WATER[i];
	}

	queue.Push(bit);
	status.Insert(bit);

	while (queue.GetSize()) {
		int current = queue.Pop();

		for (int i = 0; i < 3; i++) {
			WATER[2 - i] = (current >> (i * 8)) & 255;
		}

		if (WATER[0] == 0) {
			result.Insert(WATER[2]);
		}

		for (int from = 0; from < 3; from++) {
			for (int to = 0; to < 3; to++) {
				if (from == to) continue;

				for (int i = 0; i < 3; i++) {
					WATER[2 - i] = (current >> (i * 8)) & 255;
				}

				if (WATER[from] == 0) continue;

				int totalWater = WATER[from] + WATER[to];

				if (CAPACITY[to] < totalWater) {
					WATER[to] = CAPACITY[to];
					WATER[from] = totalWater - CAPACITY[to];
				}
				else {
					WATER[to] = totalWater;
					WATER[from] = 0;
				}

				int v = 0;
				for (int i = 0; i < 3; i++) {
					v = (v << 8) + WATER[i];
				}

				if (!status.IsExist(v)) {
					queue.Push(v);
					status.Insert(v);
				}
			}
		}
	}

	result.InOrder();

	return 0;
}