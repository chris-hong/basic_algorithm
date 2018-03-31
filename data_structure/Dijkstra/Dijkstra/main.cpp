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

// 우선순위 큐 연산자 OverLoading, 우선순위 큐의 구조체 비교 연산을 위해 재정의
struct Comp {
	bool operator() (struct Edge e1, struct Edge e2) {
		return e1.weight > e2.weight;	// '<' : 높은순으로 뽑음, '>' : 낮은순으로 뽑음
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

		// 방향성, 가중치 그래프이므로 from -> to 에 가중치(weight)로 저장한다.
		pGraph->Adj[from][to] = weight;
	}

	return pGraph;
}

void BackTrackPath(std::vector<int>& Path, int start, int end) {
	std::stack<int> S;	// 역추적 위한 스택
	int temp = end;
	while (temp != -1) {
		S.push(temp);
		temp = Path[temp];
	}

	std::cout << "최단거리 경로 :";
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
	Distance[start] = 0;	// 시작점 처리

	std::vector<int> Path(pGraph->V, -1);

	while (!PQ.empty()) {
		// 큐에서 노드 pop()
		int from = PQ.top().to;
		PQ.pop();

		// 현재 vertex와 연결된 모든 노드 검사
		for (int to = 0; to < pGraph->V; to++) {
			// 연결노드를 찾으면..
			if (pGraph->Adj[from][to] > 0) {
				// (핵심공식) 현재 노드에서 연결 노드까지의 거리 계산
				int minDistance = Distance[from] + pGraph->Adj[from][to];

				// 목적지가 아직 방문하지 않은 노드라면
				if (Distance[to] == -1) {
					Distance[to] = minDistance;
					struct Edge E;
					E.to = to;
					E.weight = pGraph->Adj[from][to];
					PQ.push(E);
					Path[to] = from;
				}

				// 더욱 거리가 작은 경로를 찾았을때 값을 갱신
				if (Distance[to] > minDistance) {
					Distance[to] = minDistance;
					Path[to] = from;
				}
			}
		}
	}

	if (Distance[end] != -1) {
		std::cout << (char)(start + 65) << "에서 " << (char)(end + 65) << "까지 최소거리는 " << Distance[end] << "입니다. " << std::endl;
		BackTrackPath(Path, start, end);
	}
	else {
		std::cout << (char)(start + 65) << "에서 " << (char)(end + 65) << "까지 경로가 없습니다. " << std::endl;
	}

}

int main() {
	int vertex, edge;
	std::cout << "노드 갯수 : ";
	std::cin >> vertex; std::cin.get();
	std::cout << "엣지 갯수 : ";
	std::cin >> edge; std::cin.get();

	struct Graph* pGraph = MakeGraph(vertex, edge);

	int start, end;
	std::cout << "시작점을 입력하세요 : ";
	std::cin >> start; std::cin.get();
	std::cout << "끝점을 입력하세요 : ";
	std::cin >> end; std::cin.get();

	Dijkstra(pGraph, start, end);

	getchar();
	return 0;
}