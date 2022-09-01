#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

int N = 0;
int ARRAY[10];

bool check_input_N(int input)
{
	if (input < 2 || input > 10)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

bool check_input_array_element(int input)
{
	if (input < 2 || input > 10000)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

int get_GCD(int n1, int n2)
{
	if (n2 == 0) return n1;
	return get_GCD(n2, n1 % n2);
}

int main()
{
	cin >> N;

	bool is_input_ok = true;

	if (check_input_N(N))
	{

		for (int i = 0; i < N; i++) {
			cin >> ARRAY[i];
			if (!check_input_array_element(ARRAY[i])) is_input_ok = false;
		}

		if (is_input_ok)
		{
			int gcd = ARRAY[0];
			int lcm = ARRAY[0];
			for (int i = 1; i < N; i++) {
				gcd = get_GCD(gcd, ARRAY[i]);
				lcm = lcm / get_GCD(lcm, ARRAY[i]) * ARRAY[i];
			}

			printf("%d %d\n", gcd, lcm);
		}
	}

	system("pause");

	return 0;
}