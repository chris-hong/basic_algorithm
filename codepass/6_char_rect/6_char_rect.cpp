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

void print_rect(int input)
{
	for (int i = 1; i <= input; i++)
	{
		for (int j = input; j >= 1; j--)
		{
			printf("%c ", ((j * input - i) % 26) + 65);
		}
		
		printf("\n");
	}
}

int main()
{
	int input = 0;

	do
	{
		cin >> input;
	} while (check_input(input));

	print_rect(input);

	return 0;
}