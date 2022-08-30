#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool check_input_N(int input)
{
	if (input < 1 || input > 100 || input % 2 == 0)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

void print_triangle(int N)
{
	int middle = N / 2 + 1;
	int star = 0;
	for (int i = 1; i <= N; i++)
	{
		int diff = abs(middle - i);
		int empty = middle - diff - 1;
		int star = 2 * empty + 1;
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

	cin >> N;

	if (check_input_N(N))
	{
		print_triangle(N);
	}

	system("pause");

	return 0;
}