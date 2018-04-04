#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph {
	int V;
	int E;
	vector<vector<int>> Adj;
};

struct Edge {
	int from;
	int to;
	int weight;
};

struct Comp {
	bool operator() (struct Edge e1, struct Edge e2) {
		return e1.weight > e2.weight;
	}
};

priority_queue<struct Edge, vector<struct Edge>, Comp> PQ;

struct DisjointSet {
	struct DisjointSet* pParent;
	int data;
	int rank;
};

struct Graph* MakeGraph() {
	struct Graph* pGraph = new Graph();

	cout << "Vertex : "; cin >> pGraph->V; cin.get();
	cout << "Edge: "; cin >> pGraph->E; cin.get();

	for (int i = 0; i < pGraph->V; i++) {
		pGraph->Adj.push_back(vector<int>(pGraph->V, -1));
	}

	for (int i = 0; i < pGraph->E; i++) {
		int from, to, weight;
		cin >> from; cin >> to; cin >> weight; cin.get();
		pGraph->Adj[from][to] = weight;
		pGraph->Adj[to][from] = weight;

		struct Edge E;
		E.from = from;
		E.to = to;
		E.weight = weight;

		PQ.push(E);
	}

	return pGraph;
}

struct DisjointSet* Dis_MakeSet(int data) {
	struct DisjointSet* pNode = new DisjointSet();
	pNode->data = data;
	pNode->pParent = pNode;
	pNode->rank = 0;
	return pNode;
}

struct DisjointSet* Dis_Find(struct DisjointSet* pSet) {
	struct DisjointSet* pParent = pSet->pParent;
	if (pParent != pSet) {
		pParent = Dis_Find(pParent);
	}
	return pParent;
}

void Dis_Union(struct DisjointSet* pSet1, struct DisjointSet* pSet2) {
	
	cout << "UNION(" << pSet1->data << "," << pSet2->data << ")" << endl;
	
	struct DisjointSet* pParent1 = Dis_Find(pSet1);
	struct DisjointSet* pParent2 = Dis_Find(pSet2);

	if (pParent1 != pParent2) {
		if (pParent1->rank == pParent1->rank) {
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

vector<struct DisjointSet*>* MakeDisjointSet(int _N) {
	vector<DisjointSet*>* pDisjointSet = new vector<DisjointSet*>(_N);
	for (int i = 0; i < _N; i++) {
		(*pDisjointSet)[i] = Dis_MakeSet(i);
	}

	return pDisjointSet;
}

//int Kruskal(struct Graph* pGraph, vector<struct DisjointSet*>* pDisjointSet) {
int Kruskal(vector<struct DisjointSet*>* pDisjointSet) {
	int totalWeight = 0;

	// 우선순위 큐를 사용하기 때문에 weight에 의하여 자동으로 정렬됨.
	while (!PQ.empty()) {
		int from = PQ.top().from;
		int to = PQ.top().to;
		int weight = PQ.top().weight;

		struct DisjointSet* pSet1 = (*pDisjointSet)[from];
		struct DisjointSet* pSet2 = (*pDisjointSet)[to];

		// 두 노드의 최상위 부모가 다르다는 의미는 서로 연결되지 않았다는 의미
		if (Dis_Find(pSet1) != Dis_Find(pSet2)) {
			Dis_Union(pSet1, pSet2);
			//totalWeight += pGraph->Adj[from][to];
			totalWeight += weight;
		}

		PQ.pop();
	}

	return totalWeight;
}

int main() {
	struct Graph* pGraph = MakeGraph();
	
	vector<struct DisjointSet*>* pDisjointSet = MakeDisjointSet(pGraph->V);
	
	//int totalWeight = Kruskal(pGraph, pDisjointSet);
	int totalWeight = Kruskal(pDisjointSet);
	
	cout << "Total weight : " << totalWeight << endl;
	
	getchar();
	return 0;
}