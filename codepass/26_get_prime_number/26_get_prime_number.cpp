#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

int N = 0;
int ARRAY[100];


bool check_input_N(int input)
{
	if (input < 0 || input > 100)
	{
		return false;
	}
	return true;
}

bool check_input_M(int input)
{
	if (input < 1 || input > pow(10, 6))
	{
		return false;
	}
	return true;
}

bool is_prime_number(int num)
{
	if (num < 2) return false;
	int sqrt_num = (int)sqrt(num);
	for (int i = 2; i <= sqrt_num; i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}

int get_under_prime_number(int num)
{
	for (int i = num; i >= 2; i--)
	{
		if (is_prime_number(i)) return i;
	}
	return -9999999;
}

int get_upper_prime_number(int num)
{
	for (int i = num; i <= 1000000; i++)
	{
		if (is_prime_number(i)) return i;
	}
	return 9999999;
}


int main()
{
	cin >> N;

	if (check_input_N(N))
	{
		for (int i = 0; i < N; i++)
		{
			cin >> ARRAY[i];
			if (!check_input_M(ARRAY[i])) return 0;
		}

		for (int j = 0; j < N; j++)
		{
			int upper_prime = get_upper_prime_number(ARRAY[j]);
			int under_prime = get_under_prime_number(ARRAY[j]);
			int diff_upper = upper_prime - ARRAY[j];
			int diff_under = ARRAY[j] - under_prime;
			if (upper_prime == under_prime) printf("%d\n", under_prime);
			else if (diff_upper > diff_under) printf("%d\n", under_prime);
			else if (diff_upper < diff_under) printf("%d\n", upper_prime);
			else printf("%d %d\n", under_prime, upper_prime);
		}
	}

	system("pause");

	return 0;
}