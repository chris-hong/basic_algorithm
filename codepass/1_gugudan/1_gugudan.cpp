#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

bool check_input(int input)
{
	if (input < 2 || input > 9)
	{
		cout << "INPUT ERROR!" << endl;
		return true;
	}
	return false;
}

void get_sequence(vector<int>& sequence, int input1, int input2)
{
	bool is_asc = false;

	if (input1 < input2)
	{
		for (int i = input1; i <= input2; i++) sequence.push_back(i);
	}
	else
	{
		for (int i = input1; i >= input2; i--) sequence.push_back(i);
	}
}

void print_gugudan(vector<int>& sequence)
{
	for (int i = 1; i <= 9; i++)
	{
		for (int num : sequence)
		{
			printf("%d * %d = %2d   ", num, i, num * i);
		}
		printf("\n");
	}
}

int main()
{
	int input1 = 0, input2 = 0;
	vector<int> sequence;
	do
	{
		cin >> input1 >> input2;
	} while (check_input(input1) || check_input(input2));

	get_sequence(sequence, input1, input2);
	print_gugudan(sequence);
	
	return 0;
}
