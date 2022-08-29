#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool check_middle(int idx, int N)
{
	return N / 2 + 1 > idx;
}

bool check_input_N(int input)
{
	if (input < 1 || input > 100 || input % 2 == 0)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

bool check_input_M(int input)
{
	if (input < 1 || input > 4)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

void print_triangle_type1(int N)
{
	int middle = N / 2 + 1;
	int star = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i <= middle)
		{
			star = i;
		}
		else
		{
			star = 2 * middle - i;
		}
		for (int j = 0; j < star; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void print_triangle_type2(int N)
{
	int middle = N / 2 + 1;
	int empty = 0;
	int star = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i <= middle)
		{
			empty = middle - i;
			star = i;
		}
		else
		{
			empty = i - middle;
			star = 2 * middle - i;
		}
		for (int j = 0; j < empty; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < star; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void print_triangle_type3(int N)
{
	int middle = N / 2 + 1;
	for (int i = 1; i <= N; i++)
	{
		int diff = abs(middle - i);
		int empty = middle - diff - 1;
		int star = 2 * diff + 1;
		for (int j = 0; j < empty; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < star; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void print_triangle_type4(int N)
{
	int middle = N / 2 + 1;
	for (int i = 1; i <= N; i++)
	{
		int diff = abs(middle - i);
		int empty = (i <= middle) ? (i - 1) : (middle - 1);
		int star = diff + 1;
		for (int j = 0; j < empty; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < star; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

int main()
{
	int N = 0;
	int M = 0;

	cin >> N;
	cin >> M;

	if (check_input_N(N) && check_input_M(M))
	{
		switch (M)
		{
		case 1:
			print_triangle_type1(N);
			break;
		case 2:
			print_triangle_type2(N);
			break;
		case 3:
			print_triangle_type3(N);
			break;
		default:
			print_triangle_type4(N);
			break;
		}
	}

	system("pause");

	return 0;
}