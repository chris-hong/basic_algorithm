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
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3
};

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

bool check_left(int x, int y)
{
	int X = x;
	int Y = y - 1;

	if (Y >= 0)
	{
		if (ARRAY[X][Y] == 0) return true;
		else return false;
	}
	else return false;
}

bool check_up(int x, int y)
{
	int X = x - 1;
	int Y = y;

	if (X >= 0)
	{
		if (ARRAY[X][Y] == 0) return true;
		else return false;
	}
	else return false;
}

void make_snail_rectangle()
{
	int num = 0;
	int x = 0;
	int y = 0;
	int timeout = 0;
	DIRECTION direction = DIRECTION::RIGHT;

	ARRAY[x][y] = ++num;
	while (timeout < 4)
	{
		switch (direction)
		{
		case DIRECTION::RIGHT:
			if (check_right(x, y)) {
				timeout = 0;
				ARRAY[x][++y] = ++num;
			}
			else {
				direction = DIRECTION::DOWN;
				timeout++;
			}
			break;
		case DIRECTION::DOWN:
			if (check_down(x, y)) {
				timeout = 0;
				ARRAY[++x][y] = ++num;
			}
			else {
				direction = DIRECTION::LEFT;
				timeout++;
			}
			break;
		case DIRECTION::LEFT:
			if (check_left(x, y)) {
				timeout = 0;
				ARRAY[x][--y] = ++num;
			}
			else {
				direction = DIRECTION::UP;
				timeout++;
			}
			break;
		case DIRECTION::UP:
			if (check_up(x, y)) {
				timeout = 0;
				ARRAY[--x][y] = ++num;
			}
			else {
				direction = DIRECTION::RIGHT;
				timeout++;
			}
			break;
		default:
			break;
		}
	}
}

void print_snail_rectangle()
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
		make_snail_rectangle();
		print_snail_rectangle();
	}

	system("pause");

	return 0;
}