#pragma once

struct Graph {
	int V;
	int E;
	//vector<vector<int>> Adj;
	int** Adj;
};

struct Edge {
	int to;
	int weight;
};

struct Comp {
	bool operator() (struct Edge e1, struct Edge e2) {
		return e1.weight > e2.weight;
	}
};

struct Graph* MakeEmptyGraph(int maxVertex) {
	struct Graph* pGraph = new Graph();

	pGraph->Adj = new int*[maxVertex];
	for (int i = 0; i < maxVertex; i++) {
		//pGraph->Adj.push_back(vector<int>(maxVertex, -1));
		pGraph->Adj[i] = new int[maxVertex];
		for (int j = 0; j < maxVertex; j++) {
			pGraph->Adj[i][j] = -1;
		}
	}

	return pGraph;
}

void DeleteGraph(struct Graph* pGraph, int maxVertex) {
	for (int i = 0; i < maxVertex; i++) {
		delete(pGraph->Adj[i]);
	}
	delete(pGraph->Adj);
	delete(pGraph);
}