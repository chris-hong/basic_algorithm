#include <iostream>
#include <vector>
#include <random>

struct Node {
	int data;
	struct Node* pNext;
};

struct Node* MakeSimpleLinkedList(int _N) {
	struct Node* pNode1 = new Node();
	pNode1->data = 0;
	struct Node* pCurrent1 = pNode1;

	for (int i = 1; i < _N; i++) {
		pCurrent1->pNext = new Node();
		pCurrent1 = pCurrent1->pNext;
		pCurrent1->data = i;
	}

	return pNode1;
}

struct Node* MakeConnectedLinkedList(struct Node* pNode1, int _Base, int _N) {
	std::random_device rn;
	std::mt19937_64 rnd(rn());
	std::uniform_int_distribution<int> range(1, _N);

	int randNum = range(rnd);

	std::cout << "Random Number: " << randNum << std::endl;

	struct Node* pNode2 = new Node();
	pNode2->data = _Base;
	struct Node* pCurrent2 = pNode2;
	struct Node* pCurrent1 = pNode1;

	for (int i = 1; i < randNum; i++) {
		pCurrent2->pNext = new Node();
		pCurrent2 = pCurrent2->pNext;
		pCurrent1 = pCurrent1->pNext;
		pCurrent2->data = _Base - i;
	}

	pCurrent2->pNext = pCurrent1->pNext;

	return pNode2;
}

void PrintLinkedList(struct Node* pNode) {
	struct Node* pCurrent = pNode;

	while (pCurrent != nullptr) {
		std::cout << pCurrent->data << std::endl;
		pCurrent = pCurrent->pNext;
	}
}

struct Node* SearchIntersectionNode(struct Node* pNode1, struct Node* pNode2, int _N) {
	std::vector<struct Node*> hashPNode(_N);

	struct Node* pCurrent1 = pNode1;
	for (int i = 0; i < _N; i++) {
		hashPNode[i] = pCurrent1;
		pCurrent1 = pCurrent1->pNext;
	}

	struct Node* PCurrent2 = pNode2;
	for (int i = 0; i < _N; i++) {
		if (hashPNode[i] == PCurrent2) return PCurrent2;
		PCurrent2 = PCurrent2->pNext;
	}
	
	return nullptr;
}

int main() {
	int Base = 100;
	int N = 10;

	struct Node* pNode1 = MakeSimpleLinkedList(N);
	PrintLinkedList(pNode1);

	struct Node* pNode2 = MakeConnectedLinkedList(pNode1, Base, N);
	PrintLinkedList(pNode2);

	struct Node* pIntersectionNode = SearchIntersectionNode(pNode1, pNode2, N);
	if (pIntersectionNode) std::cout << "Find IntersectionNode <Address>: " << pIntersectionNode << "<data>: " << pIntersectionNode->data << std::endl;

	getchar();
	return 0;
}