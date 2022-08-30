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

int get_number(int num)
{
	return num % 10;
}

enum DIRECTION
{
	RIGHT_DOWN = 0,
	LEFT = 1,
	UP = 2
};

bool check_right_down(int x, int y)
{
	int X = x + 1;
	int Y = y + 1;
	if (X < N && Y < N)
	{
		if (ARRAY[X][Y] < 0) return true;
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
		if (ARRAY[X][Y] < 0) return true;
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
		if (ARRAY[X][Y] < 0) return true;
		else return false;
	}
	else return false;
}

void fill_array()
{
	DIRECTION direction = DIRECTION::RIGHT_DOWN;
	int x = 0;
	int y = 0;
	int num = 0;
	int timeout = 0;

	ARRAY[x][y] = get_number(num++);

	while (timeout < 3)
	{
		switch (direction)
		{
		case DIRECTION::RIGHT_DOWN:
			if (check_right_down(x, y)) {
				timeout = 0;
				ARRAY[++x][++y] = get_number(num++);
			}
			else {
				direction = DIRECTION::LEFT;
				timeout++;
			}
			break;
		case DIRECTION::LEFT:
			if (check_left(x, y)) {
				timeout = 0;
				ARRAY[x][--y] = get_number(num++);
			}
			else {
				direction = DIRECTION::UP;
				timeout++;
			}
			break;
		case DIRECTION::UP:
			if (check_up(x, y)) {
				timeout = 0;
				ARRAY[--x][y] = get_number(num++);
			}
			else {
				direction = DIRECTION::RIGHT_DOWN;
				timeout++;
			}
			break;
		default:
			break;
		}
	}
}

void print_array()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if(ARRAY[i][j] >= 0) printf("%d ", ARRAY[i][j]);
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
		fill_array();
		print_array();
	}

	system("pause");

	return 0;
}