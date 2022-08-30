#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

int N = 0;
int M = 0;
int ARRAY[40];
int divisor_sum = 0;
int multiple_sum = 0;

bool check_input_N(int input)
{
	if (input < 1 || input > 40)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

bool check_intput_M(int input)
{
	if (input < 1 || input > 100)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

int main()
{
	cin >> N;

	if (check_input_N(N))
	{
		for (int i = 0; i < N; i++) {
			cin >> ARRAY[i];
		}
		cin >> M;
		if (check_intput_M(M)) {
			for (int j = 0; j < N; j++) {
				if (M % ARRAY[j] == 0) divisor_sum += ARRAY[j];
				if (ARRAY[j] % M == 0) multiple_sum += ARRAY[j];
			}
			cout << divisor_sum << endl;
			cout << multiple_sum << endl;
		}
	}

	system("pause");

	return 0;
}