#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

int ARRAY[10];
int MAX = 10;

bool check_input_N(int input)
{
	if (input < 1 || input > 21 * pow(10, 8))
	{
		return false;
	}
	return true;
}

void do_reverse_sum(int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		int N = ARRAY[i];
		int SUM_N = 0;
		int REV_N = 0;
		int digit = (int)log10(N);
		for (int k = 0; k <= digit; k++)
		{
			int unit = (int)(pow(10, digit - k));
			int num = N / unit;
			N -= (num * unit);
			SUM_N += num;
			REV_N += num * (int)(pow(10, k));
		}
		printf("%d %d\n", REV_N, SUM_N);
	}
}

int main()
{
	int cnt = 0;
	for (int i = 0; i < MAX; i++)
	{
		cin >> ARRAY[i];
		if (!check_input_N(ARRAY[i]))
			break;
		cnt++;
	}

	do_reverse_sum(cnt);

	system("pause");

	return 0;
}