#include <iostream>
//#pragma warning(disable:4996)
using namespace std;

int MATRIX[9][9];
int BLANK_X[81];
int BLANK_Y[81];

bool isOK = false;

bool IsPossibleX(int x, int num) {
	for (int i = 0; i < 9; i++) {
		if (MATRIX[x][i] == num) return false;
	}
	return true;
}

bool IsPossibleY(int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (MATRIX[i][y] == num) return false;
	}
	return true;
}

bool IsPossibleSquare(int x, int y, int num) {
	int shareX = x / 3;
	int shareY = y / 3;

	for (int i = shareX * 3; i < (shareX + 1) * 3; i++) {
		for (int j = shareY * 3; j < (shareY + 1) * 3; j++) {
			if (MATRIX[i][j] == num) return false;
		}
	}
	return true;
}

void PrintMatrix() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << MATRIX[i][j] << " ";
		}
		cout << endl;
	}
}


void SUDOKU(int depth, int _blankCount) {
	if (isOK) return;	// 하나만 출력하기 위함.

	if (depth == _blankCount) {
		PrintMatrix();
		isOK = true;
		return;
	}

	int x = BLANK_X[depth];
	int y = BLANK_Y[depth];

	for (int num = 1; num <= 9; num++) {
		bool isX = IsPossibleX(x, num);
		bool isY = IsPossibleY(y, num);
		bool isSquare = IsPossibleSquare(x, y, num);
		if (isX && isY && isSquare) {
			MATRIX[x][y] = num;
			SUDOKU(depth + 1, _blankCount);
			MATRIX[x][y] = 0;
		}
	}
}

int main() {
	//freopen("input2.txt", "r", stdin);

	int blankCount = 0;
		
	// BLANK 기록
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> MATRIX[i][j];

			if (MATRIX[i][j] == 0) {
				BLANK_X[blankCount] = i;
				BLANK_Y[blankCount] = j;
				blankCount += 1;
			}
		}
	}

	SUDOKU(0, blankCount);

	return 0;
}