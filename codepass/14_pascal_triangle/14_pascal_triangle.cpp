#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int ARRAY[31][31];
int N = 0;
int M = 0;

bool check_input_N(int input)
{
	if (input < 1 || input > 30)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

bool check_input_M(int input)
{
	if (input < 1 || input > 3)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

int get_sum(int i, int j)
{
	if (j == 0) return 1;
	
	if (j > 0) return ARRAY[i - 1][j - 1] + ARRAY[i - 1][j];
}

void make_pascal_triangle()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			ARRAY[i][j] = get_sum(i, j);
		}
	}
}

void print_triangle_type1()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", ARRAY[i][j]);
		}
		printf("\n");
	}
}

void print_triangle_type2()
{
	for (int i = N-1; i >= 0; i--)
	{
		int empty = N - i - 1;
		for (int k = 0; k < empty; k++)
		{
			printf(" ");
		}
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", ARRAY[i][j]);
		}
		printf("\n");
	}
}

void print_triangle_type3()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", ARRAY[N-j-1][N-i-1]);
		}
		printf("\n");
	}
}

int main()
{
	memset(ARRAY, 0, sizeof(ARRAY));

	cin >> N;
	cin >> M;

	if (check_input_N(N) && check_input_M(M))
	{
		make_pascal_triangle();
		switch (M)
		{
		case 1:
			print_triangle_type1();
			break;
		case 2:
			print_triangle_type2();
			break;
		case 3:
			print_triangle_type3();
			break;
		default:
			break;
		}
		
	}

	system("pause");

	return 0;
}