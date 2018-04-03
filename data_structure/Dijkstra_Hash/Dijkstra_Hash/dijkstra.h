#pragma once

#include <vector>
#include <queue>
#include <stack>

#include "graph.h"
#include "hash.h"

void BackTrackPath(vector<int>& Path, int start, int end) {
	stack<int> S;
	int temp = end;
	S.push(end);
	while (Path[temp] != -1) {
		S.push(Path[temp]);
		temp = Path[temp];
	}
	cout << "경로";
	while (!S.empty()) {
		int nodeNum = S.top();
		S.pop();
		cout << " -> " << ConvertNumberToString(nodeNum) << "(" << nodeNum << ")";
	}
	cout << endl;
}

void Dijkstra(struct Graph* pGraph, int start, int end) {
	priority_queue<Edge, vector<Edge>, Comp> PQ;

	vector<int> Distance(pGraph->V, -1);
	vector<int> Path(pGraph->V, -1);

	struct Edge E;
	E.to = start;
	E.weight = 0;

	PQ.push(E);

	Distance[start] = 0;

	while (!PQ.empty()) {
		int from = PQ.top().to;
		PQ.pop();

		for (int to = 0; to < pGraph->V; to++) {
			if (pGraph->Adj[from][to] > 0) {
				int minDistance = Distance[from] + pGraph->Adj[from][to];

				if (Distance[to] == -1) {
					Distance[to] = minDistance;
					struct Edge edge;
					edge.to = to;
					edge.weight = pGraph->Adj[from][to];
					PQ.push(edge);
					Path[to] = from;
				}

				if (Distance[to] > minDistance) {
					Distance[to] = minDistance;
					Path[to] = from;
				}
			}
		}
	}

	if (Distance[end] != -1) {
		cout << ConvertNumberToString(start) << "에서 " << ConvertNumberToString(end) << "까지 최소거리는 " << Distance[end] << "입니다. " << std::endl;
		BackTrackPath(Path, start, end);
	}
	else {
		cout << ConvertNumberToString(start) << "에서 " << ConvertNumberToString(end) << "까지 경로가 없습니다. " << std::endl;
	}
}