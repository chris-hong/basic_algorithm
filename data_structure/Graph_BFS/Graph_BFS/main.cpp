#include <iostream>
#include <vector>
#include <queue>

struct Graph {
	int V;
	int E;
	std::vector<std::vector<int>> Adj;
};

struct Graph* MakeGraph(int vertex, int edge) {
	struct Graph* pGraph = new Graph();

	pGraph->V = vertex;
	pGraph->E = edge;

	for (int i = 0; i < vertex; i++) {
		pGraph->Adj.push_back(std::vector<int>(vertex));
	}

	for (int i = 0; i < edge; i++) {
		int from, to;
		std::cout << "Edge[" << i + 1 << "] From : ";
		std::cin >> from;
		std::cin.get();

		std::cout << "Edge[" << i + 1 << "] To : ";
		std::cin >> to;
		std::cin.get();

		pGraph->Adj[from][to] = 1;
		pGraph->Adj[to][from] = 1;
	}

	return pGraph;
}

void BFS(struct Graph* pGraph, std::vector<int>& bufferV, int entry) {
	std::queue<int> Q;
	Q.push(entry);		// 자기 자신을 넣는다. 처음 한번 시작하기 위하여 PUSH

	while (!Q.empty()) {
		int from = Q.front(); Q.pop();

		if (!bufferV[from]) {
			std::cout << "탐색[" << from << "]" << std::endl;
			bufferV[from] = 1;
			
			for (int to = 0; to < pGraph->V; to++) {
				if (!bufferV[to] && pGraph->Adj[from][to]) {
					Q.push(to);
				}
			}
		}
	}
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

	std::vector<int> bufferV(pGraph->V, 0);

	for (int i = 0; i < pGraph->V; i++) {
		if (!bufferV[i]) {
			BFS(pGraph, bufferV, i);
		}
	}

	getchar();
	return 0;
}