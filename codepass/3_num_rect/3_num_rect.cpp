#include <iostream>
#include <cstdio>

using namespace std;

bool check_input(int input)
{
	if (input < 1 || input > 100)
	{
		cout << "INPUT ERROR!" << endl;
		return true;
	}
	return false;
}

void print_rect(int input1, int input2)
{
	for (int i = 0; i < input1; i++)
	{
		for (int j = 1; j <= input2; j++)
		{
			printf("%d ", i * input2 + j);
		}
		printf("\n");
	}
}

int main()
{
	int input1 = 0, input2 = 0;

	do
	{
		cin >> input1 >> input2;
	} while (check_input(input1) || check_input(input2));

	print_rect(input1, input2);

	return 0;
}