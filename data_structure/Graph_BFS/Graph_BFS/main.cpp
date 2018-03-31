#include <iostream>
#include <vector>
#include <queue>

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

		// �����⼺ �׷������ �����ϰ� ����� true
		pGraph->Adj[from][to] = true;
		pGraph->Adj[to][from] = true;
	}

	return pGraph;
}

void BFS(struct Graph* pGraph, std::vector<bool>& isVisitBuffer, int entry) {
	std::queue<int> Q;
	Q.push(entry);		// �ڱ� �ڽ��� �ִ´�. ó�� �ѹ� �����ϱ� ���Ͽ� PUSH

	while (!Q.empty()) {
		int from = Q.front(); Q.pop();

		if (!isVisitBuffer[from]) {
			std::cout << "Ž��[" << from << "]" << std::endl;
			isVisitBuffer[from] = true;
			
			for (int to = 0; to < pGraph->V; to++) {
				if (!isVisitBuffer[to] && pGraph->Adj[from][to]) {
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

	std::vector<bool> isVisitBuffer(pGraph->V, 0);

	for (int i = 0; i < pGraph->V; i++) {
		if (!isVisitBuffer[i]) {
			std::cout << "Vertex[" << i << "]�� �ű� ����" << std::endl;
			BFS(pGraph, isVisitBuffer, i);
		}
	}

	getchar();
	return 0;
}