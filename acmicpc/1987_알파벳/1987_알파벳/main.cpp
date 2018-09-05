#include <iostream>
using namespace std;

int R, C;
char BUFFER[20][20];
bool IsVisit[128];
int MaxTraverse = 0;

void Traverse(int depth, int _x, int _y) {
	char tValue = BUFFER[_x][_y];
	
	if (IsVisit[(int)tValue]) {
		MaxTraverse = MaxTraverse < depth ? depth : MaxTraverse;
	/*	cout << "MAX: " << MaxTraverse << ", IsVisit ";
		for (int i = 65; i < 91; i++) {
			if (IsVisit[i]) cout << (char)i;
		}
		cout << " -> " << tValue << endl;*/
		return;
	}

	IsVisit[(int)tValue] = true;

	if (_x - 1 >= 0) Traverse(depth + 1, _x - 1, _y);
	if (_x + 1 < R) Traverse(depth + 1, _x + 1, _y);
	if (_y - 1 >= 0) Traverse(depth + 1, _x, _y - 1);
	if (_y + 1 < C) Traverse(depth + 1, _x, _y + 1);

	IsVisit[(int)tValue] = false;
}

int main() {
	char* inputStream = new char[20];
	
	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		cin >> inputStream;
		for (int j = 0; j < C; j++) {
			BUFFER[i][j] = inputStream[j];
		}
	}


	Traverse(0, 0, 0);
	
	//cout << "=========================================" << endl;
	cout << MaxTraverse << endl;

	delete inputStream;
	return 0;
}