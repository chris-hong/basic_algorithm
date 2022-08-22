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
		int blank = input - i - 1;
		int occupy = i + 1;
		int gap = 0;
		for (int j = 0; j < blank; j++)
		{
			printf("  ");
		}

		for (int k = 1; k <= occupy; k++)
		{
			printf("%c ", (k + gap - 1 + i) % 26 + 65);
			gap += input - k - 1;
			
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