#include <iostream>
#include <vector>

struct Graph {
	int V;
	int E;
	std::vector<std::vector<bool>> Adj;
};

struct Graph* MakeGraph(int vertex, int edge) {
	struct Graph* pGraph = new Graph();

	pGraph->V = vertex;
	pGraph->E = edge;

	for (int i = 0; i < vertex; i++) {
		pGraph->Adj.push_back(std::vector<bool>(vertex, false));
	}

	for (int i = 0; i < edge; i++) {
		int from, to;
		std::cout << "Edge[" << i + 1 << "] From : ";
		std::cin >> from; 
		std::cin.get();

		std::cout << "Edge[" << i + 1 << "] To : ";
		std::cin >> to;
		std::cin.get();

		// 무방향성 그래프라고 가정하고 양방향 true
		pGraph->Adj[from][to] = true;
		pGraph->Adj[to][from] = true;
	}

	return pGraph;
}

void DFS(struct Graph* pGraph, std::vector<bool>& isVisitBuffer, int from) {
	std::cout << "탐색[" << from << "]" << std::endl;
	isVisitBuffer[from] = true;
	
	for (int to = 0; to < pGraph->V; to++) {
		// 방문하지 않았고, 연결된 노드가 있다면..
		while (!isVisitBuffer[to] && pGraph->Adj[from][to]) {
			DFS(pGraph, isVisitBuffer, to);
		}
	}

	std::cout << "BackTracking[" << from << "]" << std::endl;
}

void PrintGraph(struct Graph* pGraph) {
	int vertex = pGraph->V;

	std::cout << "*** Matrix[" << vertex << "][" << vertex << "] ***" << std::endl;

	for (int i = 0; i < vertex; i++) {
		for (int j = 0; j < vertex; j++) {
			std::cout << pGraph->Adj[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "********************" << std::endl;

}

int main() {
	int vertex = 8;
	int edge = 8;

	struct Graph* pGraph = MakeGraph(vertex, edge);
	PrintGraph(pGraph);

	std::vector<bool> isVisitBuffer(pGraph->V, 0);

	for (int i = 0; i < pGraph->V; i++) {
		if (!isVisitBuffer[i]) {
			DFS(pGraph, isVisitBuffer, i);
		}
	}

	getchar();
	return 0;
}
