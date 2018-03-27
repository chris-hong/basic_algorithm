#include <iostream>

struct Node {
	int data;
	struct Node* next;
};

void MakeList(struct Node* pNode, int _N) {
	struct Node* pCurrent = pNode;
	pCurrent->data = 0;

	for (int i = 1; i < _N; i++) {
		struct Node* newNode = new Node();
		newNode->data = i;
		newNode->next = nullptr;
		pCurrent->next = newNode;
		pCurrent = pCurrent->next;
	}
}

Node* ReverseList(struct Node* pNode) {
	struct Node* pCurrent = pNode;
	struct Node* pNext = pCurrent->next;
	pCurrent->next = nullptr;
	while (pNext != nullptr) {
		struct Node* pNextNext = pNext->next;
		pNext->next = pCurrent;
		pCurrent = pNext;
		pNext = pNextNext;
	}
	return pCurrent;
}

void PrintList(struct Node* pNode) {
	struct Node* pCurrent = pNode;

	while (pCurrent != nullptr) {
		std::cout << pCurrent->data << std::endl;
		pCurrent = pCurrent->next;
	}
}

int main() {
	struct Node* pNode = new Node();
	pNode->data = 0; 
	pNode->next = nullptr;

	MakeList(pNode, 10);
	PrintList(pNode);
	
	pNode = ReverseList(pNode);
	PrintList(pNode);

	while (pNode != nullptr) {
		struct Node* pNext = pNode->next;
		free(pNode);
		pNode = pNext;
	}

	getchar();
	return 0;
}
