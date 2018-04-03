#include <iostream>
#include <vector>
#include <string>
#include "dijkstra.h"
#include "hash.h"
#include "graph.h"

using namespace std;

int main(int argc, char* argv[]) {
	int MAX_VERTEX = 10000;

	string start, end;
	cin >> start; cin.get();
	cin >> end; cin.get();

	string fileName(argv[argc - 1]);
	struct Graph* pGraph = MakeEmptyGraph(MAX_VERTEX);

	CreateHashTable(pGraph, fileName);

	int dStart = ConvertStringToNumber(start);
	int dEnd = ConvertStringToNumber(end);

	Dijkstra(pGraph, dStart, dEnd);

	DeleteHashTable();
	DeleteGraph(pGraph, MAX_VERTEX);
	
	getchar();
	return 0;
}