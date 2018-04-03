#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

struct Graph {
	int V;
	int E;
	vector<vector<int>> Adj;
};

struct Edge {
	int before;
	int current;
	int weight;
};

struct Comp {
	bool operator()(struct Edge e1, struct Edge e2) {
		return e1.weight > e2.weight;
	}
};

struct Graph* MakeGraph(int vertex, int edge, string filename) {
	struct Graph* pGraph = new Graph();
	pGraph->V = vertex;
	pGraph->E = edge;
	
	for (int i = 0; i < vertex; i++) {
		pGraph->Adj.push_back(vector<int>(vertex, -1));
	}

	ifstream readFile(filename);
	if (readFile.is_open()) {
		string line;
		while (getline(readFile, line)) {
			istringstream iss(line);
			vector<string> buffer;
			string chunk;
			while (getline(iss, chunk, ' ')) {
				buffer.push_back(chunk);
			}
			
			int from = atoi(buffer[0].c_str());
			int to = atoi(buffer[1].c_str());
			int weight = atoi(buffer[2].c_str());

			pGraph->Adj[from][to] = weight;
			pGraph->Adj[to][from] = weight;
		}

		readFile.close();
	}

	return pGraph;
}

void Prims(struct Graph* pGraph, int start) {
	priority_queue<struct Edge, vector<struct Edge>, Comp> PQ;
	struct Edge E;
	E.before = start;
	E.current = start;
	E.weight = 0;
	PQ.push(E);

	vector<int> Distance(pGraph->V, -1);
	Distance[start] = 0;
	
	vector<int> Path(pGraph->V, -1);
	vector<bool> IsVisit(pGraph->V, false);

	while (!PQ.empty()) {
		int before = PQ.top().before;
		int current = PQ.top().current;
		int weight = PQ.top().weight;
		PQ.pop();

		if (IsVisit[current]) {					// 이미 방문한 곳이면 넘어간다.
			continue;
		}

		cout << "Visit : " << current << endl;

		IsVisit[current] = true;
		Distance[current] = weight;
		Path[current] = before;

		for (int next = 0; next < pGraph->V; next++) {
			if (pGraph->Adj[current][next] > 0) {	// 연결노드 중에..
				if (!IsVisit[next]) {				// 아직 가지 않은 노드가 있다면..
					struct Edge edge;
					edge.before = current;
					edge.current = next;
					edge.weight = pGraph->Adj[current][next];
					PQ.push(edge);
				}
			}
		}
	}

	int totalDistance = 0;
	for (int i = 0; i < pGraph->V; i++) {
		cout << "Distance[" << i << "]: " << Distance[i] << endl;
		totalDistance += Distance[i];
	}
	cout << "Total Distance: " << totalDistance << endl;

	for (int i = 0; i < pGraph->V; i++) {
		cout << "Path[" << i << "]: " << Path[i] << endl;
	}
}

int main(int argc, char* argv[]) {
	string fileName(argv[argc - 1]);
	
	int vertex, edge;
	cout << "VERTEX: ";
	cin >> vertex; cin.get();
	cout << "EDGE: ";
	cin >> edge; cin.get();

	struct Graph* pGraph = MakeGraph(vertex, edge, fileName);

	int start;
	cout << "START: ";
	cin >> start; cin.get();

	Prims(pGraph, start);

	getchar();
	return 0;
}
