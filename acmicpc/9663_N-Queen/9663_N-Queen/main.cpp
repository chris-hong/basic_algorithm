#include <iostream>
using namespace std;

int SELECT_X[15];
int SELECT_Y[15];
int totalCount = 0;		// 중복이 발생하여.. AVL에 적용해서 넣자.

template <typename T>
struct tNode {
	T v;
	struct tNode<T> pLeft;
	struct tNode<T> pRight;
};

int ABS(int num) {
	return num > 0 ? num : -num;
}

bool IsSameRow(int fromX, int fromY, int toX, int toY) {
	if (fromX == toX || fromY == toY) return true;
	else return false;
}

bool IsCross(int fromX, int fromY, int toX, int toY) {
	int x = ABS(fromX - toX);
	int y = ABS(fromY - toY);

	return x == y ? true : false;
}

bool IsPossible(int x, int y, int depth) {
	for (int i = 0; i < depth; i++) {
		if (IsSameRow(SELECT_X[i], SELECT_Y[i], x, y)) return false;
		if (IsCross(SELECT_X[i], SELECT_Y[i], x, y)) return false;
	}
	return true;
}
 
void N_Queen(int depth, int N) {
	if (N == 1) return;

	if (depth == N) {
		totalCount += 1;
		return;
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (IsPossible(x, y, depth)) {
				SELECT_X[depth] = x;
				SELECT_Y[depth] = y;
				N_Queen(depth + 1, N);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;

	N_Queen(0, N);

	cout << totalCount << endl;

	return 0;
}