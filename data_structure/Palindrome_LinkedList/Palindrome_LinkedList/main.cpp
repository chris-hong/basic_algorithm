#include <iostream>
#include <string>
#include <vector>

struct Node {
	char ch;
	struct Node* pNext;
};

struct Node* MakeNodeList(std::string& input, int inputSize) {
	if (inputSize == 0) return nullptr;

	struct Node* pNode = new Node();
	struct Node* pCurrent = pNode;
	pCurrent->ch = input.at(0);

	for (int i = 1; i < inputSize; i++) {
		pCurrent->pNext = new Node();
		pCurrent = pCurrent->pNext;
		pCurrent->ch = input.at(i);
	}

	return pNode;
}

std::vector<char>* ConvertToHash(struct Node* pNode) {
	std::vector<char>* pHash = new std::vector<char>();
	struct Node* pCurrent = pNode;

	while (pCurrent != nullptr) {
		pHash->push_back(pCurrent->ch);
		pCurrent = pCurrent->pNext;
	}

	return pHash;
}

struct Node* ReverseNodeList(struct Node* pNode) {
	struct Node* pCurrent = pNode;
	struct Node* pNextNode = pCurrent->pNext;
	pCurrent->pNext = nullptr;
	while (pNextNode != nullptr) {
		struct Node* pNextNextNode = pNextNode->pNext;
		pNextNode->pNext = pCurrent;
		pCurrent = pNextNode;
		pNextNode = pNextNextNode;
	}
	
	return pCurrent;
}

bool IsPalindrome(std::vector<char>* pHash, struct Node* pNode) {
	struct Node* pCurrent = pNode;
	
	for (std::vector<char>::iterator vi = pHash->begin(); vi != pHash->end(); vi++) {
		if (*vi != pCurrent->ch) return false;
		pCurrent = pCurrent->pNext;
	}

	return true;
}

void RemoveNodeList(struct Node* pNode) {
	struct Node* pCurrent = pNode;

	while (pCurrent != nullptr) {
		struct Node* pNextNode = pCurrent->pNext;
		delete(pCurrent);
		pCurrent = pNextNode;
	}
}

void PrintNodeList(struct Node* pNode) {
	struct Node* pCurrent = pNode;
	while (pCurrent != nullptr) {
		std::cout << pCurrent->ch << std::endl;
		pCurrent = pCurrent->pNext;
	}
}

int main() {
	
	std::string inputString;
	std::getline(std::cin, inputString);
	int inputSize = inputString.size();

	struct Node* pNode = MakeNodeList(inputString, inputSize);
	PrintNodeList(pNode);

	std::vector<char>* pHash = ConvertToHash(pNode);

	pNode = ReverseNodeList(pNode);
	PrintNodeList(pNode);

	if (IsPalindrome(pHash, pNode)) std::cout << "Input String is Palindrome!!" << std::endl;
	else std::cout << "Input string is not Palindrome!!" << std::endl;

	RemoveNodeList(pNode);

	getchar();
	return 0;
}