#include <iostream>
#include <random>

using namespace std;

#define SET_SIZE 10

// DisjointSet Structure (�и����� �ڷᱸ��)
struct DisjointSet {
	struct DisjointSet* pParent;
	int data;
	int rank;
};

void Dis_Union(struct DisjointSet* pSet1, struct DisjointSet* pSet2);
struct DisjointSet* Dis_Find(struct DisjointSet* pSet);
struct DisjointSet* Dis_MakeSet(int data);
void PrintDisjointSet(struct DisjointSet* pSet);

int main() {
	
	// 1. DisjointSet (�и����� ����)
	struct DisjointSet* set[SET_SIZE];
	for (int i = 0; i < SET_SIZE; i++) {
		set[i] = Dis_MakeSet(i);
	}

	// 2. Random Union
	random_device rn;
	mt19937_64 rnd(rn());
	uniform_int_distribution<int> range(0, SET_SIZE - 1);
	for (int i = 0; i < SET_SIZE; i++) {
		int r1 = range(rnd);
		int r2 = range(rnd);
		if (r1 < r2) {
			Dis_Union(set[r1], set[r2]);
		}
	}

	// 3. ���� ��Ȳ ��� (Union Ȯ��)
	for (int i = 0; i < SET_SIZE; i++) {
		PrintDisjointSet(set[i]);
	}

	getchar();
	return 0;
}

struct DisjointSet* Dis_MakeSet(int data) {
	struct DisjointSet* pNode = new DisjointSet();
	pNode->pParent = pNode;		// �ڱ��ڽ� ����Ŵ(���� ǥ���ϱ� ���ؼ�)
	pNode->data = data;
	pNode->rank = 0;
	return pNode;
}

void Dis_Union(struct DisjointSet* pSet1, struct DisjointSet* pSet2) {
	// �� ���տ��� set2�� �θ� set1���� ����
	cout << "UNION(" << pSet1->data << "," << pSet2->data << ")" << endl;

	struct DisjointSet* pParent1 = Dis_Find(pSet1);		// set1�� �ֻ��� �θ� ã��
	struct DisjointSet* pParent2 = Dis_Find(pSet2);		// set2�� �ֻ��� �θ� ã��

	// ���� �ֻ��� �θ� �ٸ� ��쿡�� ���� (������ �����ϸ� ���ѷ��� �ɼ� ����)
	if (pParent1 != pParent2) {
		if (pParent1->rank == pParent2->rank) {
			pParent2->pParent = pParent1;
			pParent1->rank += 1;
		}
		else if (pParent1->rank > pParent2->rank) {
			pParent2->pParent = pParent1;
		}
		else {
			pParent1->pParent = pParent2;
		}
	}
}

struct DisjointSet* Dis_Find(struct DisjointSet* pSet) {
	// ���� ������ �ֻ��� �θ�ã��
	struct DisjointSet* pParent = pSet->pParent;
	if (pParent != pSet) {
		pParent = Dis_Find(pSet->pParent);
	}

	return pParent;
}

void PrintDisjointSet(struct DisjointSet* pSet) {
	cout << pSet->data << "�� �θ�: " << pSet->pParent->data << endl;
}

