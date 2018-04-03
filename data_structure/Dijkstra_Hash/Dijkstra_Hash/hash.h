#pragma once

#include <string>
#include <fstream>
#include <sstream>

#include "graph.h"

using namespace std;

#define HASH_TABLE_SIZE 17	// 소수 17
int hashSize = 0;

struct Node {
	string name;
	int number;
	struct Node* pNext;
};

struct HashTable {
	int key;
	struct Node* pNext;
};

struct HashTable Hash[HASH_TABLE_SIZE];

int MakeHashKey(string chunk) {
	int sum = 0;
	for (int i = 0; i < chunk.size(); i++) {
		sum += chunk[0];
	}

	return sum % HASH_TABLE_SIZE;
}

int ConvertStringToNumber(string chunk) {
	int key = MakeHashKey(chunk);
	
	if (!Hash[key].pNext) {
		return -1;
	}
	else {
		struct Node* pNode = Hash[key].pNext;
		while (pNode != nullptr) {
			if (pNode->name.compare(chunk) == 0) {
				return pNode->number;
			}
			pNode = pNode->pNext;
		}
	}
	
	return -1;
}

string ConvertNumberToString(int num) {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		struct Node* pNode = Hash[i].pNext;
		while (pNode != nullptr) {
			if (pNode->number == num) {
				return pNode->name;
			}
			pNode = pNode->pNext;
		}
	}

	return nullptr;
}

int InsertNode(string thunk) {
	int key = MakeHashKey(thunk);
	struct Node* pNext = Hash[key].pNext;	// 해당 Hash에서 같은 Node가 등록되어 있는지 확인 후 있으면 노드번호를 리턴
	while (pNext != nullptr) {
		if (pNext->name.compare(thunk) == 0) {
			return pNext->number;
		}
		pNext = pNext->pNext;
	}

	struct Node* pNode = new Node();		// 같은 Node가 없으면 신규로 생성하여 Hash의 next로 연결
	pNode->name = thunk;
	pNode->number = hashSize;
	hashSize++;
	pNode->pNext = Hash[key].pNext;
	Hash[key].pNext = pNode;
	return pNode->number;
}

void CreateHashTable(struct Graph* pGraph, string fileName) {
	ifstream readFile(fileName);
	if (readFile.is_open()) {
		string line;
		while (getline(readFile, line)) {
			istringstream iss(line);
			string thunk;
			vector<string> buffer;
			while (getline(iss, thunk, ' ')) {
				buffer.push_back(thunk);
			}
			int from = InsertNode(buffer[0]);
			int to = InsertNode(buffer[1]);
			int weight = atoi(buffer[2].data());
			pGraph->Adj[from][to] = weight;
			pGraph->V = hashSize;
			pGraph->E += 1;
		}
		readFile.close();
	}
}

void DeleteHashTable() {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		struct Node* pNode = Hash[i].pNext;
		while (pNode != nullptr) {
			Node* pNext = pNode->pNext;
			delete(pNode);
			pNode = pNext;
		}
	}
}