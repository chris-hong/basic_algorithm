#include <iostream>
#include <cstdio>

using namespace std;

bool check_input(int input)
{
	if (input < 1 || input > 100 || input % 2 == 0)
	{
		cout << "INPUT ERROR" << endl;
		return false;
	}
	return true;
}

void print_triangle(int input)
{
	int arr[100][100];

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
			arr[i][j] = -1;
	}

	int center = input / 2;
	int num = 0;

	for (int j = center; j >= 0; j--)
	{
		int end = center + (center - j);
		for (int i = j; i <= end; i++) {
			arr[i][j] = num++;
		}
	}

	for (int k = 0; k < input; k++)
	{
		for (int l = 0; l < input; l++)
		{
			if (arr[k][l] >= 0) printf("%c ", (arr[k][l] % 26) + 65);
			else break;
		}
		printf("\n");
	}
}

int main()
{
	int input = 0;

	cin >> input;

	if (check_input(input)) {
		print_triangle(input);
	}

	return 0;
}