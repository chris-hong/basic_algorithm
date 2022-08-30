#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int ARRAY[101][101];
int N = 0;

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
	DOWN = 1,
	RIGHT_UP = 2,
	RIGHT = 3
};

bool check_left_down(int x, int y)
{
	int X = x + 1;
	int Y = y - 1;

	if (X < N && Y >= 0)
	{
		if (ARRAY[X][Y] == 0) return true;
		else return false;
	}
	else return false;
}

bool check_down(int x, int y)
{
	int X = x + 1;
	int Y = y;

	if (X < N)
	{
		if (ARRAY[X][Y] == 0) return true;
		else return false;
	}
	else return false;
}

bool check_right_up(int x, int y)
{
	int X = x - 1;
	int Y = y + 1;

	if (X >= 0 && Y < N)
	{
		if (ARRAY[X][Y] == 0) return true;
		else return false;
	}
	else return false;
}

bool check_right(int x, int y)
{
	int X = x;
	int Y = y + 1;

	if (Y < N)
	{
		if (ARRAY[X][Y] == 0) return true;
		else return false;
	}
	else return false;
}

void make_char_diamond()
{
	int num = 0;
	int x = 0;
	int y = 0;
	int timeout = 0;
	int middle = (N * N) / 2;
	DIRECTION direction = DIRECTION::DOWN;

	ARRAY[x][y] = ++num;
	while (timeout < 4)
	{
		switch (direction)
		{
		case DIRECTION::LEFT_DOWN:
			if (check_left_down(x, y)) {
				timeout = 0;
				ARRAY[++x][--y] = ++num;
			}
			else {
				if (num <= middle) direction = DIRECTION::DOWN;
				else direction = DIRECTION::RIGHT;
				timeout++;
			}
			break;
		case DIRECTION::DOWN:
			if (check_down(x, y)) {
				timeout = 0;
				ARRAY[++x][y] = ++num;
				if (num <= middle) direction = DIRECTION::RIGHT_UP;
				else direction = DIRECTION::LEFT_DOWN;
			}
			else {
				timeout++;
			}
			break;
		case DIRECTION::RIGHT_UP:
			if (check_right_up(x, y)) {
				timeout = 0;
				ARRAY[--x][++y] = ++num;
			}
			else {
				if (num <= middle) direction = DIRECTION::RIGHT;
				else direction = DIRECTION::DOWN;
				timeout++;
			}
			break;
		case DIRECTION::RIGHT:
			if (check_right(x, y)) {
				timeout = 0;
				ARRAY[x][++y] = ++num;
				if (num <= middle) direction = DIRECTION::LEFT_DOWN;
				else direction = DIRECTION::RIGHT_UP;
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
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", ARRAY[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	memset(ARRAY, 0, sizeof(ARRAY));

	cin >> N;

	if (check_input_N(N))
	{
		make_char_diamond();
		print_char_diagmond();
	}

	system("pause");

	return 0;
}