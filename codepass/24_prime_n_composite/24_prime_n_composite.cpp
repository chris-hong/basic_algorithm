#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

int ARRAY[10];
int MAX = 5;

bool check_input_N(int input)
{
	if (input < 1 || input > 10 * pow(10, 8))
	{
		return false;
	}
	return true;
}

void printe_is_prime(int N)
{
	if (N < 2) 
	{
		cout << "number one" << endl;
		return;
	}
	int max_isp = sqrt(N);
	for (int i = 2; i <= max_isp; i++)
	{
		if (N % i == 0)
		{
			cout << "composite number" << endl;
			return;
		}
	}
	cout << "prime number" << endl;
	return;
}

int main()
{
	int cnt = 0;
	for (int i = 0; i < MAX; i++)
	{
		cin >> ARRAY[i];
		if (check_input_N(ARRAY[i]))
		{
			printe_is_prime(ARRAY[i]);
		}
	}

	system("pause");

	return 0;
}