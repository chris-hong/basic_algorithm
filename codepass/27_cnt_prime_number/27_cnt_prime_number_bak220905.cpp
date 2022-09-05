#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

const int MAX = 2000000;

bool check_input(int input)
{
	if (input < 0 || input > 2 * pow(10, 6))
	{
		return false;
	}
	return true;
}

void make_result(int* ARRAY)
{
	ARRAY[0] = ARRAY[1] = 1;
	for (int i = 2; i*i <= MAX; i++)
	{
		if (ARRAY[i] == 0)
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				ARRAY[j] = 1;
			}
		}
	}
}


int main()
{
	int N = 0;
	int M = 0;

	int* ARRAY = new int[2000001];

	cin >> N;
	cin >> M;

	memset(ARRAY, 0, sizeof(int) * 2000001);
	
	if (check_input(N) && check_input(M))
	{
		int PRIME_SUM = 0;
		
		make_result(ARRAY);
		
		for (int k = N; k <= M; k++)
		{
			if (ARRAY[k] == 0)
			{
				PRIME_SUM++;
			}
				
		}
		cout << PRIME_SUM << endl;
	}

	delete ARRAY;

	system("pause");

	return 0;
}