#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

int N = 0;

bool check_input_N(int input)
{
	if (input < 2 || input > 21 * pow(10, 8))
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
		set<int> divisor_set;
		int sqrt_num = (int)sqrt(N);
		for (int i = 1; i <= sqrt_num; i++) {
			if (N % i == 0) {
				divisor_set.insert(i);
				divisor_set.insert(N / i);
			}
		}
		for (auto const& item : divisor_set)
		{
			printf("%d ", item);
		}
		/*for (auto it = divisor_set.begin(); it != divisor_set.end(); it++)
		{
			printf("%d ", *it);
		}*/
		printf("\n");
	}

	system("pause");

	return 0;
}