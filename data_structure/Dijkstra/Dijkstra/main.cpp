#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct Graph {
	int V;
	int E;
	std::vector<std::vector<int>> Adj;
};

struct Edge {
	int to;
	int weight;
};

// �켱���� ť ������ OverLoading, �켱���� ť�� ����ü �� ������ ���� ������
struct Comp {
	bool operator() (struct Edge e1, struct Edge e2) {
		return e1.weight > e2.weight;	// '<' : ���������� ����, '>' : ���������� ����
	}
};

struct Graph* MakeGraph(int vertex, int edge) {
	struct Graph* pGraph = new Graph();

	pGraph->V = vertex;
	pGraph->E = edge;

	for (int i = 0; i < vertex; i++) {
		pGraph->Adj.push_back(std::vector<int>(vertex, 0));
	}

	for (int i = 0; i < edge; i++) {
		int from, to, weight;
		
		std::cout << "Edge[" << i + 1 << "] From: ";
		std::cin >> from; std::cin.get();

		std::cout << "Edge[" << i + 1 << "] To: ";
		std::cin >> to; std::cin.get();

		std::cout << "Edge[" << i + 1 << "] Weight: ";
		std::cin >> weight; std::cin.get();

		// ���⼺, ����ġ �׷����̹Ƿ� from -> to �� ����ġ(weight)�� �����Ѵ�.
		pGraph->Adj[from][to] = weight;
	}

	return pGraph;
}

void BackTrackPath(std::vector<int>& Path, int start, int end) {
	std::stack<int> S;	// ������ ���� ����
	int temp = end;
	while (temp != -1) {
		S.push(temp);
		temp = Path[temp];
	}

	std::cout << "�ִܰŸ� ��� :";
	while (!S.empty()) {
		std::cout << " " << (char)(S.top() + 65);
		S.pop();
	}
	std::cout << std::endl;
}

void Dijkstra(struct Graph* pGraph, int start, int end) {
	std::priority_queue<Edge, std::vector<Edge>, Comp> PQ;
	struct Edge E;
	E.to = start;
	E.weight = 0;
	PQ.push(E);

	std::vector<int> Distance(pGraph->V, -1);
	Distance[start] = 0;	// ������ ó��

	std::vector<int> Path(pGraph->V, -1);

	while (!PQ.empty()) {
		// ť���� ��� pop()
		int from = PQ.top().to;
		PQ.pop();

		// ���� vertex�� ����� ��� ��� �˻�
		for (int to = 0; to < pGraph->V; to++) {
			// �����带 ã����..
			if (pGraph->Adj[from][to] > 0) {
				// (�ٽɰ���) ���� ��忡�� ���� �������� �Ÿ� ���
				int minDistance = Distance[from] + pGraph->Adj[from][to];

				// �������� ���� �湮���� ���� �����
				if (Distance[to] == -1) {
					Distance[to] = minDistance;
					struct Edge E;
					E.to = to;
					E.weight = pGraph->Adj[from][to];
					PQ.push(E);
					Path[to] = from;
				}

				// ���� �Ÿ��� ���� ��θ� ã������ ���� ����
				if (Distance[to] > minDistance) {
					Distance[to] = minDistance;
					Path[to] = from;
				}
			}
		}
	}

	if (Distance[end] != -1) {
		std::cout << (char)(start + 65) << "���� " << (char)(end + 65) << "���� �ּҰŸ��� " << Distance[end] << "�Դϴ�. " << std::endl;
		BackTrackPath(Path, start, end);
	}
	else {
		std::cout << (char)(start + 65) << "���� " << (char)(end + 65) << "���� ��ΰ� �����ϴ�. " << std::endl;
	}

}

int main() {
	int vertex, edge;
	std::cout << "��� ���� : ";
	std::cin >> vertex; std::cin.get();
	std::cout << "���� ���� : ";
	std::cin >> edge; std::cin.get();

	struct Graph* pGraph = MakeGraph(vertex, edge);

	int start, end;
	std::cout << "�������� �Է��ϼ��� : ";
	std::cin >> start; std::cin.get();
	std::cout << "������ �Է��ϼ��� : ";
	std::cin >> end; std::cin.get();

	Dijkstra(pGraph, start, end);

	getchar();
	return 0;
}