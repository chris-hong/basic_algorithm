#include <iostream>
#include <cstdio>

using namespace std;

bool check_input_N(int input)
{
	if (input < 1 || input > 100)
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

void print_triangle_type1(int N)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void print_triangle_type2(int N)
{
	for (int i = N; i >= 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void print_triangle_type3(int N)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < N - i; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < 2 * i - 1; k++)
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
		default:
			print_triangle_type3(N);
			break;
		}
	}

	system("pause");

	return 0;
}