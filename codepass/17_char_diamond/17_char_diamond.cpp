#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

// 2*N-1
int ARRAY[200][200];
int N = 0;
int MAX = 0;
int CENTER_X = 0;
int CENTER_Y = 0;

bool check_input_N(int input)
{
	if (input < 1 || input > 100)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

enum DIRECTION {
	LEFT_DOWN = 0,
	RIGHT_DOWN = 1,
	RIGHT_UP = 2,
	LEFT_UP = 3,
	LEFT = 4,
};

enum RESULT {
	OK = 0,				// GO
	NG_OCCUPIED = 1,	// LEFT -> LEFT_DOWN ...
	NG_RANGE_OUT = 2	// LEFT_DOWN -> RIGHT_DOWN -> RIGHT_UP -> LEFT_UP -> LEFT
};

bool is_inner_scope(int x, int y)
{
	int THRESHOLD_DISTANCE = N - 1;
	// CENTER로부터 거리가 N - 1 이하인 경우만 마름모 영역에 포함된다. 
	int distance = abs(CENTER_X - x) + abs(CENTER_Y - y);
	return distance <= THRESHOLD_DISTANCE;
}

RESULT check_left_down(int x, int y)
{
	int X = x + 1;
	int Y = y - 1;

	if (X < MAX && Y >= 0)
	{
		if (is_inner_scope(X, Y))
		{
			if (ARRAY[X][Y] == -1) return RESULT::OK;
			else return RESULT::NG_OCCUPIED;
		}
	}
	return RESULT::NG_RANGE_OUT;
}

RESULT check_right_down(int x, int y)
{
	int X = x + 1;
	int Y = y + 1;

	if (X < MAX && Y < MAX)
	{
		if (is_inner_scope(X, Y))
		{
			if (ARRAY[X][Y] == -1) return RESULT::OK;
			else return RESULT::NG_OCCUPIED;
		}
	}
	return RESULT::NG_RANGE_OUT;
}

RESULT check_right_up(int x, int y)
{
	int X = x - 1;
	int Y = y + 1;

	if (X >= 0 && Y < MAX)
	{
		if (is_inner_scope(X, Y))
		{
			if (ARRAY[X][Y] == -1) return RESULT::OK;
			else return RESULT::NG_OCCUPIED;
		}
	}
	return RESULT::NG_RANGE_OUT;
}

RESULT check_left_up(int x, int y)
{
	int X = x - 1;
	int Y = y - 1;

	if (X >= 0 && Y >= 0)
	{
		if (is_inner_scope(X, Y))
		{
			if (ARRAY[X][Y] == -1) return RESULT::OK;
			else return RESULT::NG_OCCUPIED;
		}
	}
	return RESULT::NG_RANGE_OUT;
}

RESULT check_left(int x, int y)
{
	int X = x;
	int Y = y - 1;

	if (Y >= 0)
	{
		if (is_inner_scope(X, Y))
		{
			if (ARRAY[X][Y] == -1) return RESULT::OK;
			else return RESULT::NG_OCCUPIED;
		}
	}
	return RESULT::NG_RANGE_OUT;
}

void make_char_diamond()
{
	int num = 0;
	int x = 0;
	int y = CENTER_Y;
	int timeout = 0;
	DIRECTION direction = DIRECTION::LEFT_DOWN;

	ARRAY[x][y] = num;
	while (timeout < 4)
	{
		RESULT res = RESULT::NG_RANGE_OUT;

		switch (direction)
		{
		case DIRECTION::LEFT_DOWN:
			res = check_left_down(x, y);
			if (res == RESULT::OK) {
				timeout = 0;
				ARRAY[++x][--y] = ++num;
			}
			else if (res == RESULT::NG_OCCUPIED) {
				direction = DIRECTION::RIGHT_DOWN;
				timeout++;
			}
			else if (res == RESULT::NG_RANGE_OUT) {
				direction = DIRECTION::RIGHT_DOWN;
				timeout++;
			}
			break;
		case DIRECTION::RIGHT_DOWN:
			res = check_right_down(x, y);
			if (res == RESULT::OK) {
				timeout = 0;
				ARRAY[++x][++y] = ++num;
			}
			else if (res == RESULT::NG_OCCUPIED) {
				direction = DIRECTION::RIGHT_UP;
				timeout++;
			}
			else if (res == RESULT::NG_RANGE_OUT) {
				direction = DIRECTION::RIGHT_UP;
				timeout++;
			}
			break;
		case DIRECTION::RIGHT_UP:
			res = check_right_up(x, y);
			if (res == RESULT::OK) {
				timeout = 0;
				ARRAY[--x][++y] = ++num;
			}
			else if (res == RESULT::NG_OCCUPIED) {
				direction = DIRECTION::LEFT_UP;
				timeout++;
			}
			else if (res == RESULT::NG_RANGE_OUT) {
				direction = DIRECTION::LEFT_UP;
				timeout++;
			}
			break;
		case DIRECTION::LEFT_UP:
			res = check_left_up(x, y);
			if (res == RESULT::OK) {
				timeout = 0;
				ARRAY[--x][--y] = ++num;
			}
			else if (res == RESULT::NG_OCCUPIED) {
				direction = DIRECTION::LEFT;
				timeout++;
			}
			else if (res == RESULT::NG_RANGE_OUT) {
				direction = DIRECTION::LEFT;
				timeout++;
			}
			break;
		case DIRECTION::LEFT:
			res = check_left(x, y);
			if (res == RESULT::OK) {
				timeout = 0;
				ARRAY[x][--y] = ++num;
				direction = DIRECTION::LEFT_DOWN;
			}
			else {
				timeout++;
			}
			break;
		default:
			break;
		}
	}
}

void print_char_diagmond()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (ARRAY[i][j] == -1) printf("  ");
			else printf("%c ", (ARRAY[i][j] % 26) + 65);
		}
		printf("\n");
	}
}

int main()
{
	memset(ARRAY, -1, sizeof(ARRAY));

	cin >> N;

	if (check_input_N(N))
	{
		MAX = 2 * N - 1;
		CENTER_X = N - 1;
		CENTER_Y = N - 1;

		make_char_diamond();
		print_char_diagmond();
	}

	system("pause");

	return 0;
}