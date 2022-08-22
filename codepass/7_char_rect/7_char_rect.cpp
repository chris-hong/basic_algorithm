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
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			if (j % 2 == 0)
			{
				printf("%c ", ((j * input + i) % 26) + 65);
			}
			else
			{
				printf("%c ", ((j * input) + (input - i - 1)) % 26 + 65);
			}
			//printf("%c ", ((j * input + i) % 26) + 65);
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