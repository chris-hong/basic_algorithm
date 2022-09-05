#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

int N = 0;
int M = 0;

bool check_input(int input)
{
	if (input < 1 || input > pow(10, 4))
	{
		return false;
	}
	return true;
}

bool check_relation(int n1, int n2)
{
	if (n1 <= n2) return true;
	else return false;
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

int main()
{
	cin >> N;
	cin >> M;

	int PRIME_SUM = 0;
	int PRIME_MIN = -1;

	if (check_input(N) 
		&& check_input(M)
		&& check_relation(N, M))
	{
		for (int num = M; num >= N; num--)
		{
			if (is_prime_number(num))
			{
				PRIME_SUM += num;
				PRIME_MIN = num;
			}
		}

		if (PRIME_SUM > 0) {
			cout << PRIME_SUM << endl;
			cout << PRIME_MIN << endl;
		}
		else {
			cout << -1 << endl;
		}
	}

	system("pause");

	return 0;
}